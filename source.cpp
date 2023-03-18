#include <iostream>
#include <cstring>
#include <cctype>
#include <unistd.h>
#include "source.h"

using namespace std;

void introduction_1() {
    cout << "\n*Breviar teoretic*" << endl << endl;
    cout << "\nI. Cifrul monoalfabetic de substitutie" << endl;
    cout << "\ncifrul substituției este o metodă de criptare prin care unități din text sunt înlocuite cu criptotext conform unui sistem regulat;" << endl;
    cout << "\nIn cadrul cifrul monoalfabetic de criptare, se declara un alfabet cheie, fiecare litera a alfabetului initial avand un corelativ unic in nou alfabet";
    cout << endl << endl;
    cout <<"\nII.Cifrul lui Cezar" << endl;
    cout << "\nAceasta metoda de criptare realizeaza o permutare catre dreapta la n pozitii, n fiind cheia secreta.";
    cout << endl << endl;
    cout << "\nIII. Cifrul Playfair" << endl;
    cout << "\nAcest cifru aduce o noutate, alfabetul are numai 25 de caractere si formeaza o matrice patratica 5x5";
    cout << "\nCorelativul fiecarui caracter depinde de pozitia sa in alfabetul initial.";
    cout << "\nIn cazul unui mesaj de lungime impara, se adauga la sfarsitul textului caracterul X";
    cout << "\nCaracterul X se adauga si atunci cand literele vecine sunt identice.";
    cout << "\nSpre deosebire de cifrurile anterioare, acest cifru cripteaza textul folosind, pe rand, cate 2 caractere din mesajul initial, de unde si motivatia construirii unui sir de lungime para.";
}

void introduction_2() {
    cout << "  Proiectul este unul bazat pe tehnici de criptare a diferitelor mesaje, ";
    cout << "acestea variaza in functie de tehnica aleasa.";
    cout << endl;
    cout << "\n  In cele ce urmeaza vor fi prezentate atat tehnicile de criptare, cat si optiunile ";
    cout << "utilizatorului.";
    cout << endl;
    cout << "\n \tPrima tehnica -> Cifrul cu substitutie monoalfabetica";
    cout << "\n\t A doua tehnica -> Cifrul lui Cezar";
    cout << "\n\t A treia tehnica -> Cifrul Playfair";
    cout << endl << endl;
    cout << "\nOptiunile utilizatorului";
    cout << endl << "\nPrima data are loc alegerea cifrului de criptare dorit;";
    cout << "\n";
    cout << endl << "1. Cifrul monoalfabetic de criptare;" << endl;
    cout << "2. Cifrul lui Cezar;" << endl;
    cout << "3. Cifrul Playfair. Aici se cere introducerea textului cu majuscule si fara semne de punctuatie, respectiv fara litera J!" << endl;
    cout << "\nNota: Toate cele 3 cifruri cripteaza un text introdus de la tastatura, apoi preiau textul criptat si il decripteaza.";
}

void criptare_descriptare_mono_alfabetic(char alfabet_englez[], char alfabet_cheie[]) {
    char mesaj_criptat[255] = {};
    char mesaj_decriptat[255] = {};

    cout << "Introduceti mesajul secret: ";
    char mesaj_secret[255];
    cin.get();
    cin.getline(mesaj_secret, 255);

    cout << endl;
    cout << "\nSe cripteaza mesajul..." << endl;

    int n = 0; //indexare de la 0 pentru vectorul de criptare

    for (int i = 0; i < strlen(mesaj_secret); ++i) {
        char litera = mesaj_secret[i];
        int litera_copie = litera;
        if (litera_copie >= 32 && litera_copie <= 64) {
            litera = (char)(litera_copie);
            mesaj_criptat[n++] = litera;
            continue;
        }

        int pozitie = 0;

        for (int j = 0; j < strlen(alfabet_englez); j++) {
            if (litera == alfabet_englez[j])
                pozitie = j;
        }

        bool gasit = false;
        for (int k = 0; k < strlen(alfabet_cheie) && gasit == 0; ++k) {
            if (pozitie== k) {
                litera = alfabet_cheie[k];
                gasit = true;
            }
        }

        mesaj_criptat[n++] = litera;
    }

    usleep(1000049);

    cout << "Mesajul criptat este: " << mesaj_criptat << endl;
    cout << "\nSe decripteaza..." << endl;

    int m = 0;  //indexare de la 0 pentru vectorul de decriptare

    for (int i = 0; i < strlen(mesaj_criptat); ++i) {
        char litera_2 = mesaj_criptat[i];
        int litera_copie_2 = litera_2;
        if (litera_copie_2 >= 32 && litera_copie_2 <= 64) {
            litera_2 = (char)(litera_copie_2);
            mesaj_decriptat[m++] = litera_2;
            continue;
        }
        int pozitie_2 = 0;

        for (int l = 0; l < strlen(alfabet_cheie); l++) {
            if (litera_2 == alfabet_cheie[l])
                pozitie_2 = l;
        }

        bool gasit_2 = false;
        for (int j = 0; j < strlen(alfabet_englez) && gasit_2 == 0; ++j) {
            if (pozitie_2 == j) {
                litera_2 = alfabet_englez[j];
                gasit_2 = true;
            }
        }

            mesaj_decriptat[m++] = litera_2;
    }

    usleep(1000049);

    cout << "Mesajul decriptat: ";
    cout << mesaj_decriptat << endl;
    cout << endl;
}

