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


void solve() {
        int n;see(n);
        int val[n];
        int sum=0;
        for(int i=0;i<n;i++){
          see(val[i]);
            sum+=val[i];
        }
        vector<bool>dp(sum+1,false);
        dp[0]=1;
    for(int j=0;j<n;j++){
        for(int i=sum;i>=val[j];i--){
            dp[i] = dp[i] || dp[i-val[j]];// iterate in reverse order so that if avoid usings coins multiple time
        }
            
    }
    int cnt=0;
    for(int i=1;i<=sum;i++){
        if(dp[i]>0) cnt++; 
    }
    putl(cnt);
    for(int i=1;i<=sum;i++)
     if(dp[i])
      put(i);
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
