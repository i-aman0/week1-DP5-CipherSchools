#include<iostream>
using namespace std;

// two numbers are given in the form of linked list, add the numbers and return the head of the linked list

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

void print(Node* &head){  // took reference of head so that no extra copy is created
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* next=NULL;
    Node* prev=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void insertAtTail2(Node* &ansHead, Node* &ansTail, int data){
    Node* temp=new Node(data);

    if(ansHead==NULL){
        ansHead=temp;
        ansTail=temp;
        return;
    }
    else{
        ansTail->next=temp;
        ansTail=temp;
    }

}

Node* addNumbers(Node* first, Node* second){
    first=reverse(first);
    second=reverse(second);

    Node* ansHead=NULL;
    Node* ansTail=NULL;

    int carry=0;

    while(first!=NULL || second!=NULL || carry!=0){
        int sum=0;
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }

        sum=val1+val2+carry;
        int digit=sum%10;

        insertAtTail2(ansHead, ansTail, digit);

        carry=sum/10;

        if(first!=NULL){
            first=first->next;
        }

        if(second!=NULL){
            second=second->next;
        }
    }

    return reverse(ansHead);
}

int main()
{
    Node* node1=new Node(2);
    Node* head1=node1; // creating head node which is pointing to the first node created above
    Node* tail1=node1; // in case of single node tail pointer also points to that only 

    insertAtTail(tail1, 3);
    insertAtTail(tail1, 6);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 6);

    cout<<"First linked list is : "<<endl;
    print(head1);



    Node* node2=new Node(5);
    Node* head2=node2;
    Node* tail2=node2;

    insertAtTail(tail2,8);
    insertAtTail(tail2,4);
    insertAtTail(tail2,6);
    insertAtTail(tail2,2);

    cout<<"Second linked list is : "<<endl;
    print(head2);   



    Node* sum=addNumbers(head1, head2);
    cout<<"The sum of the above linked lists is : "<<endl;
    print(sum);

   
    return 0;
}