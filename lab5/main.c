#include <stdio.h>
#include <dos.h>

#define N 50
#define T 750

volatile int kb_interrupt = 0;
volatile int esc = 0;

void interrupt(*old_interrupt_handler)(void);

void interrupt new_interrupt_handler(void){
	kb_interrupt = 1;
	if(inportb(0x60) == 0x01) esc = 1;
	(*old_interrupt_handler)();
}

void set_vect(int num, void interrupt(*handler)(void)){
	disable();
	old_interrupt_handler = getvect(num);
	setvect(num, handler);
	enable();
}

void get_vect(int num, void interrupt(*handler)(void)){
	disable();
	setvect(num, handler);
	enable();
}

void exec(){
	char sentence[N];
	int i = 0;
	clrscr();
	printf("Enter sentence: ");
	fgets(sentence, N, stdin);
	set_vect(0x09, new_interrupt_handler);
	while(1){
		if(kb_interrupt){
			kb_interrupt = 0;
			if(esc) break;
			putchar(sentence[i++]);
			if(sentence[i] == '\0') i = 0;
			delay(T);
		}
	}
	get_vect(0x09, old_interrupt_handler);
	getch();
}

void main(){
	exec();
}