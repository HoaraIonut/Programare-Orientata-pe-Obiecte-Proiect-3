#ifndef DEPARTAMENT_H_INCLUDED
#define DEPARTAMENT_H_INCLUDED
#include <vector>
#include <string>
#include "angajat.h"

using namespace std;

class departament {
	static vector<angajat> totiAngajatii;
	string nume;
	vector<angajat> v;
	int n = 0, nrManager = 0;
	float cheltuieliDepartament = 0;
public:
	departament(int n, vector<angajat> v, string nume) { this->n = n; this->v = v; this->nume = nume; }
	departament(int n, string nume) { this->n = n; this->nume = nume; }
	float get_CheltuieliDepartament() {
	    actualizareCheltuieli();
        return cheltuieliDepartament;
    }
	string get_numeDepartament() { return nume; }
	vector<angajat> get_v() { return v; }
	static vector<angajat> get_totiAngajatii() { return totiAngajatii; }
	int get_nrAngajati() { return n; }
	int get_nrManageri() { return nrManager; }
	void citireAngajati();
	void actualizareCheltuieli();
	void afisareCheltuieli();
	void afisareDepartament();
	void afisareManager();
	void adaugareAngajat();
	void eliminareAngajat();
};

vector<angajat> departament::totiAngajatii;

void departament::afisareCheltuieli(){
    int c = 0;
    for(auto a = v.begin(); a != v.end(); ++a){
        c = c + 1;
        cout << "\t" << c << ". " << (*a).get_nume() << " ---------- " << (*a).get_salariuBrut() << endl;
    }
}

