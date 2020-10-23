/*  Author: Oberhofer Daniel
    Date: 23.10.2020
    Function: file-copy
    Github-repo: https://github.com/do-htl/Git-school.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*  This program copies a file using posix api commands
    such as open(), read(), write() and close().
*/

int main()
{
    char buffer[20];
    int Data_R, Data_W;
    int length =0;

    Data_R = open("Data_R.txt", O_RDWR | O_CREAT);
    Data_W = open("Data_W.txt", O_RDWR | O_CREAT);

    read(Data_R,buffer,sizeof(buffer));

    /*  The for-loop determines how many
        characters have been written into
        the "Data_R" text-file
    */

    for(int i=0; i<sizeof(buffer); i++){
        length = i;
        if(buffer[i] == NULL)break;
    }

    write(Data_W,buffer,length);

    close(Data_R);
    close(Data_W);

    return 0;
}
