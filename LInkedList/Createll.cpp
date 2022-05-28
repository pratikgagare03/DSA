#include<bits/stdc++.h>
using namespace std; 
class node{
    public:
    int data;
    node* next=NULL;// 0
};
node* first=NULL;
node* prevNode;

void insert(int data1){

if(first==NULL){
    first=new node;
    first->data=data1;
    prevNode=first;
}
else{
    node* temp=new node;
    temp->data=data1;
    prevNode->next=temp;
    prevNode=temp;
}     }

void insertAtPos(int pos,int data1,node* first1){
    if(pos==1){
        node* temp=new node;
        temp->data=data1;
        temp->next=first1;
        first=temp;
    }
    else{
        int count=1;
        while(first1!=NULL && count<pos-1){
            first1=first1->next;
            count++;
        }
        
        node* temp=new node;
        temp->data=data1;
        temp->next=first1->next;
        first1->next=temp;
        
    }
}
void insertSorted(node* first,int data1){
    node* temp=first->next;
    while(first->data<data1 &&  temp!=NULL){
        if(temp->data>data1){
        // cout<<"temp->data"<<temp->data;
        // cout<<"first->data"<<first->data;

        node* temp1=new node;
        temp1->data=data1;
        temp1->next=first->next;
        first->next=temp1;
        break;
        }

        temp=temp->next;
        first=first->next;
    }
    
}
void display(node* first){
    while(first!=NULL){
        cout<<first->data;
        first=first->next;


    if(first==NULL){
        cout<<"->NULL "<<endl;
    }
    else
        cout<<"->";
    }
}

void recDisplay(node* first){
    if(first!=NULL){
    cout<<first->data<<endl;
    recDisplay(first->next);}
}

int RecCountNode(node* first){
    if(first!=NULL){
        return RecCountNode(first->next)+1;
    }
    return 0;
}
int sum(node* first){
    if(first!=NULL){
        return first->data+=sum(first->next);
    }
    return 0;
}

void deleteNode(node* first1,int pos){
    int count=1;
    if(pos==1){
     node* temp=new node;
     temp=first1;
     first=temp->next;
     delete(temp);
    }
    else{
    while(first1!=NULL && count<pos-1){
        first1=first1->next;
        count++;
    }
    node* temp=first1->next;
    first1->next=temp->next;
    delete(temp);}
}

bool isSorted(node* p){
    //  int count=1;
    //  node* first1=first;
    //     while(first1){
    //         first1=first1->next;
    //         count++;
    //     }
    if(p && p->next==NULL){
        return true;
        }
    
    node* temp=new node;
    temp=p->next;
    while(temp->next!=NULL){
        if(p->data > temp->data){
            return false;
        }
        p = p->next;
        temp = temp->next;
    }
    return true;

    /*
    we can do the same by keeping track of previous data and keep comparing
    the same with current data 
    this can be done with one pointer only
    */
}
int main(){
    
       insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(7);
    insert(8);
    insert(9);

    // recDisplay(first);
    // cout<<RecCountNode(first)<<endl;
    // cout<<sum(first)<<endl;
    // insertAtPos(3,44,first);
    // insertSorted(first,6);
    // display(first);
    // deleteNode(first,1);
       display(first);
    cout<<isSorted(first)<<endl;
    return 0;
}