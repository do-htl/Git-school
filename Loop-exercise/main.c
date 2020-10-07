#include <stdio.h>
#include <stdlib.h>



int main()
{
    int foo_1[8], foo_2[8], foo_3[8], foo_4[8];
    int i;
//-------------------------------------------------------------
    printf("for (i=0; i<8; ++i) { foo[i] = i*2+1; }\n");
    for(i=0; i<8; ++i){
        foo_1[i] = i*2+1;
        printf("%d ", foo_1[i]);
    }
    printf("\n\n");

//-------------------------------------------------------------
    printf("for (i=7; i>=0; --i) { foo[i] = i/2; }\n");
    for(i=7; i>=0; --i){
        foo_2[i] = i*2;
        printf("%d ", foo_2[i]);
    }
    printf("\n\n");

//-------------------------------------------------------------

    printf("for (i=0; i<4; ++i) { foo[i*2] = i/2; }\n");
    for(i=0; i<4; ++i){
        foo_3[i*2] = i/2;
        printf("%d ", foo_3[i]);
    }
    printf("\n\n");

//-------------------------------------------------------------
//Multiplication

    int cnt;
    int a = 0;
    int x = 0;

    for(cnt=0; cnt<a; cnt++){
        x+=a;
    }

    printf("%d", x);
    return 0;
}
