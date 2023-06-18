//kadane algorithm
//itsactuallyashish
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &in:a) cin>>in;
    int osum=INT_MIN;
    int csum=0;
    for(int i=0;i<n;i++){
        if(csum>0) csum+=a[i];
        else csum=a[i];
        osum=max(osum,csum);
    }
    cout<<osum;
}