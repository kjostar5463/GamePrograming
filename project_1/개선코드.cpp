#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
double *intro_game(char team_name[][7]);
void gotoxy(int x, int y);
void display_line(int rand);
void display_start(char t_name[][7], int s_w[], int s_l[]);
void make_decision(int r_s, int s_w[], int s_l[], char t_name[][7]);
void game_control(int *r_s, clock_t st, double *ps, double time, int mode, int level);
int mode_select(int *x, int sl);
void countDown();

int main(void)
{
	int score_win[2]={0}, score_loose[2]={0}, r_start, game_mode;
	char team_name[2][7]={"", "CPU"};
	double pst, game_time, game_level;
	double *time_mode;
	clock_t start;
	
	time_mode=intro_game(team_name);
	game_time=time_mode[0];
	game_mode=(int)time_mode[1];
	game_level=(int)time_mode[2];
	do
	{
		display_start(team_name, score_win, score_loose);
		r_start=20;
		start=clock();
		pst=game_time;
		do
		{
			rewind(stdin);
			game_control(&r_start, start, &pst, game_time, game_mode, game_level);
		}while(pst>=0 && ((8<r_start) && (r_start<32)));
		make_decision(r_start, score_win, score_loose, team_name);
		if((score_win[0]<2) && (score_win[1]<2)){
			countDown();
		}
		else{
			display_start(team_name, score_win, score_loose);
		}
	}while((score_win[0]<2) && (score_win[1]<2));
	gotoxy(1, 14);
	printf("������ �����մϴ�. \n");
	return 0;
}
double *intro_game(char team_name[][7])
{
	int x=25;
	char s_p[]="�̱� �÷���", t_p[]="2�� �÷���";
	double time_mode[3];
	int i, mode_check;
	printf("�ٴٸ��� ���� \n\n");
	printf("3�� �ο��� 2�� ���� �̱� ���� �����Դϴ�.\n\n");
	printf("�÷����� ��带 �����Ͻÿ�.\n\n");
	printf("��� �Ͻ÷��� �ƹ�Ű�� �����ּ���.");
	getch();
	system("cls");
	do
	{
		gotoxy(1, 1);
		printf("���� �� ENTERŰ�� ��������.");
		gotoxy(25, 10);
		printf("%s", &s_p);
		gotoxy(35+strlen(s_p), 10); 
		printf("%s", &t_p);
		if(x==25){
			gotoxy(x+strlen(s_p)/2, 12);
			printf("��");
		}
		mode_check = mode_select(&x, strlen(s_p));
	}while(mode_check!=25&&mode_check!=45);
	system("cls");
	if(mode_check==25){
		time_mode[1]=mode_check;
		printf("���� ���� Ű�� z�Դϴ�.\n"); 
		for(i=0;i<1;i++)
		{
			gotoxy(1,2);
			printf("                                                ");
			gotoxy(1,2);
			printf("�÷��̾��� �̸��� �Է��ϰ� Enter>");
			scanf("%s", &team_name[i]);
			if(!strcmp(team_name[i], "CPU")){
				gotoxy(1,3);
				printf("����� �� ���� �̸��Դϴ�.\n");
				Sleep(700);
				gotoxy(1,3);
				printf("                                                    ");
				i--;
			}
		}
		printf("\n");
		gotoxy(1, 2);
		printf("                                           ");
		gotoxy(1, 2);
		printf("���̵��� �������ּ���. \n");
		printf("1.���� 2.����  3.�����");
		for(i=0;i<1;i++)
		{
			gotoxy(1,4);
			printf("                                                ");
			gotoxy(1,4);
			printf("������ ���̵��� �Է��ϰ� Enter>");
			scanf("%lf", &time_mode[2]);
			if(time_mode[2]!=1&&time_mode[2]!=2&&time_mode[2]!=3){
				gotoxy(1,5);
				printf("�߸��� �Է��Դϴ�.\n");
				Sleep(700);
				gotoxy(1,5);
				printf("                                    ");
				i--;
			}
		}
		printf("\n");
		printf("�ٴٸ��� ������ ���� �ð�(�� ����)�� �Է��ϰ� Enter>");
		scanf("%lf", &time_mode[0]);

		system("cls");

		gotoxy(1,1);
		printf("���ѽð� : %5.1f ��", time_mode[0]);
		gotoxy(30, 1);
		printf("�����ð� : %4.1f��", time_mode[0]);
		
		gotoxy(38, 6);
		printf("������");
		gotoxy(40, 7);
		printf("��");
		gotoxy(40, 9);
		printf("��");
		return time_mode;
	}
	else if(mode_check==45){
		time_mode[1]=mode_check;
		printf("�����ڴ� �� ���Դϴ�. \n");
		printf("1p��z, 2p / Ű�� ���� ���ϴ�.\n");
		for(i=0;i<2;i++)
		{
			gotoxy(1,2);
			printf("                                                    ");
			gotoxy(1,3);
			printf("                                                    ");
			gotoxy(1,2);
			printf("%d�� �÷��̾��� �̸��� �Է��ϰ� Enter>", i+1);
			scanf("%s", &team_name[i]);
			if(!strcmp(team_name[i], "CPU")){
				gotoxy(1,3);
				printf("����� �� ���� �̸��Դϴ�.\n");
				Sleep(700);
				gotoxy(1,3);
				printf("                                                    ");
				i--;
			}
		}
		printf("\n");
		printf("�ٴٸ��� ������ ���� �ð�(�� ����)�� �Է��ϰ� Enter>");
		scanf("%lf", &time_mode[0]);

		system("cls");

		gotoxy(1,1);
		printf("���ѽð� : %5.1f ��", time_mode[0]);
		gotoxy(30, 1);
		printf("����ð� : %4.1f��",0);
		
		gotoxy(38, 6);
		printf("������");
		gotoxy(40, 7);
		printf("��");
		gotoxy(40, 9);
		printf("��");
		return time_mode;
	}
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_line(int rnd)
{
	int i, line[21]={0};
	line[10]=1;
	line[4]=2;
	line[16]=2;
	gotoxy(1, 8);
	for(i=0;i<78;i++)
		printf(" ");

	gotoxy(rnd, 8);
	
	for(i=0;i<21;i++)
		if (line[i]==0)
			printf("��");
		else if (line[i]==1)
			printf("��");
		else
			printf("��");

}

void display_start(char t_name[][7], int s_w[], int s_l[])
{
	int i, r_start=20;
	display_line(20);

	for(i=0;i<2;i++)
	{
		gotoxy(i*55+10, 6);
		printf("%s", t_name[i]);
		gotoxy(i*55+10, 7);
		printf("%d��, %d��", s_w[i], s_l[i]);
	}
	if(s_w[1]<2&&s_w[0]<2){
		gotoxy(1,13);
		printf("�ƹ�Ű�� ������ ��⸦ �����մϴ�. ");
		getch();
		gotoxy(1, 12);
		printf("                                   ");
		gotoxy(1,13);
		printf("                                   ");
	}
	else{
		for(i=0; i<2; i++){
			if(s_w[i]==2){
				gotoxy(30, 13);
				if(!strcmp(t_name[1], "CPU")){
					if(s_w[1]==2){
					printf("�ƽ��׿�. �������� ������!");
					Sleep(1500);
				}
					else if(s_w[0]==2){
						printf("�����մϴ�. ����ϼ̽��ϴ�.");
						Sleep(1500);
					}
				}
				else{
					printf("�����մϴ�. ������� %s �Դϴ�.", t_name[i]);
					Sleep(1500);
				}
			}	
		}
	}
}
void make_decision(int r_s, int s_w[], int s_l[], char t_name[][7])
{
	int win;
	if (20<r_s)
	{
		win=2;
		s_w[1]+=1;
		s_l[0]+=1;
	}
	else if (r_s<20)
	{
		win=1;
		s_w[0]+=1;
		s_l[1]+=1;
	}
	else
		win=0;
	gotoxy(1, 12);
	if (win)
		printf("%s���� �̰���ϴ�. ", t_name[win-1]);
	else
		printf("�����ϴ�.");
}
void game_control(int *r_s, clock_t st, double *ps, double time, int mode, int level)
{
	int rnd, i=*r_s, key=0;
	clock_t end;
	int delay;
	if(level==1)
		delay=100;
	else if(level==2)
		delay=70;
	else if(level==3)
		delay=40;
	
	if(mode==25){
		i++;
		display_line(i);
		Sleep(delay);
		if(kbhit()&&level==1){
			key=getch();
			if(key==122){
				i-=1.5;
				display_line(i);
			}
		}
		else if(kbhit()&&level==2){
			key=getch();
			if(key==122){
				i-=1.3;
				display_line(i);
			}
		}
		else if(kbhit()&&level==3){
			key=getch();
			if(key==122){
				i-=1.1;
				display_line(i);
			}
		}
	}
	else if (mode==45){
		if(kbhit()){
			key=getch();
			switch(key){
				case 122 :
					i-=1;
					display_line(i);
					break;
				case 47 :
					i+=1;
					display_line(i);
					break;
				default:
					return;
			}
		}	
	}
	*r_s=i;

	end=clock();
	*ps=time-(double)(end-st)/CLK_TCK;
	gotoxy(30, 1);
	printf("�����ð� : %4.1f��",*ps);
}

int mode_select(int *x, int sl) {
	int key;
	key=getch();
	switch(key) {
		case 75: //����(��) ������ ȭ��ǥ Ű �Է�	
			if (*x+sl/2>30){
				system("cls");
				*x=*x-20;
				gotoxy(*x+sl/2, 12);
				printf("��");
			}
			break;
		case 77: //������(��) ������ ȭ��ǥ Ű �Է�
			if (*x+sl<50){
				system("cls");
				*x=*x+20;
				gotoxy(*x+sl/2, 12);
				printf("��");
			}
			break;
		case 13:
			return *x;
			break;
		default:
			return 0;
	}
}

void countDown(){
	int i;
	gotoxy(1,13);
	Sleep(500);
	printf("3�ʵ� �ٽ� ���۵˴ϴ�.");
	for(i=3;i>0;i--){
		gotoxy(30,13);
		printf("%d", i);
		Sleep(1000); 
	}
}
