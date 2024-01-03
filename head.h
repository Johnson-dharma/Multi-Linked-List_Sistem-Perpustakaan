#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

struct visitor {
    string nama, gender, keanggotaan;
};

struct buku {
    string judul, tipe;
    int kesediaanAwal, kesediaan;
};

typedef struct visitor infotype_visitor;
typedef struct buku infotype_buku;
typedef struct elm_visitor *adr_visitor;
typedef struct elm_buku *adr_buku;
typedef struct elm_relasi *adr_relasi;


struct List_visitor {
    adr_visitor first;
    adr_visitor last;
};

struct List_buku {
    adr_buku first;
    adr_buku last;
};

struct List_relasi{
    adr_relasi first;
    adr_relasi last;
};

struct elm_visitor {
    infotype_visitor info;
    adr_visitor next;
    adr_visitor prev;
    adr_relasi book;
};

struct elm_buku {
    infotype_buku info;
    adr_buku next;
    adr_buku prev;
};

struct elm_relasi {
    adr_buku info;
    adr_relasi next;
    adr_relasi prev;
};

void mainMenu(List_visitor &v, List_buku &b, List_relasi &r);
void menuInsert(List_visitor &v, List_buku &b, List_relasi &r);
void menuDelete(List_visitor &v, List_buku &b, List_relasi &r);
void menuUpdate(List_visitor &v, List_buku &b, List_relasi &r);
void menuShow(List_visitor &v, List_buku &b, List_relasi &r);
void menu5();

//Procedure visitor
void createListVisitor(List_visitor &v);
adr_visitor createElemenVisitor(infotype_visitor p);
void insertVisitor(List_visitor &v, adr_visitor p);
void deleteFirstVisitor(List_visitor &v, adr_visitor &p);
void deleteLastVisitor(List_visitor &v, adr_visitor &p);
void deleteAfterVisitor(List_visitor &v, adr_visitor &p, adr_visitor x);
adr_visitor searchVisitor(List_visitor v, string nama);
void penentuDeleteVisitor(List_visitor &v, adr_visitor &p);


//Procedure buku
void createListBuku(List_buku &b);
adr_buku createElemenBuku(infotype_buku p);
void insertBuku(List_buku &b, adr_buku p);
void deleteFirstBuku(List_buku &b, adr_buku &p);
void deleteLastBuku(List_buku &b, adr_buku &p);
void deleteAfterBuku(List_buku &b, adr_buku &p, adr_buku x);
void penentuDeleteBuku(List_buku &b, adr_buku &p);


//Procedure relasi
void createListRelasi(List_relasi &r);
adr_relasi createElemenRelasi(adr_buku p);
void insertRelasi(List_relasi &r, adr_relasi p, adr_visitor &v);
void deleteFirstRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v);
void deleteLastRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v);
void deleteAfterRelasi(List_relasi &r, adr_relasi &p, adr_relasi x, adr_visitor &v);
void penentuDeleteRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v);

//==============================================================================================
bool isAvailable(List_buku b, string judul);
bool isBookExist(List_buku b, string judul);
bool isVisitorExist(List_visitor v, string nama);
adr_visitor findVisitor(List_visitor v, string nama);
adr_buku findBook(List_buku b, string judul);
adr_relasi findRelation(adr_visitor adr_v, List_relasi r, adr_buku adr_b);
int hitungPinjam(List_visitor v, List_relasi r, string nama);
void buatRelasi(List_visitor &v, List_buku &b, List_relasi &r);
bool stillCanBorrow(int x, string tipe);

//Procedure Delete
void hapusVisitor(List_visitor &v, List_relasi &r);
void hapusAllRelation(adr_visitor &adr_v, List_relasi &r, int x);
void hapusBuku(List_buku &b, List_relasi &r);
void hapusRelasi(List_visitor &v, List_buku &b, List_relasi &r);

//Procedure update
void updateVisitor(List_visitor &v);
void updateBooks(List_buku &b);

//Procedure Show
void allVisitor(List_visitor v);
void allBooks(List_buku b);
void allBorrower(List_visitor v, List_relasi r);
void oneVisitor(List_visitor v, List_relasi r);
void oneBook(List_visitor v, List_buku b, List_relasi r);
void category(List_buku b);

#endif // HEAD_H_INCLUDED
