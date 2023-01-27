#include<iostream>
#include<queue>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 struct CompareNodes{
     bool operator()(ListNode* p1, ListNode* p2){
         return p1->val >= p2->val;
     }
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes > pq;
        int n = lists.size();

        for(int i = 0; i < n; i++){
            if(lists[i] == nullptr){
                continue;
            }
            pq.push(lists[i]);
        }
        ListNode* tail = new ListNode(0);
        ListNode* ptr = tail;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            if(node -> next != nullptr){
                pq.push(node -> next);
            }

            tail -> next = node;
            tail = node;
        }

        return ptr->next;
    }
};

int main()
{
    
    return 0;
}