#ifndef GESTIONAR_H_INCLUDED
#define GESTIONAR_H_INCLUDED
#include <vector>
#include <memory>
#include <algorithm>
#include <typeinfo>
#include "companie.h"

using namespace std;

class pereche {
    string nume;
    float valoare;
public:
    void set_nume(string nume) { this -> nume = nume;}
    void set_valoare(float valoare) {this -> valoare = valoare;}
    float get_valoare() { return valoare; }
    string get_nume() { return nume; }
};

template <class T>
class Info {
	T variabila;
public:
	Info(T var) { this->variabila = var; }
	void afisareInfo() {
	    bool ok = true;
		if ((string)typeid(variabila).name() == "P8companie")
			{ cout << "Denumirea cautata a fost utilizata de catre o COMPANIE." << endl; ok = false; }
		if ((string)typeid(variabila).name() == "P11departament")
            { cout << "Denumirea cautata a fost utilizata de catre un DEPARTAMENT." << endl; ok = false; }
		if ((string)typeid(variabila).name() == "P7angajat")
			{ cout << "Denumirea cautata a fost utilizata de catre un ANGAJAT." << endl; ok = false; }
        if(ok)
            cout << "Denumirea cautata nu este inca utilizata." << endl;
	}
};

template <class T>
class deducere {
	T variabila;
public:
	deducere(T var) { this->variabila = var; }
	T aplicareDeducere() {
		variabila = 0.84 * variabila;
		return variabila;
	}
};


class gestionar {
	static vector<string> toateCompaniile;
	vector<companie> v;
	int nrCompanii = 0;
public:
	template <class T> T maxim(T x1, T x2) {
		if (x1 > x2)
			return x1;
		else
			return x2;
	}
	int get_nrCompanii(){ return nrCompanii; }
	void baraDeCautare();
	bool existaCompanie(string);
	void citireCompanii();
	void adaugaCompanie();
	void eliminaCompanie();
	void eliminareAngajat();
	void adaugareAngajat();
	void eliminareDepartament();
	void adaugareDepartament();
	void numarAngajatiDepartament();
	void numarAngajatiCompanie();
	void cheltuieliCompanie();
	void afisareManager();
	void afisarePesteNAngajati();
	void afisareCompanii();
	void topCompaniiDupaCheltuieli();
	void cheltuieliCuDeduceri();
};

vector<string> gestionar::toateCompaniile;

void gestionar::baraDeCautare(){
    system("CLS");
    cout << "In acest meniu pot fi cautate denumiri pentru COMPANII, DEPARTAMENTE SAU ANGAJATI." << endl;
    cout << "Ideal daca doresti sa aflii DACA O DENUMIRE A FOST INTRODUSA IN PROGRAM." << endl;
    cout << "CAUTATI: ";
    //cin.clear(); cin.ignore(256, '\n');
    //cin.clear(); cin.ignore(256, '\n');
    string nume; getline(cin, nume);
    bool ok = true;
    for(auto a = v.begin(); a != v.end(); ++a) {
        if((*a).get_numeCompanie() == nume) {
            companie *A;
            A = new companie("", 3.14);
            Info<companie*> d(A);
            d.afisareInfo();
            ok = false;
        }
    }
    vector<departament> v1 = companie::get_toateDepartamentele();
    for(auto a = v1.begin(); a != v1.end(); ++a) {
        if((*a).get_numeDepartament() == nume) {
            departament *A;
            A = new departament(5, "");
            Info<departament*> d(A);
            d.afisareInfo();
            ok = false;
        }
    }
    vector<angajat> v2 = departament::get_totiAngajatii();
    for(auto a = v2.begin(); a != v2.end(); ++a) {
        if((*a).get_nume() == nume) {
            angajat* x;
            x = new angajat("", "", 0, false);
            Info<angajat*> d(x);
            d.afisareInfo();
            ok = false;
        }
    }
    if(ok)
        cout << "Denumirea cautata nu este inca utilizata." << endl;
}

bool gestionar::existaCompanie(string nume) {
	int ok = 0;
	ok = count_if(v.begin(), v.end(), [nume](companie A) {
		if (A.get_numeCompanie() == nume)
			return true;
		else
			return false;
		});
	if (ok == 1)
		return true;
	else
		return false;
}

void gestionar::afisareCompanii(){
    cout << "LISTA COMPANII INTRODUSE: " << endl << endl;
    int c = 0;
    for(auto a = v.begin(); a != v.end(); ++a) {
        c++;
        cout << c << ". " << (*a).get_numeCompanie() << endl;
    }
}

void gestionar::citireCompanii() {
	try {
		cout << "De cate companii se ocupa GESTIONARUL: "; cin >> nrCompanii;
		if (nrCompanii < 1 || cin.fail())
			throw 1;

	}
	catch (...) {
		do {
            cin.clear(); cin.ignore(256, '\n');
			cout << "Raspunsul trebuie sa fie un NUMAR >= 1." << endl;
			cout << "De cate companii se ocupa GESTIONARUL: "; cin >> nrCompanii;
		} while (nrCompanii < 1 || cin.fail());
	}
	cin.clear(); cin.ignore(256, '\n');
	for (int i = 0; i < nrCompanii; i++) {
		string nume;
		try {
			cout << "Nume compania " << i + 1 << ": "; getline(cin, nume);
			bool ok = true;
			for (auto i = gestionar::toateCompaniile.begin(); i != gestionar::toateCompaniile.end(); ++i)
				if ((*i) == nume)
					ok = false;
			if (!ok)
				throw 1;
		}
		catch (...) {
			bool ok;
			do {
				ok = true;
				cout << "Exista deja o companie cu acest nume!" << endl;
				cout << "Nume compania " << i + 1 << ": "; getline(cin, nume);
				for (auto i = gestionar::toateCompaniile.begin(); i != gestionar::toateCompaniile.end(); ++i)
					if ((*i) == nume)
						ok = false;
			} while (!ok);
		}
		companie A(nume);
		A.adaugareDepartamente();
		A.actualizareCheltuieliCompanie();
		v.push_back(A);
		gestionar::toateCompaniile.push_back(nume);
	}
}

