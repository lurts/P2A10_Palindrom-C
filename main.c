#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "palindrom.h"

#ifndef MAX_LENGTH
#define MAX_LENGTH 255
#endif

int main(int argc, char* argv[]) {
    char input[MAX_LENGTH];
    bool isPalindrome = false;

    if (argc == 1) {
        // keine weiteren argumente -> text aus konsole lesen
        printf("Text eingeben:>");
        fgets(input, MAX_LENGTH, stdin);

        palidrome(input, &isPalindrome);
    }
    else if (argc == 2) {
        // zusätzliches argument übergeben -> versuchen datei zu öffnen und text lesen
        FILE *inFile = fopen(argv[1], "r");
        if (inFile == NULL) {
            printf("Fehler: Datei kann nicht geoeffnet werden!\n");
            fclose(inFile);
            return 1;
        }
        fgets(input, MAX_LENGTH, inFile);
        fclose(inFile);

        palidrome(input, &isPalindrome);
    }
    else if (argc > 2) {
        // zu viele argumente -> fehler anzeigen und programm beenden
        printf("Fehler: Zu viele Argumente!");
        return 1;
    }

    if (isPalindrome) {
        printf("Der Text ist ein Palindrom!");
    }
    else {
        printf("Der Text ist KEIN Palindrom!");
    }

    return 0;
}
