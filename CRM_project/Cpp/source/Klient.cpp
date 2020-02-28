#include "Klient.hpp"

using namespace std;

Klient::Klient(){
    _klienci.push_back(this);
    std::cout << "Dodaję Klienta do bazy klientów\n";
}

Klient::~Klient(){
    for(size_t i=0; i<_klienci.size(); i++){
        if(_klienci[i] == this){
            _klienci[i] = _klienci.back();
            _klienci.pop_back();
            break;
        }
    }
}

Klient* Klient::znajdzKlienta(std::string nazwa_klienta){
    for(size_t i=0; i<_klienci.size(); i++){
        if(_klienci[i]->getName() == nazwa_klienta){
            std::cout << "Znalazlem klienta o nazwie " << _klienci[i]->getName() << ".\n";
            Klient *_ptr = _klienci[i];      //tutaj _ptr == _klienci[i], czyli
            return _ptr;                    //zwraca wskaźnik do obiektu klasy Firma/OsobaFizyczna
        }
    }
    std::cout << "Brak takiego klienta w bazie\n";
    return nullptr;
}

void Klient::spotkajSie(string nazwa_klienta, Spotkanie* spotkanie){
    Klient *ptr = Klient::znajdzKlienta(nazwa_klienta);
    if(ptr != nullptr){
        ptr->_spotkajSie(spotkanie);
    }
    else{
        cout << "Podaj prawidłową nazwę klienta\n";
        string input;
        getline(cin, input);
        spotkajSie(input, spotkanie);
        return;
    }
}

std::string Klient::wypisz_klientow(){
    std::string klienci_indywidualni = "Klienci:\n\nIndywidualni:\n";
    std::string firmy = "Firmy:\n";
	
    for (size_t i=0; i<_klienci.size(); i++)
        if(_klienci[i]->getGroupId() == 0){
		    klienci_indywidualni += _klienci[i]->getName() + "\n";
        }
        else{
            firmy += _klienci[i]->getName() + "\n";
        }
    klienci_indywidualni += "\n";
    std::string wyjscie = klienci_indywidualni + firmy;
	return wyjscie;
}

std::string Klient::getName() const {
    return _getName();
}

int Klient::getGroupId() const {
    return _getGroupId();
}

std::string _getName();

std::vector<Klient*> Klient::_klienci;