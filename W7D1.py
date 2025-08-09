
#due metodi per sapere la lunghezza delle parole contenute in una lista 
#metodo uno:


def metodo_uno(a: list[str]) -> list[int]: #funzione che prende una lista di stringhe e restituisce numeri interi 
    b = [] #lista vuota che conterà la lunghezza
    for parola in a: #ciclia ogni parola della lista 
        lunghezza = len(parola) #calcolo della lungheza con la funzion len()
        # Append aggiunge la lunghezza della parola alla lista
        b.append(lunghezza) #appen aggiunge alla lista il numero della lunghezza

    return b #restituisce la lista con le lunghezze




#metodo due
#metodo più rapido per creare la funzione con meno righe di codice


def metodo_due(a: list[str]) -> list[int]:
    return [ len(x) for x in a ] #ogni elemento "x" presente in "a" viene messo nella lista 



a = [ "ciao", "sono", "Mirko", "allievo", "di", "epicode" ]
b = metodo_due(a) #lista delle lunghezze delle parole in "a"



assert metodo_due(a) == metodo_uno(a)  #verifica se i risultati delle due funzioni sono uguali in caso contrario ci sarà un AssertionError di Python

print(a)
print(b)
