// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.


class Solution {
    void buildNode(RandomListNode* oldNode, RandomListNode* &newNode, unordered_map<RandomListNode*, RandomListNode*>& nodesMap) {
        if (nodesMap.find(oldNode) != nodesMap.end()) {
            newNode = nodesMap[oldNode];
        } else {
            newNode = new RandomListNode(oldNode->label);
            nodesMap.emplace(oldNode, newNode);
        }
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> nodesMap;
        RandomListNode* newHead = new RandomListNode(head->label);
        nodesMap.emplace(head, newHead);
        RandomListNode* runner = newHead;
        while (head) {
            if (head->next) buildNode(head->next, runner->next, nodesMap);
            if (head->random) buildNode(head->random, runner->random, nodesMap);
            head = head->next;
            runner = runner->next;
        }
        return newHead;
    }
};
