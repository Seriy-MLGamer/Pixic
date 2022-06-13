#!/bin/bash

help()
{
	echo "A configuration generator of Pixic for crossplatform compilation.
Usage.
  configuration.sh [options] <bit_depth> <operating_system>
Fields.
  bit_depth              Bit depth of Pixilang variables. Possible values: \"x32\", \"x64\".
  operating_system       Target operating system. Possible values: \"Windows\", \"Linux\", \"MacOS\".
Options.
  -h             --help  Show this message.
  -o<directory>          Set target directory for configuration file. Default is work directory."
	exit 0
}
for a in $@
do
	case $argument_state in
		directory)
			unset argument_state
			directory="$a"
		;;
		*)
			if [ ${a:0:1} = - ]
			then
				case ${a:1:1} in
					-)
						case ${a:2} in
							help) help;;
							*) echo "${@:0:1}: warning: unknown option: \"$a\"";;
						esac
					;;
					h) help;;
					o)
						if [ ${#a} = 2 ]
						then argument_state=directory
						else directory="${a:2}"
						fi
					;;
					*) echo "${@:0:1}: warning: unknown option: \"${a:0:2}\"";;
				esac
			elif [ -z $bit_depth ]
			then bit_depth=$a
			elif [ -z $operating_system ]
			then operating_system=$a
			fi
		;;
	esac
done
if [ -z $bit_depth ]
then
	echo "${@:0:1}: error: bit depth is not defined."
	exit 1
fi
if [ -z $operating_system ]
then
	echo "${@:0:1}: error: operating system is not defined."
	exit 2
fi
if [ -z "$directory" ]
then
	directory=.
fi
unset a
unset argument_state

result=\
"/**
 * @file configuration.h
 * Configuration of project for crossplatform compilation and IntelliSense support.
 * This file can be generated automatically by \"configuration.sh\".
 */

#pragma once

/*Bit depth of Pixilang variables.*/
/*Choose one of them.*/
"
x32="//#define X32"
x64="//#define X64"
case $bit_depth in
	x32) x32=${x32:2};;
	x64) x64=${x64:2};;
	*)
		echo "${@:0:1}: error: bit depth is wrong."
		exit 3
	;;
esac
result+=\
"$x32
$x64

/*Target operating system.*/
/*Choose one of them.*/
"
Windows="//#define OS_WINDOWS"
Linux="//#define OS_LINUX"
MacOS="//#define OS_MAC"
case $operating_system in
	Windows) Windows=${Windows:2};;
	Linux) Linux=${Linux:2};;
	MacOS) MacOS=${MacOS:2};;
	*)
		echo "${@:0:1}: error: operating system is wrong."
		exit 4
	;;
esac
result+=\
"$Windows
$Linux
$MacOS"
echo -n "$result">"$directory"/configuration.h