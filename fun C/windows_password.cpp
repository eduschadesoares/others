	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <locale.h>
	#include <unistd.h>
	#include <conio.h>
	
	int password(int);
		
	int main() {
		int a;
		system("color 07");
		if(password(a)!=1) {
			system("color 4F");
			printf("O programa será encerrado.\n");
			sleep(4);
			system("cls");
			return 0;
		}
		system("color 07");
		system("pause");
		return 0;
	}
	
	int password(int robson) {
		setlocale(LC_ALL, "portuguese");
		int i, j, N=30, junior, alonso, cleber=0, nelso=3;
		char V[N];
		const char C[]= {"robson"};
		junior=strlen(C);
		alonso=strlen(C);
		
		//Apresentação da senha
		system("color 0E");
		for(j=0; j<1; j++) {
			printf("Iniciando");
			usleep(200000);
			printf(".");
			usleep(200000);
			printf(".");
			usleep(200000);
			printf(".");
			usleep(200000);
			system("cls");				
		}
		
		//Início da verificação de tentativas
		while(nelso>=0) {
			system("color 0E");
			printf("Insira a senha:");
			printf("\n");
			for(alonso=strlen(C); alonso>0; alonso--) {
				printf("|¯|\t", alonso);
			}
			i=0;
			cleber=0;
			printf("\n");
					
		//Início do teste da senha dentro da leitura
			while(i<junior) {
				V[i]=getch();		
				if(V[i]==C[i]) {
					printf(" * \t");
				}
				else {
					printf(" * \t");
					cleber++;				
				}
				i++;
				}
					
			usleep(500000);
			system("cls");
			
			if(cleber==0) {
				system("color 17");
				for(j=0; j<1; j++) {
					printf("Processando");
					usleep(300000);
					printf(".");
					usleep(200000);
					printf(".");
					usleep(600000);
					printf(".");
					usleep(600000);
					system("cls");				
				}
				for(j=0; j<1; j++) {
					printf("Entrando");
					usleep(200000);
					printf(".");
					usleep(400000);
					printf(".");
					usleep(200000);
					printf(".");
					usleep(100000);
					system("cls");
				}
				for(j=0; j<2; j++) {
					printf("Aguarde");
					usleep(300000);
					printf(".");
					usleep(300000);
					printf(".");
					usleep(300000);
					printf(".");
					usleep(300000);
					system("cls");				
				}
				system("color 2F");
				printf(" ==============\n");
				printf(" ===  NICE  ===\n");
				printf(" ==============\n");
				sleep(3);
				system("cls");
					return 1;
			}
			else {
				if(nelso>1) {					
					for(j=0; j<3; j++) {
					system("color 4F");
					printf("Senha incorreta, tente novamente. (%d tentativas restantes)\n", nelso);
					printf("Aguarde");
					usleep(200000);
					printf(".");
					usleep(200000);
					printf(".");
					usleep(200000);
					printf(".");
					usleep(200000);
					system("cls");				
					}					
				}
				else {
					if(nelso==1) {					
					for(j=0; j<3; j++) {
						system("color 4F");
						printf("Senha incorreta, tente novamente. (%d tentativa restante)\n", nelso);
						printf("Aguarde");
						usleep(200000);
						printf(".");
						usleep(400000);
						printf(".");
						usleep(200000);
						printf(".");
						usleep(200000);
						system("cls");				
					}
					}
				}
				nelso--;					
			}	
		}
		
		for(j=0; j<2; j++) {
					system("color 4F");
					printf("Aguarde");
					usleep(400000);
					printf(".");
					usleep(400000);
					printf(".");
					usleep(400000);
					printf(".");
					usleep(400000);
					system("cls");				
		}
		printf("  ===============================================================================\n");
		printf("  ==  Voçê atingiu o número máximo de tentativas. Tente novamente mais tarde.  ==\n");
		printf("  ===============================================================================\n");
		sleep(5);
		system("cls");	
		return 0;
	}
