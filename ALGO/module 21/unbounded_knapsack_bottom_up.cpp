#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int wei[n];
    int val[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wei[i];
    }

    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (wei[i - 1] <= j)
            {
                int op1 = dp[i][j - wei[i - 1]] + val[i - 1];
                int op2 = dp[i - 1][j];

                dp[i][j] = max(op1, op2);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][s];

    return 0;
}