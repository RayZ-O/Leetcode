// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

public class TopKFrequentElements {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int n : nums) {
            if (mp.containsKey(n)) {
                mp.put(n, mp.get(n) + 1);
            } else {
                mp.put(n, 1);
            }
        }

        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((e1, e2) -> e1.getValue() - e2.getValue());
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (pq.size() < k) {
                pq.add(entry);
            } else if (pq.size() >= k && pq.peek().getValue() < entry.getValue()) {
                pq.poll();
                pq.add(entry);
            }
        }

        List<Integer> out = new ArrayList<>();
        while (!pq.isEmpty()) {
            out.add(pq.poll().getKey());
        }
        return out;
    }
}
