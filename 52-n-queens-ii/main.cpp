class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) {
            return 0;
        }

        this->n = n;

        a.assign(n, -1);
        row.assign(n, false);
        col.assign(n ,false);
        pos_diag.assign(2 * n - 1, false);
        neg_diag.assign(2 * n - 1, false);

        cnt = 0;

        dfs(0);

        return cnt;
    }

private:
    int n;
    int cnt;

    vector<int> a;
    vector<bool> row;
    vector<bool> col;
    vector<bool> pos_diag;
    vector<bool> neg_diag;

    void dfs(int k) {
        if (k == n) {
            cnt++;
            return;
        }

        for (int i = 0; i < n; i++) {
            int pos = i - k + n - 1;
            int neg = i + k;
            if (!col[i] && !pos_diag[pos] && !neg_diag[neg]) {
                a[k] = i;
                col[i] = true;
                pos_diag[pos] = true;
                neg_diag[neg] = true;
                dfs(k + 1);
                a[k] = -1;
                col[i] = false;
                pos_diag[pos] = false;
                neg_diag[neg] = false;
            }
        }
    }
};
