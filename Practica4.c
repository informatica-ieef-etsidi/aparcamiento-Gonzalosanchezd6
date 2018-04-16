#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NPLAZAS 10

struct plaza {
	int estado;
	char opcionvechiculo;
	char matricula[8];
};

void main() {
	char usuario[20] = "gonzalo", contrasenia[20] = "050333";
	char usuario2[20], contrasenia2[20];
	struct plaza parking[NPLAZAS];
	int matricula2[8];
	int salir = 0, salir1 = 0, ocupado = 0;
	char opcionmenu, opcionvehiculo;
	int i = 1, j;

	for ( i = 0; i < NPLAZAS; i++) {
		parking[i].estado = 0;
	}
	i = 1;

	while (salir1 == 0) {

		printf("Introduzca su usuario:\n");
		gets(usuario2);
		printf("Introduzca su contrasenia:\n");
		gets(contrasenia2);
		if (strcmp(usuario2, usuario) == 0 && strcmp(contrasenia2, contrasenia) == 0) {
			printf("Buenas. Usted estad en el aparcamiento\n");
			system("pause");
			system("cls");

			while (salir == 0) {

				printf("BIENVENIDO A LA PAGINA DONDE USTED PUEDE RESERVAR SU APARCAMIENTO\n\n");
				printf("Seleccione una de estas opciones:\n"
					"R - Reservar plaza\n"
					"A - Abandonar plaza\n"
					"E - Estado del aparcamiento\n"
					"B - Buscar vehículo por matricula\n"
					"S - Salir del programa\n");
				scanf_s("%c", &opcionmenu);
				getchar();
				system("cls");

				switch (opcionmenu) {

				case 'R':
				case'r':
					ocupado = 0;
					i = 0;
					
					while (ocupado == 0 && i < NPLAZAS) {
						if (parking[i].estado == 0) {
							parking[i].estado = 1;
							printf("Indique si el vehiculo que va a aparcar es un coche(C) o moto(M)\n");
							scanf_s("%c", &parking[i].opcionvechiculo);
							getchar();
							
							while (parking[i].opcionvechiculo != 'c' && parking[i].opcionvechiculo != 'C' && parking[i].opcionvechiculo != 'm' && parking[i].opcionvechiculo != 'M') {
								printf("Opcion incorrecta, vuelva a introducir el tipo de vehiculo\n");
								getchar();
								scanf_s("%c", &parking[i].opcionvechiculo);
							}
							
							printf("Indique la matricula de su vehiculo\n");
							scanf_s("%s", parking[i].matricula, 8);
							ocupado = 1;
						}
						i++;
					}
					if (ocupado == 0) {
						printf("Todas las plazas del parking estan ocupadas\n");
					}
					break;

				case 'A':
				case'a':
					j = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (parking[i].estado == 0) {
							j++;
						}
					}
					if (j == (NPLAZAS - 1)) {
						printf("No encontramos ningun coche para retirar de su aparcamiento\n");
					}
					else {
						printf("Introduce la matricula del coche que quiere retirar:");
						scanf_s("%s", matricula2, 8);
						ocupado = 0;
						i = 0;
						while (ocupado == 0 && i < NPLAZAS) {
							if (parking[i].estado == 1) {
								if (strcmp(matricula2, parking[i].matricula) == 0) {
									parking[i].estado = 0; 
									ocupado = 1;
								}
							}
							i++;
						}
						if (ocupado == 0) {
							printf("La matricula introducida no ha sido encontrada\n");
						}
					}
					break;

				case 'E':
				case'e':
					for (i = 0; i < NPLAZAS; i++) {
						if (parking[i].estado == 0) {
							printf("La plaza %d del parking esta libre\n", i + 1);
						}
						else {
							printf("La plaza %d esta ocupada. Matricula del vehiculo: %s\n", i + 1, parking[i].matricula);
						}
					}
					break;

				case 'b':
				case 'B':
					j = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (parking[i].estado == 0) {
							j++;
						}
					}
					if (j == (NPLAZAS - 1)) {
						printf("El parking esta vacio\n");
					}
					else {
						printf("Introduce la matricula del vehiculo que quiere buscar:\n");
						scanf_s("%s", matricula2, 8);
						ocupado = 0;
						i = 0;
						
						while (ocupado == 0 && i < NPLAZAS) {
							if (parking[i].estado == 1) {
								if (strcmp(matricula2, parking[i].matricula) == 0) {
									printf("El vehiculo con matricula %s se encuentra en la plaza 1\n", parking[i].matricula);
									ocupado = 1;
								}
							}
							i++;
						}
						if (ocupado == 0) {
							printf("La matricula no es igual a ninguna de las que hay en el parking\n");
						}
					}
					break;

				case 's':
				case 'S':
					salir = 1;
					salir1 = 1;
					break;

				default:
					printf("La opcion seleccionada no es correcta\n");
				}
				system("pause");
				system("cls");
				getchar();

			}
		}
		else {
			if (i == 3) {
				printf("Tenias 3 intentos como maximo. Lo sentimos\n");
				salir1 = 1;
			}
			else {
				printf("Error. Hay un fallo en el usuario o en la contrasenia\n");
				printf("Te quedan %d intentos\n", 3 - i);
				printf("Vuelve a introducir el usuario y la contrasenia por favor\n");
				i++;
			}
			system("pause");
		}
	}
}