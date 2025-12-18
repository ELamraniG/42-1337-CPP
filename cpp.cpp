
#include <iostream>
    struct ListNode {
      int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

#include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int reminder = 0;
        struct ListNode *lista  = new struct ListNode ();
        struct ListNode *l3  = lista;
		int res;
        while(l1 != NULL)
        {
            if (l2 == NULL)
            {
                while (l1 != NULL)
                {
					if (l1->val + reminder >= 10)
					{
						res = l3->val = l1->val + reminder;
						l3->val = res % 10;
						reminder = res / 10;
						
					}
					else
					{	
						l3->val = l1->val + reminder;
						reminder = 0;
					}
					l1 = l1->next;
					if (l1 != NULL || reminder != 0) {
						l3->next = new struct ListNode ();
						l3 = l3->next;
						l3->next = NULL;
					}
                }
            }
			else if (l1->val +l2->val + reminder >= 10)
			{
				res = (l2->val + l1->val + reminder);
				l3->val = res % 10;
				reminder = res / 10;
				l1 = l1->next;
				l2 = l2->next;
				if (l1 != NULL || l2 != NULL || reminder != 0) {
					l3->next = new struct ListNode ();
					l3 = l3->next;
				}
			}
			else if (l1->val +l2->val + reminder < 10)
			{
				res = (l2->val + l1->val + reminder );
				reminder = 0;
				l3->val = res;
				l1 = l1->next;
				l2 = l2->next;
				if (l1 != NULL || l2 != NULL || reminder != 0) {
					l3->next = new struct ListNode ();
					l3 = l3->next;
				}
			}
        }
		while(l2 != NULL)
		{
        printf("here\n");
			if (l2->val + reminder >= 10)
					{
						res = l3->val = l2->val + reminder;
						l3->val = res % 10;
						reminder = res / 10;
						
					}
					else
					{	
						l3->val = l2->val + reminder;
						reminder = 0;
					}
					l2 = l2->next;
					if (l2 != NULL || reminder != 0) {
						l3->next = new struct ListNode ();
						l3 = l3->next;
					}
		}
		while (reminder != 0)
		{
			l3->val = reminder % 10;
			reminder = reminder/ 10;
			if (reminder != 0) {
				l3->next = new struct ListNode ();
				l3 = l3->next;
			}
		}
        return lista;
    }
};