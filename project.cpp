#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
using namespace std;

double comprobacion(double f[][4]){
	int cont = 0;
	for(int j=0; j < 4 ; j++){
		cont = 0;
		for(int i=0; i < 3;i++){
			if(f[j][i] == 0){
				cont++;
				if(cont == 3){
					cout<<"R/El sistema es Inconsistente";
					return 0;
				}
			}
		}		
	}
	return 1;
}
int escalonada(double f1[4], double f2[4],double f3[4]){
	if(f1[0] != 0 && f2[1] != 0 && f3[2] != 0) {
		return 1;
	}else if(f1[2] != 0 && f2[0] != 0 && f3[1] != 0){
		return 2;
	}else if(f1[1] != 0 && f2[2] != 0 && f3[0] != 0){
		return 3;
	}else if(f1[2] != 0 && f2[1] != 0 && f3[0] != 0){
		return 4;
	}else if(f1[0] != 0 && f2[2] != 0 && f3[1] != 0){
		return 5;
	}else if(f1[1] != 0 && f2[0] != 0 && f3[2] != 0){
		return 6;
	}else{
		return 0;
	}
}
int main(){
	double matriz[3][4];
	double matriz2[3][4];
	double f1[4];
	double f2[4];
	double f3[4];
	int forma;
	double cont;
	double contb;
	int k;
	//Recibir
	for(int j=0;j< 3 ; j++){
		for(int i = 0 ; i < 4 ; i++){
			if(i != 3){
				cout<<"x"<<i+1<<" = ";
				cin>>matriz[j][i];
			}else{
				cout<<"r"<<j+1<<" = ";
				cin>>matriz[j][i];
			}
		}
		cout<<endl;
	}	

	//Destructurar
	for(int j=0;j< 3 ; j++){
		
		int contInc = 0;
		for(int i = 0 ; i < 4 ; i++){
			if(j == 0){
				f1[i]=matriz[j][i];	
			}else if(j == 1){
				f2[i]=matriz[j][i];
			}else{
				f3[i]=matriz[j][i];
			}
		}
	}	

	if(comprobacion(matriz) == 0){
		cout<<"com";
		return 0;
	}
	
	//forma
	forma = escalonada(f1,f2,f3);
	
	if(forma == 1){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f1[i];	
				}else if(j == 1){
					matriz2[j][i] = f2[i];
				}else{
					matriz2[j][i] = f3[i];
				}
			}
		}
	}
	if(forma == 2){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f2[i];	
				}else if(j == 1){
					matriz2[j][i] = f3[i];
				}else{
					matriz2[j][i] = f1[i];
				}
			}
		}
	}
	if(forma == 3){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f3[i];	
				}else if(j == 1){
					matriz2[j][i] = f1[i];
				}else{
					matriz2[j][i] = f2[i];
				}
			}
		}
	}
	if(forma == 4){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f3[i];	
				}else if(j == 1){
					matriz2[j][i] = f2[i];
				}else{
					matriz2[j][i] = f1[i];
				}
			}
		}
	}
	if(forma == 5){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f1[i];	
				}else if(j == 1){
					matriz2[j][i] = f3[i];
				}else{
					matriz2[j][i] = f2[i];
				}
			}
		}
	}
	if(forma == 2){
		for(int j=0; j<3 ; j++){
			for(int i = 0 ; i < 4 ; i++){
				if(j == 0){
					matriz2[j][i] = f2[i];	
				}else if(j == 1){
					matriz2[j][i] = f1[i];
				}else{
					matriz2[j][i] = f3[i];
				}
			}
		}
	}
	
	//respuesta
	//cada fila
	for(int j=0;j< 3 ; j++){
		//para dar 1
		cont = matriz2[j][j];
		k = j;
		do{
			if(matriz2[k][j] != 0 && matriz2[k][j] != 1){
				contb = matriz2[k][j];
				for(int i = 0; i < 4;i++){
					if(j == k){
						matriz2[k][i] = matriz2[k][i]/cont;
					}else if(j != k){
						matriz2[k][i]=matriz2[k][i]-(contb * matriz2[j][i]);
					}
					}
			}		
			if(k < 2){
				k++;	
			}else{
				k = 0;	
			}
		if(comprobacion(matriz2) == 0){
			return 0;
		}		
		}while(k != j);
	}
	
	cout<<"*********RESPUESTA*********"<<endl;
	for(int j=0;j< 3 ; j++){
		for(int i = 0 ; i < 4 ; i++){
			if(i != 3){
				cout<<matriz2[j][i]<<"   ";
			}else{
				cout<<" = "<<matriz2[j][i];
			}
		}
		cout<<endl;
	}	
		
	getch();
	return 0;
}