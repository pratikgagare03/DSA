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

int findMidElement(node* p){
    node* q=p;
    
    while(q){
        if(q->next){
            q=q->next->next;
            p=p->next;
        }
        else{
            q=q->next;
        }
    }
   return p->data;
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
display(first);
cout<<findMidElement(first)<<endl;

    return 0;
}