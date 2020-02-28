#include "Firma.hpp"

using namespace std;

Firma::Firma(string const& nazwa_firmy){           //(stala referencja) nie mozna zmienic nazwy klienta, jesli ma byc mozliwa zmiana zamiast const& użyć &  

    _nazwa_firmy = nazwa_firmy;
    cout << "Zapisano Firmę " << Firma::_getName() << "\n";
}

Firma::~Firma(){
    cout << "Usuwam przedstawicieli.\n";
    for(auto p : _przedstawiciele){
        cout << "Znalazłem przedstawiciela firmy: " << p->getName() << "\n";
        delete p;
    }
    cout << "Usuwam Klienta(firmę): " << Firma::_getName() << "\n";
}

void Firma::wypiszPrzedstawicieli(){
    cout << "Przedstawiciele " << this->_getName() << " to:\n";
    for(auto p : _przedstawiciele){
        cout << p->getName() << "\n";
    }
}

void Firma::dodajPrzedstawiciela(PrzedstawicielKlienta *ptr){
    _przedstawiciele.push_back(ptr);
    cout << ptr->getName() << " Dodany do przedstawicieli firmy " << this->_getName() << "\n";
}

string Firma::_getName() const {
    return _nazwa_firmy;
}

int Firma::_getGroupId() const {
    return idGrupy;
}

void Firma::_spotkajSie(Spotkanie* ptr){
    cout << "Który z przedstawicieli będzie na spotkaniu? ";
    Firma::wypiszPrzedstawicieli();
    string input;
    getline(cin, input);
    for(auto p : _przedstawiciele){
        if(p->getName() == input){
            ptr->dolacz(p);
            break;
        }
        else{
            cout << "Nie ma takiego przedstawiciela.\n";
            Firma::_spotkajSie(ptr);
        }
    }

}