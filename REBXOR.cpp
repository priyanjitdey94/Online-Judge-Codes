
/*
Author: Priyanjit Dey
Problem: https://www.codechef.com/SEPT15/problems/REBXOR/
Contest: September long challenge 2015
Algorithm: Trie, DP.
*/

#include<stdio.h>
#include<stdlib.h>
 
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpi vector<pair<ll,ll> > 
#define modu 1000000007
 
inline ll scan()
{
    char c = getchar_unlocked();
    register ll x = 0;
    bool neg=false;
    if(c=='-')
    {
    	neg=true;
    }
    while(c<'0'||c>'9')
    {
        c=getchar_unlocked();
        
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    if(neg==false) return x;
    else if(neg==true) return -1*x;
}
struct node
{
	ll left,right;
};
ll ans1[412345],ans2[412345],xar1[412345],xar2[412345],ar[412345],iter1=1,iter2=1;

node trie1[400000*30];
node trie2[400000*30];

void insert1 (node p[],ll idx,ll bits,ll pos)
{
    if (pos==-1) return;
    if ((1<<pos)&bits)
    {
        if (p[idx].right==0)
        {
            p[idx].right=iter1+1;iter1+=1;
        }
        idx=p[idx].right;
        insert1(p,idx,bits, pos-1);
    }
    else
    {
        if (p[idx].left==0)
        {
            p[idx].left=iter1+1;iter1+=1;
        }
        idx=p[idx].left;
        insert1(p,idx, bits, pos-1);
    }
}

void insert2 (node p[],ll idx,ll bits,ll pos)
{
    if (pos==-1) return;
    if ((1<<pos)&bits)
    {
        if (p[idx].right==0)
        {
            p[idx].right=iter2+1;iter2+=1;
        }
        idx=p[idx].right;
        insert2(p,idx,bits, pos-1);
    }
    else
    {
        if (p[idx].left==0)
        {
            p[idx].left=iter2+1;iter2+=1;
        }
        idx=p[idx].left;
        insert2(p,idx, bits, pos-1);
    }
}
 
void query (node p[],ll idx,ll a,ll pos,ll & ans)
{
    if (pos==-1) return;
    if ((1<<pos)&a)
    {
        if (p[idx].left==0)
        {
            idx=p[idx].right;
            query (p,idx, a, pos-1, ans);
        }
        else
        {
            ans+=(1<<pos); 
            idx=p[idx].left;
            query (p,idx, a, pos-1, ans);
        }
    }
    else
    {
        if (p[idx].right==0)
        {
            idx=p[idx].left;
            query(p,idx, a, pos-1, ans);  
        }
        else
        {
            ans+=(1<<pos); 
            idx=p[idx].right;
            query(p,idx, a, pos-1, ans);
        }
    }    
}    

int main()
{
	register ll i,j,k,l,n,m,res=-1,tans=0;
	n=scan();
	for(i=1;i<=n;i++)
	{
		ar[i]=scan();
	}
	xar1[0]=xar2[n+1]=ans1[0]=ans2[n+1]=0;
	for(i=1;i<=n;i++)
	{
		xar1[i]=xar1[i-1]^ar[i];
        xar2[n+1-i]=xar2[2+n-i]^ar[n+1-i];
	}
	insert1(trie1,1,0,30);
	for(i=1;i<=n;i++)
	{
		insert1(trie1,1,xar1[i],30);tans=0;
		query(trie1,1,xar1[i],30,tans);
		if(ans1[i-1]>tans)
		{
			ans1[i]=ans1[i-1];
		}
		else ans1[i]=tans;
	}
	insert2(trie2,1,0,30);
	for(i=n;i>=1;i--)
	{
		insert2(trie2,1,xar2[i],30);tans=0;
		query(trie2,1,xar2[i],30,tans);
		if(ans2[i-1]>tans)
		{
			ans2[i]=ans2[i-1];
		}
		else ans2[i]=tans;
	}
	for(i=1;i<n;i++)
	{
		if(res<(ans1[i]+ans2[i+1]))
		{
			res=ans1[i]+ans2[i+1];
		}
	}
	printf("%d\n",res);
	return 0;
}