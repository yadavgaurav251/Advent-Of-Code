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
    vector<long long> v;
    long long temp;
    while (cin >> temp)
        v.emplace_back(temp);

    for(int i=25;i<v.size();i++)
    {
        long long target=v[i];
        unordered_set<int> s;
        bool flag=false;
        for(int j=i-25;j<i;j++)
        {
            if(s.count(target-v[j]))
            {
                flag=true;
                break;
            }
            else
            {
                s.insert(v[j]);
            }
            
        }
        if(!flag)
            cout<<v[i]<<endl;
    }

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