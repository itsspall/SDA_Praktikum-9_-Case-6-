#ifndef nbtrees_h
#define nbtrees_h
#include "boolean.h"

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

/***************************/
/* Type data */
/***************************/
/* Indeks dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */
/* Kamus */
typedef char infotype;
typedef int address;
typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;
typedef nbtree Isi_Tree[jml_maks+1];

/***************************/
/* Deklarasi Fungsi */
/***************************/
void Create_tree(Isi_Tree X, int Jml_Node);
boolean IsEmpty(Isi_Tree P);
void PreOrder(Isi_Tree P, int idx);
void InOrder(Isi_Tree P, int idx);
void PostOrder(Isi_Tree P, int idx);
void Level_order(Isi_Tree X, int Maks_node);
void PrintTree(Isi_Tree P);
boolean Search(Isi_Tree P, infotype X);
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(infotype Data1, infotype Data2);

#endif