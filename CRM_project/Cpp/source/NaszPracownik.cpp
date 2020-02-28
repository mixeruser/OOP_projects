#include "NaszPracownik.hpp"
using namespace std;

NaszPracownik::NaszPracownik(string const& imie_nazwisko){
    _imie_nazwisko = imie_nazwisko;         //_imie_nazwisko w klasie nadrzednej Pracownik
    idGrupy = 0;
}

NaszPracownik::~NaszPracownik(){
    cout << "Usuwam Pracownika.\n";
}

void NaszPracownik::prowadzSpotkanie(string nazwa_pracownika, Spotkanie* ptr){
        Pracownik* pracownik = Pracownik::znajdzPracownika(nazwa_pracownika);
        if(pracownik != nullptr){
            ptr->dolacz(pracownik);
        }
        else{
            cout << "Wpisz poprawne imię i nazwisko swojego pracownika\n";
            string input;
            getline(cin, input);
            NaszPracownik::prowadzSpotkanie(input, ptr);
            return;
        }
}