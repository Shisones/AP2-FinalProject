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

int len(char str[]){
    int l = 0; int i = 0;
    while (str[i] != '\0'){
        i++; l++;
    }
    return l;
}

void swap_knife(knifeRecord data[], int a, int b){
    // Swaps two data using a temporary variable
    knifeRecord temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}
void sort_knife(knifeRecord data[]){
    // Sort by determining the maximum value on each array, decreasing the range of array that will be checked each time
    for (int i = 0; i < knifeCtr-1; i++){
        int max_idx = i; // Assume the current string is the maximum value
 
        for (int check = i+1; check < knifeCtr; check++){ // Loop to determine if the current string is actually the max value
            if (strcmp(data[check].company, data[max_idx].company) <= 0){
                max_idx = check; // Replace the max value with the currently-checked string if not
            }
        }

        // Swaps the value of the maximum value string with the current string, thus making it sort in a descending order
        char temp[50];
        swap_knife(data, i, max_idx);
    }

}
void swap_company(companyRecord data[], int a, int b){
    // Swaps two data using a temporary variable
    companyRecord temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}
void sort_company(companyRecord data[]){
    // Sort by determining the maximum value on each array, decreasing the range of array that will be checked each time
    for (int i = 0; i < companyCtr-1; i++){
        int max_idx = i; // Assume the current string is the maximum value
 
        for (int check = i+1; check < companyCtr; check++){ // Loop to determine if the current string is actually the max value
            if (strcmp(data[check].id, data[max_idx].id) <= 0){
                max_idx = check; // Replace the max value with the currently-checked string if not
            }
        }

        // Swaps the value of the maximum value string with the current string, thus making it sort in a descending order
        char temp[50];
        swap_company(data, i, max_idx);
    }

}
void swap_maker(makerRecord data[], int a, int b){
    // Swaps two data using a temporary variable
    makerRecord temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}
void sort_maker(makerRecord data[]){
    // Sort by determining the maximum value on each array, decreasing the range of array that will be checked each time
    for (int i = 0; i < makerCtr-1; i++){
        int max_idx = i; // Assume the current string is the maximum value
 
        for (int check = i+1; check < makerCtr; check++){ // Loop to determine if the current string is actually the max value
            if (strcmp(data[check].id, data[max_idx].id) <= 0){
                max_idx = check; // Replace the max value with the currently-checked string if not
            }
        }

        // Swaps the value of the maximum value string with the current string, thus making it sort in a descending order
        char temp[50];
        swap_maker(data, i, max_idx);
    }

}
void swap_steel(steelRecord data[], int a, int b){
    // Swaps two data using a temporary variable
    steelRecord temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}
void sort_steel(steelRecord data[]){
    // Sort by determining the maximum value on each array, decreasing the range of array that will be checked each time
    for (int i = 0; i < steelCtr-1; i++){
        int max_idx = i; // Assume the current string is the maximum value
 
        for (int check = i+1; check < steelCtr; check++){ // Loop to determine if the current string is actually the max value
            if (strcmp(data[check].id, data[max_idx].id) <= 0){
                max_idx = check; // Replace the max value with the currently-checked string if not
            }
        }

        // Swaps the value of the maximum value string with the current string, thus making it sort in a descending order
        char temp[50];
        swap_steel(data, i, max_idx);
    }

}

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
int search_companyName(companyRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].name, target) == 0) {
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
int search_makerName(makerRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].name, target) == 0) {
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
int search_steelName(steelRecord data[], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].name, target) == 0) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

