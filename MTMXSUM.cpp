/*

Author: Priyanjit Dey
Problem: https://www.codechef.com/FEB16/problems/MTMXSUM/
Contest: February Long Challenge
Platform: CodeChef
Algorithm Used: Segment Tree, Stack.
*/


#include<bits/stdc++.h>
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
    ll val,prefix,suffix,repeat;
};
node row[100002],col[100002];
ll n,a[112345],b[112345],pointrow[100002],pointcol[100002];
ll segtree_a[500005],segtree_b[500005],lazya[500005],lazyb[500005];
stack<pair<ll,ll> > st;
 
void update(ll node, ll x, ll y, ll i, ll j, ll inc, ll t[],ll lazy[]){
    if(x>y) return;
    if (lazy[node]!=0){
        t[node]=(t[node]+(lazy[node]*(y-x+1))%modu)%modu;
        if (x!=y){
            lazy[node*2]=(lazy[node*2]+lazy[node])%modu;
            lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%modu;
        }
        lazy[node]=0;
    }
    if(x>y||x>j||y<i) return;
    
    if (x>=i && y<=j){
        t[node]=(t[node]+(inc*(y-x+1))%modu)%modu;
        if (x!=y){
            lazy[node*2]=(lazy[node*2]+inc)%modu;
            lazy[node*2+1]=(lazy[node*2+1]+inc)%modu;
        }
        return;
    }
    
    update(node*2, x, (x+y)/2, i, j, inc,t,lazy);
    update(node*2+1, (x+y)/2+1, y,i, j, inc,t,lazy);
    t[node] = (t[node*2] + t[node*2+1])%modu;
}
ll query(ll node, ll x, ll y, ll i, ll j, ll t[], ll lazy[])
{
    if(x>y||x>j||y<i) return 0;
    if (lazy[node] !=0 )
    {
        t[node]=(t[node]+(lazy[node]*(y-x+1))%modu)%modu;
        if (x!=y)
        {
            lazy[node*2]=(lazy[node*2]+lazy[node])%modu;
            lazy[node*2+1]=(lazy[node*2 +1]+lazy[node])%modu;
        }
        lazy[node]=0;
    }
    
    if (x>=i && y<=j) return t[node];
    
    ll q1=query(node*2, x, (x+y)/2, i, j,t,lazy);
    ll q2=query(node*2+1, (x+y)/2+1, y, i, j,t,lazy);
    
    return (q1+q2)%modu;
}

int main(){
    register ll i,j,x,y,k=19,sum=0,p,q,ms,mb;
    pii temp;
    n=scan();
    reset(segtree_a,0);reset(segtree_b,0);
    for(i=0;i<n;i++){
        j=scan();
        a[i]=i+j+1;
        row[i].val=a[i];
        pointcol[i]=pointrow[i]=0;
    }
    for(i=0;i<n;i++){
        //b[i]=scan();
        j=scan();
        b[i]=i+j+1;
        col[i].val=b[i];col[i].repeat=0;
    }
    //prefix and suffix of rows
    for(i=0;i<n;i++){
        if(st.empty()){
            st.push(mp(a[i],i));
        }else if(a[i]>=st.top().ff){
            while(a[i]>=st.top().ff){
                temp=st.top();st.pop();
                row[temp.ss].suffix=i-temp.ss-1;
                if(st.empty()) break;
            }
            st.push(mp(a[i],i));
        }else st.push(mp(a[i],i));
    }
    while(!st.empty()){
        temp=st.top();st.pop();
        row[temp.ss].suffix=n-temp.ss-1;
    }
    for(i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(mp(a[i],i));
        }else if(a[i]>st.top().ff){
            while(a[i]>st.top().ff){
                temp=st.top();st.pop();
                row[temp.ss].prefix=temp.ss-i-1;
                if(st.empty()) break;
            }
            st.push(mp(a[i],i));
        }else st.push(mp(a[i],i));
    }
    while(!st.empty()){
        temp=st.top();st.pop();
        row[temp.ss].prefix=temp.ss;
    }
    
    //prefix and suffix of columns
    for(i=0;i<n;i++){
        if(st.empty()){
            st.push(mp(b[i],i));
        }else if(b[i]>=st.top().ff){
            while(b[i]>=st.top().ff){
                temp=st.top();st.pop();
                col[temp.ss].suffix=i-temp.ss-1;
                if(st.empty()) break;
            }
            st.push(mp(b[i],i));
        }else st.push(mp(b[i],i));
    }
    while(!st.empty()){
        temp=st.top();st.pop();
        col[temp.ss].suffix=n-temp.ss-1;
    }
    for(i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(mp(b[i],i));
        }else if(b[i]>st.top().ff){
            while(b[i]>st.top().ff){
                temp=st.top();st.pop();
                col[temp.ss].prefix=temp.ss-i-1;
                if(st.empty()) break;
            }
            st.push(mp(b[i],i));
        }else st.push(mp(b[i],i));
    }
    while(!st.empty()){
        temp=st.top();st.pop();
        col[temp.ss].prefix=temp.ss;
    }
    
    //update row
    for(i=0;i<n;i++){
        ms=min(row[i].prefix,row[i].suffix);mb=max(row[i].prefix,row[i].suffix);
        update(1,0,n-1, ms, mb,((ms+1)*row[i].val)%modu,segtree_a,lazya);
        for(j=0;j<ms;j++){
            pointrow[j]= (pointrow[j]+((j+1)*row[i].val)%modu)%modu;
            pointrow[mb+ms-j]=(pointrow[mb+ms-j]+((j+1)*row[i].val)%modu)%modu;
        }
    }
    for(i=0;i<n;i++){
        pointrow[i]=(pointrow[i]+query(1,0,n-1,i,i,segtree_a,lazya) )%modu;
    }
    //update coloumn
    for(i=0;i<n;i++){
        ms=min(col[i].prefix,col[i].suffix);mb=max(col[i].prefix,col[i].suffix);
        update(1,0,n-1, ms, mb,((ms+1)*col[i].val)%modu,segtree_b,lazyb);
        for(j=0;j<ms;j++){
            pointcol[j]= (pointcol[j]+((j+1)*col[i].val)%modu)%modu;
            pointcol[mb+ms-j]=(pointcol[mb+ms-j]+((j+1)*col[i].val)%modu)%modu;
        }
    }
    for(i=0;i<n;i++){
        pointcol[i]=(pointcol[i]+query(1,0,n-1,i,i,segtree_b,lazyb) )%modu;
    }
    
	for(i=0;i<n;i++){
        printf("%lld ",(pointrow[i]*pointcol[i])%modu );
    }
    return 0;
}
//11545686822