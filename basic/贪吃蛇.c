#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "acllib.h"
#include <stdlib.h>
#include <time.h> //�õ����������
#include <dos.h>
#define CX coord.X=x
#define CY coord.Y=y
#define SCP SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord)
int i,k=0,j;
int speed=0,choice=0;
ACL_Image img; //����һ��ָ��img��ָ��
typedef struct FOOD {
	int x; //ʳ��ĺ�����;
	int y; //ʳ���������;
	int yes; //�ж��Ƿ�Ҫ����ʳ��;
} food; //����ʳ��Ľṹ��

typedef struct SNAKE {
	int x[200];
	int y[200];
	int jieshu; //�ߵĽ���;
	int direction; //�ߵ��ƶ�����
	int life; //�ߵĴ� 0Ϊ���棬1Ϊ����
} snake; //�����ߵĽṹ��

typedef struct SNAKE2 {
	int x[200];
	int y[200];
	int jieshu; //�ߵĽ���;
	int direction; //�ߵ��ƶ�����
	int life; //�ߵĴ� 0Ϊ���棬1Ϊ����
} snake2; //�����ߵĽṹ��
food Food;
snake Snake;
snake2 Snake2;

void PLAY(food* p, snake* q, snake2* a) //��Ϸ���̵ĺ���
{
	srand(time(NULL));
	if (Food.yes!=0) { //��һ�γ���ʳ��
		Food.x=rand()%780+10; //����ʳ������x����
		Food.y=rand()%580+10; //����ʳ������y����
		while(Food.x%10!=0) {
			Food.x++; //�ж�ʳ���x�����Ƿ�Ϊ���������Ǿ͵���
		}
		while(Food.y%10!=0) {
			Food.y++; //�ж�ʳ���y�����Ƿ�Ϊ���������Ǿ͵���
		}
		Food.yes=0; //�������ϵ�����󣬲���ʳ��
	}
	for (i=Snake.jieshu-1;i>0;i--) { //�ؼ�!!
		Snake.x[i]=Snake.x[i-1]; //����ǰ�ƶ��ˣ�����ǰһ�����������һ������
		Snake.y[i]=Snake.y[i-1];
	}
	for (i=Snake2.jieshu-1;i>0;i--) { //�ؼ�!!
		Snake2.x[i]=Snake2.x[i-1]; //����ǰ�ƶ��ˣ�����ǰһ�����������һ������
		Snake2.y[i]=Snake2.y[i-1];
	}
	switch (Snake.direction) { //�ж���ͷ���ƶ�����1234��ʾ��������
		case 1:Snake.x[0]+=10;break; //�����ƶ�ʮ��
		case 2:Snake.x[0]-=10;break;
		case 3:Snake.y[0]-=10;break;
		case 4:Snake.y[0]+=10;break;
	}
	switch (Snake2.direction) { //�ж���ͷ���ƶ�����1234��ʾ��������
		case 1:Snake2.x[0]+=10;break; //�����ƶ�ʮ��
		case 2:Snake2.x[0]-=10;break;
		case 3:Snake2.y[0]-=10;break;
		case 4:Snake2.y[0]+=10;break;
	}
	//�������ж����Ƿ����ҧ���Լ��������������ĵ�5�ڿ�ʼ�жϣ���Ϊǰ4�ڳ��ȶ�ҧ�����Լ�
	for (i=3;i<Snake.jieshu;i++) {
		if (Snake.x[i]==Snake.x[0]&&Snake.y[i]==Snake.y[0]) {
		Snake.life=1; //�������ı�־
		jieshu();
		cancelTimer(0);	//��goto������ѭ������Ϸ��������
	}
}
	for (i=3;i<Snake2.jieshu;i++) {
		if (Snake2.x[i]==Snake2.x[0]&&Snake2.y[i]==Snake2.y[0]) {
		Snake2.life=1; //�������ı�־
		jieshu();
		cancelTimer(0);	//��goto������ѭ������Ϸ��������
	}

	//���ж����Ƿ����ײǽ�����
	if (Snake.x[0]<0||Snake.x[0]>1000||Snake.y[0]<0||Snake.y[0]>800) {
		Snake.life=1;
		jieshu();
		cancelTimer(0);
	}
	if (Snake2.x[0]<0||Snake2.x[0]>1000||Snake2.y[0]<0||Snake2.y[0]>800) {
		Snake2.life=1;
		jieshu();
		cancelTimer(0);
	}

	if (Snake.x[0]==Food.x&&Snake.y[0]==Food.y) {
		setPenColor(0);
		rectangle(Food.x,Food.y,Food.x+10,Food.y+10);
		Food.yes=1; //�����µ�ʳ��
		k+=10;
		Snake.jieshu++; //�ߵ�����ӳ�һ��
	}
	if (Snake2.x[0]==Food.x&&Snake2.y[0]==Food.y) {
		setPenColor(0);
		rectangle(Food.x,Food.y,Food.x+10,Food.y+10);
		Food.yes=1; //�����µ�ʳ��
		Snake2.jieshu++; //�ߵ�����ӳ�һ��
	}
}

void paint(food* p, snake* q, snake2* a)
{
    beginPaint();

    setBrushColor(GREEN);
    setBrushColor(GREEN);
    rectangle(Food.x,Food.y,Food.x+10,Food.y+10); //��ʳ��
    setBrushColor(RED);
    setPenColor(RED);
    for (i=0;i<Snake.jieshu;i++) {
    	rectangle(Snake.x[i],Snake.y[i],Snake.x[i]+10,Snake.y[i]+10);
	} //����
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(Snake.x[Snake.jieshu-1], Snake.y[Snake.jieshu-1], Snake.x[Snake.jieshu-1]+10, Snake.y[Snake.jieshu-1]+10);

	setBrushColor(BLUE);
	setPenColor(BLUE);
    for (i=0;i<Snake2.jieshu;i++) {
    	rectangle(Snake2.x[i],Snake2.y[i],Snake2.x[i]+10,Snake2.y[i]+10);
	} //����
	setPenColor(WHITE);
	setBrushColor(WHITE);
	rectangle(Snake2.x[Snake2.jieshu-1], Snake2.y[Snake2.jieshu-1], Snake2.x[Snake2.jieshu-1]+10, Snake2.y[Snake2.jieshu-1]+10);
	endPaint();
}

void keyListener(int key, int event, snake* q, snake2* a)
{
    if(key==104&&Snake.direction!=4) {  //���� ��
    	Snake.direction=3;
	}
    if(key==101&&Snake.direction!=3) {  //���� ��
    	Snake.direction=4;
	}
	if(key==100&&Snake.direction!=1) {  //���� ��
		Snake.direction=2;
	}
	if(key==102&&Snake.direction!=2) {  //���� ��
		Snake.direction=1;
	}
	 if(key==87&&Snake.direction!=4) {  //���� ��
    	Snake2.direction=3;
	}
    if(key==83&&Snake.direction!=3) {  //���� ��
    	Snake2.direction=4;
	}
	if(key==65&&Snake.direction!=1) {  //���� ��
		Snake2.direction=2;
	}
	if(key==68&&Snake.direction!=2) {  //���� ��
		Snake2.direction=1;
	}
}

void timerListener(int id) //Timer��ʱ��
{

	//StartView();
	PLAY(&Food, &Snake, &Snake2);
	paint(&Food, &Snake, &Snake2);
}

void StartView()
{
	loadImage("qianxun.jpg",&img);
	beginPaint();
	putImageScale(&img,DEFAULT,DEFAULT,1000,800);
	endPaint();
}

int jiemian(int a)
{
	system("color 7C");
	COORD coord;
    int x,y;
	y=3;
    for (x=35; x<65; x+=2) {
    	CX;CY;SCP;
    	printf("*");
	}
	y=19;
    for (x=35; x<65; x+=2) {
    	CX;CY;SCP;
    	printf("*");
	}
	x=35;
    for (y=3; y<20; y++) {
    	CX;CY;SCP;
    	printf("*");
	}
	x=65;
    for (y=3; y<20; y++) {
    	CX;CY;SCP;
    	printf("*");
	}
    x=41;
	y=5;
	CX;CY;SCP;
	printf("��̰���ߴ���ս1.0��");
	x=45;
	y=7;
    CX;CY;SCP;
    printf("��ʼ��Ϸ");
    x=45;
	y=9;
    CX;CY;SCP;
	printf("1����ͨ��");
	x=45;
	y=11;
    CX;CY;SCP;
	printf("2����ʿ��");
	x=45;
	y=13;
    CX;CY;SCP;
	printf("3�����߼�");
	x=45;
	y=15;
    CX;CY;SCP;
	printf("4��������");
	x=45;
	y=17;
    CX;CY;SCP;
	printf("�����룺");
    scanf("%d", &choice);

    return choice;
}

void jieshu(snake* q, snake2* a)
{
	beginPaint();
	setTextColor(BLACK);
	setTextBkColor(EMPTY);
	setTextSize(40);
	if (Snake.jieshu>Snake2.jieshu) {
		paintText(200,250,"��ɫ��ʤ����");
	} else if (Snake.jieshu<Snake2.jieshu) {
		paintText(200,250,"��ɫ��ʤ����");
	} else if (Snake.jieshu==Snake2.jieshu) {
		paintText(200,250,"ƽ�֣�");
	}
	paintText(200,300,"��Ϸ����");
	endPaint();
}

int Setup()
{
	initWindow("̰����˫�˶�ս��1.0", DEFAULT,DEFAULT,1000,800); //����Ϸ����
	initConsole();
	jiemian(choice);
	Food.yes=1; //��ʼ��һ��ʼû��ʳ��
	Snake.jieshu=20; //һ��ʼ�ߵĽ���
	Snake.direction=1; //һ��ʼ�ߵķ���������
	Snake2.jieshu=20; //һ��ʼ�ߵĽ���
	Snake2.direction=4; //һ��ʼ�ߵķ���������
	registerKeyboardEvent(keyListener);
	registerTimerEvent(timerListener);

	if (choice==1) {
		speed=200;
	}
	if (choice==2) {
		speed=150;
	}
	if (choice==3) {
		speed=100;
	}
	if (choice==4) {
		speed=30;
	}

	startTimer(0,speed);
}

