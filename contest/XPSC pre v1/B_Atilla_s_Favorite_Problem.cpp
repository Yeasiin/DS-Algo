#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 1;

        for (int i = 0; i < n; i++)
        {

            ans = max(ans, s[i] - 'a' + 1);
        }
        cout << ans << endl;
    }

    return 0;
}