void criptare_caesar(int cheie) {
    cout << "Introduceti cheia dorita: ";
    cin >> cheie;

    if (cheie > 25) {
        cout << endl;
        cout << "\nCheie invalida! Reintroduceti o valoare: ";
        cin >> cheie;
    }

    cout << "\nIntroduceti textul dorit: ";
    char mesaj_secret[255];
    cin.get();
    cin.getline(mesaj_secret, 255);

    cout << "\nAre loc criptarea mesajului secret...";

    char mesaj_criptat[255] = {};
    int l = 0;  //indexare de la 0 pentru vectorul de criptare

    for (int i = 0; i < strlen(mesaj_secret); i++) {

        if ((int)(mesaj_secret[i]) >= 32 && (int)(mesaj_secret[i]) <= 64) {
            mesaj_criptat[l++] = mesaj_secret[i];
            continue;
        }

        int litera = (int)(mesaj_secret[i]) + cheie;

        if (isupper(mesaj_secret[i])) {
            if (litera > 90)
                mesaj_criptat[l++] = char(litera) - 90 + 64;
            else mesaj_criptat[l++] = char(litera);
        }else if (islower(mesaj_secret[i])) {
                if (litera > 122)
                    mesaj_criptat[l++] = char(litera) - 122 + 96;
                else mesaj_criptat[l++] = char(litera);
        }
    }

    usleep(1000049);
    cout << endl << mesaj_criptat << endl;

    char mesaj_decriptat[255] = {};
    int k = 0;  //indexare de la 0 pentru vectorul de descriptare

    for (int j = 0; j < strlen(mesaj_criptat); j++) {
        int cheie_noua = 26-cheie;

        if ((int)(mesaj_criptat[j]) >= 32 && (int)(mesaj_criptat[j]) <= 64) {
            mesaj_decriptat[k++] = mesaj_criptat[j];
            continue;
        }

        int litera_2 = (int)(mesaj_criptat[j]) + cheie_noua;

        if (isupper(mesaj_criptat[j])) {
            if (litera_2 > 90)
                mesaj_decriptat[k++] = char(litera_2) - 90 + 64;
            else mesaj_decriptat[k++] = char(litera_2);
        }else if (islower(mesaj_criptat[j])) {
            if (litera_2 > 122)
                mesaj_decriptat[k++] = char(litera_2) - 122 + 96;
            else mesaj_decriptat[k++] = char(litera_2);
        }
    }

    cout << "\nMesajul descriptat...";
    cout << "\n";
    usleep(1000049);
    cout << mesaj_decriptat << endl;
}

