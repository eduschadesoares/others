	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <locale.h>
	#include <unistd.h>
	#include <conio.h>

	//Chamada de funções
	int login(int);
	int password(int);
	void newlogin();

	//Variáveis globais
	const int N=30; //Constante
	char C[N];
	char usuario[N];

	int main() {
		setlocale(LC_ALL, "portuguese");
		int a, b, c;
		if(login(a)==1) {
			if(password(b)!=1) {
				printf("O programa será encerrado.\n");
			}
			else {
				printf("\n                         _\n        _        ,-.    / )\n       ( `.     // /-._/ /\n        `\\ \\   /(_/ / / /  \n          ; `-`  (_/ / /\n          |       (_/ /\n           \\         /\n           )       /`\n          /      /`\n\n");
			}
		}
		else {
			newlogin();
			if(password(b)!=1) {
				printf("O programa será encerrado.\n");
			}
			else {
				printf("\n                         _\n        _        ,-.    / )\n       ( `.     // /-._/ /\n        `\\ \\   /(_/ / / /  \n          ; `-`  (_/ / /\n          |       (_/ /\n           \\         /\n           )       /`\n          /      /`\n\n");
			}
		}
		system("pause");
		return 0;
	}

	int login(int nelso) {
		int i, user;
		char stand[N]={"robson"};
		printf(" ===================================\n");
		printf(" ===  Faça login para continuar  ===\n");
		printf(" ===================================\n");
		printf(" === User: admin | Pressione (1) ===\n");
		printf(" ===================================\n");
		printf(" ===================================\n");
		printf(" === User: outro | Pressione (2) ===\n");
		printf(" ===================================\n");
		user=getch();
		switch (user) {
			case '1':
				for(i=0; i<6; i++)
					C[i]=stand[i];
				return 1;
			break;
			case '2':
				return 0;
			break;
		}
	}

	int password(int robson) {
		int i, junior, cleber=0, nelso=3;
		char V[N]; //C[N]= {"robson"};
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

	void newlogin() {
		int i, lenuser, lenpass, lenpass2, nelso, cleber=0;
		char usuario[N], fst[N], scd[N];
		//Usuário
		printf("Insira um novo usuário: ");
		gets(usuario);
		while (cleber==0) {
			nelso=0;
			printf("Insira uma senha para o usuário \"");
			lenuser=strlen(usuario);
			for(i=0; i<lenuser; i++) {
				printf("%c", usuario[i]);
			}
			printf("\": ");
			//Leitura da senha
			gets(fst);
			lenpass=strlen(fst);
			printf("Por favor, confirme a sua senha: ");
			gets(scd);
			lenpass2=strlen(scd);
			if(lenpass==lenpass2) {
				for(i=0; i<lenpass; i++) {
					if(fst[i]!=scd[i]) {
						nelso++;
					}
				}
			}
			else {
				nelso++;
			}

			if(nelso>0) {
				printf("As senhas não batem. Tente novamente.\n");
			}
			else {
				cleber=1;
			}
		}
		for(i=0; i<lenpass; i++) {
			C[i]=fst[i];
		}
		printf("\n");

	}
