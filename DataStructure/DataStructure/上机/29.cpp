#include <stdio.h>

#define MaxSize 50

typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

void StrAssigh(SqString& s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

int BF(SqString s, SqString t)
{
	int temp = 0;
	while (temp != -1)
	{
		int i = 0, j = 0;
		while (i < s.length && j < t.length)
		{
			if (s.data[i] == t.data[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (j >= t.length)
			return i - t.length;
		else
			return -1;
	}
}

int main()
{

}