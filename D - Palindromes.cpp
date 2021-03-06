#include <bits/stdc++.h>

using namespace std;

int w[505][505],g[505][505],f[505][505];
string s;
int n,m;

int dfs (int n, int k)
{
    if(n==0)
        return 0;
    dfs(w[n][k],k-1);
    int neew = n-w[n][k], j = w[n][k];
    if (j!=0)
        cout<<"+";
    for (int i=1 ; i<=(neew+1)/2 ; ++i)
        cout<<s[i+j-1];
    for (int i=neew/2 ; i; i--)
        cout<<s[i+j-1];
}


int main()
{

    cin>>s;
    cin>>m;
    n=s.size();
    for (int i=n; i; i--)
        for (int j=i+1; j<=n; j++)
        {
            g[i][j]=g[i+1][j-1];
            if (s[i-1]!=s[j-1])
                g[i][j]++;
        }

    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            f[i][j]=n;/**/

    f[0][0]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (j<=i)
                for (int k=0; k<i; k++)
                    if (f[k][j-1]+g[k+1][i]<=f[i][j])
                    {
                        f[i][j]=f[k][j-1]+g[k+1][i];
                        w[i][j]=k;
                    }

    int ans=0;

    for (int i=1; i<=m; i++)
        if (f[n][i]<f[n][ans])
            ans=i;

    cout<<f[n][ans]<<endl;
    dfs(n,ans);
    return 0;

}

