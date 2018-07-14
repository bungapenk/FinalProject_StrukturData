#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <windows.h>
#define MAX 20

using namespace std;

/*
* Ini adalah aplikasi dari IF-04
* Dibuat oleh Kelompok 9
* Terimakasih kepada :
* ALLAH SWT
* MUHAMMAD SAW
* Google.com, StackOverFlow.com, Programiz.com, dkk.
*/

struct menuSewa {
	//deklarasi struct dari menuSewa
	char namaPembooking[10][10];
	char tanggal[10][10];
	int lamaMain[10];
	char jam[10][10];
	int jml;
	int totBayar;
	int menu;
}booking;

struct sortingSearching {
	//deklarasi struct dari Sorting & Searching

	//Sorting
	string namaPemain[7];
	int noPunggung[7];
	int index[7];
	int awal, akhir, sementara;
	//Searching
	int cariData;
	int penanda;
}lineUp;

struct jajan {
	char namaJajan[15][100], max[15];
	int i, j;

}stackJajan;

//agar bisa dipanggil di void yang lain
void opening();
void pilihanSatu();
void pilihanDua();
void pilihanTiga();
void pilihanEmpat();
void pilihanLima();
void menuBalik();

void opening() {
	//menu pembuka/selamat datang
	system("cls");
	string pembuka[5] = {
		"\n+++++++++++++++++++++++++++++++++++\n",
		"+        IF-04 SEWA FUTSAL        +\n",
		"+++++++++++++++++++++++++++++++++++\n",
		"+  Universitas Amikom Yogyakarta  +\n",
		"+++++++++++++++++++++++++++++++++++\n" };
	for (int i = 0; i<5; i++) {
		cout << pembuka[i];
	}
}


void isiForm() {
	/*
	* menu untuk mengisi form data/identitas penyewa
	*/
	cout << "Masukkan Jumlah Pembooking : ";
	cin >> booking.jml;
	system("cls");
	for (int j = 0; j<booking.jml; j++) {
		cout << "\n+++++++++++++++++++++++++++++++++++";
		cout << "\n+     Masukkan Data Diri Anda     +\n";
		cout << "+++++++++++++++++++++++++++++++++++";
		cout << "\nMasukkan Nama Anda : ";
		cin >> booking.namaPembooking[j];
		cout << "Tanggal Sewa *dd/mm/yy* : ";
		cin >> booking.tanggal[j];
		cout << "Jam Berapa *XX:XX AM/PM* : ";
		cin >> booking.jam[j];
		cout << "Berapa Jam Main : ";
		cin >> booking.lamaMain[j];
	}
}

/*
* Program Khusus Admin : Nambah Jajan
*/

void tambahJajan() {
	stackJajan.i++;
	cout << "Masukkan Jajan : ";
	cin >> stackJajan.max;
	strcpy(stackJajan.namaJajan[stackJajan.i],stackJajan.max);
}

void hapusJajan() {
    if(stackJajan.i > 0) {
        cout << "Jajan yang terhapus : " << stackJajan.namaJajan[stackJajan.i] << endl;
        stackJajan.i--; stackJajan.j--;
    }
    else{
        cout << "Tidak ada data yang terambil!" << endl;
    }
}

void lihatJajan(int n) {
    if(stackJajan.j > 0) {
        for(int e = n; e >= 1; e--) {
            cout << "Jajan Yang Tersimpan : \n" << stackJajan.namaJajan[e] << endl;
        }
    }
    else {
        cout << "Tidak ada jajan yang tersimpan!" << endl;
    }
}

void hapusSemuaJajan() {
    stackJajan.i = 0; stackJajan.j = 0;
}

