#include <stdio.h>
#include <dos.h>

#define F5_KEY 63
#define F6_KEY 64
#define ESC 1

#define T 500

unsigned char scan_key(){
	unsigned char buffer;
	asm{
	 mov ah, 0
	 int 16h
	 mov buffer, ah
	};
	return buffer;
}

struct MovingChar{
	const char symbol;
	const int y;
	int x, dx;
};

void show(struct MovingChar* chr){
	gotoxy(chr->x, chr->y);
	cprintf("%c", chr->symbol);
}

void hide(struct MovingChar* chr){
	gotoxy(chr->x, chr->y);
	cprintf(" ");
}

void check(int *cur_coord, int min, int max){
	if(*cur_coord < min) *cur_coord += max-min;
	else if(*cur_coord > max)  *cur_coord -= max-min;
}

void set_dir(struct MovingChar *chr, int dx){
	chr->dx = dx;
}

void move(struct MovingChar* chr, int x1, int x2, int dir){
	hide(chr);
	set_dir(chr, dir);
	if(dir != 0) chr->x += chr->dx;
	check(&chr->x, x1, x2);
	show(chr);
}

void exec(){

	int x1 = 25, x2 = 55;
	int y1 = 8, y2 = 18;
	struct MovingChar chr;
	char symbol;
	int dir = 0;
	int i;
	unsigned char key;
	clrscr();
	srand(time(NULL));
	symbol = (char)(rand()%26 + 'A');
	chr.x = x2-x1;
	chr.y = y2-y1;
	chr.symbol = symbol;
	window(x1-1, x2+1, y1-1, y2+1);
	gotoxy(x1-1, y1-1);
	for(i = 1; i <= x2-x1+2; i++) cprintf("*");
	gotoxy(x1-1, y2-1);
	for(i = 1; i <= x2-x1+2; i++) cprintf("*");
	gotoxy(x1-1, y1-1);
	for(i = y1; i <= y2-1; i++){
		gotoxy(x1-1, i);
		cprintf("*");
		gotoxy(x2, i);
		cprintf("*");
	}
	window(x1, x2, y1, y2);
	gotoxy(2, 3);

	while(key != ESC){
		if(kbhit()) key = scan_key();
		move(&chr, x1, x2, dir);
		delay(T);
		if(key == F5_KEY) dir = -1;
		if(key == F6_KEY) dir = 1;
	}

}

void main(){
	exec();
}
