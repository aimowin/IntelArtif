#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

typedef struct{
	float peso;
	char especie;
} fruta;

int main(){
	fruta amostra[50];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas1.txt","r");
	for(int x=0;x<50;x++){
		//fread(&amostra[x],sizeof(fruta),1,fp);
		fscanf(fp,"%f %c\n",&amostra[x].peso,&amostra[x].especie); //busca no arquivo
		//printf("%2d) %f %c\n",x,amostra[x].peso,amostra[x].especie); //exibe na tela
	}
	fclose(fp);

	//inicializa o weight com um valor aleatorio
	float weight=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1

	for(int x=0;x<4000;x++){ //ajusta o weight centenas de vezes
		int alguma=rand()%25; //escolhe uma maca qualquer da amostra

		//printf("%d) [%c] %f\n",alguma,amostra[alguma].especie,amostra[alguma].peso);

		//ajusta o weight pouco a pouco
		if(amostra[alguma].peso>weight)weight=weight+(weight*0.01); //um pouco a mais
		else if(amostra[alguma].peso<weight)weight=weight-(weight*0.01); //um pouco a menos

		//printf("weight: %f\n",weight);
	}
	printf("O valor que diferencia (weight): %f\n",weight);

	return 0;
}

