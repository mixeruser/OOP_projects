#ifndef _PRZEDSTAWICIELKLIENTA_HPP_
#define _PRZEDSTAWICIELKLIENTA_HPP_
#include "Pracownik.hpp"

#include <iostream>

class PrzedstawicielKlienta : public Pracownik{
    public:
    PrzedstawicielKlienta(std::string const& imie_nazwisko, std::string const& pracodawca);
    virtual ~PrzedstawicielKlienta();

    std::string getEmployer();

    private:
    std::string _pracodawca;

};

#endif