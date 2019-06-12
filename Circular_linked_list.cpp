
#include <iostream>

using namespace std;
/********************************************
***
 1. Circular linked list is used to keep track of whose turn it is in a multiplayer game
 2. In general CLL is used to implement round robin scheduling algorithm

***********************************************/
struct CllNode{
	int data;
	struct CllNode *next;
};

CllNode* creat_new_node(int value){
	CllNode* new_node=(CllNode*)malloc(sizeof(CllNode));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}
int count_CllNode(CllNode* head_ref){
	CllNode* temp_2=head_ref;
	int count=0;
	if(temp_2==NULL){
		cout<<"Circular Linked List is Empty\n";
		return count;
	}
	do{
		temp_2=temp_2->next;
		count++;

	}while(temp_2!=head_ref);
	return count;
}

void display(CllNode* head_ref){
	CllNode* current=head_ref;
	if(current==NULL){
		cout<<"Empty CLL nothing to print\n";
	}else{
		do{
			cout<<" "<<current->data;
			current=current->next;
		}while(current!=head_ref);
	}
	cout<<"\n";
}

void insert_end(CllNode** head_ref,int value){
	CllNode* temp_1=(*head_ref);
	CllNode* new_node=creat_new_node(value);
	if(temp_1==NULL){
		(*head_ref)=new_node;
		new_node->next=(*head_ref);
	}else{
		while(temp_1->next!=(*head_ref)){
			temp_1=temp_1->next;
		}
		temp_1->next=new_node;
		new_node->next=(*head_ref);
	}

}
void insert_beg(CllNode** head_ref, int value){
	CllNode* temp=(*head_ref);
	CllNode* current=(*head_ref);

	CllNode* new_node=creat_new_node(value);
	if(temp==NULL){
		(*head_ref)=new_node;
		new_node->next=(*head_ref);
	}else{
		while(temp->next!=(*head_ref)){
			temp=temp->next;
		}
			new_node->next=current;
			(*head_ref)=new_node;
			temp->next=(*head_ref);
			current=(*head_ref);
	}
}
int main(){
	cout<<"******************************Circular Linked List************************"<<"\n";
	CllNode* head_ref=NULL;
	cout <<"No of nodes in the linked list is "<<count_CllNode(head_ref)<<endl;
	
	insert_end(&head_ref,10);
	insert_end(&head_ref,20);
	//display(head_ref);
	insert_end(&head_ref,30);
	insert_end(&head_ref,40);
	insert_end(&head_ref,50);
	display(head_ref);
	cout <<"No of nodes in the linked list are:: "<<count_CllNode(head_ref)<<endl;
	insert_beg(&head_ref,9);
	insert_beg(&head_ref,8);
	insert_beg(&head_ref,7);
	display(head_ref);
	cout <<"No of nodes in the linked list are:: "<<count_CllNode(head_ref)<<endl;

	
	

	return 0;
}
