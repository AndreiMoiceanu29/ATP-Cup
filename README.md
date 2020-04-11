# Tema 1: ATP Cup[SDA]
ATP Cup este un program realizat in C pentru simularea unui campionat de tenis, implementand concepte de Structuri de Date si Algoritmi.


# Obiective

1.  Înțelegerea conceptului de funcționare și implementarea structurilor de date (liste, stive, cozi și arbori binari de căutare)
    
2.  Operarea cu structurile de date
    
3.  Implementarea funcționalităților practice care să folosească conceptele menționate anterior
## Descriere

În cadrul _Turneului Internațional de Tenis ATP Cup_, fiecare stat participant are un lot de jucători. Acest lot urmează să-și reprezinte țara într-o succesiune de meciuri jucate contra membrilor celorlalte loturi. Se dorește realizarea unei soluții software care să automatizeze desfășurarea turneului.

## Implementare

Programul citeste dintr-un fisier tarile si jucatorii care participa in turneul de tenis.Acestea sunt procesate in structuri de date aferente, dupa care se porneste campionatul. La finalul acestuia rezultatele sunt scrise intr-un fisier de iesire. 

## Structuri de date folosite

1. Country: Retine informatiile legate de tara.
2. Player: Retine informatiile legate de un jucator.
3. Meci: Structura de date folosita intern de coada, pentru a evidentia un meci dintre 2 jucatori.
4. Lista Dublu Inlantuita Circulara cu Santinela: Folosita pentru a stoca un sir de tari.
5. Stiva: Structura de date folosita pentru accesarea intr-o anumita ordine a sirului de tari.
6. Coada: Structura de date folosita pentru simularea meciurilor dintre jucatori.
7. Arbore binar de Cautare: Structura de date folosita pentru a tine o colectie de jucatori intr-o forma ordonata.
 

## Functii folosite

1. Functiile de baza ale structurilor de date (Lista,Stiva,Coada,BST)
2. performRound: folosita pentru desfasurarea turneului.
3. loadStack: folosita pentru a prelua elementele din lista si a le pune in stiva
4. isPowerOfTwo: determina daca un numar e putere a lui 2.
5. getMaxScore: determina scorul maxim dintr-un sir de jucatori.

## Rularea Programului

./tenis fisier_cerinte fisier_input fisier_output


