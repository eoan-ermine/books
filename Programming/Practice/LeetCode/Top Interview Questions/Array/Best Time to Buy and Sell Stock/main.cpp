#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int last = prices.front();
        
        for(auto it = prices.begin() + 1; it != prices.end(); ++it) {
            int current_value = *it;
            if(current_value > last) {
                profit += (current_value - last);
            }
            last = current_value;
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    Solution solution = Solution();
    cout << solution.maxProfit(prices);
}