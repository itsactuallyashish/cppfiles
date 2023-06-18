#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=1e6+1;
    int ar[mxn];
int main(){
    int n;cin>>n;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        int in;cin>>in;
        ar[in]++;
        mx=max(mx,in);
    } 
    for(int g=mx;g>=1;g--){
        int cnt=0;
        for(int j=0;j<=mx;j+=g)
            cnt+=ar[j];
        if(cnt>1){
            cout<<g;
            break;
        }
            
    }
}