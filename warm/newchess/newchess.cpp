#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstring>
using namespace std;

#define EXIT		4
#define NEWGAME		2
#define COMPUTER	3
#define YOU			1
#define BACK		5
#define MOVE		6
#define SWAPTURN	7
#define HIGHT		10
#define WIDTH		9
#define InMat(x,begin,end)	((x)>=begin&&(x)<end)
#define ValidPosition(x,y)	(InMat(x,0,HIGHT)&&InMat(y,0,WIDTH))	
#define abs(x)				((x)>=0?(x):-(x))
#define OneDis(a,b,c,d)		(abs(a-c)+abs(b-d)==1)

#define NOCHESS		0
#define B_KING		1
#define B_CAR		2
#define B_HORSE		3
#define B_CANON		4
#define B_BISHOP	5
#define B_ELEPHANT	6
#define B_PAWN		7
#define B_BEGIN		B_KING
#define B_END		B_PAWN
#define R_KING		8
#define R_CAR		9
#define R_HORSE		10
#define R_CANON		11
#define R_BISHOP	12
#define R_ELEPHANT	13
#define R_PAWN		14
#define R_BEGIN		R_KING
#define R_END		R_PAWN
#define IsBlack(x)	((x)>=B_BEGIN&&(x)<=B_END)
#define IsRed(x)	((x)>=R_BEGIN&&(x)<=R_END)
#define IsSameSide(x,y)	(IsBlack(x)&&IsBlack(y)||IsRed(x)&&IsRed(y))

#define SEARCH_DEPTH	4

typedef char elem_t;


//define a chess position
typedef struct _chessposition{
	int x,y;
}CHESSP;

//define a chess move
typedef struct _chessmove{
	CHESSP from,to;
}CHESSMOVE;

//define chess

typedef elem_t CHESS[HIGHT][WIDTH];
extern CHESS currChess;
extern CHESSMOVE allMove[SEARCH_DEPTH+1][80];
extern int moveCount[SEARCH_DEPTH+1];
extern CHESS myChess;
extern bool YouKingDie,ComputerKingDie;
extern int First;
extern CHESSMOVE bestmove;

int youMove(){
	int message;
	while(1){
		message=Mymessage.judgeMessage();
		if(message==EXIT||message==NEWGAME||message==SWAPTURN)
			return message;
		if(message==BACK){
			MyMoveGen.popChess();
			continue;
		}
		if(message==MOVE){
			MyMoveGen.moveChess(Mymessage.chessmove);
			break;
		}
	}
	return -1;
}

void computerMove(){
	chessSearch();
	MyMoveGen.moveChess(bestmove);
}

int Play(int first){
	int whoMove=first,whoWin,result;
	MyMoveGen.initChess(first);
	while(1){
		whoWin=IsOver();
		if(whoWin==YOU||whoWin==COMPUTER)break;
		if(whoMove==COMPUTER){
			computerMove();
			whoMove=YOU;
		}
		else {
			result=youMove();
			if(result==EXIT||result==NEWGAME)
				return result;
			whoMove=COMPUTER;
		}
		cout<<"Computer: "<<calcValue(myChess,0)<<endl;
		cout<<"You: "<<calcValue(myChess,1)<<endl;
	}
	outputWiner(whoWin);
	return -1;
}

int main(){
	int playTimes=0,message,first;
	bool start=false;
	while(1){
		if(playTimes){
			while(1){
				message=Mymessage.judgeMessage();
				if(message==EXIT)return 0;
				else if(message==NEWGAME){
					start=false;
					break;
				}
			}
		}
_NEWGAME:
		while(1){
			first=Mymessage.judgeMessage();
			if(first==EXIT)return 0;
			if(first==NEWGAME){
				start=false;
				break;
			}
			if(first==COMPUTER||first==YOU){
				start=true;
				break;
			}
		}
		if(!start)continue;
		First=first;
		message=Play(first);
		if(message==EXIT)break;
		if(message==NEWGAME)goto _NEWGAME;
		playTimes++;
	}
	return 0;
}