#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


using std::string;
using std::unordered_map;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_set;
        int max_len = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            if (char_set.find(s[j]) != char_set.end()) {
                i = std::max(i, char_set[s[j]] + 1);
            }
            char_set[s[j]] = j;
            max_len = std::max(max_len, j - i + 1);
        }
        return max_len;
    }
};


int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    return 0;
}
