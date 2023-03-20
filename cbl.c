/*  cbl.c
    Console Based note & clipit Lookup & retrieval
    Linux only
    Usage:
    no args => lists your cbl text files
    argv 1 ==> basename of text file (displays files item names)
    argv 2 ==> leading characters of item to lookup (displays items info)
*/
#include <myc.h>

#define CLR "\033[33;1m"  // bright: Yellow 33 | Purple 35 | Red 31
#define DEF "\033[0m\n"   // reset to default color

char line[1024] = {'\0'};
char src[1024]  = {'\0'};
char cbl_item[64] = {'\0'};
int output = 0;
int cntx = 0;

/* This function lists all of the cbl text files
residing on the ~/.config/cbl directory
It's called when the user only types 'cbl' */
void listfiles() {
    sprintf(src, "%s/.config/cbl", getenv("HOME"));
    printf("\n%scbl files: ", CLR);
    list d = list_dir(src, 1, true);  // builds/sorts an array of dir's files
    for (int x = 0; x < d.nbr_rows; x++) {
        printf("  %s\n", d.item[x]);
    }
    list_del(d);
    puts(DEF);
}


void main (int argc, char *argv[]) {

    list aname = list_def(4, 65);  // define a 4 row array

    if (argc < 2) {
        listfiles();
        exit(EXIT_SUCCESS);
    } else {
        // configure the file (arg 2) path
        sprintf(src, "%s/.config/cbl", getenv("HOME"));
        if (contains(argv[1], ".txt") == 1) {  // user included the .txt
            concat(src, "/", argv[1], END);
        } else {
            concat(src, "/", argv[1], ".txt", END);
        }
        puts(CLR); printf("%s", src);
        if (argc == 2) {  // list items in file and exit
            puts("");
            FILE * fh = open_for_read(src);
            while(!feof(fh)) {
                fgets(line, 1000, fh);
                if (contains(line, "^_^")) {
                    list_split(aname, line, " ");
                    printf(" %-14s  ", aname.item[0]);
                    cntx++;
                    if (cntx > 2) {
                        printf("\n");
                        cntx = 0;
                    }
                }
            }
            puts(DEF);
            list_del(aname);
            fclose(fh);
            exit(EXIT_SUCCESS);
        } else {
            strncpy(cbl_item, argv[2], 60);  // find item and display info
        }
    }


    FILE * fh = open_for_read(src);
    while(!feof(fh)) {
        fgets(line, 1000, fh);
        if (contains(line, "^_^")) {
            if (output) {
                exit(EXIT_SUCCESS);
            }
            list_split(aname, line, " ");
            if (startswith(aname.item[0], cbl_item)) {
                printf("%s - %s%s", CLR, aname.item[0], DEF);
                output = 1;
            }
        } else {
            if (output) {
                printf("%s%s%s", CLR, chomp(line), DEF);
            }
        }
    }

    list_del(aname);
    fclose(fh);
    if (output == 0) {
        printf("\n%s%s%s%s", CLR, argv[1],
               " exists, but cbl item not found...", DEF);
        sprintf(line, "%s%s\0", "cbl ", argv[1]);
        system(line);
    }
}
