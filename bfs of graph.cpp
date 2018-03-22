#include <iostream>

using namespace std;

int main()
{
    int n,m,a,b,i,j,head,tail,cur,book[10]={0}, edge[10][10],que[101]={0};
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(i==j)
            edge[i][j]=0;
        else
            edge[i][j]=999;
    }
    for(i=1;i<=m;i++)//初始化邻接矩阵
    {
        cin>>a>>b;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    head=1;//初始化队列
    tail=1;
    que[tail]=1;
    tail++;
    book[1]=1;
    while(head<tail&&tail<=n)
    {
        cur=que[head];//获得当前队列头结点
        for(i=1;i<=n;i++)//以cur扩展队列。
        {
            if(edge[cur][i]==1&&book[i]==0)
            {
                que[tail]=i;
                tail++;
                book[i]=1;
            }
            if(tail>n)
            {
                break;
            }
        }
        head++;
    }
    for(i=1;i<=n;i++)
        cout<<que[i]<<' ';
    return 0;
}
