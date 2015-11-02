// Median is the middle value in an ordered integer list. If the size of the list is even,
// there is no middle value. So the median is the mean of the two middle value.

// Examples:
// [2,3,4] , the median is 3

// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:

// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
// For example:

// add(1)
// add(2)
// findMedian() -> 1.5
// add(3)
// findMedian() -> 2

class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (max_heap.empty()) {
            max_heap.push(num);
        } else if (num > max_heap.top()) {
            min_heap.push(num);
            if (min_heap.size() - max_heap.size() > 0) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }

        } else {
            max_heap.push(num);
            if (max_heap.size() - min_heap.size() > 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
};
