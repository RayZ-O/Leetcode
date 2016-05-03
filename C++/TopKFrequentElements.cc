// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int n : nums) {
            freq_map[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto p : freq_map) {
            if (pq.size() < k)  {
                pq.emplace(p.second, p.first);
            } else if (p.second > pq.top().first) {
                pq.pop();
                pq.emplace(p.second, p.first);
            }
        }
        vector<int> out;
        while (!pq.empty()) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        return vector<int>(out.crbegin(), out.crend());
    }
};
