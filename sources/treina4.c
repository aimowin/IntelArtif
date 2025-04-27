#include<stdio.h> //FILE
#include<stdlib.h> //rand
#include<time.h>

int main(){
	//a funcao fopen indica qual arquivo sera manipulado
	//a funcao fseek move o ftell ate o ultimo byte do arquivo
	//para que a funcao ftell indique o tamanho

	FILE * fp=fopen("imagens/amostra0.bmp","r");
	fseek(fp,0,SEEK_END);
	int qtdpedacos=(ftell(fp)/100)-54; //quantidade de pedacos de cada imagem

	int imagens=100; //quantidade de imagens
	float learningRate=0.0000001;
	float finalWeight;
	float weight[qtdpedacos];
	short amostra[imagens][qtdpedacos];
	srand(time(0));

	char filename[100][24]; //variavel que guarda o nome das 100 imagens
	for(int x=100;x<200;x++)sprintf(filename[x-100],"imagens/amostra%d.bmp",x);

	//extrai uns valores nos arquivos imagem e armazena em um array 'amostra'
	for(int c=0;c<imagens;c++){
		fp=fopen(filename[c],"r");
		for(int x=0;x<qtdpedacos*100;x++)fread(&amostra[c][x/100],sizeof(short),1,fp);
		fclose(fp);
	}

	//inicializa os weight com um valor aleatorio
	for(int t=0;t<qtdpedacos;t++)weight[t]=2+((float)rand()/(float)(RAND_MAX))/1.0;
	finalWeight=5+((float)rand()/(float)(RAND_MAX))/1.0;

	for(int x=0;x<3000000;x++){ //ajusta os weight milhares de vezes
		int alguma=((rand()%imagens)/2); //escolhe uma amostra qualquer

		for(int t=0;t<qtdpedacos;t++){
			//ajusta os weight pouco a pouco
			if(amostra[alguma][t]>weight[t])weight[t]=weight[t]+(weight[t]*learningRate); //um pouco a mais
			else if(amostra[alguma][t]<weight[t])weight[t]=weight[t]-(weight[t]*learningRate); //um pouco a menos
		}

		float referencia=0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weight[t])/qtdpedacos;

		//ajusta o weight final pouco a pouco
		if(referencia>finalWeight)finalWeight=finalWeight+(finalWeight*learningRate); //um pouco a mais
		else if(referencia<finalWeight)finalWeight=finalWeight-(finalWeight*learningRate); //um pouco a menos

		printf("weight = %f\n",finalWeight);
	}

	fp=fopen("weightsCirculo.txt","w");
	for(int t=0;t<qtdpedacos;t++)fprintf(fp,"%f\n",weight[t]); //grava no arquivo os weight da camada
	fprintf(fp,"%f\n",finalWeight); //grava no arquivo o weight final
	fclose(fp);

	return 0;
}

