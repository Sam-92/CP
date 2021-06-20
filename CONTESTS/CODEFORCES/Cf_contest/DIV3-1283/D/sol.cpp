#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

string to_string(string s) {return '"' + s + '"';} string to_string(const char* s) {return to_string((string) s);} string to_string(bool b) {return (b ? "true" : "false");} template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";} template <typename A>string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", ";} first = false; res += to_string(x);} res += "}"; return res;} void debug_out() { cerr << "\n"; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n"; debug_out(T...);}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline ll gcd(ll a, ll b) {if (b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a, ll b) {return ((a > b) ? a : b);}
inline ll min(ll a, ll b) {return ((a > b) ? b : a);}
ll power(ll x, ll ex);
ll powermod(ll x, ll ex, ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

set<ll> current , x;
void add(set<ll> &ans , ll xx){
    auto it1 = current.find(xx);
    auto it2 = ans.find(xx);
    auto it3 = x.find(xx);

    if(it1 == current.end() && it2 == ans.end() && it3 == x.end()){
        ans.insert(xx);
        current.insert(xx);
    }
}
void solve() {
    ll n , m;
    cin >> n >> m;

    rep(i , n){
        ll y;
        cin >> y;

        x.insert(y);
    }

    set<ll> ans;

    bool f = 1;
    while(sz(ans) != m){
        if(f){
            trav(it , x){
                ll xx = *it;
            
                ll l = xx - 1;
                ll r = xx + 1;

                add(ans , l);
                if(sz(ans) == m) break;

                add(ans , r);
                if(sz(ans) == m) break;
            }

            f = 0;
        }
        else{
            set<ll> temp = current;
            current.clear();
            trav(it , temp){
                ll xx = *it;

                ll l = xx - 1;
                ll r = xx + 1;

                add(ans , l);
                if(sz(ans) == m) break;

                add(ans , r);
                if(sz(ans) == m) break;
            }
        }
    }   

    x.insert(-inf);
    x.insert(inf);


    ll res = 0ll;
    trav(it , ans){
        ll xx = *it;
    
        auto it1 = x.ub(xx);
        
        auto it2 = --it1;
        it1++;

        ll l = *it1;
        ll r = *it2;

        res += min(abs(xx - l) , abs(xx - r));
    }

    cout << res << "\n";
    trav(it , ans) cout << *it << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    // cin >> NTC;

#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif
#ifdef PREPROCESS
    preprocess();
#endif

    ll PTC = 0;
    while ((PTC++) < NTC) {
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        // cout << "\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}