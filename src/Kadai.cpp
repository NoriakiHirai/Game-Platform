/*
*　Program name: Game Platform
*　Author: Hirai
*　Date: 2018.06.06
*　Overview: コンソールで遊べる複数の簡単なゲームを提供するプラットフォーム
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>

void omikuji(void);
void jankenController();
int janken(void);
int jankenHantei(int myHand, int opponentHand);
void printHand(int myHand, int opponentHand);
void printGoo();
void printChoki();
void printPaa();


int main(void)
{
	char choice;
	bool isContinue = true;

	printf("**************************\n");
	printf("*                        *\n");
	printf("*      Game Platform     *\n");
	printf("*                        *\n");
	printf("**************************\n");

	printf("\n");
	printf("ゲームプラットフォームへようこそ！！\n");
	while (isContinue) {
		printf("あなたはどのゲームで遊びますか？\n");
		printf("A：おみくじ、B：じゃんけん [A/B] > ");
		scanf("%c", &choice);
		rewind(stdin);

		printf("\n");
		switch (choice)
		{
		case 'A':
			omikuji();
			break;
		case 'B':
			jankenController();
			break;
		default:
			printf("AもしくはBを入力してください。");
			break;
		}
		printf("\n");
		printf("再度遊ぶゲームを選択する場合はYを、\nゲームを終了する場合はNを入力してください。[Y/N] > ");
		scanf("%c", &choice);
		rewind(stdin);

		if (choice != 'Y') {
			isContinue = false;
		}
		printf("\n");
	}
	printf("遊んでくれてありがとう。\n終了するにはEnterキーを押してください...");
	rewind(stdin);
	getchar();
	return 0;
}

void omikuji()
{
	int fortuneKey;
	char fortune[7][5] = { "大吉", "中吉", "小吉", "吉", "末吉", "凶", "大凶" };

	printf("おみくじを振りますので、ここだと思うときにEnterを押して止めてください。\n");
	Sleep(500);
	printf("いきま～す！\n");
	Sleep(500);
	while (1) {
		if (_kbhit()) {
			if (getch() == '\r')
				break;
		}
		printf("ジャカ  ");
		Sleep(500);
	
	}
	printf("\n");
	printf("ポン！！\n\n");

	//乱数によるおみくじ配列(fortune)の第1引数を生成
	srand((unsigned)time(NULL));
	fortuneKey = rand() % 7 + 1;

	printf("あなたの運勢は");
	Sleep(500);
	printf("、");
	Sleep(500);
	printf("、");
	Sleep(500);
	printf("、");

	printf("%s!!!", fortune[fortuneKey - 1]);
	Sleep(1000);
	printf("です。\n");
	printf("\n");
	//ゲーム終了時のインターバル
	Sleep(500);
}

void jankenController()
{
	char dispIMsg[25] = "私は";
	char dispPutMsg[15] = "を出しました。";
	char choice;
	int winCount = 0;
	int result = 0;

	printf("じゃんけんゲームの始まりです。\n");
	printf("勝数に応じて、称号が授与されます。\n");
	printf("目指せ10勝！！\n");
	printf("\n");
	Sleep(500);

	//やめるを選択するまで勝負を繰り返す
	bool isContinue = true;
	while (isContinue) {
		result = janken();
		winCount = winCount + result;
		printf("再度対戦する場合はYを、対戦をやめる場合はNを入力してください。[Y/N] > ");
		scanf("%c", &choice);
		rewind(stdin);

		if (choice != 'Y') {
			isContinue = false;
		}
		printf("\n");
	}
	printf("\n");
	//勝数に応じて称号を授与
	printf("お疲れ様です。称号授与を行います。\n");
	Sleep(1000);
	if (winCount < 3) {
		printf("あなたのじゃんけんの腕は初級です。\n");
	}
	else if (3 <= winCount && winCount < 7) {
		printf("あなたのじゃんけんの腕は中級です。\n");
	}
	else if (7 <= winCount && winCount < 10) {
		printf("あなたのじゃんけんの腕は上級です。\n");
	}
	else if (10 <= winCount) {
		printf("あなたのじゃんけんの腕は免許皆伝です。\n");
	}
	//ゲーム終了時のインターバル
	Sleep(500);
}

int janken()
{
	char handStr[3][7] = { "グー", "チョキ", "パー" };
	int myHand;
	int kachiboshi = 0;

	//自分の手の選択
	printf("あなたが出す手を選んでください。\n");
	printf("1:グー、2:チョキ、3:パー [1/2/3] > ");
	scanf("%d", &myHand);
	rewind(stdin);

	printf("\nじゃんけんを始めます。\n");
	Sleep(1000);
	printf("最初はグー");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	printf("\n");

	Sleep(500);
	printf("じゃんけん、");
	Sleep(500);
	printf("ポン！！！\n");


	//勝負がつくまで、じゃんけんを繰り返す
	bool isDraw = true;
	while (isDraw) {
		int result;
		char dispIMsg[25] = "私は";
		char dispPutMsg[15] = "を出しました。";

		//相手の手の選択
		//相手の手は以下の数値をそれぞれの手に振り替える
		//1:グー、2:チョキ、3:パー
		int opponentHand;
		srand((unsigned)time(NULL));
		opponentHand = rand() % 3 + 1;
		Sleep(250);
		printHand(myHand, opponentHand);

		//相手のセリフの合成
		strcat(dispIMsg, handStr[opponentHand - 1]);
		strcat(dispIMsg, dispPutMsg);
		printf("\n%s\n", dispIMsg);

		//勝敗の判定
		result = jankenHantei(myHand, opponentHand);
		printf("じゃんけんの結果は...");
		switch (result)
		{
		case 0:	//引き分け
			Sleep(1000);
			printf("Σ(ﾟДﾟ;)\n");
			Sleep(1000);
			printf("あいこです。\n");
			break;
		case 1:	//勝ち
			Sleep(1000);
			printf("（　ＴДＴ）\n");
			Sleep(1000);
			printf("負けました。あなたの勝ちです。\n");
			kachiboshi = 1;
			isDraw = false;
			break;
		case 2:	//負け
			Sleep(1000);
			printf("ヾ( ﾟ∀ﾟ)ﾉﾞ\n");
			Sleep(1000);
			printf("残念。私の勝ちです。\n");
			isDraw = false;
			break;
		default:
			break;
		}
		printf("\n");

		//あいこの場合の自分の手の選択
		if (isDraw == true) {
			printf("対戦を続けます。再度、あなたが出す手を選んでください。\n");
			printf("1:グー、2:チョキ、3:パー [1/2/3] > ");
			scanf("%d", &myHand);
			rewind(stdin);

			printf("あいこで");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf("しょ！！");
			printf("\n");
		}
	}
	Sleep(500);
	return kachiboshi;
}

/*
* jankenHantei
* 2者の手(数値)を比較し、その代償により勝敗を判定し、
* 以下の数値を返却する。
* @param myHand：自分の手
* @param opponentHand：相手の手
* @return 0:引き分け
* 	   1:自分の勝ち
* 	   2:相手の勝ち
*/
int jankenHantei(int myHand, int opponentHand)
{
	if (myHand == opponentHand) {
		return 0;
	}
	else if (myHand + 1 == opponentHand) {
		// 自分が勝ちの場合
		return 1;
	}
	else if (myHand - 1 == opponentHand) {
		// 自分が負けの場合
		return 2;
	}
	else {
		// 上記までのロジックで判定できない場合、
		// その絶対値の差は2であるので、どちらかがグーかパーということになる。
		// したがって、両者の代償を比較するだけで勝敗が判定できる。		
		if (myHand < opponentHand) {
			return 2;
		}
		else {
			return 1;
		}
	}
}

