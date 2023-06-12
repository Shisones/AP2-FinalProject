/*
Saya Jason Suryoatmojo mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "DBMS_Header.h"
#include "DBMS_Machine.h"

// Macro because why not
#define q strcmp(str, "-q") == 0
#define quit strcmp(str, "--quit") == 0

int main(){
    /* Phase 1. Transfer File Data to Array of Structs */

    int kIdx = 0; // Declare index for knife
    knifeRecord knife[100]; // Declare the data for knife
    read_knifeFile(&kIdx, knife, "R_Knife.dat"); // Read the data for knife

    int cIdx = 0; // Declare index for company
    companyRecord company[100]; // Declare the data for company
    read_companyFile(&cIdx, company, "R_Company.dat"); // Read the data for knife
    
    int mIdx = 0; // Declare index for maker
    makerRecord maker[100]; // Declare the data for maker
    read_makerFile(&mIdx, maker, "R_Maker.dat"); // Read the data for knife

    int sIdx = 0; // Declare index for steel
    steelRecord steel[100]; // Declare the data for steel
    read_steelFile(&sIdx, steel, "R_Steel.dat"); // Read the data for knife

    /* Phase 2. Word Machine Initialization */

    char str[201]; // Declare input variable
    dbms_logo(); // Print Initial DBMS Intro

    while (!(q || quit)){ // Loops as long as the input isn't '-q' or '--quit'
        printf("MarkovDB (db_knives)> "); // Input pre-text
        scanf(" %200[^\n]s", &str); // Scan for input

        int report = 0; // Variable for output code
        if (check_syntax(str) == 0){ // DBMS Control Commands

            if (strcmp(str, "-h") == 0 || strcmp(str, "--help") == 0) dbms_help(); // Used for -h
            else if (strcmp(str, "-i") == 0) dbms_info(); // Used for -i
            else if (!(q || quit)) printf("[!] ERROR : DBMS Command \"%s\" not found!\n    use -h to list all available commands\n", str);
        }else if (check_syntax(str) == 1){ // DBMS Record Commands
            wm_start(str); // Start the word machine

            if (strcmp(wm_getcw(), "ISI") == 0 || strcmp(wm_getcw(), "CREATE") == 0){ // CREATE Commands
                wm_next(str); // Increment to [table]

                if (strcmp(wm_getcw(), "t_knife") == 0){ // If the table is t_knife

                    report = knife_create(knife, str, company, maker, steel); // Insert record and get report value
                    // Code below is self explanatory
                    if (report == 1100) printf("[%d]: Record successfully created\n", report);
                    else if (report == 1110) printf("[%d]: Record creation failed : Record with id %s exists\n", report, wm_getcw());
                    else if (report == 1101) printf("[%d]: Input is missing column 'knife.id'\n", report);
                    else if (report == 1102) printf("[%d]: Input is missing column 'knife.name'\n", report);
                    else if (report == 1103) printf("[%d]: Input is missing column 'knife.company'\n", report);
                    else if (report == 1104) printf("[%d]: Input is missing column 'knife.maker'\n", report);
                    else if (report == 1105) printf("[%d]: Input is missing column 'knife.steel'\n", report);
                    else if (report == 1130) printf("[%d]: Company '%s' Doesn't exist in t_company\n        Please add the company beforehand\n", report, wm_getcw());
                    else if (report == 1140) printf("[%d]: Maker '%s' Doesn't exist in t_maker\n        Please add the maker beforehand\n", report, wm_getcw());
                    else if (report == 1150) printf("[%d]: Steel '%s' Doesn't exist in t_steel\n        Please add the steel beforehand\n", report, wm_getcw());
                }
                else if (strcmp(wm_getcw(), "t_company") == 0){ // If the table is t_company

                    report = company_create(company, str); // Insert record and get report value
                    // Code below is self explanatory
                    if (report == 2100) printf("[%d]: Record successfully created\n", report);
                    else if (report == 2110) printf("[%d]: Record creation failed : Record with id %s exists\n", report, wm_getcw());
                    else if (report == 2101) printf("[%d]: Record missing column 'company.id'\n", report);
                    else if (report == 2102) printf("[%d]: Record missing column 'company.name'\n", report);
                    else if (report == 2103) printf("[%d]: Record missing column 'knife.company'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_maker") == 0){ // If the table is t_maker
                    
                    report = maker_create(maker, str); // Insert record and get report value
                    // Code below is self explanatory
                    if (report == 3100) printf("[%d]: Record successfully created\n", report);
                    else if (report == 3110) printf("[%d]: Record creation failed : Record with id %s exists\n", report, wm_getcw());
                    else if (report == 3101) printf("[%d]: Record missing column 'maker.id'\n", report);
                    else if (report == 3102) printf("[%d]: Record missing column 'maker.name'\n", report);
                    else if (report == 3103) printf("[%d]: Record missing column 'knife.maker'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_steel") == 0){ // If the table is t_steel
                    
                    report = steel_create(steel, str); // Insert record and get report value
                    // Code below is self explanatory
                    if (report == 4100) printf("[%d]: Record successfully created\n", report);
                    else if (report == 4110) printf("[%d]: Record creation failed : Record with id %s exists\n", report, wm_getcw());
                    else if (report == 4101) printf("[%d]: Record missing column 'steel.id'\n", report);
                    else if (report == 4102) printf("[%d]: Record missing column 'steel.name'\n", report);
                    else if (report == 4103) printf("[%d]: Record missing column 'knife.steel'\n", report);
                }else printf("[!] ERROR : Table '%s' doesn't exist\n", wm_getcw());
            }
            else if (strcmp(wm_getcw(), "TAMPIL") == 0 || strcmp(wm_getcw(), "READ") == 0){ // READ Commands
                wm_next(str); // Increment to [table]
                if (strcmp(wm_getcw(), "t_knife") == 0){ // If the table is t_knife
                    
                    report = knife_read(knife, str); // Read the table and provide report
                    // Code below is self explanatory
                    if (report == 1200) printf("[%d]: %d Record shown\n", report, knifeCtr);
                    if (report == 1210) printf("[%d]: Table 't_knife' is empty\n", report);
                }
                else if (strcmp(wm_getcw(), "t_company") == 0){ // If the table is t_company
                    
                    report = company_read(company, str); // Read the table and provide report
                    // Code below is self explanatory
                    if (report == 2200) printf("[%d]: %d Record shown\n", report, companyCtr);
                    if (report == 2210) printf("[%d]: Table 't_company' is empty\n", report);
                }
                else if (strcmp(wm_getcw(), "t_maker") == 0){ // If the table is t_maker
                    
                    report = maker_read(maker, str); // Read the table and provide report
                    // Code below is self explanatory
                    if (report == 3200) printf("[%d]: %d Record shown\n", report, makerCtr);
                    if (report == 3210) printf("[%d]: Table 't_maker' is empty\n", report);
                }
                else if (strcmp(wm_getcw(), "t_steel") == 0){ // If the table is t_steel
                    
                    report = steel_read(steel, str); // Read the table and provide report
                    // Code below is self explanatory
                    if (report == 4200) printf("[%d]: %d Record shown\n", report, steelCtr);
                    if (report == 4210) printf("[%d]: Table 't_steel' is empty\n", report);
                }else printf("[!] ERROR : Table '%s' doesn't exist\n", wm_getcw());
            }
            else if (strcmp(wm_getcw(), "UBAH") == 0 || strcmp(wm_getcw(), "UPDATE") == 0){ // UPDATE Commands
                wm_next(str); // Increment to [table]

                if (strcmp(wm_getcw(), "t_knife") == 0){ // If the table is t_knife
                    
                    report = knife_update(knife, str, company, maker, steel); // Update record and get report value
                    // Code below is self explanatory
                    if (report == 1300) printf("[%d]: Record successfully updated\n", report);
                    else if (report == 1310) printf("[%d]: Record update failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 1301) printf("[%d]: Input is missing column 'knife.id'\n", report);
                    else if (report == 1302) printf("[%d]: Input is missing column 'knife.name'\n", report);
                    else if (report == 1303) printf("[%d]: Input is missing column 'knife.company'\n", report);
                    else if (report == 1304) printf("[%d]: Input is missing column 'knife.maker'\n", report);
                    else if (report == 1305) printf("[%d]: Input is missing column 'knife.steel'\n", report);
                    else if (report == 1330) printf("[%d]: Company '%s' Doesn't exist in t_company\n        Please add the company beforehand\n", report, wm_getcw());
                    else if (report == 1340) printf("[%d]: Maker '%s' Doesn't exist in t_maker\n        Please add the maker beforehand\n", report, wm_getcw());
                    else if (report == 1350) printf("[%d]: Steel '%s' Doesn't exist in t_steel\n        Please add the steel beforehand\n", report, wm_getcw());
                }
                else if (strcmp(wm_getcw(), "t_company") == 0){ // If the table is t_company
                    
                    report = company_update(company, str, knife); // Update record and get report value
                    // Code below is self explanatory
                    if (report == 2300) printf("[%d]: Record successfully updated\n", report);
                    else if (report <= knifeCtr) printf("[2300]: Record successfully updated\n        %d records also updated in 't_knife'\n", report);
                    else if (report == 2310) printf("[%d]: Record update failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 2301) printf("[%d]: Input is missing column 'company.id'\n", report);
                    else if (report == 2302) printf("[%d]: Input is missing column 'company.name'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_maker") == 0){ // If the table is t_maker
                    
                    report = maker_update(maker, str, knife); // Update record and get report value
                    // Code below is self explanatory
                    if (report == 3300) printf("[%d]: Record successfully updated\n", report);
                    else if (report <= knifeCtr) printf("[3300]: Record successfully updated\n        %d records also updated in 't_knife'\n", report);
                    else if (report == 3310) printf("[%d]: Record update failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 3301) printf("[%d]: Input is missing column 'maker.id'\n", report);
                    else if (report == 3302) printf("[%d]: Input is missing column 'maker.name'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_steel") == 0){ // If the table is t_steel
                    
                    report = steel_update(steel, str, knife); // Update record and get report value
                    // Code below is self explanatory
                    if (report == 4300) printf("[%d]: Record successfully updated\n", report);
                    else if (report <= knifeCtr) printf("[4300]: Record successfully updated\n        %d records also updated in 't_knife'\n", report);
                    else if (report == 4310) printf("[%d]: Record update failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 4301) printf("[%d]: Input is missing column 'steel.id'\n", report);
                    else if (report == 4302) printf("[%d]: Input is missing column 'steel.name'\n", report);
                }else printf("[!] ERROR : Table '%s' doesn't exist\n", wm_getcw());
            }
            else if (strcmp(wm_getcw(), "HAPUS") == 0 || strcmp(wm_getcw(), "DELETE") == 0){
                wm_next(str); // Increment to [table]

                if (strcmp(wm_getcw(), "t_knife") == 0){ // If the table is 't_knife'
                    
                    report = knife_delete(knife, str); // Delete Record and retrieve input
                    // Code below is self explanatory
                    if (report == 1400) printf("[%d]: Record successfully deleted\n", report);
                    else if (report == 1410) printf("[%d]: Record delete failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 1401) printf("[%d]: Input is missing column 'knife.id'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_company") == 0){ // If the table is 't_company'
                    
                    report = company_delete(company, str, knife); // Delete Record and retrieve input
                    // Code below is self explanatory
                    if (report == 2400) printf("[%d]: Record successfully deleted\n", report);
                    else if (report == 2410) printf("[%d]: Record delete failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 2420) printf("[%d]: Constraint Failed: Record exists in 't_knife'\n        Please delete the linked record in 't_knife' before deleting this record\n", report);
                    else if (report == 2401) printf("[%d]: Input is missing column 'company.id'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_maker") == 0){ // If the table is 't_maker'
                    
                    report = maker_delete(maker, str, knife); // Delete Record and retrieve input
                    // Code below is self explanatory
                    if (report == 3400) printf("[%d]: Record successfully deleted\n", report);
                    else if (report == 3410) printf("[%d]: Record delete failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 3420) printf("[%d]: Constraint Failed: Record exists in 't_knife'\n        Please delete the linked record in 't_knife' before deleting this record\n", report);
                    else if (report == 3401) printf("[%d]: Input is missing column 'maker.id'\n", report);
                }
                else if (strcmp(wm_getcw(), "t_steel") == 0){ // If the table is 't_steel'
                    
                    report = steel_delete(steel, str, knife); // Delete Record and retrieve input
                    // Code below is self explanatory
                    if (report == 4400) printf("[%d]: Record successfully deleted\n", report);
                    else if (report == 4410) printf("[%d]: Record delete failed : Record with id %s doesn't exist\n", report, wm_getcw());
                    else if (report == 4420) printf("[%d]: Constraint Failed: Record exists in 't_knife'\n        Please delete the linked record in 't_knife' before deleting this record\n", report);
                    else if (report == 4401) printf("[%d]: Input is missing column 'steel.id'\n", report);
                }else printf("[!] ERROR : Table '%s' doesn't exist\n", wm_getcw());
            }

        // Syntax Error Handling (ignore -q or --quit)
        }else if (!(q || quit) && check_syntax(str) == -1) printf("[!] ERROR : Invalid Syntax\n    missing semicolon(;) or dash(-)\n");
    }

    write_knifeFile(knifeCtr, knife, "R_Knife.dat");
    write_companyFile(companyCtr, company, "R_Company.dat");
    write_makerFile(makerCtr, maker, "R_Maker.dat");
    write_steelFile(steelCtr, steel, "R_Steel.dat");

    return 0;
}