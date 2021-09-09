#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct trump
{
	int order;
	char shape[3];
	int number;
};

void make_card(struct trump mkCard[]);
void display_card(struct trump mkCard[]);
void ramdom_display_card(struct trump mkCard[]);

int main(void) 
{
	struct trump card[52];
	make_card(card);
	//display_card(card);
	ramdom_display_card(card);
	return 0;
}



void make_card(struct trump mkCard[]){
	int i, j;
	char shape[4][3] = {"♠", "◆", "♥", "♣"};
	for(i=0; i<4; i++)
	{
		for(j=i*13; j<i*13+13; j++)
		{
			mkCard[j].order=i;
			strcpy(mkCard[j].shape, shape[i]);
			mkCard[j].number=j%13+1;
			switch(mkCard[j].number)
			{
				case 1:
					mkCard[j].number = 'A';
					break;
				case 11:
					mkCard[j].number = 'J';
					break;
				case 12:
					mkCard[j].number = 'Q';
					break;
				case 13:
					mkCard[j].number = 'K';
					break;
			}
		}
	}
}

void display_card(struct trump mkCard[])
{
	int i, count=0;
	for(i=0; i<52; i++)
	{
		printf("%s", mkCard[i].shape);
		if(10<mkCard[i].number)
			printf("%-2c ", mkCard[i].number);
		else
			printf("%-2d ", mkCard[i].number);
		count++;
		if(i%13+1==13)
		{
			printf("\n");
			count=0;
		}
	}
}

void ramdom_display_card(struct trump mkCard[])
{
	int i, j, lotto[5], count=0;
	srand(time(NULL));
	for(i=0;i<5;i++)
	{
		lotto[i]=rand()%52+1;
		for(j=0;j<i;j++)
		{
			if (lotto[i] == lotto[j])
			{	
				i--;
				break;
			}
		}
	}
	for(i=0; i<5; i++)
	{
		printf("%s", mkCard[lotto[i]].shape);
		if(10<mkCard[lotto[i]].number)
			printf("%-2c ", mkCard[lotto[i]].number);
		else
			printf("%-2d ", mkCard[lotto[i]].number);
		count++;
		if(i%13+1==13)
		{
			printf("\n");
			count=0;
		}
	}
}

