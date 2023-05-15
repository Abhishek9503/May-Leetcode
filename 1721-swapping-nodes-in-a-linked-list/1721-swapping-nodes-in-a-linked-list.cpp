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
    int findLength(ListNode* head)
    {
        int l=0;
        while(head!=NULL)
        {
            head=head->next;
            l++;
        }
        return l;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        // kth from start
        // k th node from End =(Length-K+1)th node from start
        
        int L=findLength(head);
        
        int size =k;
        
        ListNode * Node1=head;
        while(size>1)
        {
            Node1=Node1->next;
            size--;
        }
        
        int size2 = L -k+1;
        
        ListNode * Node2=head;
            while(size2>1)
        {
            Node2=Node2->next;
            size2--;
        }
        
        swap(Node1->val,Node2->val);
        
        return head;
    }
};