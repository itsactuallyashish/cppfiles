#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>tickets(n),fare(m);
    set<pair<int,int>>st;
    for(int i=0;i<n;i++){
        cin>>tickets[i];
        st.insert({tickets[i],i});
    }
    for(int i=0;i<m;i++){
        cin>>fare[i];
        auto it= st.lower_bound({fare[i]+1,0});
        if(it==st.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<it->first<<endl;
            st.erase(it);
        }
    }
    
}