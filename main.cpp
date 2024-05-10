#include "film.h"

int main(){
    L1 list_utama;
    L2 list_relasi;
    film x;
    aktor y;
    int pilihan;
    adr_aktor A, prec1;
    adr_film F, flag_adrFilm, prec;
    string nama_film1, nama_film2, nama_film3, flag_film, flag_aktor, flag_negara;
    relasi z;
    adr_negara N,prec2;

    createListUtama(list_utama);
    createListRelasi(list_relasi);
    header();
    pilihan = menu();


    while (pilihan != 0) {
        if (pilihan == 1) {
            x = inputNewFilm();
            flag_film = x.judul;
            flag_adrFilm = findFilm(list_utama, flag_film);

            if (cekDataFilm(flag_adrFilm)) {
                newElmFilm(x, F);
                insertLastP(list_utama, F);
            }
        } else if (pilihan == 2) {
            cout << endl;
            cout << "Nama film          : ";
            cin >> flag_film;

            y = inputNewAktor();
            F = findFilm(list_utama,flag_film);
            newElmAktor(y, A);
            insertLastC(list_utama,F,A);
        } else if (pilihan == 3) {
            z = inputNewRelasi();
            newElmNegara(z, N);
            insertLastR(list_relasi, N);
        } else if (pilihan == 4) {
            cout << endl;
            cout << "Nama negara: ";
            cin >> flag_negara;
            cout << "Nama aktor: ";
            cin >> flag_aktor;
            cout << endl;

            inputAktorAndNegara(list_utama, list_relasi, flag_aktor, flag_negara);
        } else if (pilihan == 5) {
            //system("cls");
            cout << endl;
            showDataFilm(list_utama);
            cout << endl;
        } else if (pilihan == 6) {
            //system("cls");
            cout << endl;
            showAllAktor(list_utama);
            cout << endl;
        } else if (pilihan == 7) {
            //system("cls");
            cout << endl;
            showDataNegara(list_relasi);
            cout << endl;
        } else if (pilihan == 8) {
            cout << endl;
            showAllDataListUtama(list_utama);
            cout << endl;
        } else if (pilihan == 9) {
            //system("cls");
            cout << endl;
            showAktorAndNegara(list_utama, list_relasi);
            cout << endl;
        } else if (pilihan == 10) {
            cout << endl;
            cout << "Nama film yang dicari: ";
            cin >> nama_film3;

            F = findFilm(list_utama, nama_film3);
            printSearchFilm(F);
            cout << endl;
        } else if (pilihan == 11) {
            cout << endl;
            cout << "Nama film yang dicari: ";
            cin >> flag_film;
            cout << "Nama aktor yang dicari: ";
            cin >> flag_aktor;

            printSearchAktor(list_utama, flag_film, flag_aktor);
        } else if (pilihan == 12){
            adr_negara temp;

            cout << endl;
            cout << "Nama negara yang dicari : ";
            cin >> flag_negara;

            temp = findNegara(list_relasi, flag_negara);
            printSearchNegara(temp);
        } else if (pilihan == 13) {
            deleteFilm(list_utama, prec, F);
        } else if (pilihan == 14) {
            deleteAktor(list_utama, F, prec1, A);
        } else if (pilihan == 15) {
            deleteRelasi(list_relasi, N);
        } else if (pilihan == 16) {
            cout << endl;
            cout << "Masukkan nama film: ";
            cin >> nama_film2;

            F = findFilm(list_utama, nama_film2);

            cout << "Jumlah aktor dalam film '" << nama_film2 << "' adalah " << sumOfChild(list_utama,F,A) << endl;
            cout << endl;
        }

        pilihan = menu();
    }

    return 0;
}
