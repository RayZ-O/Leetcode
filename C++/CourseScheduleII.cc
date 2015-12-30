// There are a total of n courses you have to take, labeled from 0 to n - 1.

// Some courses may have prerequisites, for example to take course 0 you have to first
// take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering
// of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is
// impossible to finish all courses, return an empty array.

// For example:

// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0.
// So the correct course order is [0,1]

// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses
// 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course
// order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

class Solution {
    using adj_list = unordered_set<int>;
    enum class Color {WHITE, GRAY, BLACK};
    bool topoSort(vector<adj_list> &graph, int node, vector<Color> &color, vector<int> &output) {
        color[node] = Color::GRAY;
        for (int adj : graph[node]) {
            if (color[adj] == Color::WHITE && !topoSort(graph, adj, color, output)) {
                return false;
            } else if (color[adj] == Color::GRAY) {
                return false;
            }
        }
        color[node] = Color::BLACK;
        output.push_back(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<adj_list> graph(numCourses);
        vector<Color> color(numCourses, Color::WHITE);
        for (auto& p : prerequisites) {
            graph[p.first].insert(p.second);
        }
        vector<int> output;
        for (int i = 0; i < color.size(); i++) {
            if (color[i] == Color::WHITE && !topoSort(graph, i, color, output)) {
                return vector<int>();
            }
        }
        return output;
    }
};
