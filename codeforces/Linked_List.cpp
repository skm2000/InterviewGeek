// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // class ListNode{
// // // public:
// // //     int value = 0;
// // //     ListNode *next;
    
// // //     ListNode(int value){
// // //         this->value = value;
// // //         next = nullptr;
// // //     }
// // // };


// // // class LinkedListCycle{
// // // private:
// // //     static int findCycleLength(ListNode* node){
// // //         ListNode* current = node;
// // //         int length = 0;
// // //         do{
// // //             current = current -> next;
// // //             length++;
// // //         } while(current != node);
        
// // //         return length;
// // //     }
    
// // //     static ListNode *findStarting(int cycleLength, ListNode* head){
// // //         ListNode* p1 = head;
// // //         ListNode* p2 = head;
        
// // //         while(cycleLength > 0){
// // //             p2 = p2 -> next;
// // //             cycleLength--;
// // //         }
        
// // //         while(p1 != p2){
// // //             p1 = p1 -> next;
// // //             p2 = p2 -> next;
// // //         }
// // //         return p1;
// // //     }
// // // public:
// // //     static bool hasCycle(ListNode *node){
// // //         ListNode *slow = node;
// // //         ListNode *fast = node;
        
// // //         while(slow != nullptr && fast->next != nullptr){
// // //             slow = slow -> next;
// // //             fast = fast -> next -> next;
            
// // //             if(slow == fast){
// // //                 return true;
// // //             }
// // //         }
        
// // //         return false;
// // //     }
    
// // //     static ListNode *findStartCycle(ListNode *node){
// // //         ListNode *slow = node;
// // //         ListNode *fast = node;
// // //         int cycleLength = 0;
        
// // //         while(slow != nullptr && fast->next != nullptr){
// // //             slow = slow -> next;
// // //             fast = fast -> next -> next;
            
// // //             if(slow == fast){
// // //                 cycleLength = findCycleLength(slow);
// // //                 cout << "Cycle Length : " << cycleLength << "\n"; 
// // //                 break;
// // //             }
// // //         }
        
// // //         ListNode *start = findStarting(cycleLength, node);
// // //         return start;
// // //     }
// // // };



// // // int main(){
// // //     ListNode *head = new ListNode(1);
// // //     head -> next = new ListNode(2);
// // //     head -> next -> next = new ListNode(3);
// // //     head -> next -> next -> next = new ListNode(4);
// // //     head -> next -> next -> next -> next = head -> next;
    
// // //     cout << "Has Cycle : " << LinkedListCycle :: hasCycle(head) << "\n";
// // //     int start = LinkedListCycle :: findStartCycle(head)->value;
// // //     cout << "Cycle start : " << start << "\n";
// // // }

// // #include <bits/stdc++.h>  
// // #define ll long long  
// // const ll mod = 1000000007;  
// // using namespace std;
// // ll MOD = 998244353;
// // #define MAX 1000007
// // #define dbg(x) cout<<#x<<" = "<<x<<endl
// // #define vdbg(v) for(auto x : v) cout<<x<<endl
// // #define INF 2e18
// // const ll N = 1e5+7;
// // #define all(x) x.begin(),x.end()
// // #define mem0(a) memset(a,0,sizeof(a))
// // #define mem1(a) memset(a,-1,sizeof(a))
// // #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// // void solve(){
// //     ll n, k;
// //     cin >> n >> k;
// //     vector<string>a(n);
// //     for(auto &i : a){
// //        cin >> i;
// //     }
// //     bool check = true;
// //     for(int i = 0; i < n; i++){
// //         vector<ll>freq(26,0);
// //         for(int j = 0; j < a[i].size(); j++){
// //             freq[a[i][j]-'a']++;
// //         }
// //         ll m = 0;
// //         for(ll j=0; j<26; j++){
// //             m = max(m, freq[j]);
// //         }
// //         if(m<k){
// //             check = false;
// //         }
// //     }
// //     if(check){
// //         cout << "YES\n";
// //         return;
// //     }
// //     cout<<"NO\n";
// // }


// // int main()
// // {
// //     fast_cin();
// //     ll t;
// //     cin >> t;
// //     while(t--) {
// //         solve();
// //     }
// //     return 0;
// // }





// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<endl
// #define INF 2e18
// const ll N = 1e5+7;
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// ll uniqueLetterString(string S) {
//     ll index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
//     memset(index, -1, sizeof(ll) * 52);
//     for (ll i = 0; i < N; ++i) {
//         ll c = S[i] - 'A';
//         res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
//         index[c][0] = index[c][1];
//         index[c][1] = i;
//     }
//     for (ll c = 0; c < 26; ++c)
//         res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
//     return res;
// }

 

// void solve(){
//     ll n;
//     cin >> n;
//     string s;
//     cin >> s;
//     transform(s.begin(), s.end(), s.begin(), ::toupper);
//     ll count = uniqueLetterString(s);
//     cout << count << endl;
// }


// int main()
// {
//     fast_cin();
//     ll t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>  
using namespace std;
 

bool check(int n)
{
    int x;
    x = round(cbrt(n));
    if (x * x * x == n) {
        return true;
    }
    else {
        return false;
    }
}

int next(int n)
{
    int f = floor(cbrt(n)) + 1;
    return f * f * f;
}

void solve(){
    // int n;
    // cin >> n;
    // vector<int>a(n);
    // int sum = 0;
    // for(auto &i : a){
    //     cin >> i;
    //     sum += i;
    // }
    // if(check(sum)){
    //     cout << "YES\n";
    // }else{
    //     cout << next(sum)-sum << "\n";
    // }
    int n, k;
    cin >> n >> k;
    k--;
    vector<int>a;
    while(n){
        a.push_back(n%10);
        n/=10;
    }
    reverse(a.begin(), a.end());
    int x = a.size();
    k = k % x;
    vector<int>p;
    for(int i = 0; i < x; i++)
    {
       if(i < k)
       {
           p.push_back(a[x + i - k]);
       }
       else
       {
           p.push_back(a[i - k]);
       }
    }
    int ans = 0;
    for(int i=0; i<x; i++){
        ans = (ans*10 + p[i]);
    }
    cout << ans << "\n";
}


int main()
{
    solve();
    return 0;
}