#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{  //struttura per dijikstra
        int nod;
        int dist;
    } nodo_t;

typedef struct{
        int n_grafo;
        int sum;
    } grafo_t;

void accoda_dij(nodo_t[], int, int*, int);
int estrai_dij(nodo_t[], int *);
void min_heapify_dij(nodo_t[], int, int**);
int leggi_somma( int);
void accoda_classif(grafo_t[], int, int*, int);
void max_heapify_classif(grafo_t[], int, int **);
void estrai_classif(grafo_t[], int *);



int main(){
    int d; //numero nodi grafo
    int k;  //lunghezza classifica
    
    int last=0, count=0, sum_grafo, i, flag=0;
    char c;


    if(scanf("%d", &d));
    if(scanf("%d", &k));
    grafo_t classif[k];

    getchar_unlocked();
    c=getchar_unlocked();
    while(c!=EOF){
        if(c=='A'){
            while(c!='\n')
                c=getchar_unlocked();
            sum_grafo=leggi_somma(d);
            if(last!=k){
                accoda_classif(classif, sum_grafo, &last, count);
            }else if(sum_grafo<classif[0].sum){
                estrai_classif(classif, &last);
                accoda_classif(classif, sum_grafo, &last, count);
            }
            count=count+1;
        }else if(c=='T'){
            while(c!='\n')
                c=getchar_unlocked();
            if(last==0){
                printf("\n");
            } else if(flag==0){
                for(i=0; i<last-1; i++)
                    printf("%d ", classif[i].n_grafo);
                printf("%d", classif[last-1].n_grafo);
                flag=1;
            }else{
                printf("\n");
                for(i=0; i<last-1; i++)
                    printf("%d ", classif[i].n_grafo);
                printf("%d", classif[last-1].n_grafo);
                
            }
        }
        c=getchar_unlocked();

    }
    return 0;
}


 

int leggi_somma( int N){
    int last=0; // per funz. accoda: indice ultimo elemento
    int i, sum=0, j, num;
    char c;
    int matr[N][N], dist[N], to_explore;
    nodo_t coda[N*N];  // non sicuro dimensione

    //lettura
    
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            num=0;
            c=getchar_unlocked();
            num=c-48;
            while(c!=',' && c>='0' && c<='9'){
                c=getchar_unlocked();
                if(c!=',' && c>='0' && c<='9')
                    num=num*10+(c-48);
            }
            matr[i][j]=num;
        }
    }

    //dijikstra
    dist[0]=0;
    for(i=1; i<N; i++){
        dist[i]=__INT_MAX__;
    }
    
    accoda_dij(coda, 0, &last, 0);
    while(last!=0){
        to_explore=estrai_dij(coda, &last);
        for(i=0; i<N; i++){
            if(matr[to_explore][i]!=0 && dist[to_explore]+matr[to_explore][i]<dist[i]){
                accoda_dij(coda, dist[to_explore]+matr[to_explore][i], &last, i);
                dist[i]=dist[to_explore]+matr[to_explore][i];
            }
        }
    }

    for(i=0; i<N; i++){
        if(dist[i]!=__INT_MAX__)
            sum=sum+dist[i];
    }

    return sum;
}

int estrai_dij(nodo_t coda[], int *last){
    int min;
    min=coda[0].nod;
    (*last)=(*last)-1;
    coda[0]=coda[*(last)];
    // max-heapify
    min_heapify_dij(coda, 0, &last);
    return min;
}

void min_heapify_dij(nodo_t coda[], int i, int**last){
    int l, r, min;
    nodo_t tmp;
    l = 2*i+1;
    r = 2*i+2;
    if(l<=(**last) && coda[l].dist<coda[i].dist)
        min=l;
    else 
        min=i;
    if(r<=(**last) && coda[r].dist<coda[min].dist)
        min=r;
    if (min!=i){
        tmp=coda[i];
        coda[i]=coda[min];
        coda[min]=tmp;
        min_heapify_dij(coda, min, last);
    }

}

void accoda_dij(nodo_t coda[], int val, int *last, int ind){
    int j;
    nodo_t tmp;
    coda[(*last)].dist=val;
    coda[(*last)].nod=ind;
    j=(*last);
    (*last)=(*last)+1;
    while(j>0 && coda[(j-1)/2].dist>coda[j].dist){
        tmp=coda[(j-1)/2];
        coda[(j-1)/2]=coda[j];
        coda[j]=tmp;
        j=(j-1)/2;
    }
}

void accoda_classif(grafo_t coda[], int val, int *last, int ind){
    int j;
    grafo_t tmp;
    coda[(*last)].sum=val;
    coda[(*last)].n_grafo=ind;
    j=(*last);
    (*last)=(*last)+1;
    while(j>0 && coda[(j-1)/2].sum<coda[j].sum){
        tmp=coda[(j-1)/2];
        coda[(j-1)/2]=coda[j];
        coda[j]=tmp;
        j=(j-1)/2;
    }

}

void max_heapify_classif(grafo_t coda[], int i, int **last){
    int l,r, max;
    grafo_t tmp;
    l = 2*i+1;
    r = 2*i+2;
    if(l<=(**last) && coda[l].sum>coda[i].sum)
        max=l;
    else 
        max=i;
    if(r<=(**last) && coda[r].sum>coda[max].sum)
        max=r;
    if (max!=i){
        tmp=coda[i];
        coda[i]=coda[max];
        coda[max]=tmp;
        max_heapify_classif(coda, max, last);
    }
    
}

void estrai_classif(grafo_t coda[], int * last){
    (*last)=(*last)-1;
    coda[0]=coda[*(last)];
    max_heapify_classif(coda, 0, &last);

}