// Given two 1d vectors, implement an iterator to return their elements alternately.

// For example, given two 1d vectors:

// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next 
// should be: [1, 3, 2, 4, 5, 6].

public class ZigzagIterator {
    Queue<Iterator> iters = new LinkedList<>();
    
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        if (!v1.isEmpty()) {
            iters.add(v1.iterator());
        }
        if (!v2.isEmpty()) {
            iters.add(v2.iterator());
        }
    }

    public int next() {
        Iterator it = iters.remove();
        int res = (int) it.next();
        if (it.hasNext()) {
            iters.add(it);
        }
        return res;
    }

    public boolean hasNext() {
        return !iters.isEmpty();
    }
}
