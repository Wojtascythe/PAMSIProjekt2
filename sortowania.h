#pragma once
#include <algorithm>
#include <math.h>
using namespace std;

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





