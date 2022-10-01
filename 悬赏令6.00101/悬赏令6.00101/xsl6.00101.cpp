#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long long n;
	long long k;
	long long num;
	long long sum=0;
	long long max=0;
	cin >> n;
	cin >> k;
	vector<long long>A;
	vector<long long>B;
	A.clear();
	for (long long i = 0; i < n; i++)
	{
		cin >> num;
		A.push_back(num);
	}
	for (long long i = 0; i < k; i++)
	{
		for (long long j = 0; j < k; j++)
		{
			if (max < A[i + j*k])
				max = A[i + j*k];
		}
		B.push_back(max);
		max = 0;
	}
	for (long long i = 0; i < k; i++)
	{
		sum += B[i];
	}
	cout << sum << endl;
}