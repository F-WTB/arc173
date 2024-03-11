#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pr = pair<int, int>;
using mint = modint998244353;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
int T;
ll K;

ll f(ll K);

int main()
{
    cin >> T;
    for (int _ = 0; _ < T; ++_)
    {
        cin >> K;
        cout << f(K) << '\n';
    }
}

ll f(ll K)
{
    int d = 0;
    while (K - pow(9, d) >= 0)
    {
        K -= pow(9, d);
        ++d;
    }
    vector<int> v;
    for (int i = 0; i < d; ++i)
    {
        v.push_back(K % 9);
        K /= 9;
    }
    ll x = 0;
    int a = 0;

    for (int i = 0; i < d; ++i)
    {
        x *= 10;
        int t = v[d - 1 - i] + (v[d - 1 - i] >= a);
        x += t;
        a = t;
    }
    return x;
}
