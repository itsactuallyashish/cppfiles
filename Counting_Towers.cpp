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
const ll md = (10e8) + 7;
ll dp[1000002][9];
void solve() {
    /*
        {1 3 4 5 6 } <- { 1 2 4 5 6 }
        {2 7 } <- { 3 7 8}
    */
   const int mx=1000001;
   for(int i=0;i<8;i++)
     dp[0][i]=1;
   for(int i=1;i<mx;i++){
        for(int j=0;j<8;j++){
            if(j==0|| j==2 || j==3 || j==4|| j==5){
                dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5])%md;
            }else{
                dp[i][j] = ( dp[i-1][2] + dp[i-1][6] + dp[i-1][7])%md;
            }
        }
   }
   int t;see(t);
   while(t--){
        ll ans=0;
        int i;see(i); i--;    
        ans = (dp[i][3] + dp[i][7])%md;
            putl(ans);
   }

    
      
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
