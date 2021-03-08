#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 2000012
 
using namespace std;
 
typedef long long int lli;
 
lli fact[MAX], invFact[MAX];
 
lli nCr(lli n, lli r);
 
int main()
{
	lli i,t,n,k;
	fact[0] = invFact[0] = invFact[1] = 1;
	for(i=1;i<MAX;i++) fact[i] = (fact[i-1]*i)%MOD;
	for(i=2;i<MAX;i++) invFact[i] = (MOD - MOD/i) * invFact[MOD % i] % MOD;
	for(i=1;i<MAX;i++) invFact[i] = (invFact[i-1] * invFact[i])%MOD;
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",((2LL*nCr(n+k+1, k+2))%MOD - n + MOD)%MOD);
	}
	return 0;
}
 
lli nCr(lli n, lli r)
{
	return (((fact[n]*invFact[r])%MOD)*invFact[n-r])%MOD;
} 