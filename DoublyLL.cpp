#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* prev=NULL;
    node* next = NULL;

};
node* first=NULL;
node* last;

void insert(int data){
    if(first==NULL){
        first=new node;
        first->data=data;
        first->prev=NULL; 
        last=first;
    }
    else{
        node* temp=new node;
        temp->data=data;
        last->next=temp;
        temp->prev=last;
        last=temp;

    }
}

void insertAtPos(int pos,int data){
node* temp=new node;
if(pos==1){
temp->data=data;
temp->next=first;
temp->prev=NULL;
first->prev=temp;
first=temp;
}
else{
    node* p=first,*q;
    int i=1;
    while(i<pos-1 && p){
        p=p->next;
        i++;
    }
    temp->data=data;
    q=p->next;
    p->next=temp;
    temp->prev=p;
    temp->next=q;
    q->prev=temp;
}

}

int deleteAtPos(int pos){
    node* p=first,*q;
    int a;
    if(pos==1){
        q=p->next;
        q->prev=NULL;
        first=q;
        a=p->data;
        delete p;
    }
    else{
        int i=1;
        while(i<pos-1){
            p=p->next;
            i++;
        }
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        a=q->data;
        delete q;

    }
    return a;
}

void reverse(node* p){
    node* q;
    while(p){
        q=p->next;
        p->next=p->prev;
        p->prev=q;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
    
}
void display(node* p){
   
    if(p){
    cout<<p->data<<" ";
    display(p->next);}
    
    
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);
    insert(17);
    display(first);
    cout<<endl;
    cout<<deleteAtPos(1)<<endl;
    insertAtPos(5,25);
    display(first);
    cout<<endl;
    reverse(first);
    display(first);
    
    return 0;
}