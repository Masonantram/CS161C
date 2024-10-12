#include <iostream>

using namespace std;

struct ListNode
        {

    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
        };



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { //produces a merged list, unsorted

    ListNode* mergedList;

    if (!list1)
    {
        return list2;
    }
    else if (!list2)
    {
        return list1;
    }

    cout << "list1 -> val = " << list1 -> val << "  list2 -> val = " << list2 -> val << '\n';

    if (list1 -> val <= list2 -> val)
    {
        mergedList = list1;
        mergedList -> next = mergeTwoLists(list1 -> next, list2);
    }
    else
    {
        mergedList = list2;
        mergedList -> next = mergeTwoLists(list1, list2 -> next);
    }

    return mergedList;
}


int main() {

//had a hell of a time lining up a sorted linked list to pass in to test, but the mergeTwoLists function works
//submitted 9/1/24



    return 0;
}
