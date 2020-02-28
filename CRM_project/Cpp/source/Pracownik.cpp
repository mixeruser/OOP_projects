#include "Pracownik.hpp"

using namespace std;

Pracownik::Pracownik(){
    id = nextId++;
    pracownicy.push_back(this);
}

Pracownik::~Pracownik(){
    for(size_t i=0; i<pracownicy.size(); i++){
        if(pracownicy[i] == this){
            pracownicy[i] = pracownicy.back();
            pracownicy.pop_back();
        }
    }
}

Pracownik * Pracownik::znajdzPracownika(string nazwa_pracownika){
    for(auto pracownik : pracownicy){
        if(pracownik->getName() == nazwa_pracownika){
            cout << "Znalazlem pracownika o nazwie " << pracownik->getName() << "\n";
            Pracownik *_ptr = pracownik;      //tutaj _ptr == _klienci[i], czyli
            return _ptr;                    //zwraca wskaźnik do obiektu klasy Firma/OsobaFizyczna
        }
    }
    cout << "Brak takiego pracownika\n";
    return nullptr;
}

string Pracownik::getName() const {
    return _imie_nazwisko;
}

int Pracownik::getId() const { return id; }
int Pracownik::getGroupId() const { return idGrupy; }

vector<Pracownik*> Pracownik::pracownicy;
int Pracownik::nextId = 0;