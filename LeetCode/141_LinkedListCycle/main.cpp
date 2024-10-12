#include <iostream>
#include <vector>

 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;

     ListNode(int x) : val(x), next(nullptr) {}
 };

bool hasCycle(ListNode *head)
{
    bool valid = false;
    ListNode* fast = head;

    while (fast && fast -> next)
    {
        head = head -> next;
        fast = fast -> next -> next;
        if (fast == head)
        {
            valid = true;
            return valid;
        }
    }

    return valid;
}

  /*  bool hasCycle(ListNode *head) {

        bool valid = false;
        vector<int> list;
        ListNode *temp = head;

        while (temp && list.size() < 10000) {
            list.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        for (int i = list.size() - 2; i >= 0; i--) {
            if (temp->val == list[i]) {
                valid = true;
                return valid;
            }
        }
        return valid;
    }*/


int main() {

    ListNode* head = new ListNode(1);

    for (int i = 1; i < 6; i++)
    {
        ListNode* newNode = new ListNode(i);

       if (!head) {
            head = newNode;
        }
        else {
           ListNode *temp = head;
           while (temp->next) {
               temp = temp->next;
           }
           temp->next = newNode;
       }
    }

/*    while (head)
    {
        cout << head -> val << '\n';
        head = head -> next;
    }*/

    bool valid = hasCycle(head);

    cout << "valid = " << valid;

    return 0;
}
