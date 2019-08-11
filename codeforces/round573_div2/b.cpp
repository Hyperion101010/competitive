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
    string arr;
    //char arr[10];
    /*for( ll i=0;i<8;i++){
        cin>>arr[i];
    }*/
    getline(cin,arr);
    vector<ll> *dt;
    ll mc=0,pc=0,sc=0;
    ll hlp[] = {0,0,0,0};
    dt=new vector<ll>[4];
    for (ll i = 0; i < arr.length(); i++)
    {
        if (arr[i] == ' ')
        {
            continue;
        }
        if (arr[i] - '0' <= 9 && arr[i] - '0' >= 0)
        {
            if (arr[i + 1] == 'm')
            {
                //m.push_back(arr[i] - '0');
                i += 1;
                mc += 1;
                dt[1].push_back(arr[i]-'0');
                hlp[1] += 1;
                //or_arr.push_back(arr[i] - '0');
            }
            else if (arr[i + 1] == 'p')
            {
                //p.push_back(arr[i] - '0');
                i += 1;
                pc += 1;
                dt[2].push_back(arr[i]-'0');
                hlp[2] += 1;
                //or_arr.push_back(arr[i] - '0');
            }
            else
            {
                //s.push_back(arr[i] - '0');
                i += 1;
                sc += 1;
                dt[3].push_back(arr[i]-'0');
                hlp[3] += 1;
                //or_arr.push_back(arr[i] - '0');
            }
        }
    }
    if( mc==1 && pc==1 && sc==1){
        cout<<2<<"\n";
    }
    else{
    for( ll i=0;i<4;i++){
        if( hlp[i] ==3){
            sort(dt[i].begin(),dt[i].end());
            //auto smp = dt[i];
            auto itr = dt[i].begin();
            if( (*(itr+1)-*(itr)==1 && *(itr+2)-*(itr+1)==1 ) || (*(itr+1)==*(itr) && *(itr+2)==*(itr) ))  {
                cout<<0<<"\n";
                cout<<*(itr+1)<<" "<<*(itr);
                break;
            }
            else if (*(itr + 1) - *(itr) <=2 || *(itr + 2) - *(itr + 1) <=2 ){
                cout<<1<<'\n';
                break;
            }
            else{
                cout<<2<<'\n';
                break;
            }
        }
        else if( hlp[i]==2){
            auto itr = dt[i].begin();
            if( abs(*(itr+1)-*(itr))<=2){
                cout<<1<<'\n';
                break;
            }
            else{
                cout<<2<<'\n';
                break;
            }
        }
    }
    }
    /*
    getline(cin,arr);
    vector<ll> m,p,s;
    ll mc=0,pc=0,sc=0;
    ll mci=1,pci=2,sci=3;
    ll hlp[2][4]; //{0,0,0,0};
    hlp[0][1]= 1;
    hlp[0][2]=2;
    hlp[0][3]=3;
    vector<ll> or_arr;
    for( ll i=0;i<arr.length();i++){
        if( arr[i]==' '){
            continue;
        }
        if( arr[i]-'0' <=9 || arr[i]-'0' >=0){
            if( arr[i+1]=='m'){
                m.push_back(arr[i]-'0');
                i+=1;
                mc+=1;
                hlp[1][1]+=1;
                or_arr.push_back(arr[i]-'0');
            }
            else if(arr[i+1]=='p'){
                p.push_back(arr[i]-'0');
                i+=1;
                pc+=1;
                hlp[1][2]+=1;
                or_arr.push_back(arr[i] - '0');
            }
            else{
                s.push_back(arr[i]-'0');
                i+=1;
                sc+=1;
                hlp[1][3]+=1;
                or_arr.push_back(arr[i] - '0');
            }
        }
    }*/
    //sort(m.begin(),m.end());
    //sort(p.begin(), p.end());
    //sort(s.begin(), s.end());
    return 0;
}
