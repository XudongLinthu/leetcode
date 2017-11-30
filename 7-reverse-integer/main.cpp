class Solution {
public:
    int reverse(int x) {
        long long n = 0;
        int xx = std::abs(x);
        while (xx > 0) {
            int tmp = 10 * n + xx % 10;
            if (tmp / 10 != n) {
                return 0;
            }
            n = tmp;
            xx /= 10;
        }
        if (x < 0) {
            return -n;
        } else {
            return n;
        }
    }
};
