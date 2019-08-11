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
typedef int ll;
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

/*
int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}*/
vector<pair<int,int>> calc(string s){
    int rem = s[0]-'a';
    int cnt=1;
    vector<pair<int,int>> arr;
    //arr.push_back(rem);
    for(int i=1;i<s.length();i++){
        if(s[i]-'a' == rem){
            cnt+=1;
        }
        else{
          //  cout<<rem<<" "<<cnt<<": ";
            arr.push_back(make_pair(rem,cnt));
            rem = s[i]-'a';
            cnt=1;
        }
    }
    arr.push_back(make_pair(rem,cnt));
    //cout<<"over\n";
    return arr;
}


int main()
{
    bolt;
    light;
    ll t;
    cin>>t;
    while(t>0){
        string f,s;
        cin>>f>>s;
        vector<pair<int,int>> ff = calc(f);
        vector<pair<int,int>> ss = calc(s);
        bool  set = false;
        if(ff.size() == ss.size()){
        for(int i=0;i<ff.size() ;i++){
            if( ff[i].first == ss[i].first && ff[i].second <= ss[i].second){
                continue;
            }
            else {
               // cout<<i<<"here";
                set =true;
            }
        }
        }
        else{
            set=true;
        }/*
        for(int i=0;i<ff.size();i++){
            cout<<ff[i].first<<" "<<ff[i].second<<"\n";
        }
        cout<<"new begin\n";
        for(int i=0;i<ss.size();i++){
            cout<<ss[i].first<<" "<<ss[i].second<<"\n";
        }*/

        if(set){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        /*
        cin>>bs>>chk;
        vector<pair<int,int>> arr;
        int chk_arr[26], bs_ar[26];
        for(int i=0;i<26;i++){
            bs_ar[i]=0;
            chk_arr[i]=0;
        }
        int rem=0;
        int


        /*



        int rem=chk[0]-'a';
        //arr.push_back(his);
        int cnt=1;
        for(int i=0;i<bs.length();i++){
            bs_ar[bs[i]-'a']+=1;
        }
        for(int i=1;i<chk.length();i++){
            if(chk[i]-'a'==rem){
                cnt+=1;
            }
            else{
                arr.push_back(make_pair(chk[i]-'a',cnt));
                rem = chk[i]-'a';
                cnt=1;
            }
        }
    /*
        for(int i=0;i<bs.length();i++){
            if(bs[i]-'a' == arr[low_].first){
                if(bs_ar[ bs[i]-'a'] > 0 && arr[low_].second >= bs_ar[bs[i]-'a']){
                    bs_ar[bs[i]-'a']-=1;
                    arr[low_].second-=1;
                }
                else{
                    chk1=1;
                    break;
                }
            }
            else{
                low_+=1;
                continue;
            }
        }
        if(chk1==0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        arr.clear();
        */
        t-=1;
    }
    return 0;
}
