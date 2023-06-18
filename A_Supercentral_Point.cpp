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

struct point{
    int x,y,i;
    bool operator<(const point& other){
        if(other.x==x){
            return y<other.y;
        }else return x<other.x;
    }
};
struct choice{
        int up,down,left,right;
};
void solve() {
        int n;see(n);
        vector<point>p(n);
        for(int i=0;i<n;i++){
            see(p[i].x,p[i].y);
            p[i].i=i;
        }
        vector<choice>ch(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(p[j].x == p[i].x && p[j].y < p[i].y)
                   ch[p[i].i].down++;
                 if(p[j].x== p[i].x && p[j].y > p[i].y)
                   ch[p[i].i].up++;
                if(p[j].y == p[i].y && p[j].x < p[i].x)
                   ch[p[i].i].left++;
                if(p[j].y == p[i].y && p[j].x >p[i].x)
                   ch[p[i].i].right++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ch[i].down>0 && ch[i].left>0 && ch[i].up>0 && ch[i].right>0)
               cnt++;
        }
        put(cnt);
        

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
