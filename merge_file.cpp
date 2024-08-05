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


void mainMenu(List_visitor &v, List_buku &b, List_relasi &r){
    int menu;
    cout << "-------------------MAIN MENU-------------------" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tampil Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Pilih Menu: "; cin >> menu;

    if (menu == 1){
        menuInsert(v, b, r);
    }else if (menu == 2){
        menuDelete(v, b, r);
    }else if (menu == 3){
        menuUpdate(v, b, r);
    }else if (menu == 4){
        menuShow(v, b, r);
    }else{
        menu5();
    }
}

void menuInsert(List_visitor &v, List_buku &b, List_relasi &r){
    int menu;
    cout << "-------------------MENU INSERT-------------------" << endl;
    cout << "1. Tambah Visitor" << endl;
    cout << "2. Tambah Buku" << endl;
    cout << "3. Tambah Peminjaman " << endl;
    cout << "4. Back" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Pilih Menu: "; cin >> menu;


    adr_visitor adr_v;
    infotype_visitor info_v;

    adr_buku adr_b;
    infotype_buku info_b;

    if (menu == 1){//insert visitor
        cout << "Masukan nama visitor: "; cin >> info_v.nama;
        cout << "Masukan gender: "; cin >> info_v.gender;
        cout << "Masukan keanggotaan: "; cin >> info_v.keanggotaan;
        adr_v = createElemenVisitor(info_v);
        insertVisitor(v, adr_v);
        cout << endl; cout << "Data berhasil diinput" << endl;
        menuInsert(v, b, r);
    }else if (menu == 2){//insert buku
        cout << "Masukan judul buku: "; cin >> info_b.judul;
        if (isBookExist(b, info_b.judul) == true){
            cout << "Judul buku sudah ada" << endl;
            menuInsert(v, b, r);
        }else{
            cout << endl; cout << "Masukan tipe buku: "; cin >> info_b.tipe;
            cout << endl; cout << "Masukan kesediaan: "; cin >> info_b.kesediaanAwal;
            info_b.kesediaan = info_b.kesediaanAwal;
            adr_b = createElemenBuku(info_b);
            insertBuku(b, adr_b);
            cout << endl; cout << "Data berhasil diinput" << endl;
            menuInsert(v, b, r);
        }
    }else if (menu == 3){//insert relasi
        buatRelasi(v, b, r);
        menuInsert(v, b, r);
    }else{
        mainMenu(v, b, r);
    }
}

void menuDelete(List_visitor &v, List_buku &b, List_relasi &r){
    int menu;
    cout << "----------------------MENU DELETE------------------" << endl;
    cout << "1. Hapus visitor" << endl;
    cout << "2. Hapus buku" << endl;
    cout << "3. Hapus peminjaman" << endl;
    cout << "4. Back" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Pilih Menu: "; cin >> menu;

    if (menu == 1){
        hapusVisitor(v, r);
        menuDelete(v, b, r);
    }else if (menu == 2){
        hapusBuku(b, r);
        menuDelete(v, b, r);
    }else if (menu == 3){
        hapusRelasi(v, b, r);
        menuDelete(v, b, r);
    }else{
        mainMenu(v, b, r);
    }
}

void menuUpdate(List_visitor &v, List_buku &b, List_relasi &r){
    int menu;
    cout << "-----------------------MENU UPDATE--------------------" << endl;
    cout << "1. Update Data Visitor" << endl;
    cout << "2. Update Data Buku" << endl;
    cout << "3. Back" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Pilih Menu: "; cin >> menu;

    if (menu == 1){
        updateVisitor(v);
        menuUpdate(v, b, r);
    }else if (menu == 2){
        updateBooks(b);
        menuUpdate(v, b, r);
    }else{
        mainMenu(v, b, r);
    }

}

void menuShow(List_visitor &v, List_buku &b, List_relasi &r){
    int menu;
    cout << "------------------------MENU SHOW-----------------------" << endl;
    cout << "1. Semua Data Visitor" << endl;
    cout << "2. Semua Data Buku" << endl;
    cout << "3. Semua Data Peminjam" << endl;
    cout << "4. Data Visitor Tertentu" << endl;
    cout << "5. Data Buku Tertentu" << endl;
    cout << "6. Book by category" << endl;
    cout << "7. Back" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Pilih Menu: "; cin >> menu;

    if (menu == 1){
        allVisitor(v);
        menuShow(v, b, r);
    }else if (menu == 2){
        allBooks(b);
        menuShow(v, b, r);
    }else if (menu == 3){
        allBorrower(v, r);
        menuShow(v, b, r);
    }else if (menu == 4){
        oneVisitor(v, r);
        menuShow(v, b, r);
    }else if (menu == 5){
        oneBook(v, b, r);
        menuShow(v, b, r);
    }else if (menu == 6){
        category(b);
        menuShow(v, b, r);
    }else{
        mainMenu(v, b, r);
    }
}

