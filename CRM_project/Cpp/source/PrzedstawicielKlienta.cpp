#include "PrzedstawicielKlienta.hpp"

using namespace std;

PrzedstawicielKlienta::PrzedstawicielKlienta(string const& imie_nazwisko, string const& pracodawca){
    _imie_nazwisko = imie_nazwisko;         //_imie_nazwisko ustawiane w klasie nadrzednej Pracownik
    idGrupy = 1;        //id kazdego czlonka grupy PrzedstawicielKlienta
    _pracodawca = pracodawca;
}

PrzedstawicielKlienta::~PrzedstawicielKlienta(){
    cout << "Usuwam przedstawiciela: " << this->getName() << "\n";
}
string PrzedstawicielKlienta::getEmployer(){
    return _pracodawca;
}

