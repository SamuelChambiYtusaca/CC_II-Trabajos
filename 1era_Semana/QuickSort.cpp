#include<iostream>
#include <stdio.h>
using namespace std;
void crear(int *&a, int tam)
{
    a = new int[tam];
    for (int i = 0; i < tam; i++){
        printf("Inserte dato [%i]: ",i); cin >> a[i]; 
    }
}

void mostrarA(int *a, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("[%i]\t",a[i]);
        cout << "\n";
}

void quicksort(int *&a,int inicio,int final)
{
    int medio, i, j, piv;
    medio = (inicio+final)/2;
    piv = a[medio];
    i = inicio;
    j = final;
    do{
        while(a[i]<piv)
            i++;
        while(a[j]>piv)
            j--;
        if(i<=j)
        {
            int aux;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }    
    }while(i<=j);
    if(inicio<j)
        quicksort(a,inicio,j);
    if(i<final)
        quicksort(a,i,final);
}
int main()
{
    int *arreglo, cant;
    cout << "Inserte el numero de elementos del arreglo: "; cin >> cant;
    crear(arreglo,cant);
    cout << "* * * * Arreglo inicial * * * *" << endl;
    mostrarA(arreglo,cant);
    cout << "* * * * Arreglo ordenado con Quicksort * * * *" << endl;
    quicksort(arreglo,0,cant-1);
    mostrarA(arreglo,cant);
    return 1;
}