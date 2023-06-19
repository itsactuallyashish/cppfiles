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
         string s,t;
         see(s,t);
         if(s.size()!=t.size()){
            put("NO");return;
         }
         int cnt=0;
         char c1,c2;
         bool flag=0;
         for(int i=0;i<s.size();i++){
                if(s[i]==t[i]) continue;
                if(cnt==0){
                    cnt++;
                    c1=s[i];c2=t[i];
                }
                else if(cnt==1){
                    if(s[i]==c2 && t[i]==c1){
                        flag=1;
                    }
                    cnt++;
                }else flag=0;

         }
         if(flag==1){
            put("YES");
         }else put("NO");
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
