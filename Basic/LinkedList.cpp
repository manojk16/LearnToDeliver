#include <iostream>

//#include <stdio.h>
// for malloc
#include <stdlib.h>
//for bool
//#include <stdbool.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};

void addfirst(node** head_ref, int value){
	node* first=*head_ref;
	node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
	}else{
		new_node->next=*head_ref;
		*head_ref=new_node;
	}

}
void append(node** head_ref, int value){

	node* last=*head_ref;
	node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
	
	}
	else{
	while(last->next!=NULL){
		last=last->next;
	 }
	 last->next=new_node;
	}
	
	
}
void add_at_pos(node** head_ref, int value, int k){
	// This single function covers the add at beg and add at last also
	int i=1;
	struct node* temp=*head_ref;
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next=NULL;

	if(k==0){
		if(*head_ref==NULL){
			*head_ref=new_node;
		}
		else{
			new_node->next=*head_ref;
			*head_ref=new_node;
		}
	}else{
		if(*head_ref==NULL){
			*head_ref=new_node;
		}else{
			while(k!=i){
				i++;
				temp=temp->next;
			}
			new_node->next=temp->next;
			temp->next=new_node;
			

		}
	}
}

void delete_from_beg(node** head_ref){
	node* temp=*head_ref;
	if(temp==NULL){
		cout<<"Nothing to Delte\n";
	}else if(temp->next==NULL){
		cout<<"Only One node, Let's delete this\n";
		(*head_ref)=NULL;
		free (temp);	
	}else{

		(*head_ref)=(*head_ref)->next;
		free (temp);
		
	}
}

void deleteList(node** head_ref){
	node* current=*head_ref;
	node* prev=*head_ref;
	if(*head_ref==NULL){
		cout<<"Linked List is already Empty\n";
	}
	else{
		while(current!=NULL){
			prev=current->next;
			//current=NULL;
			free (current);
			current=prev;	
		}

	}
	*head_ref=NULL;  // Imp here else *head_ref will point to some garbage value and al lother nodes will remain linked and filled with some garbage value 

}

void display(struct node* Node){
	if(Node==NULL){
		cout<<"Nothing to display\n";
		}else{
	while(Node!=NULL){
		cout<<"  "<<Node->data;
		
		Node=Node->next;
		}
	}
	cout<<"\n";
}
int main(){

	cout<<"Create A linked list by entering the data at end\n";
	node* head_ref=NULL;
	
	display(head_ref);
	delete_from_beg(&head_ref);
    display(head_ref);
	//delete_from_beg(&head_ref);
	append(&head_ref,5);
	display(head_ref);

	delete_from_beg(&head_ref);
	display(head_ref);
	append(&head_ref,6);
	display(head_ref);
	append(&head_ref,7);

	display(head_ref);
	cout<<"Now at begning\n";
	addfirst(&head_ref,3);
	addfirst(&head_ref,2);
	addfirst(&head_ref,1);
	display(head_ref);
	cout<<"Now at Pos\n";
	add_at_pos(&head_ref,10,5);
	display(head_ref);
	cout<<"Let's delete a node from begining\n";
	delete_from_beg(&head_ref);
	display(head_ref);
	deleteList(&head_ref);
	display(head_ref);


	return 0;
}