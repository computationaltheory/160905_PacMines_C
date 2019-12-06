#include <stdio.h>
#include <windows.h>  
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<ctype.h>
#include "funcionespacmines.h"
int u=1;
main()
{
	char nombres[50];
	char numero[1];
	int menu;
	system("color 17");
	gotoxy(20,1);
	printf("Universidad Politecnica de San Luis potosi\n Gabriel Gonzalez Orocio \n 160905\n Teoría Computacional");
	Sleep(1000);
	system("cls");
	system("color 47");
	gotoxy(33,10);
	printf("Bienvenido");
	Sleep(500);
	system("cls");
	srand(time(NULL));
	/*da el mensaje de bienvenida con los datos del creador*/
	do
	{
		int error=0;
		do{
			error=0;
		system("cls");
		gotoxy(5,14);
		printf("1.-Jugar");
		gotoxy(35,14);
		printf("2.-Instrucciones");
		gotoxy(65,14);
		printf("3.-Salir");
		gotoxy(33,10);
		/*imprime el menú de opciones*/
		printf("Eliga Una Opcion");
		gotoxy(40,11);
		fflush( stdin );
		gets(numero);
		if(isdigit(numero[0])==0)
			error=1;
		else
			error=0;	
		}while(error==1);//recibe una de las tres opciones que deben ser entero 
		menu=atoi(numero);//convierte la eleccion a entero
		switch(menu)
		{
			case 1:
				{
					registro(nombres);
					u+=1;
					//int aleatorio=1+rand()%5;//elige el aleatorio para saber que mapa te toca
					int aleatorio=5;
					switch(aleatorio)
					{
						case 1:jugar1(nombres);
							break;
						case 2:jugar2(nombres);
							break;
						case 3:jugar3(nombres);
							break;
						case 4:jugar4(nombres);
							break;
						case 5:jugar5(nombres);
							break;	
					}
				}
				break;
			case 2:
				instrucciones();
				break;
			case 3:
				system("cls");
				break;		//se borra la información y cierrael programa
		}
	
	}while(menu!=3);
	
	
	
	
}
