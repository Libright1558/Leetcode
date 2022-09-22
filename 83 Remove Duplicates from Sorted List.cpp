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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* previous = head;
        ListNode* current = nullptr;
        ListNode* last = nullptr;
        if(previous != nullptr && previous -> next != nullptr) {
            current = previous -> next;
        }
        
        if(current != nullptr && current -> next != nullptr) {
            last = current -> next;
        }
        
        while(last != nullptr) {
            if(previous -> val == current -> val && current -> val == last -> val) {
                ListNode* tempcurrent = last -> next;
                ListNode* templast;
                if(tempcurrent != nullptr) {
                    templast = tempcurrent -> next;
                }
                else {
                    templast = nullptr;
                }
                delete current;
                delete last;
                current = tempcurrent;
                last = templast;
                previous -> next = current;   
            }
            else if(previous -> val == current -> val) {
                ListNode* tempcurrent = last;
                delete current;
                current = tempcurrent;
                last = last -> next;
                previous -> next = current;
            }
            else if(current -> val == last -> val) {
                ListNode* templast = last -> next;
                delete last;
                last = templast;
                current -> next = last;
            }
            else if(previous -> val == last -> val) {
                ListNode* templast = last -> next;
                delete last;
                last = templast;
                current -> next = last;
            }
            else {
                last = last -> next;
                current = current -> next;
                previous = previous -> next;
            }  
        }
        
        if(previous != nullptr && current != nullptr) {
            if(previous -> val == current -> val) {
                ListNode* tempcurrent = last;
                delete current;
                current = tempcurrent;
                if(last != nullptr) {
                    last = last -> next;
                }
                previous -> next = current; 
            }
        }
        
        return head;
    }
};