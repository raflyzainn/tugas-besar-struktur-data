#include "film.h"

void header() {
/* I.S.
   F.S. menampilkan tampilan pertama ketika program dijalankan */
    cout << "========== TUGAS BESAR STRUKTUR DATA ==========" << endl;
    cout << "= Nama : Isteu Amelia                         =" << endl;
    cout << "= Nim : 1301223023                            =" << endl;
    cout << "= Nama : Achmad Rafly Khatami Zain            =" << endl;
    cout << "= Nim : 1301223349                            =" << endl;
    cout << "===============================================" << endl;
    cout << endl;
}

int menu() {
/* mengembalikan  */
    cout << "1. Masukkan data film (parent)" << endl;
    cout << "2. Masukkan data aktor (child)" << endl;
    cout << "3. Masukkan data negara" << endl;
    cout << "4. Hubungkan aktor dengan negara" << endl;
    cout << "5. Melihat data film" << endl;
    cout << "6. Melihat data aktor" << endl;
    cout << "7. Melihat data negara" << endl;
    cout << "8. Melihat data film dan aktor" << endl;
    cout << "9. Melihat data negara dan aktor" << endl;
    cout << "10. Mencari data film" << endl;
    cout << "11. Mencari data aktor pada film" << endl;
    cout << "12. Mencari data negara" << endl;
    cout << "13. Menghapus data film dan aktor" << endl;
    cout << "14. Menghapus data aktor pada film tertentu" << endl;
    cout << "15. Menghapus data Negara" << endl;
    cout << "16. Menghitung jumlah aktor pada film tertentu" << endl;
    cout << "0. Keluar" << endl;

    int input = 0;
    cout << "Pilihan anda: ";
    cin >> input;

    return input;
}

void createListUtama(L1 &list_utama) {
/* I.S. terdefinisi sebuah pointer list_utama yang berisikan alamat yang akan ditambahkan
   F.S. membuat list parent dengan list_utama sebagai alamat penunjuk (?)   */
    first(list_utama) = NULL;
}

void createListRelasi(L2 &list_relasi) {
/* I.S. terdefinisi sebuah pointer list_utama yang berisikan alamat yang akan ditambahkan
   F.S. membuat list relasi antara parent dan child dengan list_relasi sebagai alamat penunjuk (?)   */
    first(list_relasi) = NULL;
}

void newElmFilm(film x, adr_film &F) {
/* I.S. terdefinisi sebuah elemen baru setelah alokasi
   F.S. info adalah x dan next dan nextAktor adalah NULL */
    F = new elmt_film;
    info(F) = x;
    next(F) = NULL;
    nextAktor(F) = NULL;
}

void newElmAktor(aktor y, adr_aktor &A) {
/* I.S. terdefinisi sebuah elemen baru setelah alokasi
   F.S. info adalah y dan next dan nextNegara adalah NULL */
    A = new elmt_aktor;
    info(A) = y;
    next(A) = NULL;
    nextNegara(A) = NULL;
}

void newElmNegara(relasi z, adr_negara &N) {
/* I.S. terdefinisi sebuah elemen baru setelah alokasi
   F.S. info adalah z dan next adalah NULL */
    N = new elmt_negara;
    info(N) = z;
    next(N) = NULL;
}
relasi inputNewRelasi(){
/* mengembalikan z sebagai suatu negara baru setelah diinputkan kedalam list relasi*/
    relasi z;

    cout << endl;
    cout << "Nama Negara : ";
    cin >> z.negara;
    cout << endl;

    return z;
}

film inputNewFilm() {
/* mengembalikan x sebagai pointer untuk menginputkan beberapa info list film kedalam list parent*/
    film x;

    cout << endl;
    cout << "Judul film         : ";
    cin >> x.judul;
    cout << "Sutradara film     : ";
    cin >> x.sutradara;
    cout << "Tahun rilis film   : ";
    cin >> x.tahun_rilis;
    cout << "Total hasil film   : ";
    cin >> x.total_hasil;
    cout << endl;

    return x;
}

aktor inputNewAktor() {
/* mengembalikan y sebagai pointer untuk menginputkan beberapa info list aktor kedalam list child */
    aktor y;

    cout << "Nama aktor         : ";
    cin >> y.nama;
    cout << "Tanggal lahir aktor: ";
    cin >> y.tahun_lahir;
    cout << "Umur aktor         : ";
    cin >> y.umur;
    cout << endl;

    return y;
}

bool cekDataFilm(adr_film F) {
/* mengembalikan kebenaran apakah suatu fim sudah terdaftar atau belum kedalam list */
    if (F != NULL) {
        cout << "-FILM SUDAH TERDAFTAR SILAHKAN MASUKAN FILM LAIN-" << endl;
        cout << endl;
        return false;
    } else {
        return true;
    }
}

