#include <stdio.h>
#include <string.h>

#define NR_WORDS 10

/*
for (int i = 0 i < number_of_bytes_in_buffer; i++){
    if (*(buffer + 1)== 0){
        //buffer + 1 == adresse von 0 NACH einem Wort bzw. direkt vor nächstem Wort
    }
}
*/

char bin_search(char *haystack[],char *needle, int us, int os){

    int delta = (os - us)/2;
    int m = us + delta;
    int cmp_res;

    printf("bin_search: us= %d, os=%d, m=%d, delta=%d int cmp_res=%d\n", us, os, m, delta, cmp_res);


    cmp_res = strcmp(needle, haystack[m]);

    if (cmp_res == 0) return m;
    if (delta == 0) return -1;

    if(cmp_res < 0){
            //kleiner
            return bin_search(haystack, needle, us, m);
    }else if(cmp_res > 0){
            //größer
            return bin_search(haystack, needle, m, os);
    }
}

int main(int argc, char **argv)
{

    char *wortliste[10]= {"abc", "abx", "bac", "edf", "nnmcp", "nordpol", "oskar", "alpha", "bravo", "gamma"};

    for(int i = 0; i < NR_WORDS; i++){
        printf("wort %d = %s\n", i, wortliste[i]);
    }

    if (argc < 2){
        printf("Usage: %s needle\n", argv[0]);
        return 1;
    }else{
        int res = bin_search(wortliste, argv[1],0, NR_WORDS);
        printf("Ergebnis der Suche: %d\n", res);
        if(res != -1){
            printf("\nElement gefunden: %s\n", wortliste[res]);
        }else{
            printf("\nElement nicht gefunden\n");
        }
    }
    return 0;
}
