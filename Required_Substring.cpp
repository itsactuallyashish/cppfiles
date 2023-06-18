#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
using namespace std;
const int md=(1e9)+7;
const int mxn=1002;
    ll dp[mxn][mxn],len[mxn][mxn];
  string s;
ll ex(ll a,int b){
    ll res=1;
    while(b>0){
        if(b&1) res = (res*a)%md;
        a = (a* a) %md;
        b>>=1;
    }
    return res;
}
int main(){
    int n;see(n);
    see(s);
    int m=(int)s.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<26;j++){
            string pre=s.substr(0,i);
            char ch=(char)(j+'A');
            pre+=ch;
            len[i][j]=0;
            for(int x=0;x<pre.size();x++){
                if(pre.substr(x)==s.substr(0,pre.size()-x)){
                    len[i][j]=pre.size()-x;
                    break;
                }
            }
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<26;k++)
                dp[i][len[j][k]] = (dp[i][len[j][k]] + dp[i-1][j])%md;
        }
    }
    ll res=ex(26,n);
    for(int i=0;i<m;i++){
        res = (res - dp[n][i] + md)%md;
    }
    put(res);

}