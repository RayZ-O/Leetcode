// A 2d grid map of m rows and n columns is initially filled with water. We may perform
// an addLand operation which turns the water at position (row, col) into a land. Given a
// list of positions to operate, count the number of islands after each addLand operation.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally
// or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example:

// Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1
// represents land).

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

class Solution {
    struct ParentTree {
        ParentTree* parent;
        ParentTree() : parent(nullptr) {}
    };

    using position = pair<int, int>;
    int m;
    int n;
    int count = 0;
    unordered_map<int, ParentTree*> islands;

    const vector<position> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool inGrid(int i, int j) {
        return i >= 0 && i < m && j >=0 && j < n;
    }

    void addLand(position pos) {
        ParentTree* root1 = nullptr;
        ParentTree* pt = makeSet();
        islands[pos.first * n + pos.second] = pt;
        for (auto d : dirs) {
            int x = pos.first + d.first;
            int y = pos.second + d.second;
            if (inGrid(x, y) && islands.find(x * n + y) != islands.end()) {
                if (!root1) {
                    root1 = find(islands[x * n + y]);
                    unionSet(root1, pt);
                } else {
                    ParentTree* root2 = find(islands[x * n + y]);
                    if (root2 != root1) {
                        unionSet(root1, root2);
                        --count;
                    }
                }
            }
        }
        if (!root1) {
            ++count;
        }
    }

    ParentTree* makeSet() {
        ParentTree* pt = new ParentTree;
        pt->parent = pt;
        return pt;
    }

    ParentTree* find(ParentTree* pt) {
        if (pt->parent == pt) {
            return pt;
        } else {
            return find(pt->parent);
        }
    }

    void unionSet(ParentTree* pt1, ParentTree* pt2) {
        find(pt2)->parent = find(pt1);
    }

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        this->m = m;
        this->n = n;
        vector<int> output;
        for (auto p : positions) {
            addLand(p);
            output.push_back(count);
        }
        return output;
    }
};
