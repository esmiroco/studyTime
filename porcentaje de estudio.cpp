#include<iostream>
#include<cconio>

typedef double dato1;
using namespace std;

dato1 hora_a_minutos(dato1);
dato1 minutos_a_hora(dato1);
dato1 tiempo_dia(dato1,dato1);
dato1 porcentaje_estudio(dato1,dato1);
void mostrar_porcentaje(dato1);
void tiempo_reanudacion(dato1);
void tiempo_necesario(dato1,dato1);
void selector(int,dato1,dato1,dato1);

int main(){
	int opcion;
	dato1 h_inicio,h_actual,t_estudio;
	cout<<"Bienvendio a tu programa de calculo de porcentajes y tiempos de estudio"<<endl;
	cout<<"Ingresa la hora del dia a la que empiezas a contabilizar el tiempo: ";cin>>h_inicio;
	cout<<"Ingresa la hora actual: ";cin>>h_actual;
	cout<<"Ingresa el tiempo actual de estudio: ";cin>>t_estudio;
	cout<<"Selecciona una de las siguientes opciones: "<<endl;
	cout<<"1.- Obtener porcentaje de estudio en el día"<<endl;
	cout<<"2.- Conocer tiempo de reanudacion de estudio para un porcentaje determinado"<<endl;
	cout<<"2.- Conocer el tiempo necesario de estudio para alcanzar un porcentaje determinado"<<endl;
	cin>>opcion;
	selector(opcion,h_inicio,h_actual,t_estudio);
	
	getch();
	return 0;
}

dato1 hora_a_minutos(dato1 hora){
	hora=(int)hora;
	if(hora>=100){
		hora=((hora/100)*60)+(hora%100);
	}
	hora=(dato1)hora;
	return hora;
}

dato1 minutos_a_hora(dato1 minutos){
	minutos=int(minutos)
	if(minutos>=60){
		minutos=((minutos/60)*100)+(minutos%60);		
	}
	return (dato1)minutos;
}

dato1 tiempo_dia(dato1 h_inicio,dato1 h_actual){
	h_inicio=hora_a_minutos(h_inicio);
	h_actual=hora_a_minutos(h_actual);
	return ((h_actual)-(h_inicio));
}

dato1 porcentaje_estudio(dato1 t_estudio, dato1 t_dia){
	dato1 porcentaje;
	porcentaje=(t_estudio*100)/t_dia;
	return porcentaje;
}

void mostrar_porcentaje(dato1 porcentaje){
	cout<<endl<<"El porcentaje de estudio actual es: "<<porcentaje<<endl;
}

void tiempo_reanudacion(dato1 t_estudio){
	dato1 reanudacion,porcentaje;
	cout<<"Ingresa aqui el porcentaje del que no quieres bajar: ";cin>>porcentaje
	reanudacion=((t_estudio*100)/porcentaje);
	reanudacion=minutos_a_hora(reanudacion);
	cout<<"La hora a la que debes reanudar el estudio es: "reanudacion<<endl;
}
void tiempo_necesario();

void selector(int opcion, dato1 h_inicio, dato1 h_actual, dato1 t_estudio){
	switch(ocpion){
		double t_dia,porcentaje;
		t_dia=tiempo_dia(h_inicio,h_actual);
		porcentaje=porcentaje_estudio(t_estudio,t_dia);
		case 1:{
			mostrar_porcentaje(porcentaje);
			break;
		}
		case 2:{
			tiempo_reanudacion(h_inicio,t_estudio);
			break;
		}
		case 3:{
			tiempo_necesario(h_inicio,t_estudio);
			break;
		}
	}	
}
