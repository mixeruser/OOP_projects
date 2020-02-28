from abc import ABC, abstractmethod
import pracownik
import klient
import spotkanie

#dodaje klientów i przedstawicieli
k1 = klient.Indywidualny('Marcin W')
k1 = klient.Indywidualny('Adam S')

f1 = klient.Firma('Fisco')
f2 = klient.Firma('Arteo')

pr1 = pracownik.PrzedstawicielKlienta('Marco P', f1)
f1.dodajPrzedstawiciela(pr1)
pr2 = pracownik.PrzedstawicielKlienta('Andrzej S', f2)
f2.dodajPrzedstawiciela(pr2)
klient.Firma.nowyPrzedstawiciel()      #tutaj input



#dodaje pracowników
np1 = pracownik.NaszPracownik('Anna W')
np2 = pracownik.NaszPracownik('Marian K')
kon1 = pracownik.Konsultant('Antoni K')

print('\nPracownicy znajdujący się w bazie:')
p = pracownik.Pracownik
p.wypiszPracownikow()
print('')


#spotkanie 1
kl = klient.Klient

s1 = spotkanie.Spotkanie()
s1.dodajTemat('Wdrożenie systemu A')
kl.spotkajSie('Fisco', s1)
pracownik.NaszPracownik.prowadzSpotkanie('Marian D', s1)
kon1.konsultuj('Antoni K', s1)
print('Koniec spotkania\n')


#spotkanie 2

s2 = spotkanie.Spotkanie()
s2.dodajTemat('Program B')
kl.spotkajSie('Marcin W', s2)
pracownik.NaszPracownik.prowadzSpotkanie('Anna W', s2)
print('Koniec spotkania\n')

#iinformacje o spotkaniu
spotkanie.Spotkanie.wypiszIdSpotkan()
n = int(input('Opis którego spotkania chcesz zobaczyć? '))
spotk = spotkanie.Spotkanie.znajdzOpId(n)
spotk.opisSpotkania()


'''
k1 = klient.Indywidualny('Robercik')
s1 = Spotkanie()
s1.dolaczIndywidualny(k1)
'''
'''
s = Spotkanie
s1 = Spotkanie()
s2 = Spotkanie()
print(s._Spotkanie__spotkania)
print(s._Spotkanie__nextID)
print(s2._Spotkanie__id)
print(s2._Spotkanie__)
'''
'''    
k1 = Indywidualny('Robercik')
f1 = Firma('F1')
kl = Klient
Klient.znajdzKlienta('F1')
Firma.nowyPrzedstawiciel()

pr = pracownik.PrzedstawicielKlienta('Mariano', f1)
f1.dodajPrzedstawiciela(pr)
f1.wypiszPrzedstawicieli()

pr.getEmployer()
'''
'''
print(f1._Firma__przedstawiciele)

#print(kl._Klient__klienci)

Klient.wypiszKlientow()
Klient.znajdzKlienta('F1')
'''
'''
pk1 = pracownik.PrzedstawicielKlienta('Jan')
pk2 = pracownik.PrzedstawicielKlienta('Marcin Kop')
np1 = pracownik.NaszPracownik('Anna Waza')
k1 = pracownik.Konsultant('Antoni')

print(pk1.getGroupId())
pr = pracownik.Pracownik
print(pr._Pracownik__pracownicy)
print(pk1._PrzedstawicielKlienta__idGrupy)
#print(Pracownik.znajdzPracownika('Jan'))

pracownik.Pracownik.wypiszPracownikow()

'''