
/*
Author: Priyanjit Dey
Problem: codechef.com/FEB16/SEATL
Contest: February Long Challenge
Algorithm: Implementation
*/

#include<bits/stdc++.h>
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
struct node{
    ll val,freq,line;
};
node rowcom[1000006],colcom[1000006];
std::map<ll,ll> temp;
std::map<ll,ll>::iterator it1,it2;
ll n,m;
bool cmp(node a,node b){
    if(a.val==b.val){
        if(a.freq==b.freq){
            return a.line<b.line;
        }else return a.freq<b.freq;
    }else return a.val<b.val;
}
int main(){
    register ll t;
    t=scan();
    while(t--){
        register ll i,j,k,sum=0,ans=0,r=0,c=0,y;
        n=scan();m=scan();
        ll mat[n+1][m+1];
        temp.clear();
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                mat[i][j]=scan();
            }
        }
        node com;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                temp[mat[i][j]]++;
            }
            for(it1=temp.begin();it1!=temp.end();it1++){
                r++;
                rowcom[r].val=it1->ff;rowcom[r].freq=it1->ss;rowcom[r].line=i;
            }
            temp.clear();
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                temp[mat[j][i]]++;
            }
            for(it1=temp.begin();it1!=temp.end();it1++){
                c++;
                colcom[c].val=it1->ff;colcom[c].freq=it1->ss;colcom[c].line=i;
            }
            temp.clear();
        }
        sort(rowcom+1,rowcom+1+r,cmp);
        sort(colcom+1,colcom+1+c,cmp);
        rowcom[0].val=rowcom[0].freq=rowcom[0].line=colcom[0].val=colcom[0].freq=colcom[0].line=0;
        for(i=r,j=c;i>=1 && j>=1;){
            while(i>=1){
                y=j;
                while(y>=1){
                    sum=rowcom[i].freq+colcom[y].freq;
                    if(mat[rowcom[i].line][colcom[y].line]==rowcom[i].val){
                        sum-=1;
                    }
                    ans=max(ans,sum);
                    if(colcom[y].val==colcom[y-1].val && colcom[y].freq==colcom[y-1].freq){
                    	y--;
                    }else break;
                }
                if(rowcom[i].val==rowcom[i-1].val && rowcom[i].freq==rowcom[i-1].freq){
                	i--;
                }else break;
            }
            while(rowcom[i].val==rowcom[i-1].val && i>=1){
                i--;
            }
            while(colcom[y].val==colcom[y-1].val && y>=1){
                y--;
            }
            i-=1;j=y-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//11545686822
