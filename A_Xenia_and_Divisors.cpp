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
            int v[8]={0};
            int x;
            for(int i=0;i<n;i++ ){
                    see(x);
                v[x]++;
            }
             if(v[5]>0 || v[7]>0) {
                put(-1);return;
             }
           int x1=min({v[1],v[2],v[4]});
            v[1]-=x1;v[2]-=x1;v[4]-=x1;
            int x2 = min({v[1],v[2],v[6]});
            v[1]-=x2;v[2]-=x2;v[6]-=x2;
            int x3 = min({v[1],v[3],v[6]});
            v[1]-=x3;v[3]-=x3;v[6]-=x3;
       
            if(v[1]>0|| v[2]>0 || v[3]>0 || v[4]>0|| v[6]>0){
                put(-1);
                return;
            }
            
           
            for(int i=0;i<x1;i++){
                putl(1,2,4);
            }
            for(int i=0;i<x2;i++){
                putl(1,2,6);
            }
            for(int i=0;i<x3;i++){
                putl(1,3,6);
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
