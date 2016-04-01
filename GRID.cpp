
/*
Author: Priyanjit Dey
Problem: http://www.spoj.com/problems/SERGRID/
Contest: Practice
Algorithm: BFS, shortest path
*/


#include <bits/stdc++.h>
using namespace std;

#define ll int
#define dd double
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpi vector<pair<ll,ll> >
#define reset(a,b) memset(a,b,sizeof(a))
#define modu 1000000007
#define inf INT_MAX
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define block 317

ll n,m,dp[512][512];
string s[512];
queue<pii > q;

bool validpos(ll x,ll y){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    else return true;
}
void bfs(ll a,ll b){
    q.push(mp(a,b));
    ll i,j,x,y;pii temp;
    while(!q.empty()){
        temp=q.front();q.pop();
        x=temp.ff;y=temp.ss;
        j=s[x][y]-'0';
        if(validpos(x-j,y)){
            if(dp[x-j][y]>dp[x][y]+1){
                dp[x-j][y]=dp[x][y]+1;
                q.push(mp(x-j,y));
            }
        }
        if(validpos(x+j,y)){
            if(dp[x+j][y]>dp[x][y]+1){
                dp[x+j][y]=dp[x][y]+1;
                q.push(mp(x+j,y));
            }
        }
        if(validpos(x,y-j)){
            if(dp[x][y-j]>dp[x][y]+1){
                dp[x][y-j]=dp[x][y]+1;
                q.push(mp(x,y-j));
            }
        }
        if(validpos(x,y+j)){
            if(dp[x][y+j]>dp[x][y]+1){
                dp[x][y+j]=dp[x][y]+1;
                q.push(mp(x,y+j));
            }
        }
    }
}

int main(){
    fastio;
    cin>>n>>m;
    register ll i,j,k,p,x,y,ans=0;
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=0;
    bfs(0,0);
    dp[n-1][m-1]==inf?printf("-1\n"):printf("%d\n",dp[n-1][m-1]);
    return 0;
}
//9231656527