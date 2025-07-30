/* W5D4 */

/* Tramite l'esecuzione dì questo codice scritto in C, verranno calcolate le aree di un quadrato, di un cerchio e di un triangolo equilatero , il dato che verrà richiesto all'utente sarà D, ovvero il lato del quadrato, il raggio del cerchio e il lato del triangolo.  Il risultato sarà un numero con due cifre decimali (double)*/


#include <stdio.h> /* Indispendabile per poter scrivere nel linguaggio C */
#include <math.h> /* Libreria matematica per poter utilizzare PiGreco (M_pi) e Radice Quadrata (sqrt)*/

int main() {   //funzione principale per ingresso del programma
   float D; //double è dato per la rappresentazione numerica con parte decimale doppio (64 bit)
    
    printf("Inserisci la mnisura del lato del quadrato, del triangolo e il raggio del cerchio:  "); //printf è L'output, ovvero ciò che verrà visualizzato nel terminale come stringa
    
    scanf("%f", &D); //scanf è l'input, ovvero il dato che una volta inserito, sarà utilizzato, in questo caso corrisponde a D (&D)

    /* il simbolo % serve per leggere il singolo carattere */
    /* Il simbolo & è l'indirizzo che consente di modificare  il contenuto della variabile  D in questo caso */

    // Calcolo area del quadrato
    double area_quadrato = D * D; //formula per calcolare l'area del quadrato lato * lato

    // Calcolo area del cerchio (raggio = D/2)
    double raggio = D / 2.0;  
    double area_cerchio = M_PI * raggio * raggio;

    // Calcolo area del triangolo equilatero
    double area_triangolo = (sqrt(3) / 4.0) * D * D;

    // Output dei risultati
    printf("Area del quadrato di lato %.2f: %.2f\n", D, area_quadrato);
    printf("Area del cerchio di diametro %.2f: %.2f\n", D, area_cerchio);
    printf("Area del triangolo equilatero di lato %.2f: %.2f\n", D, area_triangolo);

    return 0;
}

/* Per eseguire il codice da terminale è necessario scrivere 'gcc W5D4.c -o outbin && ./outbin' */