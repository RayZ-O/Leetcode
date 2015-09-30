// Given two 1d vectors, implement an iterator to return their elements alternately.

// For example, given two 1d vectors:

// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next
// should be: [1, 3, 2, 4, 5, 6].

// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

class ZigzagIterator {
    typedef vector<int>::iterator Intiter;
    typedef list<pair<Intiter, Intiter>> Iterlist;
    Iterlist iters;
    Iterlist::iterator cur;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iters = {{v1.begin(), v1.end()}, {v2.begin(), v2.end()}};
        cur = iters.begin();
    }

    int next() {
        int val = *cur->first++;
        if (++cur == iters.end()) cur = iters.begin();
        return val;
    }

    bool hasNext() {
        while (!iters.empty() && cur->first == cur->second) {
            auto temp = cur;
            if (++cur == iters.end()) cur = iters.begin();
            iters.erase(temp);
        }
        return !iters.empty();
    }
};
