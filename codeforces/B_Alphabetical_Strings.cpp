#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    bool dp[n + 1][sum + 1];
    set<int> cnt[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
        cnt[i][0].insert(0);
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            for (auto t : cnt[i - 1][j])
            {
                cnt[i][j].insert(t);
            }

            if (arr[i - 1] <= j)
            {
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
                if (dp[i][j] == true)
                {
                    for (auto t : cnt[i - 1][j - arr[i - 1]])
                    {
                        cnt[i][j].insert(t + 1);
                    }
                }
            }
        }
    }

    int diff = INT32_MAX;

    if (n & 1)
        return -1;

    for (int j = sum / 2; j >= 0; j--)
    {

        if (dp[n][j] == true && cnt[n][j].find(n / 2) != cnt[n][j].end())
        {

            diff = sum - 2 * j;
            break;
        }
    }
    return (diff == INT32_MAX ? -1 : diff);
}

// Driver program to test above function
int main()
{
    int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cout<<findMin(arr, n);
}


// int n;
// 	cin >> n;
// 	int arr[n];
// 	for(int i=0; i<n; i++) {
// 		cin >> arr[i];
// 	}
// 	findMin(arr, n);


