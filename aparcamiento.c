#include <stdio.h>
#include <stdlib.h>

void main() {
	int plaza1 = 0, plaza2 = 0; 
	char opcion1, matricula1[8], matricula2[8], opcion2;

	while (1) {

		printf("BIENVENIDO A LA PAGINA DONDE USTED PUEDE RESERVAR SU APARCAMIENTO\n\n");
		printf("Seleccione una de estas opciones:\n"
			"R - Reservar plaza\n"
			"A - Abandonar plaza\n"
			"E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion1);
		getchar();
		system("cls");

		switch (opcion1) {

		case'r':
		case 'R': // En caso de reservar una plaza
			if (plaza1 == 0 && plaza2 == 0) {
				printf("Las dos plazas del aparcamiento estan libres, ocupe la plaza 1 por favor\n");
				plaza1 = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula1, 8);
				getchar();
				system("PAUSE");
				system("cls");
			}
			else if (plaza1 == 1 && plaza2 == 0) {
				printf("La plaza numero 1 esta ocupada, ocupe la plaza 2 por favor\n");
				plaza2 = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula1, 8);
				getchar();
				system("PAUSE");
				system("cls");
			}
			else if (plaza1 == 0 && plaza2 == 1) {
				printf("La plaza numero 2 esta ocupada, ocupe la plaza 1 por favor\n");
				plaza1 = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula1, 8);
				getchar();
				system("PAUSE");
				system("cls");
			}
			else {
				printf("Las dos plazas estan ya ocupadas\n");
				system("PAUSE");
				system("cls");
			}
			break;

		case 'a':
		case 'A': 
			if (plaza1 == 1 || plaza2 == 1) {
				printf("Indiquenos que plaza estaba ocupando\n");
				scanf_s("%c", &opcion2);
				getchar();

				switch (opcion2) {
				case '1':
					printf("Usted ha abandonado la plaza 1...¡Vuelva pronto!\n");
					plaza1 = 0;
					system("PAUSE");
					system("cls");
					break;
				case '2':
					printf("Usted ha abandonado la plaza 2...¡Vuelva pronto!\n");
					plaza2 = 0;
					system("PAUSE");
					system("cls");
					break;
				default:
					printf("Esa plaza no corresponde a niguna del parking\n");
					system("PAUSE");
					system("cls");
					break;
				}
			}
			else {
				printf("No hay plazas ocupadas.\n");
				system("pause");
				system("cls");
			}
			break;

		case 'E':
		case 'e': 
			if (plaza1 == 0 && plaza2 == 0) {
				printf("Plaza 1 - Libre \n");
				printf("Plaza 2 - Libre \n");
				system("PAUSE");
				system("cls");
			}
			else if (plaza1 == 0 && plaza2 == 1) {
				printf("Plaza 1 - Libre \n");
				printf("Plaza 2 - Ocupada - Matricula %s \n", matricula2);
				system("PAUSE");
				system("cls");
			}
			else if (plaza1 == 1 && plaza2 == 0) {
				printf("Plaza 1 - Ocupada - Matricula %s \n", matricula1);
				printf("Plaza 2 - Libre\n");
				system("PAUSE");
				system("cls");
			}
			else {
				printf("Plaza A - Ocupada - Matricula %s \n", matricula1);
				printf("Plaza B - Ocupada - Matricula %s \n", matricula2);
				system("PAUSE");
				system("cls");
			}
			break;

		default:  
			printf("La opcion seleccionada no es correcta\n");
			system("pause");
			system("cls");
		}

		
	}

system("PAUSE");
}
