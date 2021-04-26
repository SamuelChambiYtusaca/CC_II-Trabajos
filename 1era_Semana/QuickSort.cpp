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
    medio = (inicio+final)/2;//Indice del pivote
    piv = a[medio];//Se guarda el valor del pivote
    i = inicio;//Iterador de la izquierda
    j = final;//Iterador de la derecha
    do{
        while(a[i]<piv)//Busca por la izquierda, se detiene si el valor señalado es mayor al pivote
            i++;
        while(a[j]>piv)//Busca por la derecha,  se detiene si el valor señalado es menor al pivote
            j--;
        if(i<=j)//Si el primer iterador no paso al segundo
        {
            int aux;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;//Intercambia los valores señalados por los iteradores
            i++;
            j--;
        }    
    }while(i<=j);//Repite la busqueda si el primer iterados no sobrepaso al segundo
    if(inicio<j)
        quicksort(a,inicio,j);//Inicializa por el segmento izquierdo
    if(i<final)
        quicksort(a,i,final);//Inicializa por el segmento derecho
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