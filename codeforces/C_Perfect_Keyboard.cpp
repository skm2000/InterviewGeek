#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct node
{
    int l,r,f;
}flag[26];
int main()
{
    ios::sync_with_stdio(false);
    int t,i;
    string s;
    char a[105];
    cin >> t;
    while(t--)
    {
        cin >> s;
        for(i=0;i<26;i++)
            flag[i].l=flag[i].r=flag[i].f=-1;
        int l=50,r=50,flag1=1,len=s.length();
        a[l]=s[0];
        flag[s[0]-'a'].f=1;
        for(i=1;i<len;i++)
        {
            if(flag[s[i]-'a'].f==-1)   //The letter is not added
            {
                if(flag[s[i-1]-'a'].r==-1)   //Add to the right
                {
                    flag[s[i-1]-'a'].r=s[i];
                    flag[s[i]-'a'].l=s[i-1];
                    flag[s[i]-'a'].f=1;
                    a[++r]=s[i];
                }
                else    //The rightmost letter of the letter string cannot be added to the right
                {
                    if(flag[s[i-1]-'a'].l==-1)  //Add to the left
                    {
                        flag[s[i-1]-'a'].l=s[i];
                        flag[s[i]-'a'].r=s[i-1];
                        flag[s[i]-'a'].f=1;
                        a[--l]=s[i];
                    }
                    else
                    {
                        flag1=0;
                        break;
                    }
                }
            }
            else     //The letter has been added
            {
                if(flag[s[i-1]-'a'].l!=s[i]&&flag[s[i-1]-'a'].r!=s[i])
                {
                    flag1=0;
                    break;
                }
            }
        }
        if(!flag1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for(i='a';i<='z';i++)
            {
                if(flag[i-'a'].f==-1)
                    a[++r]=i;
            }
            for(i=l;i<=r;i++)
                cout << a[i];
            cout << endl;
        }
    }
    return 0;
}