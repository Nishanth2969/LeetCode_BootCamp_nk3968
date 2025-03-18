class Solution {
public:
    void reorderList(ListNode* head) {

        
        if (!head || !head->next || !head->next->next) return;

            ListNode *s = head, *f = head;
            while (f->next && f->next->next) {
                s = s->next;
                f = f->next->next;
            }

            ListNode *h2 = s->next;
            s->next = nullptr;

            ListNode *prev = nullptr, *curr = h2, *nxt;
            while (curr) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            h2 = prev;

            ListNode *h1 = head;
            while (h2) {
                nxt = h1->next;
                h1->next = h2;
                h2 = h2->next;
                h1->next->next = nxt;
                h1 = nxt;
            }
    }
};
