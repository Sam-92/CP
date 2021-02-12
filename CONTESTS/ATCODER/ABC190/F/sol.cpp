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

const ll N = 3e5+11;

ll tree[4*N],a[N];
bool vis[N];


void pull(ll node,ll l,ll r){
    tree[node]=(tree[l]+tree[r]);//operation
}
void update(ll node,ll l,ll r,ll index,ll val){
    if(index>r || index<l) return ;
    if(l==r) tree[node]=val; //update operation
    else{
        ll mid=l+(r-l)/2;
        
        update(node*2,l,mid,index,val);
        update(node*2+1,mid+1,r,index,val);
        
        pull(node,node*2,node*2+1);
    }
}
ll query(ll node,ll l,ll r ,ll start,ll end){
    if(end<l || start>r) return 0; //operation (inf , -inf , 0 ...)
    else if(start<=l && end>=r) return tree[node];
    else{
        ll mid=l+(r-l)/2;
        
        ll p1=query(2*node,l,mid,start,end);
        ll p2=query(2*node+1,mid+1,r,start,end);
        
        return (p1+p2); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
void solve(){
    ll n;
    cin >> n;
    
    rep(i , n) cin >> a[i];

    vll inversions ; 
    rep(i , n) {
        cout << query(1,0,n-1,0,a[n - 1 - i]) <<" ";
        inversions.pb(query(1,0,n-1,0,a[n - 1 - i]));

        vis[a[n - 1 - i]]=1;

        update(1,0,n-1,a[n - 1 -i],1);
    }
    cout << "\n";
    vll v;
    rep(i , n) v.pb(i);

    // build(1 ,0 ,n - 1);

    vll non_inversion;
    rep(i , n){
        ll ele = a[i];
        auto it = ub(a , a + n , ele);
        non_inversion.pb(a + n - it);
    }

    FOR(i , 1 , n - 1) inversions[i] += inversions[i - 1];

    rep(i , n) cout << inversions[i] << " ";
    cout << "\n";
     rep(i , n) cout << non_inversion[i] << " ";
    cout << "\n";
   
    ll pfx[n] = {0};
    rep(i , n){
        if(i == 0) pfx[i] = non_inversion[i];
        else pfx[i] = pfx[i - 1] + non_inversion[i];
    }

    cout << inversions[n - 1] <<"\n";

    rep(i , n - 1){
        cout <<"\n################## \n";
        cout << i + 1 << ": \n";
        rep(j , n){
            cout << a[(i + j + 1)%(n)] << " ";
        }
        cout <<"\n################## \n";
        
        // ll y = query(1 , 0 , n - 1 , 0 , i - 1) ;
        ll y = inversions[i];

        // ll x = query(1, 0, n - 1, i, n - 1);
        ll x = inversions[n - 1] - y;

        ll z = (i + 1 )* non_inversion[i];

        cout << x <<" " << y << " " << z << "\n";
        // cout << ans << "\n";

        // ans += pfx[i];

        // cout << ans <<"\n";

    }
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
