#include<bits/stdc++.h>
using namespace std;
struct node{
    map<char,node*>child;
    node* suffix_link=nullptr;
    node* output_link=nullptr;
    vector<int>id;
    
};
void build(node *root,vector<string>patterns){
    int i=0;
    for(auto st:patterns){
        node *curr=root;
        for(auto ch:st){
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }else{
                node *new_node=new node();
                curr->child[ch]=new_node;
                curr=new_node;
            }
        }
        curr->id.push_back(i);
        i++;
    }
}
// constructing suffix and output link on the top of trie
void construct(node * root){
    root->suffix_link=root;
    queue<node*>q;
    for(auto pr:root->child){
        char ch=pr.first;
        q.push(root->child[ch]);
        root->child[ch]->suffix_link=root;
    }
    while(!q.empty()){
        node * curr=q.front();
        q.pop();
        for(auto pr:curr->child){
            char ch=pr.first;
            node * child =curr->child[ch];
            node * tmp = curr->suffix_link;
            // pick the child and follow the suffix link untill the child of suffix link becomes the ch or it reaches the root
            while(!tmp->child.count(ch) && tmp!=root){
                tmp=tmp->suffix_link;
            }
            if(tmp->child.count(ch))
                child->suffix_link=tmp->child[ch];
            else
              child->suffix_link=root;
            q.push(child);
        }
        // setting output link(always point towards suffix link)
        if(curr->suffix_link->id.size()>0)
            curr->output_link=curr->suffix_link;
        else 
        curr->output_link=curr->suffix_link->output_link; 
    }
}
void search(node * root ,string &s,vector<vector<int>>&res){
        node *par = root;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(par->child.count(ch)){
                par=par->child[ch];
                if(par->id.size()>0){
                    for(auto x:par->id)
                        res[x].push_back(i);
                }
                node * my_output_link=par->output_link;
                while(my_output_link!=NULL){
                    for(auto x:my_output_link->id)
                        res[x].push_back(i);
                    
                    my_output_link=my_output_link->output_link;
                }
            }else{
                while(par!=root && !par->child.count(ch)){
                    par=par->suffix_link;
                }
                if(par->child.count(ch)){
                    i--;
                }
            }
        }
}
int main(){
    int n;cin>>n;
    vector<string>pat;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        pat.push_back(s);
    }
    string st;
    cin>>st;
    vector<vector<int>>lst(n);
    node * root= new node();
    build(root,pat);
    construct(root);
    search(root,st,lst);
    for(int i=0;i<n;i++){
        if(lst[i].size()==0) cout<<-1;
        else{
            for(auto end_pnts:lst[i]){
                cout<<end_pnts-pat[i].size()+1<<" ";
            }
        }
        cout<<"\n";
    }
}