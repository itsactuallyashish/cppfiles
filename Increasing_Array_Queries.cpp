#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
const int MAXN = 3e6;
long long seg[4 * MAXN];
int n;
#define ll long long

ll qry(int l, int r)
{
	ll res = 0;

	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += seg[l++];
		if (r & 1)
			res += seg[--r];
	}
	return res;
}
void upd(int in, ll val)
{
	in += n;
	seg[in] = val;

	in >>= 1;
	while (in >= 1)
	{
		seg[in] = seg[2 * in] + seg[2 * in + 1];
		in >>= 1;
	}
	return;
}
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
ll pre[maxn], contr[maxn], ans[maxn], x[maxn];
vector<pii> que[maxn];
int main()
{
	fast_io;
	int nn, q;
	cin >> nn >> q;

	for (int i = 0; i < nn; i++)
	{
		cin >> x[i];
		pre[i] = pre[i - 1] + x[i];
	}
	x[nn] = 1e18;
	pre[nn] = pre[nn - 1] + x[nn];
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		que[a].push_back(make_pair(b, i));
	}

	n=ceil(pow(2,log2(nn)));
	// n = nn;
	deque<int> stck = {nn};
	for (int i = nn - 1; i >= 0; i--)
	{
		while (stck.size() && x[i] >= x[stck.front()])
		{
			upd(stck.front(), 0);
			stck.pop_front();
		}
		contr[i] = (stck.front() - 1 - i) * x[i] - (pre[stck.front() - 1] - pre[i]);
		upd(i, contr[i]);
		stck.push_front(i);
		for (pii j : que[i])
		{
			int pos = upper_bound(stck.begin(), stck.end(), j.first) - stck.begin() - 1;
			ans[j.second] = (pos ? qry(i, stck[pos - 1]) : 0) + (j.first - stck[pos]) * x[stck[pos]] - (pre[j.first] - pre[stck[pos]]);
		}
	}
	for (int i = 0; i < q; i++)
	{
		cout << ans[i] << "\n";
	}
}