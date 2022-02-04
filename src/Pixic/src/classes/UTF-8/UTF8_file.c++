#include <classes/UTF-8/UTF8_file>

#include <classes/UTF-8/UTF8_exception>

using namespace std;

static inline streampos calculate_offset(istream& stream, streampos& previous);

UTF32_char UTF8_file::get()
{
	streampos return_on_error=istream::tellg();
	#define UTF8_ERROR\
	{\
		istream::seekg(return_on_error, ios_base::beg);\
		throw UTF8_exception();\
	}
	int value=istream::get();
	if (value==EOF)
	{
		position+=1;
		return EOF;
	}
	if ((value&0x80)==0x00)
	{
		position+=1;
		return value;
	}
	if ((value&0xC0)==0x80)
	{
		char buffer[3];
		*buffer=value&0x3F;
		char a;
		for (a=1; a!=4; a++)
		{
			value=istream::get();
			if ((value&0xC0)==0x80&&a!=3) buffer[a]=value&0x3F;
			else if ((value&0xE0)==0xC0&&a==1)
			{
				position+=1;
				return (value&0x1F)<<6|*buffer;
			}
			else if ((value&0xF0)==0xE0&&a==2)
			{
				position+=1;
				return (value&0x0F)<<12|buffer[1]<<6|*buffer;
			}
			else if ((value&0xF8)==0xF0&&a==3)
			{
				UTF32_char result=(value&0x07)<<18;
				for (char a=2; a!=-1; a--) result|=buffer[a]<<6*a;
				position+=1;
				return result;
			}
			else UTF8_ERROR
		}
	}
	if ((value&0xE0)==0xC0)
	{
		UTF32_char result=(value&0x1F)<<6;
		value=istream::get();
		if ((value&0xC0)!=0x80) UTF8_ERROR
		position+=1;
		return result|value&0x3F;
	}
	if ((value&0xF0)==0xE0)
	{
		UTF32_char result=(value&0x0F)<<12;
		value=istream::get();
		if ((value&0xC0)!=0x80) UTF8_ERROR
		result|=(value&0x3F)<<6;
		value=istream::get();
		if ((value&0xC0)!=0x80) UTF8_ERROR
		position+=1;
		return result|value&0x3F;
	}
	if ((value&0xF8)==0xF0)
	{
		UTF32_char result=(value&0x07)<<18;
		for (char a=2; a!=-1; a--)
		{
			value=istream::get();
			if ((value&0xC0)!=0x80) UTF8_ERROR
			result|=(value&0x3F)<<6*a;
		}
		position+=1;
		return result;
	}
	UTF8_ERROR
	#undef UTF8_ERROR
}
UTF8_file& UTF8_file::put(UTF32_char symbol)
{
	if (symbol<0x00000080) ostream::put((char)symbol);
	else if (symbol<0x00000800)
	{
		ostream::put(symbol>>6&0x1F|0xC0);
		ostream::put(symbol&0x3F|0x80);
	}
	else if (symbol<0x00010000)
	{
		ostream::put(symbol>>12&0x0F|0xE0);
		ostream::put(symbol>>6&0x3F|0x80);
		ostream::put(symbol&0x3F|0x80);
	}
	else if (symbol<0x00011000)
	{
		ostream::put(symbol>>18&0x07|0xF0);
		ostream::put(symbol>>12&0x3F|0x80);
		ostream::put(symbol>>6&0x3F|0x80);
		ostream::put(symbol&0x3F|0x80);
	}
	else throw UTF8_exception();
	position+=1;
	return *this;
}
UTF8_file& UTF8_file::put_LE(UTF32_char symbol)
{
	if (symbol<0x00000080) ostream::put((char)symbol);
	else if (symbol<0x00000800)
	{
		ostream::put(symbol&0x3F|0x80);
		ostream::put(symbol>>6&0x1F|0xC0);
	}
	else if (symbol<0x00010000)
	{
		ostream::put(symbol&0x3F|0x80);
		ostream::put(symbol>>6&0x3F|0x80);
		ostream::put(symbol>>12&0x0F|0xE0);
	}
	else if (symbol<0x00011000)
	{
		ostream::put(symbol&0x3F|0x80);
		ostream::put(symbol>>6&0x3F|0x80);
		ostream::put(symbol>>12&0x3F|0x80);
		ostream::put(symbol>>18&0x07|0xF0);
	}
	else throw UTF8_exception();
	position+=1;
	return *this;
}
UTF8_file& UTF8_file::seekg(streamoff offset, ios_base::seekdir origin)
{
	streampos return_on_error=istream::tellg();
	streampos position_on_error=position;
	#define UTF8_ERROR\
	{\
		istream::seekg(return_on_error, ios_base::beg);\
		position=position_on_error;\
		throw UTF8_exception();\
	}
	if (origin==ios_base::beg)
	{
		istream::seekg(0, ios_base::beg);
		position=0;
	}
	else if (origin==ios_base::end)
	{
		istream::seekg(0, ios_base::end);
		try
		{
			position+=calculate_offset(*this, return_on_error);
		}
		catch(exception&)
		{
			UTF8_ERROR
		}
	}
	if (offset<0)
	{
		for (streampos a=offset; a; a+=1)
		{
			int value=istream::seekg(-1, ios_base::cur).get();
			istream::seekg(-2, ios_base::cur);
			if ((value&0xC0)==0x80)
			{
				char a;
				for (a=1; a!=4; a++)
				{
					value=istream::get();
					istream::seekg(-2, ios_base::cur);
					if ((value&0xE0)==0xC0||(value&0xF0)==0xE0||(value&0xF8)==0xF0) break;
					if ((value&0x80)==0x00||(value&0xF8)==0xF8) UTF8_ERROR
				}
				if (a==4) UTF8_ERROR
			}
			else if ((value&0xE0)==0xC0) istream::seekg(-1, ios_base::cur);
			else if ((value&0xF0)==0xE0) istream::seekg(-2, ios_base::cur);
			else if ((value&0xF8)==0xF0) istream::seekg(-3, ios_base::cur);
			else if ((value&0xF8)==0xF8&&value!=EOF) UTF8_ERROR
			istream::seekg(1, ios_base::cur);
		}
	}
	else
	{
		for (streampos a=0; a!=offset; a+=1)
		{
			int value=istream::get();
			if ((value&0xC0)==0x80)
			{
				char a;
				for (a=1; a!=4; a++)
				{
					value=istream::get();
					if ((value&0xE0)==0xC0||(value&0xF0)==0xE0||(value&0xF8)==0xF0) break;
					if ((value&0x80)==0x00||(value&0xF8)==0xF8) UTF8_ERROR
				}
				if (a==4) UTF8_ERROR
			}
			else if ((value&0xE0)==0xC0) istream::seekg(1, ios_base::cur);
			else if ((value&0xF0)==0xE0) istream::seekg(2, ios_base::cur);
			else if ((value&0xF8)==0xF0) istream::seekg(3, ios_base::cur);
			else if ((value&0xF8)==0xF8&&value!=EOF) UTF8_ERROR
		}
	}
	position+=offset;
	return *this;
	#undef UTF8_ERROR
}

