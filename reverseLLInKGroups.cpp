#include<iostream>
using namespace std;


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

Node* kReverse(Node* head, int k){
    // Base Case
    if(head==NULL){
        return NULL;
    }

    // Step 1. Reverse first k nodes
    Node* next=NULL;
    Node* curr=head;
    Node* prev=NULL;

    int count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    // Step 2. Rest recursion will handle 
    if(next!=NULL){
        head->next=kReverse(next,k);
    }

    // Returning head of reversed list i.e. prev
    return prev;
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

    //cout<<"Head points at value : "<<head->data<<endl;
    //cout<<"Tail points at value : "<<tail->data<<endl;

    cout<<"\nThe reversed linked list is : "<<endl;
    head=kReverse(head,2);
    print(head);
    cout<<endl;

    return 0;
}