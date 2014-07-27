#include <stdio.h>
#include <stdlib.h>

void print(int n)
{
    if(n>0)
    {
        n--;
        print(n/26);
        printf("%c",(n%26)+65);
    }
}

int main(int argc, char *argv[]) {
    print(atoi(argv[1]));
    printf("\n");
    return 0;
}
