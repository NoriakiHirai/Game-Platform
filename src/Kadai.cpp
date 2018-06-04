#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void omikuji(void);
void junken(void);

int main(void)
{
	char choice;
	bool isContinue = true;

	printf("あなたはどちらで遊びますか？\n");

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
			printf("%c が選択されました。\n", choice);
			break;
		default:
			printf("AもしくはBを入力してください。\n");
			break;
		}

		printf("再度遊ぶゲームを選択する場合はYを、\nゲームを終了する場合はNを入力してください。[Y/N] > ");
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
	int lottery;
	srand((unsigned)time(NULL));
	lottery = rand() % 7 + 1;
	printf("おみくじを引きます。\nあなたの運勢は、");
	switch (lottery) {
	case 1:
		printf("大吉");
		break;
	case 2:
		printf("中吉");
		break;
	case 3:
		printf("小吉");
		break;
	case 4:
		printf("吉");
		break;
	case 5:
		printf("末吉");
		break;
	case 6:
		printf("凶");
		break;
	default:
		printf("大凶");
		break;
	}
	printf("です。\n\n");
}

void junken()
{
	char myHand;
	printf("じゃんけんゲームの始まりです。\n");

	//自分の手の選択
	printf("あなたが出す手を選んでください。\n");
	printf("A:グー、B:チョキ、C:パー [A/B/C] > ");
	scanf("%c", &myHand);

	//相手の手の選択
	int opponentHand;
	srand((unsigned)time(NULL));
	opponentHand = rand() % 3 + 1;

	printf("じゃんけんを始めます。\n");
	printf("最初はグー...\n");
	printf("じゃんけん、ポン\n");

	//相手の手は以下の数値をそれぞれの手に振り替える
	//1:グー、2:チョキ、3:パー
	switch (opponentHand)
	{
	case 1:	//相手の手がグーの場合
		break;
	case 2:	//相手の手がチョキの場合
		break;
	case 3:	//相手の手がパーの場合
		break;
	default:
		break;
	}
}