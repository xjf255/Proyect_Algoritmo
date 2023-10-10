//Nombre Adrian Juan Fernando Diaz Tazen
//Curso, Algoritmos
//Sección B
//Nombre programa : Intereses

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
using namespace std;

void imprimir(double f1[4], double f2[4],double f3[4]){
	cout<<"*********RESPUESTA*********"<<endl;
	for(int i=0; i <4;i++){
		if(i==3){
			cout<<"= "<<f1[i];
		}else{
			cout<<f1[i]<<" ";
		}
	}
	cout<<endl;
	for(int i=0; i <4;i++){
		if(i==3){
			cout<<"= "<<f2[i];
		}else{
			cout<<f2[i] <<" ";
		}
	}
	cout<<endl;
	for(int i=0; i <4;i++){
		if(i==3){
			cout<<"= "<<f3[i];
		}else{
			cout<<f3[i]<<" ";
		}
	}	
	cout<<endl;
}
int comprobacion(double f[4]){
	int cont = 0;
	for(int i=0; i < 3;i++){
		if(f[i] == 0){
			cont++;
			if(cont == 3){
				cout<<"R/El sistema es Inconsistente";
				return 0;
			}
		}
	}	
}
int escalonada(double f1[4], double f2[4],double f3[4]){
	if(f1[0] != 0 && f2[1] != 0 && f3[2] != 0) {
//		cout<<f1<<f2<<f3;
		return 1;
	}else if(f1[2] != 0 && f2[1] != 0 && f3[0] != 0){
		return 3;
	}else{
		return 2;
	}
}
int main(){
	double matriz[3][4];
	double f1[4];
	double f2[4];
	double f3[4];
	int forma;
	double cont;
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
	if(comprobacion(f1) == 0 || comprobacion(f2) == 0 || comprobacion(f3) == 0){
		return 0;
	}
	forma = escalonada(f1,f2,f3);
	if(forma == 3){
		cont = f3[0];
		for(int i= 0; i<4;i++){
			f3[i]=f3[i]/cont;
		}
		if(f2[0] != 0){
			cont = f2[0];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f3[i]);
			}	
		}
		if(f1[0] != 0){
			cont = f1[0];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f3[i]);
			}
		}	
		//2da columna
		cont = f2[1];
		for(int i= 0; i<4;i++){
			f2[i]=f2[i]/cont;
		}	
		if(f3[1] != 0){
			cont = f3[1];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f2[i]);
			}	
		}
		if(f1[1] != 0){
			cont = f1[1];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f2[i]);
			}
		}
		//3ra Columna
		cont = f1[2];
		for(int i= 0; i<4;i++){
			f1[i]=f1[i]/cont;
		}	
		if(f3[2] != 0){
			cont = f3[2];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f1[i]);
			}	
		}
		if(f2[2] != 0){
			cont = f2[2];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f1[i]);
			}
		}
		if(comprobacion(f1) == 0 || comprobacion(f2) == 0 || comprobacion(f3) == 0){
			return 0;
		}
		imprimir(f3,f2,f1);
	}else if(forma == 1){
		cont = f1[0];
		for(int i= 0; i<4;i++){
			f1[i]=f1[i]/cont;
		}
		if(f2[0] != 0){
			cont = f2[0];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f1[i]);
			}	
		}
		if(f3[0] != 0){
			cont = f3[0];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f1[i]);
			}
		}	
		//2da columna
		cont = f2[1];
		for(int i= 0; i<4;i++){
			f2[i]=f2[i]/cont;
		}	
		if(f3[1] != 0){
			cont = f3[1];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f2[i]);
			}	
		}
		if(f1[1] != 0){
			cont = f1[1];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f2[i]);
			}
		}
		//3ra Columna
		cont = f3[2];
		for(int i= 0; i<4;i++){
			f3[i]=f3[i]/cont;
		}	
		if(f1[2] != 0){
			cont = f1[2];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f3[i]);
			}	
		}
		if(f2[2] != 0){
			cont = f2[2];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f3[i]);
			}
		}
		if(comprobacion(f1) == 0 || comprobacion(f2) == 0 || comprobacion(f3) == 0){
			return 0;
		}
		imprimir(f1,f2,f3);
	}else{
		cont = f2[0];
		for(int i= 0; i<4;i++){
			f2[i]=f2[i]/cont;
		}
		if(f1[0] != 0){
			cont = f1[0];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f2[i]);
			}	
		}
		if(f3[0] != 0){
			cont = f3[0];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f2[i]);
			}
		}	
		//2da columna
		cont = f1[1];
		for(int i= 0; i<4;i++){
			f1[i]=f1[i]/cont;
		}	
		if(f3[1] != 0){
			cont = f3[1];
			for(int i= 0; i<4;i++){
				f3[i]=f3[i]-(cont*f1[i]);
			}	
		}
		if(f2[1] != 0){
			cont = f2[1];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f1[i]);
			}
		}
		//3ra Columna
		cont = f3[2];
		for(int i= 0; i<4;i++){
			f3[i]=f3[i]/cont;
		}	
		if(f1[2] != 0){
			cont = f1[2];
			for(int i= 0; i<4;i++){
				f1[i]=f1[i]-(cont*f3[i]);
			}	
		}
		if(f2[2] != 0){
			cont = f2[2];
			for(int i= 0; i<4;i++){
				f2[i]=f2[i]-(cont*f3[i]);
			}
		}
		if(comprobacion(f1) == 0 || comprobacion(f2) == 0 || comprobacion(f3) == 0){
			return 0;
		}
		imprimir(f1,f2,f3);
	}
	getch();
	return 0;
}