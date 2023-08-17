@echo off

rem (C) 2022-2023 Серый MLGamer. All freedoms preserved.
rem Videos at Дзен: <https://dzen.ru/seriy_mlgamer>
rem Music at SoundCloud: <https://soundcloud.com/seriy_mlgamer>
rem Videos at YouTube: <https://www.youtube.com/@Seriy_MLGamer>
rem Code at GitHub: <https://github.com/Seriy-MLGamer>
rem Me at ВКонтакте: <https://vkontakte.ru/seriy_mlgamer>
rem Material support at DonationAlerts: <https://www.donationalerts.com/r/seriy_mlgamer>
rem E-mail: <Seriy-MLGamer@yandex.ru>

rem This file is part of Pixic.
rem Pixic is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
rem Pixic is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
rem You should have received a copy of the GNU General Public License along with Pixic. If not, see <https://www.gnu.org/licenses/>.

pixilang -c boot.pixi
move boot.pixicode ../../out/pixic/src/share/pixic/boot.pixicode
../../out/pixic/src/bin/pixic test.pixi -t -o out --folder