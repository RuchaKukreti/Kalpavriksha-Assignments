#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int calculate(int m,int n,char op){
    if(op=='/'){
        if(n==0)
        {   printf("Error: Division by 0");
            exit(0);}
        return m/n;}
    else if(op=='*')return m*n;
}
int isoperator(char ch){
    if(ch=='+'|| ch=='-' || ch=='*' || ch=='/')return 1;
    return 0;
}
int formNumber(char exp[],int *i){
    int n=0;
    while(isdigit(exp[*i]) && !isspace(exp[*i]) && !isoperator(exp[*i])){
                n=n*10+(exp[*i]-'0');
                (*i)++;
            }
    return n;
}
int formValue(char exp[],int *i){
    int m=0,n=0,ans=0;
    char op;
    while(isspace(exp[*i]))(*i)++;
    m=formNumber(exp,i);
    while(exp[*i]!='+' || exp[*i]!='-'){
                                if(isspace(exp[*i])){
                                    (*i)++;}
                                if(exp[*i]=='/' || exp[*i]=='*'){
                                    op=exp[*i];
                                    (*i)++;    
                                }
                                else if(exp[*i]=='+'||exp[*i]=='-')return m;
                                else{
                                    if(exp[*i]=='\0'||exp[*i]=='\n')break;
                                    printf("Error: Invalid expression.");
                                    exit(0);
                                }
                                if(isspace(exp[*i])){(*i)++;}
                                n=formNumber(exp,i);
                                ans=calculate(m,n,op);
                                m=ans; //shuffel m,n,ans
                                if(exp[*i]=='\0')return ans;
                        }
        return m;
}
int evaluate(char exp[],int *i){
    int v,value=0;
    value=formValue(exp,i);
    while(exp[*i]!='\0'){                    //until we get end of exp
       if(isspace(exp[*i])){(*i)++;}
       if(exp[*i]=='+'){
            (*i)++;
            v=formValue(exp,i);
            value+=v;
       }
       else if(exp[*i]=='-'){
            (*i)++;
            v=-1*formValue(exp,i);
            value+=v;
       }
       else{(*i)++;}
    }
    return value;
}
void main(){
    char exp[100];    
    printf("Enter your arithmetic expression: ");
    fgets(exp,sizeof(exp),stdin);
    int i=0;
    int value=evaluate(exp,&i);
    printf("Evaluated value:%d",value);
}