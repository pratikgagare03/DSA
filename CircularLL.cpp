#include<bits/stdc++.h>
using namespace std; 

class node
{
    public:
    int data;
    node* next=NULL;// 0
};
node* first=NULL;
node* prevNode=first;


void insert(int data1){

if(first==NULL){
    first=new node;
    first->data=data1;
    first->next=first;
    prevNode=first;
}
else{
    node* temp=new node;
    temp->data=data1;
    prevNode->next=temp;
    temp->next=first;
    prevNode=temp;

}     }





void display(node* p){
    do{
        cout<<p->data;
        p=p->next;


    if(p==first){
        cout<<"->First"<<endl;
    }
    else
        cout<<"->";
    }while(p!=first);
}


int deletePos(int pos){
    node* p=first;
    node* q;
    int a;
    if(pos==1){
        while(p->next!=first){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        a=q->data;
        delete q;
    

    }
    else{
    for(int i=1;i<pos-1;i++){
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    a=q->data;
    delete q;}
    return a;
}
   
 

int main(){
    
    insert(1);
    insert(2);
    insert(4);
    insert(8);
    insert(12);
    insert(16);
  
    
   

 display(first);
cout<<deletePos(3)<<endl;
 display(first);

    return 0;
}