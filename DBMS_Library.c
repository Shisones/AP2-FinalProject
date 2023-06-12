/*
Saya Jason Suryoatmojo mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "DBMS_Header.h"
#include "DBMS_Machine.h"

/* ----- [Counter Variables] ----- */

int knifeCtr = 0; // Counter for knives
int makerCtr = 0; // Counter for makers
int companyCtr = 0; // Counter for companies
int steelCtr = 0; // Counter for steels

/* ----- [Counter Variables] ----- */

/* ----- [Imported Functions] ----- */

int search_knifeID(knifeRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].id, target) == 0) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}
int search_companyID(companyRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].id, target) == 0) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}
int search_makerID(makerRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].id, target) == 0) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}
int search_steelID(steelRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].id, target) == 0) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

/* ----- [Imported Functions] ----- */

/* ----- [File CRUD] ----- */

// Read R_Knife file and inputs it to knifeRecord
void read_knifeFile(int *idx, knifeRecord rec[], char file[]){
    FILE *file_knife; // Declare a file pointer
    file_knife = fopen(file, "r"); // Use read function on the file

    // Scan the first record of R_Knife
    fscanf(file_knife, "%s %s %s %s %s", rec[*idx].id, rec[*idx].company, rec[*idx].name, rec[*idx].maker, rec[*idx].steel);

    // If the first record is null, tell the user
    if (strcmp(rec[*idx].id, "#####") == 0) printf("File Kosong!\n");
    else{ // Otherwise, read the records until null is met
        while (strcmp(rec[*idx].id, "#####") != 0){
            *idx = *idx + 1; 
            fscanf(file_knife, "%s %s %s %s %s", rec[*idx].id, rec[*idx].company, rec[*idx].name, rec[*idx].maker, rec[*idx].steel);
        }
    }
    knifeCtr = *idx;
    fclose(file_knife);
}
// Read R_Company file and inputs it to companyRecord
void read_companyFile(int *idx, companyRecord rec[], char file[]){
    FILE *file_company; // Declare a file pointer
    file_company = fopen(file, "r"); // Use read function on the file

    // Scan the first record of R_Company
    fscanf(file_company, "%s %s", rec[*idx].id, rec[*idx].name);
    
    // If the first record is null, tell the user
    if (strcmp(rec[*idx].id, "#####") == 0) printf("File Kosong!\n");
    else{ // Otherwise, read the records until null is met
        while (strcmp(rec[*idx].id, "#####") != 0){
            *idx = *idx + 1; 
            fscanf(file_company, "%s %s", rec[*idx].id, rec[*idx].name);
        }
    }
    companyCtr = *idx;
    fclose(file_company);
}
// Read R_Maker file and inputs it to makerRecord
void read_makerFile(int *idx, makerRecord rec[], char file[]){
    FILE *file_maker; // Declare a file pointer
    file_maker = fopen(file, "r"); // Use read function on the file

    // Scan the first record of R_Maker
    fscanf(file_maker, "%s %s", rec[*idx].id, rec[*idx].name);

    // If the first record is null, tell the user
    if (strcmp(rec[*idx].id, "#####") == 0) printf("File Kosong!\n");
    else{ // Otherwise, read the records until null is met
        while (strcmp(rec[*idx].id, "#####") != 0){
            *idx = *idx + 1; 
            fscanf(file_maker, "%s %s", rec[*idx].id, rec[*idx].name);
        }
    }
    makerCtr = *idx;
    fclose(file_maker);
}
// Read R_Steel file and inputs it to steelRecord
void read_steelFile(int *idx, steelRecord rec[], char file[]){
    FILE *file_steel; // Declare a file pointer
    file_steel = fopen(file, "r"); // Use read function on the file

    // Scan the first record of R_Steel
    fscanf(file_steel, "%s %s", rec[*idx].id, rec[*idx].name);

    // If the first record is null, tell the user
    if (strcmp(rec[*idx].id, "#####") == 0) printf("File Kosong!\n");
    else{ // Otherwise, read the records until null is met
        while (strcmp(rec[*idx].id, "#####") != 0){
            *idx = *idx + 1; 
            fscanf(file_steel, "%s %s", rec[*idx].id, rec[*idx].name);
        }
    }
    steelCtr = *idx;
    fclose(file_steel);
}

/* ----- [File CRUD] ----- */

/* ----- [DBMS Control] ----- */

