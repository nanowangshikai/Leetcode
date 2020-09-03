#include <iostream>

using namespace std;

struct ListNode { 
    int val;
    ListNode *next; //指向struct ListNode 类型数据的指针
    ListNode(int x) : val(x),next(NULL) {} //提供一个构造函数，方便初始化节点
};

ListNode display(ListNode* head){
    while (head!=nullptr)
    {
        cout << "value now is " <<head->val <<endl;
        head = head->next;
    }
    return 0;
};



class Solution{
    public:
        
        ListNode* reverseList(ListNode* head, ListNode* b){
        ListNode* curr=head;
        ListNode* pre=NULL;
        
        while(curr!= b ){
            ListNode* t = curr->next;
            curr->next = pre;
            pre = curr;
            curr = t;
        }

            
            return curr;
        }

        ListNode* reverseKGroup(ListNode* head, int k){
            
            ListNode* tail = head;
            ListNode* hd = head;
            
            for(int i=0; i<k; ++i){
                tail = tail->next;
            }

            ListNode* sub = reverseList(hd, tail);
            hd->next = reverseKGroup(tail, k);
            
            display(sub);

            return sub;
        }
};




int main(){

    ListNode* head = nullptr;
    //创建一个链表
    head = new ListNode(1);
    head->next = nullptr; //表示链表的结尾

    //在创建一个链表
    ListNode *secondPtr = new ListNode(2);
    secondPtr->next = nullptr; //表示链表的结尾
    head->next = secondPtr;

    ListNode *third = new ListNode(3);
    third->next = nullptr;
    secondPtr->next = third;

    ListNode *four = new ListNode(4);
    third->next = four;

    ListNode *five = new ListNode(5);
    four->next = five;

    Solution s;
    s.reverseKGroup(head, 2);

}
