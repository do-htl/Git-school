/*  Author: Oberhofer Daniel
    Date: 3.10.2020
    Function: Sieve of Erastosthenes
*/

#include <stdio.h>
#include <stdlib.h>


/*  determines the primes from 0 to 500.
    it works by crossing out the multiples of 2,3,5,7
    using two for-loops, one counts the steps (2,3,5,7)
    the other loop crosses out the multiples
*/
int *sieve(int *primes){
    int cnt, step;
    primes[1] = 0;
    for(step = 2; step <= 20;){
        for(cnt = 2 * step; cnt <= 500; cnt +=step){
            primes[cnt]=0;
        }
        step++;
        while(primes[step] == 0){
            step++;
        }
    }return primes;
}

/*  this function is only used to fill the array
    from 0 to 500
*/
int *getarray(int *array){
    int i;
    for(i=0;i<=500;i++)
    {
        array[i]=i;
    }
    return array;
}

int main()
{int *n, *primes;
 int i, array[501];
 n=getarray(array);

 primes = sieve(n);

  printf("Primzahlen von 0 bis 500: \n\n");
  for(i=0;i<=500;i++)
    {
        if(primes[i] == 0){     //used for better visual presentation of the primes
            printf("");         //gets rid of the crossed out numbers
            continue;
        }
        printf(" %d ", primes[i]);
        }
    return 0;
}