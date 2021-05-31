#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        std::vector<int> to_insert;
        int size = arr.size();
        
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] == 0) {
                to_insert.push_back(i);
            }
        }
        for(int i = 0; i < to_insert.size(); ++i) {
            auto it = arr.begin();
            std::advance(it, to_insert[i] + i);
            arr.insert(it, 0);
        }
        arr.resize(size);
    }
};

int main() {
    Solution solution = Solution();
    vector<int> sample_vector = {1,0,2,3,0,4,5,0};

    solution.duplicateZeros(sample_vector);

    for(auto it = sample_vector.begin(); it != sample_vector.end(); ++it) {
        cout << *it;
    }
}