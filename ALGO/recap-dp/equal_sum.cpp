#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    if (total % 2 == 0)
    {
        int sum = total / 2;

        int dp[n + 1][sum + 1];

        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    int op1 = dp[i - 1][j - arr[i - 1]];
                    int op2 = dp[i - 1][j];

                    dp[i][j] = op1 || op2;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][sum])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    cout << total << endl;

    return 0;
}