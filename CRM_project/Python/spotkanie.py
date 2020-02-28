import datetime


class Spotkanie:
    __spotkania = []
    __nextID = 0
    def __init__(self):
        self.__id = Spotkanie.__nextID
        Spotkanie.__nextID += 1
        self.__konsultant = None
        self.__prowadzacy = None
        self.__klient_indywidualny = None
        self.__przedstawiciel = None
        self.__temat = ''
        self.__data = self.ustawDate()
        Spotkanie.__spotkania.append(self)
        print('Rozpoczyna się spotkanie')



    def dolacz(self, pracownikptr):
        if pracownikptr.getGroupId() == 0:
            self.__prowadzacy = pracownikptr
            string = "Spotkanie prowadzi " + self.__prowadzacy.getName()
            print(string)

        elif pracownikptr.getGroupId() == 1:        #jesli jest przedstawicielem klienta
            self.__przedstawiciel = pracownikptr
            string = 'Na spotkaniu ' + self.__przedstawiciel.getName() + ' jest przedstawicielem firmy ' + self.__przedstawiciel.getEmployer()
            print(string)

        elif pracownikptr.getGroupId() == 2:
            self.__konsultant = pracownikptr
            string = 'W spotkaniu bierze udział konsultant ' + self.__konsultant.getName()
            print(string)


    def dolaczIndywidualny(self, klientptr):
        self.__klient_indywidualny = klientptr
        print('W spotkaniu bierze udział klient indywidualny', klientptr.getName())


    def ustawDate(self):
        string = input('Kiedy odbywa się spotkanie? Data spotkania w formacie RRRR-MM-DD: ')
        year, month, day = map(int, string.split('-'))
        data = datetime.date(year, month, day)
        return data


    @staticmethod
    def znajdzOpId(id):
        for s in Spotkanie.__spotkania:
            if s.getId() == id:
                return s
        print('Brak spotkania o takim id')
        return None


    @staticmethod
    def wypiszIdSpotkan():
        print('Id odbytych spotkań:')
        for s in Spotkanie.__spotkania:
            print(s.getId())


    def getId(self):
        return self.__id

    
    def opisSpotkania(self):
        string = 'Id spotkania: ' + str(self.__id) + ' Data spotkania: ' + str(self.__data) + '\n'
        if self.__klient_indywidualny != None:
            string += 'Klient(indywidualny): ' + self.__klient_indywidualny.getName() + '\n'

        elif self.__przedstawiciel != None:
            string += 'Klient(firma): ' + self.__przedstawiciel.getEmployer() + ', w spotkaniu brał udział przedstawiciel ' + self.__przedstawiciel.getName() + '\n'

        string += 'Temat spotkania: ' + self.__temat + '\nSpotkanie prowadził/a ' + self.__prowadzacy.getName() + '\n'
        
        if self.__konsultant != None:
            string += 'W spotkaniu brał udział konsultant ' + self.__konsultant.getName() + '. Uwagi i spostrzeżenia konsultanta: \n' + self.__uwagi

        print(string)


    def dodajUwagi(self, uwagi_konsultanta):
        self.__uwagi = uwagi_konsultanta


    def dodajTemat(self, temat):
        self.__temat = temat
        print('Temat spotkania:', self.__temat)
