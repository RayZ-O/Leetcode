// Follow up for H-Index: What if the citations array is sorted in ascending order?
// Could you optimize your algorithm?

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int size = citations.size();
        int low = 0;
        while (low < size && citations[low] == 0) low++;
        int high = size - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] < size - mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return size - low;
    }
};

