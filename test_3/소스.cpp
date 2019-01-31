//6781. 삼삼 트리플 게임
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[9];
char color[9];

void sort()
{
	int tempnum;
	char tempcolor;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (num[j] < num[i])
			{
				tempnum = num[j];
				num[j] = num[i];
				num[i] = tempnum;

				tempcolor = color[j];
				color[j] = color[i];
				color[i] = tempcolor;
			}
		}
	}
}


void sol(int x)
{
	for (int i = 0; i < 9; i++)
	{
		if (x == i)
			continue;
		else if (num[i] == num[x] && color[i] == color[x])//숫자3개가 다 같은 경우
		{
			for (int j = 0; j < 9; j++)
			{
				if (x == j || i == j)
					continue;
				else if (num[j] == num[x] && color[j] == color[x])
				{
					num[x] = -1;
					num[i] = -1;
					num[j] = -1;
					return;
				}
			}
		}
		else if (num[i] == (num[x] + 1) && color[i] == color[x])//숫자3개가 연속할 경우
		{
			for (int j = 0; j < 9; j++)
			{
				if (x == j || i == j)
					continue;
				else if (num[j] == (num[x] + 2) && color[j] == color[x])
				{
					num[x] = -1;
					num[i] = -1;
					num[j] = -1;
					return;
				}
			}
		}
	}
}


int main()
{
	int T;
	scanf("%d", &T);

	char *win = "win";
	char *con = "continue";
	char *answer = (char*)malloc(sizeof(char) * 8);

	for (int test = 1; test <= T; test++)
	{
		for (int i = 0; i < 9; i++)
			scanf("%1d", &num[i]);
		for (int j = 0; j < 9; j++)
			scanf(" %c", &color[j]);

		sort();

		for (int k = 0; k < 9; k++)
		{
			if (num[k] == -1)
				continue;

			sol(k);
		}

		for (int i = 0; i < 9; i++)
			printf("%d ", num[i]);

		strcpy(answer, win);

		for (int l = 0; l < 9; l++)
		{
			if (num[l] != -1)
			{
				strcpy(answer, con);
				break;
			}
		}

		printf("#%d %s\n", test, answer);
	}

	return 0;
}
