#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=2e5+1;
int destinations[mxn];
bool visited[mxn];
int step=0;
int pathlen[mxn];
queue<int>path;
void dfs(int x){
    path.push(x);
    if(visited[x]){
        step+=pathlen[x];
        return;
    }
    step+=1;
    visited[x]=1;
    dfs(destinations[x]);

}
int main(){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>destinations[i];
            destinations[i]--;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                step=0;
                dfs(i);
                int decrementer=1;
                while(!path.empty()){
                        if(path.front()==path.back()){
                            decrementer=0;
                        }
                        pathlen[path.front()]=step;
                        step-=decrementer;
                        path.pop();
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<pathlen[i]<<" ";
}