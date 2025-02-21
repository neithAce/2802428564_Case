#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int x;
	tnode *prev;
	tnode *next;
}*head, *tail;

void push_front(int value)
{
	struct tnode *node = (tnode*) malloc(sizeof(tnode));
	node->x = value;
	node->prev = NULL;
	node->next = head;
	
	if(head==NULL)
	{
		head = tail = node;
	}
	else
	{
		head->prev = node;
		head = node;
	}
}

void push_back(int value)
{
	struct tnode *node = (tnode*) malloc(sizeof(tnode));
	node->x = value;
	node->next = NULL;
	node->prev = tail;
	
	if(head==NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}

void push_mid(int value, int searchKey)
{
	if(head == NULL){
		printf("List masih kosong, menambahkan di depan.\n");
		push_front(value);
		return;
	}
	
	struct tnode *curr = head;
	while(curr != NULL){
		if(curr->x == searchKey){
		    struct tnode *node = (tnode*) malloc(sizeof(tnode));
	        node->x = value;
	        node->prev = curr;
	        node->next = curr->next;
	       
	        if(curr->next != NULL){
	       	    curr->next->prev = node;
		    }else{
		    	tail = node;
		    }
		    curr->next = node;
		    return;
	    }
	    curr = curr->next;
    }
    printf("Data %d tidak ditemukan\n", searchKey);
}

void delete_front()
{
	if(head==NULL)
	{
		printf("There is no data\n");
		return;
	}
	struct tnode *del = head;
	head = head->next;
	
	if(head != NULL){
		head->prev = NULL;
	}else{
		tail = NULL;
	}
	free(del);
}

void delete_back(){
	if(head == NULL){
		printf("List kosong\n");
		return;
	}
	struct tnode *del = tail;
	tail = tail->prev;
	
	if(tail != NULL){
		tail->next = NULL;
	}else{
		head = NULL;
	}
	free(del);
}

void delete_mid(int searchKey){
	if(head == NULL){
		printf("List kosong\n");
		return;
	}
	struct tnode *curr = head;
	while(curr != NULL){
		if(curr->x == searchKey){
			if(curr == head){
				delete_front();
			}else if(curr == tail){
				delete_back();
			}else{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
			}
			return;
		}
		curr = curr->next;
	}
	printf("Data %d tidak ditemukan\n", searchKey);
}

void printList()
{
	if (head==NULL)
	{
		printf("List kosong\n");
		return;
	}
	
	struct tnode *curr = head;
	
	while(curr!=NULL)
	{
		printf("%d ", curr->x);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	printf("Linked list\n");
	push_back(13);
	push_back(1);
	push_back(3);
	printList();
	
	printf("Delete dari depan:\n");
	delete_front();
	printList();
	
	printf("Menambahkan ke belakang:\n");
	push_back(99);
	printList();
	
	printf("Delete dari belakang:\n");
	delete_back();
	printList();
	
	printf("Menambahkan di tengah setelah angka 1:\n");
	push_mid(50, 1);
	printList();
	
	printf("Menghapus angka 50 dari tengah:\n");
	delete_mid(50);
	printList();
	
	return 0;
}

