#include <conio.h>
#include <dos.h>

#define T 700
#define S 2
#define COLORS 16

const char* get_color_name(int color){
	switch(color){
		case 0: return "Black";
		case 1: return "Blue";
		case 2: return "Green";
		case 3: return "Cyan";
		case 4: return "Red";
		case 5: return "Magenta";
		case 6: return "Brown";
		case 7: return "Light grey";
		case 8: return "Dark grey";
		case 9: return "Light blue";
		case 10: return "Light green";
		case 11: return "Light cyan";
		case 12: return "Light red";
		case 13: return "Light magenta";
		case 14: return "Yellow";
		case 15: return "White";
	}
	return "";
}

void print(int t_value, int bg_value, int step){
       const char* str = "Hello world!";
       const char* t_color = get_color_name(t_value);
       const char* bg_color = get_color_name(bg_value);
       int i, j;
       gotoxy(1, 9);
       for(i = 0; i <= step; i++) delline();
       textattr(BLINK | bg_value * COLORS | t_value);
       gotoxy(1,1);
       for(j = 0; j <= step; j++) insline();
       gotoxy(1,1);
       cprintf("%s Text Color: %s, Background color: %s", str, t_color, bg_color);
}


void exec(){
	int x1 = 10, x2 = 70;
	int y1 = 8, y2 = 18;
	int i;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();

	window(x1, y1, x2, y2);
	for(i = 0; i < COLORS; i++){
		print(i, COLORS-i-1, S);
		if(kbhit()) return;
		delay(T);
	}
	getch();
}

void main(){
	exec();
}