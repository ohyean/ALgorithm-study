//거의 최단 경로 https://www.acmicpc.net/problem/5719
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int N, M;
int S, D;
int U, V, P;
int map[500][10000];
int visit[500][10000];
int min;


void sol(int sp, int len)
{
	for (int i = 0; i < N; i++)
	{
		if (map[sp][i] != 0)
		{
			len = len + map[sp][i];

			if (i == D)
			{
				if (min > len)
					min = len;
				return;
			}
			else
			{
				if (min < len)
					return;

				sol(i, len);
			}
		}
	}
}


void del(int sp, int len)
{
	for (int i = 0; i < N; i++)
	{
		if (map[sp][i] != 0)
		{
			len = len + map[sp][i];

			if (i == D)
			{
				if (min == len)
					map[sp][i] = 0;
				return;
			}
			else
			{
				if (min < len)
					return;

				sol(i, len);
			}
		}
	}
}


int main()
{
	while (1)
	{
		int answer = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;

		scanf("%d %d", &S, &D);
		
		for (int i = 0; i < M; i++)
		{
			scanf("%d %d %d", &U, &V, &P);
			map[U][V] = P;
		}

		//최단경로 구하기
		min = 987654321;
		sol(S, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		//최단경로 삭제
		del(S, 0);
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}



		//다시 최단경로 구하기
		min = 987654321;
		sol(S, 0);
	
		if (min == 987654321)
			min = -1;

		printf("%d\n", min);
	}
	return 0;
}