/*
Saya Jason Suryoatmojo mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "DBMS_Machine.h"

int idx;
int wlen;
char cw[51];

/* ----- [Word Machine Controls] ----- */

// Start the machine
void wm_start(char str[]){
    idx = 0; // Set the index to 0, pointing to the 1st index of the str
    wlen = 0; // Set the wordlength to 0, as a starting point 

    while (str[idx] == ' ') { idx++; }// Move the index until it reaches the first non-space character

    while ((str[idx] != ' ') && (wm_end(str) == 0)){ // Loops as long as no space is encountered, and eop is false
        cw[wlen] = str[idx]; // Assign each character from the string to current word
        wlen++;
        idx++;
    }

    cw[wlen] = '\0'; // Finishes the current word string by marking the last char as null
}
// Resets the current word
void wm_reset(){
    wlen = 0; // Set the length as 0
    cw[wlen] = '\0'; // Immediately terminates the current word, making it a null string
}
// Mark the End-of-Process
int wm_end(char str[]){
    // Check for delimiter
    if (str[idx] == ';') return 1;
    else return 0;
}
// Increment the index so it points to the next word
void wm_next(char str[]){
    wlen = 0; // Set the current word length to 0, same as refreshing it

    while (str[idx] == ' ') idx++; // Move the index until it reaches the first non-space character
    while ((str[idx] != ' ') && (wm_end(str) == 0)){ // Loops as long as no space is encountered, and eop is false
        cw[wlen] = str[idx]; // Assign each character from the string to current word
        wlen++;
        idx++;
    }

    cw[wlen] = '\0'; // Finishes the current word string by marking the last char as null
}
// Returns specific outputs
int wm_wordlen(){ return wlen; } // Returns current word length
char* wm_getcw(){ return cw; } // Returns current word

/* ----- [Word Machine Controls] ----- */

int check_syntax(char str[]){
    int x = 0; int i = 0;
    if (str[0] == '-') return 0;

    while (i < 200 && str[i] != '\0'){
        if (str[i] == ';') return 1;
        i++;
    }

    return -1;   
}
