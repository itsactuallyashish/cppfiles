#include<bits/stdc++.h>
using namespace std;
struct Node{
        int ch[26]={};
        int fail;
        vector<int>word;
        int out=-1;
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
            //setting output link
            if(T[T[x].fail].word.empty()){
                T[x].out=T[T[x].fail].out;
            }else{
                T[x].out=T[x].fail;
            }
        }
 
        
}
 
void search(string &s,vector<int>&res){
        int x=1;
        for(int i=0;i<s.size();i++){
            char cc=s[i]-'a';
            if(T[x].ch[cc]){
                x=T[x].ch[cc];
                if(!T[x].word.empty()){
                    // for(auto ss:T[x].word){
                    //     if(res[ss].empty())
                    //      res[ss].push_back(i);
                    // }
                    if(res[x]==-1)
                        res[x]=i;
                }
                int ot=T[x].out;
                while(ot!=-1){
                    // for(auto ss:T[ot].word);
                    //     if(res[ss].empty())
                    //      res[ss].push_back(i);
                    if(res[ot]==-1)
                        res[ot]=i;
                    ot=T[ot].out;
                }
            }else{
                while(x!=1 && !T[x].ch[cc]){
                        x=T[x].fail;
                }
                if(T[x].ch[cc]) i--;
            }
        }
            
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;cin>>s;
    int n;cin>>n;
    vector<string>pat(n);
    for(int i=0;i<n;i++){
        cin>>pat[i];
        insert(pat[i],i);
    }
    build();
    vector<int>res(I+1,-1);
    search(s,res);
    vector<int>ans(n,-1);
    for(int i=1;i<=I;i++){
        if(res[i]==-1)continue;
        for(auto x:T[i].word){
            if(ans[x]>=0)continue;
                ans[x]=res[i] -pat[x].size()+2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
}