void menuJajan() {
	int n = 0;
	int pilih;
	ayo:
	    cout <<   "=================";
	    cout << "\n== ADMIN JAJAN ==\n";
	    cout <<   "=================\n";
	    stackJajan.namaJajan[n];
	    stackJajan.i = 0;
	    stackJajan.j = 0;
    balik:
        cout << " 1. Tambah Jajan\n 2. Hapus Jajan\n 3. Lihat Jajan\n 4. Hapus Semua Jajan\n 5. Balik Menu User\n";
        cout << "Masukkan Pilihan : "; cin >> pilih;
        cout << endl;

        if(pilih == 1) {
            if(stackJajan.j > n) {
                stackJajan.j++; tambahJajan();
            }
            else {
                cout << "Stock Jajan Penuh!" << endl;
                getch();
            }
            goto balik;
        }
        else if(pilih == 2) {
            hapusJajan(); getch();
            goto balik;
        }
        else if(pilih == 3) {
            lihatJajan(stackJajan.i); getch();
            goto balik;
        }
        else if(pilih == 4) {
            hapusSemuaJajan(); getch();
            goto balik;
        }
        else if(pilih == 5) {
            menuBalik(); getch();
        }
        else {
            exit(0);
        }
}


/*
* Program User Untuk Menyewa Futsal
*/

void menuUtama() {
	/*
	* menu utama untuk
	* - lihat siapa saja yang telah membooking
	* - menambahkan lineup dan menyorting lineup
	* - mencari nomor punggung pemain yang sudah disorting
	* - keluar
	*/

	//panggil opening();
	opening();

	//Menu Booking
	cout << endl;
	cout << "1. Lihat Daftar Pembooking" << endl;
	//Sorting -LineUp-
	cout << "2. Masukkan Lineup" << endl;
	cout << "3. Cari Data Pemain" << endl;
	cout << "4. (Admin) : Jajan" << endl;
	cout << "5. Beli Jajan" << endl;
	cout << "6. Keluar" << endl;
	cout << "Pilih Menu : ";
	cin >> booking.menu;
	system("cls");

	if (booking.menu == 1) {
		pilihanSatu();
		menuBalik();
	}

	else if (booking.menu == 2) {
		pilihanDua();
		menuBalik();
	}

	else if (booking.menu == 3) {
		pilihanTiga();
		menuBalik();
	}

	else if (booking.menu == 4) {
		pilihanEmpat();
		menuBalik();
	}

	else if (booking.menu == 5) {
		pilihanLima();
		menuBalik();
	}

	else if (booking.menu == 6) {
		cout << "\n+++++++++++++++++++++++";
		cout << "\n+     TERIMAKASIH     +\n";
		cout << "+++++++++++++++++++++++\n";
		exit(0);
	}

	else {
		cout << "\n--  Arep Ngopo Cukkk???  --\n";
	}
}

void menuBalik() {
	//menu untuk balik ke menuUtama
	char pilihBalik = 0;
	bool exitNow = false;

	cout << "\nBalik ke menu? (y/n) : ";
	cin >> pilihBalik;
	if (pilihBalik == 'y') {
		return menuUtama();
	}
	else if (pilihBalik == 'n') {
		cout << "\n+++++++++++++++++++++++";
		cout << "\n+     TERIMAKASIH     +\n";
		cout << "+++++++++++++++++++++++\n";
		exitNow = true;
	}
	else {
		cout << "\n+++++++++++++++++++";
		cout << "\n+   Jancoookkkk   +\n";
		cout << "+++++++++++++++++++";
	}
}

void pilihanSatu() {
	// mengisi data pembooking dengan struct
	for (int k = 0; k<booking.jml; k++) {
		cout << "\n===========================" << endl;
		cout << "    Tampilkan Informasi    " << endl;
		cout << "===========================" << endl;
		cout << "Nama Anda 				: " << booking.namaPembooking[k] << endl;
		cout << "Tanggal Sewa 				: " << booking.tanggal[k] << endl;
		cout << "Jam Main 				: " << booking.jam[k] << endl;
		cout << "Lama Bermain 				: " << booking.lamaMain[k] << endl;
		//rumus total bayar
		booking.totBayar = 120000 * booking.lamaMain[k];
		cout << "Biaya Sewa 				: " << booking.totBayar << endl;
	}
}

