#include "bits/stdc++.h"
using namespace std;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll long long
#define ld long double
#define all(c) (c).begin(),(c).end()
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define f first
#define s second

inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline ll gcd(ll a ,ll b) {if(b==0) return a; a%=b;return gcd(b,a);}
ll power(ll x, ll y){if(y == 0) return 1; ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex , ll md) {ll ans = 1ll;while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll;x = (x * x) % md;}return ans;}

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e6 + 1;
ll n , a[N] ,ans ;
ll kadane(vll v){
    ll n = v.size();
    ll mxsum = 0 , cursum = 0;
    for(ll i = 0 ; i < n ; i++){
        cursum += v[i];
        if(cursum < 0) cursum = 0;
        else mxsum = max(mxsum , cursum);
    }
    return mxsum;
}
void solve(){
    cin >> n;
    rep(i , n) {
        cin >> a[i] ;
        if(!(i&1)) ans += a[i];
    }
    vll v1 , v2;
    for(ll i = 1 ; i < n; i += 2) v1.pb(a[i] - a[i - 1]);
    for(ll i = 1 ; i < n - 1 ; i += 2) v2.pb(a[i] - a[i + 1]);
    cout << ans + max(kadane(v1) , kadane(v2)) << endl;
    n = 0, ans = 0;
    rep(i , n + 1) a[i] = 0 ; 
}
int main(){
    IOS;
    cout << fixed << setprecision(20);
    ll NTC=1;
    cin>>NTC;
    ll PTC=0;
    while(PTC++<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
