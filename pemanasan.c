#include <stdio.h>

int main(){
	int i;
	int num[3];
	int *ptr = num;
	
	for(i = 0; i < 3; i++){
		scanf("%d", ptr + i);
	}
	
	printf("Bilangan yang dimasukkan adalah: ");
	
	for(i = 0; i < 3; i++){
		printf("%d ", *(ptr + i));
	}
	
	return 0;
}
