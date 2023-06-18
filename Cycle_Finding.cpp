#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll INF = 1e17;
const ll NINF = INF*(-1);
// this uses modified bellman ford algorithm(not an convensional shortest path algorihm)
// we initializes the bellman ford with all distances to 0 .relaxations will take us to -ve distances
// we perform N iteration of relaxations
// we capture relaxing parents
// Nth iteration will confirm/deny existence of negative cycle
// after n iteration :if we confirm negative cycle (we start from the vertex that was last relaxed)
//we traceback its relaxants Ntimes to confirm that we are in a vertex that's part of negative cycle
//following the above we continued to traceback relaxants until we end where we started
//we reverse the order and present the cycle
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>dis(n+1,0),relaxant(n+1,-1);
    vector<array<ll,3>>edges(m+1);
    int x=-1;
    for(int i=0;i<m;i++){
        array<ll,3>ar;
        cin>>ar[0]>>ar[1]>>ar[2];
        edges.push_back(ar);
    }
    //performing n Iteration and capturing the relaxants(parent)
    for(int i=1;i<=n;i++){
         x=-1;
        for(auto e:edges){
            array<ll,3>ar=e;
            if(dis[ar[0]]+ar[2]<dis[ar[1]]){
                dis[ar[1]]=dis[ar[0]]+ar[2];
                relaxant[ar[1]]=ar[0];
                x=ar[1];
            }
        }
    }
    if(x==-1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        //we perform n relaxation to traceback to the veertex that is the part of the negative cycle
        for(int i=1;i<=n;i++) x=relaxant[x];
        vector<ll>cycle;
        for(int v=x;;v=relaxant[v]){
            cycle.push_back(v);
            if(v==x&&cycle.size()>1)
            break;
        }
        reverse(cycle.begin(),cycle.end());
        for(auto x:cycle) cout<<x<<" ";
    }

}