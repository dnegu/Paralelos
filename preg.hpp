#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef size_t ST;
typedef int** MI;

/**
Pregunta Numero 1
**/

MI TNL3(MI &A,MI &B,ST &tam)
{
    ST i,j,k;
    MI C;
    C=new int*[tam]; /*Uso de Memoria*/
    for(int i=0;i<tam;i++)
        C[i]=new int[tam]; /*Uso de Memoria*/

    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            for(k=0;k<tam;k++)
            C[i][j]+=A[i][k]*B[k][j]; /*Uso de Memoria*/
    return C;
}

void print(MI &A,ST &tam)
{
    ST i,j;
    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    cout<<"_______________________________"<<endl;
}

void llenar(MI& A,ST &tam)
{
    A=new int*[tam];  /*Uso de Memoria*/
    for(int i=0;i<tam;i++)
        A[i]=new int[tam]; /*Uso de Memoria*/

    ST i,j;
    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            A[i][j]=rand() % 10 + 1; /*Uso de Memoria*/
}

void limpiar(MI& A, ST &tam)
{
    for(int i=0;i<tam;i++)
        delete A[i];
    delete A;
}

/**
Pregunta Numero 2
**/

MI TNL6(MI &A,MI &B,ST tam,ST tamblock)
{
    ST i,j,k,ib,jb,kb;
    MI C;
    C=new int*[tam];
    for(int i=0;i<tam;i++)
        C[i]=new int[tam]; /*Uso de Memoria*/

    for (i = 0; i < tam; i+=tamblock)
        for (j = 0 ; j < tam; j+=tamblock)
	      for (k = 0; k < tam ; k+= tamblock)
	         for (ib = i; ib<j+tamblock; ib++)
	            for (kb = k ; kb<k+tamblock; kb++)
	               for (jb = j ; jb<j+tamblock ; jb++)
	                 C[ib][jb] += A[ib][kb] *B[kb][jb]; /*Uso de Memoria*/
    return C;
}

/**
Pregunta 3
En el TNL3 :
	El tiempo computacional es BIGO(n^3) pero utiliza demasiada memoria en su ejecucion.
	La complejidad es cubica ya que recorre 3 ciclos loop invariant, estos ciclos dependen del 
	tamanho de la matriz directamente.
	
En el TNL6: 
	El tiempo computacional es BIGO(n^3) pero utiliza poca memoria en su ejecucion.
	La complejidad es cubica, ya que aunque se utilice 6 ciclos, estos no lo evaluan en toda la 
	matriz, sus ciclos en este caso no dependen del tamanho de la matriz sino de el tamanho del bloque 
	en la matriz a ejecutar.
**/


