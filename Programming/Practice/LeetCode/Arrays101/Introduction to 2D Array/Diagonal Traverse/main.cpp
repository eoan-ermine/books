// (0, 0)
// (0, 1), (1, 0)
// (2, 0), (1, 1), (0, 2)
// (1, 2), (2, 1)
// (2, 2)

// ---
// -i, +j; +i, -j;
// +i, -j; -i, +j; -i, +j;
// +i, =; +i, -j;
// =, +j



class Solution {
public:
	void searchPush(vector<vector<int>>& mat, vector<int>& result, int i, int j, int columns) {
		while(i >= 0 && j < columns) {
			result.push_back(mat[i][j]);
			--i, ++j;
		}
	}

	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		vector<int> result;

		int rows = mat.size();
		int columns = mat[0].size();

		for(int i = 0; i != rows; ++i) {
			this->searchPush(mat, result, i, 0, columns);
		}

		int i = rows - 1;
		for(int j = 1; j < columns; ++j) {
			this->searchPush(mat, result, i, j, columns);
		}

		return result;
	}
};
