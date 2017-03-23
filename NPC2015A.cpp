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

vi adjlist[27];
string s;
int main(){
    fastio;
    register ll i,j,k,p,q;
    char x,y;
    //scanf("%s",&s);
    cin>>s;
    k=s.size();
    for(i=0;i<26;i++){
        adjlist[i].clear();
    }
    for(i=0;i<k;i++){
        adjlist[(ll)s[i]-65].pb(i);
    }
    //scanf("%lld",&q);
    cin>>q;
    while(q--){
        cin>>x>>y;
        i=(ll)x-65;
        j=(ll)y-65;
        if(!adjlist[i].size() || !adjlist[j].size()){
            printf("TIDAK\n");continue;
        }

        if((adjlist[j][adjlist[j].size()-1] - adjlist[i][0])>=1){
            printf("YA\n");
        }else printf("TIDAK\n");
    }
    return 0;
}