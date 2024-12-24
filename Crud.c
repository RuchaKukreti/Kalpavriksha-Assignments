#include<stdio.h>
#include<stdlib.h>
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
void crud(int oper){
    user u;
    int updateflag=0,deleteflag=0,ID=0;
    char *mode;
    if(oper==1){mode="a+";}
    else{mode="r";}
    FILE *file=openFile(userfile,mode),*file2;
    if(oper==3 || oper==4){file2=openFile("temp.txt","w");}
    if(oper==1 || oper==3){
        u=getDetails();
        }
    if(oper==4){
        printf("Enter ID to be deleted: ");
        scanf("%d",&ID);
        }
    user u2;
    while(fscanf(file,"%d,%49[^,],%d",&u2.id,u2.name,&u2.age)!=EOF){
            if(oper==1){ //create
                if(u.id==u2.id){
                printf("User already exists.\n");
                fclose(file);
                return;}
            }
            else if(oper==2){//read
                printf("%d\t%s\t%d\n",u2.id,u2.name,u2.age);
            }
            else if(oper==3){//update
                if(u2.id==u.id){
                    fprintf(file2,"%d,%s,%d\n",u.id,u.name,u.age);
                    updateflag=1;
                }
                else{
                    fprintf(file2,"%d,%s,%d\n",u2.id,u2.name,u2.age);
                }
            }
            else if(oper==4){//delete
                if(u2.id==ID){
                    deleteflag=1;
                }
                else{
                    fprintf(file2,"%d,%s,%d\n",u2.id,u2.name,u2.age);
                }
            }
            
        }
    if(oper==1){
                    fprintf(file,"%d,%s,%d\n",u.id,u.name,u.age);
                    printf("\nUser added!\n");
                    fclose(file);
                    return;
    }
    fclose(file);
    if(oper==2)return;
    if(oper==3 || oper==4)fclose(file2);
    if(updateflag ||deleteflag){
        if(updateflag){
            printf("User record updated.\n");
            }
        else if(deleteflag){
            printf("User record deleted.\n");
            }
        remove(userfile);
        rename("temp.txt",userfile);
        }
    else{
        printf("User doesn't exist.\n");
        remove("temp.txt");
    }
}
int main(){
    int ch=0;
    while(1){
    printf("Click: 1.Create  2.Read  3.Update  4.Delete  5.Exit  :");
    scanf("%d",&ch);
    if(ch==1 || ch==2|| ch==3 || ch==4){crud(ch);}
    else{
        if(ch==5){
            printf("Exiting.\n");
            return 0;
        }
        printf("Enter valid choice");
        }
    }
    return 0;
}