/*
    Copyright (C) 2021  Jared M. Bennett

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>

//Returns 1 when yes (Y, y) and 0 when something else is pressed
int read_yes_no(){
    printf("[y/N] ");
    char buf[16];
    fgets(buf, sizeof buf, stdin);
    if(buf[0] == 121 || buf[0] == 89){
        return 1;
    }else {
        return 0;
    }
}

//Makes a char uppercase (e.g. a to A)
char char_to_uppercase(char s){
    if(s >= 'a' && s <= 'z') {
        s = s -32;
    }
    return s;
}