void dbms_help(){
    printf(" Usage : [options]\n");
    printf("\n");
    printf(" Options :\n");
    printf(" -h, --help           Show basic help message\n");
    printf(" -q, --quit           Quit program\n");
    printf(" -i                   Show information of the db_knives database (AP2 Final Project)\n");
    printf(" -err                 Show error codes and what they mean (AP2 Final Project)\n");
    printf("\n");
    printf(" ----- Database Control (AP2 Final Project) ----- \n");
    printf("\n");
    printf(" Database Usage : [command] [table] [value1] [value2];\n");
    printf("\n");
    printf(" Command :\n");
    printf(" BUAT, CREATE         Create a new record, values must be filled for all columns\n");
    printf(" BACA, READ           Read a table of record\n");
    printf(" PERBARUI, UPDATE     Update an existing record (based on the id/first input)\n");
    printf(" HAPUS, DELETE        Delete an existing record (based on the id/first input)\n");
    printf("\n");
}
void dbms_logo(){
    printf("     __  ___              __                 ____   ____     \n");
    printf("    /  |/  /____ _ _____ / /__ ____  _   __ / __ \\ / __ )    Markov DB v.0.4\n");
    printf("   / /|_/ // __ `// ___// //_// __ \\| | / // / / // __  |    \n");
    printf("  / /  / // /_/ // /   / ,<  / /_/ /| |/ // /_/ // /_/ /     [-h] or [-help] for manual\n");
    printf(" /_/  /_/ \\__,_//_/   /_/|_| \\____/ |___//_____//_____/      [-q] or [--quit] to exit\n");
    printf("                                                             \n");
    printf("[*] Created by Jason Suryoatmojo (2204524) \n");
    printf("[!] This database management system is made specifically to fulfill \n");
    printf("    the score requirement for Algorithm and Programming II subject \n");
    printf("    in Indonesia's University of Education, Computer Science Major \n");
    printf("    any other use is Prohibited. \n");
    printf("\n");
}
void dbms_info(){
    printf(" Table Structure and Information \n");
    printf("\n");
    printf(" Knife Table (t_knife) : 5 Columns\n");
    printf(" - knife.id[25](char)\n - knife.company[50](char)\n - knife.name[50](char)\n - knife.maker[50](char)\n - knife.steel[50](char)\n");
    printf("\n");
    printf(" Company Table (t_company) : 2 Columns\n");
    printf(" - company.id[25](char)\n - company.name[50](char)\n");
    printf("\n");
    printf(" Maker Table (t_maker) : 2 Columns\n");
    printf(" - maker.id[25](char)\n - maker.name[50](char)\n");
    printf("\n");
    printf(" Steel Table (t_steel) : 2 Columns\n");
    printf(" - steel.id[25](char)\n - steel.name[50](char)\n");
    printf("\n");
}

/* ----- [DBMS Control] ----- */

/* ----- [Struct CRUD] ----- */

