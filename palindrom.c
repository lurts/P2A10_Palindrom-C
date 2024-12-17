//
// Created by laebbeke on 17.12.2024.
//

#include "palindrom.h"

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        // 32, bzw 'a' - 'A' addieren um zu kleinbuchstaben umzuwandeln
        return c + ('a' - 'A');
    }
    return c;
}

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void removeNonAlpha(char text[]) {
    // muss mir da noch was überlegen
    // eventuell brauche ich diese funktion gar nicht aber idk
}

void palidrome(const char text[], bool* is) {
    unsigned int left = 0;      // index links
    unsigned int right = 0;     // index rechts

    // länge der string bestimmen
    while (text[right] != '\0') {
        right++;
    }
    right--; // letztes zeichen ist '\0' also um 1 zurück gehen

    // palindrom test
    while (left < right) {
        // überspringe nicht buchstaben links
        while(left < right && !isAlpha(text[left])) {
            left++;
        }
        // überspringe nicht buchstaben rechts
        while (left < right && !isAlpha(text[right])) {
            right--;
        }

        // vergleiche zeichen links und rechts
        if (toLower(text[left]) != toLower(text[right])) {
            *is = false; // kein palindrom
            return;
        }
    }
}