void menu5(){
    cout << endl; cout << "Terima Kasih :) " << endl;
    cout << "Made by Johnson, Maziyah, and Akmal" << endl;
}

//=============================================================================================

void createListVisitor(List_visitor &v){
    v.first = NULL;
    v.last = NULL;
}

adr_visitor createElemenVisitor(infotype_visitor p){
    adr_visitor New = new elm_visitor;
    New->info.nama = p.nama;
    New->info.gender = p.gender;
    New->info.keanggotaan = p.keanggotaan;
    New->book = NULL;
    New->next = NULL;
    New->prev = NULL;
    return New;
}

void insertVisitor(List_visitor &v, adr_visitor p){
    if (v.first == NULL){
        v.first = p;
        v.last = p;
    }else{
        p->prev = v.last;
        v.last->next = p;
        v.last = p;
    }
}

void deleteFirstVisitor(List_visitor &v, adr_visitor &p) {
    if (v.first == NULL) {
        cout << "Tidak ada data visitor" << endl;
        p = NULL;
    } else {
        p = v.first;
        v.first = p->next;
        if (v.first != NULL) {
            v.first->prev = NULL;
        } else {
            v.last = NULL;
        }
        p->next = NULL;
    }
}


void deleteLastVisitor(List_visitor &v, adr_visitor &p) {
    if (v.first == NULL) {
        cout << "Tidak ada data visitor" << endl;
        p = NULL;
    } else {
        p = v.last;
        if (p->prev != NULL) {
            v.last = p->prev;
            v.last->next = NULL;
        } else {
            v.first = NULL;
            v.last = NULL;
        }
        p->prev = NULL;
    }
}


void deleteAfterVisitor(List_visitor &v, adr_visitor &p, adr_visitor x){
    if (v.first == NULL){
        cout << "Tidak ada data visitor" << endl;
		p = NULL;
	}else if (v.first->next == NULL){
		p = v.first;
		v.first = NULL;
		v.last = NULL;
	}else{
        p = x;
        x = x->prev;
        x->next = p->next;
        p->next->prev = x;
        p->next = NULL;
        p->prev = NULL;
    }
}

adr_visitor searchVisitor(List_visitor v, string nama){
    adr_visitor p = v.first;
    while (p->info.nama != nama && p != NULL){
        p = p->next;
    }

    if (p == NULL){
        cout << "Nama tidak ditemukan. " << endl;
    }

    return p;
}

void penentuDeleteVisitor(List_visitor &v, adr_visitor &p){
    adr_visitor temp = NULL;
    // Hasil delete disimpan di temp
    if (p == v.first){
        deleteFirstVisitor(v, temp);
    }else if (p == v.last){
        deleteLastVisitor(v, temp);
    }else{
        deleteAfterVisitor(v, temp, p);
    }
}

//==========================================================================================================================

void createListBuku(List_buku &b){
    b.first = NULL;
    b.last = NULL;
}

adr_buku createElemenBuku(infotype_buku p){
    adr_buku New = new elm_buku;
    New->info.judul = p.judul;
    New->info.tipe = p.tipe;
    New->info.kesediaan = p.kesediaan;
    New->info.kesediaanAwal = p.kesediaanAwal;
    return New;
}

void insertBuku(List_buku &b, adr_buku p){
    p->next = NULL;
    p->prev = NULL;
    if (b.first == NULL){
        b.first = p;
        b.last = p;
    }else{
        p->prev = b.last;
        b.last->next = p;
        b.last = p;
    }
}

void deleteFirstBuku(List_buku &b, adr_buku &p){
    if (b.first == NULL) {
        cout << "Tidak ada data buku" << endl;
        p = NULL;
    } else {
        p = b.first;
        b.first = p->next;
        if (b.first != NULL) {
            b.first->prev = NULL;
        } else {
            b.last = NULL;
        }
        p->next = NULL;
    }
}

void deleteLastBuku(List_buku &b, adr_buku &p){
    if (b.first == NULL) {
        cout << "Tidak ada data visitor" << endl;
        p = NULL;
    } else {
        p = b.last;
        if (p->prev != NULL) {
            b.last = p->prev;
            b.last->next = NULL;
        } else {
            b.first = NULL;
            b.last = NULL;
        }
        p->prev = NULL;
    }
}

