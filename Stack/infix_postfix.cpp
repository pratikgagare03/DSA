#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        char data;
        node* next=NULL;
};
node* top=NULL;
char* post;
void push(char data){
    node* p=new node;
    if(top==NULL){
        p->data=data;
        
        top=p;
    }
    else{
        p->data=data;
        p->next=top;
        top=p;
    }
}

char pop(){
    char a=-1;
    if(top){
    node* q=top;
    //a=(*q).data;
    a=q->data;
    top=top->next;
    delete(q);
    }
    return a;
}

char peek(int pos){
    int i=1;
    char a=-1;
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
int pre(char a){
    if(a=='+'|| a=='-'){
        return 1;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else
        return -1;
}
void infix_postfix(string s){
    post=new char[s.length()];
    int j=0,i=0;
    while(i<s.length()){
        if(s[i]!='+'&& s[i]!='-' && s[i]!='*' && s[i]!='/'){
            // cout<<"entered for"<<s[i]<<endl;
            post[j++]=s[i++];
            
        }
        else{
            if(pre(s[i])>pre(peek(1))){
                push(s[i++]);
            }
            else{
                while(pre(s[i])<=pre(peek(1))){
                    post[j++]=pop();
                }
                push(s[i++]);
            }
        }
    }
    while(top){
        post[j++]=pop();
    }

}
void print(int n){

for(int i=0;i<n;i++){
    cout<<post[i];
}
}
int main(){
    string s="a+b*c-d/e*k";
    infix_postfix(s);
    print(s.length());
    return 0;
}