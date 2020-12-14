#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    int c = 0,ans = INT_MAX;
    while(n != 0){
        int t = n;
        while(t > 0){
            int x = t%10;
            t /= 10;
            ans = min(ans,n-x);
        }
        n = ans;
        c++;
    }
    cout<<c<<"\n";
}