void departament::citireAngajati() {
	for (int i = 0; i < n; i++) {
		system("CLS");
		string nume;
		int luna, an, zi;
		float salariu;
		bool manager;
		if (i == 0)
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Primul angajat introdus este intotdeauna manager." << endl; manager = true;
		}
		else {
			string opt;
			try {
				cout << "Angajatul introdus este manager: " << endl;
				cout << "1. DA" << endl << "2. NU" << endl;
				cout << "Optiunea dumneavoastra: "; cin >> opt;
				if (opt != "1" && opt != "2")
					throw 1;
			}
			catch (...) {
				do {
					cout << "Raspunsul poate fi doar 1 sau 2." << endl;
					cout << "Angajatul introdus este manager: " << endl;
					cout << "1. DA" << endl << "2. NU" << endl;
					cout << "Optiunea dumneavoastra: "; cin >> opt;
				} while (opt != "1" && opt != "2");
			}
			if (opt == "1")
				manager = true;
			if (opt == "2")
				manager = false;
			cin.clear();
			cin.ignore(256, '\n');
		}
		cout << endl << endl;
		bool verificare = true;
		try {
			cout << "Nume: "; getline(cin, nume);
			for (auto i = v.begin(); i != v.end(); ++i)
				if ((*i).get_nume() == nume)
					verificare = false;
			for (auto i = totiAngajatii.begin(); i != totiAngajatii.end(); ++i)
				if ((*i).get_nume() == nume)
					verificare = false;
			if (!verificare)
				throw 1;
		}
		catch (...) {
			do {
				verificare = true;
				cout << "Numele introdus este deja folosit. Introduceti un alt nume." << endl;
				cout << "Nume: "; getline(cin, nume);
				for (auto i = v.begin(); i != v.end(); ++i)
					if ((*i).get_nume() == nume)
						verificare = false;
				for (auto i = totiAngajatii.begin(); i != totiAngajatii.end(); ++i)
					if ((*i).get_nume() == nume)
						verificare = false;
			} while (!verificare);
		}
		try {
			cout << "Salariu: "; cin >> salariu;
			if (cin.fail() || salariu < 1)
				throw 1;
		}
		catch (...) {
			cout << "Salariul trebuie sa fie un NUMAR > 0." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Salariu: "; cin >> salariu;
			} while (cin.fail() || salariu < 1);
		}
		try {
			cout << "An angajare: "; cin >> an;
			if (cin.fail() || an < 2000 || an > 2022)
				throw 1;
		}
		catch (...) {
			cout << "Anul trebuie sa fie un NUMAR > 1999 si NUMAR < 2022." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "An angajare: "; cin >> an;
			} while (cin.fail() || an < 2000 || an > 2022);
		}
		try {
			cout << "Luna angajare: "; cin >> luna;
			if (cin.fail() || luna < 1 || luna > 12)
				throw 1;
		}
		catch (...) {
			cout << "Luna trebuie sa fie un NUMAR > 0 si NUMAR < 13." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Luna angajare: "; cin >> luna;
			} while (cin.fail() || luna < 1 || luna > 12);
		}
		try {
			cout << "Zi angajare: "; cin >> zi;
			if (cin.fail() || zi < 1) {
				throw 1;
			}
			if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
				if (zi > 31) {
					throw 1;
				}
			if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
				if (zi > 30) {
					throw 1;
				}
			if (luna == 2)
				if (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0)) {
					if (zi > 29)
						throw 1;
				}
				else {
					if (zi > 28) {
						throw 1;
					}
				}
		}
		catch (...) {

			cout << "Ziua introdusa trebuie sa fie un NUMAR > 0" << endl;
			cout << "Daca luna introdusa este 1 3 5 7 8 10 12 atunci NUMAR < 32" << endl;
			cout << "Daca luna introdusa este 4 6 9 11 atunci NUMAR < 31" << endl;
			cout << "Daca luna introdusa este 2 si ANUL este bisect atunci NUMAR < 30" << endl;
			cout << "Daca luna introdusa este 2 si ANUL nu este bisect atunci NUMAR < 29" << endl;
			int ok = 1;
			while (ok) {
			    cin.clear(); cin.ignore(256, '\n');
				ok = 0;
				cout << "Zi angajare: "; cin >> zi;
				if (cin.fail() || zi < 1) {
					ok = 1;
				}
				if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
					if (zi > 31) {
						ok = 1;
					}
				if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
					if (zi > 30) {
						ok = 1;
					}
				if (luna == 2)
					if (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0)) {
						if (zi > 29)
							ok = 1;
					}
					else {
						if (zi > 28) {
							ok = 1;
						}
					}
			}
		}
		string dataAngajare = "";
		if (zi < 10)
			dataAngajare = dataAngajare + "0" + to_string(zi);
		else
			dataAngajare = dataAngajare + to_string(zi);
		if (luna < 10)
			dataAngajare = dataAngajare + ".0" + to_string(luna);
		else
			dataAngajare = dataAngajare + '.' + to_string(luna);
		dataAngajare = dataAngajare + "." + to_string(an);
		if (manager) {
			angajat A(nume, dataAngajare, salariu, true, "MANAGER");
			v.push_back(A);
			totiAngajatii.push_back(A);
			nrManager++;
		}
		else {
			angajat A(nume, dataAngajare, salariu, true);
			cout << endl;
			cout << "Manageri existenti in companie: " << endl;
			int c = 0;
			for (auto i = v.begin(); i != v.end(); ++i) {
				if ((*i).get_numeManager() == "MANAGER") {
					c = c + 1;
					cout << c << ". " << (*i).get_nume() << endl;
				}
			}
			cout << endl << endl;
			int opt;
			try {
				cout << "Managerul angajatului introdus este: "; cin >> opt;
				if (cin.fail() || opt < 1 || opt > c)
					throw 1;
			}
			catch (...) {
				cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
				do {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Managerul angajatului introdus este: "; cin >> opt;
				} while (cin.fail() || opt < 1 || opt > c);
			}
			int c1 = 0;
			for (auto i = v.begin(); i != v.end(); ++i) {
				if ((*i).get_numeManager() == "MANAGER") {
					c1 = c1 + 1;
					if (c1 == opt)
						A.set_numeManager((*i).get_nume());
				}
			}
			v.push_back(A);
			totiAngajatii.push_back(A);
		}

	}
	system("CLS");
}

void departament::actualizareCheltuieli() {
	cheltuieliDepartament = 0;
	for (auto i = v.begin(); i != v.end(); ++i) {
		cheltuieliDepartament = cheltuieliDepartament + (*i).get_salariuBrut();
	}
}

