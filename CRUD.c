#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
char filename[]="users.txt";
typedef struct{
    int ID;
    char Name[20];
    int Age;
} user;
void Create(){
    //Taking the data
    user u,prev_u;
    printf("Add a new user to the file.");
    printf("\nEnter ID: ");
    scanf("%d",&u.ID);
    printf("Enter Name: ");
    scanf("%s",&u.Name);
    printf("Enter Age: ");
    scanf("%d",&u.Age);
    if(u.Age<1 || u.Age>100){printf("Error: Invalid age. User not created.");
    return;}
    //Checking if the user id exists by opening file in read mode
    FILE *file=fopen(filename,"r+");
    if(!file){
        printf("Error opening the file.");
        return;
        }
    while (fscanf(file, "%d,%49[^,],%d\n", &prev_u.ID, prev_u.Name, &prev_u.Age) != EOF) {
        if(u.ID==prev_u.ID){
            printf("User with this ID already exists.");
            fclose(file);
            return;
        }
    }
    //puting data in the file if it is new id
    fprintf(file,"%d,%s,%d\n",u.ID,u.Name,u.Age);
    fclose(file);
    printf("User added");
    
}
void Read(){
    FILE *file=fopen(filename,"r");
    if(!file){printf("File doesn't exist");
        return;
        }
    user u;
    printf("-----------------------------\n");
    printf("ID\tName\tAge");
    printf("\n-----------------------------\n");
    while(fscanf(file,"%d,%49[^,],%d\n", &u.ID, u.Name, &u.Age) !=EOF){
        printf("%d\t%s\t%d\n", u.ID, u.Name, u.Age);
    }
    fclose(file);
}
 void Update(){
    FILE *file=fopen(filename,"r");
    if(!file){printf("File doesn't exist");
        return;
        }
    int update_id,flag=0;
    user u;
    printf("Enter User ID: ");
    scanf("%d",&update_id);
    //creating a temporary file
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }
    //Checking if the user id exists
    while (fscanf(file, "%d,%49[^,],%d\n", &u.ID, u.Name, &u.Age) != EOF) {
        if(u.ID==update_id){
            printf("Enter new Name: ");
            scanf("%s", u.Name);
            printf("Enter new Age: ");
            scanf("%d", &u.Age);
            flag=1;                 //If id to be updated exists set flag=1
        }
        fprintf(tempFile, "%d,%s,%d\n", u.ID, u.Name, u.Age);
    }
    fclose(file);
    fclose(tempFile);
    if (flag) {
        remove(filename);
        rename("temp.txt", filename);
        printf("User Record Updated..\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
 }
void Delete(){
    FILE *file=fopen(filename,"r");
    if(!file){printf("File doesn't exist");
        return;
        }
    int delete_id,flag=0;
    user u;
    printf("Enter User ID: ");
    scanf("%d",&delete_id);
    //creating a temporary file
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }
    //Checking if the user id exists
    while (fscanf(file, "%d,%49[^,],%d\n", &u.ID, u.Name, &u.Age) != EOF) {
        if(u.ID!=delete_id){
            fprintf(tempFile, "%d,%s,%d\n", u.ID, u.Name, u.Age);
        }
        else{flag=1;}                   //If Id to be deleted exists set flag=1
    }
    fclose(file);
    fclose(tempFile);
    if (flag) {
        remove(filename);
        rename("temp.txt", filename);
        printf("User Record Deleted..\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
}
int main(){
    int choice;
    while(1){
        printf("\n1. Create a user.\n2. Display user details.\n3. Update user details.\n4. Remove a user\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: Create();
                break;
            case 2: Read();
                break;
            case 3: Update();
                break;
            case 4: Delete();
                break;
            case 5:
                exit(0);
            default:printf("Enter valid choice.");
                break;
        }
    }
    return 0;
}