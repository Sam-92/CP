/**
 *    Author:  Sanchit Sinha
 *    Created: 16.10.2020 22:18:28       
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
        // n=6 : 2 4 6 1 3 5  
        // n=1 : 1
        // n= 2 : NO 
        // n= 3 : 3 1 2 -> NO 
        // n = 4 : 2 4 1 3 
        if(n==1 ) cout<<1<<"\n";
        else if(n==2 || n==3) cout<<"NO SOLUTION\n";
        else{
                for(ll i=2;i<=n;i+=2) cout<<i<<" ";
                for(ll i=1;i<=n;i+=2) cout<<i <<" " ;
                cout<<'\n';
        }
        return 0;
}
