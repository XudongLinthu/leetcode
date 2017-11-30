class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        std::vector<int> count(n + 1);
        for (int c: citations) {
            if (c >= n) {
                count[n]++;
            } else {
                count[c]++;
            }
        }
        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};
