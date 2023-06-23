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

vector<vector<int>>g(4,vector<int>(4,0)),mat(4,vector<int>(4,0));
bool valid(int i,int j,int r){
    if(i>=0 && i<4 && j>=0 && j<4 && g[i][j]==r) return 1;
    return 0;
}
int x[]={1,1,0,0};
            int y[]={0,1,1,0};
void solve() {
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    char ch;see(ch);
                    if(ch=='#') g[i][j]=1;
                }
            }
            
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int p=i+x[k];
                        int q=j+y[k];
                        if(valid(p,q,g[i][j])){
                            cnt++;
                        }
                    }
                    mat[i][j]=cnt;
                    if(cnt>=3 || (cnt==1 && i!=0 && i!=3 && j!=0 && j!=3)){
                        put("YES");return;
                    }
                }
            }
            // for(int i=0;i<4;i++){
            //     for(int j=0;j<4;j++){
            //         put(mat[i][j]);
            //     }
            //     putl();
            // }
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
