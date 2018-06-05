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

void omikuji(void);
void janken(void);
int jankenHantei(int myHand, int opponentHand);

int main(void)
{
	char choice;
	bool isContinue = true;

	printf("**************************\n");
	printf("*                        *\n");
	printf("*      Game Platform     *\n");
	printf("*                        *\n");
	printf("**************************\n");

	printf("\nゲームプラットフォームへようこそ！！\n");
	printf("あなたはどのゲームで遊びますか？\n");
	while (isContinue) {
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
			janken();
			break;
		default:
			printf("AもしくはBを入力してください。\n");
			break;
		}
		printf("\n再度遊ぶゲームを選択する場合はYを、\nゲームを終了する場合はNを入力してください。[Y/N] > ");
		scanf("%c", &choice);
		rewind(stdin);
		
		if (choice != 'Y') {
			isContinue = false;
		}
	}
	printf("\n遊んでくれてありがとう。\n終了するにはEnterキーを押してください...");
	rewind(stdin);
	getchar();
	return 0;
}

void omikuji()
{
	int fortuneKey;
	char dispStr[27] = "あなたの運勢は、";
	char dispStr_suffix[8] = "です。";
	char fortune[7][5] = { "大吉", "中吉", "小吉", "吉", "末吉", "凶", "大凶"};
	
	printf("おみくじを引きます。\n");
	//乱数によるおみくじ配列(fortune)の第1引数を生成
	srand((unsigned)time(NULL));
	fortuneKey = rand() % 7 + 1;

	//文字列の合成
	strcat(dispStr, fortune[fortuneKey - 1]);
	strcat(dispStr, dispStr_suffix);

	printf("%s", dispStr);
	printf("\n");
}

void janken()
{
	char dispIMsg[25] = "私は";
	char dispPutMsg[15] = "を出しました。";
	char handStr[3][7] = { "グー", "チョキ", "パー" };
	int myHand;
	printf("じゃんけんゲームの始まりです。\n");

	//自分の手の選択
	printf("あなたが出す手を選んでください。\n");
	printf("1:グー、2:チョキ、3:パー [1/2/3] > ");
	scanf("%d", &myHand);
	rewind(stdin);

	printf("\nじゃんけんを始めます。\n");
	Sleep(2000);
	printf("最初はグー...\n");
	Sleep(1000);
	printf("じゃんけん、ポン\n");

	//勝負がつくまで、じゃんけんを繰り返す
	bool isDraw = true;
	while (isDraw) {
		int result;

		//相手の手の選択
		//相手の手は以下の数値をそれぞれの手に振り替える
		//1:グー、2:チョキ、3:パー
		int opponentHand;
		srand((unsigned)time(NULL));
		opponentHand = rand() % 3 + 1;
		Sleep(2000);

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
		}
	}
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
	} else if (myHand + 1 == opponentHand) {
		// 自分が勝ちの場合
		return 1;
	} else if (myHand - 1 == opponentHand) {
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