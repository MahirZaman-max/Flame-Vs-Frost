#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int playerChar1, playerChar2;//0=firen,1=freezeman,2=rudolf,3=henry
//SWITCH FLAG
//'''''''''''''''''''''''''''''''''''''''''''''
bool introFlag = true;
bool loadingFlag = true;
bool homeFlag = true;
bool startFlag = false;//startFlag true hole selectionPage e jabe
bool settingFlag = false;
bool instructionFlag = false;
bool aboutUsFlag = false;
bool button[] = { true, true, true, true, true };//true mani default button show krtese.false hle hoverd hbe.
bool player1ProfileFlag[4] = { false, false, false, false };
bool player2ProfileFlag[4] = { false, false, false, false };
bool circleFlag[2] = { false, false };//map er corner e circle click ene dei.
bool inGame = false;
//PIC VARRIABLES
//'''''''''''''''''''''''''''''''''''''''''''''''''
int Intro;
int loading[8];
int B[5],BH[5];
int Home;
int aboutUs;
int selectionPage;
int circle;
int profilePic[4];//{firen,freeze,rodulf,henry}
int bg1, bg2;//bg1=moonmap,bg2=firemap
//FUNCTIONS
//''''''''''''''''''''''''''''''''''''''''''''''''
void handleButtonOfHomepage(int mx,int my){
	//START BUTTON ER KAJ
	if (mx > 150 && mx<450 && my>250 && my < 301){
		if (introFlag == false && loadingFlag == false){
			PlaySound("clickSound.wav", NULL, SND_FILENAME | SND_ASYNC);
			homeFlag = false;
			startFlag = true;
		}
	}
	//ABOUT US ER KAJJJ
	else if (mx>150 && mx<450 && my>83 && my<134){
		if (introFlag == false && loadingFlag == false){
            PlaySound("clickSound.wav", NULL, SND_FILENAME | SND_ASYNC);
			homeFlag = false;
			aboutUsFlag = true;
		}
	}
	//EXIT BUTTON ER KAAJ
	else if (mx>150 && mx<450 && my>28 && my < 77){
		if (introFlag == false && loadingFlag == false){
			PlaySound("clickSound.wav", NULL, SND_FILENAME | SND_ASYNC);
			iDelay(2);
			exit(0);
		}
	}

}
//PLAYER 1 SELECT KORAR KAJJJJ.......................
void handlePlayer1Selection(int mx,int my){
	if (mx > 180 && mx<235 && my>200 && my<250){
		player1ProfileFlag[0] = true;
		player1ProfileFlag[1] = false;
		player1ProfileFlag[2] = false;
		player1ProfileFlag[3] = false;

	}
	else if (mx > 250 && mx<305 && my>200 && my<250){
		player1ProfileFlag[0] = false;
		player1ProfileFlag[1] = true;
		player1ProfileFlag[2] = false;
		player1ProfileFlag[3] = false;

	}
	else if (mx > 320 && mx<375 && my>200 && my<250){
		player1ProfileFlag[0] = false;
		player1ProfileFlag[1] = false;
		player1ProfileFlag[2] = true;
		player1ProfileFlag[3] = false;

	}
	else if (mx > 385 && mx<440 && my>200 && my<250){
		player1ProfileFlag[0] = false;
		player1ProfileFlag[1] = false;
		player1ProfileFlag[2] = false;
		player1ProfileFlag[3] = true;

	}
}
//PLAYER 2 SELECT KORAR FUNTION...........................................................
void handlePlayer2Selection(int mx, int my){
	if (mx > 620 && mx<675 && my>200 && my<250){
		player2ProfileFlag[0] = true;
		player2ProfileFlag[1] = false;
		player2ProfileFlag[2] = false;
		player2ProfileFlag[3] = false;

	}
	else if (mx > 685 && mx<740 && my>200 && my<250){
		player2ProfileFlag[0] = false;
		player2ProfileFlag[1] = true;
		player2ProfileFlag[2] = false;
		player2ProfileFlag[3] = false;

	}
	else if (mx > 750 && mx<805 && my>200 && my<250){
		player2ProfileFlag[0] = false;
		player2ProfileFlag[1] = false;
		player2ProfileFlag[2] = true;
		player2ProfileFlag[3] = false;

	}
	else if (mx > 820 && mx<875 && my>200 && my<250){
		player2ProfileFlag[0] = false;
		player2ProfileFlag[1] = false;
		player2ProfileFlag[2] = false;
		player2ProfileFlag[3] = true;

	}
}
//SELECTION PAGE ER READY BUTTON ER KAAAAAJJJJJJ
void ReadyButton(int mx,int my){
	bool player1Flag = false, player2Flag = false,mapFlag=false;
	for (int i = 0; i < 4; i++){
		if (player1ProfileFlag[i]){
			player1Flag = true;
			playerChar1 = i;
			break;
		}

	}
	for (int i = 0; i < 4; i++){
		if (player2ProfileFlag[i]){
			player2Flag = true;
			playerChar2 = i;
			break;
		}

	}
	for (int i = 0; i < 2; i++){
		if (circleFlag[i]){
			mapFlag = true;
			break;

		}
	}
	if (player1Flag && player2Flag && mapFlag && mx>765 && mx<900 && my>0 && my<45){
		startFlag = false;
		inGame = true;
		
	}


}

