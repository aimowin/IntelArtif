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
	float finalWeight;
	float weight[8];
	fruta amostra[30];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas2.txt","r");
	for(int x=0;x<30;x++)fread(&amostra[x],sizeof(fruta),1,fp);
	fclose(fp);

	//inicializa os weight com um valor aleatorio
	for(int t=0;t<8;t++)weight[t]=((float)rand()/(float)(RAND_MAX))/1.0;
	finalWeight=((float)rand()/(float)(RAND_MAX))/1.0;

	for(int x=0;x<4000;x++){ //ajusta os weight centenas de vezes
		int alguma=rand()%15; //escolhe uma maca qualquer

		float caracteristica[8]={amostra[alguma].peso,amostra[alguma].volume,amostra[alguma].cor,amostra[alguma].posicao,amostra[alguma].textura,amostra[alguma].consistencia,amostra[alguma].temperatura,amostra[alguma].idade};

		for(int t=0;t<8;t++){
			//ajusta os weight pouco a pouco
			if(caracteristica[t]>weight[t])weight[t]=weight[t]+(weight[t]*0.01); //um pouco a mais
			else if(caracteristica[t]<weight[t])weight[t]=weight[t]-(weight[t]*0.01); //um pouco a menos
		}

		float referencia=(weight[0]+weight[1]+weight[2]+weight[3]+weight[4]+weight[5]+weight[6]+weight[7])/8;

		//ajusta o weight final
		if(referencia>finalWeight)finalWeight=finalWeight+(finalWeight*0.01); //um pouco a mais
		else if(referencia<finalWeight)finalWeight=finalWeight-(finalWeight*0.01); //um pouco a menos

		printf("w = [ %f %f %f %f %f %f %f %f ] finalWeight = %f\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7],finalWeight);
	}

	fp=fopen("weights1.txt","w");
	//for(int t=0;t<8;t++)fwrite(&weight[t],sizeof(float),1,fp); //grava no arquivo os weight da camada
	for(int t=0;t<8;t++)fprintf(fp,"%f\n",weight[t]); //grava no arquivo os weight da camada
	fprintf(fp,"%f\n",finalWeight); //grava no arquivo o weight final
	//fwrite(&finalWeight,sizeof(float),1,fp); //grava no arquivo o weight final
	fclose(fp);

	printf("\nOs valores que diferenciam = %f %f %f %f %f %f %f %f e o valor final %f foram inseridos no arquivo weights1.txt\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7],finalWeight);

	return 0;
}

