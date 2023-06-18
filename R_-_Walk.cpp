#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define ll long long
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
uniform_int_distribution<int> uid(0,lim-1);
return uid(rang);
}
const int mod = 1e9+7;
//=======================
int add(int i, int j){
    if((i+=j)>=mod)
    i-=mod;
    return i;
}

int mul(int i, int j){
    return int((ll)i*j %mod);
}
template<class T> struct Matrix{
    T**mat;
    int a,b;
    Matrix():a(0),b(0){}
    Matrix(int a_,int b_):a(a_),b(b_){
        int i,j;
        mat=new T*[a];
        fo(i,a){
            mat[i]=new T[b];
            fo(j,b)
            mat[i][j]=0;
        }

    }
    Matrix(const vector<vector<T>>& vt){
        int i,j;
        *this=Matrix((int)vt.size(),(int)vt[0].size());
        fo(i,a){
        fo(j,b)
        mat[i][j]=vt[i][j];
        }

    }
    Matrix operator*(const Matrix & m){
        int i,j,k;
        assert(b==m.a);
        Matrix r(a,m.b);
        fo(i,a){
            fo(j,m.b)
             fo(k,b)
              r.mat[i][j]=add(r.mat[i][j],mul(mat[i][k],m.mat[k][j]));
        }
        return r;
    }
    Matrix &operator*=(const Matrix &m){
        return *this=(*this)*m;
    }
    friend Matrix power(Matrix m,ll p){
        int i;
        assert(m.a==m.b);
        Matrix r(m.a,m.b);
        fo(i,m.a)
        r.mat[i][i]=1;
        for(;p>0;p>>=1,m*=m)
         if(p&1)
           r*=m;
           return r;
    }
};

  
int main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
ll m;
cin>>n>>m;
vector<vector<int>> adj(n,vector<int>(n));
int i,j;
fo(i,n)
 fo(j,n)
  cin>>adj[i][j];
Matrix<int> mat(adj);
mat=power(mat,m);
int ans=0;
fo(i,n)
 fo(j,n)
  ans=add(mat.mat[i][j],ans);

cout<<ans;

// cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
return 0;
}

