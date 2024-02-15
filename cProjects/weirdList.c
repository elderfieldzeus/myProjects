#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
}*LIST;

void initialize(LIST *head) {
	*head = NULL;
}

void insertFront(LIST *head, int newNum) {
	LIST temp = malloc(sizeof(struct node));
	temp->next = *head;
	temp->num = newNum;
	*head = temp;
}

void insertLast(LIST *head, int newNum) {
	if(*head == NULL) {
		(*head) = malloc(sizeof(struct node));
		(*head)->next = NULL;
		(*head)->num = newNum;
	}
	else {
		LIST current = *head;
		for(current; current->next != NULL; current = current->next);
		current->next = malloc(sizeof(struct node));
		current = current->next;
		current->num = newNum;
		current->next = NULL;
	}
}

void delete(LIST *head, int findNum) {
	LIST prev = NULL, curr = *head;
	for(prev, curr; curr != NULL && curr->num != findNum; prev = curr, curr = curr->next);
	if(prev == NULL) {
		LIST temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else {
		prev->next = curr->next;
		free(curr);
	}
}

void display(LIST head) {
	LIST current = head;
	for(current; current != NULL; current = current->next) {
		printf("%d ", current->num);
	}
	printf("\n");	
}

int main() {
	LIST head;
	initialize(&head);
	insertFront(&head, 3);
	insertFront(&head, 5);
	insertLast(&head, 8);
	display(head);
	delete(&head, 5);
	insertFront(&head, 2);
	display(head);
	return 0;
}
