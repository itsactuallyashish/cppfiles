#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 int n;cin>>n;
 vector<ll>number(n),pos(n);
 for(int i=0;i<n;i++){
        ll x;cin>>x;
        x--;
        number[i]=x;
        pos[number[i]]=i;
 }
 ll pass=0;
 for(int i=0;i<n;i++){
        if(pos[i]<pos[i-1])
          pass++;
 }
 cout<<pass;
}