static inline streampos calculate_offset(istream& stream, streampos& previous)
{
	streampos return_on_error=stream.tellg();
	#define UTF8_ERROR\
	{\
		stream.seekg(return_on_error, ios_base::beg);\
		throw UTF8_exception();\
	}
	streampos result=0;
	streampos position=return_on_error-previous;
	if (position==-1) throw UTF8_exception();
	stream.seekg(previous, ios_base::beg);
	if (position<0)
	{
		streampos a=position; while (a<0)
		{
			int value=stream.seekg(-1, ios_base::cur).get();
			stream.seekg(-2, ios_base::cur);
			if ((value&0x80)==0x00||value==EOF) a+=1;
			else if ((value&0xC0)==0x80)
			{
				char b;
				for (b=1; b!=4; b++)
				{
					value=stream.get();
					stream.seekg(-2, ios_base::cur);
					if ((value&0xE0)==0xC0||(value&0xF0)==0xE0||(value&0xF8)==0xF0) break;
					if ((value&0x80)==0x00||(value&0xF8)==0xF8) UTF8_ERROR
				}
				if (b==4) UTF8_ERROR
				a+=b+1;
			}
			else if ((value&0xE0)==0xC0)
			{
				stream.seekg(-1, ios_base::cur);
				a+=2;
			}
			else if ((value&0xF0)==0xE0)
			{
				stream.seekg(-2, ios_base::cur);
				a+=3;
			}
			else if ((value&0xF8)==0xF0)
			{
				stream.seekg(-3, ios_base::cur);
				a+=4;
			}
			else UTF8_ERROR
			stream.seekg(1, ios_base::cur);
			result-=1;
		}
		if (a!=0) UTF8_ERROR
	}
	else
	{
		streampos a=0; while (a<position)
		{
			int value=stream.get();
			if ((value&0x80)==0x00||value==EOF) a+=1;
			else if ((value&0xC0)==0x80)
			{
				char b;
				for (b=1; b!=4; b++)
				{
					value=stream.get();
					if ((value&0xE0)==0xC0||(value&0xF0)==0xE0||(value&0xF8)==0xF0) break;
					if ((value&0x80)==0x00||(value&0xF8)==0xF8) UTF8_ERROR
				}
				if (b==4) UTF8_ERROR
				a+=b+1;
			}
			else if ((value&0xE0)==0xC0)
			{
				stream.seekg(1, ios_base::cur);
				a+=2;
			}
			else if ((value&0xF0)==0xE0)
			{
				stream.seekg(2, ios_base::cur);
				a+=3;
			}
			else if ((value&0xF8)==0xF0)
			{
				stream.seekg(3, ios_base::cur);
				a+=4;
			}
			else UTF8_ERROR
			result+=1;
		}
		if (a!=position) UTF8_ERROR
	}
	return result;
	#undef UTF8_ERROR
}