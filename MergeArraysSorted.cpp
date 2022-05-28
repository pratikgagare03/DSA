#include<bits/stdc++.h>
using namespace std;
void merge(int a1[],int m,int a2[],int n,int a3[]){
       int i=0,j=0,k=0;
       for(;i<m && j<n;k++){
            if(a1[i]<a2[j]){
                a3[k]=a1[i];
                i++;
            }
            else{
                a3[k]=a2[j];
                j++;
            }
       }
       for(;i<m;i++,k++){
           a3[k]=a1[i];
       }
       for(;j<n;j++,k++){
           a3[k]=a2[j];
       }
}
int main(){
    int a1[]={3,4,5,6,10};
    int a2[]={1,2,7,8,12};
    int a3[10];
    merge(a1,5,a2,5,a3);
    for(int i=0;i<10;i++){
        cout<<a3[i]<<" ";
    }
    cout<<endl;
    return 0;
}