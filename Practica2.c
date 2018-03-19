#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main() {
	int plaza1 = 0, plaza2 = 0; // Plaza 1 para coches, plaza 2 para motos
	int salir = 0;
	char opcionmenu, opcionvehiculo;
	char matricula1[8], matricula2[8], matriculabusqueda[8];


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
			if (plaza1 == 0 && plaza2 == 1) {

				printf("La plaza 1 esta libre, escriba su matricula\n");
				plaza1 = 1;
				printf("Introduzca su matricula: ");
				scanf_s("%s", matricula1, 8);
				system("cls");
			}
			else if (plaza1 == 0 && plaza2 == 0) {

				printf("Las dos plazas estan libres, se le ha asignado la 1\n");
				plaza1 = 1;
				printf("Introduzca su matricula: ");
				scanf_s("%s", matricula1, 8);
				system("cls");
			}

			else if (plaza1 == 1 && plaza2 == 0) {

				printf("Se le ha asignado la plaza 2\n");
				plaza2 = 1;
				printf("Introduzca su matricula: ");
				scanf_s("%s", matricula2, 8);
				system("cls");
			}
			else {
				printf("Las dos plazas estan ocupadas\n");
				system("cls");

			}
			break;

		case 'A':
		case'a':
			if (plaza1 == 0 && plaza2 == 0) { 
				printf("El parking esta vacio. Usted no puede abandonzar ninguna plaza.\n");
			}
			else {
				printf("Indiquenos la matricula del vehiculo que quiere retirar");
				scanf_s("%s", matriculabusqueda, 8);
				if (strcmp(matriculabusqueda, matricula1) == 0) {
					plaza1 = 0; 
				}
				else if (strcmp(matriculabusqueda, matricula2) == 0) { 
					plaza2 = 0;
				}
				else {
					printf("No encontramos la matricula seleccionada en el parking. Vuelva a intentarlo.\n");
				}
			}
			break;

		case 'E':
		case'e':
			if (plaza1 == 0) { 
				printf("La plaza de coche se encuentra libre en estos momentos\n");
			}
			else 
				printf("La plaza de coche se encuentra ocupada por un vehiculo con matricula: %s\n", matricula1);

			if (plaza2 == 0) { 
				printf("La plaza de moto se encuentra libre en estos momentos\n");
			}
			else 
				printf("La plaza de moto se encuentra ocupada por un vehiculo con matricula:: %s\n", matricula2);
			break;

		case 'b':
		case 'B':
			if (plaza1 == 1 || plaza2 == 1) {
				printf("Intoduzca la matricula del vehiculo que desea buscar\n");
				scanf_s("%s", matriculabusqueda, 8);
				if (strcmp(matriculabusqueda, matricula1) == 0) {
					printf("El vehiculo de matricula %s se encuentra  estacionado en la plaza 1\n", matricula1);
				}
				else if (strcmp(matriculabusqueda, matricula2) == 0) {
					printf("El vehiculo de martricula %s se encuentra estacionado en la plaza 2\n", matricula2);
				}
				else {
					printf("La matricula seleccionada no ha sido encontrada en ningun vehiculo del parking, lo sentimos.\n");
				}
			}
			else {
				printf("En estos momentos las plazas del parking se encuentran vacias\n");
			}
			break;

		case 's':
		case 'S':
			salir = 1;
			break;

		default:
			printf("La opcion seleccionada no es correcta\n");
		}
		system("pause");
		system("cls");
		getchar();

	}
}