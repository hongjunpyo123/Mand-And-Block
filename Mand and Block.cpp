#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 200
#define HEIGHT 200
#define monsterx  = 50
#define monstery = 50
#define MAX 15
//------------------------ 
int i = 0,j = 0, ix = 0, sz = 0, k = 0;
int player_x = 2;
int player_y = 26;
int shooting_x = 0,shooting_y = 0,shooting_x1 = 0,shooting_y1 = 0,shooting_x2 = 0,shooting_y2 = 0;
int space = 0;
int space1 = 3;
bool bullet = false;
bool bullet1 = false;
bool bullet2 = false;
int sz1 = 0;
int x1 = 0,y1 = 27;
int score1;
int voulb = 0;
int stage = 1;
int score = 0;
int monster = 0;
int hp = 5;
int voulb1 = 0;
int sc2 = 0;
int monster1 = 0;
int mp = 5;
int fps = 5;
int fpsx = 70;
int cha = 1;
int count = 8;
int a_x,a_y;
int monster1_x = 135,monster1_y = 12,monster2_x = 135,monster2_y = 16,monster3_x = 135,monster3_y = 20;// 3���������� ù��° ����  �� 
int tel;
int level = 0;
int power = 1;
int speed = 1;
int ultimate = 4;
int exp;
int randome;
int ex[MAX] = {0}, ey[MAX] = {0};
bool enemy[MAX] = {false};
int count1 = 0;
int quest = 10;
int randome_monster = 0;
int bosshp = 1000;
int max = 5;
int arrow = 10; 

