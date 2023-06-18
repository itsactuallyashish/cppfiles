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
            int cnt5=0,cnt0=0;
            for(int i=0;i<n;i++){
                int x;see(x);
                if(x==5) cnt5++;
                else cnt0++;
            }
            ll sum=0;
            int ans=-1;
            for(int i=0;i<cnt5;i++){
                sum+=5;
                if(sum%9==0){
                    ans=i+1;
                }
            }
            
            if(cnt0){
                for(int i=0;i<ans;i++){
                cout<<5;
                }
                if(ans>0){
                    for(int i=0;i<cnt0;i++)
                     cout<<0;
                }
                else cout<<0;
            }
                else cout<<-1;
            
              
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
