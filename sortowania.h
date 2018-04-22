#pragma once
#include <algorithm>
#include <math.h>
using namespace std;

//quicksort scalanie introspektywne 

//quicksort(tablica,lewy,prawy)
//mergesort(tablica,poczatek,koniec,WIELKOSC)
//introsort(tablica,WIELKOSC)

template <class KLASA>
void quicksort(KLASA tablica[], int left, int right){
int i=left,j=right;
int x=tablica[(left+right)/2];
do{
while (tablica[i]<x) i++;
while (tablica[j]>x) j--;
if (i<=j){
	swap(tablica[i], tablica[j]);
	i++;
	j--;
};

} while (i<=j);

if (left<j) quicksort(tablica,left,j);
if (right>i) quicksort(tablica,i,right);

};


//------------------------------- MERGESORT
template <class KLASA>
void merge(KLASA tablica[], int poczatek, int srodek, int koniec, int WIELKOSC){
int i,j,k;
int n1=srodek-poczatek+1;
int n2=koniec-srodek;
KLASA L[n1];
KLASA P[n2];

for (i=0;i<n1; i++) L[i]=tablica[poczatek+i]; //rozbij na dwie podtablice
for (j=0;j<n2; j++) P[j]=tablica[srodek+1+j];
i=0;
j=0;
k=poczatek;

while (i<n1&& j<n2){
if (L[i]<=P[j]){
	tablica[k]=L[i];
	i++;
} else {
tablica[k]=P[j];
j++;
};
k++;
};

while (i<n1){
tablica[k]=L[i];
i++;
k++;
};

while (j<n2){
tablica[k]=P[j];
j++;
k++;
};
//delete L;
//delete P;

};

template <class KLASA>//to NAJPIERW DLA ŚRODKA
void mergesort(KLASA tablica[], int poczatek, int koniec, int WIELKOSC){
int srodek;
if (poczatek<koniec){
srodek=(poczatek+koniec)/2;
mergesort(tablica,poczatek,srodek, WIELKOSC);
mergesort(tablica,srodek+1,koniec, WIELKOSC);
merge(tablica,poczatek,srodek,koniec, WIELKOSC);
};
};

