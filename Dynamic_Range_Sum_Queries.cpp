#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int mxn=1000001;
int n;
ll t[2*mxn];
void update(int in,int val){
            in+=n;
            t[in]=val;
            while(in>=1){
                in>>=1;
                t[in]=t[2*in]+t[2*in+1];
            }
}
ll sum(int l,int r){
        ll res=0;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
                if(l&1) res+=t[l++];
                if(r&1) res+=t[--r];
        }
        return res;
}
int main(){
    int q;
    cin>>n>>q;
    vector<long long> ar(n);
    for(auto &elem:ar) cin>>elem;
    for(int i=0;i<n;i++) update(i,ar[i]);
  for(int i=0;i<q;i++){
    int code;
    cin>>code;
    if(code==2){
    int l,r;
    cin>>l>>r;
    l--;r--;
    cout<<sum(l,r)<<"\n";
    }
    else {
        int in,val;
        cin>>in>>val;
        in--;
        update(in,val);
    }
  }
}