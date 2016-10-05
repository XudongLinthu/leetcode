class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        int k = n / 2;
        double tmp;
        if (n > 0) {
            tmp = myPow(x, k);
        } else {
            x = 1 / x;
            tmp = myPow(x, -k);
        }
        if (n % 2 == 0) {
            return tmp * tmp;
        } else {
            return tmp * tmp * x;
        }
    }
};
