#include <iostream>
#include <cstring>
#include <cctype>
#include <unistd.h>
#include "source.h"

using namespace std;

int main() {
    char alfabet_englez[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //Alfabeturile declarate pentru prima tehnica de criptare
    char alfabet_cheie[] = {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    int cheie = 0;  //declararea cheii pentru a doua tehnica de criptare

    char alfabet_fair[5][5] = {'A', 'B', 'C', 'D', 'E',
                                'F', 'G', 'H', 'I', 'K',
                                'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U',
                                'V', 'W', 'X', 'Y', 'Z'}; //declararea alfabetului folosit pentru a treia tehnica de criptare

    char alegere;
    introduction_1();

    cout << endl << endl;
    cout << "\nDoriti sa incepeti? y/n ";
    cin >> alegere;

    if (alegere != 'y' && alegere != 'n') {
        cout << "Alegerea facuta este invalida! Reincercati y/n ";
        cin >> alegere;
    }

    while (alegere == 'y') {
        int alegere_optiune_cifru;

        cout << "\nSe va afisa meniul de optiuni" << endl;
        introduction_2();
        cout << "\nIntroduceti modalitatea de criptare dorita: ";
        cin >> alegere_optiune_cifru;

        switch(alegere_optiune_cifru) {
            case 1:
                criptare_descriptare_mono_alfabetic(alfabet_englez, alfabet_cheie);
                    break;

            case 2:
                criptare_caesar(cheie);
                    break;

            case 3:
                criptare_decriptare_playfair(alfabet_fair);
                    break;

            default:
                cout << "Optiune invalida!";
                     break;
        }

        cout << "\nDoriti sa reincercati? y/n ";
        cin >> alegere;

        if (alegere == 'y')
            for (int interatie = 0; interatie <= 12; interatie++)
                cout << endl << endl << endl; //aceasta structura repetitiva adauga mai multe randuri libere astfel incat
    }                                          //pe ecran sa fie afisat din nou numai optiunile utilizatorului

    cout << endl;
    cout << "\nMultumesc!" << endl << endl;

    return 0;
}
