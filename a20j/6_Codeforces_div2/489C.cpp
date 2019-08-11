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

int main()
{
    bolt;
    light;
    ll len,sm;
    cin>>len>>sm;
    ll sm1=sm;
    int mx_arr[len];
    int mn_arr[len];
    for(int i=0;i<len;i+=1){
        mx_arr[i]=0;
        mn_arr[i]=0;
    }
    ll tt = 9*len;
    int chn = len;
    int ll=0,rr=0;
    for(int i=0;i<len;i++){
        if( tt < sm ){
            rr=1;
            break;
        }
        if(i==0 &&  sm <= 9 ){
            mx_arr[0]=sm;
            break;
        }
        else{
            if( sm > 9 ){
                mx_arr[i]=9;
                sm-=9;
            }
            else{
                if(sm==0){
                    break;
                }
                else{
                    mx_arr[i]=sm;
                    sm=0;
                }
            }
        }
    }
    if(sm1==0){
        rr=1;
    }
    int ln=len;
    for(int i=0;i<len;i++){
        if( sm1==0 ){
            rr=1;
            break;
        }
        if(rr==1 ){break;}
        if( i==0 && sm1 <=9 ){
            mn_arr[0]=sm1-1;
            mn_arr[len-1]=1;
            sm1=0;
            break;
        }
        else{
            if( sm1<=9){
                if(i==len-1){
                    mn_arr[i]=sm1;
                }
                else{
                mn_arr[i]=sm1-1;
                mn_arr[len-1]=1;
                break;
                }
            }
            else{
                mn_arr[i]=9;
                sm1-=9;
                tt-=9;
            }
        }
    }
    if(rr==0){
    for(int i=len-1;i>=0;i-=1){
        cout<<mn_arr[i];
    }
    cout<<" ";
    for(int i=0;i<len;i++){
        cout<<mx_arr[i];
    }
    cout<<'\n';
    }
    else{
        cout<<-1<<" "<<-1<<'\n';
    }
    return 0;
}
