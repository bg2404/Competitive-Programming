#include<bits/stdc++.h>
using namespace std;
int T,N,K[100001],G,p[100001],cnt,chkcess[100001]={},chkce[100001]={};
int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        cnt=0;
        memset(chkcess,0,sizeof(chkcess));
        memset(chkce,0,sizeof(chkce));
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&K[j]);
            for(int k=1;k<=K[j];k++)
            {
                scanf("%d",&G);
                if(!chkcess[j]&&!chkce[G])
                {
                    p[j]=G;
                    chkcess[j]=1;
                    chkce[G]=1;
                    cnt++;
                }
            }
        }
        if(cnt==N)
        {
            printf("OPTIMAL\n");
            continue;
        }
        else
        {
            for(int j=1;j<=N;j++)
                if(!chkcess[j])
                {
                    for(int k=1;k<=N;k++)
                        if(!chkce[k])
                        {
                            printf("IMPROVE\n%d %d\n",j,k);
                            break;
                        }
                    break;
                }
        }
    }
}