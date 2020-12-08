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

struct node
{
    string ins;
    char sign;
    int value;
    int index;
    bool operator<(const node &t) const
    {
        return (this->index < t.index);
    }
};

void Solve()
{
    string s;
    vector<node> v;
    int count = 0;
    while (getline(cin, s))
    {

        if (s.empty())
        {
            break;
        }
        else
        {
            stringstream st;
            string temp;
            for (int i = 0; i < s.length(); i++)
            {
                temp += s[i];
                if (s[i] == '+' || s[i] == '-')
                    temp += ' ';
            }
            st << s;
            string ins;
            st >> ins;
            char sign;
            st >> sign;
            int value;
            st >> value;
            node a = {ins, sign, value, count};
            count++;
            v.emplace_back(a);
        }
    }
    set<node> checkrep;
    for (int j = 0; j < v.size(); j++)
    {
        bool flag = false;
        int acc = 0;
        string ogins = v[j].ins;
        if (v[j].ins == "acc")
        {
            continue;
        }
        if (v[j].ins == "jmp")
        {
            v[j].ins = "nop";
            flag = true;
        }
        else
        {
            v[j].ins = "jmp";
            flag = true;
        }
        set<node> checkrep;
        for (int i = 0; i < v.size(); i++)
        {
            if (checkrep.count(v[i]) == 0)
            {
                if (v[i].ins == "acc")
                {
                    if (v[i].sign == '+')
                    {
                        acc += v[i].value;
                    }
                    else
                        acc -= v[i].value;
                }
                if (v[i].ins == "jmp")
                {
                    if (v[i].sign == '+')
                    {
                        i += v[i].value;
                    }
                    else
                        i -= v[i].value;
                    i--;
                }
                checkrep.insert(v[i]);
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << acc << endl;
        else
        {
            v[j].ins = ogins;
        }
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