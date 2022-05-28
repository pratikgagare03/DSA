#include<bits/stdc++.h>
using namespace std;
class poly{
    public:
        int coeff;
        int power;
};
void createPoly(int size,poly arr[]){
    
    for(int i=0;i<size;i++){
        int term;
        cout<<"Enter term:" ;
        cin>>term;
        cout<<"Enter coeff:" ;
        cin>>arr[term-1].coeff;
        cout<<"Enter power:" ;
        cin>>arr[term-1].power;
        
    }
    
}
int evaluatePoly(poly arr[],int x){
    int ans=0;
     for(int i=0;i<3;i++){
         ans+=arr[i].coeff*(pow(x,arr[i].power));
     }
     return ans;
}

int main(){
    poly arr[3];
    createPoly(3,arr);
    cout<<evaluatePoly(arr,3)<<endl;
    return 0;
}

