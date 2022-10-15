#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long long n;
	long long k;
	long long h;
	long long num;
	long long sum = 0;
	long long max = 0;
	cin >> n;
	cin >> k;
	if (n / k == 0)
		h = n / k;
	else
		h = n / k + 1;
	vector<long long>A;
	vector<long long>B;
	A.clear();
	B.clear();
	for (long long i = 0; i < n; i++)
	{
		cin >> num;
		A.push_back(num);
	}
	if (n == k)
	{
		for (long long i = 0; i < n; i++)
			sum += A[i];
		cout << sum << endl;
	}
	else
	{
		for (long long i = 0; i < k; i++)
		{
			for (long long j = 0; j < h; j++)
			{
				if (i + j*k < n)
				{
					if (max <= A[i + j*k])
						max = A[i + j*k];
				}
				else
					break;
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
}