#include<stdio.h>

int main(){
    char s[]="deep";
    
    long int h=0,x=0;
    for(int i=0;s[i]!='\0';i++){
        x=1;
        x=x<<s[i]-97;
        if(x&h>0){
            printf(" %c is duplicated",s[i]);
        }
        else{
            // cout<<s<<endl;
            h=x|h;
        } 
    }
    return 0;
}