#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next=NULL;
};
node* top=NULL;
char* post;
void push(int data){
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
    int i=1;
    int a=-1;
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
 int isOperand(char x)
{
if(x=='+' || x=='-' || x=='*' || x=='/')
return 0;
else
return 1;
}
int evaluatePostfix(string s){
    
    for(int i=0;i<s.length();i++){
        if(isOperand(s[i])){
            push(s[i]-'0');
        }
        else{
            int a=pop();
            int b=pop();
int ans;
            if(s[i]=='+'){
                ans=b+a;
            }
            else if(s[i]=='-'){
                ans=b-a;
            }
            else if(s[i]=='/'){
                ans=b/a;
            }
            else if(s[i]=='*'){
                ans=b*a;
            }
    push(ans);
        }
    }
    return peek(1);
}
string s1;
void print(int n){

for(int i=0;i<n;i++){
    cout<<post[i];
}
}
int main(){
    string post1="234*+82/-";
    cout<<evaluatePostfix(post1);
   
    
    return 0;
}