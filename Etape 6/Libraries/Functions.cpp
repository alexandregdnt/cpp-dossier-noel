#include "Functions.h"

char *toCapitalize(const char *str) {
    char *tmpstr;
    tmpstr = new char[strlen(str) + 1];

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0)
            tmpstr[i] = toupper(str[i]);
        else
            tmpstr[i] = tolower(str[i]);
    }
    return tmpstr;
}