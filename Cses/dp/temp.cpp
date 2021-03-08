#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll CountSteps(string s1, string s2) 
{ 
    ll i = 0, j = 0,size = s1.length(); 
    ll result = 0; 
    while (i < size) { 
        j = i; 
        while (s1[j] != s2[i]) { 
            j += 1; 
        } 
        while (i < j) { 
            char temp = s1[j]; 
            s1[j] = s1[j - 1]; 
            s1[j - 1] = temp; 
            j -= 1; 
            result += 1; 
        } 
        i += 1; 
    } 
    return result; 
} 

void solve(){
    ll n,ss=0,ts=0;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string s1=s,s2=t;
    unordered_set<char>u1;
    unordered_set<char>u2;
    for(char c:s) u1.insert(c); 
    for(char c:t) u1.insert(c); 
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1 != s2){
		cout<<"NO"<<"\n";
		return;
	}
	if(u1.size() == u2.size() && u1.size()<n){
		cout<<"YES"<<"\n";
		return;
	}
	ss = CountSteps(s,s1);
	ts = CountSteps(t,s2);
	if(abs(ss-ts)%2 == 0) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}