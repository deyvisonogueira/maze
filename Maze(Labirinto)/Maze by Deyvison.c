//Labirinto do Rato | Deyvison Nogueira RA: 20211940042
#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#include <locale.h>
#define MAX 15


void cria(char l[MAX][MAX]){
     int i,j,x,y;
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             l[i][j]='|';
             else
              l[i][j]='.';
          }
     for(i=0;i<MAX;i++){
           l[0][i]='*';
           l[MAX-1][i]='*';
           l[i][0]='*';
           l[i][MAX-1]='*';
           }// fim for
        x=  rand() % MAX;
        y=  rand() % MAX;
        l[x][y]='Q';
     }// fim funcao cria
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int col){
    int i,j;
     for ( i = 0; i < linha; i++)
    {
     printf("\n");
          for ( j = 0; j < col; j++)
			printf (" %c ",mat[i][j] );
     	}

     } // fim funcao
     
 int funcaoSuperMouse(char lab[MAX][MAX],int i, int j){
     tpilha p1;
     inicializa (&p1);
     tdado pos;
     do{
        lab[i][j] = 'M'; 
        if(lab[i][j+1]=='.' || lab[i][j+1]=='Q') {
            pos.i = i;
			pos.j = j;
			push(&p1, pos);
            j++; 
        } 
		else if (lab[i+1][j]=='.' || lab[i+1][j]=='Q'){
            pos.i = i;
			pos.j = j;
			push(&p1, pos);
			i++;
		}
		else if (lab[i][j-1]=='.' || lab[i][j-1]=='Q'){
            pos.i = i;
			pos.j = j;
			push(&p1, pos);
			j--;
		}
		else if (lab[i-1][j]=='.' || lab[i-1][j]=='Q'){
			push(&p1, pos);
            pos.i = i;
			pos.j = j;
			i--;
		}
		else 
		if(!isEmpty(p1)){
			lab[i][j] = 'x';
			pos = pop(&p1);
			i = pos.i;
			j = pos.j;
			}
		else 
			printf("Impossivel encontrar o queijo, que fomeee! :'( )");
        Sleep(180);
        system("cls");
        mostraLabirinto(lab, MAX,MAX); 
     } while(lab[i][j]!='Q');
     printf("Yummy, queijo encontrado na Linha: %d e Coluna: %d",i,j);
 }// fim funcao


int main(){
    char labirinto[MAX][MAX];
    int x,y;
    cria(labirinto);
    mostraLabirinto(labirinto,MAX,MAX);
    printf("\nEntre com a posicao inicial:");
    scanf("%d %d",&x,&y);
    funcaoSuperMouse(labirinto,x,y);
    getch();
    }
