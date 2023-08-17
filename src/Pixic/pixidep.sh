#!/bin/bash

#(C) 2023 Серый MLGamer. All freedoms preserved.
#Videos at Дзен: <https://dzen.ru/seriy_mlgamer>
#Music at SoundCloud: <https://soundcloud.com/seriy_mlgamer>
#Videos at YouTube: <https://www.youtube.com/@Seriy_MLGamer>
#Code at GitHub: <https://github.com/Seriy-MLGamer>
#Me at ВКонтакте: <https://vkontakte.ru/seriy_mlgamer>
#Material support at DonationAlerts: <https://www.donationalerts.com/r/seriy_mlgamer>
#E-mail: <Seriy-MLGamer@yandex.ru>

#This file is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#You should have received a copy of the GNU General Public License along with this file. If not, see <https://www.gnu.org/licenses/>.

function generate
{
	declare file
	case $1 in
		input)
			if ! file=$(cat "$2")
			then return 1
			fi
		;;
		dependency)
			if ! file=$(cat "$prefix/$2")
			then return 1
			fi
		;;
	esac
	declare -i state=0 found a
	for ((a=0; a!=${#file}; a++))
	do
		case $state in
			0)
				case ${file:a:1} in
					/) state=1;;
					\") state=2;;
					\') state=3;;
				esac
			;;
			1)
				case ${file:a:1} in
					\*) state=4;;
					/) state=5;;
					\") state=2;;
					\') state=3;;
					*) state=0;;
				esac
			;;
			2)
				case ${file:a:1} in
					\\) state=6;;
					\") state=0;;
				esac
			;;
			3)
				case ${file:a:1} in
					\\) state=7;;
					\') state=0;;
				esac
			;;
			4)
				case ${file:a:1} in
					\*) state=8;;
					*) state=9;;
				esac
			;;
			5)
				case ${file:a:1} in
					"
") state=0;;
				esac
			;;
			6) state=2;;
			7) state=3;;
			8)
				case ${file:a:1} in
					"
")
						state=10
						found=1
					;;
					\*);;
					/) state=0;;
					*) state=11;;
				esac
			;;
			9)
				case ${file:a:1} in
					\*) state=12;;
				esac
			;;
			10)
				if [[ ${file:a:1} = $(expr substr " * @file" $found 1) ]]
				then
					if [[ $found = 8 ]]
					then
						a+=1
						break
					else found+=1
					fi
				elif [[ $found = 3 ]]
				then
					case ${file:a:1} in
						"
") found=1;;
						\*) state=8;;
						/) state=0;;
						*) state=11;;
					esac
				else
					case ${file:a:1} in
						"
") found=1;;
						\*) state=8;;
						*) state=11;;
					esac
				fi
			;;
			11)
				case ${file:a:1} in
					"
")
						state=10
						found=1
					;;
					\*) state=8;;
				esac
			;;
			12)
				case ${file:a:1} in
					\*);;
					/) state=0;;
					*) state=9;;
				esac
			;;
		esac
	done
	if [[ $a = ${#file} ]]
	then return 0
	fi
	declare -i can_continue=0
	state=0
	for ((; a!=${#file}; a++))
	do
		case $state in
			0)
				case ${file:a:1} in
					"
")
						can_continue=1
						a+=1
						break
					;;
					\*) state=1;;
				esac
			;;
			1)
				case ${file:a:1} in
					"
")
						can_continue=1
						a+=1
						break
					;;
					\*);;
					/) break;;
					*) state=0;;
				esac
			;;
		esac
	done
	declare -a include_before dependencies
	declare -i start=a
	if [[ $can_continue = 1 ]]
	then
		can_continue=0
		state=0
		found=1
		for ((; a!=${#file}; a++))
		do
			case $state in
				0)
					if [[ ${file:a:1} = $(expr substr " * Include before." $found 1) ]]
					then
						if [[ $found = 18 ]]
						then state=1
						else found+=1
						fi
					elif [[ $found = 3 ]]
					then
						case ${file:a:1} in
							"
") found=1;;
							\*) state=2;;
							/)
								can_continue=1
								a=start
								break
							;;
							*) state=3;;
						esac
					else
						case ${file:a:1} in
							"
") found=1;;
							\*) state=2;;
							*) state=3;;
						esac
					fi
				;;
				1)
					case ${file:a:1} in
						"
")
							state=4
							found=1
						;;
						\*) state=2;;
						*) state=3;;
					esac
				;;
				2)
					case ${file:a:1} in
						"
")
							state=0
							found=1
						;;
						\*);;
						/)
							can_continue=1
							a=start
							break
						;;
						*) state=3;;
					esac
				;;
				3)
					case ${file:a:1} in
						"
