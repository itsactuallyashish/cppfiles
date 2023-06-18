#include<bits/stdc++.h>

using namespace std;

//structure of tree
struct tree{
    bool islocked;
    bool have_locked_desc;
    int uid;
    tree*parent;
    vector<tree*>c;
    tree(){
        uid=-1;
        have_locked_desc=false;
        islocked=false;
        parent=NULL;
    }
    tree(tree*par){
        parent=par;
        uid=-1;
        have_locked_desc=false;
        islocked=false;
    }
};

//implementation of lock function

        bool lock(tree *s,int id){
            // check if it has any locked descendents or is already locked
             if(s->islocked|| s->have_locked_desc) return false;
             bool flag=0;
            // check for the ancestors if locked and start occupying resources by setting have_anc_locked=1
             vector<tree*> temp;
            tree *cur =s->parent;
            while(cur){
                // check if it is locked if not occupy it
                 if(cur->islocked==false ){
                    cur->have_locked_desc=true;
                    temp.push_back(cur);
                 }
                 else {
                    flag=1;
                    break;
                 }
                cur=cur->parent;
            }

             if(flag==1) {
                //unblock_resources
                for(auto k:temp)
                   k->have_locked_desc=false;
                  return false; 
             }
             else {
                s->islocked=true;
                s->uid=id;
                return true;
             }

        }

  


