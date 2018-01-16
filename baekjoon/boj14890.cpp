#include <iostream> 
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	//문제 조건 입력
	int N, L;
	int cnt = 0; //개수
	bool aaa = true;
	cin >> N >> L;
	//배열 생성 arr[N][N], 0으로 값 초기화
	vector<vector<int>> arr(N, vector<int>(N, 0));
	vector<vector<int>> arr2(N, vector<int>(N, 0));

	//값 삽입
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			arr2[j][i] = arr[i][j];
		}

	// 판단
	for (int i = 0; i < N; i++)
	{
		vector<int> a(N, 0);
		aaa = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (abs(arr[i][j] - arr[i][j + 1]) > 1)
				break;
			else if (arr[i][j] - arr[i][j + 1] == 1)
			{
				if (L == 1)
				{
					if (j + 1 > N - 1)
						aaa = false;
					else
						a[j + 1] = 1;
				}
				else
				{
					for (int k = 1; k < L; k++)
					{
						if (j + 1 + k > N - 1)
							aaa = false;
						else
						{
							if (arr[i][j + 1] != arr[i][j + 1 + k])
								aaa = false;
						}

						if (k == L - 1 && aaa == true)
						{
							for (int k = 0; k < L; k++)
								a[j + 1 + k] = 1;
						}

					}
				}
			}
			else if (arr[i][j] - arr[i][j + 1] == -1)
			{
				if (L == 1)
				{
					if (a[j] == 1)
						aaa = false;
					else
						a[j] = 1;
				}
				else
				{
					for (int k = 1; k < L; k++)
					{
						if (j - k < 0)
							aaa = false;
						else
						{
							if (arr[i][j] != arr[i][j - k] || a[j] == 1 || a[j - k] == 1)
								aaa = false;
						}

					}
				}
			}

			if (aaa)
			{
				if (j == N - 2)
					cnt++;
			}
			else
				break;
		}
	}

	//판단2
	for (int i = 0; i < N; i++)
	{
		vector<int> a(N, 0);
		aaa = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (abs(arr2[i][j] - arr2[i][j + 1]) > 1)
				break;
			else if (arr2[i][j] - arr2[i][j + 1] == 1)
			{
				if (L == 1)
				{
					if (j + 1 > N - 1)
						aaa = false;
					else
						a[j + 1] = 1;
				}
				else
				{
					for (int k = 1; k < L; k++)
					{
						if (j + 1 + k > N - 1)
							aaa = false;
						else
						{
							if (arr2[i][j + 1] != arr2[i][j + 1 + k])
								aaa = false;
						}

						if (k == L - 1 && aaa == true)
						{
							for (int k = 0; k < L; k++)
								a[j + 1 + k] = 1;
						}

					}
				}
			}
			else if (arr2[i][j] - arr2[i][j + 1] == -1)
			{
				if (L == 1)
				{
					if (a[j] == 1)
						aaa = false;
					else
						a[j] = 1;
				}
				else
				{
					for (int k = 1; k < L; k++)
					{
						if (j - k < 0)
							aaa = false;
						else
						{
							if (arr2[i][j] != arr2[i][j - k] || a[j] == 1 || a[j - k] == 1)
								aaa = false;
						}

					}
				}
			}

			if (aaa)
			{
				if (j == N - 2)
					cnt++;
			}
			else
				break;
		}
	}


	printf("%d\n", cnt);

	return 0;

}