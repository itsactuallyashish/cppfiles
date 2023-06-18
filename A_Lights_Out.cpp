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
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        int l[3][3],m[3][3]={0};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                    see(l[i][j]);
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                m[i][j]+=l[i][j];
                if(l[i][j]){
                    for(int k=0;k<4;k++){
                        if(i+x[k]>=0 && i+x[k]<3 && j+y[k]>=0 && j+y[k]<3){
                            m[i+x[k]][j+y[k]]+=l[i][j];
                        }
                    }
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              if(m[i][j]&1) cout<<0;
              else cout<<1;
            }
            putl();
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
