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
        int n,k,x;
        see(n,k,x);
        if(n==1 && x==1){
            put("NO");
            return;
        }
        if(k==1 && x==1) {
            put("NO");
            return;
        }
        if(x!=1){
            putl("YES");
            putl(n);
            for(int i=1;i<=n;i++)
             put(1);
        }else{

            vector<int>res;
            if(k==2){
                if(n%2==0){
                    putl("YES");
                    while(n>0){
                        res.push_back(2);
                        n-=2;
                    }
                }else{
                    put("NO");
                }
            }else{
                if(n%2==1){
                 putl("YES");
                 while(n>3){
                 
                    n-=2;
                    res.push_back(2);
                 }
                 res.push_back(3);
                
                }else{
                     putl("YES");
                    while(n>0){
                        res.push_back(2);
                        n-=2;
                    }
                }
               
            }
            if(res.size()>0)
              putl(res.size());
            for(auto c:res) put(c);
        }
        


}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
