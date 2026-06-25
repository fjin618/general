// Example program
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
     ListNode* prev = nullptr;
     ListNode* curr = head;
     
     while(nullptr != curr)
     {
         ListNode* temp = curr->next;
         curr->next = prev;
         prev = curr;
         curr = temp;
     }
     
     return prev;
}

ListNode* createList();

int main()
{
    ListNode* head = nullptr;
    if (nullptr == reverseList(head))
    {
        cout << "Expect this log print because of head is nullptr" << endl;
    }
    
    cout << "-------------------------------------------------" << endl;
    
    head = new ListNode(0);
    if (head == reverseList(head))
    {
        cout << "Only one node in the list!!" << endl;
    }
    
    cout << "-------------------------------------------------" << endl;
    
    int n = 5;
    ListNode* curr = head;
    while(n)
    {
        cout << "Create a node with value n: " << n << endl;
        curr->next = new ListNode(n);
        curr = curr->next;
        n--;
    }
    
    cout << "-------------------------------------------------" << endl;
    
    curr = head;
    while(nullptr != curr)
    {
        cout << "Value of current node: " << curr->value << endl;
        curr = curr->next;
    }
    ListNode* res = reverseList(head);
    cout << "-------------------------------------------------" << endl;
    curr = res;
    while(nullptr != curr)
    {
        cout << "Value of current node after reversed: " << curr->value << endl;
        curr = curr->next;
    }
    
    return 0;
}
