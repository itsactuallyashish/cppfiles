#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define ll long long
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()

struct node{
    int x;
    node * next;
    node(int x,node * link):x(x),next(link){}
    node(int x):x(x){}
};
void solve() {
   ll n;see(n);
   node *head = new node(1);
    node * curr=head;
    for(int i=2;i<=n;i++){
        curr->next=new node(i);
        curr=curr->next;
    }
    curr->next=head;
    curr=head;
    int cnt=n;
    while(cnt>=1){
        put(curr->next->x);
        cnt--;
        node *tmp = curr->next;
        curr->next=tmp->next;
        delete(tmp);
        curr=curr->next;
    }
    
   
        
}
  
    
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout<<'\n';
    }

}