// Update Constraint
int update_knifeCompany(knifeRecord data[], int n, char target[], char result[]) {
    int changed = 0;
    for (int i = 0; i < n; i++) { // Overwrite each and every one of the same name as target
        if (strcmp(data[i].company, target) == 0) {
            strcpy(data[i].company, result); // Overwrite target with result
            changed++;
        }
    }
    return changed; // Return the total number of changed record
}
int update_knifeMaker(knifeRecord data[], int n, char target[], char result[]) {
    int changed = 0;
    for (int i = 0; i < n; i++) { // Overwrite each and every one of the same name as target
        if (strcmp(data[i].maker, target) == 0) {
            strcpy(data[i].maker, result); // Overwrite target with result
            changed++;
        }
    }
    return changed; // Return the total number of changed record
}
int update_knifeSteel(knifeRecord data[], int n, char target[], char result[]) {
    int changed = 0;
    for (int i = 0; i < n; i++) { // Overwrite each and every one of the same name as target
        if (strcmp(data[i].steel, target) == 0) {
            strcpy(data[i].steel, result); // Overwrite target with result
            changed++;
        }
    }
    return changed; // Return the total number of changed record
}
// Delete Constraint
int restrict_knifeCompany(knifeRecord data[], int n, char target[]) {
    int i; // Check if knife.company has matching records
    while (i < knifeCtr){
        if (strcmp(data[i].company, target) == 0) return 1;
        i++;
    }
    return 0; // Return the total number of found record
}
int restrict_knifeMaker(knifeRecord data[], int n, char target[]) {
    int i; // Check if knife.maker has matching records
    while (i < knifeCtr){
        if (strcmp(data[i].maker, target) == 0) return 1;
        i++;
    }
    return 0; // Return the total number of found record
}
int restrict_knifeSteel(knifeRecord data[], int n, char target[]) {
    int i; // Check if knife.steel has matching records
    while (i < knifeCtr){
        if (strcmp(data[i].steel, target) == 0) return 1;
        i++;
    }
    return 0; // Return the total number of found record
}

/* ----- [Imported Functions] ----- */

/* ----- [File CRUD] ----- */

