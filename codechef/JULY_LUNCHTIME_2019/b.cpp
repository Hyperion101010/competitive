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

ll cal(ll ip)
{
    ll cnt = 0;
    while (ip > 0)
    {
        cnt += ip % 10;
        ip /= 10;
    }
    return cnt;
}

int main()
{
    bolt;
    light;
    ll t;
    cin >> t;
    while (t--)
    {
        ll ln;
        cin>>ln;
        map<ll,ll, greater<ll>> dt;
        vector<ll> swp;
        unordered_map<ll,bool> chk;
        unordered_map<ll,ll> cnt1;
        //vector<ll> dt;
        for( ll i=0;i<ln;i++){
            ll smp;
            cin>>smp;
            swp.push_back(smp);
            dt.insert( make_pair(smp*(i+1), i) );
            if( cnt1.find(smp)!=cnt1.end() ) {
                auto otr = cnt1.find(smp);
                auto s1 = otr->second;
                cnt1.insert(make_pair(smp,s1+1));
            }
            else{
            cnt1.insert(make_pair(smp,1));
            }
        }
        for( auto itr = dt.begin(); itr!=dt.end(); itr++){
            auto pr = itr;
            ll ind = pr->second;
            ll val = pr->first;
            if( ind >= ln-1 ){
                continue;
            }
            if( chk.find(ind) !=chk.end()  || chk.find((ind+1)) != chk.end() && ( cnt1[swp[ind]]<=1 || cnt1[swp[ind+1]]<=1 ) ){
                continue;
            }
            if( swp[ind+1] > swp[ind]){
                continue;
            }
            ll tmp = swp[ind+1];
            swp[ind+1] = swp[ind];
            swp[ind] = tmp;
            ll c1  = cnt1[swp[ind]];
            ll c2  = cnt1[swp[ind+1]];
            cnt1[swp[ind]] = (c1-1);
            cnt1[swp[ind+1]] = c2-1;
            chk.insert(make_pair(ind+1,true));
            chk.insert(make_pair(ind,true));
            //chk.insert();
        }
        ll sm=0;
        for( ll i=1; i<=ln; i++){
            sm+=(i*swp[i-1]);
        }
        /* code */
        cout<<sm<<"\n";
    }
    return 0;
}

/*

int main()
{
    bolt;
    light;
    ll t;
    cin >> t;
    while (t--)
    {
        ll ln;
        cin>>ln;
        map<ll,ll, greater<ll>> dt;
        vector<ll> swp;
        unordered_map<ll,bool> chk;
        //vector<ll> dt;
        for( ll i=0;i<ln;i++){
            ll smp;
            cin>>smp;
            swp.push_back(smp);
            dt.insert( make_pair(smp*(i+1), i) );
        }
        for( auto itr = dt.begin(); itr!=dt.end(); itr++){
            auto pr = itr;
            ll ind = pr->second;
            ll val = pr->first;
            if( ind >= ln-1 ){
                continue;
            }
            if( chk.find(swp[ind]) !=chk.end()  || chk.find( swp[(ind+1)]) != chk.end()  ){
                continue;
            }
            if( swp[ind+1] > swp[ind]){
                continue;
            }
            ll tmp = swp[ind+1];
            swp[ind+1] = swp[ind];
            swp[ind] = tmp;
            chk.insert(make_pair(swp[ind+1],true));
            chk.insert(make_pair(swp[ind],true));
        }
        ll sm=0;
        for( ll i=1; i<=ln; i++){
            sm+=(i*swp[i-1]);
        }
cout << sm << "\n";
}
return 0;
}
*/

/*
 bolt;
    light;
    ll t;
    cin >> t;
    while (t--)
    {
        ll ln;
        cin>>ln;
        map<ll,ll, greater<ll>> dt;
        vector<ll> swp;
        unordered_map<ll,bool> chk;
        //vector<ll> dt;
        for( ll i=0;i<ln;i++){
            ll smp;
            cin>>smp;
            swp.push_back(smp);
            dt.insert( make_pair(smp*(i+1), i) );
        }
        for( auto itr = dt.begin(); itr!=dt.end(); itr++){
            auto pr = itr;
            ll ind = pr->second;
            ll val = pr->first;
            if( ind >= ln-1 ){
                continue;
            }
            if( chk.find( swp[ind]) !=chk.end()  || chk.find( (swp[ind+1])) != chk.end()  ){
                continue;
            }
            if( swp[ind+1] > swp[ind]){
                continue;
            }
            ll tmp = swp[ind+1];
            swp[ind+1] = swp[ind];
            swp[ind] = tmp;
            //chk.insert(make_pair(swp[ind],true));
            chk.insert(make_pair(ind,true));
        }
        ll sm=0;
        for( ll i=1; i<=ln; i++){
            sm+=(i*swp[i-1]);
        }
*/