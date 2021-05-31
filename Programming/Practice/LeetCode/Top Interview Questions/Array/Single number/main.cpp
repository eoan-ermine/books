#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> occurences;
        for(const int& num: nums) {
            occurences[num] += 1;
        }
        for(auto it = occurences.begin(); it != occurences.end(); ++it) {
            if(it->second == 1) {
                return it->first;
            }
        }

        // Time: O(n)
        // Space: O(n)
    }

    int singleNumberOptimal(vector<int>& nums) {
        int result = 0;
        for(const int& num: nums) {
            result ^= num;
        }
        return result;

        // Time: O(n)
        // Space: O(1)
    }
};