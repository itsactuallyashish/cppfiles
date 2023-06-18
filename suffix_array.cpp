//implimentation of suffix_arrays
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);};

struct suffix_arrays{
        int maxn=100004;
        int n=-1;
        string s;
        vector<int>RA,SA,tempSA,tempRA;
        vector<int>lcp;
        
        void countingsort(int k){
            int maxi=max(300,n);
            int sum=0;
            vector<int>c(maxn,0);
            for(int i=0;i<n;i++){
                c[i+k<n?RA[i+k]:0]+=1;//count the frequency of each integer rank
            }
            for(int i=0;i<maxi;i++){
                int t= c[i];
                c[i]=sum;
                sum+=t;
            }
            for(int i=0;i<n;i++){//shuffling the suffix array
                tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
            }
            for(int i=0;i<n;i++) SA[i]=tempSA[i];
        }
        void kasai(){
            lcp.assign(n,0);
                int k=0;
                vector<int>rank(n,0);
                for(int i=0;i<n;i++){
                    rank[SA[i]]=i;
                }
                for(int i=0;i<n;i++){
                    if(rank[i]==n-1){
                        k=0;
                        continue;
                    }
                    int j=SA[rank[i]+1];
                    while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
                    lcp[rank[i]]=k;
                    if(k) k--;
                }
            }
        void build(string x){
            s=x;
            // s.push_back('$');
            n=s.size();
            RA.assign(maxn,0);SA.assign(maxn,0);tempSA.assign(maxn,0);tempRA.assign(maxn,0);
            for(int i=0;i<n;i++){
                SA[i]=i;
                RA[i]=int(s[i])+0;
            }
            for(int k=1;k<n;k*=2){
                countingsort(k);
                countingsort(0);// for the stable sort
                int r=0;
                tempRA[SA[r]]=r;
                for(int i=1;i<n;i++){
                    //compare the adjacent suffixes if same pair => same rank otherwise r++;
                    tempRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
                }
                for(int i=0;i<n;i++)
                    RA[i]=tempRA[i];
                if(RA[SA[n-1]]==n-1) break;// optimization trick
            }
                kasai();
        }
};

int main(){
    string s;getline(cin,s);
    suffix_arrays ar;
    ar.build(s);
    for(int i=0;i<ar.n-1;i++){
        int x= ar.SA[i];
        // put(x);
        // cout<<ar.s.substr(x,ar.n)<<" ";
        cout<<ar.lcp[i]<<" ";
        // cout<<ar.SA[i];
        // cout<<"\n";
    }
    // for(int i=0;i<ar.n;i++) cout<<ar.lcp[i];
}