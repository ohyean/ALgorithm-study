//17장 부분합 문제 : 크리스마스 인형
#include <iostream>
#include <vector>
using namespace std;

int C;				//테스트케이스 개수
int N, K;			//N: 상자개수  K: 어린이 수
int box[100000];
int psum[100000];
int mod[100000];

void partialsum()
{
	psum[0] = box[0];
	mod[0] = psum[0] % K;
	for (int i = 1; i < N; i++)
	{
		psum[i] = psum[i - 1] + box[i];
		mod[i] = psum[i] % K;
	}
}


int sol1()
{
	int answer = 0;
	vector<long long> count(K, 0);
	count[0] += 1;
	for (int i = 0; i < N; i++)
	{
		count[mod[i]]++;
	}
	for (int j = 0; j < K; j++)
	{
		if (count[j] >= 2)
		{
			answer = answer + ((count[j] * (count[j]- 1)) / 2) % 20190101;
		}
	}
	return answer;
}


int sol2(int pos)
{
	int answer;
	vector<int> visit(N, 0);
	for (int i = pos; i < N; i++)
	{
		if (mod[i] == 0)
		{
			answer++;
			continue;
		}
		else if (mod[i] > 0)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (mod[i] == mod[j])
				{
					answer = answer + sol2(j + 1);
					return answer;
				}
			}
		}
	}
}


int main()
{
	std::cin >> C;
	for (int T = 1; T <= C; T++)
	{
		int answer1, answer2;
		memset(box, 0, sizeof(box));
		memset(psum, 0, sizeof(psum));
		memset(mod, 0, sizeof(mod));
		std::cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			std::cin >> box[i];
		}

		partialsum();
		answer1 = sol1();
		answer2 = sol2(0);

		std::cout << answer1 << " " << answer2 << std::endl;
	}
	return 0;
}