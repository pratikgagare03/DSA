#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next=NULL;
};
node* top=NULL;

void push(int data){
    node* p=new node;
    if(top==NULL){
        p->data=data;
        
        top=p;
    }
    else{
        p->data=data;
        p->next = top;
        top=p;
    }
}

int pop(){
    int a=-1;
    if(top){
    node* q=top;
    //a=(*q).data;
    a=q->data;
    top=top->next;
    delete(q);
    }
    return a;
}

int peek(int pos){
    int i=1,a=-1;
    node* p=top;
    while(p && i!=pos){
        p=p->next;
        i++;
    }
    if(i==pos && p){
        a=p->data;   
    }
    return a;
}

void paranth(string s){
   int a=1;
   int x;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' ||s[i]=='{'){
            push(s[i]);
        }
        else if(s[i]==')' || s[i]==']' ||s[i]=='}'){
            if(top)
                 x=pop();
            else{
                a=-1;
                break;
            }
            if(abs(s[i]-x)>2){//difference of ascii values of any opening and closing paranthesis is always <=2
                //cout<<s[i]<<" "<<x<<endl;
                a=-1;
                break;
            }
        }        }
    if(top==NULL && a==1){
        cout<<"Matched"<<endl;
    }
    else{
        cout<<"Not Matched"<<endl;
    }
}

void print(node* top){
node* q=top;

while(q!=NULL){
    cout<<q->data;
    q=q->next;
}
cout<<endl;
}

int main(){
    string s="[{(b)+}(a)*k](]";
    paranth(s);
   
    return 0;
}