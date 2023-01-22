#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

using namespace std;

class angajat {
	string nume, dataAngajarii, numeManager;
	float salariuBrut;
	bool manager;
public:
	angajat(string, string, float, bool, string);
	string get_numeManager();
	string get_nume();
	string get_dataAngajarii();
	float get_salariuBrut();
	void set_numeManager(string);
	void afisareAngajat();
};

angajat::angajat(string nume = "", string dataAngajarii = "", float salariuBrut = 0, bool manager = false, string numeManager = "MANAGER") {
	this->nume = nume;
	this->dataAngajarii = dataAngajarii;
	this->salariuBrut = salariuBrut;
	this->manager = manager;
	this->numeManager = numeManager;
}


string angajat::get_numeManager() {
	return numeManager;
}

string angajat::get_nume() {
	return nume;
}

string angajat::get_dataAngajarii() {
	return dataAngajarii;
}

void angajat::set_numeManager(string numeManager) {
	this->numeManager = numeManager;
}

float angajat::get_salariuBrut() {
	return salariuBrut;
}

void angajat::afisareAngajat() {
	cout << "NUME ANGAJAT: " << nume << endl;
	cout << "STATUS: ";
	if (numeManager == "MANAGER")
		cout << "manager" << endl;
	else {
		cout << "angajat" << endl;
		cout << "NUME MANAGER: " << numeManager << endl;
	}
	cout << "DATA ANGAJARII: " << dataAngajarii << endl;
	cout << "SALARIU BRUT: " << salariuBrut << endl;
}

#endif // ANGAJAT_H_INCLUDED
