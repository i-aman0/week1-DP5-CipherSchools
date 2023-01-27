#include<iostream>
using namespace std;

// given a linked list, delete nth node from the end of linked list
// There are 3 ways to solve this question :

// 1. Find the size of the array and then delete (size-n)th node from starting

// 2. Use slow and fast pointer
//    Shift the fast pointer at nth node from starting
//    When fast pointer is at nth node from stating and slow pointer is at head
//    Move slow and fast pointer by one unit at a time 
//    By the time the fast pointer reaches end of the list, the slow pointer will point to the (size-n)th node from beginning
//     i.e. nth node form end

// 3. Traverse the linked list and push the nodes in a stack
//    When complete list is pushed into the stack, start popping and decrement the value of 1 each time you pop
//    When n==-1 stop , it means you are at a prev to nth node from beginning 
//    use conventional method to delete node


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }


    // destructor 
    ~Node(){
        int value=this->data;

        // freeing memory 
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data : "<<value<<endl;
    }
};



void insertAtHead(Node* &head, int data){
    //creating a new node
    Node* temp=new Node(data);
     
    temp->next=head;
    head=temp;
}



void insertAtTail(Node* &tail, int data){
    // create a new node
    Node* temp=new Node(data);

    tail->next=temp;
    tail=tail->next;
}



void insertAtPosition(Node* &tail, Node* &head, int position, int data){

    // inserting at start
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    // inserting at tail
    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }

    // inserting at a position 
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

}


void deleteNode(int position, Node* &head, Node* &tail){

    // deleting start or first node 
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;

        // freeing memory (the delete keyword calls the destructor of the object)
        delete temp;
    }

    else{
        // deleting any other node (last or any middle node)

        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next==NULL){
            tail=prev;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


// 1st method by finding the length of linked list 
Node* deleteK(Node* head, int n){
    Node* temp=head;
    if(head->next==NULL){
        return NULL;
    }
    
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    temp=head;

    if(n==count){
        return head->next;
    }

    int searchPoint=count-n;
    // start i from 1 or go upto searchPoint-1 bcoz we need to go upto a node previous to the destined node for deleting 
    for(int i=1;i<searchPoint; i++){
        temp=temp->next;
    }

    temp->next=temp->next->next;

    return head;

}



void print(Node* &head){  // took reference of head so that no extra copy is created
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1=new Node(10);

    //cout<<"The data stored in node is : "<<node1->data<<endl;
    //cout<<"The next pointer of node points to : "<<node1->next<<endl;

    Node* head=node1; // creating head node which is pointing to the first node created above
    Node* tail=node1; // in case of single node tail pointer also points to that only 

    insertAtHead(head,20);
    print(head);

    insertAtHead(head,30);
    print(head);

    insertAtHead(head,40);
    print(head);

    insertAtTail(tail,50);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtPosition(tail, head, 3, 70);
    print(head);

    head=deleteK(head, 3);
    cout<<"Deleted 3rd node from end"<<endl;
    print(head);

    return 0;
}