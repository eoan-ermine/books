class Solution {
public:
    vector<int> generateRow(vector<int>& previousRow, int rowIdx) {
        if(rowIdx == 0) {
            return {1};
        }
        if(rowIdx == 1) {
            return {1, 1};
        }
        
        vector<int> newRow(rowIdx + 1, 0);
        
        newRow[0] = 1;
        for(int i = 1; i < rowIdx; ++i) {
            newRow[i] = previousRow[i - 1] + previousRow[i];
        }
        newRow[rowIdx] = 1;
        
        return newRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        result.reserve(numRows);
        
        for(int i = 1; i < numRows; ++i) {
            result.push_back(generateRow(result.back(), i));   
        }
        
        return result;
    }
};
