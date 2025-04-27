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

	int imagens=200; //quantidade de imagens
	float margemQuad=0.9,margemCirc=1.8;
	float finalWeightQuad,finalWeightCirc;
	float weightsQuadrado[qtdpedacos];
	float weightsCirculo[qtdpedacos];
	short amostra[imagens][qtdpedacos];
	int quadradoreconhecido=0,naoquadradoreconhecido=0;
	int circuloreconhecido=0,naocirculoreconhecido=0;
	srand(time(0));

	char filename[200][24]; //variavel que guarda o nome das 200 imagens
	for(int x=0;x<200;x++)sprintf(filename[x],"imagens/amostra%d.bmp",x);

	//extrai uns valores nos arquivos imagem e armazena em um array 'amostra'
	for(int c=0;c<imagens;c++){
		fp=fopen(filename[c],"r");
		for(int x=0;x<qtdpedacos*100;x++)fread(&amostra[c][x/100],sizeof(short),1,fp);
		fclose(fp);
	}

	//inicializa os weight com valores buscado do arquivo
	fp=fopen("weightsQuadrado.txt","r");
	for(int t=0;t<qtdpedacos;t++)fscanf(fp,"%f\n",&weightsQuadrado[t]); //busca no arquivo os weight da camada
	fscanf(fp,"%f\n",&finalWeightQuad); //busca no arquivo o valor do weight final
	fclose(fp);

	fp=fopen("weightsCirculo.txt","r");
	for(int t=0;t<qtdpedacos;t++)fscanf(fp,"%f\n",&weightsCirculo[t]); //busca no arquivo os weight da camada
	fscanf(fp,"%f\n",&finalWeightCirc); //busca no arquivo o valor do weight final
	fclose(fp);

	printf("\n\nfinalWeightQuad %f\nfinalWeightCirc %f\n\n",finalWeightQuad,finalWeightCirc);

	for(int x=0;x<500;x++){
		int alguma=(rand()%imagens)/2; //escolhe um quadrado qualquer
		float referencia=0.0;
		for(int t=0;t<qtdpedacos;t++)referencia-=(amostra[alguma][t]*weightsQuadrado[t]);
		referencia/=23;
		if(referencia>finalWeightQuad-(finalWeightQuad*margemQuad)&&referencia<finalWeightQuad+(finalWeightQuad*margemQuad))quadradoreconhecido++;
		referencia=0.0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weightsCirculo[t]);
		if(referencia>finalWeightCirc-(finalWeightCirc*margemCirc)&&referencia<finalWeightCirc+(finalWeightCirc*margemCirc))naoquadradoreconhecido++;
	}
	for(int x=0;x<500;x++){
		int alguma=100+((rand()%imagens)/2); //escolhe um circulo qualquer
		float referencia=0.0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weightsCirculo[t]);
		referencia/=-23;
		if(referencia>finalWeightCirc-(finalWeightCirc*margemCirc)&&referencia<finalWeightCirc+(finalWeightCirc*margemCirc))circuloreconhecido++;
		referencia=0.0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weightsQuadrado[t]);
		if(referencia>finalWeightQuad-(finalWeightQuad*margemQuad)&&referencia<finalWeightQuad+(finalWeightQuad*margemQuad))naocirculoreconhecido++;
	}

	printf("%d quadrados reconhecidos\n",quadradoreconhecido);
	printf("%d quadrados nao reconhecidos\n",500-quadradoreconhecido);
	printf("%d nao-quadrados reconhecidos (erro-q)\n\n",naoquadradoreconhecido);

	printf("%d circulos reconhecidos\n",circuloreconhecido);
	printf("%d circulos nao reconhecidos\n",500-circuloreconhecido);
	printf("%d nao-circulos reconhecidos (erro-c)\n\n",naocirculoreconhecido);

	return 0;
}

