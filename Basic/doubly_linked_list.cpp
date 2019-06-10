#include <iostream>
//#include <stdlib>


using namespace std;
struct DLLnode{
	int data;
	struct DLLnode* prev;
	struct DLLnode* next;
};
DLLnode* creat_new_node(int value){
	DLLnode* new_node=(DLLnode*)malloc(sizeof(DLLnode));
	new_node->data=value;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
void insert_beg(DLLnode** head_ref, int value){
	DLLnode* first=*head_ref;
	DLLnode* new_node=creat_new_node(value);

	if((*head_ref)==NULL){
		(*head_ref)=new_node;
	}else{
		new_node->next=first;
		first->prev=new_node->next;
		(*head_ref)=new_node;
	}
}
void insert_end(DLLnode* head_ref,int value){
	DLLnode *temp=head_ref;
	DLLnode* new_node=creat_new_node(value);
	if(temp==NULL){
		head_ref=new_node;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;	
		}
		temp->next=new_node;
		new_node->prev=temp->next;
	}
}
void display(DLLnode* head_ref){
	DLLnode* first=head_ref;
	if(first==NULL){
		cout<<"Empty DLL, Nothing to Display\n";
	}else{
		while(first!=NULL){
			cout<<first->data<<" ";
			first=first->next;
		}
		cout<<"\n";
	}
}

int main(){
	cout <<"*************Doubly Linked List**************\n";
	struct DLLnode* head_ref=NULL;
	int data;
	display(head_ref);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_beg(&head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_beg(&head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_beg(&head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_beg(&head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_beg(&head_ref,data);
	display(head_ref);
	cout<<"****************Insert at End**************\n";
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_end(head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_end(head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_end(head_ref,data);
	cout<<"Enter the data for the DLLnode \n";
	cin>>data;
	insert_end(head_ref,data);
	display(head_ref);
	

}


