// https://leetcode.com/problems/set-matrix-zeroes/
// 19/12/2021

class Solution {
public:
    pair<int,int> d[4] {
        make_pair(-1, 0),
        make_pair(0, -1),
        make_pair(1, 0),
        make_pair(0, 1)
    };
    int mxN = 200;
    
    int findDNE (vector<vector<int>>& matrix) {
        unordered_set<int> s;
        for (vector<int>& row: matrix) {
            s.insert(row.begin(), row.end());
        }
        for (int i = 1; i<=mxN*mxN; ++i) {
            if (!s.count(i)) {
                return i;
            }
        }
        return mxN*mxN+2;
    }
    
    void propogate (vector<vector<int>>& matrix, int unique, int ogR, int ogC) {
        for (const auto& [dr, dc]: d) {
            for (int dis = 0; ; ++dis) {
                int r = ogR+dis*dr;
                int c = ogC+dis*dc;
                if (!(0<=r && r<matrix.size()) || !(0<=c && c<matrix[0].size())) {
                    break;
                } else if (matrix[r][c]!=0) {
                    matrix[r][c] = unique;
                }
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int unique = findDNE(matrix);
        for (int r = 0; r<matrix.size(); ++r) {
            for (int c = 0; c<matrix[0].size(); ++c) {
                if (matrix[r][c]==0) {
                    propogate(matrix, unique, r, c);
                }
            }
        }
        for (vector<int>& row: matrix) {
            replace(row.begin(), row.end(), unique, 0);
        }
    }
};