")
							state=0
							found=1
						;;
						\*) state=2;;
					esac
				;;
				4)
					if [[ ${file:a:1} != $(expr substr " * " $found 1) ]]
					then
						can_continue=1
						a=a-found+1
						break
					fi
					if [[ $found = 3 ]]
					then
						state=5
						found=1
						start=a+1
					else found+=1
					fi
				;;
				5)
					if [[ ${file:a:1} = $(expr substr Dependencies. $found 1) ]]
					then
						if [[ $found = 13 ]]
						then state=6
						else found+=1
						fi
					else
						case ${file:a:1} in
							"
")
								if [[ $found = 1 ]]
								then
									can_continue=1
									a+=1
									break
								fi
								state=4
								found=1
								include_before[${#include_before[*]}]=${file:start:a-start}
							;;
							\*) state=7;;
							*) state=8;;
						esac
					fi
				;;
				6)
					case ${file:a:1} in
						"
")
							can_continue=1
							a=a-16
							break
						;;
						\*) state=7;;
						*) state=8;;
					esac
				;;
				7)
					case ${file:a:1} in
						"
")
							state=4
							found=1
							include_before[${#include_before[*]}]=${file:start:a-start}
						;;
						\*);;
						/) break;;
						*) state=8;;
					esac
				;;
				8)
					case ${file:a:1} in
						"
")
							state=4
							found=1
							include_before[${#include_before[*]}]=${file:start:a-start}
						;;
						\*) state=7;;
					esac
				;;
			esac
		done
		if [[ $can_continue = 1 ]]
		then
			state=0
			found=1
			for ((; a!=${#file}; a++))
			do
				case $state in
					0)
						if [[ ${file:a:1} = $(expr substr " * Dependencies." $found 1) ]]
						then
							if [[ $found = 16 ]]
							then state=1
							else found+=1
							fi
						elif [[ $found = 3 ]]
						then
							case ${file:a:1} in
								"
") found=1;;
								\*) state=2;;
								/) break;;
								*) state=3;;
							esac
						else
							case ${file:a:1} in
								"
") found=1;;
								\*) state=2;;
								*) state=3;;
							esac
						fi
					;;
					1)
						case ${file:a:1} in
							"
")
								state=4
								found=1
							;;
							\*) state=2;;
							*) state=3;;
						esac
					;;
					2)
						case ${file:a:1} in
							"
")
								state=0
								found=1
							;;
							\*);;
							/) break;;
							*) state=3;;
						esac
					;;
					3)
						case ${file:a:1} in
							"
")
								state=0
								found=1
							;;
							\*) state=2;;
						esac
					;;
					4)
						if [[ ${file:a:1} != $(expr substr " * " $found 1) ]]
						then break
						fi
						if [[ $found = 3 ]]
						then
							state=5
							start=a+1
						else found+=1
						fi
					;;
					5)
						case ${file:a:1} in
							"
") break;;
							\*) state=6;;
							*) state=7;;
						esac
					;;
					6)
						case ${file:a:1} in
							"
")
								state=4
								found=1
								dependencies[${#dependencies[*]}]=${file:start:a-start}
							;;
							\*);;
							/) break;;
							*) state=7;;
						esac
					;;
					7)
						case ${file:a:1} in
							"
