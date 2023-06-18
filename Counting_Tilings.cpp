#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
const int md = int (1e9+7);
map<int,vector<int>>prevtilling;
void generate_tilling(int idx,int  n, int prev,int next){
            if(idx==n){
                prevtilling[next].push_back(prev);
                return;
            }
            // if current block is already filled
            if((1<<idx)&prev){
             generate_tilling(idx+1,n,prev,next);
             return ;
            }
            // if block can be placed vertically
            if((idx + 1) <n && ((1<<(idx+1))&prev)==0){
             generate_tilling(idx+2,n,prev,next);
            }
            // place the block horizontally
            next = next | (1<<idx);
             generate_tilling(idx+1,n,prev,next);
}
void solve() {
        int n,m; see(n,m);
        int limit = 1<<n;
        for(int mask =0 ;mask < limit ;mask ++){
            generate_tilling(0,n,mask,0);
        }
        vector<int>prev(limit);
        vector<int>curr(limit);
        prev[0]=1;
        for(int row =0;row<m;row++){
            for(int tile =0;tile < limit ;tile++){
                for(auto x:prevtilling[tile]){
                    curr[tile] = ( curr[tile] + prev[x])%md;
                }
            }
            swap(prev,curr);
            fill(all(curr),0);
        }
        put(prev[0]);
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
