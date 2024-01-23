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
    int gcd(int a , int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cpy = head;
        while(cpy->next!=NULL){
            int GcdOf2=0;
            int n = cpy->val;
            int m = cpy->next->val;
            if(n<m){
                GcdOf2 = gcd(n,m);
            }
            else{
                GcdOf2 = gcd(m,n);
            }
            ListNode* ele = new ListNode(GcdOf2);
            ele->next = cpy->next;
            cpy->next = ele;
            cpy=ele->next;
        }
        return head;
    }
};