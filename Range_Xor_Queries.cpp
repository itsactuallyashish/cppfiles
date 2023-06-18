#include <iostream>
#include <vector>
using namespace std;
long long sgt[1000001];
int n;
int query(int l,int r){
    l+=n,r+=n;
    int res=0;
    for(;l<r;l>>=1,r>>=1){
        if(l&1) res=res^sgt[l++];
        if(r&1) res=res^sgt[--r];
    }
    return res;
}
int main(){
    int q;
    cin>>n>>q;
    vector<long long> ar(n);
    for(auto &elem:ar) cin>>elem;
    for(int i=0;i<n;i++) sgt[i+n]=ar[i];
    for(int i=n-1;i>=1;i--) sgt[i]=sgt[2*i]^sgt[2*i+1];
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    cout<<query(l,r)<<"\n";
  }
}