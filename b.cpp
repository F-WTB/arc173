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
int N, x[300][3];

ll s(int i, int j, int k)
{
    ll v = 0;
    int a[3] = {0, 1, 2};
    do
    {
        v += ll((a[1] - a[0] + 3) % 3 == 1 ? 1 : -1) * x[i][a[0]] * x[j][a[1]] * x[k][a[2]];
    } while (next_permutation(a, a + 3));
    return v;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i][0] >> x[i][1];
        x[i][2] = 1;
    }
    deque<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (q.size() > 1 && s(q.front(), q.back(), i))
        {
            q.pop_front();
            q.pop_back();
        }
        else
            q.push_back(i);
    }
    if (q.size() < 3)
    {
        cout << N / 3 << '\n';
        return 0;
    }
    int a = q.front();
    int b = q.back();
    int dx = x[b][0] - x[a][0];
    int dy = x[b][1] - x[a][1];
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    int c = 0;
    for (int i = 0; i < N; ++i)
        if (ll(x[i][0] - x[a][0]) * dy == ll(x[i][1] - x[a][1]) * dx)
            ++c;

    cout << min(N / 3, N - c) << '\n';
}
