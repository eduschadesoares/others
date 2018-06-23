	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <locale.h>
	#include <unistd.h>
	#include <conio.h>
	#define N 30
	
	//Global variables
	char adminpass[N]; //password variable (admin)
	char adminuser[N]; //user variable (admin)
	char otruser[N]; //user variable (any)
	char otrpass[N]; //password variable (any)
	
	//Void functions 
	void login(); //First void function //Calls (menu)
	void menu(); //Calls these next functions: 
	void admuser(); //(Admin user)= Creates an admin login
	void newuser(); //(New user)= A user may create a new user  
	void newpass(); //(New password)= Also created by a user that creates a user
	void menurld(); //(Menu reload)= Reloads again with 2 diferent users
	void admpassvrf(); //(Admin password verification) Verifies the password
	void otrpassvrf(); //(Other password verification) Also virifies the password


	int main() {
		setlocale(LC_ALL, "portuguese");
		login();
		system("pause");		
		return 0;
	}

	//Calling the other void functions
	void login() {
		menu();		
	}
	
	//Loading the menu
	void menu() {
		int i=0, chs;
		admuser(); //Adding the admin user
				
		//Initializing in main menu
		while(i==0) {
		printf(" ========================================\n");
		printf(" ===        Login to continue         ===\n");
		printf(" ========================================\n");
		
		printf(" ===   User: "); //Showing the main user
		for(i=0; i<10; i++) {
			printf("%c", adminuser[i]);
		}
		printf(" | Press (1)   ===\n");	
		printf(" ========================================\n");
		printf(" ========================================\n");
		printf(" ===   User: New        | Press (2)   ===\n");
		printf(" ========================================\n");
			chs=getch();
			
			//Choosing the user
			switch(chs) {
				case '1' : 
					system("cls");
					admpassvrf();
					i++;
					break;
				case '2' :
					system("cls");
					newuser();								
					i++;
					break;
				default :
					printf(" %c is an invalid option, try again.", chs);
					printf("\n");
					i=0;
					break;
			}
		}
	}
	
	//Adding a main user
	void admuser() {
		int i, userlen, passlen;
		
		//Setting the admin password & user
		char mainpass[N]=("robson");
		char mainuser[N]=("admin"); //Max= 10 characters
		passlen=strlen(mainpass);
		userlen=strlen(mainuser);		
		for(i=0; i<passlen; i++) {
			adminpass[i]=mainpass[i];
		}
		for(i=0; i<userlen; i++) {
			adminuser[i]=mainuser[i];
		}
	}

	//Creating a new user	
	void newuser() {
		int i=0, j=0, chs, userlen;
		char newuser[N];
		system("cls");
		while(i==0) {
			i=0;
			j=0;
			printf(" Insert a new user: ");
			gets(newuser);
			userlen=strlen(newuser);
			printf(" Do you really want to create \""); //Make sure that you want to do it
			for(i=0; i<userlen; i++) {
				printf("%c", newuser[i]);
			}
			
			printf("\" user?");
			printf("\n");
			
			while(j==0) {
				printf(" ===================================\n");
				printf(" ===   If you want | Press (1)   ===\n");
				printf(" ===================================\n");
				printf(" ===================================\n");
				printf(" ===   If you dont | Press (2)   ===\n");
				printf(" ===================================\n");
				chs=getch();
				fflush(stdin);
				switch(chs) {
					case '1' :
						j++;
						i++;
						for(i=0; i<userlen; i++) {
							otruser[i]=newuser[i];
						}
						newpass();
						break;
					case '2' :
						j++;
						i=0;
						break;
					default :
						printf(" %c is an invalid option, try again.\n", chs);
						j=0;
						break;		
				}			
			}		
		}
	}
	
	//Creating a new password
	void newpass() {
		int i, chs, mark=0, loop=0, userlen, passlen, passlencfm;
		char newpass[N], newpasscfm[N];
		system("cls"); //Cleans the screen 
		userlen=strlen(otruser);
		
		while(loop==0) {
			mark=0;		
			printf(" Insert a password for \"");
			for(i=0; i<userlen; i++) {
				printf("%c", otruser[i]);
			}
			printf("\" user: ");
			gets(newpass);
			fflush(stdin);
			passlen=strlen(newpass);
			
			printf(" Please, repeat the password: "); //Confirming the password
			gets(newpasscfm);
			fflush(stdin);
			passlencfm=strlen(newpasscfm);
			
			if(passlen==passlencfm) { 
				for(i=0; i<passlen; i++) {
					if(newpass[i]!=newpasscfm[i]) {
						mark++;
					}				
				}
			}
			else {
				mark++;
			}
		
			if(mark>0) {
				printf(" Passwords don't match. Try again.\n"); //Errou
			}
			else {
				loop=1;
			}
		}
		
		for(i=0; i<passlen; i++) {
			otrpass[i]=newpass[i];
		}
		//Going to the second menu
		menurld();
	}
	
	//Reloading a new menu
	void menurld() {
		int i=0, chs, userlen, adminuserlen;
		userlen=strlen(otruser);
		adminuserlen=strlen(adminuser);
		while(i==0) {
			printf(" ========================================\n"); //Now are 3 choices
			printf(" ===        Login to continue         ===\n");
			printf(" ========================================\n");			
			printf(" ===   User: "); //Showing the main user
			for(i=0; i<10; i++) {
				printf("%c", adminuser[i]);			}
			printf(" | Press (1)   ===\n");	
			printf(" ========================================\n");			
			printf(" ===   User: "); //Showing the other user
			for(i=0; i<10; i++) {
				printf("%c", otruser[i]); //Max= 10 characters
			}
			printf(" | Press (2)   ===\n");	
					
			printf(" ========================================\n");
			printf(" ===   User: New        | Press (3)   ===\n");
			printf(" ========================================\n");
			chs=getch();
			system("cls");
			switch (chs) {
				case '1' :
					printf(" Admin user (");
					for(i=0; i<adminuserlen; i++) {
						printf("%c", adminuser[i]);
					}
					printf(") selected.\n");
					admuser(); //Found a bug here (fixed)
					admpassvrf(); //Going to the admin password verification
					i++;
					break;
				case '2' :
					printf(" User (");
					for(i=0; i<userlen; i++) {
						printf("%c", otruser[i]);
					}
					printf(") selected.\n");
					otrpassvrf(); //Going to the "other" password verification
					i++;
					break;
				case '3' :
					printf(" Do you really want to create a new user? ¬¬\n");
					newuser(); //Creates a new user again
					i++;
					break;			
				default :
					printf(" %c is an invalid option, try again.", chs);
					printf("\n");
					i=0;
					break;				
			}			
		}		
	}
	
	//Verifying the main password
	void admpassvrf() {
		int i=0, cnc=3, mark=0, aux;
		int passlen, userlen;
		char inspass[N];
		fflush(stdin);
		passlen=strlen(adminpass);
		userlen=strlen(adminuser);
		while(cnc>=0) {
			i=0;
			mark=0;
			printf(" Insert the password: ");			
			printf("\n");
			for(aux=passlen; aux>0; aux--) {
				printf("|-|");
			}
			printf("\n");
			while(i<passlen) {
				inspass[i]=getch();
				printf(" * "); //Show only "*" instead what is typed
				
				if(inspass[i]!=adminpass[i]){
					mark++; //Testing the typed password
				}				
				i++;
			}
			printf("\n");
			
			if(mark==0) {
				printf(" You are logged in as ");
				for(i=0; i<userlen; i++) {
					printf("%c", adminuser[i]);
				}
				printf("!\n");							
				break;
			}
			else {
				if(cnc>1) {
				printf(" Wrong password. Try again. (%d more tries)\n", cnc);
				}
				else {
					if(cnc==1) {
					printf(" Wrong password. Try again. (%d more try)\n", cnc);
					}
				}
				cnc--;	
			}	
		}
		
		if(cnc<0) {
			printf("\n You failed more than 3 times. Try again.\n\n");
			sleep(4); 
			system("cls");
			menu();
		}
	}
	
	//Verifying the other password
	void otrpassvrf() { 
		int i=0, cnc=3, mark=0, aux; //Same void function but different password
		int passlen, userlen;
		char inspass[N];
		passlen=strlen(otrpass);
		userlen=strlen(otruser);
		while(cnc>=0) {
			i=0;
			mark=0;
			printf(" Insert the password: ");
			printf("\n");
			for(aux=passlen; aux>0; aux--) {
				printf("|-|");
			}
			printf("\n");			
			
			while(i<passlen) {
				inspass[i]=getch();
				printf(" * ");
				
				if(inspass[i]!=otrpass[i]){ //Another password
					mark++;
				}				
				i++;
			}
			printf("\n");
			
			if(mark==0) {
				printf(" You are logged in as ");
				for(i=0; i<userlen; i++) {
					printf("%c", otruser[i]);
				}
				printf("!\n");
				break;
			}
			else {
				if(cnc>1) {
				printf(" Wrong password. Try again. (%d more tries)\n", cnc);
				}
				else {
					if(cnc==1) {
					printf(" Wrong password. Try again. (%d more try)\n", cnc);
					}
				}
				cnc--;	
			}	
		}
		
			if(cnc<0) {
				printf("\n You failed more than 3 times. Try again.\n\n");
				sleep(4);
				system("cls");		
				menurld(); //Returns to menu reload
			}	
	}
