//6109 추억의 2048게임
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[20][20];
char S[5];

void zero(int N)
{
	if (!strcmp(S, "up"))
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N - 1; k++)
			{
				if (arr[k][i] == 0)
				{
					for (int l = k + 1; l < N; l++)
					{
						if (arr[l][i] != 0)
						{
							arr[k][i] = arr[l][i];
							arr[l][i] = 0;
							break;
						}
					}
				}
			}
		}
	}

	else if (!strcmp(S, "down"))
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = N-1; k > 0; k--)
			{
				if (arr[k][i] == 0)
				{
					for (int l = k - 1; l >= 0; l--)
					{
						if (arr[l][i] != 0)
						{
							arr[k][i] = arr[l][i];
							arr[l][i] = 0;
							break;
						}
					}
				}
			}
		}
	}

	else if (!strcmp(S, "left"))
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N - 1; k++)
			{
				if (arr[i][k] == 0)
				{
					for (int l = k + 1; l < N; l++)
					{
						if (arr[i][l] != 0)
						{
							arr[i][k] = arr[i][l];
							arr[i][l] = 0;
							break;
						}
					}
				}
			}
		}
	}

	else if (!strcmp(S, "right"))
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = N - 1; k > 0; k--)
			{
				if (arr[i][k] == 0)
				{
					for (int l = k - 1; l >= 0; l--)
					{
						if (arr[i][l] != 0)
						{
							arr[i][k] = arr[i][l];
							arr[i][l] = 0;
							break;
						}
					}
				}
			}
		}
	}
}
	


//1: up, 2:down, 3:left, 4:right
void move(int N)
{
	if (!strcmp(S, "up"))
	{
		for (int i = 0; i < N; i++)
		{
			zero(N);
			for (int j = 0; j < N - 1; j++)
			{
				if (arr[j][i] != 0 && arr[j][i] == arr[j+1][i])
				{
					arr[j+1][i] = 0;
					arr[j][i] = arr[j][i] * 2;
				}
				else
					continue;
			}
			zero(N);
		}
	}

	else if (!strcmp(S, "down"))
	{
		for (int i = 0; i < N; i++)
		{
			zero(N);
			for (int j = N-1; j > 0; j--)
			{
				if (arr[j][i] != 0 && arr[j][i] == arr[j - 1][i])
				{
					arr[j - 1][i] = 0;
					arr[j][i] = arr[j][i] * 2;
				}
				else
					continue;
			}
			zero(N);
		}
	}

	else if (!strcmp(S, "left"))
	{
		for (int i = 0; i < N; i++)
		{
			zero(N);
			for (int j = 0; j < N-1; j++)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1])
				{
					arr[i][j + 1] = 0;
					arr[i][j] = arr[i][j] * 2;
				}
				else
					continue;
			}
			zero(N);
		}
	}

	else if (!strcmp(S, "right"))
	{
		for (int i = 0; i < N; i++)
		{
			zero(N);
			for (int j = N-1; j > 0; j--)
			{
				if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1])
				{
					arr[i][j - 1] = 0;
					arr[i][j] = arr[i][j] * 2;
				}
				else
					continue;
			}
			zero(N);			
		}
	}
}


int main()
{
	int T, N;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		memset(arr, 0, sizeof(arr));
		memset(S, 0, sizeof(S));
		scanf("%d", &N);
		scanf(" %s", S);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		move(N);

		printf("#%d\n", test);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}