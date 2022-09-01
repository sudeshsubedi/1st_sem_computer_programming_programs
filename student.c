/*
* crud program for students details
* concepts used: file handling and structs
*/

#include <stdio.h>
#include <stdlib.h>

int num_of_sts;

struct Student {
    char name[30], faculty[5], roll[15];
};

void menu();
void show_all(struct Student* sts);
void add(struct Student* sts);
void delete(struct Student* sts);
void update(struct Student* sts);

int main() {
    struct Student students[100];
    // struct Student* student;
    int opt, quit = 1;
    FILE* fp;
    fp = fopen("/home/sudesh/BCT/1st_sem/C/programs/builds/student.dat", "rb");
    if(fp == NULL) {
        printf("error opening file\n");
        exit(1);
    }

    num_of_sts = fread(students, sizeof(struct Student), 100, fp);
    fclose(fp);
    while(quit)
    {
        menu();
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
        case 1:
            show_all(students);
            break;
        case 2:
            add(students);
            break;
        case 3:
            delete(students);
            break;
        case 4:
            update(students);
            break;
        case 5:
            quit = 0;
            break;
        default:
            printf("Invalid option %d\n", opt);
            getchar();
        }
    }
    fp = fopen("/home/sudesh/BCT/1st_sem/C/programs/builds/student.dat", "wb");
    if(fp == NULL) {
        printf("error opening file for writing\n");
        exit(1);
    }

    fwrite(students, sizeof(struct Student), num_of_sts, fp);
    fclose(fp);
    return 0;
}

void menu() {
    system("clear");
    printf("Student management system\n");
    printf("\n1. Show all students\n");
    printf("2. Add a student\n");
    printf("3. Remove a student\n");
    printf("4. Change students faculty\n");
    printf("5. Exit\n");
}


void show_all(struct Student* sts) {
    int i=0;
    system("clear");
    if(num_of_sts <= 0) {
        printf("No records available.\n");
    } else {
        printf("%-20s%-15s%-5s\n", "Name", "Roll no", "Faculty");
        while(i<num_of_sts)
        {
            printf("%-20s%-15s%-5s\n", sts->name, sts->roll, sts->faculty);
            i++;
            sts++;
        }
    }
    printf("press enter key to continue\n");
    getchar();  
}



void add(struct Student* sts) {
    int i=0;
    while(i<num_of_sts) {
        sts++;
        i++;
    }
    num_of_sts++;
    system("clear");
    printf("Enter students name: \n");
    // fgets(sts->name, 30, stdin);
    scanf("%[^\n]s", sts->name);
    getchar();

    printf("Enter students roll no: \n");
    // fgets(sts->roll, 10, stdin);
    scanf("%[^\n]s", sts->roll);
    getchar();
    printf("Enter students faculty: \n");
    // fgets(sts->faculty, 5, stdin);
    scanf("%[^\n]s", sts->faculty);
    getchar();
    printf("press enter key to continue\n");
    getchar(); 
}



void delete(struct Student* sts) {
    system("clear");
    printf("delete\n");
    printf("press enter key to continue\n");
    getchar(); 
}


void update(struct Student* sts) {
    system("clear");
    printf("update\n");
    printf("press enter key to continue\n");
    getchar(); 
}