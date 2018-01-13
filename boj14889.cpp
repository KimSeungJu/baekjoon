#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

//find ability value
int power(vector<vector<int>> arr,vector<int> xx)
{
	int sum=0;

	// combination (N/2)C(2)
	vector<int> d;
	for (int i = 0; i < xx.size() - 2; i++)
		d.push_back(0);
	for (int i = 0; i < 2; i++)
		d.push_back(1);

	vector<vector<int>> ans;
	do {
		vector<int> current;
		for (int i = 0; i < xx.size(); i++)
		{
			if (d[i] == 1)
				current.push_back(xx[i]);
		}
		ans.push_back(current);
	} while (next_permutation(d.begin(), d.end()));
	
	//sum ability value
	for (auto &v : ans)
	{
		sum += arr[v[0]-1][v[1]-1];
		sum += arr[v[1] - 1][v[0] - 1];
		//cout << '\n';
	}
	//cout << '\n';


	return sum;

}

int main()
{
	//problem condition
	int N;
	int x;
	cin >> N;
	x = N / 2;
	int real_ans;

	//new array arr[N][N], initialization of zero
	vector<vector<int>> arr(N, vector<int>(N, 0));
	vector<int> a(N);

	//input the array
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
		a[i] = i + 1;


	//divide team
	vector<int> d;
	for (int i = 0; i < x; i++)
		d.push_back(0);
	for (int i = 0; i < N - x; i++)
		d.push_back(1);

	vector<vector<int>> ans;
	do {
		vector<int> current;
		for (int i = 0; i < N; i++)
		{
			if (d[i] == 1)
				current.push_back(a[i]);
		}
		ans.push_back(current);
	} while (next_permutation(d.begin(), d.end()));

	//save the number of team cases - caution of stack size
	vector<int> sumsum(ans.size());

	int k = 0;
	for (auto &v : ans)
	{
		/*
		for (int i = 0; i<v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		*/
		sumsum[k] = power(arr, v);
		//cout << k << ':' << sumsum[k] << '\n';
		k++;
	}
	//cout << '\n';

	//find minimum of ability value
	int q = k / 2;
	k--;
	real_ans = abs(sumsum[k] - sumsum[0]);

	for (int i = 1; i <= q; i++)
	{
		if(real_ans > abs(sumsum[k - i] - sumsum[i]))
			real_ans= abs(sumsum[k - i] - sumsum[i]);
	}
	
	//print answer
	cout << real_ans;

	return 0;

}