// A group of two or more people wants to meet and minimize the total travel distance. You are 
// given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The 
// distance is calculated using Manhattan Distance, where 
// distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

// For example, given three people living at (0,0), (0,4), and (2,2):

// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
// The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. 
// So return 6.

public class BestMeetingPoint {
    public int minTotalDistance(int[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        int[] countX = new int[n];
        int[] countY = new int[m];
        int numPeople = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    countX[j]++;
                    countY[i]++;
                    numPeople++;
                }
            }
        }
        return minTotalDistance(countX, numPeople) + minTotalDistance(countY, numPeople);
    }

    int minTotalDistance(int[] count, int numPeople) {
        int cnt = 0;
        int point = 0;
        for (int i = 0; i < count.length; i++) {
            cnt += count[i];
            if (cnt > numPeople/2) {
                point = i;
                break;
            }
        }
        int dist = 0;
        for (int i = 0; i < count.length; i++) {
            dist += count[i] * Math.abs(i - point);
        }
        return dist;
    }
}
