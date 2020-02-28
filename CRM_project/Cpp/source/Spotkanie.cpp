#include "Spotkanie.hpp"

using namespace std;

Spotkanie::Spotkanie(){
    konsultant = nullptr;
    prowadzacy = nullptr;
    konsultant = nullptr;
    klient_indywidualny = nullptr;
    przedstawiciel = nullptr;
    _id = _nextId++;
    string input;
    cout << "Z kim odbywa się spotkanie? Wpisz imię i nazwisko klienta, bądź nazwę firmy.\n";
    getline(cin, input);
    Klient::spotkajSie(input, this);
    cout << "Jaki jest temat spotkania?\n";
    getline(cin, input);
    _temat = input;
    cout << "Który z Twoich pracowników prowadzi spotkanie z klientem?\n";
    getline(cin, input);
    NaszPracownik::prowadzSpotkanie(input, this);
    cout << "Czy w spotkaniu bierze udział konsultant? Wpisz 'tak' lub 'nie'.\n";
    getline(cin, input);
    if(input == "tak"){
        cout << "Podaj imię i nazwisko swojego konsultanta\n";
        getline(cin, input);
        Konsultant::konsultuj(input, this);
    }else{}

    Spotkanie::setDate();
    cout << "Spotkanie zapisane.\n\n";
    _spotkania.push_back(this);
}

Spotkanie::~Spotkanie(){
    for(size_t i=0; i<_spotkania.size(); i++){
        if(_spotkania[i] == this){
            _spotkania[i] = _spotkania.back();
            _spotkania.pop_back();
            break;
        }
    }
    cout << "Spotkanie usunięte\n";
}

void Spotkanie::setDate() {
    int day, month, year;
    int c = 0;
    cout << "Podaj datę w spotkania formacie DD/MM/RRRR\nData: ";
            cin >> day;
             if(cin.get() != '/'){
                cout << "Zły format, spodziewany slash: '/'\n";
                c++;
            }
            else{
                cin >> month;
                if(cin.get() != '/'){
                    cout << "Zły format, spodziewany '/'\n";
                    c++;
                }
                else{
                    cin >> year;
                    _day = day;
                    _month = month;
                    _year = year;
                    cout << "Data ustawiona pomyślnie\n";
                }
            }
            while(cin.fail()){
                cin.clear();
                cout << "Błąd(!): Data nie powinna zawierać liter. Usuwam spotkanie.\n";
            }
            if(c != 0){
                setDate();
            }
}

void Spotkanie::dolacz(Pracownik *ptr){
    if(ptr->getGroupId() == 1){     //jesli pracownik jest przedstawicielem klienta
        przedstawiciel = (PrzedstawicielKlienta*)ptr;
        cout << ptr->getName() << " jest przedstawicielem " << przedstawiciel->getEmployer() << " na spotkaniu.\n";
    }
    else if(ptr->getGroupId() == 0){
        prowadzacy = (NaszPracownik*)ptr;
        cout << "Spotkanie prowadzi " << prowadzacy->getName() << "\n";
    }
    else if(ptr->getGroupId() == 2){
        konsultant = (Konsultant*)ptr;
        cout << "W spotkaniu bierze udział konsultant " << konsultant->getName() << "\n";
    }
}

void Spotkanie::dolaczIndywidualny(Klient* ptr){
    klient_indywidualny = (Klient*)ptr;
    cout << "W spotkaniu weźmie udział klient indywidualny " << klient_indywidualny->getName() << "\n";
}

string Spotkanie::opisSpotkania(){
    string s = "Id spotkania: " + to_string(_id) + "  Data spotkania: " + to_string(_day) + "." + to_string(_month) + "." + to_string(_year) + "\n" + "Klient";
    if(klient_indywidualny != nullptr){
        s += "(indywidualny): " + klient_indywidualny->getName() + "\n";
    }
    else if(przedstawiciel != nullptr){
        s += "(firma): " + przedstawiciel->getEmployer() + ", w spotkaniu brał udział przedstawiciel " + przedstawiciel->getName() + "\n";
    }
    s += "Temat spotkania: " + _temat + "\nSpotkanie prowadził/a " + prowadzacy->getName() + "\n";
    if(konsultant != nullptr){
        s += "W spotkaniu brał udział konsultant "  + konsultant->getName() + "\nUwagi i spostrzeżenia konsultanta: " + _uwagi + "\n";
    }
    return s;
}

void Spotkanie::dodajUwagi(string uwagi){
    _uwagi = uwagi;
}

void Spotkanie::wypiszIdSpotkan(){
    for(auto s : _spotkania){
        cout << s->getId() << "\n";
    }
}

Spotkanie* Spotkanie::znajdzPoId(int id){
    for(auto s : _spotkania){
        if(s->getId() == id){
            return s;
            break;
        }
    }
    cout << "Brak spotkania o takim id\n";
    return nullptr;
}

int Spotkanie::getId(){ return _id; }
int Spotkanie::_nextId = 0;
vector<Spotkanie*> Spotkanie::_spotkania;