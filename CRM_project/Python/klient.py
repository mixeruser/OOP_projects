from abc import ABC, abstractmethod
import pracownik


class Klient(ABC):
    __klienci = []
    def __init__(self):
        Klient.__klienci.append(self)
        print('Dodaję klienta ', end='')


    @staticmethod
    def znajdzKlienta(nazwa_klienta):
        for p in Klient.__klienci:
            if p.getName() == nazwa_klienta:
                print('Znalazłem klienta', p.getName())
                return p
        print('W bazie nie ma takiego klienta')


    @staticmethod
    def spotkajSie(nazwa_klienta, spotkptr):
        kl = Klient.znajdzKlienta(nazwa_klienta)
        if kl == None:
            nazwa_klienta = input('Podaj prawidłową nazwę klienta: ')
            Klient.spotkajSie(nazwa_klienta, spotkptr)
            return
        else:
            kl._spotkajSie(spotkptr)


    @abstractmethod
    def _spotkajSie(self, spotkptr):
        pass


    @staticmethod
    def wypiszKlientow():
        for k in Klient.__klienci:
            print(k.getName())


    @abstractmethod
    def getName(self):
        pass



class Indywidualny(Klient):
    def __init__(self, imie_nazwisko):
        super().__init__()
        self.__imie_nazwisko = imie_nazwisko
        print('(indywidualnego):', self.getName())


    def _spotkajSie(self, spotkptr):
        spotkptr.dolaczIndywidualny(self)


    def getName(self):
        return self.__imie_nazwisko



class Firma(Klient):
    def __init__(self, nazwa_firmy):
        super().__init__()
        self.__nazwa_firmy = nazwa_firmy
        self.__przedstawiciele = []
        print('(firmę):', self.getName())


    def dodajPrzedstawiciela(self, przedstawicielptr):
        self.__przedstawiciele.append(przedstawicielptr)
        string = 'Dodaję przedstawiciela firmy ' + self.getName() + ': ' + przedstawicielptr.getName()
        print(string)


    @staticmethod
    def nowyPrzedstawiciel():               #input
        string = input('Przedstawiciela której firmy chcesz dodać? ')
        firma = Klient.znajdzKlienta(string)
        if firma == None:
            Firma.nowyPrzedstawiciel()
            return
        string = input('Podaj imię i nazwisko nowego przedstawiciela firmy: ')
        p = pracownik.PrzedstawicielKlienta(string, firma)
        firma.dodajPrzedstawiciela(p)


    def wypiszPrzedstawicieli(self):
        string = 'Przedstawiciele firmy ' + self.getName() + ":"
        print(string)
        for p in self.__przedstawiciele:
            print(p.getName())


    def _spotkajSie(self, spotkptr):
        print('Który z przedstawicieli jest na spotkaniu?')
        self.wypiszPrzedstawicieli()
        string = input('Podaj imię i nazwisko przedstawiciela: ')
        for p in self.__przedstawiciele:
            if p.getName() == string:
                spotkptr.dolacz(p)
                return
        print('Firma nie posiada takiego przedstawiciela')
        self._spotkajSie(spotkptr)


    def getName(self):
        return self.__nazwa_firmy
