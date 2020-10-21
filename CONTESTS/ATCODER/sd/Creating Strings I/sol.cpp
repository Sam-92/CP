/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 01:01:46       
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
        string s;
        
        cin>>s;
        sort(s.begin(),s.end());
        vector<string> v;
        do{
                v.push_back(s);
        } while (next_permutation(s.begin(),s.end()));
        cout<<(int)v.size()<<"\n";
        for(ll i=0;i<(int)v.size();i++) cout<<v[i]<<"\n";
        cout<<"\n";
        return 0;
}
