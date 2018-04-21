#include <string>
#include <iostream>
#include <stdlib.h>
#define wielkoscDanejNieposortowanej 100000
#define wielkoscDanejPosortowanej 100000
using namespace std;

template <class KLASA> // KLASA np. int, float, double...
void wszystkieLosowe(KLASA tablica[],int wielkoscTablicy){
for (int i=0;i<wielkoscTablicy;i++){
tablica[i]=(KLASA)rand()%wielkoscDanejNieposortowanej;//rzutowanie na KLASA zapewnia nam wiele typów
};
};



