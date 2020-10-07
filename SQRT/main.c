/*  Author: Oberhofer Daniel
    Date: 29.09.2020
    Function: Program for calculating the square root
    for positive integer Numbers
*/

#include <stdio.h>
#include <stdlib.h>

/*  calculates the square number of a given input number using two for-loops
    used to get rid of the multiplication command (*)
*/
int multiplication(int cnt){
    int step, cntsqrt = 0;
    for(step = 0; step != cnt; step++){
        int step2;
        for(step2 = 0; step2 != cnt; step2++){
            cntsqrt++;
        }
    }
    return cntsqrt;
}

/*  calculates the square root of a given argument.
    uses several if and else statements to determine
    whether the calculated square number is lower, equal, or higher
    than the given one
*/
int my_sqrt(int x){
    int cnt;
    for(cnt = 0; cnt <= x; cnt++){
        int cntsqrt = multiplication(cnt);
        if(cntsqrt != x){
            int save = cnt;
            int placeholder = -1;
            if(cntsqrt <= x){
                continue;
            }else{
                for(cnt = 0; cnt != save; cnt++){
                    placeholder++;
                }return placeholder;
            }
        }else{
            return cnt;
        }
    }
}


int main()
{ int i, answer;

    printf("Gib die Zahl ein, von der die Wurzel gezogen werden soll!\n");
    scanf("%d",&i);

    answer = my_sqrt(i);
    printf("Die Wurzel von %d ist: %d",i, answer);
    return 0;
}
