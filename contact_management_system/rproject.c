#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

//function 
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//main
int main(){
	system("color 0b");
		//variable declaration
		int ch,rd,found,i,r;
		char search[15],str[10],std[12]="Sajal Gupta";
		FILE *fp,*ft;
		struct contact_book{
			char name[20];
			int num;
			char email[20];
		}list;
		if(std!=NULL)//tgdgdgdgdg
		{
		if(std[0]==83 && std[1]==97 && std[2]==106&&std[3]==97&&std[4]==108&&std[5]==32&&std[6]==71&&std[7]==117&&std[8]==112&&std[9]==116&&std[10]==97)
		{
		
		while(1)
		{
		system("cls");
		gotoxy(3,2);
		printf("created by - %s",std);
		gotoxy(15,8);
		printf("-------------------------------------------\n");		gotoxy(15,9);
		printf("			Contact Book\t\n");		gotoxy(15,10);
		printf("-------------------------------------------\n\n\n");		
		printf("\t\t	[1] Add a Contact\n");
		printf("\t\t	[2] List Of All Contact\n");
		printf("\t\t	[3] Edit a Contact\n");
		printf("\t\t	[4] Search a Contact\n");
		printf("\t\t	[5] Delete All Contact\n");
		printf("\t\t	[0] Exit\n\n");
		printf("\t\t Enter Your Choice: ");
		
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0: 
					system("cls");
					gotoxy(15,8);
					printf("Are you Sure?\n");
					gotoxy(15,11);
					printf("\t\t[1] Yes\t [2] No");
					printf("\n\n\t Enter Your Choice: ");
					scanf(" %ld",&rd);
					switch(rd){
						case 1: exit(1);
								break;
						case 2: break;
					}
					break; 
					
			case 1: system("cls");
					gotoxy(15,8);
					fp=fopen("rproject.txt","a");
					printf(" ------------------------------\n");
					printf("\t\t    Enter Following Details   \n");
					printf("\t\t------------------------------\n\n");
					printf("\t\tName : ");	//Detail taken from user
					scanf("%s",list.name);
					printf("\t\tEmail:");
					scanf("%s",list.email);
					printf("\t\tnumber : ");
					scanf("%d",&list.num);
				
					fwrite(&list,sizeof(list),1,fp);
				
					fclose(fp);
					printf("\t\t! Number saved Successfully\n");
					printf("\n\t\tPress Enter to Continue...");
					
					getch();
					break;
			case 2: system("cls");
					gotoxy(15,8);
					printf(" \t------------------------------\n");
					printf("\t\t\t    List Of All Contacts   \n");
					printf("\t\t\t------------------------------\n\n");
					fp=fopen("rproject.txt","r");
				/*	printf(" ------------------------------\n");
					printf("\t\t    Enter Following Details   \n");
					printf("\t\t------------------------------\n\n");*/
					printf("\t\tName\t\tEmail\t\t Number\n\n");
					found =0;
					while(fread(&list,sizeof(list),1,fp)==1)
					{
						found++;
					printf("\t  %10s\t %13s\t\t %10d\n",list.name,list.email,list.num);
					}
					fclose(fp);
					printf("!Results %d\n",found);
					printf("Press Enter To Continue...");
					if(std[0]==83 && std[4]==108 && std[10]==97)
					{}
					else{
						exit(1);
					}
					
					getch();
					break;
			case 3: system("cls");
					gotoxy(15,8);
					printf(" ---------------------------------\n");
					printf("\t\t\tEdit A Contacts  \n");
					printf("\t\t---------------------------------\n\n");
					found=0;
					for(i=97;i<123;i++){
						fp=fopen("rproject.txt","r");
						while(fread(&list,sizeof(list),1,fp)==1){
							
							if(list.name[0]==i||list.name[0]==i-32)
							{
								found++;
								printf("\t [%d] %10s\t %13s\t\t %10d\n",found,list.name,list.email,list.num);
								
							}
						}
						fclose(fp);
					}
					
					printf("\n\t! enter the sequencial number to be Edit: ");
					scanf("%d",&rd);
				if(rd<=found){	
				found=0;
					for(i=97;i<123;i++){
						fp=fopen("rproject.txt","r");
						
						while(fread(&list,sizeof(list),1,fp)==1){
							
							if(list.name[0]==i||list.name[0]==i-32)
							{
								ft=fopen("temp.txt","a");
								found++;
							if(found==rd){
								printf("\nname: ");scanf("%s",list.name);
								printf("email: ");scanf("%s",list.email);
								printf("\nnum: ");scanf("%d",&list.num);
								fwrite(&list,sizeof(list),1,ft);
							}
							else{
								fwrite(&list,sizeof(list),1,ft);
							}
							fclose(ft);
								
							}
						}
						fclose(fp);
					}
					remove("rproject.txt");
					int a=rename("temp.txt","rproject.txt");
				
				}
				else{
					system("cls");
							gotoxy(30,10);
							printf("! Wrong Key Enter\n");
							printf("\n\n\t\t!Press Enter to Continue..");
							getch();
							break;
				}
					break;
			
			
			case 4: system("cls");
					gotoxy(15,8);
					printf(" ---------------------------------\n");
					printf("\t\t\tSearch A Contacts  \n");
					printf("\t\t---------------------------------\n\n");
					printf("Search by Name/Number\n");
					
					scanf("%s",search);
					if(search[0]>=48 && search[0]<=57)
					ch=2;
					else
					ch=1;
					
					switch(ch)
					{
					case 1: system("cls");
							gotoxy(15,8);
							printf(" ---------------------------------\n");
							printf("\t\t\tSearch A Contacts  \n");
							printf("\t\t---------------------------------\n\n");
							printf("\ts.no\t Name\t\tEmail\t\t\tnumber\n\n");
							r=search[0];
							fp=fopen("rproject.txt","r");
							found=0;
							while(fread(&list,sizeof(list),1,fp)==1)
							{
							if(list.name[0]==r){
							if(strcmp(list.name,search)==0)
							{
								found++;
								printf("\t %d %10s\t %13s\t\t %10d\n",found,list.name,list.email,list.num);
							}
							}
							}
							fclose(fp);
							break;
					case 2: fp=fopen("rproject.txt","r");
							r=atoi(search);
							while(fread(&list,sizeof(list),1,fp)==1){
								if(r==list.num)
								printf("\t%10s\t %13s\t\t %10d\n",list.name,list.email,list.num);
							}
							fclose(fp);
							break;
					default: 
							system("cls");
							gotoxy(30,10);
							printf("! Wrong Key Enter\n");
							printf("\n\n\t\t!Press Enter to Continue..");
							getch();
							break;			
								
						
					}
					getch();
					break;
		
			case 5: system("cls");
					gotoxy(15,8);
					printf(" ---------------------------------\n");
					printf("\t\t\tDelete All Contacts  \n");
					printf("\t\t---------------------------------\n\n");
					printf("\t Are you Sure?\n\n");
					printf("\t\t[1] Yes\t [2] No\n\n");
					printf("\t\tEnter Your Choice: ");
					scanf("%d",&ch);
					switch(ch){
						case 1: 
								remove("rproject.txt");
								printf("! All Contacts Deleted Successfully\n\n");
								printf("Press Enter to continue...");
								getch();
								break;
						case 2:	printf("");
								break;
					   default: 
								system("cls");
								gotoxy(30,10);
								printf("! Wrong Key Enter\n");
								printf("\n\n\t\t!Press Enter to Continue..");
								getch();
								break;
						} 					//closing of case 5 switch
						break;				//break of case 5
					
			default: 
						system("cls");
						gotoxy(30,10);
						printf("! Wrong Key Enter\n");
						printf("\n\n\t\t!Press Enter to Continue..");
						getch();
						break;				//break of default
		}//main switch
		
	}//closing of while
	
}//closing of 2nd main if
	else{
		gotoxy(30,10);
		printf("Sorry\n\n\n\n\n\n\n");
		exit(1);
	}
}//closing of 1st main if
}//closing of main
