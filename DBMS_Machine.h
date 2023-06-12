/*
Saya Jason Suryoatmojo mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/* ----- [Global Variable] ----- */

extern int idx;
extern int wordlen;  
extern char cw[51];

/* ----- [Global Variable] ----- */

/* ----- [Word Machine Controls] ----- */

// Main controls, start and reset
void wm_start(char str[]);
void wm_reset();
// Index movement controls
void wm_next(char str[]);
// Word Machine Outputs
char* wm_getcw();
int wm_wordlen();
// Determine Status
int wm_end(char str[]);

/* ----- [Word Machine Controls] ----- */

/* ----- [Syntax Control] ----- */

int check_syntax(char str[]);

/* ----- [Syntax Control] ----- */
