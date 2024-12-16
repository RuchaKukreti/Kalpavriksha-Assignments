#include<stdio.h>
#include<stdlib.h>                        //for exit(0)
typedef struct{
    int id;
    char name[100];
    int age;
}user;
char userfile[]="user.txt";
user getDetails(){
    user u;
    printf("Enter the details:\n");
    printf("ID: ");
    scanf("%d",&u.id);
    printf("Name: ");
    scanf("%s",u.name);
    printf("age: ");
    scanf("%d",&u.age);
    while(u.age<1 || u.age>100){
        printf("Enter valid age.\n");
        scanf("%d",&u.age);
    }
    return u;
}
FILE* openFile(char *filename,char *mode){
    FILE *file=fopen(filename,mode);                 
    if(!file){
        printf("Error opening the file.");
        exit(0);
    }
    return file;
}
void create(){
    user u=getDetails();
    FILE *file=openFile(userfile,"a+");  //open the file
    user user2;
    while(fscanf(file,"%d,%49[^,],%d\n", &user2.id,user2.name,&user2.age) !=EOF){//checking if the id already exists in the file
        if(u.id==user2.id){
            printf("User already exists.\n");
            fclose(file);
            return;
            }
    }
    fprintf(file,"%d,%s,%d\n",u.id,u.name,u.age);
    fclose(file);
    printf("\nUser added!\n");
}
void read(){
    FILE *file=openFile(userfile,"r");
    user u;
    printf("ID\tName\tAge\n--------------------\n");
    while(fscanf(file,"%d,%49[^,],%d",&u.id,u.name,&u.age)!=EOF){
        printf("%d\t%s\t%d\n",u.id,u.name,u.age);
    }
    fclose(file);
}
void update(){
    FILE *file=openFile(userfile,"r");
    FILE *file2=openFile("temp.txt","w");
    user u=getDetails();
    user u2;
    int flag=0;
    while(fscanf(file,"%d,%[^,],%d",&u2.id,u2.name,&u2.age)!=EOF){
        if(u2.id==u.id){
            fprintf(file2,"%d,%s,%d\n",u.id,u.name,u.age);
            flag=1;
        }
        else{
            fprintf(file2,"%d,%s,%d\n",u2.id,u2.name,u2.age);
        }
    }
    fclose(file);
    fclose(file2);
    if(flag){printf("User record updated.\n");
    remove(userfile);
    rename("temp.txt",userfile);
    }
    else{printf("User doesn't exist.\n");
    remove("temp.txt");
    }
}
void delete(){
    int ID,flag=0;
    printf("Enter ID to be deleted: ");
    scanf("%d",&ID);
    user u;
    FILE *file=openFile(userfile,"r");
    FILE *file2=openFile("temp.txt","w");
    while(fscanf(file,"%d,%[^,],%d",&u.id,u.name,&u.age)!=EOF){
        if(u.id==ID){
            flag=1;
        }
        else{
            fprintf(file2,"%d,%s,%d\n",u.id,u.name,u.age);
        }
    }
    fclose(file);
    fclose(file2);
    if(flag){printf("User record deleted.\n");
        remove(userfile);
        rename("temp.txt",userfile);
    }
    else{printf("User not found.\n");
        
    }
}
int main(){
    int ch;
    while(1){
    printf("Click: 1.Create  2.Read  3.Update  4.Delete  5.Exit  :");
    scanf("%d",&ch);
    if(ch==1)create();
    else if(ch==2)read();
    else if(ch==3)update();
    else if(ch==4)delete();
    else if(ch==5){exit(0);}
    else{printf("Enter valid choice\n");}
    }
    return 0;
}
