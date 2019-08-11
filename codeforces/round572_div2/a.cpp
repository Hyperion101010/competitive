#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define l 1000001
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

/*
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
}*/

int main()
{
    //bolt;
    //light;
    ll len;
    cin>>len;
    string data;
    cin>>data;
   // getline(cin,data);
    vector<ll> o ;
    ll tt=0;
    if(data[0]-'0'==0){
        o.pb(0);
    }
    else{
        o.pb(1);
        tt+=1;
    }
    for(int i=1;i<data.length();i++){
        if(data[i]-'1'==0){
            o.pb(o[i-1]+1);
            tt+=1;
        }
        else{
            o.pb(o[i-1]);
        }
    }
    ll pos=0;
    for(int i=0;i< data.length();i++){
        ll lf0= (i+1)-o[i];
        ll lf1= o[i];
        ll r0 = tt-lf0;
        ll r1 = tt-o[i];
        if( lf0!=lf1 && r0!=r1){
            pos=i;
            break;
        }
    }
    if( tt!=data.length() -tt){
        cout<<1<<"\n"<<data<<'\n';
    }
    else{
    cout<<2<<'\n';
    for(int i=0;i<=pos;i++){
        cout<<data[i];
    }
    cout<<" ";
    for(int i=pos+1; i<data.length();i++){
        cout<<data[i];
    }
    cout<<'\n';
    }
    return 0;
}
