#include<iostream> 
using namespace std;

const int MOD=998244353;

long long mpow(long long a,long long x){
	if(x==0) return 1;
	if(x==1) return a%MOD;
	long long t=mpow(a,x>>1);
	if(x&1){
		return (t*t%MOD)*(a%MOD)%MOD;
	}else{
		return (t*t%MOD);
	}
}

int main() {
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		ans=(ans+mpow(i,n-1))%MOD;
	}
	ans=(n%MOD)*ans%MOD;
	cout<<ans<<endl;
	return 0;
}
