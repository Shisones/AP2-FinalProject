/*
Saya Jason Suryoatmojo mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>

/* ----- [Global Variable] ----- */

extern int knifeCtr; // Counter for knives
extern int makerCtr; // Counter for makers
extern int companyCtr; // Counter for companies
extern int steelCtr; // Counter for steels

/* ----- [Global Variable] ----- */

/* ----- [Structure for Tables] ----- */

// Knife Table
typedef struct knifeRecord{
    char id[25];
    char name[50];
    char company[50];
    char maker[50];
    char steel[50];
}knifeRecord;
// Maker Table
typedef struct makerRecord{
    char id[25];
    char name[50];
}makerRecord;
// Company Table
typedef struct companyRecord{
    char id[25];
    char name[50];
}companyRecord;
// Steel Table
typedef struct steelRecord{
    char id[25];
    char name[50];
}steelRecord;

/* ----- [Structure for Tables] ----- */

/* ----- [Imported Function Header] ----- */

int len(char str[]); // CAN'T USE STRLEN? MAKE MY OWN LMAO

// Sorting Functions
void swap_knife(knifeRecord data[], int a, int b);
void sort_knife(knifeRecord data[]);
void swap_company(companyRecord data[], int a, int b);
void sort_company(companyRecord data[]);
void swap_maker(makerRecord data[], int a, int b);
void sort_maker(makerRecord data[]);
void swap_steel(steelRecord data[], int a, int b);
void sort_steel(steelRecord data[]);

// Searching Function
int search_knifeID(knifeRecord data[], int n, char target[]);
int search_companyID(companyRecord data[], int n, char target[]);
int search_companyName(companyRecord data[], int n, char target[]);
int search_makerID(makerRecord data[], int n, char target[]);
int search_makerName(makerRecord data[], int n, char target[]);
int search_steelID(steelRecord data[], int n, char target[]);
int search_steelName(steelRecord data[], int n, char target[]);
// Update Constraint = Update Other Records
int update_knifeCompany(knifeRecord data[], int n, char target[], char result[]);
int update_knifeMaker(knifeRecord data[], int n, char target[], char result[]);
int update_knifeSteel(knifeRecord data[], int n, char target[], char result[]);
// Delete Constraint = Restrict Deletion
int restrict_knifeCompany(knifeRecord data[], int n, char target[]);
int restrict_knifeMaker(knifeRecord data[], int n, char target[]);
int restrict_knifeSteel(knifeRecord data[], int n, char target[]);

/* ----- [Imported Function Header] ----- */

/* ----- [File CRUD] ----- */

// Record Reading
void read_knifeFile(int *idx, knifeRecord rec[], char file[]);
void write_knifeFile(int knifeCtr, knifeRecord rec[], char file[]);

void read_companyFile(int *idx, companyRecord rec[], char file[]);
void write_companyFile(int companyCtr, companyRecord rec[], char file[]);

void read_makerFile(int *idx, makerRecord rec[], char file[]);
void write_makerFile(int makerCtr, makerRecord rec[], char file[]);

void read_steelFile(int *idx, steelRecord rec[], char file[]);
void write_steelFile(int steelCtr, steelRecord rec[], char file[]);

/* ----- [File CRUD] ----- */

/* ----- [DBMS Control] ----- */

void dbms_logo(); // Shows initial logo
void dbms_help(); // Shows help 
void dbms_info(); // Shows database management system information
void dbms_error(); // Shows report code and error messages
void dbms_errorshort(); // Shows report code 
void dbms_save(knifeRecord knife[], companyRecord company[], makerRecord maker[], steelRecord steel[]); // Save record to local storage
void dbms_quit();

/* ----- [DBMS Control] ----- */

/* ----- [Struct CRUD] ----- */

// Knife CRUD
int knife_create (knifeRecord knife[], char str[], companyRecord company[], makerRecord maker[], steelRecord steel[]);
int knife_read (knifeRecord knife[], char str[]);
int knife_update (knifeRecord knife[], char str[], companyRecord company[], makerRecord maker[], steelRecord steel[]);
int knife_delete (knifeRecord knife[], char str[]);
// Company CRUD
int company_create (companyRecord company[], char str[]);
int company_read (companyRecord company[], char str[]);
int company_update (companyRecord company[], char str[], knifeRecord knife[]);
int company_delete (companyRecord company[], char str[], knifeRecord knife[]);
// Maker CRUD
int maker_create (makerRecord maker[], char str[]);
int maker_read (makerRecord maker[], char str[]);
int maker_update (makerRecord maker[], char str[], knifeRecord knife[]);
int maker_delete (makerRecord maker[], char str[], knifeRecord knife[]);
// Steel CRUD
int steel_create (steelRecord steel[], char str[]);
int steel_read (steelRecord steel[], char str[]);
int steel_update (steelRecord steel[], char str[], knifeRecord knife[]);
int steel_delete (steelRecord steel[], char str[], knifeRecord knife[]);

/* ----- [Struct CRUD] ----- */

void printknife(knifeRecord knife[]);
void printcompany(companyRecord company[]);
void printmaker(makerRecord maker[]);
void printsteel(steelRecord steel[]);
