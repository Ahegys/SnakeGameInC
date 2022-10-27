#include "includes.h"

int main(){
	// MAIN VARIBLES
	int	quit;
	int head;
	int tail;
	int	x[1000];
	int	y[1000];
	int	game_over;
	int xdir;
	int ydir;
	int	new_head;
	int	ch;
	game_over = 0;
	xdir = 1;
	ydir = 0;
	head = 0;
	tail = 0;
	quit = 0;
		
	printf("\e[?25l");
	while (!quit){
	// RENDERIZA MINHA TABLE UMA FAKE SCREEN EM TERMINAL
	
		//CANTOS TOP SIDE
		printf("╔");
		for (int i = 0; i < COLS; i++)
			printf("═");
		printf("╗\n");

		//PAREDES
		for (int j = 0; j < ROWS; j++){
			printf("║");
			for (int i = 0; i < COLS; i++)
				printf(".");
			printf("║\n");
		}

		//CANTOS BOT SIDE
		printf("╚");
		for (int i = 0; i < COLS; i++)
			printf("═");
		printf("\n");
	
	// MOVE DE VOLTA O CURSOR PARA PRIMEIRA LINHA
	printf("\e[%iA", ROWS + 2);
	
	x[head] = COLS / 2;
	y[head] = ROWS / 2;
	
	while (!quit && !game_over){
		// LIMPA O RASTRO DO TERMINAL
		printf("\e[%iB\e[%iC▓", y[tail] + 1, x[tail] + 1);
		printf("\e[%iF", y[tail] + 1);

		tail = (tail + 1) % 1000;
		new_head = (head + 1) % 1000;
		x[new_head] = (x[head] + xdir + COLS) % COLS;
		y[new_head] = (y[head] + ydir + ROWS) % ROWS;
		head = new_head;
		//DRAW HEAD

		printf("\e[%iB\e[%iC▓", y[head] + 1, x[head] + 1);
		printf("\e[%iF", y[head] + 1);

		usleep(5 * 1000000 / 60);

		ch = getchar();
		}
	}
	// VOLTA O CURSOR PARA TELA
	printf("\e[?25h");
	return (0);
}
