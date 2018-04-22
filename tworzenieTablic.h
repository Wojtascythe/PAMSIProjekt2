#include <string>
#include <iostream>
#include <stdlib.h>
#define wielkoscDanejNieposortowanej 100000
#define wielkoscDanejPosortowanej 100000
#define oIleSkok 15
using namespace std;

template <class KLASA> // KLASA np. int, float, double...
void wszystkieLosowe(KLASA tablica[],int wielkoscTablicy){
for (int i=0;i<wielkoscTablicy;i++){
tablica[i]=(KLASA)rand()%wielkoscDanejNieposortowanej;//rzutowanie na KLASA zapewnia nam wiele typów
};
};


template <class KLASA>
void czescLosowe(KLASA tablica[],float procentPosortowanych, int wielkoscTablicy){
int wielkoscPosortowanej=(int)(procentPosortowanych/100.0*wielkoscTablicy); // tu liczymy matematycznie procent zrobiony
tablica[0]=(KLASA)rand()%wielkoscDanejPosortowanej;//
for (int i=1;i<wielkoscPosortowanej;i++){ //wypelnij posortowanymi
tablica[i]=tablica[i-1]+(KLASA)rand()%oIleSkok;
};
KLASA temp=tablica[wielkoscPosortowanej-1];
for (int i=wielkoscPosortowanej;i<wielkoscTablicy;i++){
tablica[i]=temp+(KLASA)rand()%wielkoscDanejNieposortowanej;
};
};

template <class KLASA>
void wszystkieOdwrocone(KLASA tablica[],int wielkoscTablicy){
tablica[wielkoscTablicy-1]=rand()%wielkoscDanejPosortowanej;
for (int i=wielkoscTablicy-2; i>=0;i--){
tablica[i]=tablica[i+1]+(KLASA)rand()%oIleSkok;
};
};
