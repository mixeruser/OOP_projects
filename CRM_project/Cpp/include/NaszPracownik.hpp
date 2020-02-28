#ifndef _NASZPRACOWNIK_HPP
#define _NASZPRACOWNIK_HPP
#include "Spotkanie.hpp"
#include "Pracownik.hpp"
#include <string>
class Spotkanie;
class Pracownik;

class NaszPracownik : public Pracownik{
    public:
    NaszPracownik(std::string const& imie_nazwisko);

    virtual ~NaszPracownik();

    static void prowadzSpotkanie(std::string nazwa_pracownika, Spotkanie* ptr);

};

#endif