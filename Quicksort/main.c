/*  Author: Oberhofer Daniel
    Date: 09.01.2021
    Function: Quicksort
    Sorting elements with quicksort algorithm
    Github-repo: https://github.com/do-htl/Git-school.git
*/

/*  Average time
    Number of elements: 10  | 100   | 1000  | 10000 | 100000
    Time [us]:          2   | 10    | 95    | 2500  | 140200
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


/*  This partition function is used to place the pivot element at
    its correct position. In this case the first element
    of the array is set to the pivot element.
    All elements that are smaller than pivot are moved
    to the left and every element that is greater to the right of pivot
*/
int partition(int *a, int us, int os){

    int buffer;
    int pivot = a[us];
    int usb = us;
    int osb = os;

    //Placing pivot at the right position
    while(usb < osb){
        //Numbers that are smaller or equal to pivot
        while(a[usb] <= pivot && usb < osb) usb++;
        //Numbers that are greater than pivot
        while(a[osb] > pivot && osb > us) osb--;

        if(usb < osb){
            buffer = a[usb];
            a[usb] = a[osb];
            a[osb] = buffer;
        }
    }
    a[us] = a[osb];
    a[osb] = pivot;
    return osb;
}

//Quicksort algorithm
void qs(int *a, int us, int os){
    if(us < os){
        int pivot = partition(a, us, os);
        qs(a, us, pivot - 1);
        qs(a, pivot + 1, os);
    }
}

// creates a array of size size and fills it with random ints in range 0 to max_int
int *create_array(int size, int max_int)
{
	int *b = (int*)malloc(size * sizeof(int));

	for (int i=0; i<size; i++) {
		b[i] = rand() % max_int;
	}

	return b;
}

#define MY_SIZE 100

int main(int argc, char **argv)
{
	// create random ints based in current time
	srand(time(NULL));
    int *a = create_array(MY_SIZE, 100);

    //Time measurements ...
    struct timeval tv_begin, tv_end, tv_diff;
    gettimeofday(&tv_begin, NULL);

    qs(a, 0, MY_SIZE);

    gettimeofday(&tv_end, NULL);
    timersub(&tv_end, &tv_begin, &tv_diff);

	int old = -1;
	for (int i=0; i<MY_SIZE; ++i)      {
		if (old != -1) assert(old <= a[i]);
		printf("%d ", a[i]);
		old = a[i];
	}

    printf("\n\nElapsed time for %d elements: %ld microseconds \n\n", MY_SIZE, tv_diff.tv_usec);
	printf("\n");
}
