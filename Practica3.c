#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct plaza {
	int estado;
	char opcionvechiculo;
	char matricula[8];
};

void main() {
	char usuario[20] = "gonzalo", contrasenia[20] = "050333";
	char usuario2[20], contrasenia2[20];
	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'M' }; // Plaza 1 para coches, plaza 2 para motos
	int matricula2[8];
	int salir = 0, salir1 = 0;
	char opcionmenu, opcionvehiculo;
	int i = 1;

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
					if (plaza1.estado == 1 && plaza2.estado == 1) {
						printf("Las plazas del parking están todas ocupadas\n");
					}
					else {
						printf("Introduzca el vehiculo que va a aparcar\n");
						printf("Pulse C si es un coche\n");
						printf("Pulse M si es una moto\n");
						scanf_s("%c", &opcionvehiculo);
						getchar();
						system("cls");

						switch (opcionvehiculo) {

						case 'c':
						case 'C':
							if (plaza1.estado == 0) {
								printf("Introduzca la matricula del vehiculo:");
								scanf_s("%s", plaza1.matricula, 8);
								plaza1.estado = 1;
							}
							else {
								printf("Las plazas de coche estan todas ocupadas\n");
							}
							break;

						case 'm':
						case 'M':
							if (plaza2.estado == 0) {
								printf("Introduzca la matricula del vehiculo:");
								scanf_s("%s", plaza2.matricula, 8);
								plaza2.estado = 1;
							}
							else {
								printf("Las plazas de moto estan todas ocupadas\n");
							}
							break;

						default:
							printf("Error. La opcion introducida no es correcta\n");
							break;
						}
					}
					break;

				case 'A':
				case'a':
					if (plaza1.estado == 0 && plaza2.estado == 0) {
						printf("El parking esta vacio. Usted no puede abandonzar ninguna plaza.\n");
					}
					else {
						printf("Indiquenos la matricula del vehiculo que quiere retirar");
						scanf_s("%s", matricula2, 8);
						if (strcmp(matricula2, plaza1.matricula) == 0) {
							plaza1.estado = 0;
						}
						else if (strcmp(matricula2, plaza2.matricula) == 0) {
							plaza2.estado = 0;
						}
						else {
							printf("No encontramos la matricula seleccionada en el parking. Vuelva a intentarlo.\n");
						}
					}
					break;

				case 'E':
				case'e':
					if (plaza1.estado == 0) {
						printf("La plaza de coche se encuentra libre en estos momentos\n");
					}
					else
						printf("La plaza de coche se encuentra ocupada por un vehiculo con matricula: %s\n", plaza1.matricula);

					if (plaza2.estado == 0) {
						printf("La plaza de moto se encuentra libre en estos momentos\n");
					}
					else
						printf("La plaza de moto se encuentra ocupada por un vehiculo con matricula:: %s\n", plaza2.matricula);
					break;

				case 'b':
				case 'B':
					if (plaza1.estado == 1 || plaza2.estado == 1) {
						printf("Intoduzca la matricula del vehiculo que desea buscar\n");
						scanf_s("%s", matricula2, 8);
						if (strcmp(matricula2, plaza1.matricula) == 0) {
							printf("El vehiculo de matricula %s se encuentra  estacionado en la plaza 1\n", plaza1.matricula);
						}
						else if (strcmp(matricula2, plaza2.matricula) == 0) {
							printf("El vehiculo de martricula %s se encuentra estacionado en la plaza 2\n", plaza2.matricula);
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