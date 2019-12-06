void instrucciones(void);
int registro(char nombres[50]);
void jugar1(char nombres[50]);
void jugar2(char nombres[50]);
void jugar3(char nombres[50]);
void jugar4(char nombres[50]);
void jugar5(char nombres[50]);
void ganaste(void);
void perdiste(void);
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 void instrucciones()
 /*Esta funcion dice las instrucciones del juego*/
{
	system("cls");
	gotoxy(33,10);
	printf("Las reglas son:");
	Sleep(1000);
	system("cls");
	gotoxy(1,1);
	printf("1.-Para desplazarse, se elegira la posicion en base al renglon y la columna por medio de las teclas W(arriba)A(izquierda)x(abajo)D(derecha)");
    gotoxy(1,3);
	printf("2.-No puede desplazarse si existe una pared de por medio");	
	gotoxy(1,5);
	printf("3.-Cada movimiento se registra,cada ficha amarilla vale 1 punto");	
	gotoxy(1,7);
	printf("4.-Si topa con pared en dos ocasiones el juego termina.\n\n\n\n\n\n\n\n");
	system("pause");//se pausa hasta recibir una tecla
}
int registro(char nombres[50])
{
	int i,v;
	do{
		v=0;
	system("cls");
	gotoxy(33,10);
	printf("Dame tu nombre\n");
	fflush(stdin);//limpia para recibir el nombre
	gotoxy(33,11);
	gets(nombres);
	for(i=0;i<strlen(nombres);i++)
	{
		if(isalpha(nombres[i])==0&&isspace(nombres[i])==0)
		{
			v++;
		}
	}
	}while(v>0||strlen(nombres)<1);//validacion del nombre para que sean solo letras y no sea nulo
	system("cls");
	return 1;
}
void jugar1(char nombres[50])
{
	typedef struct{
	int x;
	int y;
}posicion;//estructura para la posicion
	FILE *archivo;
	archivo=fopen("datosdejuego.txt","w");
	int ceros[10][10];
	posicion jugador={5,5};
	posicion obstaculo[7] ={26,5,54,9,12,13,40,19,33,15,54,19,19,21};
	posicion punto[3]= {47,13,68,17,47,23};
	/*Estructuras con pisiciones x y y */
	char c;
	int a=3,p=0,p2=0,i,j;
	gotoxy(33,10);
	printf("PAC-MINES (Mapa1)");
	Sleep(1000);
	system("color 27");	
	Sleep(1000);
	system("color 37");
	Sleep(1000);
	system("color 67");
	Sleep(1000);
	system("color 57");
	system("cls");
	/*Animacion que muestra el nombre del juego cambiando de colores*/
	for(i=0;i<10;i++)
		{
			for( j=0;j<10;j++)
			{
				ceros[i][j]=0;
				gotoxy(5+j*7,5+i*2);
				printf("%d",ceros[i][j]);
			}
			printf("\n");
			gotoxy(obstaculo[0].x,obstaculo[0].y);
			printf("%c",219);
			gotoxy(obstaculo[1].x,obstaculo[1].y);
			printf("%c",219);
			gotoxy(obstaculo[2].x,obstaculo[2].y);
			printf("%c",219);
			gotoxy(obstaculo[3].x,obstaculo[3].y);
			printf("%c",219);
			gotoxy(obstaculo[4].x,obstaculo[4].y);
			printf("%c",219);
			gotoxy(obstaculo[5].x,obstaculo[5].y);
			printf("%c",219);
			gotoxy(obstaculo[6].x,obstaculo[6].y);
			printf("%c",219);
			gotoxy(punto[0].x,punto[0].y);
			printf("$");
			gotoxy(punto[1].x,punto[1].y);
			printf("$");
			gotoxy(punto[2].x,punto[2].y);
			printf("$");
			gotoxy(jugador.x,jugador.y);
			printf ("1");
		}
	Sleep(5000);	
	system("cls");
	/*imprime el arreglo con sus obstaculos y sus posiciones por 5 segundos*/
	do
	{
		gotoxy(20,0);
		printf("Coordenadas x:%d y:%d Movimientos:%d Puntos:%d Vidas:%d",jugador.x,jugador.y,p,p2,a);
		do
		{
		c=getch();//recibe solamente un caracter
		if(c=='a')
			jugador.x-=7;
		if(c=='d')
			jugador.x+=7;
		if(c=='w')
			jugador.y-=2;
		if(c=='x')
			jugador.y+=2;
		}while(jugador.y<5||jugador.y>23||jugador.x<5||jugador.x>68);
		system("cls");
		p++;	
			for(i=0;i<3;i++)
		{
			if(jugador.x==punto[i].x&&jugador.y==punto[i].y)
			{
				system("cls");
				gotoxy(20,0);
				p2++;
				printf("%d puntos de 3",p2);
				Sleep(500);
				system("cls");
			//si el jugador toma un punto se incrementa 
			}
		}	
		for(i=0;i<7;i++)
		{
			if(jugador.x==obstaculo[i].x&&jugador.y==obstaculo[i].y)
			{
				system("cls");
				gotoxy(20,0);
				printf("Perdiste una vida");
				Sleep(500);
				system("cls");
				a--;
				//si el jugador comparte posicion con el obstaculo pierde una vida y lo muestra en la pantalla
			}
		}
		for( i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				gotoxy(5+j*7,5+i*2);
				printf("x");
			}
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}//reimprime las posiciones nuevas
	
	}while(a>0&&p2<3);
	if(p2==3)
		ganaste();//si tienes todos los puntos y conservas minimo una vida te manda a la funcion ganaste
	if(a==0)
		perdiste();//si pierdes todas las vidas te manda a la funcion perdiste
	fprintf(archivo, "%s\t", nombres);
	fprintf(archivo, "%d\t", p);
	fprintf(archivo, "%d\t", p2);
	fclose(archivo);
	system("cls");
	system("pause");
}
void jugar2(char nombres[50])
/*Funcion igual a la funcion jugar 1 ,mismos comentarios*/
{
	typedef struct{
	int x;
	int y;
}posicion;
	FILE *archivo;
	archivo=fopen("datosdejuego.txt","w");
	int ceros[10][10];
	posicion jugador={5,5};
	posicion obstaculo[7] ={26,5,54,9,12,13,40,19,33,15,54,19,19,21};
	posicion punto[3]= {47,13,68,17,47,23};
	char c;
	int a=3,p=0,p2=0,i,j;
	gotoxy(33,10);
	printf("PAC-MINES (Mapa 2)");
	Sleep(1000);
	system("color 27");	
	Sleep(1000);
	system("color 37");
	Sleep(1000);
	system("color 67");
	Sleep(1000);
	system("color 57");
	system("cls");
	for(i=0;i<10;i++)
		{
			for( j=0;j<10;j++)
			{
				ceros[i][j]=0;
				gotoxy(5+j*7,5+i*2);
				printf("%d",ceros[i][j]);
			}
			printf("\n");
			gotoxy(obstaculo[0].x,obstaculo[0].y);
			printf("%c",219);
			gotoxy(obstaculo[1].x,obstaculo[1].y);
			printf("%c",219);
			gotoxy(obstaculo[2].x,obstaculo[2].y);
			printf("%c",219);
			gotoxy(obstaculo[3].x,obstaculo[3].y);
			printf("%c",219);
			gotoxy(obstaculo[4].x,obstaculo[4].y);
			printf("%c",219);
			gotoxy(obstaculo[5].x,obstaculo[5].y);
			printf("%c",219);
			gotoxy(obstaculo[6].x,obstaculo[6].y);
			printf("%c",219);
			gotoxy(punto[0].x,punto[0].y);
			printf("$");
			gotoxy(punto[1].x,punto[1].y);
			printf("$");
			gotoxy(punto[2].x,punto[2].y);
			printf("$");
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	Sleep(5000);	
	system("cls");
	do
	{
		gotoxy(20,0);
		printf("Coordenadas x:%d y:%d Movimientos:%d Puntos:%d Vidas:%d",jugador.x,jugador.y,p,p2,a);
		do
		{
		c=getch();
		if(c=='a')
			jugador.x-=7;
		if(c=='d')
			jugador.x+=7;
		if(c=='w')
			jugador.y-=2;
		if(c=='x')
			jugador.y+=2;
		}while(jugador.y<5||jugador.y>23||jugador.x<5||jugador.x>68);
		system("cls");
		p++;	
			for(i=0;i<3;i++)
		{
			if(jugador.x==punto[i].x&&jugador.y==punto[i].y)
			{
				system("cls");
				gotoxy(20,0);
				p2++;
				printf("%d puntos de 3",p2);
				Sleep(500);
				system("cls");
				
			}
		}	
		for(i=0;i<7;i++)
		{
			if(jugador.x==obstaculo[i].x&&jugador.y==obstaculo[i].y)
			{
				system("cls");
				gotoxy(20,0);
				printf("Perdiste una vida");
				Sleep(500);
				system("cls");
				a--;
			}
		}
		for( i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				gotoxy(5+j*7,5+i*2);
				printf("x");
			}
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	
	}while(a>0&&p2<3);
	if(p2==3)
		ganaste();
	if(a==0)
		perdiste();
	fprintf(archivo, "%s\t", nombres);
	fprintf(archivo, "%d\t", p);
	fprintf(archivo, "%d\t", p2);
	fclose(archivo);	
	system("cls");
	system("pause");
}
void jugar3(char nombres[50])
/*Funcion igual a la funcion jugar 1 ,mismos comentarios*/
{
	typedef struct{
	int x;
	int y;
}posicion;
	FILE *archivo;
	archivo=fopen("datosdejuego.txt","w");
	int ceros[10][10];
	posicion jugador={5,5};
	posicion obstaculo[7] ={26,5,54,9,12,13,40,19,33,15,54,19,19,21};
	posicion punto[3]= {47,13,68,17,47,23};
	char c;
	int a=3,p=0,p2=0,i,j;
	gotoxy(33,10);
	printf("PAC-MINES (Mapa 3)");
	Sleep(1000);
	system("color 27");	
	Sleep(1000);
	system("color 37");
	Sleep(1000);
	system("color 67");
	Sleep(1000);
	system("color 57");
	system("cls");
	for(i=0;i<10;i++)
		{
			for( j=0;j<10;j++)
			{
				ceros[i][j]=0;
				gotoxy(5+j*7,5+i*2);
				printf("%d",ceros[i][j]);
			}
			printf("\n");
			gotoxy(obstaculo[0].x,obstaculo[0].y);
			printf("%c",219);
			gotoxy(obstaculo[1].x,obstaculo[1].y);
			printf("%c",219);
			gotoxy(obstaculo[2].x,obstaculo[2].y);
			printf("%c",219);
			gotoxy(obstaculo[3].x,obstaculo[3].y);
			printf("%c",219);
			gotoxy(obstaculo[4].x,obstaculo[4].y);
			printf("%c",219);
			gotoxy(obstaculo[5].x,obstaculo[5].y);
			printf("%c",219);
			gotoxy(obstaculo[6].x,obstaculo[6].y);
			printf("%c",219);
			gotoxy(punto[0].x,punto[0].y);
			printf("$");
			gotoxy(punto[1].x,punto[1].y);
			printf("$");
			gotoxy(punto[2].x,punto[2].y);
			printf("$");
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	Sleep(5000);	
	system("cls");
	do
	{
		gotoxy(20,0);
		printf("Coordenadas x:%d y:%d Movimientos:%d Puntos:%d Vidas:%d",jugador.x,jugador.y,p,p2,a);
		do
		{
		c=getch();
		if(c=='a')
			jugador.x-=7;
		if(c=='d')
			jugador.x+=7;
		if(c=='w')
			jugador.y-=2;
		if(c=='x')
			jugador.y+=2;
		}while(jugador.y<5||jugador.y>23||jugador.x<5||jugador.x>68);
		system("cls");
		p++;	
			for(i=0;i<3;i++)
		{
			if(jugador.x==punto[i].x&&jugador.y==punto[i].y)
			{
				system("cls");
				gotoxy(20,0);
				p2++;
				printf("%d puntos de 3",p2);
				Sleep(500);
				system("cls");
				
			}
		}	
		for(i=0;i<7;i++)
		{
			if(jugador.x==obstaculo[i].x&&jugador.y==obstaculo[i].y)
			{
				system("cls");
				gotoxy(20,0);
				printf("Perdiste una vida");
				Sleep(500);
				system("cls");
				a--;
			}
		}
		for( i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				gotoxy(5+j*7,5+i*2);
				printf("x");
			}
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	
	}while(a>0&&p2<3);
	if(p2==3)
		ganaste();
	if(a==0)
		perdiste();
	fprintf(archivo, "%s\t", nombres);
	fprintf(archivo, "%d\t", p);
	fprintf(archivo, "%d\t", p2);
	fclose(archivo);	
	system("cls");
	system("pause");
}
void jugar4(char nombres[50])
/*Funcion igual a la funcion jugar 1 ,mismos comentarios*/
{
	typedef struct{
	int x;
	int y;
}posicion;
	FILE *archivo;
	archivo=fopen("datosdejuego.txt","w");
	int ceros[10][10];
	posicion jugador={5,5};
	posicion obstaculo[7] ={26,5,54,9,12,13,40,19,33,15,54,19,19,21};
	posicion punto[3]= {47,13,68,17,47,23};
	char c;
	int a=3,p=0,p2=0,i,j;
	gotoxy(33,10);
	printf("PAC-MINES (Mapa 4)");
	Sleep(1000);
	system("color 27");	
	Sleep(1000);
	system("color 37");
	Sleep(1000);
	system("color 67");
	Sleep(1000);
	system("color 57");
	system("cls");
	for(i=0;i<10;i++)
		{
			for( j=0;j<10;j++)
			{
				ceros[i][j]=0;
				gotoxy(5+j*7,5+i*2);
				printf("%d",ceros[i][j]);
			}
			printf("\n");
			gotoxy(obstaculo[0].x,obstaculo[0].y);
			printf("%c",219);
			gotoxy(obstaculo[1].x,obstaculo[1].y);
			printf("%c",219);
			gotoxy(obstaculo[2].x,obstaculo[2].y);
			printf("%c",219);
			gotoxy(obstaculo[3].x,obstaculo[3].y);
			printf("%c",219);
			gotoxy(obstaculo[4].x,obstaculo[4].y);
			printf("%c",219);
			gotoxy(obstaculo[5].x,obstaculo[5].y);
			printf("%c",219);
			gotoxy(obstaculo[6].x,obstaculo[6].y);
			printf("%c",219);
			gotoxy(punto[0].x,punto[0].y);
			printf("$");
			gotoxy(punto[1].x,punto[1].y);
			printf("$");
			gotoxy(punto[2].x,punto[2].y);
			printf("$");
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	Sleep(5000);	
	system("cls");
	do
	{
		gotoxy(20,0);
		printf("Coordenadas x:%d y:%d Movimientos:%d Puntos:%d Vidas:%d",jugador.x,jugador.y,p,p2,a);
		do
		{
		c=getch();
		if(c=='a')
			jugador.x-=7;
		if(c=='d')
			jugador.x+=7;
		if(c=='w')
			jugador.y-=2;
		if(c=='x')
			jugador.y+=2;
		}while(jugador.y<5||jugador.y>23||jugador.x<5||jugador.x>68);
		system("cls");
		p++;	
			for(i=0;i<3;i++)
		{
			if(jugador.x==punto[i].x&&jugador.y==punto[i].y)
			{
				system("cls");
				gotoxy(20,0);
				p2++;
				printf("%d puntos de 3",p2);
				Sleep(500);
				system("cls");
				
			}
		}	
		for(i=0;i<7;i++)
		{
			if(jugador.x==obstaculo[i].x&&jugador.y==obstaculo[i].y)
			{
				system("cls");
				gotoxy(20,0);
				printf("Perdiste una vida");
				Sleep(500);
				system("cls");
				a--;
			}
		}
		for( i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				gotoxy(5+j*7,5+i*2);
				printf("x");
			}
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	
	}while(a>0&&p2<3);
	if(p2==3)
		ganaste();
	if(a==0)
		perdiste();
	fprintf(archivo, "%s\t", nombres);
	fprintf(archivo, "%d\t", p);
	fprintf(archivo, "%d\t", p2);
	fclose(archivo);	
	system("cls");
	system("pause");
}
void jugar5(char nombres[50])
/*Funcion igual a la funcion jugar 1 ,mismos comentarios*/
{
	
	typedef struct{
	int x;
	int y;
}posicion;
	FILE *archivo;
	archivo=fopen("datosdejuego.txt","w");
	int ceros[10][10];
	posicion jugador={5,5};
	posicion obstaculo[7] ={26,5,54,9,12,13,40,19,33,15,54,19,19,21};
	posicion punto[3]= {47,13,68,17,47,23};
	char c;
	int a=3,p=0,p2=0,i,j;
	gotoxy(33,10);
	printf("PAC-MINES (Mapa 5)");
	Sleep(1000);
	system("color 27");	
	Sleep(1000);
	system("color 37");
	Sleep(1000);
	system("color 67");
	Sleep(1000);
	system("color 57");
	system("cls");
	for(i=0;i<10;i++)
		{
			for( j=0;j<10;j++)
			{
				ceros[i][j]=0;
				gotoxy(5+j*7,5+i*2);
				printf("%d",ceros[i][j]);
			}
			printf("\n");
			gotoxy(obstaculo[0].x,obstaculo[0].y);
			printf("%c",219);
			gotoxy(obstaculo[1].x,obstaculo[1].y);
			printf("%c",219);
			gotoxy(obstaculo[2].x,obstaculo[2].y);
			printf("%c",219);
			gotoxy(obstaculo[3].x,obstaculo[3].y);
			printf("%c",219);
			gotoxy(obstaculo[4].x,obstaculo[4].y);
			printf("%c",219);
			gotoxy(obstaculo[5].x,obstaculo[5].y);
			printf("%c",219);
			gotoxy(obstaculo[6].x,obstaculo[6].y);
			printf("%c",219);
			gotoxy(punto[0].x,punto[0].y);
			printf("$");
			gotoxy(punto[1].x,punto[1].y);
			printf("$");
			gotoxy(punto[2].x,punto[2].y);
			printf("$");
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	Sleep(5000);	
	system("cls");
	do
	{
		gotoxy(20,0);
		printf("Coordenadas x:%d y:%d Movimientos:%d Puntos:%d Vidas:%d",jugador.x,jugador.y,p,p2,a);
		do
		{
		c=getch();
		if(c=='a')
			jugador.x-=7;
		if(c=='d')
			jugador.x+=7;
		if(c=='w')
			jugador.y-=2;
		if(c=='x')
			jugador.y+=2;
		}while(jugador.y<5||jugador.y>23||jugador.x<5||jugador.x>68);
		system("cls");
		p++;	
			for(i=0;i<3;i++)
		{
			if(jugador.x==punto[i].x&&jugador.y==punto[i].y)
			{
				system("cls");
				gotoxy(20,0);
				p2++;
				printf("%d puntos de 3",p2);
				Sleep(500);
				system("cls");
				
			}
		}	
		for(i=0;i<7;i++)
		{
			if(jugador.x==obstaculo[i].x&&jugador.y==obstaculo[i].y)
			{
				system("cls");
				gotoxy(20,0);
				printf("Perdiste una vida");
				Sleep(500);
				system("cls");
				a--;
			}
		}
		for( i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				gotoxy(5+j*7,5+i*2);
				printf("x");
				gotoxy(obstaculo[0].x-6,obstaculo[0].y);
			printf("%d",1);
			gotoxy(obstaculo[1].x-6,obstaculo[1].y);
			printf("%d",1);
			gotoxy(obstaculo[2].x-6,obstaculo[2].y);
			printf("%d",1);
			gotoxy(obstaculo[3].x-6,obstaculo[3].y);
			printf("%d",1);
			gotoxy(obstaculo[4].x-6,obstaculo[4].y);
			printf("%d",1);
			gotoxy(obstaculo[5].x-6,obstaculo[5].y);
			printf("%d",1);
			gotoxy(obstaculo[6].x-6,obstaculo[6].y);
			printf("%d",1);
			}
			gotoxy(jugador.x,jugador.y);
			printf ("<");
		}
	
	}while(a>0&&p2<3);
	if(p2==3)
		ganaste();
	if(a==0)
		perdiste();	
	fprintf(archivo, "%s\t", nombres);
	fprintf(archivo, "%d\t", p);
	fprintf(archivo, "%d\t", p2);
	fclose(archivo);	
	system("cls");
	system("pause");
}
void ganaste()
{
		int i,j;
	for(i=25;i>-5;i--)
	{
		system("cls");
		gotoxy(25,i);
		printf("You WIN");
		gotoxy(25,i+1);
		printf("Created by:Gabriel Gonzalez Orocio");
		gotoxy(25,i+2);
		printf("Teoria computacional");
		gotoxy(25,i+3);
		printf("2019");
		Sleep(100);
	}//imprime que ganaste y muestra los creditos del juego
}
void perdiste()
{
		int i,j;
	for(i=25;i>-5;i--)
	{
		system("cls");
		gotoxy(25,i);
		printf("You LOSE");
		gotoxy(25,i+1);
		printf("Created by:Gabriel Gonzalez Orocio");
		gotoxy(25,i+2);
		printf("Teoria computacional");
		gotoxy(25,i+3);
		printf("2019");
		Sleep(100);
	}//imprime que perdiste y muestra los creditos del juego
}

