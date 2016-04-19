// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation
// which turns the water at position (row, col) into a land. Given a list of positions to operate, count the
// number of islands after each addLand operation. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by
// water.

// Example:

// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

// 0 0 0
// 0 0 0
// 0 0 0
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
// We return the result as an array: [1, 1, 2, 3]

public class NumberOfIslandsII {
    class DisjointSetNode {
        DisjointSetNode parent;
        int rank;
        DisjointSetNode() {
            parent = this;
            rank = 0;
        }
    }

    class DisjointSet {
        private Set<DisjointSetNode> sets;

        DisjointSet() {
            sets = new HashSet<>();
        }

        void add(DisjointSetNode x) {
            sets.add(x);
        }

        DisjointSetNode find(DisjointSetNode x) {
            if (x.parent != x) {
                x.parent = find(x.parent);
            }
            return x.parent;
        }

        void union(DisjointSetNode x, DisjointSetNode y) {
            DisjointSetNode p1 = find(x);
            DisjointSetNode p2 = find(y);
            if (p1 == p2) {
                return;
            }
            if (p1.rank > p2.rank) {
                p2.parent = p1;
                sets.remove(p2);
            } else {
                if (p1.rank == p2.rank) {
                    p2.rank++;
                }
                p1.parent = p2;
                sets.remove(p1);
            }
        }

        int numOfSets() {
            return sets.size();
        }
    };

    int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        Map<Integer, DisjointSetNode> mp = new HashMap<>();
        DisjointSet dset = new DisjointSet();
        List<Integer> out = new ArrayList<>();
        for (int[] pos : positions) {
            DisjointSetNode node = new DisjointSetNode();
            mp.put(n * pos[0] + pos[1], node);
            dset.add(node);
            for (int[] d : dirs) {
                int x = pos[0]+d[0];
                int y = pos[1]+d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && mp.containsKey(n * x + y)) {
                    DisjointSetNode neighbour = mp.get(n * x + y);
                    if (dset.find(node) != dset.find(neighbour)) {
                        dset.union(node, neighbour);
                    }
                }
            }
            out.add(dset.numOfSets());
        }
        return out;
    }
}
