/*
	Autor: Jesus Angel Leon Diaz
	Programa: Algoritmo de Bresenham 1
	
	Este programa calcula los valores necesarios para dibujar una linea
	utilizando el algoritmo de Bresenham o punto medio.
	
	Solo imprime los valores de los puntos a dibujar, no dibuja ninguna linea.
	
	NO considera casos especiales, es decir, rectas con pendientes negativas.

*/

#include <stdio.h>

int main(){

	//Declaración de varoables
	/*Entiendase Xi = X inicial, Yi = Y inicial, Xf = X final, Yf = Y final, j = contador 
	(control de ciclo while), Dx = delta de X, Dy = delta de Y, DDx = delta de X por 2, 
	DDy = delta de Y por 2, Pk = parametro de decision Pk y m = pendiente de la recta a 
	calcular*/
    int Xi = 3, Xf = 9, Yi = 2, Yf = 9,  j = 0; 
    float m = 0.0, Dx = 0, Dy = 0, DDy = 0, DDx = 0, Pk = 0;
	
	/*Calculo de variables Dy, Dx y m*/    
    Dy = Yf - Yi;
    Dx = Xf - Xi;
    m = Dy/Dx; 
    
    /*Calculo de variables DDy, DDx y Pk*/
    DDx = Dx * 2;
    DDy = Dy * 2;
    Pk = Pk + DDy - Dx;
    
    printf("m = %f\n", m);
    printf("j = %i,\t Pk = %f,\t Xi = %i,\t Yi = %i\n",j,Pk,Xi,Yi);
    
    //Decision: se puede o no dibujar esta recta, es decir, es o no un caso especial
    if (((m < 1) && (m > 0))|| m == 1.0 || m == 0.0){
        
        //Si se puede calcular, se hace lo siguiente
        do{
            if (Pk<0){
                Xi = Xi + 1;
                Pk = Pk + DDy;
                j++;
            }
            else{
                Xi = Xi + 1;
                Yi = Yi + 1;
                Pk = Pk + DDy - DDx;
                j++;
            }
            
            printf("j = %i,\t Pk = %f,\t Xi = %i,\t Yi = %i\n",j,Pk,Xi,Yi); 
        }while(j < Dx);        
    }
    else{ //No se pude calcular, pues es una recta con pendiente negativa
        
        printf("Esta linea no se puede dibujar con el algoritmo, pues no cumple con la condicion de 0 <= m <= 1");

    }
    
    return 0;
}
