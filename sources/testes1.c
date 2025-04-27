#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

int main(){
	char especie;
	int macacerto=0,macaerrado=0,qqrcerto=0,qqrerrado=0;
	float finalWeight,referencia;
	float weight[8];
	float peso,volume,cor,posicao,textura,consistencia,temperatura,idade;
	srand(time(0));

	//inicializa os weights com valores buscados do txt
	FILE *fp=fopen("weights1.txt","r");
	for(int t=0;t<8;t++)fscanf(fp,"%f\n",&weight[t]); //busca no arquivo os weight da camada
	//for(int t=0;t<8;t++)fread(&weight[t],sizeof(float),1,fp);
	fscanf(fp,"%f\n",&finalWeight); //busca no arquivo o valor do weight final
	//fread(&finalWeight,sizeof(float),1,fp);
	fclose(fp);

	for(int x=0;x<1000;x++){
		if(rand()%2==0){
			especie='m';

			peso=0.8+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .8 e .9
			volume=0.7+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .7 e .8
			cor=0.6+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .6 e .7
			posicao=0.5+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .5 e .6
			textura=0.4+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .4 e .5
			consistencia=0.3+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .3 e .4
			temperatura=0.2+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .2 e .3
			idade=0.1+((float)rand()/(float)(RAND_MAX))/10.0; //valor entre .1 e .2
		}else{
			especie='q';

			peso=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			volume=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			cor=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			posicao=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			textura=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			consistencia=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			temperatura=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
			idade=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1
		}

		referencia=((peso*weight[0])+(volume*weight[1])+(cor*weight[2])+(posicao*weight[3])+(textura*weight[4])+(consistencia*weight[5])+(temperatura*weight[6])+(idade*weight[7]))/8;
		//printf("O valor obtido: %f | O valor esperado: %f\n",referencia,finalWeight);

		if(especie=='m')
			if(referencia>finalWeight-.4&&referencia<finalWeight+.4)macacerto++;else macaerrado++;
		else
			if(referencia>finalWeight-.4&&referencia<finalWeight+.4)qqrerrado++;else qqrcerto++;
	}
	printf("%d tentativas:\nEsperado maca dado maca: %d\nEsperado maca dado qqr: %d\nEsperado qqr dado qqr: %d\nEsperado qqr dado maca: %d\n",(macacerto+macaerrado+qqrcerto+qqrerrado),macacerto,macaerrado,qqrerrado,qqrcerto);

	return 0;
}

