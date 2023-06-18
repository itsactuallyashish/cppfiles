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
            int k;see(k);
            vector<int>a(12);
            for(int i=0;i<12;i++)
                see(a[i]);
            sort(all(a),greater<int>());
            int mncnt=0;
            if(k==0){
                put(0);return;
            }
            for(auto x:a){
                k-=x;
                mncnt++;
                if(k<=0){
                    put(mncnt);
                    return;
                }
            }
            put(-1);
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
