class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        if(l1==nullptr)
        return l2;
        if(l2==nullptr)
        return l1;
        int sum=l1->val+l2->val;
        if(sum>=10)
        {carry=sum/10;
        sum=sum%10;
        }
        ListNode * newlist=new ListNode(sum);
        l1=l1->next;
        l2=l2->next;
        ListNode* newlist1=newlist;
        while(l1!=nullptr && l2!=nullptr)
        {
             sum=carry+l1->val+l2->val;
             carry=sum/10;
             sum=sum%10;
             ListNode* newnode=new ListNode(sum);
             newlist1->next=newnode;
             newlist1=newlist1->next;
             l1=l1->next;
             l2=l2->next;
        }
        while(l1!=nullptr)
        {
            sum=carry+l1->val;
            carry=sum/10;
            sum=sum%10;
            ListNode* newnode =new ListNode(sum);
            newlist1->next=newnode;
            newlist1=newlist1->next;
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            sum=carry+l2->val;
            carry=sum/10;
            sum=sum%10;
            ListNode* newnode =new ListNode(sum);
            newlist1->next=newnode;
            newlist1=newlist1->next;
            l2=l2->next;
        }
        if(carry!=0)
        {
            ListNode* newnode = new ListNode(carry);
            newlist1->next=newnode;
            newlist1=newlist1->next;
        }

        return newlist;
    }
};