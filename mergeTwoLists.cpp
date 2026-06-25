Example program
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

ListNode* createList(const vector<int>& nums)
{
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for (int num : nums)
    {
        ListNode* newNode = new ListNode(num);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            curr->next = newNode;
        }
        curr = newNode;
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* listOne, ListNode* listTwo)
{
    ListNode dummy(0);
    ListNode* p = &dummy;
    while(listOne and listTwo)
    {
        if(listOne->value > listTwo->value)
        {
            p->next = listTwo;
            p = listTwo;
            listTwo = listTwo->next;
        }
        else
        {
            p->next = listOne;
            p = listOne;
            listOne = listOne->next;
        }
    }
    
    listOne == nullptr ? p->next = listTwo : p->next = listOne;
    return dummy.next;
}

int main()
{
    vector<int> one = {1, 3, 5, 7, 9};
    vector<int> two = {2, 4, 6, 8, 10};
    ListNode* listOne = createList(one);
    ListNode* listTwo = createList(two);
    ListNode* res = mergeTwoLists(listOne, listTwo);
    while(res)
    {
        cout << res->value << endl;
        res = res->next;
    }
    return 0;
}
