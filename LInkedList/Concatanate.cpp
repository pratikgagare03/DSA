#include<bits/stdc++.h>
using namespace std; 
class node{
    public:
    int data;
    node* next=NULL;// 0
};
node* first=NULL;
node* second=NULL;
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


void concat(node* p,node* q){
    while(p->next){
        p=p->next;
    }
    p->next=q;
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
concat(first,second);
display(first);

    return 0;
}