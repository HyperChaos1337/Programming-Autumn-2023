#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define width 640
#define height 480

void axis(int zoom){

	char values[3];
	int counter = 1;
	int i;
	line(0, height / 2, width, height / 2);
	line(0, 0, 0, height);


	for (i = zoom; i < width;){
		putpixel(i, height / 2 + 1, 15);
		putpixel(i, height / 2 - 1, 15);
		sprintf(values, "%d", counter);
		outtextxy(i, height / 2 + 4, values);
		i += zoom;
		counter++;
	}

	counter = -1;
	for (i = height/2 + zoom; i < height;){
		putpixel(1, i, 15);
		sprintf(values, "%d", counter);
		outtextxy(3, i + 2, values);
		i += zoom;
		counter--;
	}

	counter = 0;
	for (i = height/2; i >= 0;){
		putpixel(1, i, 15);
		sprintf(values, "%d", counter);
		outtextxy(3, i + 2, values);
		i -= zoom;
		counter++;
	}
}

void graph(int zoom){

	float tmp = zoom;
	float frequency = 1.0 / tmp;

	float start = 3 * 3.14 / 2;
	float end = 9 * 3.14;

	float f = 0;
	float max = 0;
	float min = 0;
	char points[40];

	float x;

	axis(zoom);
	for (x = start * zoom; x < end * zoom; x++){

		f = pow(cos(x/2 * frequency), 3) + sqrt(x * frequency);
		min = pow(cos(start/2 * frequency), 3) + sqrt(start * frequency);
		putpixel(x, (height / 2) - (f * zoom), 10);
		if (f > max) max = f;
		if (f < min) min = f;

	}

	setcolor(15);
	line(start * zoom, height / 2 - (max * zoom) - 10, start * zoom, height / 2 - (min * zoom));
	line(end * zoom, height / 2 - (max * zoom), end * zoom, height / 2 - (min * zoom) + 10);

	setcolor(12);
	line(2, height / 2 - (max * zoom) - 1, width, height / 2 - (max * zoom) - 1);
	line(2, height / 2 - (min * zoom) + 1, width, height / 2 - (min * zoom) + 1);

	setcolor(15);
	outtextxy(start * zoom + 3, height / 2 - (max * zoom) - 10, "3Pi/2");
	outtextxy(end * zoom + 3, height / 2 - (min * zoom) + 4, "9Pi");

	sprintf(points, "sup f(x) = %lf", max);
	outtextxy(width / 2 - 30, height / 2 - (max * zoom) - 10, points);
	sprintf(points, "inf f(x) = %lf", min);
	outtextxy(width / 2 - 30, height / 2 - (min * zoom) + 4, points);

}

void init(){

	int driver = DETECT;
	int mode = 0;
	int zoom = 20;
	clrscr();
	initgraph(&driver, &mode, "C://turboc3//bgi");
	graph(zoom);
	getch();
	closegraph();

}

void main(){
	init();
}
