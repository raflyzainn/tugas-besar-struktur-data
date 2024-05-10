#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define nextAktor(P) P->nextAktor
#define nextNegara(P) P->nextNegara

using namespace std;

struct film {
    string judul;
    string sutradara;
    string tahun_rilis;
    int total_hasil;
};

struct aktor {
    string nama;
    string tahun_lahir;
    int umur;
};

struct relasi {
    string negara;//,hobi
};

typedef struct elmt_film *adr_film;

typedef struct elmt_aktor *adr_aktor;

typedef struct elmt_negara *adr_negara;

struct elmt_aktor {
    aktor info;
    adr_aktor next;
    adr_negara nextNegara;
};

struct elmt_film {
    film info;
    adr_film next;
    adr_aktor nextAktor;
};

struct elmt_negara {
    relasi info;
    adr_negara next;
};

struct L1 {
    adr_film first;
};

struct L2 {
    adr_negara first;
};

void header();
int menu();
void createListUtama(L1 &list_utama);
void createListRelasi(L2 &list_relasi);
void newElmFilm(film x, adr_film &F);
void newElmAktor(aktor y, adr_aktor &A);
void newElmNegara(relasi z, adr_negara &N);
relasi inputNewRelasi();
film inputNewFilm();
aktor inputNewAktor();
bool cekDataFilm(adr_film F);
void insertFirstP(L1 &list_utama, adr_film F);
void insertLastP(L1 &list_utama, adr_film F);
void deleteFirstP(L1 &list_utama, adr_film &F);
void deleteLastP(L1 &list_utama, adr_film &F);
void deleteAfterP(L1 &list_utama, adr_film prec, adr_film &F);
void deleteFilm(L1 &list_utama, adr_film prec, adr_film &F);
adr_film findFilm(L1 list_utama, string nama_film);
void printSearchFilm(adr_film F);
void showDataFilm(L1 list_utama);
void insertFirstC(L1 &list_utama, adr_film F, adr_aktor A);
void insertLastC(L1 &list_utama, adr_film F, adr_aktor A);
void deleteFirstC(L1 &list_utama, adr_film F, adr_aktor &A);
void deleteLastC(L1 &list_utama, adr_film F, adr_aktor &A);
void deleteAfterC(L1 &list_utama, adr_film F, adr_aktor prec, adr_aktor &A);
void deleteAktor(L1 &list_utama, adr_film F, adr_aktor prec, adr_aktor &A);
void printSearchAktor(L1 list_utama, string nama_film, string nama_aktor);
adr_aktor findAktorInFilm(L1 &list_utama, string nama_aktor);
void showAllAktor(L1 list_utama);
void showAllDataListUtama(L1 list_utama);
int sumOfChild(L1 list_utama, adr_film F, adr_aktor A);
void insertFirstR(L2 &list_relasi, adr_negara N);
void insertLastR(L2 &list_relasi, adr_negara N);
void deleteFirstR(L2 &list_relasi, adr_negara &N);
void deleteAfterR(L2 &list_relasi, adr_negara prec, adr_negara &N);
void deleteLastR(L2 &list_relasi, adr_negara &N);
void deleteRelasi(L2 &list_relasi, adr_negara &M);
adr_negara findNegara(L2 list_relasi, string flag_negara);
void printSearchNegara(adr_negara N);
void showDataNegara(L2 list_relasi);
void inputAktorAndNegara(L1 &list_utama, L2 &list_relasi, string nama_aktor, string negara);
void showAktorAndNegara(L1 list_utama, L2 list_relasi);
// POINT 3 DAN 9 BELUM

#endif // FILM_H_INCLUDED
