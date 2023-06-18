#include <iostream>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        ll xr=0;
        for(int i=0;i<n;i++) xr= xr ^ ar[i];
        if(xr!=0) cout<<"first"<<"\n";
        else cout<<"second"<<"\n";
    }
}