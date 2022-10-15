#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>

using namespace std;
long long f(int a, int b)
{
	long long mi = 1;
	for (long long i = 0; i < b; i++)
	{
		mi = mi*a;
	}
	return mi % 998244353;
}
int main()
{
	long long n;
	long long m;
	cin >> n;
	cin >> m;
	long long c = n - 1;
	long long sum = 0;
	for (long i = 1; i <= m; i++)
	{
		sum = (sum % 998244353 + (n % 998244353 * f(i, c)) % 998244353) % 998244353;
	}
	cout << sum << endl;
}