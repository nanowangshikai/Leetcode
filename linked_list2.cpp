#include <iostream>

using namespace std;

// http://c.biancheng.net/view/1570.html Good website for Linked list

//自引用数据结构

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
        ListNode* reverseList(ListNode* head){
            // display(head);
            if(head->next == NULL){
                return 0;
            }

            ListNode* pre = NULL;
            ListNode* current = head; 
            while(current != NULL){
                ListNode* t = current->next;    //temporary store (next current value)
                current->next = pre;
                pre = current;
                current = t;

            }

            display(pre);




            return 0;
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
    s.reverseList(head);

}
