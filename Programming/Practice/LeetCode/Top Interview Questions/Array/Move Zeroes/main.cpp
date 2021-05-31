#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // My solution
    void moveZeroes(vector<int>& nums) {
        auto iterator = remove(nums.begin(), nums.end(), 0);
        for(auto it = iterator; it != nums.end(); ++it) {
            *it = 0;
        }
    }
    // Normal solution
    void moveZeroesGood(vector<int>& nums) {
        for(int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); ++cur) {
            if(nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};