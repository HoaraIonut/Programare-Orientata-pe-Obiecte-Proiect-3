#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include <iostream>
#include "gestionar.h"
#include <windows.h>

using namespace std;

class Meniu {
   static Meniu *instanta;
   gestionar A;
   bool companii = false;
   adaugaCompaniiMeniu() {
   }
public:
   static Meniu *getInstanta() {
      if (!instanta)
        instanta = new Meniu;
      return instanta;
   }
   void afisareMeniu();
   void introducereCompanii();
   void afisareCompanii();
   void existaCompanie();
   void numarAngajatiCompanie();
   void numarAngajatiDepartament();
   void cheltuieliCompanie();
   void topCompaniiDupaCheltuieli();
   void cheltuieliCuDeduceri();
   void informatiiManager();
   void afisareDepartamenteN();
   void adaugaCompanie();
   void eliminaCompanie();
   void adaugaDepartament();
   void eliminaDepartament();
   void adaugaAngajat();
   void eliminaAngajat();
   void baraDeCautare();
};

Meniu *Meniu::instanta = 0;

void Meniu::afisareMeniu() {
    system("CLS");
    cout << "MENIU - PROGRAM DE GESTIUNE COMPANII" << endl << endl;
    cout << "1.  BARA DE CAUTARE" << endl;
    cout << "2.  INTRODUCERE COMPANII" << endl;
    cout << "3.  AFISARE COMPANII" << endl;
    cout << "4.  EXISTA COMPANIE" << endl;
    cout << "5.  NUMAR ANGAJATI COMPANIE" << endl;
    cout << "6.  NUMAR ANGAJATI DEPARTAMENT" << endl;
    cout << "7.  CHELTUIELI COMPANIE" << endl;
    cout << "8.  TOP COMPANII DUPA CHELTUIELI" << endl;
    cout << "9.  CHELTUIELI DACA COMPANIILE AR DISPUNE DE DEDUCERI" << endl;
    cout << "10. INFORMATII MANAGER" << endl;
    cout << "11. AFISARE DEPARTAMENTE CU CEL PUTIN N ANGAJATI" << endl;
    cout << "12. ADAUGA O NOUA COMPANIE IN PROGRAM" << endl;
    cout << "13. ELIMINA O COMPANIE DIN PROGRAM" << endl;
    cout << "14. ADAUGA UN NOU DEPARTAMENT IN PROGRAM" << endl;
    cout << "15. ELIMINA UN DEPARTAMENT DIN PROGRAM" << endl;
    cout << "16. ADAUGA UN NOU ANGAJAT IN PROGRAM" << endl;
    cout << "17. ELIMINA UN ANGAJAT DIN PROGRAM" << endl;
    cout << "18. PARASIRE PROGRAM" << endl;
    cout << endl << endl;
    int opt;
    try {
        cout << "Optiunea dumneavoastra este: "; cin >> opt;
        if(cin.fail() || opt < 1 || opt > 18)
            throw 1;
    }
    catch(...) {
        do {
            cout << "Optiunea poate sa fie un NUMAR cuprins intre 1 si 18." << endl;
            cin.clear(); cin.ignore(256, '\n');
            cout << "Optiunea dumneavoastra este: "; cin >> opt;
        }
        while (cin.fail() || opt < 1 || opt > 18);
    }
    if(opt == 1) {
        baraDeCautare();
    }
    if(opt == 2) {
        introducereCompanii();
    }
    if(opt == 18) {
        system("CLS");
        cout << "Multumesc pentru utilizare!" << endl;
    }
    if(opt == 3) {
        afisareCompanii();
    }
    if(opt == 4) {
        existaCompanie();
    }
    if(opt == 5) {
        numarAngajatiCompanie();
    }
    if(opt == 6) {
        numarAngajatiDepartament();
    }
    if(opt == 7) {
        cheltuieliCompanie();
    }
    if(opt == 8) {
        topCompaniiDupaCheltuieli();
    }
    if(opt == 9) {
        cheltuieliCuDeduceri();
    }
    if(opt == 10) {
        informatiiManager();
    }
    if(opt == 11) {
        afisareDepartamenteN();
    }
    if(opt == 12) {
        adaugaCompanie();
    }
    if(opt == 13) {
        eliminaCompanie();
    }
    if(opt == 14) {
        adaugaDepartament();
    }
    if(opt == 15) {
        eliminaDepartament();
    }
    if(opt == 16) {
        adaugaAngajat();
    }
    if(opt == 17) {
        eliminaAngajat();
    }
}

void Meniu::introducereCompanii() {
    system("CLS");
    if(companii)
        cout << "COMPANIILE AU FOST DEJA INTRODUSE IN PROGRAM. SE PREGATESTE REVENIREA LA MENIUL PRINCIPAL..." << endl;
    else {
        companii = true;
        A.citireCompanii();
        cout << "COMPANIILE AU FOST INTRODUSE. SE PREGATESTE REVENIREA LA MENIUL PRINCIPAL..." << endl;
    }
    Sleep(1500);
    afisareMeniu();
}

void Meniu::afisareCompanii() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.afisareCompanii();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::existaCompanie() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.afisareCompanii();
        string nume;
        cout << "\nNumele companiei cautate: "; getline(cin, nume);
        if(A.existaCompanie(nume))
            cout << "Compania cautata exista in program. " << endl;
        else
            cout << "Compania cautata nu exista in program. " << endl;
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::numarAngajatiCompanie() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.numarAngajatiCompanie();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::numarAngajatiDepartament() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.numarAngajatiDepartament();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::cheltuieliCompanie() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.cheltuieliCompanie();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::topCompaniiDupaCheltuieli() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.topCompaniiDupaCheltuieli();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::cheltuieliCuDeduceri() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.cheltuieliCuDeduceri();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::informatiiManager() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.afisareManager();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::afisareDepartamenteN() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        A.afisarePesteNAngajati();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::adaugaCompanie() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.adaugaCompanie();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::eliminaCompanie() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.eliminaCompanie();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::adaugaDepartament() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.adaugareDepartament();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::eliminaDepartament() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.eliminareDepartament();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::adaugaAngajat() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.adaugareAngajat();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::eliminaAngajat() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.eliminareAngajat();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

void Meniu::baraDeCautare() {
    system("CLS");
    if(A.get_nrCompanii() == 0)
        cout << "Nu exista companii introduse in program. " << endl;
    else {
        cin.clear(); cin.ignore(256, '\n');
        A.baraDeCautare();
    }
    string s;
    cout << endl;
    cout << "Apasati orice caracter pentru a continua..." << endl;
    cin >> s;
    //cin.clear(); cin.ignore(256, '\n');
    afisareMeniu();
}

#endif // MENIU_H_INCLUDED
