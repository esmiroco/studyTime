#include<iostream>
#include "funciones.h"
#include<conio.h>

typedef int dato1;
using namespace std;

int main(){
	int opcion;
	dato1 h_inicio,h_actual,t_estudio,t_dia;
	cout<<"Bienvendio a tu programa de calculo de porcentajes y tiempos de estudio"<<endl;

	cout<<"Ingresa la hora del dia a la que empiezas a contabilizar el tiempo: ";cin>>h_inicio;
	cout<<"Ingresa la hora actual: ";cin>>h_actual;
	cout<<"Ingresa el tiempo actual de estudio: ";cin>>t_estudio;

	h_inicio=hora_a_minutos(h_inicio);
	h_actual=hora_a_minutos(h_actual);
	t_estudio=hora_a_minutos(t_estudio);
	t_dia=h_actual-h_inicio;
	
	cout<<endl;
	porcentaje_estudio(t_estudio,t_dia);

	bool respuesta=true;

	while(respuesta){
		cout<<endl<<"Selecciona una de las siguientes opciones: "<<endl;
	
		cout<<"1.- Obtener porcentaje de estudio en el dia"<<endl;
		cout<<"2.- Conocer tiempo de reanudacion de estudio para un porcentaje determinado"<<endl;
		cout<<"3.- Conocer el tiempo necesario de estudio para alcanzar un porcentaje determinado"<<endl;
		cout<<"4.- Conocer el porcentaje que tendrias tras un receso de duracion a especificar"<<endl;
		cout<<"5.- Conocer el porcentaje que tendrias tras estudiar un tiempo determinado a partir de ahora"<<endl;

		cin>>opcion;
		cout<<endl;
		selector(opcion,h_inicio,h_actual,t_estudio,t_dia);

		respuesta=condicion();
	}
	
	
	getch();
	return 0;
}
