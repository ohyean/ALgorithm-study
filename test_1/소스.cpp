//5550. 나는 개구리로소이다
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int answer;
char arr[2500];
int temp;

void sol(int num, int len, char next)
{
	if (next == 'c')
	{
		for (int i = num; i < len; i++)
		{
			if (arr[i] == 'c')
			{
				arr[i] = '0';
				sol(i + 1, len, 'r');
				break;
			}
			if (i == (len - 1))
				return;
		}
	}
	else if (next == 'r')
	{
		for (int i = num; i < len; i++)
		{
			if (arr[i] == 'r')
			{
				arr[i] = '0';
				sol(i + 1, len, 'o');
				break;
			}
			if (i == (len - 1))
				return;
		}
	}
	else if (next == 'o')
	{
		for (int i = num; i < len; i++)
		{
			if (arr[i] == 'o')
			{
				arr[i] = '0';
				sol(i + 1, len, 'a');
				break;
			}
			if (i == (len - 1))
				return;
		}
	}
	else if (next == 'a')
	{
		for (int i = num; i < len; i++)
		{
			if (arr[i] == 'a')
			{
				arr[i] = '0';
				sol(i + 1, len, 'k');
				break;
			}
			if (i == (len - 1))
				return;
		}
	}
	else if (next == 'k')
	{
		for (int i = num; i < len; i++)
		{
			if (arr[i] == 'k')
			{
				arr[i] = '0';
				temp = i;
				break;
			}
			if (i == (len - 1) && arr[i] != 'k')
				return;
		}
	}
	else
		return;
}


int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		answer = 0;
		memset(arr, 0, sizeof(arr));
		scanf(" %s", arr);

		int len = strlen(arr);
		int maxcnt = len / 5;
		int cnt = 0;
		int pos = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == '0')
				continue;

			sol(i, len, 'c');
		
			if (pos == temp)
			{
				answer++;
				i = -1;
				pos = 0;
				continue;
			}

			i = temp;

			if (pos != temp && i == len - 1)
			{
				i = -1;
				cnt++;
				if (cnt > maxcnt)
					break;
				continue;
			}

			pos = temp;
		}

		for (int k = 0; k < len; k++)
		{
			if (arr[k] != '0')
			{
				answer = -1;
				break;
			}
			else if (k == (len - 1) && arr[k] == '0')
			{
				answer++;
				break;
			}
		}


		printf("#%d %d\n", test, answer);
	}

	return 0;
}
