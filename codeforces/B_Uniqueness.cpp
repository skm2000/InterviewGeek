#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int ans = n - 1;
    map<int, int> freq; 
    for(int i = 0; i < n; ++i){
        bool validPrefix = true;
        for(int j = 0; j < i; ++j){
            freq[a[j]]++;
            if(freq[a[j]] == 2){
                validPrefix = false;
                break;
            }
        }
        int min_index_suffix = n;
        for(int j = n - 1; j >= i; --j){
            freq[a[j]]++;
            if(freq[a[j]] == 1){
                min_index_suffix = j;
            }
            else break;
        }
        if(validPrefix){
            ans = min(ans, min_index_suffix - i);
        }
        
        freq.clear();
    }
    cout << ans << '\n';
} 