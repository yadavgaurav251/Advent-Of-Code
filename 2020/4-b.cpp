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
    int count = 0;
    bool flag = false;
    map<string, int> m;
    vector<string> tocheck = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    string s;
    while (getline(cin, s))
    {
        if (s.empty())
        {
            bool allpresent = true;
            for (auto x : tocheck)
            {
                if (m[x] == 0)
                {
                    allpresent = false;
                }
            }
            if (allpresent)
                count++;

            m.clear();
        }

        stringstream breaker;
        breaker << s;
        while (breaker >> s)
        {
            //cout<<s<<endl;
            for (auto &x : s)
                if (x == ':')
                    x = ' ';

            for (auto x : tocheck)
            {
                size_t found = s.find(x);
                if (found != string::npos)
                {
                    if (x == "byr")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        int age;
                        st >> temp >> age;
                        if (age >= 1920 && age <= 2002)
                        {
                            m[x]++;
                        }
                    }
                    else if (x == "iyr")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        int age;
                        st >> temp >> age;
                        if (age >= 2010 && age <= 2020)
                        {
                            m[x]++;
                        }
                    }
                    else if (x == "eyr")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        int age;
                        st >> temp >> age;
                        if (age >= 2020 && age <= 2030)
                        {
                            m[x]++;
                        }
                    }
                    else if (x == "hgt")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        string ht;
                        st >> temp >> ht;
                        int n = ht.size();
                        if (ht[n - 1] == 'n' && ht[n - 2] == 'i')
                        {
                            int value = stoi(ht.substr(0, n - 2));
                            if (value >= 59 && value <= 76)
                                m[x]++;
                        }
                        else if (ht[n - 1] == 'm' && ht[n - 2] == 'c')
                        {
                            int value = stoi(ht.substr(0, n - 2));
                            if (value >= 150 && value <= 193)
                                m[x]++;
                        }
                    }
                    else if (x == "hcl")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        string ht;
                        st >> temp >> ht;
                        if (ht[0] == '#' && ht.size() == 7)
                        {
                            bool correct = true;

                            for (int i = 0; i < 6; i++)
                            {
                                if (isalpha(ht[i + 1]))
                                {
                                    if (ht[i + 1] - 'f' > 0)
                                        correct = false;
                                }
                                else if (!isdigit(ht[i + 1]))
                                {
                                    // anything beside aphabet or digit would be wrong
                                    correct = false;
                                }
                            }
                            if (correct)
                                m[x]++;
                        }
                    }
                    else if (x == "ecl")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        string ht;
                        st >> temp >> ht;
                        unordered_set<string> validcol = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                        if (validcol.count(ht))
                        {
                            m[x]++;
                        }
                    }
                    else if (x == "pid")
                    {
                        stringstream st;
                        st << s;
                        string temp;
                        string ht;
                        st >> temp >> ht;
                        if (ht.size() == 9)
                        {
                            bool correct = true;
                            for (int i = 0; i < 6; i++)
                            {
                                if (!isdigit(ht[i + 1]))
                                {
                                    // anything beside digit would be wrong
                                    correct = false;
                                }
                            }
                            if (correct)
                                m[x]++;
                        }
                    }
                    //cout<<x<<" "<<m[x]<<endl;
                }
            }
        }
    }
    bool allpresent = true;
    for (auto x : tocheck)
    {
        if (m[x] == 0)
        {
            allpresent = false;
        }
    }
    if (allpresent)
        count++;
    cout << count << endl;
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
/*
for (auto &x : s)
    if (x == ':')
        x = ' ';
for (auto x : tocheck)
{
    size_t found = s.find(x);
    if (found != string::npos)
    {
        if (x == "byr")
        {
            stringstream st;
            st << s;
            string temp;
            int age;
            st >> temp >> age;
            if (age >= 1920 && age <= 2002)
            {
                m[x]++;
            }
        }
        else if (x == "iyr")
        {
            stringstream st;
            st << s;
            string temp;
            int age;
            st >> temp >> age;
            if (age >= 2010 && age <= 2020)
            {
                m[x]++;
            }
        }
        else if (x == "eyr")
        {
            stringstream st;
            st << s;
            string temp;
            int age;
            st >> temp >> age;
            if (age >= 2020 && age <= 2030)
            {
                m[x]++;
            }
        }
        else if (x == "hgt")
        {
            stringstream st;
            st << s;
            string temp;
            string ht;
            st >> temp >> ht;
            int n = ht.size();
            if (ht[n - 1] == 'n' && ht[n - 2] == 'i')
            {
                int value = stoi(ht.substr(0, n - 2));
                if (value >= 59 && value <= 76)
                    m[x]++;
            }
            else if (ht[n - 1] == 'm' && ht[n - 2] == 'c')
            {
                int value = stoi(ht.substr(0, n - 2));
                if (value >= 150 && value <= 192)
                    m[x]++;
            }
        }
        else if (x == "hcl")
        {
            stringstream st;
            st << s;
            string temp;
            string ht;
            st >> temp >> ht;
            if (ht[0] == '#' && ht.size() == 7)
            {
                bool correct = true;

                for (int i = 0; i < 6; i++)
                {
                    if (isalpha(ht[i + 1]))
                    {
                        if (ht[i + 1] - 'f' > 0)
                            correct = false;
                    }
                    else if (!isdigit(ht[i + 1]))
                    {
                        // anything beside aphabet or digit would be wrong
                        correct = false;
                    }
                }
                if (correct)
                    m[x]++;
            }
        }
        else if (x == "ecl")
        {
            stringstream st;
            st << s;
            string temp;
            string ht;
            st >> temp >> ht;
            unordered_set<string> validcol = {"amb", " blu", "brn", "gry", "grn", "hzl", "oth"};
            if (validcol.count(ht))
            {
                m[x]++;
            }
        }
        else if (x == "pid")
        {
            stringstream st;
            st << s;
            string temp;
            string ht;
            st >> temp >> ht;
            if (ht.size() == 9)
            {
                bool correct = true;
                for (int i = 0; i < 6; i++)
                {
                    if (!isdigit(ht[i + 1]))
                    {
                        // anything beside digit would be wrong
                        correct = false;
                    }
                }
                if (correct)
                    m[x]++;
            }
        }
    }
*/