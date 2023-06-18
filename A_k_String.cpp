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
        string s;see(s);
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int x=s.size()/k;
        s.clear();
        for(auto pr:mp){
            if(x==1 && pr.second!=k){
                 put(-1);return;
            }
            if(pr.second%k!=0){
                put(-1);return;
            }
            for(int i=0;i<pr.second/k;i++)
               s.push_back(pr.first);
        }
        for(int i=0;i<k;i++)cout<<s;
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
