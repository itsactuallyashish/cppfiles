#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int i, j, k, b, uid, q, a, N, M, Q, flag;
    cin >> N >> M >> Q;
    map<string, int> mp;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        mp[s] = i;
    }
    map<int, int> hash;
    for (int i = 0; i < N; i++)
        hash[i] = -1;
    vector<vector<ll>> A(N);
    i = 1;
    j = 0;
    k = 0;
    while (i < N)
    {
        A[j].push_back(i);
        k++;
        if (k == M)
        {
            k = 0;
            j++;
        }
        i++;
    }
    string x;
    for (i = 0; i < Q; i++)
    {
        cin >> q >> x >> uid;
            a = mp[x];
            flag = 1;
        if (q == 1)
        {
            
            vector<ll> st;
            b = ceil(float(a) / float(M)) - 1;
            st.push_back(b);
            while (b != 0)
            {
                b = ceil(float(b) / float(M)) - 1;
                st.push_back(b);
            }
            for (k = 0; k < st.size(); k++)
            {
                if (hash[st[k]] != -1)
                {
                    flag = 0;
                    break;
                }
            }
            vector<ll> temp;
            temp.push_back(a);
            i = 0;
            j = 1;
            while (i != j)
            {
                for (auto p : A[temp[i]])
                {
                    if (hash[p] != -1)
                    {
                        flag = 0;
                        break;
                    }
                    else
                    {
                        temp.push_back(p);
                        j++;
                    }
                }
                i++;
            }
            if (flag == 1)
                hash[a] = uid;
        }
        else if (q == 2)
        {
            flag = 0;
            if (hash[a] == uid)
            {
                hash[a]=-1;
                flag = 1;
            }
        }
        else
        {
             
            for(auto p:A[a]){
                // cerr<<hash[p]<<" ";
                if(hash[p]!=uid){
                    flag=0;break;
                }
            }
            // cerr<<flag;
            if(flag==1){
                for(auto p:A[a]){
                    hash[p]=-1;
                }
                hash[a]=uid;
            }
        }
        if (flag == 1)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

