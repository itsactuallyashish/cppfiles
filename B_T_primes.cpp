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
const int mxn=1e6+10;
int isprime[mxn]={1};
void sieve(){
        isprime[0]=isprime[1]=0;
        for(int i=2;i<mxn;i++)
           isprime[i]=1;
        for(int i=2;i*i<mxn;i++){
            if(isprime[i]==1){
                for(int j=i+i;j<mxn;j+=i)
                    if(isprime[j]==1)
                      isprime[j]=0;
            }
        }
}
void solve() {
    sieve();
    int n;see(n);
    for(int i=0;i<n;i++){
            ll x;see(x);
            double val=sqrt(x);
            if(floor(val)==val && isprime[(int)floor(val)]){
                putl("YES");
            }else putl("NO");
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
