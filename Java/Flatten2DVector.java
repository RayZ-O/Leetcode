// Implement an iterator to flatten a 2d vector.

// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next 
// should be: [1,2,3,4,5,6].

public class Vector2D {
    Queue<Iterator> iters = new LinkedList<>();

    public Vector2D(List<List<Integer>> vec2d) {
        for (List<Integer> vec : vec2d) {
            if (!vec.isEmpty()) {
                iters.add(vec.iterator());
            }
        }
    }

    public int next() {
        Iterator it = iters.element();
        int res = (int) it.next();
        if (!it.hasNext()) {
            iters.remove();
        }
        return res;
    }

    public boolean hasNext() {
        return !iters.isEmpty();
    }
}
