#include <bits/stdc++.h>

using namespace std;

int ub(int d){ return ceil( d*.75);
}

int main(){
    int t;
    cin>>t;
    while(t!=0){
        string data;
        int d, pr_cnt1=0,pr_cnt2=0;
        cin>>d>>data;
        //getline(cin,data);
        //cout<<data<<" "<<d;
        int chk[d];
        memset(chk,0,sizeof(chk));
        for(int i=0;i<d;i++){
            if(data[i]-'P'==0){
                chk[i] = 1;
                pr_cnt1+=1;
            }
        }
        for(int i=2;i<d-2;i+=1){
            if( !chk[i] && (chk[i-2] || chk[i-1] ) && (chk[i+1] || chk[i+2])){
                pr_cnt2+=1;
            }
        }

        if(pr_cnt1+pr_cnt2 >= ub(d)){
            if(pr_cnt1>=ub(d)){
                cout<<0<<"\n";
            }
            else {
            cout<<ub(d)-pr_cnt1<<"\n";
            }
        }
        else{
            cout<<-1<<"\n";
        }
        t-=1;
    }
    return 0;
}