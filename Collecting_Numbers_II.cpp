#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 int n;cin>>n;
 int m;cin>>m;
 vector<ll>number(n+1),pos(n+1);
 for(int i=1;i<=n;i++){
        ll x;cin>>x;
        number[i]=x;
        pos[number[i]]=i;
 }
 ll pass=1;
 for(int i=1;i<n;i++){
        if(pos[i]>pos[i+1])
          pass++;
 }
 int l,r;
 set<pair<int,int>>st;
 for(int i=0;i<m;i++){
    cin>>l>>r; 
    if(number[l]+1<=n) st.insert({number[l],number[l]+1});
    if(number[l]-1>=1) st.insert({number[l]-1,number[l]}); 
    if(number[r]+1<=n) st.insert({number[r],number[r]+1});
    if(number[r]-1>=1) st.insert({number[r]-1,number[r]}); 
    for(auto pr:st){
        pass-=pos[pr.first] > pos[pr.first+1];
    }
    swap(number[l], number[r]);
    pos[number[l]]=l;
    pos[number[r]]=r;
    for(auto pr:st){
        pass+=pos[pr.first] > pos[pr.first+1];
    }
    st.clear();
    cout<<pass<<"\n";
 }
}