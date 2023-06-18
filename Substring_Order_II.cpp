#include <bits/stdc++.h>
using namespace std;
#define ll long long
string S;
ll N, cnt[200005], dp[200005];
 
struct SuffixAuto {
    struct State {
        int len, link;
        int next[26];
        State(int _len = 0, int _link = -1) : len(_len), link(_link) {
            memset(next, -1, sizeof(next));
        }
    };
 
    vector<State> states;
    int last;
 
    inline int state(int len = 0, int link = -1) {
        states.emplace_back(len, link);
        return states.size() - 1;
    }
 
    void init(const string &S) {
        states.reserve(2 * S.size());
        last = state();
        for (char c : S)
            extend(c);
    }
 
    void extend(char _c) {
        int c = _c - 'a'; 
        int cur = state(states[last].len + 1), P = last; 
        cnt[cur] = 1;
        while (P != -1 && states[P].next[c] == -1) {
            states[P].next[c] = cur;
            P = states[P].link;
        }
        if (P == -1)
            states[cur].link = 0;
        else {
            int Q = states[P].next[c];
            if (states[P].len + 1 == states[Q].len)
                states[cur].link = Q;
            else {
                int C = state(states[P].len + 1, states[Q].link);
                cnt[C] = 0;
                copy(states[Q].next, states[Q].next + 26, states[C].next);
                while (P != -1 && states[P].next[c] == Q) {
                    states[P].next[c] = C;
                    P = states[P].link;
                }
                states[Q].link = states[cur].link = C;
            }
        }
        last = cur;
    }
} sa;
 
ll dfs_dp(int u = 0) {
    if (dp[u] != 0)
        return dp[u];
    for (int i = 0; i < 26; i++) {
        int v = sa.states[u].next[i];
        if (v != -1) 
            dp[u] += dfs_dp(v);
    }
    return dp[u] += cnt[u];
}
 
string p = "";
 
void dfs(int u = 0) {
    if (N < cnt[u])
        return;
    else 
        N -= cnt[u];
    for (int i = 0; i < 26; i++) {
        int v = sa.states[u].next[i];
        if (v != -1) {
            if (N >= dp[v])
                N -= dp[v];
            else {
                p += (char)(i + 'a');
                return dfs(v);
            }
        }
    }
}
 
int main() {
    cin >> S >> N;
    sa.init(S);
 
    vector<pair<int,int>> v(sa.states.size());
    for (int i = 0; i < sa.states.size(); i++)
        v[i] = {sa.states[i].len, i};
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for (auto [len, id] : v)
        if (sa.states[id].link != -1)
            cnt[sa.states[id].link] += cnt[id];
    cnt[0] = 1;
 
    dfs_dp();
 
    dfs();
 
    cout << p ;
}
