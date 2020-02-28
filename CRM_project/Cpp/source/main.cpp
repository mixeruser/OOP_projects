#include <iostream>
#include <string>
#include <fstream>

#include "Firma.hpp"
#include "OsobaFizyczna.hpp"
#include "NaszPracownik.hpp"
#include "PrzedstawicielKlienta.hpp"
#include "Spotkanie.hpp"

using namespace std;

int main(){

    string input;
    NaszPracownik* p1 = new NaszPracownik("Kazimierz Dolny");
    NaszPracownik* p2 = new NaszPracownik("Marian Kop");
    NaszPracownik* p3 = new NaszPracownik("Anna Waza");

    Konsultant* k1 = new Konsultant("Zbigniew Mrugalski");
    Konsultant* k2 = new Konsultant("Antoni Las");

    cout << "Witaj w programie CRM\n\nTwoi pracownicy:\n" << p1->getName() << "\n" <<
        p2->getName() << "\n" << p3->getName() << "\nTwoi konsultanci: \n" << k1->getName() << "\n" <<
        k2->getName() << "\n\n";

    new OsobaFizyczna("K1");
    Spotkanie* s = new Spotkanie();
    cout << s->opisSpotkania();
    while(input != "exit"){

        getline(cin, input);

        /*KLIENCI*/
        if(input == "dodaj klienta"){
            cout << "Jeśli Klient jest firmą, wpisz: firma\n"
                "Jeśli Klient jest osobą fizyczną, wpisz: indywidualny\n"
                "Typ Klienta: ";
            cin >> input;
            cin.ignore();

            if(input == "firma"){
                cout << "Podaj nazwę Firmy: ";
                getline(cin, input);
                if(Klient::znajdzKlienta(input) == nullptr){
                    new Firma(input);
                }
                else{cout << "Firma " << input << " znajduje się już w bazie klientów.\n";}
            }
            else if(input == "indywidualny"){
                cout << "Podaj imię i nazwisko: ";
                getline(cin, input);
                if(Klient::znajdzKlienta(input) == nullptr){
                    new OsobaFizyczna(input);
                }
                else{
                    cout << "Klient " << input << " znajduje się już w bazie klientów.\n";
                }
            }
            else{
                cout << "Błąd(!): Podałeś zły typ\n";
            }
        }

        if(input == "usun klienta"){
            cout << "Podaj nazwe klienta do usuniecia: ";
            getline(cin, input);
            delete Klient::znajdzKlienta(input);
        }

        if(input == "wypisz klientow"){
            cout << Klient::wypisz_klientow();
        }

        /*PRZEDSTAWICIELE*/
        if(input == "dodaj przedstawiciela"){
            cout << "Przedstawiciela której firmy chcesz dodać?\n";
            getline(cin, input);
            Firma *ptr = (Firma*)Klient::znajdzKlienta(input);
            if(ptr != nullptr){
                string pracodawca = ptr->getName();
                cout << "Podaj imię i nazwisko nowego przedstawiciela " << ptr->getName() << ": ";
                getline(cin, input);
                PrzedstawicielKlienta *pk = new PrzedstawicielKlienta(input, pracodawca);
                ptr->dodajPrzedstawiciela(pk);
            }
        }

        if(input == "wypisz przedstawicieli"){
            cout << "Firma: ";
            cin >> input;
            Firma *ptr = (Firma*)Klient::znajdzKlienta(input);
            ptr->wypiszPrzedstawicieli();
        }

        /*SPOTKANIA*/
        if(input == "dodaj spotkanie"){
            Spotkanie* ptr = new Spotkanie();
        }
        if(input == "spotkanie info"){
            int id;
            cout << "Id spotkan:\n";
            Spotkanie::wypiszIdSpotkan();
            cout << "Informacje o którym spotkaniu chcesz uzyskać?\n";
            cin >> id;
            cout << Spotkanie::znajdzPoId(id)->opisSpotkania();
        }
        
        /*HELP*/
        if(input == "help"){
            ifstream f("read/help.txt");
            if (f.is_open()){
                cout << f.rdbuf();
            }
        }

    }
    return 0;
}