void departament::afisareDepartament() {
	cout << "Departament " << nume << endl << endl;
	actualizareCheltuieli();
	cout << "Cheltuieli departament: " << cheltuieliDepartament << endl << endl;
	for (auto i = v.begin(); i != v.end(); ++i) {
		if ((*i).get_numeManager() == "MANAGER") {
			cout << "MANAGER: " << (*i).get_nume() << endl;
			for (auto j = v.begin(); j != v.end(); ++j)
				if ((*j).get_numeManager() == (*i).get_nume())
					cout << "---" << (*j).get_nume() << endl;
			cout << endl;
		}
	}
	cout << endl << endl;
}
//
//void departament::afisareManager(string numeManager) {
//	bool ok = false;
//	angajat A("", "", 0, true);
//	for (auto i = v.begin(); i != v.end(); ++i) {
//		if ((*i).get_numeManager() == "MANAGER")
//			if ((*i).get_nume() == numeManager)
//			{
//				ok = true;
//				A = (*i);
//			}
//	}
//	if (!ok)
//		cout << "Persoana cautata nu este manager in acest departament." << endl;
//	else {
//		cout << "MANAGER: " << numeManager << endl << endl;
//		cout << "SALARIU: " << A.get_salariuBrut() << endl;
//		cout << "DATA ANGAJARE IN COMPANIE: " << A.get_dataAngajarii() << endl;
//		cout << "PERSOANE SUBORDONATE: " << endl;
//		for (auto a = v.begin(); a != v.end(); ++a) {
//			if ((*a).get_numeManager() == numeManager)
//				cout << "---> " << (*a).get_nume() << endl;
//		}
//	}
//}

