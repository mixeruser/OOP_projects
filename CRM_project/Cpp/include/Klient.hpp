#ifndef _KLIENT_HPP_
#define _KLIENT_HPP_
#include <vector>
#include <iostream>

/* Z klienta dziedziczy Firma i OsobaFizyczna */

class Spotkanie;

class Klient{
    public:
    Klient();

    virtual ~Klient();
    static Klient * znajdzKlienta(std::string nazwa_klienta);

    static std::string wypisz_klientow();
     
    std::string getName() const;

    static void spotkajSie(std::string nazwa_klienta, Spotkanie * spotkanie);  //nazwa klienta oraz wskaznik do spotkania

    protected:
    virtual std::string _getName() const = 0;
    virtual int _getGroupId() const = 0;
    int getGroupId() const;
    virtual void _spotkajSie(Spotkanie* spotkanie) = 0;
    
    private:
    static std::vector<Klient*> _klienci;
    const Klient *_ptr;
};

#endif