//intro page er kaj
//''''''''''''''''''''''''''''''''''''''''''''
void introFunction(){
	introFlag = false;
}
void introDisplay(){
	
	iShowImage(0, 0, 900, 500, Intro);
}
//loading page er kaj
//''''''''''''''''''''''''''''''''''''''''''
int loadingIndex = 0;
bool loadingKey = true;
void loadingDisplay(){
	iShowImage(0, 0, 900, 500, loading[loadingIndex]);
	loadingIndex++;
	if (loadingIndex == 8){
		loadingIndex = 7;
		iText(280, 20, "Enter Space or Click to Continue", GLUT_BITMAP_TIMES_ROMAN_24);
		loadingKey = false;
	}
}
//homepage er kaj
//'''''''''''''''''''''''''''''''''''''''''''''''''''''
void displayHome(){
	
	iShowImage(0, 0, 900, 500, Home);
	int y = 250;
	for (int i = 0; i < 5; i++){
		if (button[i]){
			iShowImage(200, y, 300, 51, B[i]);
			y -= 56;
		}
		else{
			iShowImage(200, y, 300, 51, BH[i]);
			y -= 56;
		}
	}
	
}
void homeHoverEffect(int mx,int my){
	int y = 250;
	for (int i = 0; i<5; i++){
		if (mx > 200 && mx<500 && my>y && my < y + 34){
			button[i] = false;
			
		}
		else{
			button[i] = true;
		}
		y -= 56;
	}
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^MATCH ER VITORER KAJER VARRIABLE^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int playerPosition1X=100, playerPosition1Y=90, playerPosition2X=800, playerPosition2Y=90,p1width=60,p2width=-60,p1height=120,p2height=120;
const int ground = 90;
int sprite[4][100];
int health1 = 160, health2 = 160;
int i = 0, j = 0,m,n,t=0,s=0;
int fireX1, fireY1 = playerPosition1Y + 40, fireX2, fireY2 = playerPosition2Y + 40, firewidth = 70, firewidth1=70;//special action sprite er co-ordinate
int frameCounter1 = 13, frameCounter2 = 13, frameCounter3 = 13, frameCounter4 = 13, frameCounter5 = 13, frameCounter6 = 13, framecounterrun[6] = { 0, 0, 0, 0, 0, 0 };
int framecounterpunch[2] = { 0, 0 }, framecounterkick[2] = { 0, 0 }, framecounterjump[2] = { 0, 0 }, framecounterblock[2] = { 0, 0 }, framecounerthrow[2] = { 0, 0 }, timecounterfireball[2] = { 0, 0 };;
int framecounterfire[2] = { 0, 0 };
bool p1rightface=true,p1leftface=false;
bool p2rightface = true, p2leftface = false;
bool fire[2] = { false, false };
bool fireflag[2];
bool anycollision[2] = { false, false }, collision[2] = { false, false }, punchcollision[2] = { false, false };//collision mane fire/freeze/ninjaspin collision
int H[2] = { 1, 1 };
int result=0;
void displayFiren(int a){
	if (a == 1){
		if (health1 == 0){
			i = 41;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 2 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (fire[0]){
				m = 58;
				timecounterfireball[0]++;
				if (p1rightface && timecounterfireball[0] < 2){
					firewidth = 70;
					fireX1 = playerPosition1X + 40;
					fireflag[0] = true;
				}
				if (p1leftface && timecounterfireball[0]<2){
					firewidth = -70;
					fireX1 = playerPosition1X - 40;
					fireflag[0] = false;

				}
				if (fireflag[0]) fireX1 += 5;
				else  fireX1 -= 5;
				//damage er kaaj''''''''''''''''''''''''''''
				if (p2rightface && fireX1 > playerPosition2X + p2width - 50 && fireX1 < playerPosition2X + 20 && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 10;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;

				}
				if (p2leftface && fireX1>playerPosition2X - 30 && fireX1 < playerPosition2X + p2width + 20 && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 10;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;
				}
				if (fireX1>900 || fireX1 < 0 || collision[0]){
					fire[0] = false;
					timecounterfireball[0] = 0;
					fireX1 = 1000;
					collision[0] = false;
				}

			}
			if ((GetAsyncKeyState('W') & 0x8000)){//JUMP"""""""""""""""""""""""""""
				framecounterrun[0] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 7;
				else i = 8;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}
			else if (!(GetAsyncKeyState('W') & 0x8000) && playerPosition1Y > ground){//JUMP""""""""""""""""""""""""""""""""
				framecounterrun[0] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 7;
				else i = 8;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi high
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}

			else if ((GetAsyncKeyState('D') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//WALK..............................
				framecounterrun[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (playerPosition1X < 840) playerPosition1X += 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 9;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 15 == 0){
						i++;

					}
					if (framecounterpunch[0]<240 && i > 17){
						i = 9;
					}
					else if (i > 21){
						i = 9;
						framecounterpunch[0] = 1;
					}
				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 59;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 62){
						i = 59;
					}
					else if (i > 62){
						i = 59;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter1++;
					if (frameCounter1 > 15){
						i++;
						frameCounter1 = 0;
					}
					if (i > 3) i = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//WALK..............................
				framecounterrun[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				if (playerPosition1X > 60) playerPosition1X -= 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 9;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 15 == 0){
						i++;
					}
					if (framecounterpunch[0]<240 && i > 17){
						i = 9;
					}
					else if (i > 21){
						i = 9;
						framecounterpunch[0] = 1;
					}


				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 59;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 62){
						i = 59;
					}
					else if (i > 62){
						i = 59;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter1++;
					if (frameCounter1 > 15){
						i++;
						frameCounter1 = 0;
					}
					if (i > 3) i = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState('D') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN..............................
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (framecounterrun[0] == 0) i = 4;
				if (playerPosition1X < 840) playerPosition1X += 2;
				framecounterrun[0] += 1;
				if (framecounterrun[0]>15){
					i++;
					framecounterrun[0] = 1;
				}
				if (i > 6) i = 4; // loop sprite 4-6
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN....................................
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterrun[0] == 0) i = 4;
				if (playerPosition1X > 60) playerPosition1X -= 2;
				framecounterrun[0]++;
				if (framecounterrun[0] > 15){
					i++;
					framecounterrun[0] = 1;
				}
				if (i > 6) i = 4; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(' ') & 0x8000)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 22;
				framecounerthrow[0]++;
				if (framecounerthrow[0] == 5) fire[0] = true;
				if (framecounerthrow[0] < 50){
					if (framecounerthrow[0] % 20 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}
			else if (!(GetAsyncKeyState(' ') & 0x8000) && (i == 22 || i == 23 || i == 24)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 22;
				framecounerthrow[0]++;
				if (framecounerthrow[0] < 50){
					if (framecounerthrow[0] % 20 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}

			else if ((GetAsyncKeyState('Q') & 0x8000)){//PUNCH""""""""""""""""""""""""""""""""""""""""""""""""""""""
				framecounterrun[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounterkick[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterpunch[0] == 0) i = 9;
				framecounterpunch[0]++;
				if (framecounterpunch[0] % 15 == 0){
					i++;
					if (p1rightface && p2leftface && playerPosition1X + p1width >= playerPosition2Y && playerPosition1X + p1width <= playerPosition2Y + p2width){
						health2 = health2 - H[0];
						H[0]++;
						anycollision[0] = true;
						punchcollision[0] = true;
					}

				}
				if (framecounterpunch[0]<240 && i > 17){
					i = 9;
				}
				else if (i > 21){
					i = 9;
					framecounterpunch[0] = 1;
				}


			}
			else if ((GetAsyncKeyState('E') & 0x8000)){//KICK""""""""""""""""""""""""""""""""""""""""""""""""""""
				framecounterrun[0] = 0;
				framecounterpunch[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterkick[0] == 0) i = 59;
				framecounterkick[0]++;
				if (framecounterkick[0] % 15 == 0){
					i++;
				}
				if (framecounterkick[0]<240 && i > 62){
					i = 59;
				}
				else if (i > 62){
					i = 59;
					framecounterkick[0] = 1;
				}
			}
			else if ((GetAsyncKeyState('F') & 0x8000)){//BLOCK"""""""""""""""""""""""""""""""""""""""""""""
				framecounterrun[0] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterblock[0] == 0) i = 52;
				framecounterblock[0]++;
				if ((framecounterblock[0] / 15) % 2 == 1) i = 53;
				else if ((framecounterblock[0] / 15) % 2 == 0) i = 52;
			}
			else{
				i = 0;
				framecounterrun[0] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;

			}
		}
		
	}
	//player 2 handle''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	if (a == 2){
		if (health2 == 0){
			j = 41;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 1 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (health2 == 0){
				j = 41;
				iDelay(1);
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(350, 250, "PLAYER 2 WON!!!!!!", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if (fire[1]){
				n = 58;
				timecounterfireball[1]++;
				if (p2rightface && timecounterfireball[1] < 2){
					firewidth1 = -70;
					fireX2 = playerPosition2X - 40;
					fireflag[1] = true;
				}
				if (p2leftface && timecounterfireball[1]<2){
					firewidth1 = +70;
					fireX2 = playerPosition2X + 40;
					fireflag[1] = false;

				}
				if (fireflag[1]) fireX2 -= 5;
				else  fireX2 += 5;
				//DaMAGE ER KAAJJJJ"'''''''''''''''''''''''''''''''''
				if (p1leftface && fireX2 > playerPosition1X + p1width && fireX2 < playerPosition1X + 30 && playerPosition1Y - 10 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 10;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;

				}
				if (p1rightface && fireX2>playerPosition1X - 20 && fireX2 < playerPosition1X + p1width + 20 && playerPosition1Y - 10 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 10;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;
				}
				if (fireX2>900 || fireX2 < 0 || collision[1]){
					fire[1] = false;
					timecounterfireball[1] = 0;
					fireX2 = 1000;
					collision[1] = false;
				}

			}
			if ((GetAsyncKeyState(VK_UP) & 0x8000)){//JUMP''''''''''''''''''''''''''''''''''''''
				framecounterrun[1] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 7;
				else j = 8;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;

				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}
				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}
			else if (!(GetAsyncKeyState(VK_UP) & 0x8000) && playerPosition2Y > ground){//JUMP''''''''''''''''''''''''''''''''''''
				framecounterrun[1] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 7;
				else j = 8;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi high
				}

				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;
				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}

				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}

			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//L2Rwalk.......................................
				framecounterrun[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (playerPosition2X < 840) playerPosition2X += 1;
				if ((GetAsyncKeyState('L') & 0x8000)){
					if (framecounterpunch[1] == 0) j = 9;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 15 == 0){
						j++;

					}
					if (framecounterpunch[1]<240 && j > 17){
						j = 9;
					}
					else if (j > 21){
						j = 9;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 59;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 62){
						j = 59;
					}
					else if (j > 62){
						j = 59;
						framecounterkick[1] = 1;
					}
				}
				else{
					framecounterpunch[0] = 1;
					framecounterkick[1] = 0;
					frameCounter2++;
					if (frameCounter2 > 15){
						j++;
						frameCounter2 = 0;
					}
					if (j > 3) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//R2LWALK................................
				framecounterrun[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (playerPosition2X > 60) playerPosition2X -= 1;
				if ((GetAsyncKeyState('L') & 0x8000)){
					if (framecounterpunch[1] == 0) j = 9;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 15 == 0){
						j++;

					}
					if (framecounterpunch[1]<240 && j > 17){
						j = 9;
					}
					else if (j > 21){
						j = 9;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 59;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 62){
						j = 59;
					}
					else if (j > 62){
						j = 59;
						framecounterkick[1] = 1;
					}
				}
				else{
					framecounterpunch[1] = 0;
					framecounterkick[1] = 0;
					frameCounter2++;
					if (frameCounter2 > 15){
						j++;
						frameCounter2 = 0;
					}
					if (j > 3) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//LtoR RUNNN.......................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (framecounterrun[1] == 0) j = 4;
				if (playerPosition2X < 840) playerPosition2X += 2;
				framecounterrun[1]++;
				if (framecounterrun[1]>15){
					j++;
					framecounterrun[1] = 1;
				}
				if (j > 6) j = 4; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//RtoL RUNNNNN................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;

				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (framecounterrun[1] == 0) j = 4;
				if (playerPosition2X > 60) playerPosition2X -= 2;
				framecounterrun[1]++;
				if (framecounterrun[1] > 15){
					j++;
					framecounterrun[1] = 1;
				}
				if (j > 6) j = 4; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState('J') & 0x8000)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 22;
				framecounerthrow[1]++;
				if (framecounerthrow[1] == 5) fire[1] = true;
				if (framecounerthrow[1] < 50){
					if (framecounerthrow[1] % 20 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}
			else if (!(GetAsyncKeyState('L') & 0x8000) && (j == 22 || j == 23 || j == 24)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 22;
				framecounerthrow[1]++;
				if (framecounerthrow[1] < 50){
					if (framecounerthrow[1] % 20 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}
			else if ((GetAsyncKeyState('L') & 0x8000)){//PUNCH'''''''''''''''''''''''''''''''''''''''
				framecounterrun[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterpunch[1] == 0) j = 9;
				framecounterpunch[1]++;
				if (framecounterpunch[1] % 15 == 0){
					j++;

				}
				if (framecounterpunch[1]<240 && j > 17){
					j = 9;
				}
				else if (j > 21){
					j = 9;
					framecounterpunch[1] = 1;
				}


			}
			else if ((GetAsyncKeyState('I') & 0x8000)){//KICK'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
				framecounterrun[1] = 0;
				framecounterpunch[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterkick[1] == 0) j = 59;
				framecounterkick[1]++;
				if (framecounterkick[1] % 15 == 0){
					j++;
				}
				if (framecounterkick[1]<240 && j > 62){
					j = 59;
				}
				else if (j > 62){
					j = 59;
					framecounterkick[1] = 1;
				}
			}
			else if ((GetAsyncKeyState('O') & 0x8000)){//''''''''''''''''''''BLOCK''''''''''''''''''''''''''
				framecounterrun[1] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterblock[1] == 0) j = 52;
				framecounterblock[1]++;
				if ((framecounterblock[1] / 15) % 2 == 1) j = 53;
				else if ((framecounterblock[1] / 15) % 2 == 0) j = 52;
			}
			else{
				j = 0;
				framecounterrun[1] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
			}

		}
	}

}
void displayFreeze(int a){
	if (a == 1){
		if (health1 == 0){
			i = 41;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 2 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (fire[0]){
				m = 59;
				timecounterfireball[0]++;
				if (p1rightface && timecounterfireball[0] < 2){
					firewidth = 70;
					fireX1 = playerPosition1X + 40;
					fireflag[0] = true;
				}
				if (p1leftface && timecounterfireball[0]<2){
					firewidth = -70;
					fireX1 = playerPosition1X - 40;
					fireflag[0] = false;

				}
				if (fireflag[0]) fireX1 += 6;
				else  fireX1 -= 6;
				//damage er kaj
				if (p2rightface && fireX1 > playerPosition2X + p2width - 50 && fireX1 < playerPosition2X && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 8;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;

				}
				if (p2leftface && fireX1>playerPosition2X - 30 && fireX1 < playerPosition2X + p2width && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 8;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;
				}
				if (fireX1>900 || fireX1 < 0 || collision[0]){
					fire[0] = false;
					timecounterfireball[0] = 0;
					fireX1 = 1000;
					collision[0] = false;
				}

			}
			if ((GetAsyncKeyState('W') & 0x8000)){//JUMP'''''''''''''''''''''''''''''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 9;
				else i = 10;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}
			else if (!(GetAsyncKeyState('W') & 0x8000) && playerPosition1Y > ground){//JUMPPP''''''''''''''''''''''''''''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 9;
				else i = 10;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi high
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}
			else if ((GetAsyncKeyState('D') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//WALK''''''''''''''''''''''''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (playerPosition1X < 840) playerPosition1X += 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 12;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 20 == 0){
						i++;


					}
					if (framecounterpunch[0]<240 && i > 14){
						i = 12;
					}
					else if (i > 17){
						i = 12;
						framecounterpunch[0] = 1;
					}


				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 18;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 20){
						i = 18;
					}
					else if (i > 20){
						i = 18;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter3++;
					if (frameCounter3 > 15){
						i++;
						frameCounter3 = 0;
					}
					if (i > 5) i = 1; // loop sprite 1-5
				}
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//'''''''''''''''''''WALK'''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				if (playerPosition1X > 60) playerPosition1X -= 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 12;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 20 == 0){
						i++;


					}
					if (framecounterpunch[0]<240 && i > 14){
						i = 12;
					}
					else if (i > 17){
						i = 12;
						framecounterpunch[0] = 1;
					}
				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 18;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 20){
						i = 18;
					}
					else if (i > 20){
						i = 18;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter3++;
					if (frameCounter3 > 15){
						i++;
						frameCounter3 = 0;
					}
					if (i > 5) i = 1; // loop sprite 1-5
				}
			}
			else if ((GetAsyncKeyState('D') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN..............................
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounterpunch[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (framecounterrun[3] == 0) i = 6;
				if (playerPosition1X < 840) playerPosition1X += 2;
				framecounterrun[3] += 1;
				if (framecounterrun[3]>15){
					i++;
					framecounterrun[3] = 1;
				}
				if (i > 8) i = 6; // loop sprite 4-6
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN....................................
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounterpunch[0] = 0;
				framecounerthrow[0] = 0;
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				if (framecounterrun[3] == 0) i = 6;
				if (playerPosition1X > 60) playerPosition1X -= 2;
				framecounterrun[3]++;
				if (framecounterrun[3] > 15){
					i++;
					framecounterrun[3] = 1;
				}
				if (i > 8) i = 6; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(' ') & 0x8000)){//''''''''''''''''throw ICE'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 21;
				framecounerthrow[0]++;
				if (framecounerthrow[0] == 5) fire[0] = true;
				if (framecounerthrow[0] < 45){
					if (framecounerthrow[0] % 10 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}
			else if (!(GetAsyncKeyState(' ') & 0x8000) && (i == 21 || i == 22 || i == 23 || i == 24 || i == 25)){//''''''''''''''''throw ICE'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 21;
				framecounerthrow[0]++;
				if (framecounerthrow[0] < 45){
					if (framecounerthrow[0] % 10 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}
			else if ((GetAsyncKeyState('Q') & 0x8000)){//''''''''''''''''''''''''''''''''''''''''''PUNCH'''''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterpunch[0] == 0) i = 12;
				framecounterpunch[0]++;
				if (framecounterpunch[0] % 20 == 0){
					i++;


				}
				if (framecounterpunch[0]<240 && i > 14){
					i = 12;
				}
				else if (i > 17){
					i = 12;
					framecounterpunch[0] = 1;
				}


			}
			else if ((GetAsyncKeyState('E') & 0x8000)){//''''''''''''''''''''''''''''''KICK'''''''''''''''''''''''''''''
				framecounterrun[3] = 0;
				framecounterpunch[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterkick[0] == 0) i = 18;
				framecounterkick[0]++;
				if (framecounterkick[0] % 15 == 0){
					i++;
				}
				if (framecounterkick[0]<240 && i > 20){
					i = 18;
				}
				else if (i > 20){
					i = 18;
					framecounterkick[0] = 1;
				}
			}
			else if ((GetAsyncKeyState('F') & 0x8000)){//'''''''''''''''''''''''''''''''''BLOCK""""""""""""""""""""""""""""""""'
				framecounterrun[3] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterblock[0] == 0) i = 54;
				framecounterblock[0]++;
				if ((framecounterblock[0] / 15) % 2 == 1) i = 55;
				else if ((framecounterblock[0] / 15) % 2 == 0) i = 54;
			}
			else{
				i = 0;
				framecounterrun[3] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
			}
		}

	}
	//player 2 handle''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	if (a == 2){
		if (health2 == 0){
			j = 42;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 1 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (fire[1]){
				n = 59;
				timecounterfireball[1]++;
				if (p2rightface && timecounterfireball[1] < 2){
					firewidth1 = -70;
					fireX2 = playerPosition2X - 40;
					fireflag[1] = true;
				}
				if (p2leftface && timecounterfireball[1]<2){
					firewidth1 = +70;
					fireX2 = playerPosition2X + 40;
					fireflag[1] = false;

				}
				if (fireflag[1]) fireX2 -= 6;
				else  fireX2 += 6;
				//DaMAGE ER KAAJJJJ"'''''''''''''''''''''''''''''''''
				if (p1leftface && fireX2 > playerPosition1X + p1width && fireX2 < playerPosition1X + 30 && playerPosition1Y - 10 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 8;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;

				}
				if (p1rightface && fireX2>playerPosition1X + 30 && fireX2 < playerPosition1X + p1width + 20 && playerPosition1Y - 10 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 8;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;
				}
				if (fireX2>900 || fireX2 < 0 || collision[1]){
					fire[1] = false;
					timecounterfireball[1] = 0;
					fireX2 = 1000;
					collision[1] = false;
				}

			}
			if ((GetAsyncKeyState(VK_UP) & 0x8000)){//JUMP''''''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 9;
				else j = 10;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;

				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}
				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}
			else if (!(GetAsyncKeyState(VK_UP) & 0x8000) && playerPosition2Y > ground){//'''''''''''''''''''''''''''JUMP'''''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 9;
				else j = 10;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi high
				}

				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;
				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}

				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}
			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//walk'''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (playerPosition2X < 840) playerPosition2X += 1;
				if ((GetAsyncKeyState('L') & 0x8000)){
					if (framecounterpunch[1] == 0) j = 12;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 20 == 0){
						j++;


					}
					if (framecounterpunch[1]<240 && j > 14){
						j = 12;
					}
					else if (j > 17){
						j = 12;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 18;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 20){
						j = 18;
					}
					else if (j > 20){
						j = 18;
						framecounterkick[1] = 1;
					}
				}
				else{
					framecounterpunch[1] = 0;
					framecounterkick[1] = 0;
					frameCounter4++;
					if (frameCounter4 > 15){
						j++;
						frameCounter4 = 0;
					}
					if (j > 5) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//''''''''''''''''''''''''''''WALK''''''''''''''''
				framecounterrun[2] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (playerPosition2X > 60) playerPosition2X -= 1;
				if ((GetAsyncKeyState('L') & 0x8000)){
					if (framecounterpunch[1] == 0) j = 12;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 20 == 0){
						j++;


					}
					if (framecounterpunch[1]<240 && j > 14){
						j = 12;
					}
					else if (j > 17){
						j = 12;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 18;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 20){
						j = 18;
					}
					else if (j > 20){
						j = 18;
						framecounterkick[1] = 1;
					}
				}
				else{
					framecounterpunch[1] = 0;
					framecounterkick[1] = 0;
					frameCounter4++;
					if (frameCounter4 > 15){
						j++;
						frameCounter4 = 0;
					}
					if (j > 5) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//LtoR RUNNN.......................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (framecounterrun[2] == 0) j = 6;
				if (playerPosition2X < 840) playerPosition2X += 2;
				framecounterrun[2]++;
				if (framecounterrun[2]>15){
					j++;
					framecounterrun[2] = 1;
				}
				if (j > 8) j = 6; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//RtoL RUNNNNN................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (framecounterrun[2] == 0) j = 6;
				if (playerPosition2X > 60) playerPosition2X -= 2;
				framecounterrun[2]++;
				if (framecounterrun[2] > 15){
					j++;
					framecounterrun[2] = 1;
				}
				if (j > 8) j = 6; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState('J') & 0x8000)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 21;
				framecounerthrow[1]++;
				if (framecounerthrow[1] == 5) fire[1] = true;
				if (framecounerthrow[1] < 45){
					if (framecounerthrow[1] % 10 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}
			else if (!(GetAsyncKeyState('J') & 0x8000) && (j == 21 || j == 22 || j == 23 || j == 24 || j == 25)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 21;
				framecounerthrow[1]++;
				if (framecounerthrow[1] < 50){
					if (framecounerthrow[1] % 10 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}

			else if ((GetAsyncKeyState('L') & 0x8000)){//'''''''''''''''''''''''''''PUNCH'''''''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterpunch[1] == 0) j = 12;
				framecounterpunch[1]++;
				if (framecounterpunch[1] % 20 == 0){
					j++;


				}
				if (framecounterpunch[1]<240 && j > 14){
					j = 12;
				}
				else if (j > 17){
					j = 12;
					framecounterpunch[1] = 1;
				}


			}
			else if ((GetAsyncKeyState('I') & 0x8000)){//''''''''''''''''''''''''''''KICK'''''''''''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterpunch[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterkick[1] == 0) j = 18;
				framecounterkick[1]++;
				if (framecounterkick[1] % 15 == 0){
					j++;
				}
				if (framecounterkick[1]<240 && j > 20){
					j = 18;
				}
				else if (j > 20){
					j = 18;
					framecounterkick[1] = 1;
				}
			}
			else if ((GetAsyncKeyState('O') & 0x8000)){//''''''''''''''''''''''''''block'''''''''''''''''''''''''''
				framecounterrun[2] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterblock[1] == 0) j = 54;
				framecounterblock[1]++;
				if ((framecounterblock[1] / 15) % 2 == 1) j = 55;
				else if ((framecounterblock[1] / 15) % 2 == 0) j = 54;
			}
			else{
				j = 0;
				framecounterrun[2] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
			}

		}
	}


}
void displayRudolf(int a){
	if (a == 1){
		if (health1 == 0){
			i = 42;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 2 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (fire[0]){
				m = 57;
				timecounterfireball[0]++;
				if (p1rightface && timecounterfireball[0] < 2){
					firewidth1 = 70;
					fireX1 = playerPosition1X + 40;
					fireflag[0] = true;
				}
				if (p1leftface && timecounterfireball[0]<2){
					firewidth1 = -70;
					fireX1 = playerPosition1X - 40;
					fireflag[0] = false;

				}
				if (fireflag[0]) fireX1 += 7;
				else  fireX1 -= 7;
				//damage er kaaj
				if (p2rightface && fireX1 > playerPosition2X + p2width  && fireX1 < playerPosition2X && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 7;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;

				}
				if (p2leftface && fireX1>playerPosition2X - 30 && fireX1 < playerPosition2X + p2width && playerPosition2Y - 10 < fireY1){
					if (!(GetAsyncKeyState('O') & 0x8000)){
						health2 -= 7;
					}
					if (health2<0){
						health2 = 0;
					}
					collision[0] = true;
				}
				if (fireX1>900 || fireX1 < 0 || collision[0]){
					fire[0] = false;
					timecounterfireball[0] = 0;
					fireX1 = 1000;
					collision[0] = false;
				}

			}
			if ((GetAsyncKeyState('W') & 0x8000)){//'''''''''''''''''''''''JUMP'''''''''''''''''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 9;
				else i = 10;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}
			else if (!(GetAsyncKeyState('W') & 0x8000) && playerPosition1Y > ground){//''''''''''''''''''''''''''''''JUMP'''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				framecounterjump[0]++;
				t = framecounterjump[0] / 10;
				if (t < 1) i = 9;
				else i = 10;
				if (framecounterjump[0] % 10 == 0){
					playerPosition1Y = ground + 50 * t - 5 * t*t;//s=ut-0.5at^2 formula a=10dhorsi high
				}
				if (GetAsyncKeyState('D') & 0x8000){
					if (p1leftface){
						p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
					}
					if (playerPosition1X < 840) playerPosition1X += 1;

				}
				else if (GetAsyncKeyState('A') & 0x8000){
					if (p1rightface){
						p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
					}
					if (playerPosition1X > 60) playerPosition1X -= 1;

				}
				if (playerPosition1Y <= ground){
					playerPosition1Y = ground;
					i = 0;
					if (t >= 1) framecounterjump[0] = 0;
				}

			}
			else if ((GetAsyncKeyState('D') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//walk'''''''''''''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (playerPosition1X < 840) playerPosition1X += 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 13;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 20 == 0){
						i++;

					}
					if (framecounterpunch[0]<240 && i > 13){
						i = 11;
					}
					else if (i > 21){
						i = 11;
						framecounterpunch[0] = 1;
					}


				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 14;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 21){
						i = 14;
					}
					else if (i > 21){
						i = 14;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter5++;
					if (frameCounter5 > 15){
						i++;
						frameCounter5 = 0;
					}
					if (i > 4) i = 1; // loop sprite 1-5
				}
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && !(GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//walk''''''''''''''''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				if (playerPosition1X > 60) playerPosition1X -= 1;
				if ((GetAsyncKeyState('Q') & 0x8000)){
					if (framecounterpunch[0] == 0) i = 13;
					framecounterpunch[0]++;
					if (framecounterpunch[0] % 20 == 0){
						i++;

					}
					if (framecounterpunch[0]<240 && i > 13){
						i = 11;
					}
					else if (i > 21){
						i = 11;
						framecounterpunch[0] = 1;
					}


				}
				else if ((GetAsyncKeyState('E') & 0x8000)){
					if (framecounterkick[0] == 0) i = 14;
					framecounterkick[0]++;
					if (framecounterkick[0] % 15 == 0){
						i++;
					}
					if (framecounterkick[0]<240 && i > 21){
						i = 14;
					}
					else if (i > 21){
						i = 14;
						framecounterkick[0] = 1;
					}
				}
				else{
					framecounterpunch[0] = 0;
					framecounterkick[0] = 0;
					frameCounter5++;
					if (frameCounter5 > 15){
						i++;
						frameCounter5 = 0;
					}
					if (i > 4) i = 1; // loop sprite 1-5
				}
			}
			else if ((GetAsyncKeyState('D') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN..............................
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1leftface){
					p1width = -p1width, p1leftface = false, p1rightface = true, playerPosition1X -= 30;
				}
				if (framecounterrun[4] == 0) i = 5;
				if (playerPosition1X < 840) playerPosition1X += 2;
				framecounterrun[4] += 1;
				if (framecounterrun[4]>15){
					i++;
					framecounterrun[4] = 1;
				}
				if (i > 7) i = 5; // loop sprite 4-6
			}
			else if ((GetAsyncKeyState('A') & 0x8000) && (GetAsyncKeyState(VK_LSHIFT) & 0x8000)){//RUN....................................
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (p1rightface){
					p1width = -p1width, p1leftface = true, p1rightface = false, playerPosition1X += 30;
				}
				if (framecounterrun[4] == 0) i = 5;
				if (playerPosition1X > 60) playerPosition1X -= 2;
				framecounterrun[4]++;
				if (framecounterrun[4] > 15){
					i++;
					framecounterrun[4] = 1;
				}
				if (i > 7) i = 5; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(' ') & 0x8000)){//''''''''''''''''throw NINJASTAR'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 22;
				framecounerthrow[0]++;
				if (framecounerthrow[0] == 5) fire[0] = true;
				if (framecounerthrow[0] < 50){
					if (framecounerthrow[0] % 20 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}
			else if (!(GetAsyncKeyState(' ') & 0x8000) && (i == 22 || i == 23 || i == 24)){//''''''''''''''''throw NINJASTAR'''''''''''''''''''''''''''
				if (framecounerthrow[0] == 0) i = 22;
				framecounerthrow[0]++;
				if (framecounerthrow[0] < 50){
					if (framecounerthrow[0] % 20 == 0){
						i++;
					}
				}
				else
				{
					i = 0;
				}

			}
			else if ((GetAsyncKeyState('Q') & 0x8000)){//PUNCH'''''''''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterpunch[0] == 0) i = 13;
				framecounterpunch[0]++;
				if (framecounterpunch[0] % 20 == 0){
					i++;

				}
				if (framecounterpunch[0]<240 && i > 13){
					i = 11;
				}
				else if (i > 21){
					i = 11;
					framecounterpunch[0] = 1;
				}


			}
			else if ((GetAsyncKeyState('E') & 0x8000)){//''''''''''''''''''''''''''''''KICK'''''''''''''''''''''''''''''''''
				framecounterrun[4] = 0;
				framecounterpunch[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterkick[0] == 0) i = 14;
				framecounterkick[0]++;
				if (framecounterkick[0] % 15 == 0){
					i++;
				}
				if (framecounterkick[0]<240 && i > 21){
					i = 14;
				}
				else if (i > 21){
					i = 14;
					framecounterkick[0] = 1;
				}
			}
			else if ((GetAsyncKeyState('F') & 0x8000)){//""""""""""""""""""""""BLOCK""""""""""""""""""""""""'
				framecounterrun[4] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounerthrow[0] = 0;
				if (framecounterblock[0] == 0) i = 52;
				framecounterblock[0]++;
				if ((framecounterblock[0] / 15) % 2 == 1) i = 53;
				else if ((framecounterblock[0] / 15) % 2 == 0) i = 52;
			}

			else{
				i = 0;
				framecounterrun[4] = 0;
				framecounterpunch[0] = 0;
				framecounterkick[0] = 0;
				framecounterjump[0] = 0;
				framecounterblock[0] = 0;
				framecounerthrow[0] = 0;
			}
		}

	}
	//player 2 handle''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	if (a == 2){
		if (health2 == 0){
			j = 42;
			result++;
			if (result > 300){
				iSetColor(149, 143, 156);
				iFilledRectangle(200, 100, 500, 300);
				iSetColor(0, 0, 0);
				iText(230, 250, "PLAYER 1 WON!!!!!!\n Enter C To Continue", GLUT_BITMAP_TIMES_ROMAN_24);
				if (GetAsyncKeyState('C') & 0x8000){
					inGame = false;
					homeFlag = true;

				}
			}
		}
		else{
			if (fire[1]){
				n = 57;
				timecounterfireball[1]++;
				if (p2rightface && timecounterfireball[1] < 2){
					firewidth = -70;
					fireX2 = playerPosition2X - 40;
					fireflag[1] = true;
				}
				if (p2leftface && timecounterfireball[1]<2){
					firewidth = +70;
					fireX2 = playerPosition2X + 40;
					fireflag[1] = false;

				}
				if (fireflag[1]) fireX2 -= 7;
				else  fireX2 += 7;
				//DaMAGE ER KAAJJJJ"'''''''''''''''''''''''''''''''''
				if (p1leftface && fireX2 > playerPosition1X + p1width - 30 && fireX2 < playerPosition1X - 30 && playerPosition1Y - 10 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 7;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;

				}
				if (p1rightface && fireX2>playerPosition1X - 30 && fireX2 < playerPosition1X + p1width - 10 && playerPosition1Y - 30 < fireY2){
					if (!(GetAsyncKeyState('F') & 0x8000)){
						health1 -= 7;
					}
					if (health1<0){
						health1 = 0;
					}
					collision[1] = true;
				}
				if (fireX2>900 || fireX2 < 0 || collision[1]){
					fire[1] = false;
					timecounterfireball[1] = 0;
					fireX2 = 1000;
					collision[1] = false;
				}

			}
			if ((GetAsyncKeyState(VK_UP) & 0x8000)){//'''''''''''''''''''''''''''''JUMP''''''''''''''''''''''''''''''''''''''''''''
				framecounterrun[5] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 9;
				else j = 10;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi
				}
				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;

				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}
				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}
			else if (!(GetAsyncKeyState(VK_UP) & 0x8000) && playerPosition2Y > ground){//'''''''''''''''''''''''''''''''''''''JUMP'''''''''''''''''''''''''
				framecounterrun[5] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				framecounterjump[1]++;
				s = framecounterjump[1] / 10;
				if (s < 1) j = 9;
				else j = 10;
				if (framecounterjump[1] % 10 == 0){
					playerPosition2Y = ground + 50 * s - 5 * s*s;//s=ut-0.5at^2 formula a=10dhorsi high
				}

				if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)){
					if (p2rightface){
						p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
					}
					if (playerPosition2X < 840) playerPosition2X += 1;
				}
				else if ((GetAsyncKeyState(VK_LEFT) & 0x8000)){
					if (p2leftface){
						p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
					}
					if (playerPosition2X > 60) playerPosition2X -= 1;
				}

				if (playerPosition2Y <= ground){
					playerPosition2Y = ground;
					j = 0;
					if (s >= 1) framecounterjump[1] = 0;
				}

			}
			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//'''''''''''''''WALK'''''''''''''''''''''
				framecounterrun[5] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (playerPosition2X < 840) playerPosition2X += 1;
				if ((GetAsyncKeyState('L') & 0x8000)){//PUNCH
					if (framecounterpunch[1] == 0) j = 13;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 20 == 0){
						j++;

					}
					if (framecounterpunch[1]<240 && j > 13){
						j = 11;
					}
					else if (j > 21){
						j = 11;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 14;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 21){
						j = 14;
					}
					else if (j > 21){
						j = 14;
						framecounterkick[1] = 1;
					}
				}

				else{
					framecounterpunch[1] = 0;
					framecounterkick[1] = 0;
					frameCounter4++;
					if (frameCounter4 > 15){
						j++;
						frameCounter4 = 0;
					}
					if (j > 4) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//RtoLWALK
				framecounterrun[5] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (playerPosition2X > 60) playerPosition2X -= 1;
				if ((GetAsyncKeyState('L') & 0x8000)){//PUNCH
					if (framecounterpunch[1] == 0) j = 13;
					framecounterpunch[1]++;
					if (framecounterpunch[1] % 20 == 0){
						j++;

					}
					if (framecounterpunch[1]<240 && j > 13){
						j = 11;
					}
					else if (j > 21){
						j = 11;
						framecounterpunch[1] = 1;
					}


				}
				else if ((GetAsyncKeyState('I') & 0x8000)){
					if (framecounterkick[1] == 0) j = 14;
					framecounterkick[1]++;
					if (framecounterkick[1] % 15 == 0){
						j++;
					}
					if (framecounterkick[1]<240 && j > 21){
						j = 14;
					}
					else if (j > 21){
						j = 14;
						framecounterkick[1] = 1;
					}
				}
				else{
					framecounterpunch[1] = 0;
					framecounterkick[1] = 0;
					frameCounter4++;
					if (frameCounter4 > 15){
						j++;
						frameCounter4 = 0;
					}
					if (j > 4) j = 1; // loop sprite 1-3
				}
			}
			else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//LtoR RUNNN.......................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2rightface){
					p2width = -p2width, p2leftface = true, p2rightface = false, playerPosition2X -= 30;
				}
				if (framecounterrun[5] == 0) j = 5;
				if (playerPosition2X < 840) playerPosition2X += 2;
				framecounterrun[5]++;
				if (framecounterrun[5]>15){
					j++;
					framecounterrun[5] = 1;
				}
				if (j > 7) j = 5; // loop sprite 1-3
			}
			else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && (GetAsyncKeyState(VK_RCONTROL) & 0x8000)){//RtoL RUNNNNN................................
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (p2leftface){
					p2width = -p2width, p2leftface = false, p2rightface = true, playerPosition2X += 30;
				}
				if (framecounterrun[5] == 0) j = 5;
				if (playerPosition2X > 60) playerPosition2X -= 2;
				framecounterrun[5]++;
				if (framecounterrun[5] > 15){
					j++;
					framecounterrun[5] = 1;
				}
				if (j > 7) j = 5; // loop sprite 1-3

			}
			else if ((GetAsyncKeyState('J') & 0x8000)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 22;
				framecounerthrow[1]++;
				if (framecounerthrow[1] == 5) fire[1] = true;
				if (framecounerthrow[1] < 50){
					if (framecounerthrow[1] % 20 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}
			else if (!(GetAsyncKeyState('J') & 0x8000) && (j == 22 || j == 23 || j == 24)){//''''''''''''''''throw fire'''''''''''''''''''''''''''
				if (framecounerthrow[1] == 0) j = 22;
				framecounerthrow[1]++;
				if (framecounerthrow[1] < 50){
					if (framecounerthrow[1] % 20 == 0){
						j++;
					}
				}
				else
				{
					j = 0;
				}

			}
			else if ((GetAsyncKeyState('L') & 0x8000)){//PUNCH''''''''''''''''''''''''''''''''
				framecounterrun[5] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterpunch[1] == 0) j = 13;
				framecounterpunch[1]++;
				if (framecounterpunch[1] % 20 == 0){
					j++;

				}
				if (framecounterpunch[1]<240 && j > 13){
					j = 11;
				}
				else if (j > 21){
					j = 11;
					framecounterpunch[1] = 1;

				}


			}
			else if ((GetAsyncKeyState('I') & 0x8000)){//'''''''''''''''''''''''''''KICK''''''''''''''''''''''''''''''''
				framecounterrun[5] = 0;
				framecounterpunch[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterkick[1] == 0) j = 14;
				framecounterkick[1]++;
				if (framecounterkick[1] % 15 == 0){
					j++;
				}
				if (framecounterkick[1]<240 && j > 21){
					j = 14;
				}
				else if (j > 21){
					j = 14;
					framecounterkick[1] = 1;
				}
			}
			else if ((GetAsyncKeyState('O') & 0x8000)){//BLOCK"""""""""""""""""""""""""""""""""""""""""""
				framecounterrun[5] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounerthrow[1] = 0;
				if (framecounterblock[1] == 0) j = 52;
				framecounterblock[1]++;
				if ((framecounterblock[1] / 15) % 2 == 1) j = 53;
				else if ((framecounterblock[1] / 15) % 2 == 0) j = 52;
			}
			else{
				j = 0;
				framecounterrun[5] = 0;
				framecounterpunch[1] = 0;
				framecounterkick[1] = 0;
				framecounterjump[1] = 0;
				framecounterblock[1] = 0;
				framecounerthrow[1] = 0;
			}

		}
	}


}
void displayHenry(int a){
	if (a == 1){

	}
	else if (a == 2){

	}

}
void iDraw()
{
	iClear();
	if (introFlag){
		introDisplay();
	}
	else if (loadingFlag){
		loadingDisplay();
		iDelay(1);
	}
	else if (homeFlag){
		displayHome();

	}
	else if (startFlag){
		iShowImage(0, 0, 900, 500, selectionPage);
		if (player1ProfileFlag[0]){
			iShowImage(225, 310, 130, 130, profilePic[0]);
			iText(260, 273, "FIREN",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player1ProfileFlag[1]){
			iShowImage(225, 310, 130, 130, profilePic[1]);
			iText(225, 273, "FREEZEMAN", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player1ProfileFlag[2]){
			iShowImage(225, 310, 130, 130, profilePic[2]);
			iText(250, 273, "RUDOLF", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player1ProfileFlag[3]){
			iShowImage(225, 310, 130, 130, profilePic[3]);
			iText(255, 273, "HENRY", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (player2ProfileFlag[0]){
			iShowImage(670, 310, 130, 130, profilePic[0]);
			iText(705, 273, "FIREN", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player2ProfileFlag[1]){
			iShowImage(670, 310, 130, 130, profilePic[1]);
			iText(670, 273, "FREEZEMAN", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player2ProfileFlag[2]){
			iShowImage(670, 310, 130, 130, profilePic[2]);
			iText(695, 273, "RUDOLF", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (player2ProfileFlag[3]){
			iShowImage(670, 310, 130, 130, profilePic[3]);
			iText(690, 273, "HENRY", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (circleFlag[0]){
			iShowImage(310, 125, 30, 30, circle);
		}
		else if (circleFlag[1]){
			iShowImage(505, 125, 30, 30, circle);
		}
			
	}
	else if (settingFlag){
		//INSTRUCTION BUTTON ER KAJ EKHNE LEKHO
	}
	else if (instructionFlag){
		//INSTUCTION BUTTON ER KAJ EKHNE LEKHO
	}
	else if (aboutUsFlag){
		iShowImage(0, 0, 900, 500, aboutUs);

	}
	else if (inGame){
		if (circleFlag[0]){
			iShowImage(0, 0, 900, 500, bg1);
			iSetColor(255, 0, 0);
			iFilledRectangle(55, 435, 160, 20);
			iFilledRectangle(685, 435, 160, 20);
			iSetColor(0, 191, 0);
			iFilledRectangle(55, 435, health1, 20);
			iFilledRectangle(685, 435, health2, 20);

		}
		else if (circleFlag[1]){
			iShowImage(0, 0, 900, 500, bg2);
			iSetColor(255, 0, 0);
			iFilledRectangle(55, 435, 160, 20);
			iFilledRectangle(685, 435, 160, 20);
			iSetColor(0, 191, 0);
			iFilledRectangle(55, 435, health1, 20);
			iFilledRectangle(685, 435, health2, 20);

		}
		iShowImage(playerPosition1X, playerPosition1Y, p1width, p1height,sprite[playerChar1][i]);
		iShowImage(playerPosition2X, playerPosition2Y, p2width, p2height, sprite[playerChar2][j]);
		if (fire[0]){
			iShowImage(fireX1, fireY1, firewidth , 40, sprite[playerChar1][m]);
		}
		if (fire[1]){
			iShowImage(fireX2, fireY2, firewidth1 , 40, sprite[playerChar2][n]);
		}

		if(playerChar1 == 0){
			displayFiren(1);
		}
		else if (playerChar1 == 1){
			displayFreeze(1);
		}
		else if (playerChar1 == 2){
			displayRudolf(1);
		}
		else if (playerChar1 == 3){
			displayHenry(1);
		}

		if (playerChar2 == 0){
			displayFiren(2);
		}
		else if (playerChar2 == 1){
			displayFreeze(2);
		}
		else if (playerChar2 == 2){
			displayRudolf(2);
		}
		else if (playerChar2 == 3){
			displayHenry(2);
		}
	}
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//ipassiveMouse//
void iPassiveMouseMove(int mx, int my)
{
		homeHoverEffect(mx,my);
	
	


}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//LOADING PAGE MOUSE CLICK KRLE OFF KORAR JONNO
		//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
		if (loadingFlag){
			if (loadingKey == false) loadingFlag = false;
		}
		//HOMEPAGE ER BUTTON HANDLE
		//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
		else if (homeFlag){
			handleButtonOfHomepage(mx, my);
		}
		else if (startFlag){
			handlePlayer1Selection(mx, my);
			handlePlayer2Selection(mx, my);	
			if (mx > 180 && mx<335 && my>60 && my<150){
				circleFlag[0] = true;
				circleFlag[1] = false;
			}
			else if (mx > 375 && mx<530 && my>60 && my<150){
				circleFlag[0] = false;
				circleFlag[1] = true;
			}
			ReadyButton(mx, my);
		}
		else if (aboutUsFlag){
			if (mx > 780 && mx<900 && my>0 && my < 40){
				PlaySound("backSound.wav", NULL, SND_FILENAME | SND_ASYNC);
				aboutUsFlag = false;
				homeFlag = true;
			}
		}


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ' && loadingKey == false)
	{
		loadingFlag = false;
	}
	
}



/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	if (key == GLUT_KEY_UP)
	{
			
	}
	if (key == GLUT_KEY_DOWN)
	{
		
	}
	if (key == GLUT_KEY_HOME)
	{

	}

}



int main()
{
	iSetTimer(3000, introFunction);
	///srand((unsigned)time(NULL));
	iInitialize(900, 500, "FLAME VS FROST");
	
	//INTRO ER PIC LOAD
	//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	Intro = iLoadImage("Intro.bmp");
	//LOADING PAGE ER PIC LOAD
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	loading[0] = iLoadImage("L1.jpg");
	loading[1] = iLoadImage("L2.jpg");
	loading[2] = iLoadImage("L3.jpg");
	loading[3] = iLoadImage("L4.jpg");
	loading[4] = iLoadImage("L5.jpg");
	loading[5] = iLoadImage("L6.jpg");
	loading[6] = iLoadImage("L7.jpg");
	loading[7] = iLoadImage("L8.jpg");
	//BUTTONS ER PIC LOAD
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	char fileName[50];
	
	for (int i = 0; i < 5; i++){
		sprintf_s(fileName,"B%d.png",i + 1);
		B[i] = iLoadImage(fileName);
		sprintf_s(fileName, "B%dH.png", i + 1);
		BH[i] = iLoadImage(fileName);
	}
	//HOME PAGE ER PIC LOAD
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Home = iLoadImage("Home.jpg");
	//ABOUTUS ER PIC LOAD
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	aboutUs = iLoadImage("aboutUs.png");
	//SELECTION PAGE ER PIC LOAD
	//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	selectionPage = iLoadImage("selectionPage.jpg");
	profilePic[0] = iLoadImage("firenProfile.jpg");
	profilePic[1] = iLoadImage("freezeProfile.jpg");
	profilePic[2] = iLoadImage("rudolfProfile.jpg");
	profilePic[3] = iLoadImage("henryProfile.png");
	circle = iLoadImage("circle.png");
	//BACKGROUND LOAD
	bg1 = iLoadImage("MoonBg.jpg");
	bg2 = iLoadImage("FireBg.jpg");
	//Character image Load
	char spriteName[50];
	for (int i = 0; i < 63; i++){
		sprintf_s(spriteName, "firen//fi%d.png", i + 1);//firen LOAD
		sprite[0][i] = iLoadImage(spriteName);
	}
	for (int i = 0; i < 60; i++){
		sprintf_s(spriteName, "freeze//fr%d.png", i+1);//freezeman LOAD
		sprite[1][i] = iLoadImage(spriteName);
	}
	for (int i = 0; i < 58; i++){
		sprintf_s(spriteName, "rudolf//ru%d.png", i + 1);//Rudolf LOAD
		sprite[2][i] = iLoadImage(spriteName);
	}

	

	iStart();
	return 0;
}