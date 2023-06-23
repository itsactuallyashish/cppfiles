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
            string s;
            ll a;
            int n,b;
            see(a,b,n);
                for(int i=0;i<=9;i++){
                    ll t= a*10 +i;
                    if(t%b==0){
                        a= t;
                        n--;
                        break;
                    }
                }
                if(a%b!=0){
                    put(-1);return;
                }
            cout<<a;
            while(n--){
                cout<<0;
            }
           
            
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
