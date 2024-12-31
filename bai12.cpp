#include < bits / stdc++.h>
using namespace std;
long long w[100005], v[100005]; // mang w la trong luong moi mon do, va mang v la gia tri tuong ung cua mon do long long dp[100005][100005];
int main()
{
    int n, s; // n: so luong mon do; S: trong luong toi da nguoi do co the mang
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            // khong chon mon do thu i, thi gia tri trong tui bang gia tri truoc do
            dp[i][j] = dp[i - 1][j];
            // chon do vat thu i, gia tri trong tui la dp[i-1][j -w[i]] + v[i] if(j >= w[il)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); // tui phai co trong luong it nhat bang trong luong mon do thi moi co the chua duoc no
            }
        }
    }
    cout << dp[n][s];
    return 0;
}