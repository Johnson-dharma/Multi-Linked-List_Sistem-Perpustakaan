#include "head.h"
#include <iostream>
using namespace std;

int main() {
    List_visitor v;
    List_buku b;
    List_relasi r;

    createListVisitor(v);
    createListBuku(b);
    createListRelasi(r);

    infotype_visitor p;
    p.nama = "john"; p.gender = "laki"; p.keanggotaan = "member";
    adr_visitor x = createElemenVisitor(p);
    insertVisitor(v, x);

    p.nama = "bob"; p.gender = "laki"; p.keanggotaan = "non";
    x = createElemenVisitor(p);
    insertVisitor(v, x);

    p.nama = "ziyah"; p.gender = "perempuan"; p.keanggotaan = "member";
    x = createElemenVisitor(p);
    insertVisitor(v, x);

    p.nama = "al"; p.gender = "laki"; p.keanggotaan = "non";
    x = createElemenVisitor(p);
    insertVisitor(v, x);

    p.nama = "raya"; p.gender = "laki"; p.keanggotaan = "non";
    x = createElemenVisitor(p);
    insertVisitor(v, x);

    //=================================================================================

    adr_buku z;
    infotype_buku a;
    a.judul = "dune"; a.tipe = "adventure"; a.kesediaanAwal = 3; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    a.judul = "kamu"; a.tipe = "romance"; a.kesediaanAwal = 2; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    a.judul = "brave"; a.tipe = "action"; a.kesediaanAwal = 5; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    a.judul = "divergent"; a.tipe = "action"; a.kesediaanAwal = 1; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    a.judul = "aku"; a.tipe = "romance"; a.kesediaanAwal = 3; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    a.judul = "mine"; a.tipe = "romance"; a.kesediaanAwal = 3; a.kesediaan = a.kesediaanAwal;
    z = createElemenBuku(a);
    insertBuku(b, z);

    //============================================================================================
    adr_relasi adr_r;

    x = findVisitor(v, "john");
    z = findBook(b, "dune");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "bob");
    z = findBook(b, "dune");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "john");
    z = findBook(b, "kamu");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "bob");
    z = findBook(b, "divergent");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "john");
    z = findBook(b, "brave");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "ziyah");
    z = findBook(b, "aku");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "ziyah");
    z = findBook(b, "kamu");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "al");
    z = findBook(b, "mine");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "al");
    z = findBook(b, "brave");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "raya");
    z = findBook(b, "mine");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    mainMenu(v, b, r);

    /*
    adr_buku adr_b = r.last->info;
    cout << adr_b->info.judul;
    */
    return 0;
}
