#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define L 1000006
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
#define forr(i, p, n) for (ll i = p; i < (ll)n; i++)
typedef long long ll;
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
    for (; k; k >>= 1LL)
    {
        if (k & 1LL)
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

ll min (ll a, ll b){
    return a>=b?b:a;
}

ll max(ll a, ll b){
    return a>=b?a:b;
}

int main()
{
    bolt;
    light;
    ll n,s,t;
    ll test;
    cin>>test;
    while(test--){
    cin>>n>>s>>t;
    if(min(s,t) >= n){
        cout<<1<<'\n';
    }
    else if(s+t==n){
        cout<<n<<'\n';
    }
    else{
        cout<<"ext";
        ll lll = min(s,t);
        ll r = n - min(s,t);
        ll ext = max(s,t) - r;
        cout<<lll<<" "<<r<<max(s,t);
        if(ext >=n){
            cout<<1<<'\n';
        }
        if( ext <= min(lll,r) ){
            cout<<"here1"<<n<<" "<<ext<<" "<<t;
            cout<<max(lll,r)+1<<'\n';
        }
        else{
            cout<<"here"<<n<<" "<<ext<<" "<<t;
            cout<<n-ext+1<<'\n';
        }
    }
    }
    return 0;
}
