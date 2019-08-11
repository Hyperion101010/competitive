#include<iostream>
using namespace std;
void function(int n)
{
int i=1,s=1;
while(s<=n)
{
i++;
s=s+i;
cout<<"*"<<"\n";
}
}
int main()
{
int n;
cin>>n;
function(n);
return 0;
}
