#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {        
        int size = s.size() - 1;
        for(int i = 0; i <= size / 2; ++i) {
            std::swap(s[i], s[size - i]);
        }
    }
};