/*********************Queue**********************/
/*
1. A Queue is a list which strore the similiar type of data, It is different from stack ncz Insertion happen at one end it is called rear and deleteion happen at another end it is 
called front.
2. To insert an element is called the Enqueue. Enque happen at rear end 
3. To delete an element is called the Dequeue.
4. Enqueue an element in a full queue is overflow 
5. Dequeue an element from an empty queue is underflow
6. Insertion and deletion must follow FIFO or LILO sequence 
*********************************Application****************************
1. Scheduling the job in OS
2. Waitinting time of customer in call center
3. Asynchronous file transfer 
*/

/*******Implementation Using Dynamic Circular Array**********/

#include <iostream>
#include <climits>
using namespace std;
struct ArrayQueue
{
	int rear;
	int front;
	int capacity;
	int *array;
};

// Allocates the memory and Initialize the Varaibles
ArrayQueue* createQueue(int size){
	ArrayQueue* Q=(ArrayQueue*)malloc(sizeof(ArrayQueue));
	Q->rear=-1;
	Q->front=-1;
	Q->capacity=size;
	Q->array=(int*)malloc(sizeof(int));
}
// Check if Q is full or not 
bool isFullQueue(ArrayQueue* Q){
	return((Q->rear+1)%Q->capacity==Q->front);   // % by capacity because we are Using Circular 
}
bool isEmptyQueue(ArrayQueue* Q){
	return(Q->front==-1);
}
//Insert the element 
void Enqueue(ArrayQueue* Q, int data){
	if(isFullQueue(Q)){
		cout<<"Queue is Full\n";
		return;
	}else{
		Q->rear=(Q->rear+1)% Q->capacity; // before insert the element rear =-1+1=0
		Q->array[Q->rear]=data;
		if(Q->front==-1){ // After Inserting first element make front =rear =0
			Q->front=Q->rear;
		}
	}
}

// Remove the element from the front end of the queue
int Dequeue(ArrayQueue* Q){
	int data;// Inititialize the data the value which does not exist in to Queue
	if(isEmptyQueue(Q)){
		cout<<"Queue is Empty\n";
		return 0;
	}else{
		data=Q->array[Q->front];
		if(Q->front==Q->rear){
			Q->front=Q->rear=-1;
		}else{
			Q->front=(Q->front+1)% Q->capacity;
		}
	}
	return data;
}
// find out the size of the queue means the number of elements exist similiar to rear-front+1
int Queuesize(ArrayQueue* Q){
	if(isEmptyQueue){
		return 0;
	}else{
	return(Q->capacity-Q->front+Q->rear+1)%Q->capacity;
	}
}

void deleteQueue(ArrayQueue* Q){
	if(Q){
		if(Q->array){
			free(Q->array);
		}
		free(Q);
	}
}

void display(ArrayQueue* Q){
	for(int i=0;i<=(Q->rear)%Q->capacity;i++){
		cout<<Q->array[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	// Create the Skeleton of the Queue

	ArrayQueue* Q= createQueue(10);
	// Enter the elements in to Queue
	Enqueue(Q,10);
	Enqueue(Q,20);
	Enqueue(Q,30);
	Enqueue(Q,400);
	Enqueue(Q,50);
	display(Q);
	// display the size
	cout<< "Queue Size of after inserting the above elements is : " << Queuesize(Q)<<endl;
	//Check Queue is Full or Not 
	if(isFullQueue(Q)){
		cout<<"Queue is FULL\n";
	}else{
		cout<<"Queue is not full Yet\n";
	}
	// Check if Queue is empty or not 
		if(isEmptyQueue(Q)){
		cout<<"Queue is empty\n";
	}else{
		cout <<"Queue is not Empty\n";
	}

	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;
	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;
	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;
	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;
	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;

	// display the size
	cout<< "Queue Size : " << Queuesize(Q)<<endl;
	// UnderFlow
	cout <<"Element to be deleted from front is::" <<Dequeue(Q)<<endl;
//check size again 
	cout<< "Queue Size: " << Queuesize(Q)<<endl;
	//Check Queue is Full or Not 
	if(isFullQueue(Q)){
		cout<<"Queue is FULL\n";
	}else{
		cout<<"Queue is not full Yet\n";
	}
	// Check if Queue is empty or not 
		if(isEmptyQueue(Q)){
		cout<<"Queue is empty\n";
	}else{
		cout <<"Queue is not Empty\n";
	}

	return 0;
}