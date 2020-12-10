/*
       Hi there <3 
──────▄▀▄─────▄▀▄
─────▄█░░▀▀▀▀▀░░█▄
─▄▄──█░░░░░░░░░░░█──▄▄
█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repa(i, a, n) for (int i = a; i < n; i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrepa(i, a, n) for (int i = n; i >= a; i--)
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define ba back()
#define popcount __builtin_popcountll
#define fastIO()                     \
    {                                \
        ios::sync_with_stdio(false); \
        cin.tie(NULL);               \
        cout.tie(NULL);              \
    }
#define in(x) \
    int x;    \
    cin >> x;
#define in1(x) \
    int x;     \
    cin >> x;  \
    x--;
#define inll(x) \
    ll x;       \
    cin >> x;
#define ins(x) \
    string x;  \
    cin >> x;

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef pair<double, double> pdd;
typedef long double LD;
typedef double D;

void Solve()
{
    vector<int> v;
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    v.push_back(v[v.size() - 1] + 3);
    int n = v.size();
    vector<long long> dp(n + 1, 0);
    long long sum = 1;
    int j = 0;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i - 1 >= 0 && v[i] - v[i - 1] <= 3)
        {
            dp[i] += dp[i - 1];
        }
        if (i - 2 >= 0 && v[i] - v[i - 2] <= 3)
        {
            dp[i] += dp[i - 2];
        }
        if (i - 3 >= 0 && v[i] - v[i - 3] <= 3)
        {
            dp[i] += dp[i - 3];
        }
    }
    cout << dp[n - 1] << endl;
}

int main()
{
    fastIO();
    int t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}