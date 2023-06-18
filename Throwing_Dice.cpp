#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1ll << 60;
const int md = 1e9 + 7;
using matrix = vector<vector<ll>>;
matrix g;
matrix mul(matrix A, matrix B)
{
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            for (int k = 0; k < A[0].size(); k++)
            {

                C[i][j] += A[i][k] * B[k][j] % md;
                C[i][j] %= md;
            }
        }
    }
    return C;
}
matrix binex(matrix x, ll y)
{
    matrix r(x.size(), vector<ll>(x.size()));
    int f = 0;
    while (y > 0)
    {
        if (y & 1)
        {
            if (f)
                r = mul(r, x);
            else
                r = x, f = 1;
        }
        y = y >> 1;
        x = mul(x, x);
    }
    return r;
}
int main()
{
    ll k;
    cin >> k;
    g.assign(6, vector<ll>(6, 0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0)
                g[i][j] = 1;
            else if (i - j == 1)
                g[i][j] = 1;
        }
    }
    matrix res(binex(g, k));
    cout << res[0][0];
}