void printHand(int myHand, int opponentHand)
{
	int i;
	int handArray[2] = { myHand, opponentHand };
	for (i = 0; i < 2; i++) {
		switch (handArray[i])
		{
		case 1:
			printGoo();
			break;
		case 2:
			printChoki();
			break;
		case 3:
			printPaa();
			break;
		default:
			break;

		}
		printf("\n\n");
		Sleep(500);
		if (i == 0) {
			printf("V.S.");
			printf("\n\n");
		}
	}
	Sleep(250);
}

void printGoo()
{
	printf("\n"
		"      *******|******|******|*****|\n"
		"      *******|******|******|*****|\n"
		"      *******|******|******|*****|\n"
		"  *****?*****|******|******|*****|\n"
		" *******?*************************\n"
		"  *******?************************\n"
		"   *******?***********************\n"
		"    ******************************\n"
		"     *****************************\n"
		"      ****************************\n"
		"       ***************************\n"
		"        ************************* \n"
	);
}

void printChoki()
{
	printf("\n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"       ******  ******  \n"
		"  *****?************** \n"
		" *******?**************\n"
		"  *******?*************\n"
		"   *******?************\n"
		"    *******************\n"
		"     ******************\n"
		"      *****************\n"
		"       ****************\n"
		"        ************** \n"
	);
}

void printPaa()
{
	printf("\n"
		"       ******|******|******|*****|\n"
		"       ******|******|******|*****|\n"
		"       ******|******|******|*****|\n"
		"       ******|******|******|*****|\n"
		"       ******|******|******|*****|\n"
		"       ******|******|******|*****|\n"
		"       ***************************\n"
		"  *****?**************************\n"
		" *******?*************************\n"
		"  *******?************************\n"
		"   *******?***********************\n"
		"    ******************************\n"
		"     *****************************\n"
		"      ****************************\n"
		"       ***************************\n"
		"        ************************* \n"
	);
}