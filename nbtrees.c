#include <stdio.h>
#include <stdbool.h>
#include "nbtrees.h"

/***************************/
/* I M P L E M E N T A S I */
/***************************/

void Create_tree(Isi_Tree X, int Jml_Node) {
    // IS: X belum terdefinisi
    // FS: X terdefinisi dengan Jml_Node elemen dalam pola Level Order
    for (int i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info untuk node %d: ", i);
        scanf(" %c", &X[i].info); // Input info untuk node
        printf("Masukkan fs (first son) untuk node %d (0 jika tidak ada): ", i);
        scanf("%d", &X[i].ps_fs); // Input first son
        printf("Masukkan nb (next brother) untuk node %d (0 jika tidak ada): ", i);
        scanf("%d", &X[i].ps_nb); // Input next brother
        printf("Masukkan pr (parent) untuk node %d (0 jika tidak ada): ", i);
        scanf("%d", &X[i].ps_pr); // Input parent
    }
}

boolean IsEmpty(Isi_Tree P) {
    // IS: P terdefinisi
    // FS: Mengembalikan true jika P kosong
    return P[1].info == '\0'; // Jika elemen pertama kosong, maka tree kosong
}

void PreOrder(Isi_Tree P, int idx) {
    // IS: P terdefinisi
    // FS: Semua simpul P ditampilkan secara PreOrder
    if (idx != nil) {
        printf("%c ", P[idx].info); // Tampilkan parent
        PreOrder(P, P[idx].ps_fs); // Kunjungi first son
        PreOrder(P, P[idx].ps_nb); // Kunjungi next brother
    }
}

void InOrder(Isi_Tree P, int idx) {
    // IS: P terdefinisi
    // FS: Semua simpul P ditampilkan secara InOrder
    if (idx != nil) {
        InOrder(P, P[idx].ps_fs);  // Kunjungi first son
        printf("%c ", P[idx].info); // Tampilkan parent
        InOrder(P, P[idx].ps_nb);  // Kunjungi next brother
    }
}

void PostOrder(Isi_Tree P, int idx) {
    // IS: P terdefinisi
    // FS: Semua simpul P ditampilkan secara PostOrder
    if (idx != nil) {
        PostOrder(P, P[idx].ps_fs); // Kunjungi first son
        PostOrder(P, P[idx].ps_nb); // Kunjungi next brother
        printf("%c ", P[idx].info); // Tampilkan parent
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    // IS: X terdefinisi
    // FS: Semua simpul X ditampilkan secara Level Order
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') {
            printf("%c ", X[i].info);
        }
    }
}

void PrintTree(Isi_Tree P) {
    // IS: P terdefinisi
    // FS: Semua simpul P ditulis ke layar
    printf("Tree elements (PreOrder): ");
    PreOrder(P, 1);
    printf("\n");
}

boolean Search(Isi_Tree P, infotype X) {
    // IS: P terdefinisi
    // FS: Mengembalikan true jika ada node dengan nilai X
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    // IS: P terdefinisi
    // FS: Mengembalikan banyak elemen dalam pohon
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    // IS: P terdefinisi
    // FS: Mengembalikan banyak daun dalam pohon
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    // IS: P terdefinisi
    // FS: Mengembalikan level dari node X
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1; // Jika X tidak ditemukan
}

int Depth(Isi_Tree P) {
    // IS: P terdefinisi
    // FS: Mengembalikan tinggi pohon
    int maxDepth = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int depth = 0;
            int parent = P[i].ps_pr;
            while (parent != nil) {
                depth++;
                parent = P[parent].ps_pr;
            }
            if (depth > maxDepth) maxDepth = depth;
        }
    }
    return maxDepth;
}

int Max(infotype Data1, infotype Data2) {
    // IS: Data1 dan Data2 terdefinisi
    // FS: Mengembalikan nilai terbesar dari dua data
    return (Data1 > Data2) ? Data1 : Data2;
}