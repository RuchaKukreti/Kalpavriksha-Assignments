#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int calculate(int num1,int num2,char operator){
    int ans;
    switch(operator){
        case '+': ans=num1+num2;
        break;
        case '-': ans=num1-num2;
        break;
        case '*': ans=num1*num2;
        break;
        case '/': 
                    if(num2==0){
                        printf("Error: Division by zero.");
                        exit(0);}
                    ans=num1/num2;
        break;
        default :printf("Invalid operation.");
                 exit(0);
    }
    return ans;
}
int precedence(char operator) {
    if (operator=='/') {
        return 4;
    }
    if (operator=='*'){
        return 3;
    }
    if (operator=='+'){
        return 2;
    }
    if (operator=='-') {
        return 1;
    }
    return 0;
}

int evaluate(char* exp) {
    int number[100], top = -1;
    char operator[100],topOp = -1;
    int i = 0;
    while(exp[i]!='\0'){
        if(isspace(exp[i])){
            i++;
            continue;}
        if(isdigit(exp[i])){
            int num=0;
            while(i < strlen(exp) && isdigit(exp[i])){
                num=num*10+(exp[i]-'0');
                i++;
            }
            number[++top]=num;
        }
        else if(exp[i]=='('){
            operator[++topOp]=exp[i];
            i++;
        }
        else if(exp[i]==')'){
            while(topOp>=0 && operator[topOp]!='('){
                int num2=number[top--];
                int num1=number[top--];
                char op=operator[topOp--];
                number[++top]=calculate(num1,num2,op);
            }
            topOp--;
            i++;
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            while(topOp>=0 && precedence(operator[topOp])>=precedence(exp[i])){
                int num2=number[top--];
                int num1=number[top--];
                char op=operator[topOp--];
                number[++top]=calculate(num1,num2,op);
            }
            operator[++topOp] = exp[i];
            i++;
        }
        else{
            printf("Invalid expression");
            exit(0);
        }
    }
    while (topOp >= 0) {
        int num2 = number[top--];
        int num1 = number[top--];
        char op = operator[topOp--];
        number[++top] = calculate(num1, num2, op);
    }
    return number[top];
}
void main(){
    char exp[100];
    printf("Enter the expression :");
    fgets(exp, sizeof(exp), stdin);
    int i=0;
    while(exp[i]!='\0'){
        if(!isdigit(exp[i])&& !isspace(exp[i])&& exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' && exp[i]!='(' && exp[i]!=')'){
            printf("Invalid Expression");
            return;
        }
        i++;
    }
    
    int result = evaluate(exp);
    printf("Result: %d\n", result);
}