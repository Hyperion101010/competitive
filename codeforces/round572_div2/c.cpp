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

ll ans=0, lfb, rfb;
ll lkup[11][11];
vector<ll> dt;


ll compute( ll a, ll b){
    if( a+b>=10){
        ans+=1;
    }
    return (a+b)%10;
}

/*
ll compute( ll a, ll b){
    if( a+b>=10){
        if( lkup[a][b]==-1){
            lkup[a][b]=1;
        }
        lkup[a][b]+=1;
    }
    return (a+b)%10;
}

ll sol( ll lf, ll lr){
    if( lfb>lf || rfb<lr || lf==lr){
        return 0;
    }
    if( lkup[lf][lr] >=0 ){
        return lkup[lf][lr];
    }
   // cout<<"called for"<<lf<<lr<<"\n";
    if( abs(lf-lr)==1){
     //   cout<<"reached for"<<lf<<" "<<lr;
        return compute(dt[lf],dt[lr]);
    }
    ll md=(lf+lr)/2;
    return compute( sol(lf,md), sol(md+1,lr));
    //return compute( compute(lf,lr), sol(lf+2,lr));
}*/


ll sol( ll lf, ll lr){
    if( lfb>lf || rfb<lr || lf==lr){
        return 0;
    }
   // cout<<"called for"<<lf<<lr<<"\n";
    if( abs(lf-lr)==1){
     //   cout<<"reached for"<<lf<<" "<<lr;
        return compute(dt[lf],dt[lr]);
    }
    ll md=(lf+lr)/2;
    return compute( sol(lf,md), sol(md+1,lr));
    //return compute( compute(lf,lr), sol(lf+2,lr));
}

int main()
{
    //bolt;
    //light;
    ll ln;
    cin>>ln;
    for( ll i=0;i<ln;i++){
        ll smp;
        cin>>smp;
        dt.pb(smp);
    }
    memset(lkup,-1,sizeof(lkup));
    ll q;
    cin>>q;
    while(q--){
        ll lf,lr;
        cin>>lf>>lr;
        lf-=1;
        lr-=1;
        lfb=lf;
        rfb=lr;
        ll sm1 = sol(lf,lr);
        cout<<ans<<"\n";
        ans=0;
    }
    //sol();
    return 0;
}
