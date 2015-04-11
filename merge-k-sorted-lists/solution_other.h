1:    ListNode *mergeKLists(vector<ListNode *> &lists) {  
2:      // Start typing your C/C++ solution below  
3:      // DO NOT write int main() function  
4:      ListNode * head = new ListNode(INT_MIN);  
5:      for(int i = 0; i < lists.size(); i++)  
6:      {  
7:        ListNode* p1 = head->next;  
8:        ListNode * p2 = lists[i];  
9:        ListNode* pre = head;  
10:        while(p1!= NULL && p2!= NULL)  
11:        {  
12:          if(p1->val >= p2->val)  
13:          {  
14:            pre->next = p2;   
15:            p2 = p2->next; pre = pre->next;  
16:            pre->next = p1;  
17:            continue;  
18:          }  
19:          pre = p1;  
20:          p1 = p1->next;;  
21:        }  
22:        if(p2 != NULL)  
23:        {  
24:          pre->next = p2;  
25:        }  
26:      }  
27:      ListNode* del = head;  
28:      head = head->next;  
29:      delete del;  
30:      return head;      
31:    } 