void insertFirstP(L1 &list_utama, adr_film F) {
/* I.S. terdefinisi list_utama sebagai salah satu list parent dan F yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer F ditambahkan sebagai list baru kedalam mll  sebagai list pertama*/
    if (first(list_utama) == NULL) {
        first(list_utama) = F;
    } else {
        next(F) = first(list_utama);
        first(list_utama) = F;
    }
}

void insertLastP(L1 &list_utama, adr_film F) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer F ditambahkan sebagai list baru kedalam list parent mll sebagai list terakhir*/
    adr_film Q;

    if (first(list_utama) == NULL) {
        first(list_utama) = F;
    } else {
        Q = first(list_utama);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = F;
    }
}

void deleteFirstP(L1 &list_utama, adr_film &F) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F yang berisi alamat list pertama
   F.S. elemen pertama yang ditunjuk oleh F dihapuskan dari list parent*/
    if (first(list_utama) == NULL) {
        F = NULL;
    } else {
        F = first(list_utama);
        first(list_utama) = next(F);
        next(F) = NULL;
    }
}

void deleteLastP(L1 &list_utama, adr_film &F) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F yang berisi alamat list terakhir
   F.S. elemen terakhir yang ditunjuk oleh F dihapuskan dari list parent*/
    adr_film Q;

    if (first(list_utama) == NULL) {
        F = NULL;
    } else if (next(first(list_utama)) == NULL) {
        F = first(list_utama);
        first(list_utama) = NULL;
    } else {
        Q = first(list_utama);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        F = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfterP(L1 &list_utama, adr_film prec, adr_film &F) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F yang berisi alamat list diantara list pertama dan terakhir
   F.S. elemen diantara list pertama dan terakhir yang ditunjuk oleh F dihapuskan dari list parent*/
    if (prec == NULL || next(prec) == NULL) {
        F = NULL;
    } else {
        F = next(prec);
        next(prec) = next(next(prec));
        next(F) = NULL;
    }
}

void deleteFilm(L1 &list_utama, adr_film prec, adr_film &F) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F dan prec yang berisi alamat list
   F.S. dihapusnya suatu list film dari list parent setellah memanggil findfilm*/
    string flag;
    adr_film P, Q;

    cout << endl;
    cout << "Film yang ingin dihapus : ";
    cin >> flag;
    cout << endl;

    P = findFilm(list_utama, flag);

    if (P == first(list_utama)) {
        deleteFirstP(list_utama, F);
    } else if (next(P) == NULL) {
        deleteLastP(list_utama, F);
    } else {
        Q = first(list_utama);

        while (next(Q) != P) {
            Q = next(Q);
        }

        deleteAfterP(list_utama, Q, F);
    }
}

