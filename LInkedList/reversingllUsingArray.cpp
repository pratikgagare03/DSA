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

void reversellArray(node* p){// vector
    vector<int> v;
    int i=0;
    node* first=p;
    while(first){
        v.push_back(first->data);
        first=first->next;
    }
first=p;
i=v.size()-1;
       while(first){
           first->data=v[i];
           i--;
           first=first->next;
       }
   
    
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
display(first);
reversellArray(first);
display(first);

    return 0;
}