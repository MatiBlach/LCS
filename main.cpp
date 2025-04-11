/* https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/ */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string longest_common_subsequence(const string& x, const string& y) {
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs = x[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

int main() {
    int N;
    cin >> N;

    for (int case_num = 1; case_num <= N; ++case_num) {
        int n, m;
        cin >> n;
        string x;
        cin >> x;
        cin >> m;
        string y;
        cin >> y;

        cout << "case " << case_num << " ";

        string lcs = longest_common_subsequence(x, y);

        if (lcs.empty()) {
            cout << "N" << endl;
        }
        else {
            cout << "Y" << endl;
            cout << lcs.length() << endl;

            unordered_map<char, pair<int, int>> positions;
            int x_pos = 1;
            int y_pos = 1;
            for (char c : lcs) {
                while (x[x_pos - 1] != c) x_pos++;
                while (y[y_pos - 1] != c) y_pos++;
                cout << c << " " << x_pos++ << " " << y_pos++ << endl;
            }
        }
    }

    return 0;
}

