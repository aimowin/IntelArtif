#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

typedef struct{
	float peso;
	float volume;
	float cor;
	float posicao;
	float textura;
	float consistencia;
	float temperatura;
	float idade;
	char especie;
} fruta;

int main(){
	fruta amostra;
	srand(time(0));

	FILE *fp=fopen("entradas2.txt","w");
	for(int x=0;x<15;x++){
		amostra.especie='m'; //macas

		amostra.peso=0.8+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .8 e .9
		amostra.volume=0.7+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .7 e .8
		amostra.cor=0.6+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .6 e .7
		amostra.posicao=0.5+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .5 e .6
		amostra.textura=0.4+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .4 e .5
		amostra.consistencia=0.3+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .3 e .4
		amostra.temperatura=0.2+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .2 e .3
		amostra.idade=0.1+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .1 e .2

		fwrite(&amostra,sizeof(amostra),1,fp); //grava no arquivo
	}
	for(int x=0;x<15;x++){
		amostra.especie='q'; //fruta qualquer

		amostra.peso=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.volume=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.cor=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.posicao=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.textura=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.consistencia=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.temperatura=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		amostra.idade=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1

		fwrite(&amostra,sizeof(amostra),1,fp); //grava no arquivo
	}
	fclose(fp);

	fopen("entradas2.txt","r");
	for(int x=0;x<30;x++){
		//busca todos valores no arquivo e exibe na tela
		fread(&amostra,sizeof(amostra),1,fp);
		printf("%d) %f %f %f %f %f %f %f %f %c\n",x,amostra.peso,amostra.volume,amostra.cor,amostra.posicao,amostra.textura,amostra.consistencia,amostra.temperatura,amostra.idade,amostra.especie);
	}
	fclose(fp);

	return 0;
}

