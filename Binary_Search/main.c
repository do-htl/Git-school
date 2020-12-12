/*  Author: Oberhofer Daniel
    Date: 18.11.2020
    Function: Binary Search
    Find a word in a word file
    Github-repo: https://github.com/do-htl/Git-school.git

    Lukas Kasticky hat mir bei dieser Abgabe geholfen,
    deshalb sind Ähnlichkeiten vorhanden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/stat.h>

//Binary search function

void *Binaere_Suche(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*), size_t start, size_t end){
    //if the given word was not found inside the "wortbuffer"
    if (end < start){
        return NULL;
    }

    size_t mid = (start + end) / 2;
    const void *p = (void *)(((const char*)base)+(mid*size));
    int comparison = (*compar)(key, p);

    //algorithm to determine whether to word we are looking for
    //is higher or lower than the word in the middle
    if (comparison > 0){
        return Binaere_Suche(key, base, nmemb, size, compar, mid+1, end);
    }else if (comparison < 0){
        return Binaere_Suche(key, base, nmemb, size, compar, start, mid-1);
    }else{
        return(void *)p;
    }
}

/*
//Different Binary Search method:

void *bin_search(char *base[],char *key, int us, int os){

    int delta = (os - us)/2;
    int m = us + delta;
    int cmp_res;

    cmp_res = strcmp(key, base[m]);

    if (cmp_res == 0) return m;
    if (delta == 0) return -1;

    if(cmp_res < 0){                //kleiner
            return bin_search(base, key, us, m);
    }else if(cmp_res > 0){          //größer
            return bin_search(base, key, m, os);
    }
}
*/


//compare function
static int cmpfunc(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}

/*  Binary search functions by repeatedly dividing
    the search interval in half, beginning in the middle.

    The searched wortbuffer has to be sorted in order for
    this to work.
*/
int main(int argc, char **argv)
{
    int fd;
    struct stat status;
    char *File_data;
    long int max_length = 0, word_count = 0, chars = 0, cnt = 0;
    long int words = 0, characters = 0;
    long int buffer;

    //Opens wortbuffer file and writes it into
    //the buffer File_data
    fd = open("wortbuffer", O_RDONLY);
    fstat(fd, &status);
    File_data = malloc(status.st_size);
    read(fd, File_data, status.st_size);

    //Finding the largest word in the "wortbuffer"
    for (cnt; cnt < status.st_size; cnt++){
        if (File_data[cnt] == '\0'){
            if (chars > max_length)
                max_length = chars;
                word_count++;
                chars = 0;
                continue;
        }chars++;
    }max_length++;

    char(*search_index)[max_length];
    search_index = malloc(word_count * max_length);


    for(buffer = 0; buffer < status.st_size; buffer++){
    search_index[words][characters] = File_data[buffer];

    if (File_data[buffer] == '\0'){
        words++;
        characters = 0;
    }
    else{
        characters++;
        }
    }

//Given for-loop:
  for(;;){
        printf("-----------------------------------------\n");
        printf("Search for word: ");
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = 0;

        if (!strlen(input)) break;

        struct timeval tv_begin, tv_end, tv_diff;

        /*
            Output of own Binary_search algorithm:
        */
        gettimeofday(&tv_begin, NULL);
        void *res = Binaere_Suche(input,search_index,word_count,max_length,cmpfunc,0, word_count);
        gettimeofday(&tv_end, NULL);

        timersub(&tv_end, &tv_begin, &tv_diff);
        printf("Binary_Search (own):\n");
        if (res != NULL){
            printf("found");
            } else {
                printf("not found");
            }
            printf(" in (%ld seconds %ld microseconds)\n\n", tv_diff.tv_sec, tv_diff.tv_usec);

        /*
            Output of bsearch Algorithm:
        */
        gettimeofday(&tv_begin, NULL);
        void *res_bsearch = bsearch(input,search_index,word_count,max_length,cmpfunc);
        gettimeofday(&tv_end, NULL);

        timersub(&tv_end, &tv_begin, &tv_diff);

        printf("Binary_Search (bsearch):\n");
        if (res_bsearch != NULL){
            printf("found");
            } else {
                printf("not found");
            }
            printf(" in (%ld seconds %ld microseconds)\n", tv_diff.tv_sec, tv_diff.tv_usec);
        }
}
