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


    Command Line Tool to decode text that is encoded with the caesar's cipher
    Sample Text: "MFQQT QNXF, NHM BZJWIJ RNHM LJWS RNY INW YWJKKJS. BJSS IZ RTJHMYJXY PTRR RTWLJS SFHMRNYYFL ZR ANJW NS INJ JNXINJQJ. NHM BFWYJ FZK INHM. IJNS HMWNXYTUM."
*/

#include <stdlib.h>
#include <string.h>

//has some utility functions
#include "util.h"

//ANSI color codes - Only used on linux to color things and make them bold - it doesn't work on windows
#define GREEN "\e[0;32m"
#define WHITE_BOLD "\e[1;37m"
#define RED "\e[0;31m"
#define RESET "\e[0m"

//"undefine" the color code in windows
#ifdef _WIN32
    #undef GREEN
    #define GREEN ""
    #undef WHITE_BOLD
    #define WHITE_BOLD ""
    #undef RED
    #define RED ""
    #undef RESET
    #define RESET ""
#endif

/*
    tries to crack the ciphered input by adding 1 to every char (and subtracting 25 to get from Z to A)
    and asking the user if the text is readable
    it repeats this task 25 times but breaks if the user says the text is readable
    returns 1 if it could be deciphered 
    else it returns 0
*/ 
int decipher(char input[]){
    char startChar = char_to_uppercase(input[0]);
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < strlen(input); j++){
            char currentCh = char_to_uppercase(input[j]);
            if(currentCh >= 65 && currentCh <= 90){
                if(currentCh == 90){
                    input[j] = currentCh - 25;
                }else {
                    input[j] = currentCh + 1;
                }
            }
        }
        printf("Is this readable?\n %s\n", input);

        if(read_yes_no() == 1){
            printf("Decoded: %s%s%s \n", GREEN, input, RESET);
            int shiftcount = input[0] - startChar;
            printf("The alphabet was shifted %d places\n", shiftcount);
            return 1;
        }
    }
    return 0;
}

/*
    Main Method:
    checks if an argument was supplied
    tries to decipher the input using the decipher(char input[]) function
    if this succeeds it exits
    if it fails it asks the user if they want to retry
*/
int main( int argc, char *argv[] ){
    if(argc > 2) {
        printf("Too many arguments supplied.\n");
        return -1;
    } else if (argc < 2){
        printf("Please provide a ciphered text as argument.");
        return -1;
    }
    printf("%sCaesar\'s Cipher cracker\n\n", WHITE_BOLD);
    printf("Command Line Tool that can decode text that is encoded with the caesar's cipher\n\n");
    printf("Copyright (C) 2021  Jared M. Bennett\n\n");
    printf("This program comes with ABSOLUTELY NO WARRANTY.\n");
    printf("This is free software, and you are welcome to redistribute it\n");
    printf("under certain conditions.%s\n\n", RESET);
    printf("Ciphered text is %s%s%s\n\n", RED, argv[1], RESET);

    while(decipher(argv[1]) == 0){
        printf("Cycled through whole alphabet.\n Retry? ");
        if(read_yes_no() == 0){
            break;
        }
        printf("Retrying...\n");
    }

    return EXIT_SUCCESS;
}