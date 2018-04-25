#pragma once
#define TYP int
#include <iostream>
#include "tworzenieTablic.h"
#include "sortowania.h"
#include <chrono>  // mierzenie czasu
#include <thread>
#include <stdlib.h>
using namespace std;

//0-nie odwracaj, 1-odwracaj
void testQuicksort( int _switch);
void testQuicksort(float procent);
void testMergesort( int _switch);
void testMergesort(float procent);
void testIntrosort( int _switch);
void testIntrosort(float procent);
int main(){
//testQuicksort(0);
//testQuicksort((float)25.0);
//testQuicksort((float)50.0);
//testQuicksort((float)75.0);
//testQuicksort((float)95.0);
//testQuicksort((float)99.0);
//testQuicksort((float)99.7);
//testQuicksort(1);
//testMergesort(0);
//testMergesort((float)25.0);
//testMergesort((float)50.0);
//testMergesort((float)75.0);
//testMergesort((float)95.0);
//testMergesort((float)99.0);
//testMergesort((float)99.7);
//testMergesort(1);
testIntrosort(0);
testIntrosort((float)25.0);
testIntrosort((float)50.0);
testIntrosort((float)75.0);
testIntrosort((float)95.0);
testIntrosort((float)99.0);
testIntrosort((float)99.7);
testIntrosort(1);

};

void testQuicksort(int _switch){
int *czasy = new int[100];
cout<<"Testy dla QUICKSORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){ //do zrobienia średniej ze 100 wyników

if(_switch==0) wszystkieLosowe(tablica,wielkoscTab[j]); else if (_switch==1) wszystkieOdwrocone(tablica,wielkoscTab[j]);
auto start=chrono::high_resolution_clock::now();//start stopera
quicksort(tablica,0,wielkoscTab[j]-1);
auto stop=chrono::high_resolution_clock::now();//stop stopera
czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();
};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Quicksort, wszystkie losowe (SWITCH!):\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};

void testQuicksort(float procent){
int *czasy = new int[100];
cout<<"Testy dla QUICKSORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){
czescLosowe(tablica,procent,wielkoscTab[j]);
auto start=chrono::high_resolution_clock::now();
quicksort(tablica,0,wielkoscTab[j]-1); //podawanie skrajnych granic lewy/prawy
auto stop=chrono::high_resolution_clock::now();
czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();
};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Quicksort, "<<procent<<"% posortowanych:\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};

void testMergesort(int _switch){
int *czasy = new int[100];
cout<<"Testy dla MERGESORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){ //5 liczb z wielkosctab
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){ //sto testow dla kazdego z pieciu

if(_switch==0) wszystkieLosowe(tablica,wielkoscTab[j]); else if (_switch==1) wszystkieOdwrocone(tablica,wielkoscTab[j]);

auto start=chrono::high_resolution_clock::now();
mergesort(tablica,0,wielkoscTab[j]-1,wielkoscTab[j]);
auto stop=chrono::high_resolution_clock::now();


czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();
};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Mergesort, wszystkie losowe";
if (_switch==1) cout<<", odwrócone";
cout<<":\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};

void testMergesort(float procent){
int *czasy = new int[100];
cout<<"Testy dla MERGESORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){

czescLosowe(tablica,procent,wielkoscTab[j]);
auto start=chrono::high_resolution_clock::now();
mergesort(tablica,0,wielkoscTab[j]-1,wielkoscTab[j]);
auto stop=chrono::high_resolution_clock::now();
czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();
};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Mergesort, "<<procent<<"% posortowanych:\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};

void testIntrosort(int _switch){
int *czasy = new int[100];
cout<<"Testy dla INTROSORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){

if(_switch==0) wszystkieLosowe(tablica,wielkoscTab[j]); else if (_switch==1) wszystkieOdwrocone(tablica,wielkoscTab[j]);
auto start=chrono::high_resolution_clock::now();
introsort(tablica,wielkoscTab[j]);
auto stop=chrono::high_resolution_clock::now();
czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();

};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Introsort, wszystkie losowe:\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};

void testIntrosort(float procent){
int *czasy = new int[100];
cout<<"Testy dla INTROSORTa\n";
double czasSredni=0;
int wielkoscTab[5]={10000,50000,100000,500000,1000000};
for (int j=0;j<5;j++){
TYP *tablica=new TYP[wielkoscTab[j]];
for (int i=0;i<100;i++){

czescLosowe(tablica,procent,wielkoscTab[j]);
auto start=chrono::high_resolution_clock::now();
introsort(tablica,wielkoscTab[j]);
auto stop=chrono::high_resolution_clock::now();
czasy[i]=chrono::duration_cast<chrono::milliseconds>(stop-start).count();
};
for (int i=0;i<100;i++) czasSredni=czasSredni+czasy[i];
cout<<"Introsort, "<<procent<<"% posortowanych:\n"
<<wielkoscTab[j]<<" wielkość tablicy\n"
<<czasSredni<<" milisekund - czas łączny\n"
<<czasSredni/100<<" milisekund średnio!\n"
<<"-----------\n";
czasSredni=0;
delete tablica, czasy;
};
};