void deleteAfterBuku(List_buku &b, adr_buku &p, adr_buku x){
    if (b.first == NULL){
        cout << "Tidak ada data buku" << endl;
		p = NULL;
	}else if (b.first->next == NULL){
		p = b.first;
		b.first = NULL;
		b.last = NULL;
	}else{
        p = x;
        x = x->prev;
        x->next = p->next;
        p->next->prev = x;
        p->next = NULL;
        p->prev = NULL;
    }
}

void penentuDeleteBuku(List_buku &b, adr_buku &p){
    adr_buku temp = NULL;
    if (p == b.first){
        deleteFirstBuku(b, temp);
    }else if (p == b.last){
        deleteLastBuku(b, temp);
    }else{
        deleteAfterBuku(b, temp, p);
    }
}

//========================================================================================================================

void createListRelasi(List_relasi &r){
    r.first = NULL;
    r.last = NULL;
}

adr_relasi createElemenRelasi(adr_buku p){
    adr_relasi New = new elm_relasi;
    New->info = p;
    New->next = NULL;
    New->prev = NULL;
    return New;
}

void insertRelasi(List_relasi &r, adr_relasi p, adr_visitor &v) {
    if (v->book == NULL) {
        r.first = p;
        r.last = p;
    } else {
        p->next = r.first;
        r.first->prev = p;
        r.first = p;
    }

    v->book = p;
}

void deleteFirstRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v){
    cout << "test123" << endl;
    if (v->book == NULL){
        cout << "Tidak ada data relasi" << endl;
        p = NULL;
    }else{
        p = v->book;
        if (p->next != NULL){
            r.first = p->next;
            r.first->prev = NULL;
        }else{
            r.first = NULL;
            r.last = NULL;
        }
        p->prev = NULL;
        p->next = NULL;

        v->book = r.first;
}
}

void deleteLastRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v) {
    if (v->book == NULL) {
        cout << "Tidak ada data relasi" << endl;
        p = NULL;
    } else {
        p = v->book;
        while (p->next != NULL){//cari last
            p = p->next;
        }
        if (p->prev != NULL) {//Kalo bukan cuma satu relasi
            adr_relasi temp = p->prev;
            temp->next = NULL;
        }
        p->prev = NULL;
        p->next = NULL;
    }
}


void deleteAfterRelasi(List_relasi &r, adr_relasi &p, adr_relasi x, adr_visitor &v) {
    if (v->book == NULL || x == NULL) {
        cout << "Tidak dapat menghapus elemen yang diberikan" << endl;//Bermasalah----------------------
        p = NULL;
    } else {
        p = x;

        if (p->prev != NULL) {
            p->prev->next = p->next;
        } else {
            r.first = p->next;
        }

        if (p->next != NULL) {
            p->next->prev = p->prev;
        } else {
            r.last = p->prev;
        }
        p->prev = NULL;
        p->next = NULL;
    }
}


void penentuDeleteRelasi(List_relasi &r, adr_relasi &p, adr_visitor &v){
    adr_relasi temp = NULL;

    if (p == v->book){
        deleteFirstRelasi(r, temp, v);
    }else if (p == r.last){
        deleteLastRelasi(r, temp, v);
    }else{
        deleteAfterRelasi(r, temp, p, v);
    }
}
//============================================================================================================

bool isAvailable(List_buku b, string judul){//untuk mencari tahu apakah buku masih available untk dipinjam
    adr_buku temp = b.first;
    while (temp != NULL){
        if (temp->info.judul == judul){
            if (temp->info.kesediaan != 0){
                return true;
            }
            break;
        }
        temp = temp->next;
    }
    return false;
}

