if [[ ${@:1:1} = "" ]]
then
	echo "${@:0:1}: error: output directory is not defined."
	exit 1
fi
result=\
"/**
 * \file configuration.h
 * Configuration of project for crossplatform compilation and IntelliSense support.
 * This file can be generated automatically by \"configuration.sh\".
 */

#pragma once

/*Bit depth of target device.*/
/*Choose one of them.*/
"
x32="//#define x32"
x64="//#define x64"
if [[ ${@:2:1} = x32 ]]
then x32=${x32:2}
elif [[ ${@:2:1} = x64 ]]
then x64=${x64:2}
else
	echo "${@:0:1}: error: bit depth is wrong."
	exit 2
fi
result+="$x32
$x64

/*Target operating system.*/
/*Choose one of them.*/
"
Windows="//#define OS_Windows"
Linux="//#define OS_Linux"
if [[ ${@:3:1} = Windows ]]
then Windows=${Windows:2}
elif [[ ${@:3:1} = Linux ]]
then Linux=${Linux:2}
else
	echo "${@:0:1}: error: operating system is wrong."
	exit 3
fi
result+="$Windows
$Linux"
echo "$result">"${@:1:1}"/configuration.h