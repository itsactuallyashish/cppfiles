#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(int n,int k){
    if(n==1) return 1;
    if(k<=(n+1)/2){
        if(2*k>n) return (2*k)%n;
        else return 2*k;
    } 
    ll x=solve(n/2,k-(n+1)/2);
    if(n%2) return 2*x+1;
    else return 2*x-1;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<"\n";
    }
}