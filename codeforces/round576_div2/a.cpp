#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed << setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define bolt ios::sync_with_stdio(0)
#define light   \
    cin.tie(0); \
    cout.tie(0)
typedef long long ll;
#define forr(i, p, n) for (ll i = p; i < (ll)n; i++)
using namespace std;
ll mult(ll a, ll b, ll p = MOD) { return ((a % p) * (b % p)) % p; }
ll multbig(ll a, ll b, ll mod)
{
    if (a == 0 or b == 0)
        return 0;
    if (a == 1 or b == 1)
        return (a * b) % mod;
    ll cur = multbig(a, b / 2, mod);
    cur = (2 * cur) % mod;
    if (b % 2)
        cur = (cur + a) % mod;
    return cur;
}
ll add(ll a, ll b, ll p = MOD) { return (a % p + b % p) % p; }
ll fpow(ll n, ll k, ll p = MOD)
{
    ll r = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)
            r = mult(r, n, p);
        n = mult(n, n, p);
    }
    return r;
}
ll inv(ll a, ll p = MOD) { return fpow(a, p - 2, p); }
ll inv_euclid(ll a, ll m = MOD)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

class g
{
    ll v;
    list<ll> *adj;

public:
    g(ll v)
    {
        this->v = v;
        adj = new list<ll>[v];
    }
    void addedge(ll u, ll w)
    {
        adj[u].push_back(w);
    }
    void dfs_util(ll u, bool visited[])
    {
        visited[u] = true;
        list<ll>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            if (!visited[*itr])
            {
                dfs_util(*itr, visited);
            }
        }
    }
    void dfs(ll u)
    {
        bool *visited = new bool[u];
        for (ll i = 0; i < u; i++)
        {
            visited[i] = false;
        }
        dfs_util(u, visited);
    }
};

ll mx(ll a , ll b){
    return a>=b?a:b;
}

ll mn( ll a, ll b){
    return a>=b?b:a;
}

int main()
{
    bolt;
    light;
    ll ln;
    ll cnt=0,m=0;
    cin>>ln;
    ll li,hi;
    cin>>li>>hi;
    vector<ll> dt;
    for(ll i=0;i<ln;i++){
        ll smp;
        cin>>smp;
        dt.pb(smp);
    }
    vector<ll> pre;
    ll hs=0;
    for( ll i=1;i<li;i++){
        if(i<li){
            hs = mx(hs,dt[i-1]);
            pre.pb(mx(hs,dt[i-1]));
        }
        if( i==li){
            ll flg=0;
            for( ll j=i+1;j<=(li+hi) && flg!=1;j++){
                if( j> ln-1){
                    flg=1;
                    continue;
                }
                else{
                    pre.pb(mx(hs,));
                }
            }
        }
    }

    /*
    vector<ll> pre;
    //pre.pb(dt[0]);
    ll hs=0;
    ll smpx=0;
    if( ){

    }
    for( ll j=0;j<;j++){

        hs = mx(dt[j],hs);
    }
    for( ll j=x+1;j<=(x+y);j++){
        hs = mx(dt[j],hs);
    }
    ll ans=0;
    for( ll i=x;i<(ln-y);i++){
        hs = mx(dt[i+y],hs);
        if( hs > dt[i]  ){
            ans = {  }
            break;
        }
    }
    cout<<ans<<"\n";
    */
    return 0;
}
