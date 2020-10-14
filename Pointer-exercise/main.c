#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int* px;

    x = 0x42;
    px = &x;

   //*px = 0x43;

    printf("Wert von x = %d\n", x);
    printf("Speicheradresse von x = %x\n\n", &x);

    printf("Wert von px = %x\n", px); //Speicheradresse von x
    printf("Wert von *px = %d\n", *px); //Pointer auf x
    printf("Speicheradresse von px = %x\n\n", &px);

    return 0;
}
