#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buf[0x100];

void reverse(int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char temp = buf[i];
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = temp;
    }
}

int main()
{
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    int secret = 0xc0deface;
    while (1)
    {
        printf("\nString: ");
        scanf("%255s", buf);
        reverse(strlen(buf));
        printf(buf);
        if (secret == 0xdeadbeef)
        {
            system("/bin/sh");
        }
    }
}