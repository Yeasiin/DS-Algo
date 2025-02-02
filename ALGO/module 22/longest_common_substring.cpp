#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int maxInt = INT_MIN;
    pair<int, int> dpIndex;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";

            if (dp[i][j] > maxInt)
            {
                maxInt = max(maxInt, dp[i][j]);
                dpIndex = {i, j};
            }
        }

        cout << endl;
    }

    cout << maxInt;

    cout << "\n"
         << dpIndex.first << " => " << dpIndex.second;

    cout << endl;

    string ans;
    while (dpIndex.first != 0 && dpIndex.second != 0)
    {
        if (a[dpIndex.first - 1] == b[dpIndex.second - 1])
        {
            ans += a[dpIndex.first - 1];
            dpIndex.first--;
            dpIndex.second--;
        }
        else
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}