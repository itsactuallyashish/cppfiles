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
const int md=1e9+7;
int n;
 vector<vector<int>>paths,dp;

void solve() {
      see(n);
       paths.assign(n,vector<int>(n,0));
       vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch;see(ch);
                paths[i][j]=(ch=='.');
            }
        }
        
        dp[0]=paths[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(paths[i][j]==0){
                  dp[j]=0;
                    continue;
                }
                if(j>=1){
                    dp[j] = (dp[j] + dp[j-1])%md;
                }
            }
        }
        put(dp[n-1]);

       
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
