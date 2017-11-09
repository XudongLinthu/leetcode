class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            f[i][i] = 1;
        }
        for (int i = 1; i < len; i++) {
            f[i][i-1] = 0;
        }
        for (int n = 2; n <= len; n++) {
            for (int i = 0; i < len; i++) {
                int j = i + n - 1;
                if (j >= len) {
                    continue;
                }
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1] + 2;
                } else {
                    f[i][j] = std::max(f[i+1][j], f[i][j-1]);
                }
            }
        }
        return f[0][len-1];
    }

private:
    static const int MAXN = 1000;
    int f[MAXN][MAXN];
};
