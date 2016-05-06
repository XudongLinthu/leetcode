#include <iostream>

// start

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (size_t i = 0; i < nums.size(); i++) {
            nums_map[nums[i]] = i;
        }
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int other = target - num;
            auto find = nums_map.find(other);
            if (find != nums_map.end() && find->second != i) {
                res.push_back(i);
                res.push_back(find->second);
                return res;
            }
        }
        return res;
    }
};

// end


int main() {
    vector<int> nums = {{3, 2, 4}};
    Solution s;
    auto res = s.twoSum(nums, 6);
    std::cout << res[0] << " " << res[1] << std::endl;
}
