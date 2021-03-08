    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
        int t;
        cin>>t;
        while(t--){
            int n,k;
            cin>>n>>k;
            string ans="";
            int check = -1;
            for(int i=0;i<k;i++) ans += "a";
            for(int i=k;i<n;i++){
                if(check == -1){
                    ans += 'c';
                    check = 0;
                }
                else if(check == 0){
                    ans += 'b';
                    check = 1;
                }
                else{
                    ans += 'a';
                    check = -1;
                }
            }
            cout<<ans<<"\n";
        }
    }