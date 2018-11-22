/*
	Calcola il determinante di matrici
	
	programmato da: Carlo Zambaldo
	ultimo aggiornamento: 21.11.2018
*/

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h>
using namespace std;

#define Id 10

int main(){
	int n,m,p,q;
	
	// Richiedo l'inserimento di n,m,p
	do{
		cout<<"Inserire le dimensioni della matrice A come richiesto."<<endl;
		cout<<"Righe della matrice A: ";
		cin>>n;
		cout<<"Colonne della matrice A: ";
		cin>>m;
		
		cout<<"Inserire le dimensioni della matrice B come richiesto."<<endl;
		cout<<"Righe della matrice B: ";
		cin>>p;
		cout<<"Colonne della matrice B: ";
		cin>>q;
		if(n!=p)
			system("CLS");
			cout<<"Non posso fare il prodotto."<<endl;
	} while(n!=p);
	
	cout<<endl<<"Hai inserito A["<<n<<"]["<<m<<"] e B["<<m<<"]["<<p<<"]."<<endl;
	// Inizializzo le matrici
	int A[n][m];
	int B[m][p];
	int C[n][p];
	srand(time(NULL));
	
	// inserisco dei numeri casuali nelle matrici A e B
	cout<<endl<<"Genero le matrici... ";
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j]=rand()%5;
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			B[i][j]=rand()%5;
		}
	}
	cout<<"Fine."<<endl<<endl;
	
	// Visualizzo le due matrici
	cout<<"Visualizzo le matrici:"<<endl<<endl;
	cout<<"- matrice A:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<"- matrice B:"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// Calcolo il prodotto di AxB
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			for(int k=0; k<m; k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	
	// Stampo AxB
	cout<<"matrice C = (AxB):"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// Genero una matrice identità di ordine Id
	int I[Id][Id];
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			if(i==j)
				I[i][j]=1;
			else
				I[i][j]=0;
		}
	}
	
	// Stampa la matrice identita'
	cout<<endl<<endl<<"Stampo la matrice identita': "<<endl;
	for(int i=0; i<Id; i++){
		for(int j=0; j<Id; j++){
			cout<<I[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// Faccio il trasposto della matrice A (nxm) e lo inserisco in Amenouno
	int Amenouno[m][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			Amenouno[i][j] = A[j][i];
		}
	}
	
	// Stampa la matrice trasposta Amenouno
	cout<<endl<<endl<<"Stampo la matrice trasposta di A: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<Amenouno[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// Eseguo il prodotto fra A e Amenouno
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			for(int k=0; k<m; k++){
				C[i][j]+=A[i][k]*Amenouno[k][j];
			}
		}
	}
	
	// Stampa la matrice trasposta Amenouno
	cout<<endl<<endl<<"Stampo la matrice di controllo: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	system("PAUSE");
	return 0;
}

