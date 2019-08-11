
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

vector<ll> dt;
ll cnt=0;
ll rtln=0;

ll construct_tree_util(ll st, ll en, ll *rt, ll ti){
    if( st == en ){
        rt[ti] = dt[st];
        return rt[ti];
    }
    ll md = (st+en)/2;
    rt[ti] = construct_tree_util(st,md,rt,2*ti+1) ^ construct_tree_util(md+1,en,rt,2*ti+2);
    return rt[ti];
}

ll* construct_tree(){
    ll hgt = (int)ceil(log2(dt.size()));
    ll mx_sz = 2 * (int)pow(2, hgt) - 1;
    rtln = mx_sz;
    ll *rt = new ll[mx_sz];
    construct_tree_util(0,dt.size()-1,rt,0);
    return rt;
}

ll answer_q_ut(ll *rt, ll ss, ll sen,ll qs, ll qe, ll si){
    if( qs <= ss || qe>= sen){
        return rt[si];
    }
    if( qs> ss || qe < sen){
        return 0;
    }
    ll md = (qs+qe)/2;
    ll lf = answer_q_ut(rt,ss,md,qs,qe,2*si+1);
    ll lr = answer_q_ut(rt,md+1,sen,qs,qe,2*si+2);
    return lf^lr;
}

ll answer_q(ll *rt, ll qs, ll qe){
    if( qs < 0 || qe > dt.size()-1 || qs > qe){
        return 0;
    }
    return answer_q_ut(rt,0,dt.size()-1,qs,qe,0);
}

void cl( ll *rt, ll si, ll sen, ll ad){
    if( si<0 || sen> dt.size()-1 || ad>dt.size()-1){
        return ;
    }
    if( answer_q(rt,si,si+ad) == answer_q(rt,si+ad,sen)){
        cnt+=1;
    }
    cl(rt,si,sen,ad+1);
    cl(rt,si+1,sen,0);
}

int main()
{
    bolt;
    light;
    ll t;
    cin>>t;
    while( t--){
        ll l;
        cin>>l;
        for( ll i=0;i<l;i++){
            ll smp;
            cin>>smp;
            dt.push_back(smp);
        }
        // memset(lkup,-1,sizeof(lkup));
        // answer_q(rt,si,si+ad)
        ll *rt = construct_tree();
       // cl(rt,0,dt.size()-1,0);
        cout<<(answer_q(rt,1,2));
        cout<<(answer_q(rt,2,2));
        cout<<cnt<<"\n";
	for(ll j=0;j<rtln;j++){
		cout<<rt[j]<<" ";
	}
        dt.clear();
    }
    return 0;
}

/*
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

unordered_map<nd> lk_mp;
vector<ll> dt;
ll cnt=0;

struct nd
{
    int dat;
    struct nd *left;
    struct nd *right;
};

nd* ins( int data){
    nd* node = (nd*)new(nd);
    node->dat = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

nd* cl(nd* rt, ll hsxr,ll ind){
    if( ind > dt.size()-1){
        return rt;
    }
    if( lk_mp.find(rt) !=lk_mp.end(rt)){
        return rt;
    }
    ll lf,lr;
    nd* rtn =(nd*) new(nd);
    rtn->dat = hsxr;
    rtn->left = cl( rtn, hsxr^dt[ind], ind+1);
    rtn->right = cl( rtn, dt[ind], ind+1);
    lk_mp.insert(rtn);
    return rtn;
}




nd* cl(nd* rt, ll hsxr,ll ind){
    if( ind > dt.size()-1){
        return hsxr;
    }
    ll lf,lr;
    if( hsxr == dt[ind]){
        cnt+=1;
    }
    lf =  cl( hsxr^dt[ind], ind+1);
    lr =  cl(dt[ind], ind+1);
    return rt;
}


int main()
{
    bolt;
    light;
    ll t;
    while( t--){
        ll l;
        cin>>l;
        for( ll i=0;i<l;i++){
            ll smp;
            cin>>smp;
            dt.push_back(smp);
        }
        //memset(lkup,-1,sizeof(lkup));
        nd* root =(nd*) new(nd);
        cl(root,0);
    }
    return 0;
}
*/
