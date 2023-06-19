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
            int n,k;see(n,k);
            int sum=0;
            vector<int>a(n);
            for(auto &in :a) see(in);
            for(int i=0;i<k;i++){
                sum+=a[i];
            }
            int mxsum=sum;
            int ans=1;
            for(int i=k;i<n;i++){
                sum-=a[i-k];
                sum+=a[i];
                if(mxsum > sum){
                    ans=i+1-k+1;
                    mxsum=sum;
                }
            }
            put(ans);
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
