
#generatore di password 



import string  #importo modulo della libreria per evitare di scrivere stringhe 
import random #importo modulo per scegliere numeri e lettere casuali 

ALFANUMERICI = string.ascii_lowercase + string.ascii_uppercase +string.digits #assegno ad "ALFANUMERICI" lettere,maiuscole e minuscole e numeri
TUTTI_ASCII  = ALFANUMERICI + string.punctuation #assegno a "TUTTI_ASCII" - "ALFANUMERICI" piu tutti i simboli ASCII 

def generate_password(lenght:int, charset:str) -> str: #creo la funzione per generare password
    password = [] #lista vuota che conterrà il numero dei caratteri 
    for i in range(0, lenght): #genera una sequenza di numeri della lunghezza richiesta
        letter = random.choice(charset) #sceglie un carattere casuale da charset
        password.append(letter) #aggiunge il carattere alla lista

    #'|'.join(['1','2','3']) => "1|2|3"
    #''.join(['1','2','3']) => "123"

    return ''.join(password) #unisce i caratteri in un'unica stringa 


scelta = input("Complessa o semplice? C/S: ") #il terminale mostrerà all'utente una scelta e sulla base di essa ci saranno differrenze
if scelta.lower() == "c":
    password = generate_password(20, TUTTI_ASCII)  #se la scelta sarà C verrà attivata la funzione "generate_password" con i due parametri (20 e TUTTI_ASCII)

elif scelta.lower() == "s":
    password = generate_password(8, ALFANUMERICI) #se la scelta sarà S verrà attivata la stessa funzione ma con i paramenti differernti (8 e ALFANUMERICI)

else:
    password = generate_password(2000, TUTTI_ASCII) #oppure, nel caso in cui non venga scelta nessuna opzione verrà generata una password da 2000 caratteri


print(password)  #verrà stampata la password in base alla scelta fatta