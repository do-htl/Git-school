/*  Author: Oberhofer Daniel
    Date: 17.10.2020
    Function: rle-encode
    rle - run-length encoding
    Github-repo: https://github.com/do-htl/Git-school.git
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_RLEN 42

/*  run-length encoding algorithm, that works by using
    multiple for loops, two are used to save a data value
    to the result and one is used for counting up when the
    same data value occurs in consecutive data elements

    Using an allocated memory block for the result with the
    size (length * 2) because when the data value changes allm
    the time e.g.: FOFO it would be F1O1F1O1
    resulting in the size being twice as big as the original one
*/

char* encode(char* str)
{
    int rep = 1, cnt, cnt2, step = 0;
    char temp[MAX_RLEN];
    int length = strlen(str);
    char* res = (char*)malloc(sizeof(char) * (length * 2));

    for (cnt= 0; cnt < length; cnt++) {
        res[step++] = str[cnt];
        for(;str[cnt] == str[cnt+1];rep++,cnt++) {
        }
        sprintf(temp, "%d", rep);
        rep = 1;
        for(cnt2=0; *(temp+cnt2);){
            res[step++] = temp[cnt2++];
        }
    }
    res[step] = '\0';
    return res;
}

int main(int argc, char **argv)
{
    char str[MAX_RLEN];

    do{
        if(fgets(str, MAX_RLEN, stdin) == NULL) break;
		str[MAX_RLEN-1] = 0;    // TODO: is this really needed?
		str[strlen(str)-1] = 0; // TODO: why is this here?
        char* res = encode(str);
        printf(">%s\n", res);
        free(res);

    }while (strlen(str)> 1);



    return 0;
}
