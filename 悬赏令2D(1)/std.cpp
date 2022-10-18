#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const ll N = 1e6+10;

ll pl[N], pr[N], fac[N];

ll qpow(ll a, ll b) {
    ll ans = 1;
    for(; b >= 1; b >>= 1, a = 1ll * a * a % MOD)
        if(b & 1) ans = 1ll * ans * a % MOD;
    return ans;
}

int main() {
    ll n, k, y = 0, ans = 0;
	ll xx,yy;
	cin>>xx>>yy;
	if(yy==1){
		cout<<xx%MOD<<endl;
		return 0;
	} 
    if(xx==1){
        cout<<yy%MOD<<endl;
        return 0;
    }
	if(yy<=xx){
		ll sum=0;
		for(ll i=1;i<=yy;i++)
		{
			sum=(sum+qpow(i,xx-1))%MOD;
		}
		cout<<sum*xx%MOD<<endl;
	}
	else 
	{
		n=yy,k=xx-1;
	    pl[0]=pr[k+3]=fac[0]=1;
	    for(ll i = 1; i <= k +2; i ++)
	        pl[i] = 1ll * pl[i - 1] * (n - i) % MOD;
	    for(ll i = k + 2; i >= 1; i --)
	        pr[i] = 1ll * pr[i + 1] * (n - i) % MOD;
	    for(ll i = 1; i <= k + 2; i ++)
	        fac[i] = 1ll * fac[i - 1] * i % MOD;
	    for(ll i = 1; i <= k + 2; i ++) {
	        y = (y + qpow(i, k)) % MOD;
	        ll a = pl[i - 1] * 1ll * pr[i + 1] % MOD;
	        ll b = fac[i - 1] * ((k - i) & 1 ? -1ll : 1ll) * fac[k + 2 - i] % MOD;
	        ans = (ans + 1ll * y * a % MOD * qpow(b, MOD - 2) % MOD) % MOD;
	    }
    	cout << (ans * xx % MOD + MOD) % MOD << endl;
	}
    return 0;
}
