#include<bits/stdc++.h>
using namespace std;
struct Node{
        int ch[26]={};
        int fail;
        vector<int>word;
        string s;
        int cnt=0;
}T[500005];
int I=1;
void insert(string s,int ii){
    int x=1;
    for(int i=0;i<(int)s.size();i++){
        int y=s[i]-'a';
        if(T[x].ch[y]==0){
               T[x].ch[y]=++I;
        }
        x=T[x].ch[y];
    }
    T[x].word.push_back(ii);
}
vector<int>adj[500005];
void build(){
        int x=1;
        queue<int>q;
        T[x].fail=x;
        for(int i=0;i<26;i++){
            if(T[x].ch[i]){
                T[T[x].ch[i]].fail=x;
                q.push(T[x].ch[i]);
            }else{
                T[x].ch[i]=x;
            }
        }
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(T[x].ch[i]){
                    T[T[x].ch[i]].fail = T[T[x].fail].ch[i];
                    q.push(T[x].ch[i]);
                }else{
                    T[x].ch[i]=T[T[x].fail].ch[i];
                }
            }
        }
        for(int i=2;i<=I;i++){
            adj[T[i].fail].push_back(i);
        }
}
void run(string &s){
        for(int i=0,x=1;i<(int)s.size();i++){
            x=T[x].ch[s[i]-'a'];
            T[x].cnt++;
        }
}
int ans[500005];
int dfs(int u){
    int res=T[u].cnt;
    for(auto v:adj[u]){
        res+=dfs(v);
    }
    for(auto w:T[u].word){
        ans[w]=res;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;cin>>s;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string st;cin>>st;
        insert(st,i);
    }
    build();
    run(s);
    dfs(1);
    for(int i=0;i<n;i++){
       cout<<(ans[i]>0?"YES\n":"NO\n");
    }
}