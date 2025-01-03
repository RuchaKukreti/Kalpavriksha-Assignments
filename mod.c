#include <stdio.h>
#include <math.h>
void binary(int *bin,int expo){
    int i=0,mod=0;
    while(expo>0){
        mod=expo%2;
        bin[32-i-1]=mod;
        expo=expo/2;
        i++;
    }
}
int main() {
    int b,n,m;
    printf("Base: ");
    scanf("%d",&b);
    printf("Exponent: ");
    scanf("%d",&n);
    printf("Mod: ");
    scanf("%d",&m);
    
    if(m<=1){
        printf("Invalid input for mod Enter mod>1\n");
        return 0;
    }
    if(n<0){
        printf("Invalid input for exponent Enter exponent>=0\n");
        return 0;
    }
    //create binary of exponent n;
    int bin[32]={0};
    binary(bin,n);
    //iterate until we get 1st 1 digit;
    int i=0;
    while(bin[i]!=1){
        i++;
    }
    //skip the first 1;
    i++;
    int value=b;
    while(i<32){
        if(bin[i]==0){//do 1 step
            value=(int)pow(value,2)%m;
        }
        else{//do 2 steps
            //step 1;
            value=(int)pow(value,2)%m;
            //step 2;
            value=(value*b)%m;
        }
        i++;
    }
    printf("ans:%d",value);
    return 0;
}