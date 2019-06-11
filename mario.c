#include <cs50.h>
#include <stdio.h>


void mario(int n);

int main(void)
{
    int num;
    do {
        num = get_int("Height: ");
    }
    while (num < 1 || num > 8);
    
    mario(num);
}

void printchr(string c, int n) {
    for (int i=0; i<n; i++)
    {
        printf("%s", c);
    }
}

void mario(int n) 
{
    for (int i=1; i <= n; i++)
    {
        printchr(" ", n - i);
        printchr("#", i);
        printf("  ");
        printchr("#", i);
        printf("\n");
    }
}
