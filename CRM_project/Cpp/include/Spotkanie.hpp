#ifndef _SPOTKANIE_HPP_
#define _SPOTKANIE_HPP_
#include "PrzedstawicielKlienta.hpp"
#include "NaszPracownik.hpp"
#include "Klient.hpp"
#include "Konsultant.hpp"
#include <vector>
#include <iostream>

class Pracownik;
class PrzedstawicielKlienta;
class Klient;
class Konsultant;

class Spotkanie{
    public:
    Spotkanie();
    
    virtual ~Spotkanie();

    void dolacz(Pracownik *ptr);
    void dolaczIndywidualny(Klient* indywidualny);
    void dodajUwagi(std::string uwagi);
    int getId();
    std::string opisSpotkania();
    static void wypiszIdSpotkan();
    static Spotkanie* znajdzPoId(int id);

    private:
    void setDate();
    static std::vector<Spotkanie*> _spotkania;
    int _day, _month, _year, _date;
    int _id;
    static int _nextId;
    std::string _temat, _uwagi;
    
    //uczestnicy spotkania:
    PrzedstawicielKlienta* przedstawiciel;
    Klient* klient_indywidualny;
    Pracownik* prowadzacy;
    Pracownik* konsultant;
};


#endif