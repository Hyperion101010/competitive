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

bool par(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n     = n & (n - 1);
    }
    return parity;
}

int main()
{
   // bolt;
    //light;
    ll t;
    ll ev=0,od=0;
    cin>>t;
    while(t--){
        ll q;
        cin>>q;
        set<ll> dto;
        //pair<set<ll>>
        while(q--){
            ll smp=0;
            cin>>smp;
            vector<long> dt;
            dto.insert(smp);
            dt.push_back(smp);
            ll ev=0,od=0;
            for(auto itr=dto.begin(); itr!=dto.end();itr++){
                if( *itr!=smp && *itr ^ smp!=0){
                dto.insert( smp ^ *itr);
                od+=par(smp ^ *itr);
               // cout<<od<<*itr^smp<<" ";
                }
                else{
                    od+=par( smp );
                //    cout<<od<<;
                }
            }
            ev = dto.size() -od;
            cout<<ev<<" "<<od<<" "<<dto.size()<<'\n';
            /*
            ll smp;
            cin>>smp;
            dto.push_back(smp);
            ll ev1=0;
            for( ll i=0; i < dto.size() ;i+=1){
                if( smp ^ dto[i] ==0){
                    ev1+=par(dto[i]);
                    continue;
                }
                else{
                 ev1+= par(dto[i]^smp);
                 dto.push_back(dto[i]^smp);
                }
                cout<<" for"<<ev1<<" "<<ev<<" "<<od<<'\n';
            }*/
        }
    }
    return 0;
}
