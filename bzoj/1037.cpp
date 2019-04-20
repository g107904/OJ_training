#include <iostream>  
#include <iomanip>
#include <fstream>
#include <cstdio> 
#include <ctype.h> 
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <queue>  
#include <set>
#include <stack>  
#include <algorithm>  
#define INF 0x7fffffff  
#define EPS 1e-12
#define eps 1e-7
#define MOD 12345678
#define PI 3.141592653579798  
#define MAXM 1000010  
#define maxn 100010
#define max(a,b) a > b ? a : b
int dp[310][155][25][25],n,m,k;
using namespace std; 
int main()  
{   
    scanf("%d%d%d",&n,&m,&k);
     dp[1][1][1][0]=dp[1][0][0][1]=1;
     for(int i = 1;i <= n+m;i++)
         for(int x = 0;x <= i && x <= n;x++)
             for(int c = 0;c <= x && c <= k;c++)
                 for(int d = 0;d <= k;d++)
                 {
                     if(c+1 <= k && x+1 <= n)
                        dp[i+1][x+1][c+1][max(d-1,0)] += dp[i][x][c][d] % MOD;
                     if(d+1 <= k && i-x < m)
                        dp[i+1][x][max(c-1,0)][d+1] += dp[i][x][c][d] % MOD;
                 }
    int ans = 0;
    for(int i = 0;i <= k;i++)
        for(int j = 0;j  <= k;j++)
            ans += dp[n+m][n][i][j] % MOD;
    printf("%d\n",ans % MOD);
	return 0;  
}  