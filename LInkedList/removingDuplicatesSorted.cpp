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
void removeDuplicates(node* p){
    int prevData=p->data;
    node* prevNode=p;
    p=p->next;
    while(p){
        int a= p->data;
        if(prevData==a){
            prevNode->next=p->next;
            delete(p);
        }
        else
            prevNode=p;

        prevData=prevNode->data;
        p=prevNode->next;
    }
}
int main(){
    
    insert(1);
    insert(2);
    insert(2);
    insert(3);
    insert(3);
    insert(6);
    insert(9);
    insert(9);
display(first);
removeDuplicates(first);
display(first);

    return 0;
}