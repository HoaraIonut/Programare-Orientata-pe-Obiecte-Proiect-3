#ifndef COMPANIE_H_INCLUDED
#define COMPANIE_H_INCLUDED
#include <vector>
#include "departament.h"

using namespace std;

class builder {
public:
	string buildNume();
	int buildNrDepartamente();
	departament buildDepartament(vector<departament>);
	void buildRaportDepartament(departament);
	int buildNrAngajati(departament);
	static bool verificareNume(vector<departament>, string);
};

string builder::buildNume() {
	system("CLS");
	string nume;
	cout << "Numele companiei este: ";
	getline(cin, nume);
	//cin.clear(); cin.ignore(256, '\n');
	return nume;
}

int builder::buildNrDepartamente() {
	system("CLS");
	int nr;
	try {
		cout << "Numar de departamente companie: "; cin >> nr;
		if (cin.fail() || nr < 1)
			throw 1;
	}
	catch (...) {
		do {
			cout << "Numarul de departamente trebuie sa fie un NUMAR > 0." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Numar de departamente companie: "; cin >> nr;
		} while (cin.fail() || nr < 1);
	}
	cin.ignore(256, '\n');
	return nr;
}

bool builder::verificareNume(vector<departament> v, string nume) {
	for (auto i = v.begin(); i != v.end(); ++i)
		if ((*i).get_numeDepartament() == nume)
			return false;
	return true;
}

departament builder::buildDepartament(vector<departament> v) {
	system("CLS");
	int nr;
	string nume;
	//cin.clear(); cin.ignore(256, '\n');
	try {
		cout << "Nume departament: "; getline(cin, nume);
		if (!verificareNume(v, nume))
			throw 1;
	}
	catch (...) {
		do {
			cout << "Numele introdus corespunde deja unui departament! Introduceti un alt nume!" << endl;
			cout << "Nume departament: "; getline(cin, nume);
		} while (!verificareNume(v, nume));
	}
	try {
		cout << "Numar de angajati departamentul " << nume << " este:"; cin >> nr;
		if (cin.fail() || nr < 1)
			throw 1;
	}
	catch (...) {
		do {
			cout << "Numarul de angajati trebuie sa fie un NUMAR > 0." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Numar de angajati departamentul " << nume << " este:"; cin >> nr;
		} while (cin.fail() || nr < 1);
	}
	departament A(nr, nume);
	A.citireAngajati();
	/*cin.clear();
	cin.ignore(256, '\n');*/
	return A;
}

void builder::buildRaportDepartament(departament A) {
	A.afisareDepartament();
}

int builder::buildNrAngajati(departament A) {
	return A.get_nrAngajati();
}

class companie {
	builder A;
	static vector<departament> toateDepartamentele;
	vector<departament> v;
	string nume;
	int nrDepartamente = 0;
	int nrAngajati = 0;
	float cheltuieliCompanie = 0;
public:
    companie(string x, float nr){this -> nume;}
	companie();
	companie(string);
	string get_numeCompanie() { return nume; this->cheltuieliCompanie = 0;}
	int get_nrAngajati() { return nrAngajati; }
	float get_cheltuieliCompanie() {
        actualizareCheltuieliCompanie();
	    return cheltuieliCompanie;
    }
    static vector<departament> get_toateDepartamentele() {return toateDepartamentele;}
	void afisareManager();
	void set_nrDepartamente(int nr) { nrDepartamente = nr; }
	void adaugareDepartamente();
	void afisareDepartamente();
	void actualizareCheltuieliCompanie();
	void adaugareDepartament();
	void adaugareDepartamentParametru(departament);
	void stergereDepartament();
	void actualizareNumarAngajati();
	void eliminareAngajat();
	void adaugareAngajat();
	bool existaDepartament(string);
	void numarAngajatiDepartament();
	void numarAngajatiCompanie();
	void generareCheltuieliCompanie();
	void pestenAngajati(int n);
	companie operator+(companie& ob);
	companie operator>(companie& ob);
};

vector<departament> companie::toateDepartamentele;

void companie::afisareManager(){
    if(v.size() == 0)
        cout << "Compania selectata nu are departamente." << endl;
    else {
        cout << "Departamentele existente in companie sunt: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c  << ". " << (*a).get_numeDepartament() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Managerul cautat este in departamentul: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Managerul cautat este in departamentul: "; cin >> opt;
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

void companie::adaugareAngajat(){
    if (nrDepartamente == 0)
        cout << "Compania aleasa nu are departamente introduse." << endl;
    else {
        cout << "Compania aleasa are urmatoarele departamente: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c << ". " << (*a).get_numeDepartament() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Angajtul adaugat o sa fie in departamentul: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Angajatul adaugat o sa fie in departamentul: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt){
                (*a).adaugareAngajat();
                break;
            }
        }
    }
}

