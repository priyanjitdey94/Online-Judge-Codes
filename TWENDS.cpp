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
#define inf 1000000000
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define block 317

inline ll scan(){
    char c = getchar_unlocked();
    register ll x = 0;
    bool neg=false;
    if(c=='-'){
        neg=true;
    }
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    if(neg==false) return x;
    else if(neg==true) return -1*x;
}


ll dp[1002][1002],n,ar[112345];

ll solve(ll x,ll y){
    if(x>y) return 0;

    if(dp[x][y]!=-1) return dp[x][y];

    if(x==y){
        dp[x][y]=ar[x];
        return dp[x][y];
    }

    ll lx,ly,rx,ry;
    if(ar[x+1]>=ar[y]){
        lx=x+2;ly=y;
    }else{
        lx=x+1;ly=y-1;
    }

    if(ar[x]>=ar[y-1]){
        rx=x+1;ry=y-1;
    }else{
        rx=x;ry=y-2;
    }

    dp[x][y]=max(ar[x]+solve(lx,ly),ar[y]+solve(rx,ry));
    return dp[x][y];
}

int main(){
    fastio;
    register ll i,j,k,p,q,l,x,y,t1=1;
    cin>>n;
    while(n!=0){
        ll sum=0;
        for(i=1;i<=n;i++){
            cin>>ar[i];
            sum+=ar[i];
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        cout<<"In game "<<t1<<", the greedy strategy might lose by as many as"<< sum-solve(1,n) <<" points."<<endl;
        cin>>n;t1++;
    }
    return 0;
}