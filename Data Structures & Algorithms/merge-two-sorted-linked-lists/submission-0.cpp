class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* i = list1;
        ListNode* j = list2;

        while (i != NULL && j != NULL) {
            if (i->val <= j->val) {
                tail->next = i;
                i = i->next;
            } else {
                tail->next = j;
                j = j->next;
            }
            tail = tail->next;
        }

        if (i != NULL) tail->next = i;
        if (j != NULL) tail->next = j;

        return dummy.next;
    }
};