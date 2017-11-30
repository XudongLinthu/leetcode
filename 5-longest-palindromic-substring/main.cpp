class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            f[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            f[i][i-1] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1] + 2;
                } else {
                    f[i][j] = -2 << 30;
                }
            }
        }
        int maxl = 0;
        int maxi = 0, maxj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][j] > maxl) {
                    maxl = f[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
        }
        return s.substr(maxi, maxj - maxi + 1);
    }
private:
    static const int MAXN = 1000;
    int f[MAXN][MAXN];
};
