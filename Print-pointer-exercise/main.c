#include <stdio.h>
#include <stdlib.h>

void print_char(char);
void printf_str(char *str){
    char *p = str;
    while(*p!='\0'){
        print_char(*p);
        p++;
    }
}

int main()
{
    char *str;
    str = "foo";

    print_char();
    printf_str(*str);

    return 0;
}
