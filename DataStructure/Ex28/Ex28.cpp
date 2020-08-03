#include<stdio.h>
#include<string.h>

int main()
{
    char str[2000];
    int i, num[256] = { 0 };
    printf("please input string:");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++)
        num[(int)str[i]]++;
    for (i = 0; i < 256; i++)
        if (num[i] != 0)
            printf("字符%c出现%d次\n", (char)i, num[i]);

    return 0;
}
