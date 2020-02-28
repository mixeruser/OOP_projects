#ifndef _PRACOWNIK_HPP_
#define _PRACOWNIK_HPP_
#include <iostream>
#include <vector>

/* Z Pracownika dziedziczy NaszPracownik, PrzedstawicielKlienta, Konsultant */

class Pracownik{
    public:
    Pracownik();
    virtual ~Pracownik();

    static Pracownik * znajdzPracownika(std::string nazwa_pracownika);
    int getId() const ;
    int getGroupId() const ;    //idGrupy dla NaszegoPracownika = 0, Przed

    std::string getName() const;
    void wypisz();

    protected:
    int idGrupy;
    std::string _imie_nazwisko;         //przypisywane w konstruktorach klas podrzednych

    private:
    int id;
    static int nextId;
    static std::vector<Pracownik*>pracownicy;
};

#endif