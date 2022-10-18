#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;

const int MAXN = 5005;
const int N = 5000;
const int MOD = 998244353;

ll add(ll a, ll b) {return (a + b) % MOD;}
ll mul(ll a, ll b) {return a * b % MOD;}

ll inv[MAXN], C[MAXN][MAXN], B[MAXN];

void init(){
	for (int i = 0; i <= N; i++) C[i][0] = C[i][i] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j < i; j++){
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
		}
	}
	
	inv[1] = 1;
	for (int i = 2; i <= N + 1; i++){
		inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
	}
	
	B[0] = 1;
	for (int m = 1; m <= N; m++){
		ll sum = 0;
		for (int k = 0; k < m; k++)
		{
			sum = add(sum, mul(C[m + 1][k], B[k]));
		}
		B[m] = mul(MOD - sum, inv[m + 1]);
	}
}

ll mpow(ll a, ll b){
	ll base = a, ans = 1;
	while(b){
		if(b&1){
			ans = mul(ans, base);
		}
		base = mul(base, base);
		b >>= 1;
	}
	return ans;
}

int main(){
	init();
	int n,m;
	cin>>n>>m;
	//if(n>5000) return 0;
	m++;n--;
	ll res = 0;
	for (int k=0;k<=n;k++)
	{
		res=add(res,mul(mul(C[n+1][k],B[k]), mpow(m,n+1-k)));
	}
	cout<<mul(mul(inv[n+1],res),n+1)<<endl;
	return 0;
}
