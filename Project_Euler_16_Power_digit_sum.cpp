#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
const int mod=1e9+7;

void solve(int n){
    int pro=1,carry=0;
    vector<int>v;
    v.push_back(2);
    n--;
    while(n--){
        for(int i=0;i<v.size();i++){
           int x=v[i]*2;
           v[i]=(x+carry)%10;
           carry=(x+carry)/10;

        }
        if(carry) v.push_back(carry);
        carry=0;
    }
    int ans=0;
    for(auto in :v) ans+=in;
    cout<<ans<<"\n";
}
int main() {
    
    int t;cin>>t;
    int n,m;
    while(t--){
        cin>>n;
        solve(n);
    }  
    
    return 0;
}