void pilihanDua() {
	// menambahkan lineup pemain sekaligus mengurutkan dengan sorting
	// Sorting - Tambah Lineup Pemain
	cout << "++++++++++++++++++++++++++++++++";
	cout << "\n+  Silahkan Isi Lineup Pemain  +\n";
	cout << "++++++++++++++++++++++++++++++++\n";
	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		//input nama lineup
		cout << "Masukkan Nama Pemain : ";
		cin >> lineUp.namaPemain[lineUp.awal];
		//input no punggung lineup
		cout << "Masukkan No Punggung Pemain : ";
		cin >> lineUp.noPunggung[lineUp.awal];
	}

	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		lineUp.index[lineUp.awal] = lineUp.awal;
	}

	for (lineUp.awal = 0; lineUp.awal<4; lineUp.awal++) {
		for (lineUp.akhir = lineUp.awal + 1; lineUp.akhir<5; lineUp.akhir++) {
			if (lineUp.noPunggung[lineUp.index[lineUp.awal]] > lineUp.noPunggung[lineUp.index[lineUp.akhir]]) {
				lineUp.sementara = lineUp.index[lineUp.awal];
				lineUp.index[lineUp.awal] = lineUp.index[lineUp.akhir];
				lineUp.index[lineUp.akhir] = lineUp.sementara;
			}
		}
	}

	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		cout << "\n++++++++++++++++++++++" << "++++++";
		cout << "\n+    Data Pemain Urut " << lineUp.awal << "    +\n";
		cout << "++++++++++++++++++++++" << "++++++\n";

		cout << "- Nama Pemain : " << lineUp.namaPemain[lineUp.index[lineUp.awal]] << "				- No Punggung : ";
		cout << lineUp.noPunggung[lineUp.index[lineUp.awal]] << endl;
	}
	cin.ignore();
	cin.get();

	// system("pause");
}

void pilihanTiga() {
	// mencari no Punggung pemain dengan searching
	//tampilkan data pemain
	cout << "+++++++++++++++++++++";
	cout << "\n+    Data Pemain    +\n";
	cout << "+++++++++++++++++++++\n";

	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		lineUp.index[lineUp.awal] = lineUp.awal;
	}

	for (lineUp.awal = 0; lineUp.awal<4; lineUp.awal++) {
		for (lineUp.akhir = lineUp.awal + 1; lineUp.akhir<5; lineUp.akhir++) {
			if (lineUp.noPunggung[lineUp.index[lineUp.awal]] > lineUp.noPunggung[lineUp.index[lineUp.akhir]]) {
				lineUp.sementara = lineUp.index[lineUp.awal];
				lineUp.index[lineUp.awal] = lineUp.index[lineUp.akhir];
				lineUp.index[lineUp.akhir] = lineUp.sementara;
			}
		}
	}

	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		cout << "\n+++++++++++++++++++++++" << "++++++";
		cout << "\n+     Data Pemain     +\n";
		cout << "+++++++++++++++++++++++" << "++++++\n";

		cout << "- Nama Pemain : " << lineUp.namaPemain[lineUp.index[lineUp.awal]] << "				- No Punggung : ";
		cout << lineUp.noPunggung[lineUp.index[lineUp.awal]] << endl;
	}

	cout << "\n==========================";
	cout << "\n     Cari Data Pemain     \n";
	cout << "==========================\n";

	cout << "Silahkan Masukkan No.Punggung Yang Dicari : ";
	cin >> lineUp.cariData;

	//pake sequential search

	for (lineUp.awal = 0; lineUp.awal<5; lineUp.awal++) {
		if (lineUp.noPunggung[lineUp.index[lineUp.awal]] == lineUp.cariData) {
			lineUp.penanda = 1;
			break;
		}
	}

	if (lineUp.penanda == 1) {
		cout << "Data ditemukan pada indeks ke- " << lineUp.awal << endl;
	}
	else {
		cout << "Data tidak ditemukan";
	}
	cin.get();
	_getche();
}


void pilihanEmpat(void) {
	menuJajan();
}

void pilihanLima() {

	_getch();
}

int main(void) {
	//tampilkan opening
	opening();

	//Menu Sewa
	isiForm();

	//tampilkan & input pilihan
	system("cls");
	opening();
	menuUtama();
}