// Read R_Knife file and inputs it to knifeRecord
void read_knifeFile(int *idx, knifeRecord rec[], char file[]){
    FILE *file_knife; // Declare a file pointer
    file_knife = fopen(file, "r"); // Use read function on the file

    // Scan the first record of R_Knife
    fscanf(file_knife, "%s %s %s %s %s", rec[*idx].id, rec[*idx].name,  rec[*idx].company,rec[*idx].maker, rec[*idx].steel);

    // If the first record is null, tell the user
    if (strcmp(rec[*idx].id, "#####") == 0) printf("File Kosong!\n");
    else{ // Otherwise, read the records until null is met
        while (strcmp(rec[*idx].id, "#####") != 0){
            *idx = *idx + 1; 
            fscanf(file_knife, "%s %s %s %s %s", rec[*idx].id, rec[*idx].name,  rec[*idx].company,rec[*idx].maker, rec[*idx].steel);
        }
    }
    knifeCtr = *idx;
    fclose(file_knife);
}
void write_knifeFile(int knifeCtr, knifeRecord rec[], char file[]){
    FILE *file_knife; // Declare a file pointer
    file_knife = fopen(file, "w"); // Specify the pointer, and use the write mode
    // Loops through each laptop record
    for (int iK = 0; iK < knifeCtr; iK++){ // Inputs each rec of the knife record into the file
        fprintf(file_knife, "%s %s %s %s %s\n", rec[iK].id, rec[iK].name,  rec[iK].company,rec[iK].maker, rec[iK].steel);
    }
    fprintf(file_knife, "##### ##### ##### #####"); // Termination record
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
void write_companyFile(int companyCtr, companyRecord rec[], char file[]){
    FILE *file_company; // Declare a file pointer
    file_company = fopen(file, "w"); // Specify the pointer, and use the write mode
    // Loops through each laptop record
    for (int i = 0; i < companyCtr; i++){ // Inputs each rec of the company record into the file
        fprintf(file_company, "%s %s\n", rec[i].id, rec[i].name);
    }
    fprintf(file_company, "##### #####"); // Termination record
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
void write_makerFile(int makerCtr, makerRecord rec[], char file[]){
    FILE *file_maker; // Declare a file pointer
    file_maker = fopen(file, "w"); // Specify the pointer, and use the write mode
    // Loops through each laptop record
    for (int i = 0; i < makerCtr; i++){ // Inputs each rec of the maker record into the file
        fprintf(file_maker, "%s %s\n", rec[i].id, rec[i].name);
    }
    fprintf(file_maker, "##### #####"); // Termination record
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
void write_steelFile(int steelCtr, steelRecord rec[], char file[]){
    FILE *file_steel; // Declare a file pointer
    file_steel = fopen(file, "w"); // Specify the pointer, and use the write mode
    // Loops through each laptop record
    for (int i = 0; i < steelCtr; i++){ // Inputs each rec of the steel record into the file
        fprintf(file_steel, "%s %s\n", rec[i].id, rec[i].name);
    }
    fprintf(file_steel, "##### #####"); // Termination record
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
    printf(" -e, --err            Show error codes and what they mean (AP2 Final Project)\n");
    printf(" -s                   Save the current data into local storage (AP2 Final Project)\n");
    printf("\n");
    printf(" ----- Database Control (AP2 Final Project) ----- \n");
    printf("\n");
    printf(" Database Usage : [command] [table] [value1] [value2];\n");
    printf("\n");
    printf(" Command :\n");
    printf(" ISI, CREATE         Create a new record, values must be filled for all columns\n");
    printf(" TAMPIL, READ        Read a table of record\n");
    printf(" UBAH, UPDATE        Update an existing record (based on the id/first input)\n");
    printf(" HAPUS, DELETE       Delete an existing record (based on the id/first input)\n");
    printf("\n");
}
void dbms_logo(){
    printf("     __  ___              __                 ____   ____     \n");
    printf("    /  |/  /____ _ _____ / /__ ____  _   __ / __ \\ / __ )    Markov DB v.1.3\n");
    printf("   / /|_/ // __ `// ___// //_// __ \\| | / // / / // __  |    \n");
    printf("  / /  / // /_/ // /   /  ,< / /_/ /| |/ // /_/ // /_/ /     [-h] or [-help] for manual\n");
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
    printf(" - knife.id[25](char)\n - knife.name[50](char)\n - knife.company[50](char), foreign key(t_company)\n - knife.maker[50](char), foreign key(t_maker)\n - knife.steel[50](char), foreign key(t_steel)\n");
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
void dbms_error(){
    printf(" Error Report Message Explanation:\n");
    printf("\n");
    printf(" First digit represents the table (e.g. 1XXX represents an process in table t_knife)\n");
    printf(" Second digit represents the action (e.g. X3XX represents a updating process)\n");
    printf(" Third digit represents database-side error, this error can vary between function\n");
    printf(" Fourth digit represents user-side error, this error is usually an input error\n");
    printf(" A successful process is usually indicated by a code where the last two digits are 0, (e.g. XX00)\n");
    printf("\n");
    printf(" Extensive Report Code List: \n");
    printf("\n");
    printf(" - 1100: t_knife CREATE success\n");
    printf(" - 1110: t_knife CREATE failed: input id already existed\n");
    printf(" - 1120: t_knife CREATE failed: company input doesn't exist in t_company\n");
    printf(" - 1130: t_knife CREATE failed: maker input doesn't exist in t_maker\n");
    printf(" - 1140: t_knife CREATE failed: steel input doesn't exist in t_steel\n");
    printf(" - 1101: t_knife CREATE failed: input doesn't specify knife.id\n");
    printf(" - 1102: t_knife CREATE failed: input doesn't specify knife.name\n");
    printf(" - 1103: t_knife CREATE failed: input doesn't specify knife.company\n");
    printf(" - 1104: t_knife CREATE failed: input doesn't specify knife.maker\n");
    printf(" - 1105: t_knife CREATE failed: input doesn't specify knife.steel\n");
    printf(" - 1105: t_knife CREATE failed: input doesn't specify knife.steel\n");
    printf(" - 1105: t_knife CREATE failed: input doesn't specify knife.steel\n");
    printf(" - 1200: t_knife READ success\n");
    printf(" - 1210: t_knife READ failed: no records in t_knife\n");
    printf(" - 1300: t_knife UPDATE success\n");
    printf(" - 1310: t_knife UPDATE failed: input id doesn't exist\n");
    printf(" - 1330: t_knife UPDATE failed: company input doesn't exist in t_company\n");
    printf(" - 1340: t_knife UPDATE failed: maker input doesn't exist in t_maker\n");
    printf(" - 1350: t_knife UPDATE failed: steel input doesn't exist in t_steel\n");
    printf(" - 1301: t_knife UPDATE failed: input doesn't specify knife.id\n");
    printf(" - 1302: t_knife UPDATE failed: input doesn't specify knife.name\n");
    printf(" - 1303: t_knife UPDATE failed: input doesn't specify knife.company\n");
    printf(" - 1304: t_knife UPDATE failed: input doesn't specify knife.maker\n");
    printf(" - 1305: t_knife UPDATE failed: input doesn't specify knife.steel\n");
    printf(" - 1400: t_knife DELETE success\n");
    printf(" - 1410: t_knife DELETE failed: input id doesn't exist\n");
    printf(" - 1401: t_knife DELETE failed: input doesn't specify knife.id\n");
    printf("\n");
    printf(" - 2100: t_company CREATE success\n");
    printf(" - 2100: t_company CREATE success\n");
    printf(" - 2110: t_company CREATE failed: input id already existed\n");
    printf(" - 2101: t_company CREATE failed: input doesn't specify company.id\n");
    printf(" - 2102: t_company CREATE failed: input doesn't specify company.name\n");
    printf(" - 2200: t_company READ success\n");
    printf(" - 2210: t_company READ failed: no records in t_company\n");
    printf(" - 2300: t_company UPDATE success\n");
    printf(" - 2310: t_company UPDATE failed: input id doesn't exist\n");
    printf(" - 2301: t_company UPDATE failed: input doesn't specify company.id\n");
    printf(" - 2302: t_company UPDATE failed: input doesn't specify company.name\n");
    printf(" - 2400: t_company DELETE success\n");
    printf(" - 2410: t_company DELETE failed: input id doesn't exist\n");
    printf(" - 2420: t_company DELETE failed: constraint fail, input record is present on t_knife\n");
    printf(" - 2401: t_company DELETE failed: input doesn't specify company.id\n");
    printf("\n");
    printf(" - 3100: t_maker CREATE success\n");
    printf(" - 3110: t_maker CREATE failed: input id already existed\n");
    printf(" - 3101: t_maker CREATE failed: input doesn't specify company.id\n");
    printf(" - 3102: t_maker CREATE failed: input doesn't specify company.name\n");
    printf(" - 3200: t_maker READ success\n");
    printf(" - 3210: t_maker READ failed: no records in t_maker\n");
    printf(" - 3300: t_maker UPDATE success\n");
    printf(" - 3310: t_maker UPDATE failed: input id doesn't exist\n");
    printf(" - 3301: t_maker UPDATE failed: input doesn't specify company.id\n");
    printf(" - 3302: t_maker UPDATE failed: input doesn't specify company.name\n");
    printf(" - 3400: t_maker DELETE success\n");
    printf(" - 3410: t_maker DELETE failed: input id doesn't exist\n");
    printf(" - 3420: t_maker DELETE failed: constraint fail, input record is present on t_knife\n");
    printf(" - 3401: t_maker DELETE failed: input doesn't specify company.id\n");
    printf("\n");
    printf(" - 4100: t_steel CREATE success\n");
    printf(" - 4110: t_steel CREATE failed: input id already existed\n");
    printf(" - 4101: t_steel CREATE failed: input doesn't specify company.id\n");
    printf(" - 4102: t_steel CREATE failed: input doesn't specify company.name\n");
    printf(" - 4200: t_steel READ success\n");
    printf(" - 4210: t_steel READ failed: no records in t_steel\n");
    printf(" - 4300: t_steel UPDATE success\n");
    printf(" - 4310: t_steel UPDATE failed: input id doesn't exist\n");
    printf(" - 4301: t_steel UPDATE failed: input doesn't specify company.id\n");
    printf(" - 4302: t_steel UPDATE failed: input doesn't specify company.name\n");
    printf(" - 4400: t_steel DELETE success\n");
    printf(" - 4410: t_steel DELETE failed: input id doesn't exist\n");
    printf(" - 4420: t_steel DELETE failed: constraint fail, input record is present on t_knife\n");
    printf(" - 4401: t_steel DELETE failed: input doesn't specify company.id\n");
    printf("\n");



    
}
void dbms_errorshort(){
    printf(" Error Report Message Explanation:\n");
    printf("\n");
    printf(" First digit represents the table (e.g. 1XXX represents an process in table t_knife)\n");
    printf(" Second digit represents the action (e.g. X3XX represents a updating process)\n");
    printf(" Third digit represents database-side error, this error can vary between function\n");
    printf(" Fourth digit represents user-side error, this error is usually an input error\n");
    printf(" A successful process is usually indicated by a code where the last two digits are 0, (e.g. XX00)\n");
    printf("\n");
}
void dbms_save(knifeRecord knife[], companyRecord company[], makerRecord maker[], steelRecord steel[]){
    // Sort the struct, for a tidier record-keeping
    sort_knife(knife);
    sort_company(company);
    sort_maker(maker);
    sort_steel(steel);
    // Overwrite the R_Knife, R_Company, R_Maker, and R_Steel data with the new one
    write_knifeFile(knifeCtr, knife, "R_Knife.dat");
    write_companyFile(companyCtr, company, "R_Company.dat");
    write_makerFile(makerCtr, maker, "R_Maker.dat");
    write_steelFile(steelCtr, steel, "R_Steel.dat");
    // Return save report
    printf("[i] Data saved to local storage successfully\n");
}

/* ----- [DBMS Control] ----- */

/* ----- [Struct CRUD] ----- */

// Knife Table CRUD
int knife_create (knifeRecord knife[], char str[], companyRecord company[], makerRecord maker[], steelRecord steel[]){
    if (wm_end(str) == 1) return 1101; // If String ends abruptly, return 1101 (ID Not Provided)
    wm_next(str); // Point to ID

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
    int cf = search_companyName(company, companyCtr, wm_getcw());
    if (cf >= 0) strcpy(knife[knifeCtr].company, wm_getcw());
    else return 1130; // If yompany doesn't exist, return 1130 (company doesn't exist)

    wm_next(str); // Copy Maker
    if (wm_end(str) == 1) return 1105; // If String ends abruptly, return 1105 (Steel Not Provided)
    int mf = search_makerName(maker, makerCtr, wm_getcw());
    if (mf >= 0) strcpy(knife[knifeCtr].maker, wm_getcw());
    else return 1140; // If maker doesn't exist, return 1140 (maker doesn't exist)

    wm_next(str); // Copy Steel
    int sf = search_steelName(steel, steelCtr, wm_getcw());
    if (sf >= 0) strcpy(knife[knifeCtr].steel, wm_getcw());
    else return 1150; // If steel doesn't exist, return 1150 (steel doesn't exist)
        
    knifeCtr++; // Increment knife record
    return 1100; // Return 1100 (Insert Success);
}
int knife_read (knifeRecord knife[], char str[]){
    if (knifeCtr == 0) return 1210; // If table is empty, return 1210 (No record)

    sort_knife(knife); // Sort the record first
    printknife(knife); // Print the knife records

    return 1200; // Return 1200 (Read Success)
}
int knife_update (knifeRecord knife[], char str[], companyRecord company[], makerRecord maker[], steelRecord steel[]){
    if (wm_end(str) == 1) return 1301; // If String ends abruptly, return 1301 (ID Not Provided)
    wm_next(str); // Point to ID
    
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
    int cf = search_companyName(company, companyCtr, wm_getcw());
    if (cf >= 0) strcpy(knife[knifeCtr].company, wm_getcw());
    else return 1330; // If yompany doesn't exist, return 1330 (company doesn't exist)

    wm_next(str); // Copy Maker
    if (wm_end(str) == 1) return 1305; // If String ends abruptly, return 1305 (Steel Not Found)
    int mf = search_makerName(maker, makerCtr, wm_getcw());
    if (mf >= 0) strcpy(knife[knifeCtr].maker, wm_getcw());
    else return 1340; // If yompany doesn't exist, return 1340 (maker doesn't exist)  

    wm_next(str); // Copy Steel
    int sf = search_steelName(steel, steelCtr, wm_getcw());
    if (sf >= 0) strcpy(knife[knifeCtr].steel, wm_getcw());
    else return 1350; // If yompany doesn't exist, return 1330 (steel doesn't exist)   
        
    return 1300; // Return 1300 (Update Success);
}
int knife_delete (knifeRecord knife[], char str[]){
    if (wm_end(str) == 1) return 1401; // If String ends abruptly, return 1401 (ID Not Provided)
    wm_next(str); // Point to ID
    
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
    wm_next(str); // Point to ID
    
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
    
    sort_company(company); // Sort the record first
    printcompany(company); // Print the company records

    return 2200; // Return 2200 (Read Success)
}
int company_update (companyRecord company[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 2301; // If String ends abruptly, return 2301 (ID Not Found)
    wm_next(str);
    // Look for same id, if not found, immediately return a 2310 (Record Not Found)
    int found = search_companyID(company, companyCtr, wm_getcw());
    char before[50]; // Placeholder for the company name before changes
    if (found == -1) return 2310; // Return not found
    else strcpy(before, company[found].name); // Otherwise, fill 'before'

    if (wm_end(str) == 1) return 2302; // If String ends abruptly, return 2302 (Name Not Found)
    
    int changed = 0;
    wm_next(str); // Copy Name
        strcpy(company[found].name, wm_getcw());
    changed = update_knifeCompany(knife, knifeCtr, before, wm_getcw());
    
    if (changed > 0) return changed;
    return 2300; // Return 2300 (Update Success);
}
int company_delete (companyRecord company[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 2401; // If String ends abruptly, return 2401 (ID Not Provided)
    wm_next(str); // Point to ID
    
    // Look for same id, if not found, immediately return 2410 (Record Not Found)
    int found = search_companyID(company, companyCtr, wm_getcw());
    char check[50]; // Placeholder for the company name
    if (found == -1) return 2410;
    else strcpy(check, company[found].name); // Otherwise, fill 'check'

    // If company is present in 't_knife', restrict delete
    if (restrict_knifeCompany(knife, knifeCtr, check) == 1) return 2420;

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
    wm_next(str); // Point to ID
    
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
    
    sort_maker(maker); // Sort the record first
    printmaker(maker); // Print the maker records

    return 3200; // Return 3200 (Read Success)
}
int maker_update (makerRecord maker[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 3301; // If String ends abruptly, return 3301 (ID Not Found)
    wm_next(str);
    // Look for same id, if not found, immediately return a 3310 (Record Not Found)
    int found = search_makerID(maker, makerCtr, wm_getcw());
    char before[50]; // Placeholder for the maker name before changes
    if (found == -1) return 3310; // Return not found
    else strcpy(before, maker[found].name); // Otherwise, fill 'before'

    if (wm_end(str) == 1) return 3302; // If String ends abruptly, return 3302 (Name Not Found)
    
    int changed = 0;
    wm_next(str); // Copy Name
        strcpy(maker[found].name, wm_getcw());
    changed = update_knifeMaker(knife, knifeCtr, before, wm_getcw());
    
    if (changed > 0) return changed;
    return 3300; // Return 3300 (Update Success);
}
int maker_delete (makerRecord maker[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 3401; // If String ends abruptly, return 3401 (ID Not Provided)
    wm_next(str); // Point to ID
    
    // Look for same id, if not found, immediately return 3410 (Record Not Found)
    int found = search_makerID(maker, makerCtr, wm_getcw());
    char check[50]; // Placeholder for the maker name
    if (found == -1) return 3410;
    else strcpy(check, maker[found].name); // Otherwise, fill 'check'

    // If maker is present in 't_knife', restrict delete
    if (restrict_knifeMaker(knife, knifeCtr, check) == 1) return 3420;

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
    wm_next(str); // Point to ID
    
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
    
    sort_steel(steel); // Sort the record first
    printsteel(steel); // Print the steel records

    return 4200; // Return 4200 (Read Success)
}
int steel_update (steelRecord steel[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 4301; // If String ends abruptly, return 4301 (ID Not Found)
    wm_next(str);
    // Look for same id, if not found, immediately return a 4310 (Record Not Found)
    int found = search_steelID(steel, steelCtr, wm_getcw());
    char before[50]; // Placeholder for the steel name before changes
    if (found == -1) return 4310; // Return not found
    else strcpy(before, steel[found].name); // Otherwise, fill 'before'

    if (wm_end(str) == 1) return 4302; // If String ends abruptly, return 4302 (Name Not Found)
    
    int changed = 0;
    wm_next(str); // Copy Name
        strcpy(steel[found].name, wm_getcw());
    changed = update_knifeSteel(knife, knifeCtr, before, wm_getcw());
    
    if (changed > 0) return changed;
    return 4300; // Return 4300 (Update Success);
}
int steel_delete (steelRecord steel[], char str[], knifeRecord knife[]){
    if (wm_end(str) == 1) return 4401; // If String ends abruptly, return 4401 (ID Not Provided)
    wm_next(str); // Point to ID
    
    // Look for same id, if not found, immediately return 4410 (Record Not Found)
    int found = search_steelID(steel, steelCtr, wm_getcw());
    char check[50]; // Placeholder for the steel name
    if (found == -1) return 4410;
    else strcpy(check, steel[found].name); // Otherwise, fill 'check'

    // If steel is present in 't_knife', restrict delete
    if (restrict_knifeSteel(knife, knifeCtr, check) == 1) return 4420;

    // Push the record out and terminate the last record
    for (int i = found; i < steelCtr; i++){
        steel[i] = steel[i+1];
    }
    steelCtr--; // Decrement total record
    return 4400; // Return 4400 (Delete Success)
}

/* ----- [Struct CRUD] ----- */

void printknife(knifeRecord knife[]){
    // Maximum Length of variables
    int idMax = 0; int nameMax = 0;
    int companyMax = 0; int makerMax = 0; int steelMax = 0;

    // Determine the longest record of each column
    for (int i = 0; i < knifeCtr; i++){ // Loop over every record
        if (len(knife[i].id) > idMax) idMax = len(knife[i].id);
        if (len(knife[i].name) > nameMax) nameMax = len(knife[i].name);
        if (len(knife[i].company) > companyMax) companyMax = len(knife[i].company);
        if (len(knife[i].maker) > makerMax) makerMax = len(knife[i].maker);
        if (len(knife[i].steel) > steelMax) steelMax = len(knife[i].steel);
    }

    int idSpc = (idMax > 8) ? idMax + 2 : 10; // Dynamize the id space, based on "Knife ID"
    int nameSpc = (nameMax > 4) ? nameMax + 2 : 6; // Dynamize the name space, based on "Name"
    int companySpc = (companyMax > 7) ? companyMax + 2 : 9; // Dynamize the company space, based on "Company"
    int makerSpc = (makerMax > 14) ? makerMax + 2 : 16; // Dynamize the maker space, based on "Maker/Designer"
    int steelSpc = (steelMax > 5) ? steelMax + 2 : 7; // Dynamize the steel space, based on "Steel"

    // This is for table, yeah, it's absolutely disgusting, i know.. but i understand this more than HTML/CSS
    for (int i = 0; i < idSpc+nameSpc+companySpc+makerSpc+steelSpc + 6; i++){
        printf("~");
    }printf("\n");
    printf("| Knife ID ");
    for (int s = 0; s < idSpc-10; s++){ printf(" "); }
    printf("| Name ");
    for (int s = 0; s < nameSpc-6; s++){ printf(" "); }
    printf("| Company ");
    for (int s = 0; s < companySpc-9; s++){ printf(" "); }
    printf("| Maker/Designer ");
    for (int s = 0; s < makerSpc-16; s++){ printf(" "); }
    printf("| Steel ");
    for (int s = 0; s < steelSpc-7; s++){ printf(" "); }
    printf("|\n");
    for (int i = 0; i < idSpc+nameSpc+companySpc+makerSpc+steelSpc + 6; i++){
        printf("~");
    }printf("\n");
    // Print the actual record
    for (int r = 0; r < knifeCtr; r++){
        printf("| %s ", knife[r].id);
        for (int s = 0; s < idSpc-len(knife[r].id)-2;s++){ printf(" "); }
        printf("| %s ", knife[r].name);
        for (int s = 0; s < nameSpc-len(knife[r].name)-2;s++){ printf(" "); }
        printf("| %s ", knife[r].company);
        for (int s = 0; s < companySpc-len(knife[r].company)-2;s++){ printf(" "); }
        printf("| %s ", knife[r].maker);
        for (int s = 0; s < makerSpc-len(knife[r].maker)-2;s++){ printf(" "); }
        printf("| %s ", knife[r].steel);
        for (int s = 0; s < steelSpc-len(knife[r].steel)-2;s++){ printf(" "); }
        printf("|\n");
    }
    for (int i = 0; i < idSpc+nameSpc+companySpc+makerSpc+steelSpc + 6; i++){
        printf("~");
    }printf("\n");
}
void printcompany(companyRecord company[]){
    // Maximum Length of variables
    int idMax = 0; int nameMax = 0;

    // Determine the longest record of each column
    for (int i = 0; i < companyCtr; i++){ // Loop over every record
        if (len(company[i].id) > idMax) idMax = len(company[i].id);
        if (len(company[i].name) > nameMax) nameMax = len(company[i].name);
    }

    int idSpc = (idMax > 10) ? idMax + 2 : 12; // Dynamize the id space, based on "Company ID"
    int nameSpc = (nameMax > 4) ? nameMax + 2 : 6; // Dynamize the name space, based on "Name"

    // This is for table, yeah, it's absolutely disgusting, i know.. but i understand this more than HTML/CSS
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    printf("| Company ID ");
    for (int s = 0; s < idSpc-12; s++){ printf(" "); }
    printf("| Name ");
    for (int s = 0; s < nameSpc-6; s++){ printf(" "); }
    printf("|\n");
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    // Print the actual record
    for (int r = 0; r < companyCtr; r++){
        printf("| %s ", company[r].id);
        for (int s = 0; s < idSpc-len(company[r].id)-2;s++){ printf(" "); }
        printf("| %s ", company[r].name);
        for (int s = 0; s < nameSpc-len(company[r].name)-2;s++){ printf(" "); }
        printf("|\n");
    }
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
}
void printmaker(makerRecord maker[]){
    // Maximum Length of variables
    int idMax = 0; int nameMax = 0;

    // Determine the longest record of each column
    for (int i = 0; i < makerCtr; i++){ // Loop over every record
        if (len(maker[i].id) > idMax) idMax = len(maker[i].id);
        if (len(maker[i].name) > nameMax) nameMax = len(maker[i].name);
    }

    int idSpc = (idMax > 8) ? idMax + 2 : 10; // Dynamize the id space, based on "Maker ID"
    int nameSpc = (nameMax > 4) ? nameMax + 2 : 6; // Dynamize the name space, based on "Name"

    // This is for table, yeah, it's absolutely disgusting, i know.. but i understand this more than HTML/CSS
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    printf("| Maker ID ");
    for (int s = 0; s < idSpc-10; s++){ printf(" "); }
    printf("| Name ");
    for (int s = 0; s < nameSpc-6; s++){ printf(" "); }
    printf("|\n");
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    // Print the actual record
    for (int r = 0; r < makerCtr; r++){
        printf("| %s ", maker[r].id);
        for (int s = 0; s < idSpc-len(maker[r].id)-2;s++){ printf(" "); }
        printf("| %s ", maker[r].name);
        for (int s = 0; s < nameSpc-len(maker[r].name)-2;s++){ printf(" "); }
        printf("|\n");
    }
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
}
void printsteel(steelRecord steel[]){
    // Maximum Length of variables
    int idMax = 0; int nameMax = 0;

    // Determine the longest record of each column
    for (int i = 0; i < steelCtr; i++){ // Loop over every record
        if (len(steel[i].id) > idMax) idMax = len(steel[i].id);
        if (len(steel[i].name) > nameMax) nameMax = len(steel[i].name);
    }

    int idSpc = (idMax > 8) ? idMax + 2 : 10; // Dynamize the id space, based on "Steel ID"
    int nameSpc = (nameMax > 4) ? nameMax + 2 : 6; // Dynamize the name space, based on "Name"

    // This is for table, yeah, it's absolutely disgusting, i know.. but i understand this more than HTML/CSS
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    printf("| Steel ID ");
    for (int s = 0; s < idSpc-10; s++){ printf(" "); }
    printf("| Name ");
    for (int s = 0; s < nameSpc-6; s++){ printf(" "); }
    printf("|\n");
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
    // Print the actual record
    for (int r = 0; r < steelCtr; r++){
        printf("| %s ", steel[r].id);
        for (int s = 0; s < idSpc-len(steel[r].id)-2;s++){ printf(" "); }
        printf("| %s ", steel[r].name);
        for (int s = 0; s < nameSpc-len(steel[r].name)-2;s++){ printf(" "); }
        printf("|\n");
    }
    for (int i = 0; i < idSpc+nameSpc+3; i++){
        printf("~");
    }printf("\n");
}


