#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
using namespace std;

const int LIM = 2e6 + 25;
const int MOD = 1e9 + 7;
const int BASE = 127;
int powMOD(int x, int n)
{
    int res = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
    }

    return res;
}

int H[LIM];
int P[LIM];
void init(const string &s)
{
    int n = s.size();
    int b = 1;
    
    H[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
        b = (1LL * b * BASE) % MOD;
    }

    P[n] = powMOD(b, MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        P[i] = (1LL * P[i + 1] * BASE) % MOD;
}

int get(int l, int r)
{
    return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD;
}
int main(){
    string s;
    see(s);
    int n=s.size();
    s+=s;
    init(s);
    int t=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int l=0,r=n-1;l<=r;){
            int lm= l + (r-l)/2;
            if(get(t,t+lm)==get(i,i+lm)){
                x=lm;
                l=lm+1;
            }else 
                r= lm-1;
        }
        if(x==n-1) continue;
        if(s[i+x] < s[t+x]) t=i;

    }
    put(s.substr(t,n));
}