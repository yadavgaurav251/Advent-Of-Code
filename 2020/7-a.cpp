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
    string s;
    map<string, set<string>> adj;
    vector<string> allbags;
    while (getline(cin, s))
    {
        int loc = s.find("bags");
        string curr = s.substr(0, loc - 1);
        //cout<<curr<<curr.size()<<endl;
        set<string> listofbags;
        bool flag1 = false, flag2 = false;
        string bagname;
        for (int i = loc; i < s.size() - 3; i++)
        {
            if (s[i] == ' ')
            {
                if (s[i + 1] == 'b' && s[i + 2] == 'a' && s[i + 3] == 'g')
                {
                    listofbags.insert(bagname);
                    bagname = "";
                    flag1 = false;
                }
            }
            if (flag1)
                bagname += s[i];

            if (isdigit(s[i]))
            {
                flag1 = true;
                i++;
            }
        }
        adj[curr] = listofbags;
        allbags.emplace_back(curr);
    }

    int count = 0;
    queue<string> q;
    set<string> cancontain;
    string first;
    for (auto x : allbags)
    {
        if (adj[x].count("shiny gold"))
        {
            if (cancontain.count(x) == 0)
                q.push(x);
            cancontain.insert(x);
            q.push(x);
        }
    }
    while (!q.empty())
    {
        string head = q.front();
        q.pop();

        for (auto x : allbags)
        {
            if (adj[x].count(head))
            {
                if (cancontain.count(x) == 0)
                    q.push(x);
                cancontain.insert(x);
            }
        }
    }
    //for (auto x : cancontain)
      //  cout << x << endl;
    cout << cancontain.size();
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