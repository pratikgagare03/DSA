#include<bits/stdc++.h>
using namespace std; 
class node{
    public:
    int data;
    node* next=NULL;// 0
};
node* first=NULL;
node* second=NULL;
node* third=NULL;
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

void insert1(int data1){

if(second==NULL){
    second=new node;
    second->data=data1;
    prevNode=second;
}
else{
    node* temp=new node;
    temp->data=data1;
    prevNode->next=temp;
    prevNode=temp;
}     }

void insert3(int data1){

if(third==NULL){
    third=new node;
    third->data=data1;
    prevNode=third;
}
else{
    node* temp=new node;
    temp->data=data1;
    prevNode->next=temp;
    prevNode=temp;
}     }

void display(node* first){
    while(first!=NULL){
        cout<<first->data;
        first=first->next;


    if(first==NULL){
        cout<<"->NULL"<<endl;
    }
    else
        cout<<"->";
    }
}


void merge(node* p,node* q){
    while(p && q){
    
    if(p->data <= q->data){
        insert3(p->data);
        p=p->next;
    }
    else{
        insert3(q->data);
        q=q->next;
        }}

    while(p){
        insert3(p->data);
        p=p->next;
    }

    while(q){
        insert3(q->data);
        q=q->next;
    }

}
   
 

int main(){
    
    insert(1);
    insert(2);
    insert(4);
    insert(8);

    insert1(3);
    insert1(5);
    insert1(6);
    insert1(7);

    
display(first);
display(second);
merge(first,second);
display(third);

    return 0;
}