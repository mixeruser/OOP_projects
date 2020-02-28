from abc import ABC, abstractmethod


class Pracownik(ABC):
    __pracownicy = []
    def __init__(self):
        Pracownik.__pracownicy.append(self)


    @staticmethod
    def wypiszPracownikow():
        for p in Pracownik.__pracownicy:
            print(p)


    @staticmethod
    def znajdzPracownika(nazwa_pracownika):
        for p in Pracownik.__pracownicy:
            if p.getName() == nazwa_pracownika:
                return p


    @abstractmethod
    def getName(self):
        pass


    @abstractmethod
    def getGroupId(self):
        pass



class PrzedstawicielKlienta(Pracownik):
    __idGrupy = 1
    def __init__(self, imie_nazwisko, pracodawcaptr):
        super().__init__()
        self.__imie_nazwisko = imie_nazwisko
        self.__pracodawcaptr = pracodawcaptr
        

    def __str__(self):
	    return "Przedstawiciel firmy %s: %s" % (self.getEmployer(), self._PrzedstawicielKlienta__imie_nazwisko)


    def getName(self):
        return self._PrzedstawicielKlienta__imie_nazwisko


    def getGroupId(self):
        return self._PrzedstawicielKlienta__idGrupy


    def getEmployer(self):
        return self._PrzedstawicielKlienta__pracodawcaptr.getName()



class NaszPracownik(Pracownik):
    __idGrupy = 0
    def __init__(self, imie_nazwisko):
        super().__init__()
        self.__imie_nazwisko = imie_nazwisko


    @staticmethod
    def prowadzSpotkanie(nazwa_pracownika, spotkanieptr):
        pracownik = Pracownik.znajdzPracownika(nazwa_pracownika)
        if pracownik != None:
            spotkanieptr.dolacz(pracownik)
        else:
            string = input('Podaj poprawne imię i nazwisko swojego pracownika: ')
            NaszPracownik.prowadzSpotkanie(string, spotkanieptr)


    def __str__(self):
        return "Nasz przedstawiciel: %s" % (self._NaszPracownik__imie_nazwisko)


    def getName(self):
        return self._NaszPracownik__imie_nazwisko


    def getGroupId(self):
        return self._NaszPracownik__idGrupy



class Konsultant(Pracownik):
    __idGrupy = 2
    def __init__(self, imie_nazwisko):
        super().__init__()
        self.__imie_nazwisko = imie_nazwisko


    @staticmethod
    def konsultuj(nazwa_konsultanta, spotkanieptr):
        konsultant = Pracownik.znajdzPracownika(nazwa_konsultanta)
        if konsultant != None:
            spotkanieptr.dolacz(konsultant)
            string = input('Konsultant radzi, aby: ')
            spotkanieptr.dodajUwagi(string)
        
        else:
            string = input('Wpisz poprawne imię i nazwisko swojego konsultanta: ')
            konsultuj(string, spotkanieptr)
            return


    def __str__(self):
        return "Konsultant: %s" % (self._Konsultant__imie_nazwisko)


    def getName(self):
        return self._Konsultant__imie_nazwisko


    def getGroupId(self):
        return self._Konsultant__idGrupy
