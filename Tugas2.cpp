#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct{
	char items[MAX];
	int top;
}Stack;

void inStack(Stack *s){
	s->top == -1;
}

int isEmpty(Stack *s){
	return s->top == -1;
}

int isFull(Stack *s){
	return s->top == MAX - 1;
}

void push(Stack *s, char c){
	if(!isFull(s)){
		s->items[++(s->top)] = c;
	}
}

char pop(Stack *s){
	if(!isEmpty(s)){
		return s->items[(s->top)--];
	}
	return -1;
}

char peek(Stack *s){
	if(!isEmpty(s)){
		return s->items[s->top];
	}
	return -1;
}

int precedence(char op){
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/') return 2;
	if(op == '^') return 3;
	return 0;
}

void infixToPostfix(char *infix, char *postfix){
	Stack s;
	inStack(&s);
	int j = 0;
	
	for(int i = 0; infix[i] != '\0'; i++){
		char ch = infix[i];
		if(isalnum(ch)){
			postfix[j++] = ch;
		}else if(ch == '('){
			push(&s, ch);
		}else if(ch == ')'){
			while(!isEmpty(&s) && peek(&s) != '('){
				postfix[j++] = pop(&s);
			}
			pop(&s);
		}else{
			while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)){
				postfix[j++] = pop(&s);
			}
			push(&s, ch);
		}
	}
	while(!isEmpty(&s)){
		postfix[j++] = pop(&s);
	}
	postfix[j] = '\0';
}

int main(){
	char infix[MAX];
	char postfix[MAX];
	
	printf("Masukkan ekspresi infix: ");
	scanf("%s", infix);
	
	infixToPostfix(infix, postfix);
	
	printf("Ekspresi dalam postfix: %s\n", postfix);
	
	return 0;
}
