#include"add_two_numbers.h"
#include<cstdlib>

class Solution {
public:
    /**
     * failed because convert to uint64_t couldn't handle large number, e.g. 10^61
     */
    ListNode* addTwoNumbers_failed(ListNode* l1, ListNode* l2) {
        uint64_t i = UINT64_MAX;
        uint64_t i1=0, i2=0, iRes=0; // store number presenting in Lists
        ListNode* tmp = NULL; // interate for list
        int64_t cnt = 0; // order number for calculate i1 and i2
        ListNode* pRes = NULL;

        tmp = l1; cnt = 1;
        while (tmp != NULL){
            i1 += tmp->val*cnt;
            cnt *= 10;
            tmp = tmp->next;
        }

        tmp = l2; cnt = 1;
        while (tmp != NULL){
            i2 += tmp->val*cnt;
            cnt *= 10;
            tmp = tmp->next;
        }

        iRes = i1+i2;
        if(iRes == 0){
            return new ListNode(0);
        }
        while (iRes != 0){
            if (tmp==NULL){ // begin case
                tmp = new ListNode(iRes%10);
                pRes = tmp;
            }else{
                ListNode* tmp2 = new ListNode(iRes%10);
                tmp->next = tmp2;
                tmp = tmp2;
            }
            iRes /= 10;
        }

        return pRes;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {}
};

int main(){
    // ListNode* l1 = new ListNode(2);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);
    //
    // ListNode* l2 = new ListNode(5);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);
    //
    // int i1[] = {9};
    // int i2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9};


    int i1[] = {2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9};
    int i2[] = {5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9};
    int cnt1 = (int)sizeof(i1)/sizeof(int);
    int cnt2 = (int)sizeof(i2)/sizeof(int);
    ListNode* l1=new ListNode(i1[0]), *l2 = new ListNode(i2[0]);

    if (cnt1 > 1){
        ListNode* tmp = l1;
        for (int i=1; i<cnt1; i++){
            ListNode* tmp2 = new ListNode(i1[i]);
            tmp->next = tmp2;
            tmp = tmp2;
        }
    }

    if (cnt2 > 1){
        ListNode* tmp = l2;
        for (int i=1; i<cnt2; i++){
            ListNode* tmp2 = new ListNode(i2[i]);
            tmp->next = tmp2;
            tmp = tmp2;
        }
    }


    Solution* solu1 = new Solution();
    solu1->addTwoNumbers(l1, l2);

    return 0;
}
