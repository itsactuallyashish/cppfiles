#include "bits/stdc++.h"
using namespace std;
int n,a[100],c,i,j;
long double ans=0;
main(){
    cin>>n;
    for(j=0;j<n;j++){
        cin>>a[j];
        for(i=0;i<j;i++){
            c=min(a[i],a[j])-1;
            ans += double(c* (c+1)/2 + a[j]*max(0,a[i]-a[j]))/(a[j]*a[i]);
        }
    }
    printf("%.6f\n",(double)ans);
}