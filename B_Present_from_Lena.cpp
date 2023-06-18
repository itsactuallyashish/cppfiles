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
    for(int i=0;i<2*n+1;i++){
        if(i<n){
            for(int j=0;j<n-i;j++){
                cout<<" "<<" ";
            }
            for(int j=n-i;j<n;j++)
                cout<<j-n+i<<" ";
            cout<<i;
            for(int j=n+1;j<n+i+1;j++)
                 cout<<" " <<n+i-j;
        }
        else {
             for(int j=0;j<i-n;j++)
                 cout<<' '<<' ';
             for(int j=i-n;j<n;j++)
                 cout<<j-i+n<<' ';
             cout<<2*n-i;
             for(int j=n+1;j<3*n+1-i;j++)
                 cout<<" " <<3*n-i-j;
             
        }
        cout<<"\n";
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
