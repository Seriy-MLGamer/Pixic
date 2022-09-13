#!/usr/bin/bash

#Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

#This file is part of Pixic runtime.
#Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.

help()
{
	echo "\
A configuration generator of Pixic runtime for crossplatform compilation.
Usage: configuration.sh [options] <bit_depth> <operating_system>
Fields.
  bit_depth                 Bit depth of Pixilang variables. Possible values: \"x32\", \"x64\".
  operating_system          Target operating system. Possible values: \"Windows\", \"Linux\", \"MacOS\".
Options.
  -h             --help     Show help (this message).
  -l             --license  Show license notice.
  -o<directory>             Set target directory for configuration file. Default is work directory.\
"
	exit 0
}
license()
{
	echo "\
Copyright (C) 2022  Seriy MLGamer

This program is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.\
"
	exit 0
}
for a in $*
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
							license) license;;
							*) echo "$0: warning: unknown option: \"$a\"";;
						esac
					;;
					h) help;;
					l) license;;
					o)
						if [ ${#a} = 2 ]
						then argument_state=directory
						else directory="${a:2}"
						fi
					;;
					*) echo "$0: warning: unknown option: \"$a\"";;
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
	echo "$0: error: bit depth is not defined."
	exit 1
fi
if [ -z $operating_system ]
then
	echo "$0: error: operating system is not defined."
	exit 2
fi
if [ -z "$directory" ]
then
	directory=.
fi
unset a
unset argument_state

result="\
/*
Copyright (C) 2022 Серый MLGamer <Seriy-MLGamer@yandex.ru>

This file is part of Pixic runtime.
Pixic runtime is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Pixic runtime is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Pixic runtime. If not, see <https://www.gnu.org/licenses/>.
*/

/**
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
		echo "$0: error: bit depth is wrong."
		exit 3
	;;
esac
result+="\
$x32
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
		echo "$0: error: operating system is wrong."
		exit 4
	;;
esac
result+="\
$Windows
$Linux
$MacOS\
"
echo -n "$result">"$directory"/configuration.h