void criptare_decriptare_playfair(char alfabet_fair[5][5]) {
    char text_initial[255];
    cout << "\nIntroduceti textul: ";
    cin.get();
    cin.getline(text_initial, 255);

    char text_criptat[255] = {};
    int cnt = 0;

    char text_modificat[255] = {};
    int index = 0;

    for (int b = 0; b < strlen(text_initial); b++)
        if (text_initial[b] != ' ')
            text_modificat[index++] = text_initial[b];

    strcpy(text_initial, text_modificat);

    for (int i = 0; i < strlen(text_initial); i+=2) {
        char litera_1 = text_initial[i];
        char litera_2;
        if (i == strlen(text_initial) - 1)
            litera_2 = 'X';
        else  litera_2 = text_initial[i+1];

        int coloana_1 = 0;
        int linie_1 = 0;

        int coloana_2 = 0;
        int linie_2 = 0;

        for (int k = 0; k < 5; k++) {
            for (int l = 0; l < 5; l++) {
                if (alfabet_fair[k][l] == litera_1) {
                    linie_1 = k;
                    coloana_1 = l;
                }else if (alfabet_fair[k][l] == litera_2) {
                    linie_2 = k;
                    coloana_2 = l;
                }
            }
        }

        if (litera_1 == litera_2) {
            litera_2 = 'X';

            for (int d = 0; d < 5; d++) {
                for (int e = 0; e < 5; e++) {
                    if (alfabet_fair[d][e] == 'X') {
                        linie_2 = d;
                        coloana_2 = e;
                    }
                }
            }
        }

        if (coloana_1 == coloana_2) {
            if (linie_1 <= 3) {
                litera_1 = alfabet_fair[linie_1+1][coloana_1];
            }else if (linie_1 == 4)
                litera_1 = alfabet_fair[0][coloana_1];

            if (linie_2 <= 3) {
                litera_2 = alfabet_fair[linie_2+1][coloana_2];
            }else if (linie_2 == 4)
                litera_2 = alfabet_fair[0][coloana_2];
        }else if (linie_1 == linie_2) {
            if (coloana_1 <= 3) {
                litera_1 = alfabet_fair[linie_1][coloana_1+1];
            }else if (coloana_1 == 4)
                litera_1 = alfabet_fair[linie_1][0];

            if (coloana_2 <= 3) {
                litera_2 = alfabet_fair[linie_2][coloana_2+1];
            }else if (coloana_2 == 4)
                litera_2 = alfabet_fair[linie_2][0];
        }else if ((linie_1 != linie_2) && (coloana_1 != coloana_2)) {
            litera_1 = alfabet_fair[linie_1][coloana_2];
            litera_2 = alfabet_fair[linie_2][coloana_1];
        }

        text_criptat[cnt++] = litera_1;
        text_criptat[cnt++] = litera_2;
    }

    cout << "\nSe cripteaza textul...";
    usleep(1000049);
    cout << endl << text_criptat << endl;
    cout << endl << endl;
    cout << "\nSe decripteaza textul...";

    char text_decriptat[255] = {};
    int nr = 0; //indexare de la 0 pentru vectorul de decriptare

    for (int i = 0; i < strlen(text_criptat); i+=2) {
        char litera_3 = text_criptat[i];
        char litera_4 = text_criptat[i+1];

        int coloana_3 = 0;
        int linie_3 = 0;

        int coloana_4 = 0;
        int linie_4 = 0;

        for (int k = 0; k < 5; k++) {
            for (int l = 0; l < 5; l++) {
                if (alfabet_fair[k][l] == litera_3) {
                    linie_3 = k;
                    coloana_3 = l;
                }else if (alfabet_fair[k][l] == litera_4) {
                    linie_4 = k;
                    coloana_4 = l;
                }
            }
        }

        if (coloana_3 == coloana_4) {
            if (linie_3 > 0) {
                litera_3 = alfabet_fair[linie_3-1][coloana_3];
            }else if (linie_3 == 0)
                litera_3 = alfabet_fair[4][coloana_3];

            if (linie_4 > 0) {
                litera_4 = alfabet_fair[linie_4-1][coloana_4];
            }else if (linie_4 == 0)
                litera_4 = alfabet_fair[4][coloana_4];
        }else if (linie_3 == linie_4) {
            if (coloana_3 > 0) {
                litera_3 = alfabet_fair[linie_3][coloana_3-1];
            }else if (coloana_3 == 0)
                litera_3 = alfabet_fair[linie_3][4];

            if (coloana_4 > 0) {
                litera_4 = alfabet_fair[linie_4][coloana_4-1];
            }else if (coloana_4 == 0)
                litera_4 = alfabet_fair[linie_4][4];
        }else if ((linie_3 != linie_4) && (coloana_3 != coloana_4)) {
            litera_3 = alfabet_fair[linie_3][coloana_4];
            litera_4 = alfabet_fair[linie_4][coloana_3];
        }

        text_decriptat[nr++] = litera_3;
        text_decriptat[nr++] = litera_4;
    }

    usleep(1000049);
    cout << endl << endl;
    cout << text_decriptat << endl;
}


