#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
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

namespace mp = boost::muliplication;
typedef mp::cpp_int ll;


int main()
{
  //  bolt;
   // light;
    ll t;
    cin>>t;
    while(t--){
        ll n=0,k=0, ans=0;
        cin>>n>>k;
        if( k>= n){
            ll ls = k%n;
            ll gr = abs(n-ls);
            if( ls==gr){
                ans = (2*ls)-1;
            }
            else if( ls > gr){
                ans = 2*gr;
            }
            else{
                ans = 2*ls;
            }
        }
        else{
            ll cnt1=k;
            ll cnt0=abs(k-n);
            if( cnt1== cnt0){
                ans=2*cnt1-1;
            }
            else if( cnt1<cnt0){
                ans=2*cnt1;
            }
            else{
                //cout<<k<<n<<" "<<abs(k-n);
                ans = 2*(cnt0);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
