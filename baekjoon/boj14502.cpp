#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int a[20][20];
int d[20][20];
int k[100];
vector<vector<int>> combi(int k[], int n)
{
	vector<int> d;
	for (int i = 0; i < n - 3; i++)
		d.push_back(0);

	for (int i = 0; i < 3; i++)
		d.push_back(1);

	vector<vector<int>> ans;
	do {
		vector<int> current;
		for (int i = 0; i < n; i++)
		{
			if (d[i] == 1)
				current.push_back(k[i]);
		}
		ans.push_back(current);

	} while (next_permutation(d.begin(), d.end()));

	sort(ans.begin(), ans.end());
	/*
	for (auto &v : ans) {
	for (int i = 0; i<v.size(); i++)
	cout << v[i] << ' ';

	cout << '\n';

	}
	*/

	return ans;
}
int main()
{

	int pop = 3;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	//wall
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				k[pop - 3] = pop;
				a[i][j] = pop;
				pop++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = a[i][j];

	vector<vector<int>> ans;

	ans = combi(k, pop - 3);

	int cnt = 0;
	int im = n + m - 1;
	int max = 0;

	for (auto &v : ans) {

		cnt = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = d[i][j];

		//wall
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {

				if (a[i][j] == v[0] || a[i][j] == v[1] || a[i][j] == v[2])
					a[i][j] = 1;
				else
				{
					if (a[i][j] != 1 && a[i][j] != 2)
						a[i][j] = 0;
				}
			}
		}
		//virus
		im = n + m - 1;

		while (im--)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (a[i][j] == 2)
					{
						if (i + 1 < n && a[i + 1][j] == 0)
							a[i + 1][j] = 2;
						if (j - 1 >= 0 && a[i][j - 1] == 0)
							a[i][j - 1] = 2;
						if (i - 1 >= 0 && a[i - 1][j] == 0)
							a[i - 1][j] = 2;
						if (j + 1 < m && a[i][j + 1] == 0)
							a[i][j + 1] = 2;

					}
				}
			}

		}

		//minimun zeros

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)cnt++;
			}
		}

		if (cnt > max)
			max = cnt;
	}

	printf("%d", max);

	return 0;

}