void gestionar::adaugaCompanie(){
    companie A;
    A.adaugareDepartamente();
    A.actualizareCheltuieliCompanie();
    v.push_back(A);
    toateCompaniile.push_back(A.get_numeCompanie());
    nrCompanii = v.size();
}

void gestionar::eliminaCompanie(){
    if(v.size() == 0)
        cout << "Nu exista inca companii introduse." << endl;
    else {
        if(v.size() == 1) {
            cout << "Nu se poate elimina ultima companie. " << endl;
        }
        else {
         cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl;
        try {
			cout << "Compania eliminata o sa fie: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Compania eliminata o sa fie: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		v.erase(v.begin() + opt - 1);
		nrCompanii = v.size();
        }
    }
}

void gestionar::eliminareAngajat(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii din care sa eliminati angajati. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl;
        try {
			cout << "Angajtul eliminat este din compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Angajatul eliminat este din compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).eliminareAngajat();
                break;
            }
		}
    }
}

void gestionar::adaugareAngajat(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii in care sa adaugati angajatul. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl;
        try {
			cout << "Angajatul adaugat o sa fie in compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Angajatul adaugat o sa fie in compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).adaugareAngajat();
                break;
            }
		}
    }
}

void gestionar::eliminareDepartament(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii din care sa eliminati departamente. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl;
        try {
			cout << "Departamentul eliminat este din compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Departamenul eliminat este din compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).stergereDepartament();
                break;
            }
		}
    }
}

void gestionar::adaugareDepartament(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii in care sa adaugati departamente. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl;
        try {
			cout << "Departamentul adaugat este in compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Departamenul adaugat este in compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).adaugareDepartament();
                //(*a).afisareDepartamente();
                break;
            }
		}
    }
}

void gestionar::numarAngajatiDepartament(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii introduse in gestionar. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Departamentul cautat este in compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Departamenul cautat este in compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).numarAngajatiDepartament();
                break;
            }
		}
    }
}

void gestionar::numarAngajatiCompanie(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii introduse in gestionar. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Numarul de angajati din compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Numarul de angajati din compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).numarAngajatiCompanie();
                break;
            }
		}
    }
}

void gestionar::cheltuieliCompanie(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii introduse in gestionar. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Cheltuielile companiei: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Cheltuielile companiei: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).generareCheltuieliCompanie();
                break;
            }
		}
    }
}

void gestionar::afisareManager(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii introduse in gestionar. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Managerul cautat este in compania: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Managerul cautat este in compania: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                (*a).afisareManager();
                break;
            }
		}
    }
}

void gestionar::afisarePesteNAngajati(){
    system("CLS");
    if (nrCompanii == 0)
        cout << "Nu exista inca companii introduse in gestionar. " << endl;
    else {
        cout << "Companiile existente in gestionar sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeCompanie() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Compania in care doriti sa cautati este: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Compania in care doriti sa cautati este: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		system("CLS");
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt) {
                int nr;
                cout << "Departamentele ce au cel putin n anjati." << endl;
                try {
                    cout << "n = "; cin >> nr;
                    if(cin.fail() || nr < 0)
                        throw 1;
                }
                catch(...){
                    do {
                        cin.clear(); cin.ignore(256, '\n');
                        cout << "n trebuie sa fie un NUMAR >= 0" << endl; cin >> nr;
                    }
                    while(cin.fail() || nr < 0);
                }
                system("CLS");
                (*a).pestenAngajati(nr);
                break;
            }
		}
    }
}

void gestionar::topCompaniiDupaCheltuieli() {
    pereche A[v.size()];
    int n = 0;
    for(auto a = v.begin(); a != v.end(); ++a){
        //(*a).actualizareCheltuieliCompanie();
        A[n].set_nume((*a).get_numeCompanie());
        A[n].set_valoare((*a).get_cheltuieliCompanie());
        n = n + 1;
    }
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if (maxim(A[i].get_valoare(), A[j].get_valoare()) == A[j].get_valoare())
                swap(A[i], A[j]);
    cout << "TOP COMPANII PRIVIND CHELTUIELILE: " << endl << endl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ". " << A[i].get_nume() << " ---------- " << A[i].get_valoare() << endl;
    }
}

void gestionar::cheltuieliCuDeduceri() {
    cout << "CHELTUIELILE COMPANIILOR DACA AR PUTEA APLICA DEDUCERI DE 16% : " << endl << endl;
    int c = 0;
    for(auto a = v.begin(); a != v.end(); ++a) {
        deducere<float> A((*a).get_cheltuieliCompanie());
        cout << ++c << ". " << (*a).get_numeCompanie() << " ---------- " << A.aplicareDeducere() << endl;
    }
}


#endif // GESTIONAR_H_INCLUDED
