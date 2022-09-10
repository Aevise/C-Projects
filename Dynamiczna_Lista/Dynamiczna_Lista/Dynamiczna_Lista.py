
if __name__ == '__main__':    
    birds = {
        0:{"Imie":"Cyprian", "Gatunek":"Modrolotka", "Wiek":2, "Charakter":"Glupi"},
        1:{"Imie":"Nasra", "Gatunek":"Modrolotka", "Wiek":2, "Charakter":"Glodomor"}
    }

    print(birds.)
    
    print("Wybierz opcje:\n1. wyswietl zawartosc slownika\n2. dodaj element \n3. wyszukaj element \n4. usun wybrany element\n0. zakoncz")
    decision = int(input("moj wybor to: "))
    while decision < 0 & decision > 4: 
        print("Sprobuj jeszcze raz xD")
        print("Wybierz opcje:\n1. wyswietl zawartosc slownika\n2. dodaj element \n3. wyszukaj element \n4. usun wybrany element\n0. zakoncz")
        decision = int(input("moj wybor to: "))        
    while decision != 0:
        if decision == 1:
            for id, dictionary in birds.items():
                print("ID:",id)
                for key in dictionary:
                    print(key, ":", dictionary[key])
            print("-------------------------")
        elif decision == 2:
            birds[len(birds)] = {"Imie":input("Podaj Imie: "), "Gatunek":input("Podaj Gatunek: "), "Wiek":int(input("Podaj wiek: ")), "Charakter":input("Podaj charakter: ")}
        elif decision == 3:
            choose = int(input("Podaj ID ptaka: "))
            if choose in birds:
                print(birds[choose])
            else:
                print("Nie odnaleziono ptaka o takim identyfikatorze")
        elif decision == 4:
            decision = int(input("Podaj ID ptaka, ktorego nalezy usunac z bazy: "))
            if decision in birds:
                del birds[decision]
            else:
                print("Nie ma ptaka o takim identyfikatorze")
        else:
            print("Podano bledna wartosc")
        print("\nWybierz opcje:\n1. wyswietl zawartosc slownika\n2. dodaj element \n3. wyszukaj element \n4. usun wybrany element\n0. zakoncz")
        print("-------------------------")
        decision = int(input("moj wybor to: "))
        while decision < 0 & decision > 4: 
            print("Sprobuj jeszcze raz xD")
            print("Wybierz opcje:\n1. wyswietl zawartosc slownika\n2. dodaj element \n3. wyszukaj element \n4. usun wybrany element\n0. zakoncz")
            decision = int(input("moj wybor to: ")) 