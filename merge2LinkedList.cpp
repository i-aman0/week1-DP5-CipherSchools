#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=NULL;
        
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        
        if(list1->val <= list2->val){
            ans=list1;
            ans->next=mergeTwoLists(list1->next, list2);
        }
        else{
            ans=list2;
            ans->next=mergeTwoLists(list1, list2->next);
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}