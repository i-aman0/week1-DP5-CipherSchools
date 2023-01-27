#include<iostream>
using namespace std;


// to remove a loop from a linked list, we find the node previous to the start node inside the loop
// make the prev node point to NULL instead of start i.e. prev->next=NULL


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

Node* isCycle(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* startingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection=isCycle(head);

    if(intersection==NULL){
        return NULL;
    }

    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    Node* start=startingNode(head);

    if(start==NULL){
        return;
    }

    Node* temp=start;

    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
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

    //deleteNode(7,head,tail);
    //print(head);

    tail->next=head->next;

    cout<<"Head points at value : "<<head->data<<endl;
    cout<<"Tail points at value : "<<tail->data<<endl;

    if(isCycle(head)!=NULL){
        cout<<"There is a cycle in the linked list"<<endl;
    }
    else{
        cout<<"There is no cycle in the linked list"<<endl;
    }

    Node* startNode=startingNode(head);
    cout<<"The loop is starting at element : "<<startNode->data<<endl;

    removeLoop(head);
    print(head);

    return 0;
}