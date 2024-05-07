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
#define ll long long
class Solution {
public:
    ListNode *resHead=nullptr , *cpy=nullptr;
    ListNode* insAtHead(ll a , int i){
        ListNode* nn = new ListNode(a);
        if(i==0){
            resHead = nn;
            cpy = nn;
        }
        else{
            nn->next = cpy;
            cpy = nn;
        }
        return cpy;
    }
    ListNode* doubleIt(ListNode* head) {
        if(head->next==nullptr){
            if(head->val == 0) return head;
        }
        ListNode* temp = head;
        ListNode *prev = nullptr, *nextOne = nullptr;
        while (temp != nullptr) {
            nextOne = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextOne;
        }
        temp = prev;
        ll sum=0 , carry=0 , i=0;
        ListNode* res;
        while(temp != nullptr){
            sum = 2*(temp->val);
            res = insAtHead((sum%10)+carry , i);
            i++;
            if(sum>=10) carry = 1;
            else carry=0;
            temp = temp->next;
        }
        if(carry) res = insAtHead(carry , i);
        return res;
    }
};