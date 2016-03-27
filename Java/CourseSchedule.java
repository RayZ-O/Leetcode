// There are a total of n courses you have to take, labeled from 0 to n - 1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which 
// is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all 
// courses?

// For example:

// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is 
// possible.

// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take 
// course 0 you should also have finished course 1. So it is impossible.

public class CourseSchedule {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] v : prerequisites) {
            graph[v[0]].add(v[1]);
        }
        int[] state = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && detectCycle(graph, state, i)) {
                return false;
            }
        }
        return true;
    }
    
    boolean detectCycle(ArrayList<Integer>[] graph, int[] state, int i) {
        state[i] = 1;
        for (Integer u : graph[i]) {
            if (state[u] == 0 && detectCycle(graph, state, u)) {
                return true;
            }
            if (state[u] == 1) {
                return true;
            }
        }
        state[i] = 2;
        return false;
    }
}
