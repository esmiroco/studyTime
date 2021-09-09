#include<iostream>
#include "funciones.h"
#include<string>
#include<cstring>

using namespace std;

bool condicion(){
	bool respuesta;
	string resp;
	cout<<endl<<"Deseas realizar alguna otra accion?"<<endl;
	cin>> resp;
	if((resp=="si")||(resp=="Si")||(resp=="yes")||(resp=="ok")||(resp=="SI")||(resp=="ya")){
		return true;
	}else{
		return false;
	}
}

dato1 hora_a_minutos(dato1 tiempo){
	if(tiempo>=100){
		tiempo=((tiempo/100)*60)+(tiempo%100);
	}
	tiempo=(dato1)tiempo;
	return tiempo;
}

dato1 minutos_a_hora(dato1 minutos){
	minutos=(int)minutos;
	if(minutos>=60){
		minutos=((minutos/60)*100)+(minutos%60);		
	}
	return (dato1)minutos;
}

dato1 tiempo_dia(dato1 h_inicio,dato1 h_actual){
	return ((h_actual)-(h_inicio));
}

void porcentaje_estudio(dato1 t_estudio, dato1 t_dia){
	double porcentaje;
	porcentaje=((double)t_estudio*100)/t_dia;
	cout<<"El porcentaje de estudio que llevas es: "<<porcentaje<<"%"<<endl;
}

void tiempo_reanudacion(dato1 t_estudio, dato1 h_inicio, dato1 t_dia){
	dato1 reanudacion,porcentaje,dif;
	cout<<"Ingresa aqui el porcentaje del que no quieres bajar: ";cin>>porcentaje;
	reanudacion=((t_estudio*100)/porcentaje);
	dif=reanudacion-t_dia;
	dif=minutos_a_hora(dif);
	reanudacion+=h_inicio;
	reanudacion=minutos_a_hora(reanudacion);
	if((reanudacion%100)<10){
		cout<<endl<<"La hora a la que debes reanudar el estudio es: "<<(reanudacion/100)<<":0"<<(reanudacion%100)<<endl;
	}else{
		cout<<endl<<"La hora a la que debes reanudar el estudio es: "<<(reanudacion/100)<<":"<<(reanudacion%100)<<endl;
	}
	
	if(dif>100){
		if((dif%100)<10){
			cout<<"Es decir, en "<<(dif/100)<<":0"<<(dif%100)<<" mas"<<endl;
		}else{
			cout<<"Es decir, en "<<(dif/100)<<":"<<(dif%100)<<" mas"<<endl;
		}
		
	}else{
		cout<<"Es decir, en "<<dif<<" minutos mas"<<endl;
	}
	
}
void tiempo_necesario(dato1 t_dia, dato1 t_estudio,dato1 h_actual){
	dato1 porcentaje, t_necesario, h_objetivo;
	cout<<"Que porcentaje de estudio diario quisieras alcanzar? ";cin>>porcentaje;
	t_necesario=((t_dia*porcentaje)-(100*t_estudio))/(100-porcentaje);
	h_objetivo=h_actual + t_necesario;
	h_objetivo=minutos_a_hora(h_objetivo);
	t_necesario=minutos_a_hora(t_necesario);
	if(t_necesario>=100){
		if((t_necesario%100)<10){
			cout<<endl<<"Tendrias que estudiar "<<(t_necesario/100)<<":0"<<(t_necesario%100)<<" continuos para alcanzar el porcentaje buscado"<<endl;
		}else{
			cout<<endl<<"Tendrias que estudiar "<<(t_necesario/100)<<":"<<(t_necesario%100)<<" continuos para alcanzar el porcentaje buscado"<<endl;
		}
		
	}else{
		cout<<endl<<"Tendrias que estudiar "<<t_necesario<<" minutos continuos para alcanzar el porcentaje buscado"<<endl;
	}
	if((h_objetivo%100)<10){
		cout<<"Es decir, hasta las "<<(h_objetivo/100)<<":0"<<(h_objetivo%100)<<endl;
	}else{
		cout<<"Es decir, hasta las "<<(h_objetivo/100)<<":"<<(h_objetivo%100)<<endl;
	}
	
}

void porcentaje_reanudacion(dato1 t_estudio, dato1 t_dia, dato1 h_actual){
	dato1 descanso,nuevo_porcentaje;
	cout<<"Ingresa aqui el tiempo de descanso que quieres darte: ";cin>>descanso;
	//transformar eventualmente tiempo descanso a minutos
	descanso=hora_a_minutos(descanso);
	nuevo_porcentaje=(t_estudio*100)/(t_dia+descanso);
	h_actual=h_actual+descanso;
	h_actual=minutos_a_hora(h_actual);
	cout<<endl<<"El porcentaje de estudio que tendras al retornar, a las "<<h_actual<<" sera de "<<nuevo_porcentaje<<"%"<<endl;
}

void porcentaje_logrado(dato1 t_estudio, dato1 t_dia, dato1 h_actual){
	dato1 objetivo, nuevo_porcentaje;
	cout<<"Ingresa aqui el tiempo de estudio que te propones realizar: ";cin>>objetivo;
	objetivo = hora_a_minutos(objetivo);
	nuevo_porcentaje=((t_estudio+objetivo)*100)/(t_dia+objetivo);
	h_actual=h_actual+objetivo;
	h_actual=minutos_a_hora(h_actual);
	cout<<endl<<"Lograrias un "<<nuevo_porcentaje<<"% estudiando hasta las "<<h_actual<<endl;
}

void selector(int opcion, dato1 h_inicio, dato1 h_actual, dato1 t_estudio, dato1 t_dia){
	switch(opcion){		
		case 1:{
			porcentaje_estudio(t_estudio,t_dia);
			break;
		}
		case 2:{
			tiempo_reanudacion(t_estudio,h_inicio,t_dia);
			break;
		}
		case 3:{
			tiempo_necesario(t_dia,t_estudio,h_actual);
			break;
		}
		case 4:{
			porcentaje_reanudacion(t_estudio, t_dia, h_actual);
			break;
		}
		case 5:{
			porcentaje_logrado(t_estudio, t_dia, h_actual);
			break;
		}
	}	
}
