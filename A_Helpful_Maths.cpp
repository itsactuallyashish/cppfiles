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
        string s;see(s);
        int cnt1=0,cnt2=0,cnt3=0;
        for(auto ch:s){
            if(ch == '1'){
                cnt1++;
            }
            if(ch=='2') cnt2++;
            if(ch=='3') cnt3++;
        }
        string res;
        while(cnt1--){
            res.push_back('1');
            res.push_back('+');
        }
        while(cnt2--){
            res.push_back('2');
            res.push_back('+');
        }
        while(cnt3--){
            res.push_back('3');
            res.push_back('+');
        }
        res.pop_back();
        put(res);
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
