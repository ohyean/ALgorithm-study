/*//6731. 홍익이의 오델로 게임
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//흰돌 : 0 , 검은돌 : 1
int N;
int min;
int arr[1000][1000];
int goal[1000][1000];

int check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == goal[i][j])
				continue;
			else if (arr[i][j] != goal[i][j])
				return -1;
		}
	}
	return 1;
}

void sol()
{

}


int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		min = 0;
		memset(arr, 0, sizeof(arr));
		memset(goal, 0, sizeof(goal));
		scanf("%d", &N);
		char temp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %c", &temp);
				if (temp == 'W')
					goal[i][j] = 0;
				else if (temp == 'B')
					goal[i][j] = 1;
			}
		}

		while (1)
		{
			if (1 == check())
				break;
			sol();
		}

		printf("#%d %d\n", test, min);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
*/

/*6719. 성수의 프로그래밍 강좌 시청
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[200];

void sort(int N)
{
	int temp;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int T, N, K;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		double answer = 0;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(N);

		int cnt = 0;
		for (int j = K; j > 0; j--)
		{
			int two = 1;
			for (int t = 0; t < j; t++)
			{
				two = two * 2;
			}

			answer = answer + arr[cnt] / two;
			cnt++;
		}

		printf("#%d %.6f", test, answer);
	}
	return 0;
}
*/

