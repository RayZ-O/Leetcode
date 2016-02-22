// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

public class MergeKSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length, new ListNodeComparator());
        for (ListNode l : lists) {
            if (l != null) {
                pq.add(l);
            }
        }
        ListNode head = new ListNode(0);
        ListNode cur = head;
        while (!pq.isEmpty()) {
            ListNode l = pq.poll();
            cur.next = l;
            cur = cur.next;
            if (l.next != null) {
                pq.add(l.next);
            }
        }
        return head.next;
    }

    private class ListNodeComparator implements Comparator<ListNode> {
        @Override
        public int compare(ListNode l1, ListNode l2) {
            return Integer.compare(l1.val, l2.val);
        }
    }
}
