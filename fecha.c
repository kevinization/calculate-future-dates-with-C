// Librerias necesarias para la ejecucion.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Metodo principal.
main()
{
	// Variables necesarias para la ejecucion.
	int opcion = 0;
	bool opcionFecha = true;
	bool ciclo = true;
	bool fechaCorrecta = 0;
	bool diasConMesCorrectos = true;

	int dia = 0;
	int mes = 0;
	int ano = 0;

	int diasRestantes = 0;
	
	int diasFechaFutura = 0;
	int mesesFechaFutura = 0;
	int anosFechaFutura = 0;
	
	int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int contadorAnos = 0;

	int otraCita = 0;
	
	// Titulo del programa.
	printf("** Programa que calcula la fecha de cita al Consulado General de Estados Unidos **\n\n");
	
	// Estructura de control While para mostrar el menu.
	while (ciclo)
	{
		// Opciones del menu.
		printf("M E N U\n");
		printf("1. Imprimir nombre y matricula.\n");
		printf("2. Introducir fecha.\n");
		printf("3. Salir.\n");
		printf("Opcion: ");
		scanf("%i", &opcion);
		opcionFecha = true;

		// Estructura selectiva switch para el control de la opcion seleccionada.
		switch (opcion){
			// Impresion del nombre y matricula.
			case 1:
				printf("Nombre: Alan Aaron Ramirez Ravelo\n");
				printf("Matricula: es221104464\n\n");
				break;
			// Calculo de la cita.
			case 2:
				// Estructura de control While para ingresar la fecha.
				while (opcionFecha)
				{
					// Asignaciones de valor a las variables necesarias.
					diasConMesCorrectos = true;
					dia = 0;
					mes = 0;
					ano = 0;
					fechaCorrecta = 0;
					diasRestantes = 0;
					diasFechaFutura = 0;
					mesesFechaFutura = 0;
					anosFechaFutura = 0;
					contadorAnos = 0;
					otraCita = 0;
					
					// Peticion y almacenamiento del dia.
					printf("Ingrese el dia: ");
					scanf("%i", &dia);
					
					//Validacion para que no ingrese un dia con un valor erroneo.
					if (dia > 31 || dia < 1){
						printf("Existe un error en la informacion proporcionada, intente de nuevo.\n\n");
					}
					else {
						// Peticion y almacenamiento del mes.
						printf("Ingrese el mes (en numero): ");
						scanf("%i", &mes);
						// Validacion para que no ingrese un mes con un valor erroneo.
						if (mes > 12 || mes < 1){
							printf("Existe un error en la informacion proporcionada, intente de nuevo.\n\n");
						}
						else{
							int i;
							for (i = 0; i < 11; i++){
								// Validacion por si ingresa un mes que no tiene los dias indicados.
								if (mes == (i + 1) && dia > meses[i]){
									printf("El mes seleccionado no tiene esos dias, intente de nuevo.\n");
									diasConMesCorrectos = false;
								}
							}
							// Validacion por si el mes si tiene los dias indicados.
							if (diasConMesCorrectos == true){
								// Peticion y almacenamiento del año.
								printf("Ingrese el ano: ");
								scanf("%i", &ano);
								// Confirmacion de la fecha ingresada.
								printf("La fecha que ingresaste es: %i/%i/%i, es correcta?\n1. Si\n2. No\n3. Ir al menu\nOpcion: ", dia, mes, ano);
								scanf("%i", &fechaCorrecta);
								// Validacion por si ingresa un valor erroneo en la confirmacion.
								if (fechaCorrecta < 1 || fechaCorrecta > 3){
									printf("Ha introducido un valor incorrecto, vuelva a intentarlo.\n");
								}
								else{
									// Si selecciona ir al menu.
									if (fechaCorrecta == 3){
										opcionFecha = false;
										printf("\n");
									}
									else{
										// Si selecciona que la fecha no es correcta.
										if (fechaCorrecta == 2){
											printf("Vuelva a introducir la fecha.\n\n");
										}
										else
										{
											// Si selecciona que la fecha si es correcta.
											if (fechaCorrecta == 1)
											{
												// Calcular los dias.
												diasRestantes = meses[mes - 1] - dia;
												
												int i;
												// Estructura de control For para recorrer los meses.
												for(i = mes - 1; i <= 11; i++) {
													// Si ya recorrio los 548 dias.
													if(diasRestantes >= 548) {
														diasFechaFutura = meses[i] - (diasRestantes - 548);
														mesesFechaFutura = i + 1;
														anosFechaFutura = ano + contadorAnos;
														// Resultado del calculo de la cita.
														printf("Fecha de la cita: %i/%i/%i\n", diasFechaFutura, mesesFechaFutura, anosFechaFutura);
														// Se pregunta si quiere calcular otra cita y se almacena la opcion.
														printf("Desea realizar el calculo de otra cita?\n1. Si\n2. No\nOpcion: ");
														scanf("%i", &otraCita);
														// Si se quiere calcular otra cita.
														if(otraCita == 1){
															break;
														}
														else {
															// Si se quiere calcular otra cita.
															if(otraCita == 2) {
																printf("\n");
																opcionFecha = false;
																break;
															}else {
																// Si se introduce un valor erroneo.
																printf("Ha introducido un valor incorrecto, vuelva a introducir la fecha.\n");
																break;
															}
															
														}
													} else {
														// Si se llega al ultimo mes y aun no se acumulan los 548 dias.
														if(i == 11 && diasRestantes < 548) {
															i = -1;
															contadorAnos++;
														}
													}
													// Acumulacion de los dias.
													diasRestantes = diasRestantes + meses[i + 1];
													
													
												}
												
											}
										}
									}
								}
							}
						}
					}
				}
	
				break;
			// Salir del programa.
			case 3:
				exit(-1);
				break;
		}
		
	}
	return 0;
}
