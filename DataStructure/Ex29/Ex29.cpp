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

//输出串s
void DispStr(SqString s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}

int result[MaxSize];

void index(SqString s, SqString t, int &num)
{
	int i = 0, k = 0;
	while (i < s.length)
	{
		int j = 0;
		while (j < t.length)
		{
			if (s.data[i] == t.data[j])  	//继续匹配下一个字符
			{
				i++;				//主串和子串依次匹配下一个字符
				j++;
			}
			else          			//主串、子串指针回溯重新开始下一次匹配
			{
				i = i - j + 1;			//主串从下一个位置开始匹配
				j = 0; 				//子串从头开始匹配
			}
		}
		if (j >= t.length)
		{
			result[k] = i - t.length;
			k++;
		} 		//返回匹配的第一个字符的下标
	}
	num = k;
}

int main()
{
	SqString a, b;
	int num;
	char d[] = { "abc abc abc" };
	char e[] = { "abc" };
	StrAssigh(a, d); DispStr(a);
	StrAssigh(b, e); DispStr(b);
	index(a, b, num);

	for (int i = 0; i < num; i++)
	{
		printf("%d ", result[i]);
	}

	return 0;
}
