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



ll n,c;
vi on,off;
bool lights[123];
set<string> result;
set<string>::iterator it;

void type1(){
	ll i;
	for(i=1;i<=n;i++){
		lights[i]=!lights[i];
	}
}
void type2(){
	ll i;
	for(i=2;i<=n;i+=2){
		lights[i]=!lights[i];
	}
}
void type3(){
	ll i;
	for(i=1;i<=n;i+=2){
		lights[i]=!lights[i];
	}
}
void type4(){
	ll i;
	for(i=1;i<=n;i+=3){
		lights[i]=!lights[i];
	}
}


int main(){
	fastio;
	cin>>n>>c;
	register ll i,j,k,p,q,x,y;
	while(true){
		cin>>k;
		if(k==-1){
			break;
		}else{
			on.pb(k);
		}
	}
	while(true){
		cin>>k;
		if(k==-1){
			break;
		}else{
			off.pb(k);
		}
	}
	ll operation[4];
	bool illegal;
	for(i=0;i<=15;i++){
		k=i;illegal=false;q=0;
		for(j=1;j<=n;j++){
			lights[j]=true;
		}
		reset(operation,0);
		for(p=0;p<4;p++){
			operation[p]=k%2;k/=2;
			q+=operation[p];
		}
		if(q>c){
			continue;
		}
		//cout<<i<<endl;
		for(p=0;p<4;p++){
			if(operation[p]){
				switch(p+1){
					case 1:type1();break;
					case 2:type2();break;
					case 3:type3();break;
					case 4:type4();break;
				}
			}
		}
		for(j=0;j<on.size();j++){
			if(!lights[on[j]]){
				illegal=true;break;
			}
		}
		for(j=0;j<off.size();j++){
			if(lights[off[j]]){
				illegal=true;break;
			}
		}
		if(!illegal){
			string s="";
			for(j=1;j<=n;j++){
				if(lights[j]){
					s+="1";
				}else{
					s+="0";
				}
			}
			result.insert(s);
		}
	}

	if(!result.size()){
		cout<<"Impossible"<<endl;
	}else{
		for(it=result.begin();it!=result.end();it++){
			cout<<*it<<endl;
		}
	}
	return 0;
}