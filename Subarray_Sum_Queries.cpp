#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 1e6;
ll seg[mx][4];
int n;
void update(int in, ll val)
{
    in += n;
    for (int i = 0; i < 4; i++)
        seg[in][i] = val;
    in >>= 1;
    while (in > 0)
    {
        seg[in][0] = max({seg[2 * in][0], seg[2 * in + 1][0], seg[2 * in][2] + seg[2 * in + 1][1], 0ll});
        seg[in][1] = max({seg[2 * in][1], seg[2 * in][3] + seg[2 * in + 1][1], 0ll});
        seg[in][2] = max({seg[2 * in + 1][2], seg[2 * in + 1][3] + seg[2 * in][2], 0ll});
        seg[in][3] = seg[2 * in][3] + seg[2 * in + 1][3];
        in >>= 1;
    }
}

int main()
{
    int nn, q;
    cin >> nn >> q;
    n = pow(2, ceil(log2(nn)));// most important step missing for a long time;
    vector<ll> v;
    for (int i = 0; i < nn; i++)
    {
        ll x;
        cin >> x;
        update(i, x);
    }

    while (q--)
    {
        int k;
        ll x;
        cin >> k >> x;
        update(k - 1, x);
        cout << seg[1][0] << "\n";
    }
}