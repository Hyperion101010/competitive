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
typedef long long  ll;
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

int Floor(int A[], int l, int r, int key)
{ 
    int m; 
  
    while( r - l > 1 ) 
    { 
        m = l + (r - l)/2;

        if( A[m] <= key )
            l = m;
        else
            r = m;
    }

    return A[r];
}

// Initial call
int Floor(int A[], int size, int key)
{
    // Add error checking if key < A[0]
    if( key > A[size] )
        return -1;

    // Observe boundaries 
    return Floor(A, 0, size, key); 
}

void calc(int srt[], int cry, int i){
    sort(srt,srt+i);
    int hlp=0,cnt=0;
    i-=1;
    
    /*
    for(int j=i; j>=0 || hlp<cry ;j-=1){
            hlp+=srt[j];
            cnt+=1;

            if(hlp >= cry){
                //cnt=abs(i-j);
                //cout<<"j"<<j;
                //cout<<cnt<<" "<<"states"<<hlp<< " "<<j<<" "<<i;
                cout<<cnt<<" ";//<<" cnt";
                break;
            }
        }
        if(hlp < cry){
            cout<<0<<" ";
        }
        //cout<<"hlp"<<hlp<<" cry"<<cry<<" cnt"<<cnt;
        */
}


int calcr(int a, int b){
    return a<=b?0:abs(a-b);
}

int main()
{
    bolt;
    light;
    ll len,tm,rem=0;
    cin >> len >>tm;
    int smm[len],ans[len],srt[len];
    //priority_queue<int,vector<int>,greater<int>> srt;
    for(int i=0;i<len;i++){
        ll sample;
        cin>>sample;
        if(i==0){
            rem=sample;
        }
        else{
            rem+=sample;
        }
        smm[i]=(rem);
        srt[i]=(sample);
        //ans[i] = sample;
    }
    int cnt;
    for(int i=0;i<len;i++){
        int hlp=0;
        if( smm[i] <= tm ){
            cout<<0<<" ";
        }
        else{
            int cry = calcr(smm[i],tm);
            if(i==0){
                cout<<0<<" ";
            }
            else{
                calc(srt,cry,i);
            }
        }
        }
    return 0;
}
