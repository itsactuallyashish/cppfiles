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
        int cnt_oddx=0,cnt_oddy=0;
        int pss1=0,pss2=0;
        if(n==1){
            int x,y;see(x,y);
            if(x&1 || y&1){
                put(-1);return;
            }
        }
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++){
            int x,y;
            see(x,y);
            pr.push_back({x,y});
            if(x&1) cnt_oddx++;
            if(y&1) cnt_oddy++;
            if(x&1 && !(y&1)) pss1++;
             if(!(x&1)&&(y&1)) pss2++;
        }
        if(cnt_oddx%2==0 && cnt_oddy%2==0){
            put(0);return;
        }
      int t=0;
      for(auto in:pr){
          int x=in.first,y=in.second;
            if(x%2!=y%2){
                if((cnt_oddx+1)%2==0 && (cnt_oddy-1)%2==0){
                        t++;
                        break;
                }
                if((cnt_oddx-1)%2==0 && (cnt_oddy+1)%2==0){
                        t++;
                        break;
                }
                
            }
      }
      if(t==0){
        put(-1);
      }else put(t);
        
        
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
