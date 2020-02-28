#ifndef _KONSULTANT__HPP__
#define _KONSULTANT__HPP__
#include "Pracownik.hpp"
#include "Spotkanie.hpp"
#include <string>


class Konsultant : public Pracownik{
    public:
    Konsultant(std::string const& imie_nazwisko);

    virtual ~Konsultant();

    static void konsultuj(std::string nazwa_konsultanta, Spotkanie* ptr);
};

#endif