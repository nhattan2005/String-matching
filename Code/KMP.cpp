#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
string s, t;
int pi[N];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    int m = s.length();
    s = " " + s;
    int n = t.length();
    t = " " + t;
    pi[1] = 0;
    int k = 0;
    for(int i = 2; i <= m; i++)
    {
        while(k > 0 && s[k+1] != s[i])
            k = pi[k];
        if(s[k+1] == s[i])
            k++;
        pi[i] = k;
    }
    //for(int i = 1; i <= m; i++) cout << pi[i] << " ";

    k = 0;
    for(int i = 1; i <= n; i++)
    {
        while(k > 0 && s[k+1] != t[i])
            k = pi[k];
        if(s[k+1] == t[i])
            k++;
        if(k == m)
        {
            cout << i-m+1 << " ";
            k = pi[k];
        }
    }
    return 0;
}
