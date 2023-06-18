#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, ll> pii;
#define fast_io  ios_base::sync_with_stdio(false); cin.tie(NULL)
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    Tree<pii> st;
    const int MOD=1e7;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> sal(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>sal[i];
        st.insert({sal[i],i});
    }
    for(int i=0;i<q;i++){
        char ch;
        cin>>ch;
        if(ch=='!'){
            int a;
            ll b;
            cin>>a>>b;
            st.erase({sal[a],a});
            sal[a]=b;
            st.insert({sal[a],a});
        }
        else{
            ll a,b;
            cin>>a>>b;
            cout<<st.order_of_key({b,MOD})-st.order_of_key({a-1,MOD})<<"\n";
        }
    }
}