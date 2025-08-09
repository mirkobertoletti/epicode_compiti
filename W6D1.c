#include <stdio.h> //libreria di base per gestire per esempio printf() e scanf()
#include <ctype.h> //utile per la conversione di caratteri
#include <stdlib.h> //necessaria per usare malloc e free
#include <unistd.h> // libreria per gestire lo sleep()
#include <string.h>
#include <stdbool.h> //importato libreria boolean, per gestire i valori booleani 0=false 1=true

#define DEFAULT_NAME "----UNSET----" // definisce un nome di default "----UNSET----" che verrà sostituito alla compilazione
int partita(); //assegnamo a partita un valore intero

int main() {
    //introduzione all'utente con lo scopo del gioco
    char *intro = "Rispondi alle domande in modo corretto per ricevere un premio"; //l'asterisco indica un puntatore di sola lettura a 'intro'
    printf("%s\n", intro); //stampiamo la stringa di testo "Rispondi alle domande...."

    //due opzioni 
    char *prompt_scelta = "scegli tra \n\tA)iniziare una nuova partira e \n\tB) Uscire la gioco"; // puntatore di sola lettura della frase
    char scelta; // scelta diventa la variabile che verra inserita dall'utente
    printf("%s\n", prompt_scelta); // stampiamo le opzioni
    printf("\nComunicami la tua scelta: "); //stampiamo il testo
    scanf(" %c", &scelta); //ora viene preso il testo inserito dall'utente e associato alla variabile scelta 
    // nota: lo spazio prima di %c serve a ignorare eventuali newline rimasti nel buffer

    int score = 0;
    char *nome = DEFAULT_NAME;

    switch (tolower(scelta)) {
        case 'a':
            if (strcmp(nome, DEFAULT_NAME) == 0) {
                printf("\nComunicami il tuo nome (subito): ");
                nome = (char *) malloc(512); // usiamo malloc per allocare dinamicamente memoria per il nome
                scanf("%s", nome); // leggiamo il nome dell'utente
            }

            score += partita(); // chiamiamo la funzione partita e sommiamo il punteggio

            printf("\nGrazie per aver giocato, %s! Hai totalizzato %d punti.\n", nome, score); // messaggio finale con punteggio
            free(nome); // liberiamo la memoria allocata per il nome
            break;

        case 'b':
            return 0; // uscita dal programma

        default:
            printf("scelta sbagliata\n"); // gestione scelta non valida
            break;
    }

    return 0;
}

int partita() {
    int score = 0;

    char *d1 = "Di che colore era il cavallo bianco di Napoleone?\n\t1) Bianco\n\t2) Nero\n\t3) Giallo\n";
    int risposta_corretta = 1; // la risposta corretta è "Bianco" (opzione 1)
    int scelta;

    bool stop = false; // variabile che può essere usata per continuare/interrompere il quiz

    printf("%s", d1); // stampiamo la domanda
    scanf("%d", &scelta); // leggiamo la risposta dell'utente

    if (scelta == risposta_corretta) {
        printf("Risposta corretta!\n");
        score++; // incrementiamo il punteggio
    } else {
        printf("Risposta sbagliata.\n");
    }

    return score; // restituiamo il punteggio ottenuto
}
