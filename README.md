# Progetto prova finale API (Algoritmi e strutture dati 2021)

*This project was made between June and July 2021, at Politecnico University of Milan.*

## GraphRanker

- L'obiettivo del progetto di quest'anno è la gestione di una classifica tra grafi
diretti pesati
- La classifica tiene traccia dei k "migliori" grafi
- Il programma da realizzare riceve in ingresso:
   - due parametri, una sola volta (sulla prima riga del file, separati da spazio):
       - d: il numero di nodi dei grafi
       - k: la lunghezza della classifica
   - Una sequenza di comandi tra:
       - AggiungiGrafo [matrice-di-adiacenza]
       - TopK
### AggiungiGrafo
Richiede di aggiungere un grafo a quelli considerati per stilare la classifica. È
seguito dalla matrice di adiacenza del grafo stesso, stampata una riga per
ogni rigo, con gli elementi separati da virgole.
I nodi del grafo sono da considerarsi etichettati logicamente con un indice
intero tra 0 e d-1; il nodo in posizione 0 è quello la cui stella uscente è
descritta dalla prima riga della matrice.
I pesi degli archi del grafo elementi sono interi nell'intervallo [0, 2^32 – 1].

### TopK
- Si consideri ogni grafo dall'inizio del programma fino al comando TopK etichettato con un indice intero corrispondente al numero di grafi letti
prima di esso (partendo da 0)
- TopK richiede al programma di stampare gli indici interi dei k grafi aventi i k valori più piccoli della seguente metrica:
- Somma dei cammini più brevi tra il nodo 0 e tutti gli altri nodi del grafo raggiungibili
da 0
- Se ci sono più grafi con lo stesso valore della metrica, si dà la precedenza ai
primi arrivati
- Le distanze dei nodi non raggiungibili da 0 sono considerate nulle
- I k indici interi sono stampati, su un unico rigo, separati da uno spazio, in un
qualunque ordine

### Esecuzione d'esempio
<pre>

Input ricevuto:               Commenti e Output Atteso
3,2                           Si richiede di manipolare grafi da 3 nodi e riportare i k=2 migliori
AggiungiGrafo                 Aggiunta del primo grafo (indice 0, somma cammini = 7)
0,4,3
0,2,0
2,0,0
AggiungiGrafo                 Aggiunta del secondo grafo (indice 1, somma cammini = 5)
0,0,2
7,0,4
0,1,0
AggiungiGrafo                 Aggiunta del terzo grafo (indice 2, somma cammini = 7)
3,1,8
0,0,5
0,9,0
TopK                          0 1 Oppure 1 0
</pre>

### Requisiti

- La correttezza e l'efficienza della soluzione proposta sono state valutate con
batterie di test automatizzate, al fine di valutare la complessità temporale e spaziale degli algoritmi utilizzati

### Note conclsive

- La soluzione proposta ha superato tutti i test con il massimo dell'efficienza temporale e spaziale


