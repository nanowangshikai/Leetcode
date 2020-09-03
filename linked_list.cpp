#include <iostream>

using namespace std;

//自引用数据结构

struct ListNode { 
    int val;
    ListNode *next; //指向struct ListNode 类型数据的指针
    // ListNode(int x) : val(x),next(NULL) {}
};

// class Solution{
//     public:
//         ListNode* reverseList(ListNode* head){
//             cout << "this head value" << head <<endl;
//         }
// };


int main(){

    ListNode* head = nullptr;
    //创建一个链表
    head = new ListNode;
    head->val = 10;
    head->next = nullptr; //表示链表的结尾

    //在创建一个链表
    ListNode *secondPtr = new ListNode;
    secondPtr->val = 15;
    secondPtr->next = nullptr; //表示链表的结尾
    head->next = secondPtr;

    cout << "first item "<<head->val << endl;
    cout << "second item "<< head->next->val << endl;


}
