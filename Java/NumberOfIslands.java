// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded 
// by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four 
// edges of the grid are all surrounded by water.

// Example 1:

// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:

// 11000
// 11000
// 00100
// 00011
// Answer: 3

public class NumberOfIslands {
    int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = m > 0 ? grid[0].length : 0;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(char[][] grid, int i, int j, int m, int n) {
        grid[i][j] = '#';
        for (int[] d : dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                dfs(grid, x, y, m, n);
            }
        }
    }
}
