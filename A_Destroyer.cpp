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
        multiset<int>st;
        st.clear();
        vector<int>val;
        for(int i=0;i<n;i++){
            int x;see(x);
            val.push_back(x);
        }
        sort(all(val));
        for(int i=0;i<n;i++){
            int x= val[i];
            if(x==0){
                 st.insert(x);
            }
            else if(st.find(x-1)!=st.end()){
                  auto it=st.find(x-1);
                  st.erase(it);
                  st.insert(x);
            }else{
                put("NO");return;
            }
            
        }
        put("YES");
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
