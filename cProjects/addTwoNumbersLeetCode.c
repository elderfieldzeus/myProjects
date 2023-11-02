//MY ANSWER
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sumNode = malloc(sizeof(struct ListNode));
    long long num1 = 0, num2 = 0, sum = 0;
    struct ListNode* currentSum = sumNode;
    int addTens = 0, end = -1;
    struct ListNode *current1 = l1, *current2 = l2;
    for(current1, current2; current1 != NULL & current2 != NULL; current1 = current1->next, current2 = current2->next){
        currentSum->val = addTens ? current1->val + current2->val + 1 : current1->val + current2->val;
        if (currentSum->val >= 10){
            addTens = 1;
            currentSum->val -= 10;
        }
        else{
            addTens = 0;
        }
        if(current1->next == NULL && current2->next == NULL)
            end = 0;
        else if(current1->next == NULL){
            end = 1;
        }
        else if(current2 ->next == NULL){
            end = 2;
        }

        currentSum->next = malloc(sizeof(struct ListNode));

        if(!(end == 0 && addTens == 0)){
            currentSum = currentSum->next;
        }
    }

    switch(end){
        case 1:
            for(current2; current2 != NULL; current2 = current2->next){
                currentSum->val = addTens ? current2->val + 1 : current2->val;
                if (currentSum->val >= 10){
                    addTens = 1;
                    currentSum->val -= 10;
                }
                else{
                    addTens = 0;
                }

                currentSum->next = malloc(sizeof(struct ListNode));

                if(!(current2->next == NULL && addTens == 0)){
                    currentSum = currentSum->next;
                }
                
            }
            break;
        case 2:
            for(current1; current1 != NULL; current1 = current1->next){
                currentSum->val = addTens ? current1->val + 1 : current1->val;
                if (currentSum->val >= 10){
                    addTens = 1;
                    currentSum->val -= 10;
                }
                else{
                    addTens = 0;
                }
                currentSum->next = malloc(sizeof(struct ListNode));

                if(!(current1->next == NULL && addTens == 0)){
                    currentSum = currentSum->next;
                }
            }
            break;
    }
    
    if(addTens){
        currentSum->val = 1;
        currentSum->next = malloc(sizeof(struct ListNode));
        currentSum->next = NULL;
    }else{
        currentSum->next = NULL;
    }

    return sumNode;
}