//-----------------------------------------------
char front_buffer[HEIGHT][WIDTH];
char back_buffer[HEIGHT][WIDTH];

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void printxy(int _x, int _y, const char* _text)
{
	gotoxy(_x, _y);
	printf(_text);
}
void color(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void printXY(int i,int j,char* image)
{
	ix = 0;
	while(1)
	{
		if(image[ix] == '\0') break;
		back_buffer[j][i+ix] = image[ix];
		ix++;
	}
}
void render()
{
	for(j=0;j<HEIGHT;j++)
	{
		for(i=0;i<WIDTH;i++)
		{
			if(back_buffer[j][i] != front_buffer[j][i])
			{
				gotoxy(i,j);
				
				if(back_buffer[j][i] == '\0')
				{
					printf("%c", ' ');
				}
				else
				{
					printf("%c", back_buffer[j][i]);
				}
			}
			
		}
	}
	for(j=0;j<HEIGHT;j++)
	{
		for(i=0;i<WIDTH;i++)
		{
			front_buffer[j][i] = back_buffer[j][i];	
			back_buffer[j][i] = '\0';
		}
	}
	
}
void intro()
{
	system("color 0e");
	system("mode con:cols=80 lines=40");
	system("title ��                                            ��MAN and BLOCK��  -  Surak Festival                     ");
	for(i=0;i<29;i++)
	{
	printxy(5+i,4+i,"*");printxy(5+i,5+i,"*");printxy(5+i,6+i,"*");printxy(5+i,7+i,"*");printxy(5+i,8+i,"*");
	Sleep(20);
	if(i==28)
	{
		for(i=0;i<28;i++)
		{
			printxy(34+i,35-i,"*");printxy(34+i,34-i,"*");printxy(34+i,33-i,"*");printxy(34+i,32-i,"*");printxy(34+i,31-i,"*");printxy(34+i,30-i,"*");
			Sleep(20);
		}
	}
}
for(i=0;i<27;i++)
		{
			if(i<14 || i>19)
			{
				printxy(19+i,13,"*");
		}
		color(15, 0);
		printxy(19+i,15,"*");printxy(19+i,14,"*");printxy(19+i,12,"*");printxy(19+i,11,"*");
		color(14, 0);
			Sleep(20);
			if(i==14)
			{
				color(15, 0);
				printxy(15+i,13,"[B][I][T]");
				color(14, 0);
				
			}
		}
		for(i=0;i<10;i++)
		{
			color(13, 0);
			printxy(60,30,"|*Surak Festival*|");
			color(14, 0);
			
		}
		Sleep(1500);
}
void bu1()
{
	space ++;
					if(space == 1)
					{
					if(bullet == false)
					{
					shooting_x = player_x + 2;
					shooting_y = player_y;
					bullet = true;
			    	}
				    }
				    if(space == 2)
					{
					if(bullet1 == false)
					{
					shooting_x1 = player_x + 2;
					shooting_y1 = player_y;
					bullet1 = true;
			    	}
				    }
				    if(space == 3)
					{
					if(bullet2 == false)
					{
					shooting_x2 = player_x + 2;
					shooting_y2 = player_y;
					bullet2 = true;
			    	}
			    	space = 0;
				    }
}
void bu2()
{
if(bullet == true)
		{
			
			printXY(shooting_x,shooting_y,"��");
			space1 = 2;
			shooting_x ++;
			if(shooting_x > 136)
			{
				bullet = false;
			}
		}
		if(bullet1 == true)
		{
			printXY(shooting_x1,shooting_y1,"��");
			space1 = 1;
			shooting_x1 ++;
			shooting_x1 ++;
			if(shooting_x1 > 135)
			{
				bullet1 = false;
			}
		}
		if(bullet2 == true)
		{
			printXY(shooting_x2,shooting_y2,"�ߡ�");
			space1 = 0;
			shooting_x2 ++;
			shooting_x2 ++;
			if(shooting_x2 > 130)
			{
				space1 = 3; 
				bullet2 = false;
			}
		}	
}
void EXP()
{
		if(exp == 5)
		{
			color(9, 11);
		printxy(56, 2, "EXP : ������");
		color(0, 14);
		}
		else if(exp == 4)
		{
			color(9, 11);
		printxy(56, 2, " EXP : ������");
		color(0, 14);
		}
		else if(exp == 3)
		{
			color(9, 11);
		printxy(56, 2, " EXP : ������");
		color(0, 14);
		}
		else if(exp == 2)
		{
			color(9, 11);
		printxy(56, 2, " EXP : ������");
		color(0, 14);
	}
		else if(exp == 1)
		{
			color(9, 11);
		printxy(56, 2, " EXP : ������");
		color(0, 14);
		}
		else if(exp == 0)
		{
		color(9,11);
		printxy(56, 2, " EXP : ������");
		color(0, 14);
		}
		color(9,11);
		if(exp >= 5)
		{
		level = level + 1;
		exp = 0;
		color(0, 14);
	}
	printf("[���� : %d]", level);
	color(0, 14);
}
void clear(int x, int y)
{
	
	for(i=0;i<50;i++)
	{
		printXY(x+i,y," ");
	}
	
}
void inventory()
{
	system("color 0e");
	system("mode con:cols=80 lines=50"); //��������������
	while(1)
	{
	printXY(60,1,"������ [Esc]");
	//����â 
	clear(14,10);gotoxy(8,10);
	printf("/POWER : %d/", power);
	clear(14,12);gotoxy(8,12);
	printf("/SPEED: %d/", speed);
	clear(14,12);gotoxy(49,13);
	printf("|���� ���� : %d|", level); 
	
	printXY(7,21,"Ű����:[1]");
	printxy(7,23,"[���ݷ��� 1 ������ŵ�ϴ�.]\n\n                ���� -1");
	printXY(40,21,"Ű����:[2]");
	printxy(40,23,"[�̵����� ��½�ŵ�ϴ�.]");
	printxy(45,25,"���� -10 ");
	
	printXY(5,15,"��");
	printXY(5,43,"��");
	printXY(69,15,"��");
	printXY(69,43,"��");
	clear(5,44);
	printXY(36,15,"��");
	for(i=16;i<43;i++) 
	{
		printxy(5,i,"��");
	}
	for(i=6;i<69;i++)
	{
		printxy(i,15,"��");
		if(i == 36)
		{
			printxy(36,15,"��");
		}
	}
	for(i=6;i<69;i++)
	{
		printxy(i,43,"��");
		if(i == 36)
		{
			printxy(36,43,"��");
		}
	}
	for(i=16;i<43;i++) 
	{
		printxy(69,i,"��");
		if(i == 29)
		{
		printxy(69,29,"��");
		}
	}
	//-----------------------------------
	for(i=6;i<68;i++)
	{
		printxy(i,29,"��");
	}
	for(i=16;i<43;i++) 
	{
		printxy(36,i,"��");
	}
	// 
	if(kbhit())
	{
	sz = getch();
	if(sz == 27)
	{
		system("color e0");
		sz = 0;
		system("cls");
		system("mode con:cols=140 lines=40");
		break;	
	}
	else if(sz == 49)
		{
			if(level >= 1)
			{
				power ++;
				level = level - 1;
			}
		}
	else if(sz == 50)
	{
		if(level >= 10)
		{
			speed ++;
			level = level - 10;
		}
	}
}
	Sleep(20);
}
}
void BOSSHP()
{
	if(bosshp == 1000)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 950)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 900 && bosshp < 950)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 850 && bosshp < 900)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 800 && bosshp < 850)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 750 && bosshp < 800)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 700 && bosshp < 750)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 650 && bosshp < 700)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
		else if(bosshp >= 600 && bosshp < 650)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 500 && bosshp < 600)
	{
		arrow = 15;
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 400 && bosshp < 500)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
		else if(bosshp >= 300 && bosshp < 400)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 200 && bosshp < 300)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp >= 100 && bosshp < 200)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	else if(bosshp < 100)
	{
		color(12, 14);
		printxy(39, 4, "| boss : �������������������������� |");
		color(0, 14);
	}
	gotoxy(100,4);
	printf("[%d]", bosshp);
 } 
