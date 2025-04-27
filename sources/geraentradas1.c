#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

typedef struct{
	float peso;
	char especie;
} fruta;

int main(){
	fruta amostra;
	srand(time(0));

	FILE *fp=fopen("entradas1.txt","w");
	for(int x=0;x<25;x++){
		amostra.especie='m'; //macas
		amostra.peso=0.082+((float)rand()/(float)(RAND_MAX))/1000.0; //valor entre 0.082 e 0.092
		//fwrite(&amostra,sizeof(amostra),1,fp); //grava no arquivo
		fprintf(fp,"%f %c\n",amostra.peso,amostra.especie); //grava no arquivo
	}
	for(int x=0;x<25;x++){
		amostra.especie='q'; //fruta qualquer
		amostra.peso=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		//fwrite(&amostra,sizeof(amostra),1,fp); //grava no arquivo
		fprintf(fp,"%f %c\n",amostra.peso,amostra.especie); //grava no arquivo
	}
	fclose(fp);

	fopen("entradas1.txt","r");
	for(int x=0;x<50;x++){
		//fread(&amostra,sizeof(amostra),1,fp); //busca no arquivo
		fscanf(fp,"%f %c\n",&amostra.peso,&amostra.especie); //busca no arquivo
		printf("%2d) %f %c\n",x,amostra.peso,amostra.especie); //exibe na tela
	}
	fclose(fp);

	return 0;
}

