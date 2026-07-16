/*
Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).



Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).



The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.



Note :

In a path no cell can be visited more than once.
If there is no possible path then return empty vector.

Example 1

Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]

Output : [ "DDRDRR" , "DRDDRR" ]

Explanation : The rat has two different path to reach (3, 3).

The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).

The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

Example 2

Input : n = 2 , grid = [ [1, 0] , [1, 0] ]

Output : -1

Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
    void pathfinder(int r, int c, string temp, vector<string>& ans, vector<vector<int>>& vis, vector<vector<int> > &grid){
        if(r == grid.size()-1 && c == grid.size()-1)
        {
            ans.push_back(temp);
            return;
        }
        vector<vector<int>> dir = {{1,0}, {0,-1}, {0,1}, {-1,0}};
        string move = "DLRU";
        for(int i=0; i<4; i++)
        {
            int nextr = r+dir[i][0];
            int nextc = c+dir[i][1];
            if(nextr >=0 && nextc >= 0 && nextr < grid.size() && nextr< grid.size() && !vis[nextr][nextc] && grid[nextr][nextc] == 1)
            {
                vis[r][c] = 1;
                pathfinder(nextr, nextc, temp+move[i], ans, vis, grid);
                vis[r][c] = 0;
                }
        }
        

    }
    public:
    vector<string> findPath(vector<vector<int> > &grid) {
        string temp = "";
        vector<vector<int>> vis (grid.size(),vector<int> (grid.size(),0));
        vector<string> ans;
        if(grid[0][0] == 1)
            pathfinder(0,0, temp, ans,vis, grid);

        return ans;
    }
};
