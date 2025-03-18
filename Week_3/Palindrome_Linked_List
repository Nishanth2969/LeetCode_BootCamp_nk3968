  class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        vector<int> temp;
        ListNode* curr = head;
        while (curr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int l = 0;
        int r = temp.size() - 1;
        while (l < r) {
            if (temp[l] != temp[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
        
    }
};
