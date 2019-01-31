/*//1번 

#include <string>
#include <vector>

using namespace std;


bool solution(vector<int> arrA, vector<int> arrB) {
	bool answer = true;

	int temp = 0;
	int arrsize;
	arrsize = arrA.size();

	int cnt = 0;
	for (int j = 0; j < arrsize; j++)
	{
		if (cnt > arrsize - 1)
		{
			answer = false;
			break;
		}
		if (arrA[j] == arrB[j])
			continue;
		else
		{
			temp = arrA[0];
			for (int i = 0; i < arrsize - 1; i++)
			{
				arrA[i] = arrA[i + 1];
			}
			arrA[arrsize - 1] = temp;
			j = -1;
			cnt++;
		}
	}

	return answer;
}
*/

/*2번문제
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int l, vector<int> v) {
	int answer = 0;

	//sort
	int arrsize = v.size();
	int temp;
	for (int i = 0; i <arrsize; i++)
	{
		for (int j = i + 1; j < arrsize; j++)
		{
			if (v[i] > v[j])
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	int max = 0;
	int front, back;
	front = v.front();
	back = l - v.back();

	int diff;
	for (int k = 0; k < arrsize - 1; k++)
	{
		diff = v[k + 1] - v[k];
		if (max < diff)
			max = diff;
	}

	answer = max / 2;

	if (max != answer * 2)
		answer++;

	if (front > answer)
		answer = front;
	if (back > answer)
		answer = back;

	return answer;
}
*/


/*3번문제
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> nums)
{
	int answer = 0;

	int bsize = board.size();
	int nsize = nums.size();

	for (int i = 0; i < bsize; i++)
	{
		for (int j = 0; j < bsize; j++)
		{
			for (int k = 0; k < nsize; k++)
			{
				if (nums[k] == board[i][j])
				{
					board[i][j] = 0;
					break;
				}
			}
		}
	}

	//가로
	for (int a = 0; a < bsize; a++)
	{
		int cnt1 = 0;
		for (int b = 0; b < bsize; b++)
		{
			if (board[a][b] == 0)
				cnt1++;
		}
		if (cnt1 == bsize)
			answer++;
	}

	//세로    
	for (int a = 0; a < bsize; a++)
	{
		int cnt2 = 0;
		for (int b = 0; b < bsize; b++)
		{
			if (board[b][a] == 0)
				cnt2++;
		}
		if (cnt2 == bsize)
			answer++;
	}

	//대각선
	int cnt3 = 0;
	int cnt4 = 0;
	for (int a = 0; a < bsize; a++)
	{
		if (board[a][a] == 0)
			cnt3++;
		if (board[bsize - 1 - a][a] == 0)
			cnt4++;
	}
	if (cnt3 == bsize)
		answer++;
	if (cnt4 == bsize)
		answer++;

	return answer;
}
*/