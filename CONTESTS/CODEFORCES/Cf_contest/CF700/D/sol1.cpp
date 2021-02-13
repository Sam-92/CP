#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;


void solve(){
    ll n;
    cin >> n;
    ll a[n + 11];
    rep(i , n) cin >> a[i];

    a[n] = 0;

    ll ct[n + 11] = {0};
    rep(i , n){
        if(i == 0) ct[i] = 1;
        else{
            if(a[i] == a[i - 1]) ct[i] = ct[i - 1];
            else ct[i] = ct[i - 1] + 1;
        }
    }
    ll dp[n + 11][2] = {0};

    map<ll , set<ll > >m;

    dp[0][0] = dp[0][1] = 1;
    m[a[0]].insert(0);
    FOR(i , 1 , n - 1){
        if(a[i] != a[i - 1]){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }

        ll last_index = n;

        auto it = m.find(a[i]);
        if(it != m.end()){
            last_index = *m[a[i]].rbegin();
            cout << i << ": " << " last_index" << last_index << "\n";
            ll val = 0;
            if(last_index == 0) val = ct[i];
            else val = ct[i] - ct[last_index];
            dp[i][0] = max(dp[i][0] , dp[last_index][1] + (val));
            dp[i][1] = max(dp[i][1] , dp[last_index][0] + (val));
        }

        m[a[i]].insert(i);
    }

    rep(i , n) cout << ct[i] << " ";
    cout << "\n";
    rep(i , n){
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }
    cout << "\n";


    cout << max(dp[n - 1][0] , dp[n - 1][1]) << "\n"; 
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
    