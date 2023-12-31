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
        string s;
        getline(cin,s);
        string t;
        getline(cin,t);
        map<char,int>mp;
        for(auto ch:s){
            
            if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')){
                mp[ch]++;
            }
            
        }
        for(auto ch:t){
            
            if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')){
                if(mp.count(ch)){
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                }
                }else{
                    put("NO");
                    return;
                }
                
                
            }
        }
        put("YES");

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
