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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode*cur = head;
        int count = 1;
        
        while(count < k)
        {
            cur = cur->next;
            count++;
        }
        cout << cur->val << " ";
        ListNode *n1 = cur;
        ListNode *temp = head;
        ListNode*prev = NULL;
        while(cur->next != NULL)
        {
            cur = cur->next;
            prev = temp;
            temp = temp->next;
        }
        cout << temp->val << " \n";
        swap(temp->val, n1->val);
        return head;
        
    }
};