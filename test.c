//#include "stdio.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

int main(int argument_count, char** arguments)
{
	SDL_Window* window=SDL_CreateWindow("Мику!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	/*char* miku=(char*)malloc(sizeof(char)*9);
	miku[0]=0x00;
	miku[1]=0xE0;
	miku[2]=0x1C;
	miku[3]=0x03;
	miku[4]=0xE3;
	miku[5]=0xFC;
	miku[6]=0x1F;
	miku[7]=0xFF;
	miku[8]=0x1F;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 9, 1, 0, GL_RGB, GL_UNSIGNED_BYTE_3_3_2, miku);*/
	/*short* miku=(short*)malloc(sizeof(short)*9);
	miku[0]=0x0000;
	miku[1]=0xF800;
	miku[2]=0x1C;
	miku[3]=0x03;
	miku[4]=0xE3;
	miku[5]=0xFC;
	miku[6]=0x1F;
	miku[7]=0xFF;
	miku[8]=0x1F;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 9, 1, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, miku);*/
	int* miku=(int*)malloc(sizeof(int)*9);
	miku[0]=0x00000000;
	miku[1]=0x00000040;
	miku[2]=0x1C;
	miku[3]=0x03;
	miku[4]=0xE3;
	miku[5]=0xFC;
	miku[6]=0x1F;
	miku[7]=0xFF;
	miku[8]=0x1F;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 9, 1, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, miku);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1); glVertex2f(-1, -1);
	glTexCoord2f(1, 1); glVertex2f(1, -1);
	glTexCoord2f(0, 0); glVertex2f(-1, 1);
	glTexCoord2f(1, 0); glVertex2f(1, 1);
	glEnd();
	SDL_GL_SwapWindow(window);
	SDL_Event event;
	while (1)
	{
		while (SDL_PollEvent(&event)) if (event.type==SDL_QUIT) return EXIT_SUCCESS;
		SDL_Delay(100);
	}
}