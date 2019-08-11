#include <bits/stdc++.h>

using namespace std;

#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll k,n;
        cin>>n>>k;
        ll l = k;
        ll r = k+n-1;
        ll ind=2;
        ll ans=0;
        ll term = (r-1)/(n-1);
        term-=1;
        
        ans-=1;
        cout<<ans+(l-1) <<"\n";
    }
    return 0;
}