void departament::afisareManager(){
    system("CLS");
    int c = 0;
    for(auto a = v.begin(); a != v.end(); ++a){
        if((*a).get_numeManager() == "MANAGER")
            c = c + 1;
    }
    if(c == 0)
        cout << "Departamentul selectat nu are manageri." << endl;
    else {
        c = 0;
        cout << "LISTA MANAGERI IN DEPARTAMENTUL " << nume << endl << endl;
        for(auto a = v.begin(); a != v.end(); ++a){
            if((*a).get_numeManager() == "MANAGER"){
                c = c + 1;
                cout << c << ". " << (*a).get_nume() << endl;
            }
        }
        cout << endl << endl;
        int opt;
        try {
			cout << "Managerul cautat este: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Managerul cautat: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		c = 0;
        system("CLS");
        for(auto a = v.begin(); a != v.end(); ++a){
            if((*a).get_numeManager() == "MANAGER"){
                c = c + 1;
                if(c == opt) {
                    cout << "MANAGER: " << (*a).get_nume() << endl << endl;
                    cout << "SALARIU: " << (*a).get_salariuBrut() << endl;
                    cout << "DATA ANGAJARE IN COMPANIE: " << (*a).get_dataAngajarii() << endl << endl;
                    int k = 0;
                    for (auto y = v.begin(); y != v.end(); ++y) {
                        if ((*y).get_numeManager() == (*a).get_nume())
                            k++;
                    }
                    if(k != 0)
                        cout << "PERSOANE SUBORDONATE: " << endl;
                    for (auto y = v.begin(); y != v.end(); ++y) {
                        if ((*y).get_numeManager() == (*a).get_nume())
                            cout << "---> " << (*y).get_nume() << endl;
                    }
                }
            }
        }
    }
}

void departament::adaugareAngajat() {
	n = n + 1;
	system("CLS");
	string nume;
	int luna, an, zi;
	float salariu;
	bool manager;
	string opt;
	try {
		cout << "Angajatul introdus este manager: " << endl;
		cout << "1. DA" << endl << "2. NU" << endl;
		cout << "Optiunea dumneavoastra: "; cin >> opt;
		if (opt != "1" && opt != "2")
			throw 1;
	}
	catch (...) {
		do {
			cout << "Raspunsul poate fi doar 1 sau 2." << endl;
			cout << "Angajatul introdus este manager: " << endl;
			cout << "1. DA" << endl << "2. NU" << endl;
			cout << "Optiunea dumneavoastra: "; cin >> opt;
		} while (opt != "1" && opt != "2");
	}
	if (opt == "1")
		manager = true;
	if (opt == "2")
		manager = false;
	cin.clear();
	cin.ignore(256, '\n');
	cout << endl << endl;
	bool verificare = true;
	try {
		cout << "Nume: "; getline(cin, nume);
		for (auto i = v.begin(); i != v.end(); ++i)
			if ((*i).get_nume() == nume)
				verificare = false;
		for (auto i = totiAngajatii.begin(); i != totiAngajatii.end(); ++i)
			if ((*i).get_nume() == nume)
				verificare = false;
		if (!verificare)
			throw 1;
	}
	catch (...) {
		do {
			verificare = true;
			cout << "Numele introdus este deja folosit. Introduceti un alt nume." << endl;
			cout << "Nume: "; getline(cin, nume);
			for (auto i = v.begin(); i != v.end(); ++i)
				if ((*i).get_nume() == nume)
					verificare = false;
			for (auto i = totiAngajatii.begin(); i != totiAngajatii.end(); ++i)
				if ((*i).get_nume() == nume)
					verificare = false;
		} while (!verificare);
	}
	try {
		cout << "Salariu: "; cin >> salariu;
		if (cin.fail() || salariu < 1)
			throw 1;
	}
	catch (...) {
		cout << "Salariul trebuie sa fie un NUMAR > 0." << endl;
		do {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Salariu: "; cin >> salariu;
		} while (cin.fail() || salariu < 1);
	}
	try {
		cout << "An angajare: "; cin >> an;
		if (cin.fail() || an < 2000 || an > 2022)
			throw 1;
	}
	catch (...) {
		cout << "Anul trebuie sa fie un NUMAR > 1999 si NUMAR < 2022." << endl;
		do {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "An angajare: "; cin >> an;
		} while (cin.fail() || an < 2000 || an > 2022);
	}
	try {
		cout << "Luna angajare: "; cin >> luna;
		if (cin.fail() || luna < 1 || luna > 12)
			throw 1;
	}
	catch (...) {
		cout << "Luna trebuie sa fie un NUMAR > 0 si NUMAR < 13." << endl;
		do {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Luna angajare: "; cin >> luna;
		} while (cin.fail() || luna < 1 || luna > 12);
	}
	try {
		cout << "Zi angajare: "; cin >> zi;
		if (cin.fail() || zi < 1) {
			throw 1;
		}
		if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
			if (zi > 31) {
				throw 1;
			}
		if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
			if (zi > 30) {
				throw 1;
			}
		if (luna == 2)
			if (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0)) {
				if (zi > 29)
					throw 1;
			}
			else {
				if (zi > 28) {
					throw 1;
				}
			}
	}
	catch (...) {
		cout << "Ziua introdusa trebuie sa fie un NUMAR > 0" << endl;
		cout << "Daca luna introdusa este 1 3 5 7 8 10 12 atunci NUMAR < 32" << endl;
		cout << "Daca luna introdusa este 4 6 9 11 atunci NUMAR < 31" << endl;
		cout << "Daca luna introdusa este 2 si ANUL este bisect atunci NUMAR < 30" << endl;
		cout << "Daca luna introdusa este 2 si ANUL nu este bisect atunci NUMAR < 29" << endl;
		int ok = 1;
		while (ok) {
            cin.clear(); cin.ignore(256, '\n');
			ok = 0;
			cout << "Zi angajare: "; cin >> zi;
			if (cin.fail() || zi < 1) {
				ok = 1;
			}
			if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
				if (zi > 31) {
					ok = 1;
				}
			if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
				if (zi > 30) {
					ok = 1;
				}
			if (luna == 2)
				if (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0)) {
					if (zi > 29)
						ok = 1;
				}
				else {
					if (zi > 28) {
						ok = 1;
					}
				}
		}
	}
	string dataAngajare = "";
	if (zi < 10)
		dataAngajare = dataAngajare + "0" + to_string(zi);
	else
		dataAngajare = dataAngajare + to_string(zi);
	if (luna < 10)
		dataAngajare = dataAngajare + ".0" + to_string(luna);
	else
		dataAngajare = dataAngajare + '.' + to_string(luna);
	dataAngajare = dataAngajare + "." + to_string(an);
	if (manager) {
		angajat A(nume, dataAngajare, salariu, true, "MANAGER");
		v.push_back(A);
		totiAngajatii.push_back(A);
		nrManager++;
	}
	else {
		angajat A(nume, dataAngajare, salariu, true);
		cout << endl;
		cout << "Manageri existenti in companie: " << endl;
		int c = 0;
		for (auto i = v.begin(); i != v.end(); ++i) {
			if ((*i).get_numeManager() == "MANAGER") {
				c = c + 1;
				cout << c << ". " << (*i).get_nume() << endl;
			}
		}
		cout << endl << endl;
		int opt;
		try {
			cout << "Managerul angajatului introdus este: "; cin >> opt;
			if (cin.fail() || opt < 1 || opt > c)
				throw 1;
		}
		catch (...) {
			cout << endl << "Valoarea introdusa trebuie sa fie o cifra cuprinsa intre 1 si " << c << "." << endl;
			do {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Managerul angajatului introdus este: "; cin >> opt;
			} while (cin.fail() || opt < 1 || opt > c);
		}
		int c1 = 0;
		for (auto i = v.begin(); i != v.end(); ++i) {
			if ((*i).get_numeManager() == "MANAGER") {
				c1 = c1 + 1;
				if (c1 == opt)
					A.set_numeManager((*i).get_nume());
			}
		}
		v.push_back(A);
		totiAngajatii.push_back(A);
	}

}

