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
#define sz(c)               (int)((c).size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

#ifdef LOCAL
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define cerr if(false) cerr
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

// dig, nnum, tight
ll dp[20][60][2];
vll dig(ll x) {
    vll ans;
    ll index = 0;
    while (x) {
        debug(x);
        ans.pb(x % 10);
        x /= 10;
    }
    return ans;
}
// return num of integers having exactly cnt number of digs d
ll calc(ll cur_index , ll cnt, ll tight, vll &v, ll k, ll d) {
    if (cur_index == -1) {
        if (cnt == k) return 1;
        else return 0;
    }
    if (dp[cur_index][cnt][tight] != -1) return dp[cur_index][cnt][tight];

    ll mx = 9;
    if (tight) mx = v[cur_index];

    ll ans = 0ll;
    FOR(i, 0, mx) {
        int new_tight = tight;
        if (i < v[cur_index]) new_tight = 0;

        if (i == d) ans += calc(cur_index - 1, cnt + 1, new_tight, v, k, d);
        else ans += calc(cur_index - 1, cnt, new_tight, v, k, d);
    }
    return (dp[cur_index][cnt][tight] = ans);
}
void solve() {
    ll a , b, d, k;
    cin >> a >> b >> d >> k;

    vll A = dig(a - 1);
    vll B = dig(b);
    debug(A, B);

    memset(dp, -1, sizeof(dp));
    ll ans2 = calc(sz(B) - 1, 0, 1, B, k, d);
    memset(dp, -1, sizeof(dp));
    ll ans1 = calc(sz(A) - 1, 0, 1, A, k, d);

    cout << ans2 - ans1 << "\n";
}


int main() {
#ifdef LOCAL
    freopen("../error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    ll NTC = 1;
    cin >> NTC;

#ifdef PREPROCESS
    preprocess();
#endif
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    factorial();
#endif

    ll PTC = 0;
    while ((PTC++) < NTC) {
        cerr << "Testcase # " << PTC << "\n";
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        cerr << "*************************\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}

ll power(ll x, ll y) {if (y == 0) return 1; ll a = power(x, y / 2); if (y % 2 == 0) return a * a; else return x * a * a;}
ll powermod(ll x, ll ex, ll md) {ll ans = 1ll; while (ex > 0) {if (ex & 1ll) ans = (ans * x) % md; ex >>= 1ll; x = (x * x) % md;} return ans;}
