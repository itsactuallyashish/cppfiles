#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int>z,v;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){

        cin>>x;
        if(x%2==0)
                z.insert(x);
        else 
                v.insert(x);
    }
    int s=accumulate(z.begin(),z.end(),0);
    int s2=accumulate(v.begin(),v.end(),0);
    vector<int>ans;
    for(auto in:z)
            ans.push_back(in);
    ans.push_back(s);
    for(auto in:v)
            ans.push_back(in);
    ans.push_back(s2);
  for(auto in:ans)
    cout<<in<<" ";
}