#include<stdio.h>
#include<stdlib.h>

char tabela_de_jogo[3][3] = {1,2,2,2,1,1,1,2,2};
int linha, coluna, i;

int inicializaMatriz(){
	int contadorLinha, contadorColuna;
	for (contadorLinha = 0; contadorLinha < 3; contadorLinha++){
		for(contadorColuna = 0; contadorColuna < 3; contadorColuna++){
			tabela_de_jogo [contadorLinha][contadorColuna];
		}
	}
}
void title(){
	system("color 03");
	printf("\n\n\n");
	printf("\n\t     |||   |||    ");
	printf("\n\t     |||   |||         ||||||  ||||||  ||||||  ||||||");
	printf("\n\t     |||   |||           ||    ||  ||  ||      ||  ||");
	printf("\n\t |||||||||||||||||       ||    ||  ||  || |||  ||  || |||| ||||");
	printf("\n\t |||||||||||||||||       ||    ||  ||  ||  ||  ||  ||  | | |__|");
    printf("\n\t     |||   |||         ||||    ||||||  ||||||  |||||| |||| |  |");
    printf("\n\t     |||   |||    ");
	printf("\n\t |||||||||||||||||      ||  ||  ||||||  ||      ||  ||   ||||||");
	printf("\n\t |||||||||||||||||      ||  ||  ||      ||      ||  ||   ||  ||");
	printf("\n\t     |||   |||          ||  ||  ||||||  ||      ||||||   ||||||");
	printf("\n\t     |||   |||           ||||   ||      ||      ||  ||   ||  ||");
	printf("\n\t     |||   |||            ||    ||||||  ||||||  ||  ||   ||  || \n\n\t\t");
	system("pause");
}
int VerificaPosicaoVazia(int linha, int coluna){
	if(tabela_de_jogo[linha][coluna] == 'X' || tabela_de_jogo[linha][coluna] == 'O'){
		printf("posicao ja ocupada!");
		return 1;
	}else
		return 0;
}
int VerificaCoordenadaValida(int linha, int coluna){
	if(linha > 2 || linha < 0 || coluna > 2 || coluna <0){
		printf("posicao invalida!");
		return 1;
	}else
		return 0;
}
void imprimeMatriz(){
	system("cls");
		printf("\n\n\n");
		printf("\t     0   1   2 \n\n");
	for(linha = 0; linha < 3; linha++){
		printf("\t  %d  %c | %c | %c ", linha, tabela_de_jogo[linha][0], tabela_de_jogo[linha][1], tabela_de_jogo[linha][2]);
				if(linha != 2){
			printf("\n\t    ---|---|--- ");
		}
		printf("\n");
	}
}
void sorteio(){
	int srt;
	srand(time(NULL));
	srt = rand()%2;
	if(srt == 1){
		player1();
	}else if(srt == 0){
		player2();
	}
}
int verifica_linhas(){
	for(i = 0; i < 3; i++){
		if(tabela_de_jogo[i][0] == tabela_de_jogo[i][1] && tabela_de_jogo[i][1] == tabela_de_jogo[i][2]){
				return 0;
			}
	}
}
int verifica_colunas(){
	for(i = 0; i < 3; i++){
		if(tabela_de_jogo[0][i] == tabela_de_jogo[1][i] && tabela_de_jogo[1][i] == tabela_de_jogo[2][i]){
				return 0;
			}
	}
}
int verifica_diagonal_principal(){
		if(tabela_de_jogo[0][0] == tabela_de_jogo[1][1] && tabela_de_jogo[1][1] == tabela_de_jogo[2][2]){
				return 0;
		}else{
				return 1;
		}
}
int verifica_diagonal_secundaria(){
	if(tabela_de_jogo[0][2] == tabela_de_jogo[1][1] && tabela_de_jogo[1][1] == tabela_de_jogo[2][0]){
				return 0;
		}else{
				return 1;
		}
}
int vencedor(){
	if(verifica_linhas() == 0)	{
		return 0;
	}else
	if(verifica_colunas() == 0){
		return 0;
	}else
	if(verifica_diagonal_principal() == 0){
		return 0;
	}else
	if(verifica_diagonal_secundaria() == 0){
		return 0;
	}
}
player1(){
	printf("\n\tPlayer 1: ");
	printf("\n\tlinha:");
	scanf("%d",&linha);
	printf("\n\tcoluna: ");
	scanf("%d",&coluna);
		if(VerificaCoordenadaValida(linha, coluna) == 1 || VerificaPosicaoVazia(linha, coluna) == 1){
			player2();
		}else{
			tabela_de_jogo[linha][coluna] = 'X';
			imprimeMatriz();
		}	
		if (vencedor() == 0){
			printf("player 1 venceu!!!");
			system("pause");
			exit(0);
		}else{
			player2();
		}
}
player2(){
	printf("\n\tPlayer 2:");
	printf("\n\tlinha: ");
	scanf("%d",&linha);
	printf("\n\tcoluna: ");
	scanf("%d",&coluna);
		if(VerificaCoordenadaValida(linha, coluna) == 1 || VerificaPosicaoVazia(linha, coluna) == 1){
			player1();
		}else{
			tabela_de_jogo[linha][coluna] = 'O';
			imprimeMatriz();
		}
		vencedor();
		if (vencedor() == 0){
			printf("player 2 venceu!!!");
			system("pause");
			exit(0);
		}else{
			player1();
		}	
}
void main(){
	title();
	system("color 02");
		inicializaMatriz();
		imprimeMatriz();
		sorteio();
}