void HP()
{ 
	if(hp == 5)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
		else if(hp == 4)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
		else if(hp == 3)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
		else if(hp == 2)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
		else if(hp == 1)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
		else if(hp == 0)
		{
			color(12, 14);
		printxy(0, 4, "| HP : ������ |");
		color(0, 14);
		}
}

void MP()
{
		if(mp == 5)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
		else if(mp == 4)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
		else if(mp == 3)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
		else if(mp == 2)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
		else if(mp == 1)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
		else if(mp == 0)
		{
			color(9, 14);
		printxy(0, 5, "| MP : ������ |");
		color(0, 14);
		}
}
void chong()//�Ѿ� 
{
		if(space1 == 3)
		{
		printXY(2, 27, "(>)(>)(>)");
	}
		else if(space1 == 2)
		{
		printXY(2, 27, "(>)(>)(");
		}
		else if(space1 == 1)
		{
		printXY(2, 27, "(>)()()");
		}
		else if(space1 == 0)
		{
		printXY(2, 27, "()()()");
		}
		
}
void reset()
{
	i = 0,j = 0, ix = 0, sz = 0, k = 0;
	player_x = 2;
	player_y = 26;
	shooting_x = 0,shooting_y = 0,shooting_x1 = 0,shooting_y1 = 0,shooting_x2 = 0,shooting_y2 = 0;
	space = 0;
	space1 = 3;
	bullet = false;
	bullet1 = false;
	bullet2 = false;
	sz1 = 0;
	x1 = 0,y1 = 27;
	voulb = 0;
	stage = 1;
	score = 0;
	monster = 0;
	hp = 5;
	voulb1 = 0;
	sc2 = 0;
	monster1 = 0;
	mp = 5;
	cha = 1;
	monster1_x = 135,monster1_y = 12,monster2_x = 135,monster2_y = 16,monster3_x = 135,monster3_y = 20;// 3���������� ù��° ����  �� 
	randome_monster = 0;
}
//------------------------------------------------------------------------
int main(void)
{
	srand(time(NULL));
	//------------------------Ŀ�� �����------------------ 
CONSOLE_CURSOR_INFO cursorInfo = { 0, } ;
cursorInfo.bVisible = 0;
cursorInfo.dwSize = 1;
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//---------------------------------------------------- 
intro();
start:
	system("color 0e");
system("title ��                                                                                                                   ��MAN and BLOCK��                            ���Ʒ� ������ �о��ּ���!���");
system("mode con:cols=140 lines=40");
    	while(1)
    	{
    		color(15, 0);
    		printxy(115,38,"Made by : Hong-jun-pyo");
    		printxy(1,38,"ver : 0.0.1");
    		color(14, 0);
			color(3, 0);
    		printxy(38, 4, "�⺻ ����Ű��  W A S D . fps�� ����Ű: [��] [��] �� ���� ");
    		printxy(41, 6, "[���ν���] �Ǵ� [�����ϱ�],[�����ϱ�]��  ����Ű: [��] [�Ʒ�] [Enter] ");
    		printxy(40, 8, " ��ų Z:(�Ϲ� ���� :: 1,2,3 �ܰ�) space:(�� :: hp + 5)");
    		printxy(48, 10, "[i]�� ����â �Դϴ�. ���ݷ� ���� �����մϴ�.");
    		color(15, 0);
    		printxy(36, 14, "BIT���Ƹ��� ���� ������ ȯ���մϴ�. �� ���α׷��� �������� ���� ���۵Ǿ����ϴ�.");
    		color(14, 0);
    		color(12, 0);
    		printxy(5,31, "[��]");printxy(13,31, "[��]");printxy(9,29, "[��]");printxy(9,31, "[��]");printxy(7,33, " [ENTER]");
			color(14, 0);	
    		printxy(24,1,"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
    		printxy(24,16,"��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
			for(i=2;i<16;i++)
    		{
    			printxy(24,i,"��");
    			printxy(120,i,"��");
			}
			color(14, 0);
			for(i=1;i<36;i++)
    		{
    			printxy(0,i,"��");
			}
			for(i=0;i<136;i++)
    		{
    			printxy(i+1,0,"��");
    			printxy(i+1,36,"��");
    			if(i == 0)
    			{
    				printxy(0,0,"��");
    				printxy(0,36,"��");
				}
				else if(i == 135)
    			{
    				printxy(138,0,"��");
    				printxy(138,36,"��");
				}
			}
			for(i=1;i<36;i++)
    		{
    			printxy(138,i,"��");
			}
    		if(sz == 0)
			{ 
    		printxy(52,25,"����������������������������������������������������������������������");
    		printxy(52,26,"��           �����ν��ۢ�          ��");
    		printxy(52,27,"����������������������������������������������������������������������");
    		
    		printxy(52,30,"����������������������������������������������������������������������");
    		printxy(52,31,"��             �����ϱ�            ��");
    		printxy(52,32,"����������������������������������������������������������������������");
    	}
    	color(11, 0);
    	printxy(49,20,"FPS:[����]---------------------------[����]");
    	color(14, 0);
    	color(15, 0);
    	printxy(fpsx,20,"��");
    	color(14, 0);
		if(kbhit())  
       {
		sz = getch();
		if(sz == 72)
		{
			printxy(9,29, "[��]");
			printxy(52,25,"����������������������������������������������������������������������");
    		printxy(52,26,"��           �����ν��ۢ�          ��");
    		printxy(52,27,"����������������������������������������������������������������������");
    		
    		printxy(52,30,"����������������������������������������������������������������������");
    		printxy(52,31,"��             �����ϱ�            ��");
    		printxy(52,32,"����������������������������������������������������������������������");
		}
		else if(sz == 80)
		{
			printxy(9,31, "[��]");
			printxy(52,25,"����������������������������������������������������������������������");
    		printxy(52,26,"��             ���ν���            ��");
    		printxy(52,27,"����������������������������������������������������������������������");
    		
    		printxy(52,30,"����������������������������������������������������������������������");
    		printxy(52,31,"��           �������ϱ⢸          ��");
    		printxy(52,32,"����������������������������������������������������������������������");
		}
		else if(sz == 77)
		{
			if(fpsx-40<=43)
			{
				printxy(13,31, "[��]");
			fpsx ++;
			sz = 0;
			fps --;
			fps --;
				color(11, 0);
			printxy(49,20,"FPS:[����]---------------------------[����]");
			color(14, 0);
			}
		}
		else if(sz == 75)
		{
			if(fpsx-40>=20)
			{
				printxy(5,31, "[��]");
			fpsx --;
			sz = 0;
			fps ++;
			fps ++;
			color(11, 0);
			printxy(49,20,"FPS:[����]---------------------------[����]");
			color(14, 0);
		}
		}
		color(15, 0);
			printxy(fpsx,20,"��");
			color(14, 0);
		}
    			sz1 = getch();
    			if(sz1 == 13 && sz == 72)
    			{
    				goto cha;
    				sz = 0,sz1 = 0;
				}
				else if(sz1 == 13 && sz == 80)
				{
					return 0;
				}
				else if(sz1 == 13 && sz == 0)
				{
					goto cha;
					sz = 0,sz1 = 0;
				}
		Sleep(70);
	}
	cha:
int sc = 0;
	system("color a0");
	system("mode con:cols=120 lines=35");
	system("title [MAN and BLOCK]                                                                       ���������� Ŭ���� �ϼ���. 1/4");
		printxy(41,18,"5�� ��  ����!");
		printxy(26,21,">> �ظ�ǥ : ���͸� óġ�ϰ� ������ �÷� ������ �������!�� <<");
		printxy(26,24,"<< ���� : [��] - ������ �����մϴ�! ��ų�� ����ϼ���. >>");
		hp = 5;
		mp = 5;
		Sleep(3300);	
//---------------------------------------------------
system("mode con:cols=140 lines=40");
		system("color e0");
	while(1)
	{
		randome_monster = rand()%3+1;
		//----------------------------
		if(hp == 0)
		{
			system("cls");
			printf("\n\n\n            game over");
			system("pause");
			return 0; 
		}
	//-----ī��Ʈ-------- //
	if(count1 >= 100)
	{
		goto boss;
	}
	else if(count1 == 10)
	{
		quest = 20;
		max = 8;
	 } 
	 else if(count1 == 20)
	 {
	 	quest = 30;
	 	max = 11;
	 }
	else if(count1 == 30)
	 {
	 	quest = 50;
	 	max = 13;
	 }
	 	else if(count1 == 50)
	 {
	 	quest = 100;
	 	max = 15;
	 }
	//------monster--------
	for(i=0;i<MAX;i++)
	{
	if(enemy[i] == false)
	{
		ey[i] = rand() % 19 + 8;
		ex[i] = 120 + i+3;
		enemy[i] = true;
		break;
	}
	}
	
	for(i=0;i<max;i++)
	{
	if(enemy[i] == true)
	{
		printXY(ex[i],ey[i],"��");
		ex[i] --;
		if(player_x == ex[i] && player_y == ey[i])
		{
			hp --;
			printxy(player_x, player_y, "��");
			Sleep(150);
			printxy(player_x, player_y, " ");
			enemy[i] = false;
		}
		
		if(shooting_x >= ex[i] && shooting_y == ey[i])
		{
			shooting_x = player_x-1;
			enemy[i] = false;
			bullet = false;
			exp ++;
			mp ++;
			count1 ++;
		}
		if(shooting_x1 >= ex[i] && shooting_y1 == ey[i])
		{
			shooting_x1 = player_x-1;
			enemy[i] = false;
			bullet1 = false;
			exp ++;
			mp ++;
			count1 ++;
			if(ultimate < 4)
			{
			ultimate ++;
		}
		}
		if(shooting_x2 >= ex[i] && shooting_y2 == ey[i])
		{
			shooting_x2 = player_x -1;
			enemy[i] = false;
			count1 ++;
			exp ++;
			mp ++;
		}
		if(ex[i] < 1)
		{
			enemy[i] = false;
		}
	}
}
	//-------����---------- 
		//������ ����  
		printxy(0,0, "*******************************************************************************************************************************************\n");
		color(0, 14);
		printf("                                                           [STAGE : %d]", stage);
		printf("[SCORE : %d]", score);
		color(13, 14);
		printxy(0,28, "===========================================================================================================================================");
		printxy(0,6, "===========================================================================================================================================");
		color(0, 14);
		printf("                                                                                                                             X:%d Y:%d",player_x,player_y);
		color(12, 14);
		printxy(58,30, "[Z] - ����");
		color(12, 14);
		printxy(58,29, "[I] - ����â");
		color(0, 14);
		color(0, 14);
		color(9, 14);
		printxy(60,35, "[space]");
		color(0, 14);
		//--------------------------------------
		gotoxy(1,1);
		printf("���� ���� �� : %d / %d" ,count1,quest);
		//----ulti gui----------------------------------------
		color(9, 14);
		printxy(70,35, " -  ü��ȸ��[mp - 5][hp + 5]");
		color(0, 14);
	if(ultimate == 4)
		{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[@]");
		printXY(67,35, "[@]");
	}
	else if(ultimate == 1)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 2)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 3)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[@]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 0)
	{
		printXY(62,33, "[]");
		printXY(57,35, "[]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
		//---------------------------------------
		//hp gui 
		HP();
		//mp gui
		MP();
		//chong gui
		chong();
		//exp
		EXP();
		//-------------
		//player���� 
		printXY(player_x,player_y,"[@]>");
		//-------------
		color(16, 14);
		printxy(6,30, "<< �Ϲݰ��� >>");
		printxy(6,32, "1�ܰ� : ���� ���� 2���� �߻��մϴ�.");
		printxy(6,34, "2�ܰ� : �߻�ü �ӵ��� 1.5�� �����մϴ�.");
		printxy(6,36, "3�ܰ� : �߻�ü �ӵ��� 2�� �����ϸ�");
		printxy(6,37, "������ ���� ��� �ѹ� �� �߻�˴ϴ�.");
		color(0, 14);
		//--------------
		if(kbhit())
		{
			sz = getch();
			if(sz == 32)
				{
					if(ultimate >= 4)
					{
						if(mp >= 5)
						{
						hp = 5;
						mp = 0;
						ultimate = 0;
						}
					}
				}
				//---------------��Ʈ��------------------------ 
				else if(sz == 97)
				{
					if(player_x > 2)
					{
					player_x = player_x - speed -1;
					
				}
				}
				else if(sz == 100)
				{
					if(player_x < 62)
					{
						player_x = player_x + speed +1;
				}
				}
				else if(sz == 119)
				{
					if(player_y > 8)
					{
					player_y = player_y - speed;
				}
				}
				else if(sz == 115)
				{
					if(player_y < 26)
					{
					player_y = player_y + speed;
				}
				}
				//-----------------����Ű------------------------
				else if(sz == 75)
				{
					if(player_x > 2)
					{
					player_x = player_x - speed -1;
				}
				}
				else if(sz == 77)
				{
					if(player_x < 62)
					{
					player_x = player_x + speed +1;
				}
				}
				else if(sz == 72)
				{
					if(player_y > 8)
					{
					player_y = player_y - speed;
				}
				}
				else if(sz == 80)
				{
					if(player_y < 26)
					{
					player_y = player_y + speed;
				}
				} 
			 //------------------------------------------------
				else if(sz == 122)
				{
					bu1(); //�߻�ü �˻� �κ�
				}
				else if(sz == 105)
				{
					inventory();
				}
					else if(sz == 98)
				{
					goto boss;
				}
		}
		bu2();//�߻�ü ���� �κ�  
		if(fps <= 0)
		{
			fps = 1;
		}
		Sleep(fps);
	render();	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------


boss:
	system("cls");
	//-------------------------������ ����------------------------------
	system("color b0");
	system("mode con:cols=120 lines=35");
	system("title [MAN and BLOCK]                                                                       ���������� Ŭ���� �ϼ���. 1/4");
		printxy(41,18,"5�� ��  ����!");
		printxy(26,21,">> �ظ�ǥ : ������ ȭ���� ���� ���� ���͸� óġ�ϼ���!�� <<");
		hp = 5;
	 mp = 5;
		Sleep(3300);	
	//---------------------------------------------------------------- 
	ultimate = 4;
	system("cls");
	count1 = 100;
	//-------------------------------intro----------------------------------------------------
	if(count1 >= 100)
	{
system("mode con:cols=140 lines=40");
		system("color e0");
	while(1)
	{
		if(bosshp <= 0)
		{
			system("cls");
			printxy(100,100,":: stage clear :: \n\n\n\n\n    �÷��� ���ּż� �����մϴ�. \n\n\n\n\n\n\n");
			system("pause");
			return 0; 
		}
		//-------------boss gui-----------------------------------------------
		color(12, 14);
		printxy(105,13,"<[��]");
		color(0, 14);
		color(9, 11);
		for(i=9;i<26;i++)
		{
			printxy(100,i,"��");
		}
		for(i=9;i<26;i++)
		{
			printxy(111,i,"��");
		}
		for(i=102;i<110;i++)
		{
			printxy(i,8,"��");
		}
		for(i=102;i<110;i++)
		{
			printxy(i,26,"��");
		}
		color(0, 14);
		//--------------------------------------------------------------------
		randome_monster = rand()%3+1;
		//----------------------------
		if(hp == 0)
		{
			system("cls");
			printf("\n\n\n            game over");
			system("pause");
			return 0; 
		}
	//------monster--------
	for(i=0;i<MAX;i++)
	{
	if(enemy[i] == false)
	{
		ey[i] = rand() % 19 + 8;
		ex[i] = 120 + i+3;
		enemy[i] = true;
		break;
	}
	}
	
	for(i=0;i<arrow;i++)
	{
	if(enemy[i] == true)
	{
		//-----------�ǰ�-------------------------- 
		printXY(ex[i],ey[i],"<��");
		ex[i] --;
		if(player_x == ex[i] && player_y == ey[i])
		{
			hp --;
			printxy(player_x, player_y, "��");
			Sleep(150);
			printxy(player_x, player_y, " ");
			enemy[i] = false;
		}
		//------------------------------------------
		if(shooting_x >= ex[i] && shooting_y == ey[i])
		{
			shooting_x = player_x-1;
			enemy[i] = false;
			bullet = false;
			mp ++;
			count1 ++;
		}
		if(shooting_x1 >= ex[i] && shooting_y1 == ey[i])
		{
			shooting_x1 = player_x-1;
			enemy[i] = false;
			bullet1 = false;
			mp ++;
			count1 ++;
			if(ultimate < 4)
			{
			ultimate ++;
		}
		}
		if(shooting_x2 >= ex[i] && shooting_y2 == ey[i])
		{
			shooting_x2 = player_x -1;
			enemy[i] = false;
			mp ++;
		}
		//-----------------------������Ÿ�� ---------------------------
		if(shooting_x >= 100)
		{
			shooting_x = player_x-1;
			printxy(102,shooting_y,"��");
			enemy[i] = false;
			bullet = false;
			mp ++;
			bosshp = bosshp - power; 
		}
		if(shooting_x1 >= 100)
		{
			printxy(102,shooting_y,"��");
			shooting_x1 = player_x-1;
			enemy[i] = false;
			bullet1 = false;
			mp ++;
			bosshp = bosshp - power; 
			if(ultimate < 4)
			{
			ultimate ++;
		}
		}
		if(shooting_x2 >= 100)
		{
			printxy(102,shooting_y,"��");
			shooting_x2 = player_x -1;
			enemy[i] = false;
			mp ++;
			bosshp = bosshp - power; 
		}
		//-----------------------ũ��Ƽ��--------------------------
		if(shooting_x >= 99 && shooting_y == 13)
		{
			shooting_x = player_x-1;
			printxy(107,13,"��");
			Sleep(150);
			enemy[i] = false;
			bullet = false;
			mp ++;
			bosshp = bosshp - 50; 
		}
		if(shooting_x1 >= 99 && shooting_y1 == 13)
		{
			printxy(107,13,"��");
			Sleep(150);
			shooting_x1 = player_x-1;
			enemy[i] = false;
			bullet1 = false;
			mp ++;
			bosshp = bosshp - 50; 
			if(ultimate < 4)
			{
			ultimate ++;
		}
		}
		if(shooting_x2 >= 99 && shooting_y2 == 13)
		{
			printxy(107,13,"��");
			Sleep(150);
			shooting_x2 = player_x -1;
			enemy[i] = false;
			mp ++;
			bosshp = bosshp - 50; 
		}
		//---------------------------------------------------------
		if(ex[i] < 1)
		{
			enemy[i] = false;
		}
	}
}
	//-------����---------- 
		//������ ����  
		BOSSHP();
		printxy(0,0, "*******************************************************************************************************************************************\n");
		color(0, 14);
		color(13, 14);
		printxy(0,28, "===========================================================================================================================================");
		printxy(0,6, "===========================================================================================================================================");
		color(0, 14);
		printf("                                                                                                                             X:%d Y:%d",player_x,player_y);
		color(0, 14);
		color(9, 14);
		printxy(60,35, "[space]");
		color(0, 14);
		//--------------------------------------
		gotoxy(1,1);
		//----ulti gui----------------------------------------
		color(9, 14);
		printxy(70,35, " -  ü��ȸ��[mp - 5][hp + 5]");
		color(0, 14);
	if(ultimate == 4)
		{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[@]");
		printXY(67,35, "[@]");
	}
	else if(ultimate == 1)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 2)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 3)
	{
		printXY(62,33, "[@]");
		printXY(57,35, "[@]");
		printXY(62,37, "[@]");
		printXY(67,35, "[]");
	}
	else if(ultimate == 0)
	{
		printXY(62,33, "[]");
		printXY(57,35, "[]");
		printXY(62,37, "[]");
		printXY(67,35, "[]");
	}
		//---------------------------------------
		//hp gui 
		HP();
		//mp gui
		MP();
		//chong gui
		chong();
		//player���� 
		printXY(player_x,player_y,"[@]>");
		//-------------
		color(16, 14);
		printxy(6,30, "<< �Ϲݰ��� >>");
		printxy(6,32, "1�ܰ� : ���� ���� 2���� �߻��մϴ�.");
		printxy(6,34, "2�ܰ� : �߻�ü �ӵ��� 1.5�� �����մϴ�.");
		printxy(6,36, "3�ܰ� : �߻�ü �ӵ��� 2�� �����ϸ�");
		printxy(6,37, "������ ���� ��� �ѹ� �� �߻�˴ϴ�.");
		color(0, 14);
		//--------------
		if(kbhit())
		{
			sz = getch();
			if(sz == 32)
				{
					if(ultimate >= 4)
					{
						if(mp >= 5)
						{
						hp = 5;
						mp = 0;
						ultimate = 0;
						}
					}
				}
				//---------------��Ʈ��------------------------ 
				else if(sz == 97)
				{
					if(player_x > 2)
					{
					player_x = player_x - speed -1;
					
				}
				}
				else if(sz == 100)
				{
					if(player_x < 62)
					{
						player_x = player_x + speed +1;
				}
				}
				else if(sz == 119)
				{
					if(player_y > 8)
					{
					player_y = player_y - speed;
				}
				}
				else if(sz == 115)
				{
					if(player_y < 26)
					{
					player_y = player_y + speed;
				}
				}
				//-----------------����Ű------------------------
				else if(sz == 75)
				{
					if(player_x > 2)
					{
					player_x = player_x - speed -1;
				}
				}
				else if(sz == 77)
				{
					if(player_x < 62)
					{
					player_x = player_x + speed +1;
				}
				}
				else if(sz == 72)
				{
					if(player_y > 8)
					{
					player_y = player_y - speed;
				}
				}
				else if(sz == 80)
				{
					if(player_y < 26)
					{
					player_y = player_y + speed;
				}
				} 
			 //----------------------�����ڵ���--------------------------
			 else if(sz == 112)
				{
					power = 100;
				}
				//---------------------------------------
				else if(sz == 122)
				{
					bu1(); //�߻�ü �˻� �κ�
				}
		}
		bu2();//�߻�ü ���� �κ�  
		Sleep(1);
	render();	
}
	}
	else
	{
		system("cls");
		gotoxy(60,60); 
		printf("**����**");
	}
	return 0;
}
