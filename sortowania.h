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

//-----------------------INTROSORT 

template <class KLASA>
int partition(KLASA tablica[], int poczatek, int koniec){
int pivot = tablica[koniec];
int temp, i=poczatek;
for (int j=poczatek;j<koniec;j++){
if (tablica[j]<pivot){
swap(tablica[i],tablica[j]);
i++;
};
};
tablica[koniec]=tablica[i];
tablica[i]=pivot;
return i;
};

template <class KLASA>
void insertion(KLASA tablica[], int WIELKOSC){
for (int i=1;i<WIELKOSC;i++){
int j=i;
while (j>0){
if (tablica[j-1]>tablica[j]){//
tablica[j-1] ^= tablica[j];//XOR
tablica[j] ^= tablica[j-1];
tablica[j-1] ^= tablica[j];
--j;
} else break;
};
};
};

template <class KLASA>
void maxheap(KLASA tablica[], int wielkoscKopca, int indeks){
int lewy=(indeks+1)*2-1;
int prawy=(indeks+1)*2;
int najwiekszy=0;
if (lewy<wielkoscKopca && tablica[lewy]>tablica[indeks]) najwiekszy=lewy; else najwiekszy=indeks;

if (prawy<wielkoscKopca && tablica[prawy]>tablica[najwiekszy]) najwiekszy=prawy;

if (najwiekszy != indeks){
	int temp=tablica[indeks];
	tablica[indeks]=tablica[najwiekszy];
	tablica[najwiekszy]=temp;
	maxheap(tablica, wielkoscKopca, najwiekszy);
};
};


template <class KLASA>
void heapsort(KLASA tablica[], int WIELKOSC){
int wielkoscKopca=WIELKOSC;
for (int p=(wielkoscKopca-1)/2; p>=0; --p) maxheap(tablica,wielkoscKopca,p);

for (int i=WIELKOSC-1; i>0; --i){
int temp=tablica[i];
tablica[i]=tablica[0];
tablica[0]=temp;
--wielkoscKopca;
maxheap(tablica, wielkoscKopca, 0);
};
};



template <class KLASA>
void introsort(KLASA tablica[], int WIELKOSC){
int WIELKOSCPartycji=partition(tablica,0,WIELKOSC-1);
if (WIELKOSCPartycji<16) insertion(tablica,WIELKOSC);
else if (WIELKOSCPartycji>2*log(WIELKOSC)) heapsort(tablica,WIELKOSC);
else quicksort(tablica,0,WIELKOSC-1);
};



