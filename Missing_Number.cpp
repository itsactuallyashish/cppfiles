#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    long long res=0;
    int i;
    for(i=1;i<=n-1;i++){
            cin>>x;
            res=res^i;
            res=res^x;
    }
    res=res^i;
    cout<<res;
}