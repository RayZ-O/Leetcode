// Implement an iterator to flatten a 2d vector.

// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// By calling next repeatedly until hasNext returns false, the order of elements
// returned by next should be: [1,2,3,4,5,6].

class Vector2D {
    vector<vector<int>>& vec2d_;;
    vector<vector<int>>::iterator it_row;
    vector<int>::iterator it_col;
    vector<int>::iterator getNext(vector<vector<int>>::iterator& it_row) {
        while (it_row != vec2d_.end() && it_row->size() == 0)
            it_row++;
        if (it_row != vec2d_.end())
            return it_row->begin();
        else
            return vec2d_.back().end();
    }
public:
    Vector2D(vector<vector<int>>& vec2d) : vec2d_(vec2d), it_row(nullptr), it_col(nullptr) {
        if (vec2d_.size() > 0) {
            it_row = vec2d_.begin();
            it_col = getNext(it_row);
        }
    }

    int next() {
        int val = *it_col;
        it_col++;
        if (it_col == it_row->end()) {
            it_col = getNext(++it_row);
        }
        return val;
    }

    bool hasNext() {
        return vec2d_.size() && it_col != vec2d_.back().end();
    }
};
