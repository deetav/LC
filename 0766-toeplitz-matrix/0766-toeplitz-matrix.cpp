class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
            int N = (int) matrix.size();
            int M = (int) matrix[0].size();
            for (int i = M - 1; i >= 0; --i) {
                    int X = 0, Y = i;
                    set<int> x;
                    while (X < N && Y < M) {
                            x.insert(matrix[X][Y]);
                            ++X;
                            ++Y;
                    }
                    if ((int) x.size() != 1) return false;
            }
            for (int i = 1; i < N; ++i) {
                    int X = i, Y = 0;
                    set<int> x;
                    while (X < N && Y < M) {
                            x.insert(matrix[X][Y]);
                            ++X;
                            ++Y;
                    }
                    if ((int) x.size() != 1) return false;
            }
            return true;
    }
};