/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) {
            return nullptr;
        }

        int l = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            l++;
        }

        int k = l - n;

        if(k == 0) {
            return head->next;
        }

        temp = head;

        for(int i = 0; i < (k - 1); i++) {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;

        return head;
    }
};

// above algorithm simply runs through the list and counts the number of elements
// then subtracts n from the total to find the index of the element to be removed.
// One edge case here is that the element to be removed is the first element, in which
// we simply return head->next

// Another interesting way to solve this problem is using fast and slow pointers.
// We run 2 pointers, one fast one slow. First we move the fast pointer n distance away
// from the slow pointer, so that by the time the fast pointer reaches the end of the
// list, the slow pointer is at the node before the node which is to be removed.