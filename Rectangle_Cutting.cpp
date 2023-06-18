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
#define inf 1e9
int mincut[505][505];
void solve() {
    int width,height;
    see(width,height);
    for(int i=1;i<=width;i++)
        for(int j=1;j<=height;j++)
            mincut[i][j]=inf;
    for(int i=1;i<501;i++)
      mincut[i][i]=0;
    for(int w=1;w<=width;w++){
        for(int h=1;h<=height;h++){
            for(int cut=1;cut<w;cut++){
                mincut[w][h]=min(mincut[w][h],mincut[w-cut][h]+mincut[cut][h]+1);
            }
            for(int cut=1;cut<h;cut++){
                mincut[w][h]=min(mincut[w][h],mincut[w][h-cut]+mincut[w][cut]+1);
            }
        }
    }
     
    put(mincut[width][height]);
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
