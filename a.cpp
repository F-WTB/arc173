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
ll f(int d, ll K);
ll f(int d, int x, ll K);

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
    return f(d, K);
}
ll f(int d, ll K)
{
    ll t = pow(9, d - 1);
    return f(d, K / t + 1, K % t);
}
ll f(int d, int x, ll K)
{
    if (d == 0)
        return 0;
    if (d == 1)
        return x;
    ll t = pow(9, d - 2);
    if (K < pow(9, d - 2))
        return x * pow(10, d - 1) + f(d - 2, K);
    else
    {
        int y = K / t;
        return x * pow(10, d - 1) + f(d - 1, y + (y >= x), K % t);
    }
}
