#Possible values.
#os=Windows
#os=Linux
ifeq ($(os), )
	operating_system=Windows
else
	operating_system=$(os)
endif

#Possible values.
#arch=x86
#arch=x86_64
ifeq ($(arch), )
	architecture=x86_64
else
	architecture=$(arch)
endif