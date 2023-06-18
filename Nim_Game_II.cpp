#include <iostream>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll xr=0;
        ll a;
        for(int i=0;i<n;i++){
            cin>>a;
            xr= xr ^ (a%4);

        } 
        if(xr!=0) cout<<"first"<<"\n";
        else cout<<"second"<<"\n";
    }
}