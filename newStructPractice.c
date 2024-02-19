#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};

int count = 0;

struct node* insertLast(struct node*, int);
struct node* insertFirst(struct node*, int);
struct node* insertAt(struct node*, int, int);
struct node* deleteFirst(struct node*);
struct node* deleteLast(struct node*);
struct node* deleteAt(struct node*, int);
struct node* deleteAll(struct node*);

void printThis(struct node*, int);
void printAll(struct node*);

int main(){
	int item, input, pos = 0;
	struct node* head = NULL;
	
	do{
		printf("==========================================\n");
		printf("\n[Number of datas available: %d]\n\n", count);
		printf("[1]Insert First [2]Insert Rear [3]Insert at [4]Delete First [5]Delete Last \n[6]Delete At [7]Delete All [8]Print specific position [9]Print All data [0] Exit\n\nSelect mode: ");
		scanf("%d", &input);
		printf("\n");
		switch(input){
			case 1 : 
				printf("You have selected insert at front.\n");	
				printf("Enter a number to insert first: ");
				scanf("%d", &item);		
				head = insertFirst(head, item);
				break;
				
			case 2 : 
				printf("You have selected insert at rear.\n");	
				printf("Enter a number to insert last: ");
				scanf("%d", &item);		
				head = insertLast(head, item);
				break;
				
			case 3 :
				printf("You have selected insert at specific location.\n");	
				printf("Enter a number to insert: ");
				scanf("%d", &item);		
				printf("At what numerical position would you like it to insert: ");
				scanf("%d", &pos);
				if(pos > count + 1){
					printf("Sorry but you can't insert at that position.");
					break;
				}else{
					head = insertAt(head, item, pos);
				}
				
				break;
				
			case 4 :
				printf("Deleting first data.\n");
				
				if(head == NULL){
					printAll(head);
					break;
				}else{
					head = deleteFirst(head);
					printAll(head);
				}
				
				break;
				
			case 5 :
				printf("Deleting last data.\n");
				
				if(head == NULL){
					printAll(head);
					break;
				}else{
					head = deleteLast(head);
					printAll(head);
				}
				
				break;
			
			case 6 :
				printf("Deleting specific node.");
				printf("Please refer to counter.\nWhat number would you like to remove: ");
				scanf("%d", &pos);
				if(head == NULL){
					printAll(head);
					break;
				}else{				
					head = deleteAt(head, pos);
				}
				
				printAll(head);
				break;
				
			case 7 : 
				if(head == NULL){
					printAll(head);
					break;
				}else{
					printf("Deleting all nodes.");
					head = deleteAll(head);
					printAll(head);
				}
				break;

			case 8 : 
				if(head == NULL){
					printAll(head);
					break;
				}else{
					printf("What position would you like to get: ");
					scanf("%d", &pos);
					printThis(head, pos);
				}
				
				break;
				
			case 9 :			
				printAll(head);
				
				break;
				
			case 0 :
				printf("Goodbye!");
				exit(1);
				
		}
		printf("\n\n==========================================");
	}while(exit != 1);
	
}

struct node* insertAt(struct node* head, int item, int pos){
	struct node* temp = NULL;
	temp = malloc(sizeof(struct node));
	
	int i = 0;
	
	struct node* ptr = NULL;
	ptr = head;
	
	temp->data = item;
	temp->link = NULL;
	
	if(head == NULL){
		head = temp;
	}else if(pos == 1){
		temp->link = head;
		head = temp;
	}else{	
		while(i + 1 != pos - 1){	//traverses to the node before the last node (last I mean the position)
			ptr = ptr->link;
			i++;
		}
		
		temp->link = ptr->link;	
		ptr->link = temp;
	}

			
	count++;
	
	return head;
	
}

struct node* insertLast(struct node* head, int item){
	struct node* temp = NULL;
	temp = malloc(sizeof(struct node));
	
	struct node* ptr = NULL;
	ptr = head;
	
	temp->data = item;
	temp->link = NULL;
	
	if(head == NULL){
		head = temp;
	}else{
		while(ptr->link != NULL){
			ptr = ptr->link;
		}
		
		ptr->link = temp;
	}
	
	count++;
	
	return head;
}

struct node* insertFirst(struct node* head, int item){
	struct node* temp = NULL;
	temp = malloc(sizeof(struct node));
	
	temp->data = item;
	temp->link = head;
	head = temp;
	
	count++;

	return head;	
}

struct node* deleteFirst(struct node* head){
	
	head = head->link;
	
	count--;
	
	return head;
}

struct node* deleteLast(struct node* head){
	struct node* ptr = NULL;
	ptr = head;
	
	int i = 0;
	
	if(head->link == NULL){
		head = NULL;
	}else{
		while(i + 1 < count - 1){	//traverses to the second to the last node.
			ptr = ptr->link;		
			i++;	
		}
		
		ptr->link = NULL;
	}
	
	count--;
	
	return head;
}

struct node* deleteAt(struct node* head, int pos){
	struct node* ptr = NULL;
	ptr = head;
	
	int i = 0;
	
	if(pos == 1){
		head = head->link;
	}else{
		while(i + 1 != pos - 1){
			ptr = ptr->link;
			i++;
		}
		ptr->link = ptr->link->link;
		
	}

	count--;
	
	return head;
}

struct node* deleteAll(struct node* head){
	
	head = NULL;
	
	count = 0;
	
	return head;
}

void printThis(struct node* head, int pos){
	int i = 0;
	struct node* ptr = NULL;
	ptr = head;

	while(i != pos - 1){
		ptr = ptr->link;
		i++;
	}
	
	printf("Requested data: [%d]", ptr->data);
}

void printAll(struct node* head){
	
	struct node* ptr = NULL;
	ptr = head;

	printf("\n-------------------------------------------------\n");
	printf("List of data available: "); 
	
	if(ptr == NULL){
		printf("List is empty.");
	}else{
		while(ptr != NULL){
			printf("[%d] ", ptr->data);
			ptr = ptr->link;
		}
	}
	
	printf("\n-------------------------------------------------\n");
}