adr_film findFilm(L1 list_utama, string nama_film) {
/* mengembalikan alamat dari suatu film ketika info judul sama dengan nama film*/
    adr_film P = first(list_utama);

    while (P != NULL) {
        if (info(P).judul == nama_film){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printSearchFilm(adr_film F) {
/* I.S. terdefinisi alamat film F dari list parent pada mll
   F.S. menampilkan keseluruhan isi elemen yang ditunjuk oleh pointer F*/
    if (F != NULL) {
        cout << "=================================================" << endl;
        cout << endl;
        cout << "Judul film        : " << info(F).judul << endl;
        cout << "Sutradara film    : " << info(F).sutradara << endl;
        cout << "Tahun rilis film  : " << info(F).tahun_rilis << endl;
        cout << "Hasil revenue film: " << info(F).total_hasil<< endl;
        cout << endl;
        cout << "=================================================" << endl;
    } else {
        cout << "- FILM TIDAK DITEMUKAN -" << endl;
    }
}

void showDataFilm(L1 list_utama) {
/* I.S. terdefinisi list_utama sebagai salah satu list pada list parent
   F.S. menampilkan keseluruhan data film pada list parent*/
    adr_film P = first(list_utama);

    cout << "=================================================" << endl;
    cout << endl;

    while (P != NULL) {
        cout << "Judul film            : " << info(P).judul << endl;
        cout << "Sutradara film        : " << info(P).sutradara << endl;
        cout << "Tahun rilis film      : " << info(P).tahun_rilis << endl;
        cout << "Total hasil film      : " << info(P).total_hasil << endl;
        cout << endl;
        P = next(P);
    }

    cout << "=================================================" << endl;
}

void insertFirstC(L1 &list_utama, adr_film F, adr_aktor A) {
/* I.S. terdefinisi list_utama sebagai salah satu list child dan F  dan A yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer A ditambahkan sebagai list child dari suatu parent sebagai list pertama*/
    adr_aktor temp = nextAktor(F);
    nextAktor(F) = A;
    next(A) = temp;
}

void insertLastC(L1 &list_utama, adr_film F, adr_aktor A) {
/* I.S. terdefinisi list_utama sebagai salah satu list child dan F  dan A yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer A ditambahkan sebagai list child dari suatu parent sebagai list terakhir*/
    if (nextAktor(F) == NULL) {
        nextAktor(F) = A;
    } else {
        adr_aktor temp = nextAktor(F);

        while (next(temp) != NULL) {
            temp = next(temp);
        }

        next(temp) = A;
    }
}

void deleteFirstC(L1 &list_utama, adr_film F, adr_aktor &A) {
/* I.S. terdefinisi list_utama sebagai salah satu list child dan F  dan A yang berisi alamat list yang akan dihapuskan
   F.S. elemen pertama yang ditunjuk oleh pointer A dihapuskan dari list child dari suatu parent*/
    if (nextAktor(F) == NULL) {
        A = NULL;
    } else {
        A = nextAktor(F);
        nextAktor(F) = next(A);
        next(A) = NULL;
    }
}

void deleteLastC(L1 &list_utama, adr_film F, adr_aktor &A) {
/* I.S. terdefinisi list_utama sebagai salah satu list child dan F  dan A yang berisi alamat list yang akan dihapuskan
   F.S. elemen terakhir yang ditunjuk oleh pointer A dihapuskan dari list child dari suatu parent*/
    adr_aktor Q;

    if (nextAktor(F) == NULL) {
        A = NULL;
    } else if (next(nextAktor(F)) == NULL) {
        A = nextAktor(F);
        nextAktor(F) = NULL;
    } else {
        Q = nextAktor(F);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        A = next(Q);
        next(Q) = NULL;
    }
}

void deleteAfterC(L1 &list_utama, adr_film F, adr_aktor prec, adr_aktor &A) {
/* I.S. terdefinisi list_utama sebagai salah satu list child dan F  dan A yang berisi alamat list yang akan dihapuskan
   F.S. elemen diantara pertama dan terakhir yang ditunjuk oleh pointer A dihapuskan dari list child dari suatu parent*/
    if (prec == NULL || next(prec) == NULL) {
        A = NULL;
    } else {
        A = next(prec);
        next(prec) = next(next(prec));
        next(A) = NULL;
    }
}

void deleteAktor(L1 &list_utama, adr_film F, adr_aktor prec, adr_aktor &A) {
/* I.S. terdifinisi list_utama sebagai salah satu list parent dan F dan prec dan A yang berisi alamat list
   F.S. dihapusnya suatu list aktor dari list child setellah memanggil findfilm*/
    string flag_aktor, flag_film;
    adr_film Q;
    adr_aktor P,R;

    cout << "Film yang ingin dicari: ";
    cin  >> flag_film;
    cout << "Aktor yang ingin dihapus : ";
    cin >> flag_aktor;
    cout << endl;

    F = findFilm(list_utama, flag_film);

    if (info(nextAktor(F)).nama == flag_aktor) {
        deleteFirstC(list_utama, F, A);
    } else if (next(nextAktor(F)) == NULL) {
        deleteLastC(list_utama, F, A);
    } else {
        R = nextAktor(F);

        while (next(R) != findAktorInFilm(list_utama, flag_aktor)) {
            R = next(R);
        }

        deleteAfterC(list_utama, F, R, A);
    }
}

void printSearchAktor(L1 list_utama, string nama_film, string nama_aktor) {
/* I.S. terdefinisi string nama_film dan string nama_aktor yang akan dicari dalam sebuah list
   F.S. menampilkan keseluruhan isi elemen suatu list child ketika info nama sama dengan nama_aktor*/
    adr_film P = findFilm(list_utama, nama_film);

    cout << "=================================================" << endl;
    cout << endl;

    if (P != NULL) {
        adr_aktor Q = nextAktor(P);

        while (Q != NULL) {
            if (info(Q).nama == nama_aktor) {
                cout << "Nama aktor          : " << info(Q).nama << endl;
                cout << "Tanggal lahir aktor : " << info(Q).tahun_lahir << endl;
                cout << "Umur aktor :        : " << info(Q).umur << endl;
                return;
            }
            Q = next(Q);
        }

        cout << "Aktor dengan nama '" << nama_aktor << "' tidak ditemukan-" << endl;
    } else {
        cout << "-Film dengan judul '" << nama_film << "' tidak ditemukan-" << endl;
    }

    cout << endl;
    cout << "=================================================" << endl;
}

adr_aktor findAktorInFilm(L1 &list_utama, string nama_aktor) {
/*mengembalikan nama aktor yang terdapat pada sebuah list film*/
    adr_film P = first(list_utama);

    while (P != NULL) {
        adr_aktor Q = nextAktor(P);

        while (Q != NULL) {
            if (info(Q).nama == nama_aktor) {
                return Q;
            }
            Q = next(Q);
        }
        P = next(P);
    }

    return NULL;
}

void showAllAktor(L1 list_utama) {
/* I.S. terdefinisi list_utama dari suatu list yang ada pada mll
   F.S. menampilkan keseluruhan data aktor beserta elemen lainnya*/
    adr_film P = first(list_utama);

    cout << "=================================================" << endl;
    cout << endl;

    while (P != NULL) {
        adr_aktor Q = nextAktor(P);

        while (Q != NULL) {
            cout << "Nama aktor          : " << info(Q).nama << endl;
            cout << "Tanggal lahir aktor : " << info(Q).tahun_lahir << endl;
            cout << "Umur aktor :        : " << info(Q).umur << endl;
            cout << endl;
            Q = next(Q);
        }

        P = next(P);
    }

    cout << endl;
    cout << "=================================================" << endl;
}

void showAllDataListUtama(L1 list_utama) {
/* I.S. terdefinisi list_utama dari suatu list yang ada pada mll
   F.S. menunjukan semua data yang ada pada list utama*/
    adr_film P = first(list_utama);
    int i = 1;

    cout << "=================================================" << endl;
    cout << endl;

    while (P != NULL) {
        cout << "Nama film        : " << info(P).judul << endl;
        cout << "Sutradara film   : " << info(P).sutradara << endl;
        cout << "Tahun rilis film : " << info(P).tahun_rilis << endl;
        cout << "Total hasil film : " << info(P).total_hasil << endl;
        cout << "Aktor pada film  : " << endl;

        adr_aktor Q = nextAktor(P);
        while (Q != NULL) {
            cout << i << ". " << info(Q).nama << endl;
            Q = next(Q);
            i = i + 1;
        }

        cout << endl;
        P = next(P);
    }

    cout << endl;
    cout << "=================================================" << endl;
}

int sumOfChild(L1 list_utama, adr_film F, adr_aktor A) {
/*mengambalikan total banyaknya jumlah child*/
    int jumlah = 0;

    if (nextAktor(F) == NULL) {
        return jumlah;
    }

    adr_aktor Q = nextAktor(F);
    while (Q != NULL) {
        jumlah = jumlah + 1;
        Q = next(Q);
    }

    return jumlah;
}

void insertFirstR(L2 &list_relasi, adr_negara N){
/* I.S. terdefinisi list_relasi sebagai salah satu list penguhubung antara child dan parent dan N yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer N ditambahkan sebagai list relasi pertama*/
    if (first(list_relasi) == NULL) {
        first(list_relasi) = N;
    } else {
        next(N) = first(list_relasi);
        first(list_relasi) = N;
    }
}

void insertLastR(L2 &list_relasi, adr_negara N){
/* I.S. terdefinisi list_relasi sebagai salah satu list penguhubung antara child dan parent dan N yang berisi alamat list yang akan ditambahkan
   F.S. elemen yang ditunjuk oleh pointer N ditambahkan sebagai list relasi terakhir*/
    adr_negara Q;

    if (first(list_relasi) == NULL) {
        first(list_relasi) = N;
    } else {
        Q = first(list_relasi);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = N;
    }
}

void deleteFirstR(L2 &list_relasi, adr_negara &N){
/* I.S. terdefinisi list_relasi sebagai salah satu list penguhubung antara child dan parent dan N yang berisi alamat list yang akan dihapuskan
   F.S. elemen yang ditunjuk oleh pointer N diphapuskan dari list relasi pertama*/
    if (first(list_relasi) == NULL) {
        N = NULL;
    } else if (next(first(list_relasi)) == NULL) {
        N = first(list_relasi);
        first(list_relasi) = NULL;
    } else {
        N = first(list_relasi);
        first(list_relasi) = next(N);
        next(N) = NULL;
    }
}

void deleteLastR(L2 &list_relasi, adr_negara &N){
/* I.S. terdefinisi list_relasi sebagai salah satu list penguhubung antara child dan parent dan N yang berisi alamat list yang akan dihapuskan
   F.S. elemen yang ditunjuk oleh pointer N diphapuskan dari list relasi terakhir*/
    adr_negara Q;

    if (first(list_relasi) == NULL) {
        N = NULL;
    } else if (next(first(list_relasi)) == NULL) {
        N = first(list_relasi);
        first(list_relasi) = NULL;
    } else {
        N = next(first(list_relasi));
        Q = first(list_relasi);

        while (next(N) != NULL) {
            N = next(N);
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfterR(L2 &list_relasi, adr_negara prec, adr_negara &N){
/* I.S. terdefinisi list_relasi sebagai salah satu list penguhubung antara child dan parent dan N yang berisi alamat list yang akan dihapuskan
   F.S. elemen yang ditunjuk oleh pointer N diphapuskan dari diantara list relasi pertama dan terakhir*/
    if (first(list_relasi) == NULL) {
        N = NULL;
    } else if (next(first(list_relasi)) == NULL) {
        N = first(list_relasi);
        first(list_relasi) = NULL;
    } else {
        N = next(prec);
        next(prec) = next(N);
        next(N) = NULL;
    }
}

adr_negara findNegara(L2 list_relasi, string flag_negara) {
/*mengembalikan nama negara ketika info negara sama dengan flag negara*/
    adr_negara Q = first(list_relasi);

    while (Q != NULL) {
        if (info(Q).negara == flag_negara) {
            return Q;
        }
        Q = next(Q);
    }

    return NULL;
}

void printSearchNegara(adr_negara N) {
/* I.S. terdefinisi alamat negara N dari list relasi pada mll
   F.S. menampilkan isi elemen yang ditunjuk oleh pointer F*/
    cout << "=================================================" << endl;
    cout << endl;

    if (N != NULL) {
        cout << "Nama negara " << info(N).negara << " ditemukan!" << endl;
        cout << endl;
    } else {
        cout << "-NEGARA TIDAK DITEMUKAN!-" << endl;
        cout << endl;
    }

    cout << "=================================================" << endl;
    cout << endl;
}


void deleteRelasi(L2 &list_relasi, adr_negara &M) {
/* I.S. terdefinisi list_relasi sebagai list penghubung antara child dan parent, dan M berisi alamat suatu negara
   F.S. dihapusnya suatu negara dari list relasi*/

   string flag;
    adr_negara P, Q;

    cout << endl;
    cout << "Negara yang ingin dihapus : ";
    cin >> flag;
    cout << endl;

    P = findNegara(list_relasi, flag);

    if (P == first(list_relasi)) {
        deleteFirstR(list_relasi, P);
    } else if (next(P) == NULL) {
        deleteLastR(list_relasi, P);
    } else {
        Q = first(list_relasi);

        while (next(Q) != P) {
            Q = next(Q);
        }

        deleteAfterR(list_relasi, Q, P);
    }
}

void showDataNegara(L2 list_relasi){
/* I.S. terdefinisi list_relasi sebagai penunjuk suatu list dari list relasi
   F.S. menampilkan seluruh data negara yang sudah terdaftar*/
    adr_negara N = first(list_relasi);

    cout << "=================================================" << endl;
    cout << endl;

    while (N != NULL){
        cout << "Negara : " << info(N).negara << endl;
        N = next(N);
    }

    cout << endl;
    cout << "=================================================" << endl;
}

void inputAktorAndNegara(L1 &list_utama, L2 &list_relasi, string nama_aktor, string negara) {
/* I.S. terdefinisi list_relasi sebagai penujuk list relasi dan list utama sebagai penujuk list child dan list parent, dan string nama_aktor dan negara berisikan child dan relasi berturut turut
   F.S. nama aktor terdaftar kedalam suatu negara*/
    adr_aktor A = findAktorInFilm(list_utama, nama_aktor);
    adr_film F;
    adr_negara N = findNegara(list_relasi, negara);
    nextNegara(A) = N;
}

void showAktorAndNegara(L1 list_utama, L2 list_relasi) {
/* I.S. terdefinisi list_relasi sebagai penujuk list relasi dan list utama sebagai penujuk list child dan list parent, dan string nama_aktor dan negara berisikan child dan relasi berturut turut
   F.S. menampilkan seluruh nama aktor yang terdaftar dari suatu negara*/
    adr_film P = first(list_utama);
    string flag;

    while (P != NULL) {
        adr_aktor R = nextAktor(P);
        while (R != NULL) {
            adr_negara Q = nextNegara(R);

            if (Q == NULL) {
                flag = "BELUM ADA NEGARA";
            } else {
                flag = info(Q).negara;
            }

            cout << "Nama aktor: " << info(R).nama << " " << "Asal negara : " << flag << endl;
            R = next(R);
        }
        P = next(P);
    }
}
