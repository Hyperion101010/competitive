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

int main()
{
    bolt;
    light;
    ll ln;
    cin>>ln;
    ll k,n;
    cin>>k;
    n=round(ln/2);
    //vector<pair<ll,ll>> dt;
    //map<ll,ll> dt;
    ll arr[1001];
    memset(arr,0,sizeof(arr));
    for( ll i=0;i<ln;i++){
        ll smp;
        cin>>smp;
        arr[smp]+=1;
    }
    ll ans=0;
    ll sz=n*2;
    sort(arr,arr+1001,greater<ll>());
    /*
    for( ll i=0;i<1001 && sz>1;i++){
        if( arr[i] ==0){
            break;
        }
        if( arr[i] & 1){
            if( sz>arr[i]){
                ans=arr[i];
                break;
            }
            else{
                if( sz & 1 ){
                    sz-=1;
                    ans+=sz;
                    sz=0;
                }
                else{
                    ans+=sz;
                    sz=0;
                }
            }
        }
        else{
            if( sz >= arr[i]){
                ans+=arr[i];
                sz-=arr[i];
            }
            else{
                if( sz & 1){
                    ans+=arr[i];
                    sz=0;
                }
                else{
                    ans+=arr[i];
                    sz=0;
                }
            }
        }
    }*/
    queue<pair<ll,ll>> eve,odd;
    for( ll i=0;i<1001;i++){
        if( arr[i] > 0 ){
            if( arr[i] & 1){
                odd.push(make_pair(i,arr[i]));
            }
            else{
                eve.push(make_pair(i,arr[i]));
            }
        }
    }
    ll flg=0;
    ll sz=2*n;
    while( sz>0 && flg==0 &&  eve.size()>0){
        auto smp = eve.front();
        eve.pop();
        if( sz>= smp.second){
            ans+=smp.second;
            sz-=smp.second;
            continue;
        }
        else{
            ans+= sz;
            sz=0;
            flg=1;
            break;
        }
    }
    while( sz>1 && flg==0 && odd.size()>0){
        auto smp=odd.front();
        odd.pop();
        if( sz>= smp.second){
            ans+=smp.second;
            sz-=smp.second;
            sz-=1;
            continue;
        }
        else{
            if( sz & 1){
                ans+=(sz-1);
            }
            else{
            ans+= sz;
            }
            flg=1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
