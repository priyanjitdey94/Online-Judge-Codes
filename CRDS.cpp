#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
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
ll dp[1123456];

void pre(){
    ll i,j;
    dp[1]=3;
    for(i=2;i<=1000000;i++){
        j=(i*3);
        dp[i]=(dp[i-1]+j);
    }
}

int main(){
    pre();
    ll t;
    cin>>t;
    while(t--){
        register ll n;
        scanf("%lld",&n);
        printf("%lld\n",(dp[n]-n)%1000007);
    }
    return 0;
}