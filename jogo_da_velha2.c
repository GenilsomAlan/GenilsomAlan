#include<stdio.h>
#include<stdlib.h>
/*
	Name: Jogo-da-velha
	Author: G. Allan
	Date: 24/10/21 23:48
	Description: version simple tic-tac-toe
*/
char structureDate[3][3]= {1,2,1,1,2,2,2,1,1};
char symbol[2] = {'X','O'};

void showLogoGame(){
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
	printf("\n\t     |||   |||            ||    ||||||  ||||||  ||  ||   ||  || 2.0\n\n\t\t");
	system("pause");
}
printStructureDate(){
	int line;
	system("cls");
		printf("\n\n\n");
		printf("\n\t    0   1   2 \n");
	for(line = 0; line < 3; line++){
		printf("\t  %d %c | %c | %c ", line, structureDate[line][0], structureDate[line][1], structureDate[line][2]);
				if(line != 2){
			printf("\n\t   ---|---|--- ");
		}
		printf("\n");
	}
}
int main(){
	int x = 0, winner = -1;
	showLogoGame();
		do{
			printStructureDate();
			(x % 2 == 0) ?  jogada(0) /*player one */: jogada(1);/*player two*/
			winner = verificationWinner();
			x++;
		}while(winner < 0);
		printStructureDate();
		( winner != 0)? printf("\n\tPlayer %d venceu!\n",winner): printf("\n\tImpate!\n");
		system("pause");
}
jogada(player){
	int positionX, positionY;
	printf("\tplayer %d:\n",player + 1);
	printf("\tDigite a linha: ");//input of positon X
	scanf("%d",&positionX);
	printf("\tDigite a coluna: ");//input of positon Y
	scanf("%d",&positionY);
	
	if(VerificationOfPositionValide(positionX, positionY) == 1){//verifi if position is valide
			printf("Posicao invalida!");
			system("pause");
	}else if(VerificationOfPositionEmpty(positionX, positionY)  == 1){//verifi if position busy
		printf("Posicao ocupada!");
		system("pause");
	}else{
		structureDate[positionX][positionY] = symbol[player];
	}
}
VerificationOfPositionValide(int X, int Y){
	if(X > 2 || X < 0 && Y > 2 || Y < 0) return 1;
	else return 0;
}
VerificationOfPositionEmpty(int X, int Y){
	if(structureDate[X][Y] == 'X' ||
		structureDate[X][Y] == 'O'){
		return 1;
	}else return 0;
}
verificationWinner(){
	int i, j;
	for(i = 0; i < 3; i++){
		if(structureDate[i][0] == structureDate[i][1] &&//line check
			structureDate[i][1] == structureDate[i][2]){
				if(structureDate[i][0] == 'X'){
					return 1;
				}else{
					return 2;
				}
		}
	}
	for(i = 0; i < 3; i++){
		if(structureDate[0][i] == structureDate[1][i] &&//column check
			structureDate[1][i] == structureDate[2][i]){
				if(structureDate[0][i] == 'X'){
					return 1;
				}else{
					return 2;
				}
		}
	}
		if(structureDate[0][0] == structureDate[1][1] &&//checking the main diagonal
		 	structureDate[1][1] == structureDate[2][2]){
				if(structureDate[i][0] == 'X'){
					return 1;
				}else{
					return 2;
				}
		}
		if(structureDate[0][2] == structureDate[1][1] &&//diagonal secondary check
		 	structureDate[1][1] == structureDate[2][0]){
					if(structureDate[i][0] == 'X'){
					return 1;
				}else{
					return 2;
				}
		}
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(structureDate[i][j] == 1 ||//check empty espaces
						structureDate[i][j] == 2){
					return -1;
				}
			}
		}
	return 0;
}