void companie::eliminareAngajat(){
    if (nrDepartamente == 0)
        cout << "Compania aleasa nu are departamente introduse." << endl;
    else {
        cout << "Compania aleasa are urmatoarele departamente: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c << ". " << (*a).get_numeDepartament() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Angajtul eliminat este din departamentul: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Angajatul eliminat este din departamentul: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt)
                (*a).eliminareAngajat();
		}
    }
}

void companie::numarAngajatiDepartament(){
    if (nrDepartamente == 0)
        cout << "Compania aleasa nu are departamente introduse." << endl;
    else {
        cout << "Compania aleasa are urmatoarele departamente: " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            cout << c << ". " << (*a).get_numeDepartament() << endl;
        }
        int opt;
        cout << endl << endl;
        try {
			cout << "Numarul de angajati din departamentul: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Numarul de angajati din departamentul: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		c = 0;
		for(auto a = v.begin(); a != v.end(); ++a){
            c = c + 1;
            if(c == opt){
                system("CLS");
                cout << "DEPARTAMENTUL: " << (*a).get_numeDepartament() << endl;
                cout << "NUMAR ANGAJATI: " << (*a).get_nrAngajati() << " (inlcusiv MANAGERI)" << endl;
                cout << "NUMAR MANAGERI: " << (*a).get_nrManageri() << endl;
            }
		}
    }
}


companie companie::operator>(companie& ob) {
	companie c;
	if (this->cheltuieliCompanie > ob.cheltuieliCompanie)
		c = *this;
	else
		c = ob;
	return c;
}

bool companie::existaDepartament(string nume) {
	for (auto i = v.begin(); i != v.end(); ++i)
		if (nume == (*i).get_numeDepartament())
			return false;
	return true;
}

void companie::adaugareDepartamentParametru(departament A) {
	nrDepartamente = nrDepartamente + 1;
	v.push_back(A);
	toateDepartamentele.push_back(A);
	actualizareCheltuieliCompanie();
	actualizareNumarAngajati();
}

void companie::actualizareCheltuieliCompanie() {
	cheltuieliCompanie = 0;
	for (auto i = v.begin(); i != v.end(); ++i)
		cheltuieliCompanie = cheltuieliCompanie + (*i).get_CheltuieliDepartament();
}

void companie::actualizareNumarAngajati() {
	nrAngajati = 0;
	for (auto i = v.begin(); i != v.end(); ++i)
		nrAngajati = nrAngajati + A.buildNrAngajati(*i);
}

companie companie::operator+(companie& ob) {
	companie C;
	for (auto i = this->v.begin(); i != this->v.end(); ++i) {
		bool ok = true;
		vector<angajat> v2;
		string nume = (*i).get_numeDepartament();
		for (auto j = ob.v.begin(); j != ob.v.end(); ++j)
			if ((*j).get_numeDepartament() == nume) {
				ok = false;
				v2 = (*j).get_v();
			}
		if (ok)
			C.adaugareDepartamentParametru(*i);
		else {
			angajat x;
			vector<angajat> v1 = (*i).get_v();
			vector<angajat> v3;
			for (auto k1 = v1.begin(); k1 != v1.end(); ++k1) {
				bool ok1 = true;
				for (auto k2 = v2.begin(); k2 != v2.end(); ++k2)
					if ((*k1).get_nume() == (*k2).get_nume()) {
						ok1 = false; x = *k2;
					}
				if (ok1)
					v3.push_back((*k1));
				else {
					if ((*k1).get_numeManager() == "MANAGER")
						v3.push_back(*k1);
					else
						v3.push_back(x);
				}
			}
			for (auto k1 = v2.begin(); k1 != v2.end(); ++k1) {
				bool ok1 = true;
				for (auto k2 = v1.begin(); k2 != v1.end(); ++k2)
					if ((*k1).get_nume() == (*k2).get_nume())
						ok1 = false;
				if (ok1)
					v3.push_back(*k1);
			}
			int c = v3.size();
			departament z(c, v3, nume);
			C.adaugareDepartamentParametru(z);
		}
	}
	for (auto i = ob.v.begin(); i != ob.v.end(); ++i) {
		bool ok = true;
		string nume = (*i).get_numeDepartament();
		for (auto j = v.begin(); j != v.end(); ++j)
			if (nume == (*j).get_numeDepartament())
				ok = false;
		if (ok)
			C.adaugareDepartamentParametru(*i);
	}
	return C;
}

