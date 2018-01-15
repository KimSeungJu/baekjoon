#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
char a[2000];
char b[2000];
int alpa[30] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int change(char *a, char *b)
{
	int x[4100];
	int k = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		x[k] = alpa[a[i] - 'A'];
		k += 2;
	}
	k = 1;
	for (int i = 0; i < len; i++)
	{
		x[k] = alpa[b[i] - 'A'];
		k += 2;
	}

	for (int j = 2 * (len - 1); j > 0; j--)
	{
		for (int i = 0; i <= j; i++)
		{
			x[i] = x[i] + x[i + 1];
			x[i] %= 10;
		}
	}
	printf("%d%d", x[0], x[1]);
	return 0;
}

int main() {

	scanf("%s", a);
	scanf("%s", b);

	int k = 0;
	k = change(a, b);

	return 0;
}
