#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLE_SIZE 26

struct node{
	char data[100];
	struct node *next;
}*hashTable[TABLE_SIZE], *curr;

int hashFunction(char data[]){
	int hashKey = tolower(data[0]) - 'a';
	return hashKey % TABLE_SIZE;
}

void pushBack(int hashKey, char data[]){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	if(hashTable[hashKey] == NULL){
		hashTable[hashKey] = newNode;
	}else{
		curr = hashTable[hashKey];
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = newNode;
	}
}

void viewHashTable(){
	for(int i = 0; i < TABLE_SIZE; i++){
		if(hashTable[i] != NULL){
			printf("Hash Table Index [%d]: \n", i);
			curr = hashTable[i];
			while(curr != NULL){
				printf("%s-> ", curr->data);
				curr = curr->next;
			}
			printf("NULL\n");
		}
	}
}

void deleteData(char data[]){
	int hashKey = hashFunction(data);
	struct node *prev = NULL;
	curr = hashTable[hashKey];
	
	while(curr != NULL){
		if(strcasecmp(curr->data, data) == 0){
			if(prev == NULL){
				hashTable[hashKey] = curr->next;
			}else{
				prev->next = curr->next;
			}
			free(curr);
			printf("Data %s berhasil dihapus.\n", data);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("Data %s tidak ditemukan.\n", data);
}

void freeHashTable(){
	for(int i = 0; i < TABLE_SIZE; i++){
		curr = hashTable[i];
		while(curr != NULL){
			struct node *temp = curr;
			curr = curr->next;
			free(temp);
		}
		hashTable[i] = NULL;
	}
}

void menu(){
	int choice;
	char data[100];
	
	do{
		printf("Menu Hash Table\n");
		printf("1. Input Data\n");
		printf("2. Lihat Hash Table\n");
		printf("3. Hapus Data\n");
		printf("4. Keluar\n");
		printf("Pilihan: ");
		scanf("%d", &choice);
		getchar();
		
		switch(choice){
			case 1:
				printf("Input Data: ");
				fgets(data, sizeof(data), stdin);
				data[strcspn(data, "\n")] = '\0';
				pushBack(hashFunction(data), data);
				break;
			case 2:
				viewHashTable();
				break;
			case 3:
				printf("Masukkan data yang ingin dihapus: ");
				fgets(data, sizeof(data), stdin);
				data[strcspn(data, "\n")] = '\0';
				deleteData(data);
				break;
			case 4:
				printf("Keluar dari program\n");
				break;
			default:
				printf("Pilihan tidak valid!\n");
		}
	}while(choice != 4);
}

int main(){
	for(int i = 0; i < TABLE_SIZE; i++){
		hashTable[i] = NULL;
	}
	menu();
	freeHashTable();
	
	return 0;
}
