#include"OsobaFizyczna.hpp"

using namespace std;

OsobaFizyczna::OsobaFizyczna(std::string const& imie_nazwisko){     //(stala referencja) nie mozna zmienic nazwy klienta, jesli ma byc mozliwa zmiana zamiast const& użyć &
    _imie_nazwisko = imie_nazwisko;
    std::cout << "Zapisano Klienta " << OsobaFizyczna::_getName() << "\n";
}

OsobaFizyczna::~OsobaFizyczna(){
    std::cout << "Usuwam Klienta(osoba fizyczna): " << OsobaFizyczna::_getName() << "\n";
}

std::string OsobaFizyczna::_getName() const {
    return _imie_nazwisko;
}

int OsobaFizyczna::_getGroupId() const {
    return idGrupy;
}

void OsobaFizyczna::_spotkajSie(Spotkanie* ptr){
    ptr->dolaczIndywidualny(this);
}