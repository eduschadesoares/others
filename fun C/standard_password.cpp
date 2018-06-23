	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <locale.h>
	#include <unistd.h>
	#include <conio.h>

	int password(int);

	int main() {
		int a, b, c;
		if(password(a)==1) {
			return 0;
		}
		system("pause");
	}

	int password(int robson) {
		setlocale(LC_ALL, "portuguese");
		int i, N=30, junior, cleber=0, nelso=3;
		char V[N], C[N]= {"robson"};
		junior=strlen(C);

		//Início da verificação de tentativas
		while(nelso>=0) {
			printf("Insira a senha: ");
			i=0;
			cleber=0;

		//Início do teste da senha dentro da leitura
			while(i<junior) {
				V[i]=getch();
				if(V[i]==C[i]) {
					printf("*");
				}
				else {
					printf("*");
					cleber++;
				}
				i++;
				}

			printf("\n");

			if(cleber==0) {
				printf(" ==============\n");
				printf(" ===  NICE  ===\n");
				printf(" ==============\n");
					return 1;
			}
			else {
				if(nelso>1) {
					printf("Senha incorreta, tente novamente. (%d tentativas restantes)\n", nelso);
				}
				else {
					if(nelso==1) {
					printf("Senha incorreta, tente novamente. (%d tentativa restante)\n", nelso);
					}
				}
				nelso--;
			}
		}
		

		printf("\nVose atingio o numero massimo de tentativas, cai fora!\n\n");
	/*	printf("  ===============================================================================\n");
		printf("  ==  Voçê atingiu o numero máximo de tentativas. Tente novamente mais tarde.  ==\n");
		printf("  ===============================================================================\n");
	*/
		return 0;
	}