// Knife Table CRUD
int knife_create (knifeRecord knife[], char str[]){
    if (wm_end(str) == 1) return 1101; // If String ends abruptly, return 1101 (ID Not Provided)

    // Look for same id, if found, immediately return a 1110 (Record Already Exist)
    int found = search_knifeID(knife, knifeCtr, wm_getcw());
    if (found >= 0) return 1110;
    // Copy ID
    if (wm_end(str) == 1) return 1102; // If String ends abruptly, return 1102 (Name Not Provided)
        strcpy(knife[knifeCtr].id, wm_getcw());
    wm_next(str); // Copy Name
    if (wm_end(str) == 1) return 1103; // If String ends abruptly, return 1103 (Company Not Provided)
        strcpy(knife[knifeCtr].name, wm_getcw());
    wm_next(str); // Copy Company
    if (wm_end(str) == 1) return 1104; // If String ends abruptly, return 1104 (Maker Not Provided)
        strcpy(knife[knifeCtr].company, wm_getcw());
    wm_next(str); // Copy Maker
    if (wm_end(str) == 1) return 1105; // If String ends abruptly, return 1105 (Steel Not Provided)
        strcpy(knife[knifeCtr].maker, wm_getcw());
    wm_next(str); // Copy Steel
        strcpy(knife[knifeCtr].steel, wm_getcw());
        
    knifeCtr++; // Increment knife record
    return 1100; // Return 1100 (Insert Success);
}
int knife_read (knifeRecord knife[], char str[]){
    if (knifeCtr == 0) return 1210; // If table is empty, return 1210 (No record)
    for (int i = 0; i < knifeCtr; i++){
        printf("%s %s %s %s %s\n", knife[i].id, knife[i].name, knife[i].company, knife[i].maker, knife[i].steel);
    }
    return 1200; // Return 1200 (Read Success)
}
int knife_update (knifeRecord knife[], char str[]){
    if (wm_end(str) == 1) return 1301; // If String ends abruptly, return 1301 (ID Not Found)
    
    // Look for same id, if not found, immediately return a 1310 (Record Not Found)
    int found = search_knifeID(knife, knifeCtr, wm_getcw());
    if (found == -1) return 1310;
    // Copy ID
    if (wm_end(str) == 1) return 1302; // If String ends abruptly, return 1302 (Name Not Found)
        strcpy(knife[found].id, wm_getcw());
    wm_next(str); // Copy Name
    if (wm_end(str) == 1) return 1303; // If String ends abruptly, return 1303 (Company Not Found)
        strcpy(knife[found].name, wm_getcw());
    wm_next(str); // Copy Company
    if (wm_end(str) == 1) return 1304; // If String ends abruptly, return 1304 (Maker Not Found)
        strcpy(knife[found].company, wm_getcw());
    wm_next(str); // Copy Maker
    if (wm_end(str) == 1) return 1305; // If String ends abruptly, return 1305 (Steel Not Found)
        strcpy(knife[found].maker, wm_getcw());
    wm_next(str); // Copy Steel
        strcpy(knife[found].steel, wm_getcw());
        
    return 1300; // Return 1300 (Update Success);
}
int knife_delete (knifeRecord knife[], char str[]){
    if (wm_end(str) == 1) return 1401; // If String ends abruptly, return 1401 (ID Not Found)

    // Look for same id, if not found, immediately return 1410 (Record Not Found)
    int found = search_knifeID(knife, knifeCtr, wm_getcw());
    if (found == -1) return 1410;
    // Push the record out and terminate the last record
    for (int i = found; i < knifeCtr; i++){
        knife[i] = knife[i+1];
    }
    knifeCtr--; // Decrement total record
    return 1400; // Return 1400 (Delete Success)
}
// Company Table CRUD
int company_create(companyRecord company[], char str[]){
    if (wm_end(str) == 1) return 2101; // If String ends abruptly, return 2101 (ID Not Provided)
    
    // Look for same id, if found, immediately return a 2110 (Record Already Exist)
    int found = search_companyID(company, companyCtr, wm_getcw());
    if (found >= 0) return 2110;
    // Copy ID
    if (wm_end(str) == 1) return 2102; // If String ends abruptly, return 2102 (Name Not Provided)
        strcpy(company[companyCtr].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(company[companyCtr].name, wm_getcw());
        
    companyCtr++; // Increment company record
    return 2100; // Return 2100 (Insert Success);
}
int company_read (companyRecord company[], char str[]){
    if (companyCtr == 0) return 2210; // If table is empty, return 2210 (No record)
    for (int i = 0; i < companyCtr; i++){
        printf("%s %s\n", company[i].id, company[i].name);
    }
    return 2200; // Return 2200 (Read Success)
}
int company_update (companyRecord company[], char str[]){
    if (wm_end(str) == 1) return 2301; // If String ends abruptly, return 2301 (ID Not Found)
    
    // Look for same id, if not found, immediately return a 2310 (Record Not Found)
    int found = search_companyID(company, companyCtr, wm_getcw());
    if (found == -1) return 2310;
    // Copy ID
    if (wm_end(str) == 1) return 2302; // If String ends abruptly, return 2302 (Name Not Found)
        strcpy(company[found].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(company[found].name, wm_getcw());
        
    return 2300; // Return 2300 (Update Success);
}
int company_delete (companyRecord company[], char str[]){
    if (wm_end(str) == 1) return 2401; // If String ends abruptly, return 2401 (ID Not Found)

    // Look for same id, if not found, immediately return 2410 (Record Not Found)
    int found = search_companyID(company, companyCtr, wm_getcw());
    if (found == -1) return 2410;
    // Push the record out and terminate the last record
    for (int i = found; i < companyCtr; i++){
        company[i] = company[i+1];
    }
    companyCtr--; // Decrement total record
    return 2400; // Return 2400 (Delete Success)
    
}
// Maker Table CRUD
int maker_create(makerRecord maker[], char str[]){
    if (wm_end(str) == 1) return 3101; // If String ends abruptly, return 3101 (ID Not Provided)
    
    // Look for same id, if found, immediately return a 2110 (Record Already Exist)
    int found = search_makerID(maker, makerCtr, wm_getcw());
    if (found >= 0) return 3110;
    // Copy ID
    if (wm_end(str) == 1) return 3102; // If String ends abruptly, return 3102 (Name Not Provided)
        strcpy(maker[makerCtr].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(maker[makerCtr].name, wm_getcw());
        
    makerCtr++; // Increment maker record
    return 3100; // Return 3100 (Insert Success);
}
int maker_read (makerRecord maker[], char str[]){
    if (makerCtr == 0) return 3210; // If table is empty, return 3210 (No record)
    for (int i = 0; i < makerCtr; i++){
        printf("%s %s\n", maker[i].id, maker[i].name);
    }
    return 3200; // Return 3200 (Read Success)
}
int maker_update (makerRecord maker[], char str[]){
    if (wm_end(str) == 1) return 3301; // If String ends abruptly, return 3301 (ID Not Found)
    
    // Look for same id, if not found, immediately return a 2310 (Record Not Found)
    int found = search_makerID(maker, makerCtr, wm_getcw());
    if (found == -1) return 3310;
    // Copy ID
    if (wm_end(str) == 1) return 3302; // If String ends abruptly, return 3302 (Name Not Found)
        strcpy(maker[found].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(maker[found].name, wm_getcw());
        
    return 3300; // Return 3300 (Update Success);
}
int maker_delete (makerRecord maker[], char str[]){
    if (wm_end(str) == 1) return 3401; // If String ends abruptly, return 3401 (ID Not Found)

    // Look for same id, if not found, immediately return 3410 (Record Not Found)
    int found = search_makerID(maker, makerCtr, wm_getcw());
    if (found == -1) return 3410;
    // Push the record out and terminate the last record
    for (int i = found; i < makerCtr; i++){
        maker[i] = maker[i+1];
    }
    makerCtr--; // Decrement total record
    return 3400; // Return 3400 (Delete Success)
    
}
// Steel Table CRUD
int steel_create(steelRecord steel[], char str[]){
    if (wm_end(str) == 1) return 4101; // If String ends abruptly, return 4101 (ID Not Provided)
    
    // Look for same id, if found, immediately return a 2110 (Record Already Exist)
    int found = search_steelID(steel, steelCtr, wm_getcw());
    if (found >= 0) return 4110;
    // Copy ID
    if (wm_end(str) == 1) return 4102; // If String ends abruptly, return 4102 (Name Not Provided)
        strcpy(steel[steelCtr].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(steel[steelCtr].name, wm_getcw());
        
    steelCtr++; // Increment steel record
    return 4100; // Return 4100 (Insert Success);
}
int steel_read (steelRecord steel[], char str[]){
    if (steelCtr == 0) return 4210; // If table is empty, return 4210 (No record)
    for (int i = 0; i < steelCtr; i++){
        printf("%s %s\n", steel[i].id, steel[i].name);
    }
    return 4200; // Return 4200 (Read Success)
}
int steel_update (steelRecord steel[], char str[]){
    if (wm_end(str) == 1) return 4301; // If String ends abruptly, return 4301 (ID Not Found)
    
    // Look for same id, if not found, immediately return a 2310 (Record Not Found)
    int found = search_steelID(steel, steelCtr, wm_getcw());
    if (found == -1) return 4310;
    // Copy ID
    if (wm_end(str) == 1) return 4302; // If String ends abruptly, return 4302 (Name Not Found)
        strcpy(steel[found].id, wm_getcw());
    wm_next(str); // Copy Name
        strcpy(steel[found].name, wm_getcw());
        
    return 4300; // Return 4300 (Update Success);
}
int steel_delete (steelRecord steel[], char str[]){
    if (wm_end(str) == 1) return 4401; // If String ends abruptly, return 4401 (ID Not Found)

    // Look for same id, if not found, immediately return 4410 (Record Not Found)
    int found = search_steelID(steel, steelCtr, wm_getcw());
    if (found == -1) return 4410;
    // Push the record out and terminate the last record
    for (int i = found; i < steelCtr; i++){
        steel[i] = steel[i+1];
    }
    steelCtr--; // Decrement total record
    return 4400; // Return 4400 (Delete Success)
    
}

/* ----- [Struct CRUD] ----- */


