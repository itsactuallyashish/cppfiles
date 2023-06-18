#include<iostream>
#include<vector>
#define ll long long
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
const int md=1e9+7;
struct trienode{
   struct trienode* child[26];
   bool isEnd;
   trienode(){
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};
trienode *root =new trienode;
void insert(string &s){
     trienode* curr=root;
     int n=s.size();
     for(int i=0;i<n;i++){
          int idx=s[i]-'a';
          if(curr->child[idx]==NULL){
               curr->child[idx]=new trienode;
          }
          curr=curr->child[idx];
     }
     curr->isEnd=true;
}

int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     string s;see(s);
     int n;see(n);
     for(int i=0;i<n;i++){
          string t;see(t);
          insert(t);
     }
     int len=s.size();
     vector<ll>dp(len+1,0);
     dp[len]=1;
     for(int i=len-1;i>=0;i--){
          trienode* tmp=root;
          for(int j=i;j<len;j++){
               int idx=s[j]-'a';
               if(tmp->child[idx]==NULL) break;
               tmp=tmp->child[idx];
               if(tmp->isEnd){
                    dp[i] =(dp[i]+dp[j+1])%md;
               }
          }
     }
     put(dp[0]);
}