")
								state=4
								found=1
								dependencies[${#dependencies[*]}]=${file:start:a-start}
							;;
							\*) state=6;;
						esac
					;;
				esac
			done
		fi
	fi
	unset file state found can_continue start
	declare name
	case $1 in
		input)
			for ((a=0; a!=${#include_before[*]}; a++))
			do
				name=${include_before[a]}
				if [[ -z ${included_files[$name]} ]]
				then
					include_before_stack[$name]=1
					if ! generate dependency "$name"
					then
						echo "pixidep.sh: error: \"include before\" dependency \"$name\" of the input file \"$2\" isn't found or can't be read.">&2
						exit 3
					fi
					unset include_before_stack[$name]
				fi
			done
			for ((a=0; a!=${#dependencies[*]}; a++))
			do
				name=${dependencies[a]}
				if [[ -z ${included_files[$name]} ]]
				then
					dependencies_stack[$name]=1
					if ! generate dependency "$name"
					then
						echo "pixidep.sh: error: dependency \"$name\" of the input file \"$2\" isn't found or can't be read.">&2
						exit 4
					fi
					unset dependencies_stack[$name]
				fi
			done
		;;
		dependency)
			for ((a=0; a!=${#include_before[*]}; a++))
			do
				name=${include_before[a]}
				if [[ -z ${included_files[$name]} ]]
				then
					if [[ -n ${include_before_stack[$name]} ]]
					then
						echo "pixidep.sh: error: cyclic \"include before\" dependencies in the file \"$name\".">&2
						exit 5
					fi
					include_before_stack[$name]=1
					if ! generate dependency "$name"
					then
						echo "pixidep.sh: error: \"include before\" dependency \"$name\" of the file \"$2\" isn't found or can't be read.">&2
						exit 6
					fi
					unset include_before_stack[$name]
				fi
			done
			echo "include \"$2\"">>$output
			included_files[$2]=1
			for ((a=0; a!=${#dependencies[*]}; a++))
			do
				name=${dependencies[a]}
				if [[ -z ${included_files[$name]} && -z ${dependencies_stack[$name]} ]]
				then
					dependencies_stack[$name]=1
					if ! generate dependency "$name"
					then
						echo "pixidep.sh: error: dependency \"$name\" of the file \"$2\" isn't found or can't be read.">&2
						exit 7
					fi
					unset dependencies_stack[$name]
				fi
			done
		;;
	esac
	return 0
}
function help
{
	echo "pixidep.sh
This script builds dependencies of a Pixilang program as \"include\" statements at so called dependencies registry.
There is the reference syntax of a program's dependencies.
  /**
   * @file [something, path of the file is recommended]
   * [description]
   *
   * Include before.
   * [patches of dependencies relative to a dependencies registry that must be included before this file for correct work]
   * Dependencies.
   * [patches of dependencies relative to a dependencies registry that must not be included before this file, so they can have cyclic dependencies]
   */
Usage.
  pixidep.sh [options] [input file]
Arguments.
  input file  The path to the main Pixilang code file that has dependencies. Default value is \"boot.pixi\" or \"boot.txt\".
Options.
  -h             --help               Show help (this message).
  -l             --license            Show license notice.
  -o <registry>  --output=<registry>  The path for an output dependencies registry. Default value is \"include/dependencies.pixi\"."
	exit 0
}
function license
{
	echo "(C) 2023 Seriy MLGamer. All freedoms preserved.
Videos at Dzen: <https://dzen.ru/seriy_mlgamer>
Music at SoundCloud: <https://soundcloud.com/seriy_mlgamer>
Videos at YouTube: <https://www.youtube.com/@Seriy_MLGamer>
Code at GitHub: <https://github.com/Seriy-MLGamer>
Me at VKontakte: <https://vkontakte.ru/seriy_mlgamer>
Material support at DonationAlerts: <https://www.donationalerts.com/r/seriy_mlgamer>
E-mail: <Seriy-MLGamer@yandex.ru>

pixidep.sh is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
pixidep.sh is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with pixidep.sh. If not, see <https://www.gnu.org/licenses/>."
	exit 0
}
function warning_undefined_parameter
{
	echo "pixidep.sh: warning: no value after \"=\" of the extended parameter: \"$1\".
But ok, just skipping. :)">&2
}
function warning_expected_assign
{
	echo "pixidep.sh: warning: expected \"=\" and value after the extended parameter: \"$1\".
But nothing SCARY. We can continue! ;)">&2
}
declare -i a
for ((a=1; a<=$#; a++))
do
	argument=${*:a:1}
	if [[ -n $state ]]
	then
		case $state in
			output)
				if [[ $output ]]
				then echo "pixidep.sh: warning: multiple definition of output dependencies registry: \"-o $argument\". Its value remains \"$output\".">&2
				else output=$argument
				fi
			;;
		esac
		unset state
	elif [[ ${argument:0:1} = - ]]
	then
		case ${argument:1:1} in
			-)
				case ${argument:2} in
					help) help;;
					license) license;;
					*)
						if [[ ${argument:2:6} = output && ( -z ${argument:8:1} || ${argument:8:1} = = ) ]]
						then
							if [[ ${argument:8:1} != = ]]
							then warning_expected_assign "$argument"
							elif [[ -n ${argument:9:1} ]]
							then
								if [[ $output ]]
								then echo "pixidep.sh: warning: multiple definition of output dependencies registry: \"$argument\". Its value remains \"$output\".">&2
								else output=${argument:9}
								fi
							else warning_undefined_parameter "$argument"
							fi
						else echo "pixidep.sh: warning: unknown option: \"$argument\"">&2
						fi
					;;
				esac
			;;
			h) help;;
			l) license;;
			o)
				if [[ ${#argument} = 2 ]]
				then state=output
				elif [[ $output ]]
				then echo "pixidep.sh: warning: multiple definition of output dependencies registry: \"$argument\". Its value remains \"$output\".">&2
				else output=${argument:2}
				fi
			;;
			*) echo "pixidep.sh: warning: unknown option: \"$argument\"">&2;;
		esac
	elif [[ $input ]]
	then echo "pixidep.sh: warning: multiple definition of input file: \"$argument\". Its value remains \"$input\".">&2
	else input=$argument
	fi
done
if ! [[ $output ]]
then output=include/dependencies.pixi
fi
prefix=$(dirname "$output")
echo "//This file was automatically generated by pixidep.sh
">$output
declare -A included_files include_before_stack dependencies_stack
if [[ $input ]]
then 
	if ! generate input "$input"
	then
		echo "pixidep.sh: error: input file \"$input\" isn't found or can't be read.">&2
		exit 1
	fi
elif ! generate input boot.pixi && ! generate input boot.txt
then
	echo "pixidep.sh: error: default input file (\"boot.pixi\" or \"boot.txt\") isn't found or can't be read.">&2
	exit 2
fi
exit 0