#include<bits/stdc++.h>
#define MT(a,b) memset(a,b,sizeof(a));
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double E=2.718281828459;
const int INF=0x3f3f3f3f;
 
int n,m,k;
 
bool city[1005];
int edge[1005];
int point[1005];
 
int p[1005];
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
 
void init()
{
    memset(city,0,sizeof(city));
    memset(edge,0,sizeof(edge));
    memset(point,0,sizeof(point));
    for(int i=1;i<=1000;i++)
    {
        p[i]=i;
        point[i]=1;
    }
}
 
int main()
{
    init();
    int s,e,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&x);
        city[x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&s,&e);
        x=find(s);
        y=find(e);
        if(x!=y)
        {
            p[x]=y;
            edge[y]+=edge[x]+1;
            point[y]+=point[x];
        }
        else
            edge[x]++;
    }
    int root[1005],sum=0;
    map<int,int>q;
    for(int i=1;i<=n;i++)
    {
        root[i]=find(i);
        if(city[i])
            q[root[i]]=2;/// is marked as containing government
        else
            q[root[i]]=max(q[root[i]],1);
    }
    map<int,int>::iterator u=q.begin();
    int no_p=0,no_e=0;
    int maxn=0;
    while(u!=q.end())
    {
        s=u->first;
                 If(u->second==1)/// does not include government
        {
            no_p+=point[s];
            no_e+=edge[s];
        }
                 Else ///contains government
        {
            sum+=(point[s]*(point[s]-1))/2-edge[s];
                         ///Complete the complete map
            maxn=max(maxn,point[s]);
        }
        u++;
    }
         Sum+=no_p*(no_p-1)/2-no_e;/// non-government complete map
         Sum+=no_p*maxn;///With government and non-government supplements with the most points complete map
    printf("%d\n",sum);
    return 0;
}