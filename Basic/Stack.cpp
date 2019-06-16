/*Stack : 
Operation : Direct: 
1: Push 
2 Pop
Indirect: 
1: int top()
2. bool isEmpty()
3. bool isFull()
4. int size()
Application: 
1. Infix to postfix
2. postfix evulation
3. Balancing of symbols
4. Implementing function calls
5. To maintain visited  history
6. Undo Operation
2*/


/* *************************Linked List Implementation******************************* */

#include <iostream>
#include <stdbool.h> 
# define MAX_SIZE 10
using namespace std;

struct List_Stack{
	int top;
	int capacity;
	int *array;

};

List_Stack *create_stack(){
	List_Stack* S=(List_Stack*)malloc(sizeof(List_Stack));
	if(!S){
		cout<<"Error in memory Allocation\n";
		return NULL;
	}
	S->top=-1;
	S->capacity=MAX_SIZE;
	S->array=(int *)malloc(S->capacity * sizeof(int));
	if(!S->array){
		return NULL;
	}
	return S;
}


bool isEmpty(List_Stack* S){
	return(S->top==-1); 
}

bool isFull{List_Stack* S}{
	return (S->top==S->capacity-1);
}
void push(List_Stack* S, int data){
	if(!isFull(S)){
		S->top=S->top+1;
		S->array[S->top]=data;
	}else{
		cout<<"OverFlow\n";
	}
}


int pop(List_Stack* S){
	if(!isEmpty(S)){
		int data=S->array[S->top]
		S->top=S->top-1;
		return data;
	}else{
		cout<<"UnderFlow\n"
		return INT_MIN;
	}
}


void delete_Link_stack(List_Stack* S){
	if(S){
		if(S->array){
			free(S->array);
		}
		free(S);
	}
}


int main(){
	List_Stack* S=NULL;
	cout<<isEmpty(S)<<endl;
	push(S,20);
	push(S,10);
	push(S,5);
	cout<<"Popped Out Element is : "<<pop()<<endl;
	cout<<"Popped Out Element is : "<<pop()<<endl;
	cout<<isFull(S)<<endl;
}