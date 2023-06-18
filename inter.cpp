#include<bits/stdc++.h>

using namespace std;
struct tree{
    
    bool islockable;
    bool islocked;
    int id;
    tree*p;
    vector<tree*>c;
    tree(){
        islocked=false;
        islockable=true;
        id=-1;
        p=NULL;
    }
    tree(tree*parent){
        p=parent;
        islockable=true;
        islocked=false;
        id=-1;
    }
};

bool locking(tree* n,int uid){
    
    if(n->islockable==false||(n->islocked)){
        
        return false;
    }
    tree*t=n;
    queue<tree*>q;
    q.push(t);
    vector<tree*>st;
    st.push_back(t);
    while(!q.empty()){
        tree* temp=q.front();
        q.pop();
        for(auto x:temp->c){
            
            st.push_back(x);
            if(x->islocked){
                
                return false;
            }
            q.push(x);
        }
    }
    n->id=uid;
    n->islocked=true;
    q.push(t);
    while(!q.empty()){
        tree* temp=q.front();
        q.pop();
        for(auto x:temp->c){
            x->islockable=false;
            q.push(x);
           
        }
    }
   
    return true;
}

bool unlocking(tree*n,int uid){
     
    if(n->islocked==false||n->islockable==false||(n->islocked&& n->id!=uid)){
        
        return false;
    }
    tree*t=n;
    n->islocked=false;
    n->id=-1;
    queue<tree*>q;
    q.push(t);
    while(!q.empty()){
        tree* temp=q.front();
        q.pop();
        for(auto x:temp->c){
         
         x->islockable=true;
         q.push(x);
        }
    }
   
    return true;
}



unordered_map<string,tree*>stot;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    tree*t=new tree();
    string d;
    cin>>d;
    stot[d]=t;
    queue<tree*>qu;
    qu.push(t);
    int k=1;
    while(!qu.empty()){
            auto temp=qu.front();
            qu.pop();
            while(k<n &&(int)temp->c.size()<m){
                    string s;
                    cin>>s;
                    tree* u=new tree();
                    stot[s]=u;
                    temp->c.push_back(u);
                    qu.push(u);
                    k++;
            }
    }
    for(int i=0;i<q;i++){
        int qn,uid;
        string name;
        bool ans;
        cin>>qn>>name>>uid;
        if(qn==1){
            ans=locking(stot[name],uid);
        }
        else if(qn==1) ans=unlocking(stot[name],uid);
        

        if(ans==1) cout<<"true\n";
        else cout<<"false\n";
    }


}