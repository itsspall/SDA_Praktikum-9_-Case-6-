#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree tree; // Deklarasi tree
    int jumlahNode;
    char cariNode;
    infotype infoNode;

    // Inisialisasi tree kosong
    for (int i = 1; i <= jml_maks; i++) {
        tree[i].info = '\0';
        tree[i].ps_fs = nil;
        tree[i].ps_nb = nil;
        tree[i].ps_pr = nil;
    }

    printf("Masukkan jumlah node dalam tree: ");
    scanf("%d", &jumlahNode);

    if (jumlahNode > jml_maks) {
        printf("Jumlah node melebihi kapasitas maksimum (%d).\n", jml_maks);
        return 1;
    }

    // Membuat tree
    Create_tree(tree, jumlahNode);

    // Menampilkan tree dalam berbagai traversal
    printf("\nTraversal PreOrder: ");
    PreOrder(tree, 1);
    printf("\nTraversal InOrder: ");
    InOrder(tree, 1);
    printf("\nTraversal PostOrder: ");
    PostOrder(tree, 1);
    printf("\nTraversal Level Order: ");
    Level_order(tree, jumlahNode);
    printf("\n");

    // Mencetak jumlah elemen dan daun
    printf("\nJumlah elemen dalam tree: %d\n", nbElmt(tree));
    printf("Jumlah daun dalam tree: %d\n", nbDaun(tree));

    // Mencari node tertentu
    printf("\nMasukkan node yang ingin dicari: ");
    scanf(" %c", &cariNode);
    if (Search(tree, cariNode)) {
        printf("Node '%c' ditemukan di tree.\n", cariNode);
        printf("Level node '%c': %d\n", cariNode, Level(tree, cariNode));
    } else {
        printf("Node '%c' tidak ditemukan di tree.\n", cariNode);
    }

    // Menghitung kedalaman tree
    printf("\nKedalaman (tinggi) tree: %d\n", Depth(tree));

    return 0;
}