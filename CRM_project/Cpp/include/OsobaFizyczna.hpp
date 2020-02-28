#ifndef _OSOBAFIZYCZNA_HPP_
#define _OSOBAFIZYCZNA_HPP_
#include "Klient.hpp"
#include "Spotkanie.hpp"
#include <iostream>

class OsobaFizyczna : public Klient{
public:
    OsobaFizyczna(std::string const& imie_nazwisko);     //(stala referencja) nie mozna zmienic nazwy klienta, jesli ma byc mozliwa zmiana zamiast const& użyć &

    virtual ~OsobaFizyczna();

    protected:
    std::string _getName() const;
    int _getGroupId() const;
    void _spotkajSie(Spotkanie* ptr);

    private:
    std::string _imie_nazwisko;
    const int idGrupy = 0;      //kazdy klient indywidualny ma id grupy = 0

};

#endif