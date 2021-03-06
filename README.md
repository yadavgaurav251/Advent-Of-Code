# Advent-Of-Code  ☃️&nbsp;🎄&nbsp;
[![GitHub stars](https://img.shields.io/github/stars/yadavgaurav251/Advent-Of-Code?style=social&label=Star&maxAge=2592000)](https://GitHub.com/yadavgaurav251/Advent-Of-Code/stargazers/)&nbsp;&nbsp;  [![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fyadavgaurav251%2FAdvent-Of-Code&count_bg=%2379C83D&title_bg=%23555555&icon=deezer.svg&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)

## 🤔&nbsp; What is Advent Of Code 

Advent of Code is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like. People use them as a speed contest, interview prep, company training, university coursework, practice problems, or to challenge each other.

You don't need a computer science background to participate - just a little programming knowledge and some problem solving skills will get you pretty far. Nor do you need a fancy computer; every problem has a solution that completes in at most 15 seconds on ten-year-old hardware.

## Feel Free To Ask Any Doubts
Ask any doubt related to Advent Of Code like logic, code, understanding the question, etc by creating a Issue with Doubt label on [yadavgaurav251/Advent-Of-Code](https://github.com/yadavgaurav251/Advent-Of-Code) repository. And I will try to resolve them to the best of my abilities.

## 🦠&nbsp; 2020 - 

## Day 1: Report Repair
[Problem Statement](https://adventofcode.com/2020/day/1)
#### Part One - 

This is a classic problem known as [Two Sum](https://leetcode.com/problems/two-sum/). 

e can write a brute force solution which will loop through each element x and find if there is another element which is equal to 2020-x. But this will have Time Complexity of O(n^2).

Efficient Solution with Time Complexity O(n) - We can use Hashing to reduce the time of searching from O(n) to O(1). Then we iterate and inserting elements into the table, we also look back to check if the current element's complement already exists in the table. If it exists, we have found a solution and return immediately.
#### Part Two - 
Again this is a very famous problem known as [Three Sum](https://leetcode.com/problems/3sum/). We just use the efficient code from part 1 and change target. We iterate through each element and target would become 2020-x.

```cpp
vector<int> v;
int temp;
while (cin >> temp)
{
    v.emplace_back(temp);
}

int ans = 0;
int n = v.size();
for (int i = 0; i < n; i++)
{

    int target = 2020 - v[i];
    unordered_set<int> s;
    for (int j = 0; j < n; j++)
    {
        if (i == j)
            continue;
        int x = v[j];

        if (s.count(x))
        {
            ans = x * (target - x) * v[i];
            break;
        }
        s.insert(target - x);
    }
}
cout << ans << endl;
```
## Day 2: Password Philosophy

[Problem Statement](https://adventofcode.com/2020/day/2)
#### Part One - 
The problem is quite simple. The only trouble you might encounter is getting the input and changing its type for that I would recommend using [StringStream](https://www.geeksforgeeks.org/stringstream-c-applications/) and then keep track of the number of the occurrences.

```cpp
string temp;
vector<string> v;
while(cin>>temp)
{
    v.emplace_back(temp);

}

int count=0;
int n=v.size();
for(int i=0;i<n;i+=3)
{
    int flag=0;
    string s1=v[i];
    for(int j=0;j<s1.length();j++)
    {
        if(s1[j]=='-')
        {
            s1[j]=' ';
        }
    }
    stringstream conv;
    conv<<s1;
    int l,r;
    conv>>l>>r;

    char tocheck=v[i+1][0];
    int occur=0;
    for(int j=0;j<v[i+2].length();j++)
    {
        if(v[i+2][j]==tocheck)
            occur++;
    }

    if(occur>=l && occur<=r)
        count++;
}
cout<<count<<endl;  

```
#### Part Two -
This is also quite similar to the above part here we can use XOR to easy or work of flipping the values. Since A= A XOR 1 will switch the value from 0 to 1 and 1 to 0 every time it runs.

```cpp
string temp;
vector<string> v;
while(cin>>temp)
{
    v.emplace_back(temp);

}
int count=0;
int n=v.size();
for(int i=0;i<n;i+=3)
{
    int flag=0;
    string s1=v[i];
    for(int j=0;j<s1.length();j++)
    {
        if(s1[j]=='-')
        {
            s1[j]=' ';
        }
    }
    stringstream conv;
    conv<<s1;
    int l,r;
    conv>>l>>r;

    char tocheck=v[i+1][0];
    for(int j=0;j<v[i+2].length();j++)
    {
        if(j+1 == l && v[i+2][j]==tocheck)
        {
            flag^=1;
        }
        if(j+1 == r && v[i+2][j]==tocheck)
        {
            flag^=1;
        }      
    }

    if(flag)
        count++;
}
cout<<count<<endl;

```
## Day 3: Toboggan Trajectory

[Problem Statement](https://adventofcode.com/2020/day/3)
#### Part One -

Simple graph traversal the only catch is the line -
> "These aren't the only trees, though; due to something you read about once involving arboreal genetics and biome stability, the same pattern repeats to the right many times"

we can simply handle by modulo every time the right crosses the limit i.e j=j%(length of the map)

```cpp

vector<string> v;
string s;
while (cin>>s)
{
    v.emplace_back(s);
}
int count=0;
int i=0,j=0;
int m=v[0].size(),n=v.size();
while(i<n)
{
    if(v[i][j]=='#')
        count++;
    i+=1;
    j+=3;
    j%=m;
}
cout<<count<<endl;

```
#### Part Two - 
It is just the same code with more moves to calculate the count on.

```cpp
vector<string> v;
string s;
while (cin >> s)
{
    v.emplace_back(s);
}

int m = v[0].size(), n = v.size();
vi ans(5);
vector<pair<int, int>> mov = {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};
for (int k = 0; k < 5; k++)
{
    int count = 0;
    int i = 0, j = 0;

    while (i < n)
    {
        if (v[i][j] == '#')
            count++;
        i += mov[k].first;
        j += mov[k].second;
        j %= m;
    }
    ans[k] = count;
}
ll total = 1;
for (auto x : ans)
    total *= x;
cout << total << endl;
```
## Day 4: Passport Processing

[Problem Statement](https://adventofcode.com/2020/day/4)
#### Part One -

We can simply ignore "cid" field and make a map in which we will push all fields that have been found. Once we encounter an empty line that means we have reached a new passport so we check the existing map if it contains all the required fields or not and then increase count accordingly.

```cpp

int count = 0;
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
                allpresent = false;
        }
        if (allpresent)
            count++;

        m.clear();
    }

    for (auto x : tocheck)
    {
        size_t found = s.find(x);
        if (found != string::npos)
        {
            m[x]++;
        }
    }
}
bool allpresent = true;
for (auto x : tocheck)
{
    if (m[x] == 0)
        allpresent = false;
}
if (allpresent)
    count++;
cout << count << endl;

```
#### Part Two - 

The code might seem a bit big but it's not very complicated. I used [StringStream](https://www.geeksforgeeks.org/stringstream-c-applications/)  to separate the input fields and then applied validations as given in the question and then increased count like part one.


```cpp
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
```



## Day 5: Binary Boarding 

[Problem Statement](https://adventofcode.com/2020/day/5)
#### Part One -

The first seven-character determine the rows and the last three characters determine the columns. It's similar to binary search. And then simply put the calculated values in the formula provided in the question to calculate the seat ID.

```cpp

 string s;
pair<string, int> ans = {"", 0};
while (cin >> s)
{
    int l = 0, r = 127;
    for (int i = 0; i < 7; i++)
    {
        int mid = (l + r) / 2;
        if (s[i] == 'F')
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int row = (l + r) / 2;

    l = 0;
    r = 7;
    for (int i = 7; i < 10; i++)
    {
        int mid = (l + r) / 2;
        if (s[i] == 'L')
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int col = (l + r) / 2;

    int id = (row * 8) + col;
    if (ans.second < id)
    {
        ans.first = s;
        ans.second = id;
    }
}
cout << ans.second << endl;
```
#### Part Two - 

We can use a set to store all the calculated the IDs and the question state the front and last seats are doesn't exist on this aircraft thus we start searching from 15 till 1011.

```cpp
string s;
pair<string, int> ans = {"", 0};
unordered_set<int> seated;
while (cin >> s)
{
    int l = 0, r = 127;
    for (int i = 0; i < 7; i++)
    {
        int mid = (l + r) / 2;
        if (s[i] == 'F')
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int row = (l + r) / 2;

    l = 0;
    r = 7;
    for (int i = 7; i < 10; i++)
    {
        int mid = (l + r) / 2;
        if (s[i] == 'L')
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int col = (l + r) / 2;

    int id = (row * 8) + col;

    seated.insert(id);
}
for (int i = 15 ; i <= 1011; i++)
{
    if (seated.count(i) == 0)
    {
        cout << i << endl;
        break;
    }
}
```

## Day 6: Custom Customs

[Problem Statement](https://adventofcode.com/2020/day/6)
#### Part One -

The question is fairly simple we can handle the input properly. We use getline instead of std::cin so that we receive an empty string we will know the group is over. Since duplicates won't be counted using Sets would be perfect since it will automatically delete duplicates. The total count would be equal to the individual Set.size() of each group.

```cpp

int count = 0;
unordered_set<int> answer;
string s;
while (getline(cin, s))
{
    if (s.empty())
    {

        count += answer.size();

        answer.clear();
    }

    for (auto x : s)
    {
        answer.insert(x);
    }
}
count += answer.size();
cout << count << endl;

```
#### Part Two - 

This time we need to add the number of question which all group members answered. We can make a map to increase the count of each question answered. If this value is equal to group count then that means everyone answered the question and we increase the total count.

```cpp
int count = 0;
string s;
int groupcount = 0;
map<char, int> answer;
while (getline(cin, s))
{
    if (s.empty())
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (answer[i] == groupcount)
                count++;
        }
        groupcount = 0;
        answer.clear();
    }
    else
    {
        groupcount++;
    }

    for (auto x : s)
    {
        answer[x]++;
    }
}
for (char i = 'a'; i <= 'z'; i++)
{
    if (answer[i] == groupcount)
        count++;
}
cout << count << endl;
```
## Day 7: Handy Haversacks

[Problem Statement](https://adventofcode.com/2020/day/7)

#### Part One -

The tricky part is to get data into correct form after that we can just look at the whole problem as a graph problem.We find list of bags starting from the colors which contain "shiny gold" and then subsequently find these bags in the list again till we can't find anymore unique bag which can contain "shiny gold" bag.
#### Part Two - 

The bags will behave like a tree ( wont contain a cycle or else the answer would have become infinity) . So we just traverse the tree starting from "shiny gold" to all its children while counting their counts ( like DFS ).

```cpp
int totalbags(string node, map<string, map<string, int>> &adj)
{
    int count = 0;
    if (adj[node].empty())
        return 0;
    else
    {
        for (auto x : adj[node])
        {
            count += x.second * (1 + totalbags(x.first, adj));
        }
    }
    return count;
}

void Solve()
{
    string s;
    map<string, map<string, int>> adj;
    vector<string> allbags;
    while (getline(cin, s))
    {
        int loc = s.find("bags");
        string curr = s.substr(0, loc - 1);
        map<string, int> listofbags;
        bool flag1 = false, flag2 = false;
        string bagname;
        int bagcount = 0;
        for (int i = loc; i < s.size() - 3; i++)
        {

            if (s[i] == ' ')
            {
                if (s[i + 1] == 'b' && s[i + 2] == 'a' && s[i + 3] == 'g')
                {
                    listofbags[bagname] = bagcount;
                    bagname = "";
                    flag1 = false;
                }
            }
            if (flag1)
                bagname += s[i];

            if (isdigit(s[i]))
            {
                bagcount = s[i] - '0';
                flag1 = true;
                i++;
            }
        }
        adj[curr] = listofbags;
        allbags.emplace_back(curr);
    }

    // PART ONE -

    int count = 0;
    queue<string> q;
    set<string> cancontain;
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
    cout << cancontain.size()<<endl;

    // PART TWO -
    count = 0;
    string first = "shiny gold";
    count = totalbags(first, adj);
    cout << count << endl;
}
```

## Day 8: Handheld Halting

[Problem Statement](https://adventofcode.com/2020/day/8)

#### Part One -

Using a struct to properly store data would make the problem a lot easier. Storing the sign will save us a tonne of headache in the code. The next thing is we need to detect if it's getting into an infinite loop. For this make a set of the structure and make sure to add an index variable in it so two same lines at different places are not treated identically. So before executing any line we check if it already present in the set, if yes then we break the loop and output the value in the accumulator.

```cpp
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
            v.pb(a);
        }
    }
    int acc = 0;
    set<node> checkrep;

    for (int i = 0; i < v.size(); i++)
    {
        if(checkrep.count(v[i])==0)
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
            cout<<acc<<endl;
            break;
        }
    }
}

```


#### Part Two - 

Keep changing one " jmp (to nop) or nop (to jmp)" and then check if it is still giving an infinite loop using part 1 code with some boolean flags and display the value of accumulator if there is not an infinite loop.

```cpp
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
            v.pb(a);
        }
    }
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
```
## Day 9: Encoding Error

[Problem Statement](https://adventofcode.com/2020/day/9)

#### Part One -

This is almost the same problem as Day 1: Report Repair or [Two Sum](https://leetcode.com/problems/two-sum/). The only thing that has changed is we need to search the value in a batch size of 25. For more detailed solution just scroll up and see solution for day 1.

```cpp
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

```


#### Part Two - 
To find a contiguous set of at least two numbers in your list which sum to the invalid number from step 1. We can use [Prefix Sum Array](https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/) and use it to calculate [Range Sum Query](https://www.geeksforgeeks.org/range-sum-queries-without-updates/) in O(1) time complexity, keep changing the range of query till we don't find the "Invalid Number" from Step 1 and store the result(indexes at which the number is found) in an array. Now simply find the maximum and minimum value in this range.

```cpp
 vector<long long> v;
long long temp;
while (cin >> temp)
    v.emplace_back(temp);

int n = v.size();

long long tofind = 507622668; // we get this value from part 1, your value may vary
vector<long long> presum(n, 0);
presum[0] = v[0];
for (int i = 1; i < n; i++)
    presum[i] = presum[i - 1] + v[i];

vector<int> loc;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < i; j++)
    {
        if ((presum[i] - presum[j]) == tofind)
        {
            loc.emplace_back(j);
            loc.emplace_back(i);
            break;
        }
    }
}
long long low = LLONG_MAX;
long long high = LLONG_MIN;
for (int i = loc[0]; i <= loc[1]; i++)
{
    low = min(low, v[i]);
    high = max(high, v[i]);
}

cout << low + high << endl;
```
## Day 10: Adapter Array

[Problem Statement](https://adventofcode.com/2020/day/10)

#### Part One -

This is just basic simulation as instructed in the quesiton and storing the result.

```cpp
vector<int> v;
int temp;
while(cin>>temp)
{
    v.emplace_back(temp);
}
v.emplace_back(0);
sort(v.begin(),v.end());
v.emplace_back(v[v.size()-1]+3);
int n=v.size();
vector<int> dif(4,0);

for(int i=0;i<n;i++)
{
    int j=i+1;
    while(j<n && (v[j]-v[i]) <4 )
    {
       dif[v[j]-v[i]]++;
       j++;
       break;
    }
}
cout<<dif[1]*dif[3];
```


#### Part Two - 

Backtracking ( TLE ) - Using backtracking can work smaller value like those in example but it won't work on large input values like that provided in the input. But it still provides us with valuable insights which will help us in making DP based solution for the problem.
```cpp
long long total = 0;
set<vector<int> > path;
bool backtracking(vector<int> v, int curr, vector<int> &outlet)
{
    if (v.size() - 1 == curr)
        return true;

        int i=curr;
        int j = i + 1;
        while (j < v.size() && (v[j] - v[i]) < 4)
        {
            outlet.push_back(v[j]);
            if (backtracking(v, j, outlet))
            {
                if (path.count(outlet) == 0)
                {
                    total++;
                    path.insert(outlet);
                }
            }
            j++;
            outlet.pop_back();
        }
    
    return false;
}
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
    vector<int> dif(4, 0);
    
    int j = 0;
    vector<int> outlet;
    outlet.push_back(0);
    total = 0;
    path.clear();
    backtracking(v, 0, outlet);
    cout << total << endl;
}
```
We can use DP here since the its has overlapping sub-problems. The DP is kinda similar to the Fibonacci DP.
> dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
```cpp
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
```



## 🤝&nbsp; Found a bug? Have a better solution ?

Feel free to **file a new issue** with a respective title and description on the the   [yadavgaurav251/Advent-Of-Code](https://github.com/yadavgaurav251/Advent-Of-Code) repository. If you already found a solution to your problem, **I would love to review your pull request**! 

