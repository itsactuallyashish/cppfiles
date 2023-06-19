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
        int x;see(x);
         int a=0,b=0;
        for(int i=0;i<x;i++){
            int l;see(l);
            if(l==100) a++;
            else b++;
        }
        bool flag=0;
        if((a*100 + b*200) %200){
            put("NO");return;
        }else {
            int half= a*100 +b*200;
            half/=2;
            for(int i=0;i<=b;i++){
                if(200 * i <=half && half -200*i<=100*a)
                   flag=1;
            }
        }
        if(flag){
        put("YES");
            return;
        }
        put("NO");

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
