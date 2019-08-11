/* Here the question was depemdemt on number theory with the solution of digit numbers*/

#include<bits/stdc++.h>

#define ll unsigned long long int

using namespace std;

ll mul(ll a){
    return a*10;;
}

int main(){
    ll t;
    cin>>t;
    while(t!=0){
        ll n1;
        cin>>n1;
        ll n=n1;
        ll sm=0;
        while(n!=0){
            sm+=n%10;
            n=n/10;
        }
        ll rem = (sm%10==0)? 0:(10-sm%10);
        ll ans = (n1*10 + rem);
        cout<<ans<<"\n";
        t-=1;
    }
    return 0;
}
