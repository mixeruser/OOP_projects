#include "Konsultant.hpp"

using namespace std;

Konsultant::Konsultant(std::string const& imie_nazwisko){
    _imie_nazwisko = imie_nazwisko;         //_imie_nazwisko ustawiane w klasie nadrzednej Pracownik
    idGrupy = 2;        //id kazdego czlonka grupy Konsultant
}

Konsultant::~Konsultant(){}

void Konsultant::konsultuj(string nazwa_konsultanta, Spotkanie* ptr){
    Pracownik* konsultant = Pracownik::znajdzPracownika(nazwa_konsultanta);
    if(konsultant != nullptr){
        ptr->dolacz(konsultant);
        cout << "Jakie są rady i uwagi konsultanta?\n";
        string input;
        getline(cin, input);
        ptr->dodajUwagi(input);
    }
    else{
        cout << "Wpisz poprawne imię i nazwisko swojego konsultanta\n";
        string input;
        getline(cin, input);
        konsultuj(input, ptr);
        return;
    }
}