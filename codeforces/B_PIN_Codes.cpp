#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int p[10] = {0,1,10,100,1000};

int b[10005],vis[10005];
int n;

int modify(int x,int y,int z)//The y-th bit of x is changed to z.
{
    int num = x / p[y] % 10;
    x -= p[y] * num;
    x += p[y] * z;
    return x;
}

int solve()
{
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        int flag = 0;
        if(vis[b[i]] > 1)
        {
            for(int j = 1;j <= 4;j++)
            {
                for(int k = 0;k <= 9;k++)
                {
                    int tmp = modify(b[i],j,k);
                    if(vis[tmp]==0)
                    {
                        ans++;
                        vis[tmp]++;
                        vis[b[i]]--;
                        b[i] = tmp;
                        flag = 1;
                        break;
                    }
                }
                if(flag)break;
            }
        }
    }
    return ans;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&b[i]);
            vis[b[i]]++;
        }
        int ans = solve();
        printf("%d\n",ans);
        for(int i = 1;i <= n;i++)printf("%04d\n",b[i]);
    }
    return 0;
}
