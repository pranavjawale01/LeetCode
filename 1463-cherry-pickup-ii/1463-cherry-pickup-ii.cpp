class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prev(n, vector<int>(n));
        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
        
        for (int row = 1; row < m; row++) {

            vector<vector<int>> curr(n, vector<int>(n));

            for (int c1 = 0; c1 <= min(n-1, row); c1++) {
                for (int c2 = max(0, n-1-row); c2 < n; c2++) {
                    
                    int prev_max = 0;
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, prev[column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        curr[c1][c2] = prev_max + grid[row][c1];
                    else
                        curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev[i][j]);    
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int t[71][71][71] = {0};
        
//         t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1]; 
        
//         for (int row = 1; row < m; row++) {
//             for (int c1 = 0; c1 <= min(n-1, row); c1++) { 
//                 for (int c2 = max(0, n-1-row); c2 < n; c2++) {                    
//                     int prev_max = 0;
//                     for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
//                         for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
//                                 prev_max = max(prev_max, t[row - 1][column1][column2]);
//                         }
//                     }
                    
//                     if (c1 == c2)
//                         t[row][c1][c2] = prev_max + grid[row][c1];
//                     else
//                         t[row][c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
//                 }
//             }
//         }
        
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 res = max(res, t[m - 1][i][j]);    
//             }
//         }
//         return res;
//     }
// };

// // class Solution {
// // public:
// //     int m, n;
// //     int t[71][71][71];
// //     vector<int> colDir{-1, 0, 1};
// //     bool isSafe(int& i) {
// //         return i >= 0 && i < n;
// //     }    
// //     int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
// //         if (row >= m)
// //             return 0;       
        
// //         if (t[row][c1][c2] != -1) {
// //             return t[row][c1][c2];
// //         }
        
// //         int count = grid[row][c1];
// //         if (c1 != c2) {
// //             count += grid[row][c2];
// //         }       
        
// //         int ans = 0;
// //         for(int& x : colDir) {
// //             for(int& y : colDir) {
// //                 int c1_ = x + c1;
// //                 int c2_ = y + c2;                
// //                 if(isSafe(c1_) && isSafe(c2_)) {
// //                     ans = max(ans, solve(grid, row+1, c1_, c2_));
// //                 }
// //             }
// //         }        
// //         return t[row][c1][c2] = count+ans;  
// //     }
    
// //     int cherryPickup(vector<vector<int>>& grid) {
// //         m = grid.size();
// //         n = grid[0].size();
// //         memset(t, -1, sizeof(t));
// //         return solve(grid, 0, 0, n-1);
// //     }
// // };