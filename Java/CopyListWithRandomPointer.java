// A linked list is given such that each node contains an additional random pointer which could
// point to any node in the list or null.

// Return a deep copy of the list.

public class CopyListWithRandomPointer {
    public RandomListNode copyRandomList(RandomListNode head) {
    	Map<RandomListNode, RandomListNode> mp= new HashMap<>();
    	RandomListNode dummy = new RandomListNode(0);
    	RandomListNode cur = dummy;
    	while (head != null) {
    	    RandomListNode node = mp.get(head);
    	    if (node != null) {
    		cur.next = node;
    	    } else {
    		cur.next = new RandomListNode(head.label);
    		mp.put(head, cur.next);
    	    }
    	    cur = cur.next;
    	    if (head.random != null) {
        		node = mp.get(head.random);
        		if (node != null) {
        		    cur.random = node;
        		} else {
        		    cur.random = new RandomListNode(head.random.label);
        		    mp.put(head.random, cur.random);
        		}
    	    }

    	    head = head.next;
    	}
    	return dummy.next;
    }
}
