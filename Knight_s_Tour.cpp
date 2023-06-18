#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
int xx[]={1,2,2,1,-1,-2,-2,-1};
int yy[]={2,1,-1,-2,-2,-1,1,2};
int vis[8][8];
bool free(int x,int y){
    return x>=0&& x<8 && y>=0&& y<8 && vis[x][y]==0;
}
int deg(array<int,2>a){
    int deg=0;
    for(int i=0;i<8;i++){
        deg+=free(a[0]+xx[i],a[1]+yy[i]);
    }
    return deg;
}
void solve(int x,int y,int a){
    vis[x][y]=a;
    if(a==64){
        // print(vis);
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                put(vis[i][j]);
            }
            cout<<"\n";
        }
        assert(1);
    }
    vector<array<int,2>>p;
    for(int i=0;i<8;i++){
        if(free(x+xx[i],y+yy[i])){
                p.push_back({x+xx[i],y+yy[i]});
        }
    }
    sort(p.begin(),p.end(),[](array<int,2>a,array<int,2>b){
            return deg(a)<deg(b);
    });
    for(auto ar:p){
        solve(ar[0],ar[1],a+1);
    }
}
int main(){
    int n,m; see(n,m);
    n--,m--;
    swap(n,m);
    solve(n,m,1);
}