#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

/*
    Command Line Tool to decode text that is encoded with the caesar's cipher
    Sample Text: "MFQQT QNXF, NHM BZJWIJ RNHM LJWS RNY INW YWJKKJS. BJSS IZ RTJHMYJXY PTRR RTWLJS SFHMRNYYFL ZR ANJW NS INJ JNXINJQJ. NHM BFWYJ FZK INHM. IJNS HMWNXYTUM."
*/
int main( int argc, char *argv[] ){
    printf("%s\n", argv[0]);
    if(argc > 2) {
        printf("Too many arguments supplied.\n");
        return 0;
    } else if (argc < 2){
        printf("Please provide a ciphered text as argument.");
        return 0;
    }
    initscr();
    scrollok(stdscr, TRUE);
    printw("Caesar\'s Cipher cracker\nCiphered text is %s\n\n", argv[1]);
    refresh();

    char startChar = argv[1][0];
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < strlen(argv[1]); j++){
            char currentCh = argv[1][j];
            if(currentCh >= 65 && currentCh <= 90){
                if(currentCh == 90){
                    argv[1][j] = currentCh - 25;
                }else {
                    argv[1][j] = currentCh + 1;
                }
            }
        }
        addstr("Is this readable?\n");
        addstr(argv[1]);
        addstr("\n");
        addstr("[Y/n] ");
        refresh();

        char ch = getch();
        addstr("\n");
        refresh();
        if(ch == 10 || ch == 121 || ch == 89){
            printw("Decoded: %s\n", argv[1]);
            int shiftcount;
            if(argv[1][0] >= startChar){
                shiftcount = abs((int) (argv[1][0] - startChar));
                printw("The alphabet was shifted %d places\n", shiftcount);
            }else {
                shiftcount = abs((int) (startChar - argv[1][0]));
                printw("The alphabet was shifted %d places backwards\n", shiftcount);
            }
            refresh();
            break;
        }
    }
    addstr("Press any key to continue...");
    refresh();
    getch();

    endwin();

    return EXIT_SUCCESS;
}
