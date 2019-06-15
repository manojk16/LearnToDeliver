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
#include <climits>
# define MAX_SIZE 10
using namespace std;

struct List_Stack{
	int data;
	struct List_Stack* next;
};
List_Stack* top; 

void push(int value){
	// create a new node and allocated the memory
	List_Stack* Node=(List_Stack*)malloc(sizeof(List_Stack));
	// Check for the Overflow
	if(!Node){
		cout<<"Heap Overflow\n";

	}
	// Assign the data in to data part of the Node
	
	Node->data=value;
	// put top pointer reference in to Node->next
	Node->next=top;
	// make Node as Top of the stack 
	top=Node;

}

bool isEmpty(){
	return(top==NULL);	
}
int pop(){
	List_Stack* temp;
	int value;
	if(isEmpty()){
		cout<<"UnderFlow\n";
	}else{
	temp=top;
	top=top->next;
	value=temp->data;
	free(temp);
	}
	return value;
}
int peek(){
	if(!isEmpty()){
		return top->data;
	}else{
		return (EXIT_FAILURE);
	}
}

void display(){
	List_Stack* temp;
	if(top==NULL){
		cout<<"Stack is Under Flow, ";
		exit(1);
	}else{
		temp=top;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
	}
	cout<<"\n";
}

int main(){
	//List_Stack* S=NULL;
	push(11); 
    push(22); 
    push(33); 
    push(44); 
  	cout<<"\n";
    // display stack elements 
    display(); 
  	cout<<"\n";
    // print top elementof stack 
    cout<<"Top element is:"<<peek()<<endl; 
  	cout<<"\n";
    // delete top elements of stack 
    cout<<"Popped out Element is::" <<pop()<<endl; 
    cout<<"\n";
	cout<<"Popped out Element is::" <<pop()<<endl; 
  	cout<<"\n";
    // display stack elements 
    cout <<"Remaining elements are ::\n";

    display(); 
  
    // print top elementof stack 
    cout<<"Top element is:"<<peek()<<endl; 
    return 0;
}