companie::companie(string nume) {
	this->nume = nume;
}

companie::companie() {
	this->nume = A.buildNume();
	this->cheltuieliCompanie = 0;
}

void companie::adaugareDepartamente() {
	this->nrDepartamente = A.buildNrDepartamente();
	for (int i = 0; i < this->nrDepartamente; i++) {
	    departament x = A.buildDepartament(v);
		v.push_back(x);
        toateDepartamentele.push_back(x);
		cin.clear(); cin.ignore(256, '\n');
	}
	actualizareNumarAngajati();
	actualizareCheltuieliCompanie();
}

void companie::afisareDepartamente() {
	system("CLS");
	cout << "Departamente compania " << nume << ": " << endl << endl;
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << "*************" << endl;
		A.buildRaportDepartament((*i));
	}
}

void companie::adaugareDepartament() {
	nrDepartamente = nrDepartamente + 1;
	cin.ignore(256, '\n');
	departament x = A.buildDepartament(v);
	v.push_back(x);
	toateDepartamentele.push_back(x);
}

void companie::stergereDepartament() {
    if(v.size() != 0)
        cout << "Lista departamente din compania " << nume << ": " << endl << endl;
	int c = 0;
	for (auto i = v.begin(); i != v.end(); ++i) {
		c = c + 1;
		cout << c << ". " << (*i).get_numeDepartament() << endl;
	}
	if (c > 1) {
		int opt;
		try {
			cout << "Departamentul sters este: "; cin >> opt;
			if (opt < 1 || opt > c || cin.fail())
				throw 1;
		}
		catch (...) {
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Departamentul sters trebuie sa fie un NUMAR cuprins intre 1 si " << c << ". " << endl;
				cout << "Departamentul sters este: "; cin >> opt;
			} while (opt < 1 || opt > c || cin.fail());
		}
		c = 0;
		for (auto i = v.begin(); i != v.end(); ++i) {
			c = c + 1;
			if (c == opt) {
				v.erase(i);
				nrDepartamente = nrDepartamente - 1;
				break;
			}
		}
	}
	else cout << "\nNu se poate sterge ultimul departament." << endl;
}

void companie::numarAngajatiCompanie() {
    int nr1 = 0, nr2 = 0;
    cout << "NUME COMPANIE: " << nume << endl;
    for(auto a = v.begin(); a != v.end(); ++a){
        nr1 += (*a).get_nrAngajati();
        nr2 += (*a).get_nrManageri();
    }
    cout << "NUMAR ANGAJATI: " << nr1 << " (inclusiv MANAGERI)" << endl;
    cout << "NUMAR MANAGERI: " << nr2 << endl << endl;
    cout << "SITUATIA PE DEPARTAMENTE" << endl << endl;
    for(auto a = v.begin(); a != v.end(); ++a)
        (*a).afisareDepartament();
}

void companie::generareCheltuieliCompanie() {
    system("CLS");
    cout << "NUME COMPANIE: " << nume << endl << endl;
    cout << "CHELTUIELI PE DEPARTAMENTE" << endl << endl;
    int c = 0, sum = 0;
    for(auto a = v.begin(); a != v.end(); ++a) {
        c = c + 1;
        (*a).actualizareCheltuieli();
        cout << c << ". " << (*a).get_numeDepartament() << " ---------- " << (*a).get_CheltuieliDepartament() << endl;
        (*a).afisareCheltuieli();
        sum = sum + (*a).get_CheltuieliDepartament();
    }
    cout << endl << endl;
    cout << "CHELTUIELI TOTALE: " << sum;
}

void companie::pestenAngajati(int n) {
    int k = 0;
    for(auto a = v.begin(); a != v.end(); ++a)
        if ((*a).get_nrAngajati() >= n)
            k++;
    if(k == 0)
        cout << "Nu exista departament in companie cu numar de angajati >= " << n << endl;
    else {
        cout << "LISTA DEPARTAMENTE CU NUMAR DE ANGAJATI >= " << n << ": " << endl << endl;
        int c = 0;
        for(auto a = v.begin(); a != v.end(); ++a) {
            if((*a).get_nrAngajati() >= n)
                cout << ++c << ". " << (*a).get_numeDepartament() << endl;
        }
    }
}

#endif // COMPANIE_H_INCLUDED
