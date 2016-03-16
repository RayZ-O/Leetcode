// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the 
// following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise 
// return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its 
// capacity, it should invalidate the least recently used item before inserting a new item.

public class LRUCache {
    class ListNode {
        int key;
        int value;
        ListNode prev;
        ListNode next;
        ListNode(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    Map<Integer, ListNode> mp;

    ListNode head;
    ListNode tail;

    void addFirst(ListNode x) {
        head.next.prev = x;
        x.next = head.next;
        x.prev = head;
        head.next = x;
    }

    void remove(ListNode x) {
        x.prev.next = x.next;
        x.next.prev = x.prev;
    }

    ListNode removeLast() {
        if (tail.prev == head) {
            return null;
        }
        ListNode p = tail.prev;
        tail.prev = p.prev;
        tail.prev.next = tail;
        return p;
    }

    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        mp = new HashMap<>();
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        ListNode x = mp.get(key);
        if (x == null) {
            return -1;
        } else {
            remove(x);
            addFirst(x);
            return x.value;
        }
    }

    public void set(int key, int value) {
        ListNode x = mp.get(key);
        if (x != null) {
            x.value = value;
            remove(x);
            addFirst(x);
        } else {
            ListNode n = new ListNode(key, value);
            mp.put(key, n);
            addFirst(n);
            if (mp.size() > capacity) {
                ListNode y = removeLast();
                mp.remove(y.key);
            }
        }
    }
}
