#include <algorithm>
#include <vector>

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> sample_vector = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solution = Solution();
    solution.removeDuplicates(sample_vector);

    for(const int& i: sample_vector) {
        cout << i;
    }
}