#include <bits/stdc++.h>

using namespace std;

long long int MOD = 100000007;

long long int mod(long long int a) {return a%MOD;}

long long int mult(long long int a, long long int b, long long int p = MOD) { return ((a % p) * (b % p)) % p; }

long long int exp(long long int b, long long int d){
    if(d==0){
        return 1;
    }
    if(d & 1 ){
        return mod(mod(b)*mod(exp(b,d-1)));
    }
    else{
        return mod(mod(exp(b,d>>1))*mod(exp(b,d>>1)));
    }
}

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = mult(res,x,p); //(res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = mult(x,x,p);//(x*x) % p;
    }
    return res;
}



int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int k;
        long long int ans;
        cin>>k;
        ans = power(2,k-1,MOD);
        ans = mult(ans,10);
        cout<<ans<<"\n";
        //cout<<"brute answer";
        //cout<<calc(k)<<"\n";
    }
    return 0;
}