#ifndef _FIRMA_HPP_
#define _FIRMA_HPP_
#include "Klient.hpp"
#include "Spotkanie.hpp"
#include "PrzedstawicielKlienta.hpp"

#include <iostream>
#include <vector>

class PrzedstawicielKlienta;

class Firma : public Klient {
    public:
    Firma(std::string const& nazwa_firmy);

    virtual ~Firma();

    void wypiszPrzedstawicieli();

    void dodajPrzedstawiciela(PrzedstawicielKlienta *ptr);
    
    protected: 
    std::string _getName() const;
    int _getGroupId() const;
    void _spotkajSie(Spotkanie* ptr);

    private:
    std::string _nazwa_firmy;
    std::vector<PrzedstawicielKlienta*>_przedstawiciele;
    const int idGrupy = 1;       //kazda firma ma id grupy 1

};

#endif