void departament::eliminareAngajat() {
	system("CLS");
	departament::afisareDepartament();
	string numeAngajat;
	cin.ignore(256, '\n');
	cout << "Numele angajatului eliminat: "; getline(cin, numeAngajat);
	cout << endl;
	bool ok = false;
	for (auto a = v.begin(); a != v.end(); ++a)
		if ((*a).get_nume() == numeAngajat) {
			ok = true;
			if ((*a).get_numeManager() == "MANAGER")
				if (nrManager > 1) {
					int c = 0;
					cout << "Lista celorlalti manageri din departament: " << endl;
					for (auto i = v.begin(); i != v.end(); ++i)
						if ((*i).get_numeManager() == "MANAGER" && i != a) {
							c = c + 1;
							cout << c << ". " << (*i).get_nume() << endl;
						}
					int nr;
					try {
						cout << "Managerul care o sa preia angajatii ramasi liberi este: "; cin >> nr;
						if (nr < 1 || nr > c || cin.fail())
							throw 1;
					}
					catch (...) {
						do {
							cin.clear();
							cin.ignore(256, '\n');
							cout << "Valoarea introdusa trebuie sa fie un NUMAR cuprins intre 1 si " << c << "." << endl;
							cout << "Managerul care o sa preia angajatii ramasi liberi este: "; cin >> nr;
						} while (nr < 1 || nr > c || cin.fail());
					}
					c = 0;
					string inlocuitor;
					for (auto i = v.begin(); i != v.end(); ++i)
						if ((*i).get_numeManager() == "MANAGER" && i != a) {
							c = c + 1;
							if (c == nr)
								inlocuitor = (*i).get_nume();
						}
					for (auto i = v.begin(); i != v.end(); ++i)
						if ((*i).get_numeManager() == (*a).get_nume())
							(*i).set_numeManager(inlocuitor);
					v.erase(a); totiAngajatii.erase(a);
					n = n - 1;
				}
				else cout << "Intr-un departament trebuie sa existe cel putin 1 manager." << endl;
			else {
				if (n > 1) { v.erase(a); totiAngajatii.erase(a); n = n - 1; }
				else cout << "In departament trebuie sa existe cel putin 1 angajat." << endl;
			}
			if (ok)
				break;
		}
	if (!ok)
		cout << "Persoana introdusa nu este in acest departament." << endl;

}

#endif // DEPARTAMENT_H_INCLUDED
