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
    char company[50];
    char name[50];
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

// Searching Func
int search_knifeID(knifeRecord data[], int n, char target[]);
int search_companyID(companyRecord data[], int n, char target[]);
int search_makerID(makerRecord data[], int n, char target[]);
int search_steelID(steelRecord data[], int n, char target[]);

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

/* ----- [DBMS Control] ----- */

/* ----- [Struct CRUD] ----- */

// Knife CRUD
int knife_create (knifeRecord knife[], char str[]);
int knife_read (knifeRecord knife[], char str[]);
int knife_update (knifeRecord knife[], char str[]);
int knife_delete (knifeRecord knife[], char str[]);
// Company CRUD
int company_create (companyRecord company[], char str[]);
int company_read (companyRecord company[], char str[]);
int company_update (companyRecord company[], char str[]);
int company_delete (companyRecord company[], char str[]);
// Maker CRUD
int maker_create (makerRecord maker[], char str[]);
int maker_read (makerRecord maker[], char str[]);
int maker_update (makerRecord maker[], char str[]);
int maker_delete (makerRecord maker[], char str[]);
// Steel CRUD
int steel_create (steelRecord steel[], char str[]);
int steel_read (steelRecord steel[], char str[]);
int steel_update (steelRecord steel[], char str[]);
int steel_delete (steelRecord steel[], char str[]);

/* ----- [Struct CRUD] ----- */
