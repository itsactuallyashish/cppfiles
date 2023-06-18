#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 int n;cin>>n;
 ll small=1;
 ll a[n]{0};
 for(int i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  for(int i=0;i<n && small>=a[i];i++){
        small+=a[i];
  }
  cout<<small;
}