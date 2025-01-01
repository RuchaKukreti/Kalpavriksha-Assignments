#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int b,n,m;

    printf("Base: ");
    scanf("%d",&b);
    printf("Exponent: ");
    scanf("%d",&n);
    printf("Mod: ");
    scanf("%d",&m);
    
    if(m<1 || n<0){
        printf("Invalid input");
        return 0;
    }

    int val[100]={0};
    val[0]=b%m;
    int j=1;

    for(int i=1;i<n;i=i*2,j++){
        val[j]=(int)pow(val[j-1],2)%m;
        int new=val[j-1]-m;
        if(abs(new)<val[j]){val[j]=new;}

    }

    int i=0,ans=0;
    while(val[i]!=0){
        i++;
    }

    if(val[i-2]<0){val[i-2]=val[i-2]+m;}
    printf("\nAns:%d",val[i-2]);

    return 0;
}