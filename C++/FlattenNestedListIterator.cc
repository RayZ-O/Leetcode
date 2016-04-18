// Given a nested list of integers, implement an iterator to flatten it.

// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Example 1:
// Given the list [[1,1],2,[1,1]],

// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be:
// [1,1,2,1,1].

// Example 2:
// Given the list [1,[4,[6]]],

// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be:
// [1,4,6].

class NestedIterator {
    using nii = vector<NestedInteger>::iterator;
    stack<pair<nii, nii>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty()) {
            st.emplace(nestedList.begin(), nestedList.end());
        }
    }

    int next() {
        return (st.top().first++)->getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) {
                st.pop();
                continue;
            }

            if (st.top().first->isInteger()) {
                return true;
            }
            auto& nl = st.top().first->getList();
            ++st.top().first;
            st.emplace(nl.begin(), nl.end());
        }
        return false;
    }
};
