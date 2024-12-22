#include<string.h>
#include<stdio.h>

void main()
{
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    char buf[0x100];
    char FLAG[] = "FLAG{fake_flag}";
    printf("Enter your input: ");
    scanf("%255s", buf);
    while(1)
    {
        int i;
        printf("Enter the index of the character you want to inspect: ");
        scanf("%d", &i);
        printf("The character at index %d is '%c'.\n", i, buf[i]);
    }
}