bool isBookExist(List_buku b, string judul){//untuk mencari tahu apakah judul buku sudah ada
    adr_buku temp = b.first;
    while (temp != NULL){
        if (temp->info.judul == judul){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool isVisitorExist(List_visitor v, string nama){//untuk mencari tahu apakah visitor yg dituju ada
    adr_visitor temp = v.first;
    while (temp != NULL){
        if (temp->info.nama == nama){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

adr_visitor findVisitor(List_visitor v, string nama){//untuk menemukan address Visitor
    adr_visitor temp = v.first;
    while (temp != NULL){
        if (temp->info.nama == nama){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

adr_buku findBook(List_buku b, string judul){//untuk menemukan address buku
    adr_buku temp = b.first;
    while (temp != NULL){
        if (temp->info.judul == judul){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

adr_relasi findRelation(adr_visitor adr_v, List_relasi r, adr_buku adr_b){
    adr_relasi adr_r = adr_v->book;
    while (adr_r != NULL){
        if (adr_r->info == adr_b){
            return adr_r;
        }
        adr_r = adr_r->next;
    }
    return NULL;
}

int hitungPinjam(List_visitor v, List_relasi r, string nama){//untuk menghitung buku yg dipinjam
    adr_visitor p = findVisitor(v, nama);
    if (p->book == NULL){
        return 0;
    }else{
        adr_relasi x = p->book;
        int i = 0;
        while (x != NULL){
            i++;
            x = x->next;
        }
        return i;
    }
}

bool stillCanBorrow(int x, string tipe){//member maks 5 dan nonmember maks 2
    if (tipe == "member"){
        if (x != 5){
            return true;
        }
    }else{
        if (x != 2){
            return true;
        }
    }
    return false;
}

void buatRelasi(List_visitor &v, List_buku &b, List_relasi &r){
    string nama, judul;
    cout << "Masukan nama visitor: "; cin >> nama;

    adr_relasi adr_r;
    adr_buku info_r;

    adr_visitor adr_v;
    infotype_visitor info_v;

    if (isVisitorExist(v, nama)){
        int x = hitungPinjam(v, r, nama);
        cout << x << endl;//------------------
        adr_v = findVisitor(v, nama);
        if (stillCanBorrow(x, adr_v->info.keanggotaan)){
            cout << "Masukan judul yang akan dipinjam: "; cin >> judul;
            if (isBookExist(b, judul)){
                if (isAvailable(b, judul)){
                    info_r = findBook(b, judul);
                    adr_r = createElemenRelasi(info_r);
                    insertRelasi(r, adr_r, adr_v);
                    info_r->info.kesediaan--;//Untuk ngurangin ketersediaan buku
                    cout << "Buku berhasil dipinjam" << endl;
                }else{
                    cout << "Ketersediaan kosong" << endl;
                }
            }else{
                cout << "Judul buku tidak ditemukan" << endl;
            }
        }else{
            cout << "Visitor sudah tidak dapat meminjam" << endl;
        }
    }else{
        cout << "Nama visitor tidak ditemukan" << endl;
    }
}

void hapusVisitor(List_visitor &v, List_relasi &r){
    adr_visitor adr_v;
    string nama;
    cout << "Masukan nama yang ingin dihapus: "; cin >> nama;
    adr_v = findVisitor(v, nama);
    if (adr_v != NULL){//untuk cek apakah visitor itu ada
        int x = hitungPinjam(v, r, nama);
        hapusAllRelation(adr_v, r, x);//buat hapus relasinya dlu baru delete visitor
        penentuDeleteVisitor(v, adr_v);
        cout << "Visitor berhasi dihapus" << endl;
    }else{
        cout << "Visitor tidak ditemukan" << endl;
    }
}

void hapusAllRelation(adr_visitor &adr_v, List_relasi &r, int x){
    if (adr_v->book == NULL){
        return;
    }else{
        adr_buku b;
        adr_relasi p;
        for (int i = 0; i < x; ++i){
            deleteLastRelasi(r, p, adr_v);//p buat nyimpennya
            b = p->info;
            b->info.kesediaan++;//untuk tambahin lagi kesediaanya
        }
    }
}

void hapusBuku(List_buku &b, List_relasi &r){
    adr_buku adr_b;
    string judul;
    cout << "Masukan judul yang ingin dihapus: "; cin >> judul;
    adr_b = findBook(b, judul);
    if (adr_b != NULL){
        if (adr_b->info.kesediaanAwal == adr_b->info.kesediaan){
            penentuDeleteBuku(b, adr_b);
            cout << "Buku berhasi dihapus" << endl;
        }else{
            cout << "Buku masih dipinjam, tidak dapat menghapus buku ini" << endl;
        }
    }else{
        cout << "Buku tidak ditemukan" << endl;
    }
}

void hapusRelasi(List_visitor &v, List_buku &b, List_relasi &r){
    adr_relasi adr_r;
    adr_visitor adr_v;
    adr_buku adr_b;
    string nama, judul;
    cout << "Masukan nama yang mengembalikan: "; cin >> nama;
    adr_v = findVisitor(v, nama);
    if (adr_v != NULL){
        cout << "Masukan judul yang ingin dibalikan: "; cin >> judul;
        adr_b = findBook(b, judul);
        adr_r = findRelation(adr_v, r, adr_b);
        if (adr_r != NULL){
            penentuDeleteRelasi(r, adr_r, adr_v);
            adr_b->info.kesediaan++;
            cout << "Relasi berhasi dihapus" << endl;
        }else{
            cout << adr_v->info.nama << " tidak meminjam buku berjudul " << judul << endl;
        }
    }else{
        cout << "Visitor tidak ditemukan" << endl;
    }
}

void updateVisitor(List_visitor &v){
    string nama;
    cout << "Masukan nama: "; cin >> nama;
    adr_visitor p = findVisitor(v, nama);

    if (p != NULL){
        cout << "Silahkan update" << endl;
        cout << "Masukan nama baru: "; cin >> p->info.nama;
        cout << "Masukan gender baru: "; cin >> p->info.gender;
        cout << "Masukan keanggotaan baru: "; cin >> p->info.keanggotaan;
        cout << endl << "Data berhasil diupdate" << endl;
    }else{
        cout << "Visitor tidak ditemukan" << endl;
    }
}

void updateBooks(List_buku &b){
    string judul;
    int jumlah, selisih;
    cout << "Masukan judul: "; cin >> judul;
    adr_buku p = findBook(b, judul);

    if (p != NULL){
        cout << "Silahkan update" << endl;
        cout << "Masukan ketersediaan: "; cin >> jumlah;

        selisih = jumlah - p->info.kesediaanAwal;
        p->info.kesediaan += selisih;

        p->info.kesediaanAwal = jumlah;
        cout << endl << "Data berhasil diupdate" << endl;
    }else{
        cout << "Buku tidak ditemukan" << endl;
    }
}

//Procedure Show===================================================================================================

void allVisitor(List_visitor v){
    adr_visitor temp = v.first;
    int i = 1;
    while (temp != NULL){
        cout << i << ". " << temp->info.nama << " " << temp->info.gender << " " << temp->info.keanggotaan << endl;
        i++;
        temp = temp->next;
    }
}

void allBooks(List_buku b){
    adr_buku temp = b.first;
    int i = 1;
    while (temp != NULL){
        cout << i << ". " << temp->info.judul << " " << temp->info.tipe << " " << temp->info.kesediaan << " dari " << temp->info.kesediaanAwal << endl;
        i++;
        temp = temp->next;
    }
}

void allBorrower(List_visitor v, List_relasi r){
    adr_visitor adr_v = v.first;
    adr_relasi adr_r;
    adr_buku b;
    int i= 1;

    while (adr_v != NULL){
        cout << i << ". " << adr_v->info.nama << " meminjam buku: " << endl;
        adr_r = adr_v->book;

        while (adr_r != NULL){
            b = adr_r->info;
            cout << "   - " << b->info.judul;
            adr_r = adr_r->next;
        }
        cout << endl;

        adr_v = adr_v->next;
        i++;
    }
}

void oneVisitor(List_visitor v, List_relasi r){
    string nama;
    adr_buku b;
    adr_relasi adr_r;
    cout << "Masukan nama: "; cin >> nama;
    adr_visitor p = findVisitor(v, nama);

    if (p != NULL){
        cout << "Gender: " << p->info.gender << endl;
        cout << "Keanggotaan: " << p->info.keanggotaan << endl;

        cout << "meminjam buku: " << endl;
        adr_r = p->book;

        while (adr_r != NULL){
            b = adr_r->info;
            cout << "   - " << b->info.judul;
            adr_r = adr_r->next;
        }
        cout << endl;
    }else{
        cout << "Visitor tidak ditemukan" << endl;
    }
}

void oneBook(List_visitor v, List_buku b, List_relasi r){
    string judul;
    cout << "Masukan judul: "; cin >> judul;
    cout << "Dipinjam oleh: " << endl;
    adr_buku adr_b = findBook(b, judul);

    adr_visitor adr_v = v.first;
    adr_relasi adr_r;
    while (adr_v != NULL){
        adr_r = adr_v->book;
        while (adr_r != NULL){
            if (adr_r->info == adr_b){
                cout << " - " << adr_v->info.nama << endl;
            }
            adr_r = adr_r->next;
        }
        adr_v = adr_v->next;
    }
}

void category(List_buku b){
    string ktgr;
    cout << "Masukan kategori: "; cin >> ktgr;
    adr_buku p = b.first;
    while (p != NULL){
        if (p->info.tipe == ktgr){
            cout << " - " << p->info.judul << endl;
        }
        p = p->next;
    }
}

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

    x = findVisitor(v, "john");
    z = findBook(b, "kamu");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "john");
    z = findBook(b, "brave");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "bob");
    z = findBook(b, "dune");
    adr_r = createElemenRelasi(z);
    insertRelasi(r, adr_r, x);
    z->info.kesediaan--;

    x = findVisitor(v, "bob");
    z = findBook(b, "divergent");
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
