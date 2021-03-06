/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 16:34:34       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        set<ll>ans;
        for(ll i=1;i*i<=n;i++){
                if(n%i==0){
                        ll div1=i,div2=n/i;
                        ans.insert(div1);
                        ans.insert(div2);
                }
        }
        for(auto it=ans.begin();it!=ans.end();it++) cout<<*it <<"\n";
        return 0;
}
