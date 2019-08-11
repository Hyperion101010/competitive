#include <bits/stdc++.h>
using namespace std;

int fct( int a){
return (a)*fct(a+1);
}

int main(){
cout<<fct(10);
return 0;
}
