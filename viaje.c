#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mostrarMenu();
float calcularImporte(int, int);
void mostrarDetalle(int, float);
void vaciarBuffer();

int main ()
{
  int id, inicio, acum_viajes, edad, aux_id, destino;
  char pass[20], aux_pass[20], rta;
  float acum_importe, importe, mayor;
  mayor = 0;
  do{
    importe = 0;
    edad = 0;

    printf("\n Ingrese su edad: \n");
    scanf("%d", &edad);
    vaciarBuffer();
    printf("\n Ingrese su identificacion: \n");
    scanf("%d", &id);
    vaciarBuffer();
    printf("\n Ingrese su password: \n");
    scanf("%s", pass);
    vaciarBuffer();
    printf("\n Por favor seleccione el codigo de la estacion de inicio \n");
    inicio = mostrarMenu();
    vaciarBuffer();
    printf("\n Ingrese su identificacion: \n");
    scanf("%d", &aux_id);
    vaciarBuffer();
    printf("\n Ingrese su password: \n");
    scanf("%s", aux_pass);
    vaciarBuffer();

    while (id != aux_id || strcmp(pass, aux_pass)){
      printf("ERROR identificacion o password incorrecto");
      printf("\n Ingrese su identificacion: \n");
      scanf("%d", &aux_id);
      printf("\n Ingrese su password: \n");
      scanf("%s", aux_pass);
   }

    printf("\n Por favor seleccione el codigo de la estacion de destino\n");
    destino = mostrarMenu();
    importe = calcularImporte(inicio, destino);

    if(edad < 5){
      importe = 0;
    }
    printf("\nEl importe a abonar es de: $%.2f \n", importe);
    if (mayor == 0){
      mayor = importe;
    }
    if(mayor < importe){
      mayor = importe;
    }

    acum_viajes = acum_viajes +1;
    acum_importe = acum_importe + importe;

    vaciarBuffer();
    printf("\n Pulse \'s\' para seguir cargando viajes, pulse \'n\' para finalizar \n");
    scanf("%c", &rta);
  }while (rta == 's');
  printf("\n %d personas viajaron \n", acum_viajes);
  printf("\n El importe total de viajes es de: $%.2f \n", acum_importe);
  printf("\n El mayor importe abonado es de: $%.2f \n", mayor);
  return 0;
}

int mostrarMenu(){
  int seleccion;
  printf("\n Selecione el numero correspondiente a la estacion: \n1 Moreno \n2 Paso del rey \n3 Merlo\n4 Padua\n5 Ituzaingó\n6 Castelar\n7 Morón\n8 Haedo\n9 Ramos Mejía\n10 Ciudadela\n11 Liniers\n12 Villa Luro\n13 Floresta\n14 Flores\n15 Caballito\n16 Once\n");
  scanf("%d", &seleccion);
  return seleccion;
}

void vaciarBuffer(){
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

float calcularImporte(int a, int b){
  float importe;
  printf("\n Calculando importe...\n");
  importe = (b-a)*2;
  if(importe < 0){
    importe = -importe;
  }
  return importe;
}
