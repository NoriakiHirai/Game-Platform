/*
*�@Program name: Game Platform
*�@Author: Hirai
*�@Date: 2018.06.06
*�@Overview: �R���\�[���ŗV�ׂ镡���̊ȒP�ȃQ�[����񋟂���v���b�g�t�H�[��
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
	printf("�Q�[���v���b�g�t�H�[���ւ悤�����I�I\n");
	while (isContinue) {
		printf("���Ȃ��͂ǂ̃Q�[���ŗV�т܂����H\n");
		printf("A�F���݂����AB�F����񂯂� [A/B] > ");
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
			printf("A��������B����͂��Ă��������B");
			break;
		}
		printf("\n");
		printf("�ēx�V�ԃQ�[����I������ꍇ��Y���A\n�Q�[�����I������ꍇ��N����͂��Ă��������B[Y/N] > ");
		scanf("%c", &choice);
		rewind(stdin);

		if (choice != 'Y') {
			isContinue = false;
		}
		printf("\n");
	}
	printf("�V��ł���Ă��肪�Ƃ��B\n�I������ɂ�Enter�L�[�������Ă�������...");
	rewind(stdin);
	getchar();
	return 0;
}

void omikuji()
{
	int fortuneKey;
	char fortune[7][5] = { "��g", "���g", "���g", "�g", "���g", "��", "�勥" };

	printf("���݂�����U��܂��̂ŁA�������Ǝv���Ƃ���Enter�������Ď~�߂Ă��������B\n");
	Sleep(500);
	printf("�����܁`���I\n");
	Sleep(500);
	while (1) {
		if (_kbhit()) {
			if (getch() == '\r')
				break;
		}
		printf("�W���J  ");
		Sleep(500);
	
	}
	printf("\n");
	printf("�|���I�I\n\n");

	//�����ɂ�邨�݂����z��(fortune)�̑�1�����𐶐�
	srand((unsigned)time(NULL));
	fortuneKey = rand() % 7 + 1;

	printf("���Ȃ��̉^����");
	Sleep(500);
	printf("�A");
	Sleep(500);
	printf("�A");
	Sleep(500);
	printf("�A");

	printf("%s!!!", fortune[fortuneKey - 1]);
	Sleep(1000);
	printf("�ł��B\n");
	printf("\n");
	//�Q�[���I�����̃C���^�[�o��
	Sleep(500);
}

void jankenController()
{
	char dispIMsg[25] = "����";
	char dispPutMsg[15] = "���o���܂����B";
	char choice;
	int winCount = 0;
	int result = 0;

	printf("����񂯂�Q�[���̎n�܂�ł��B\n");
	printf("�����ɉ����āA�̍������^����܂��B\n");
	printf("�ڎw��10���I�I\n");
	printf("\n");
	Sleep(500);

	//��߂��I������܂ŏ������J��Ԃ�
	bool isContinue = true;
	while (isContinue) {
		result = janken();
		winCount = winCount + result;
		printf("�ēx�ΐ킷��ꍇ��Y���A�ΐ����߂�ꍇ��N����͂��Ă��������B[Y/N] > ");
		scanf("%c", &choice);
		rewind(stdin);

		if (choice != 'Y') {
			isContinue = false;
		}
		printf("\n");
	}
	printf("\n");
	//�����ɉ����ď̍������^
	printf("�����l�ł��B�̍����^���s���܂��B\n");
	Sleep(1000);
	if (winCount < 3) {
		printf("���Ȃ��̂���񂯂�̘r�͏����ł��B\n");
	}
	else if (3 <= winCount && winCount < 7) {
		printf("���Ȃ��̂���񂯂�̘r�͒����ł��B\n");
	}
	else if (7 <= winCount && winCount < 10) {
		printf("���Ȃ��̂���񂯂�̘r�͏㋉�ł��B\n");
	}
	else if (10 <= winCount) {
		printf("���Ȃ��̂���񂯂�̘r�͖Ƌ��F�`�ł��B\n");
	}
	//�Q�[���I�����̃C���^�[�o��
	Sleep(500);
}

int janken()
{
	char handStr[3][7] = { "�O�[", "�`���L", "�p�[" };
	int myHand;
	int kachiboshi = 0;

	//�����̎�̑I��
	printf("���Ȃ����o�����I��ł��������B\n");
	printf("1:�O�[�A2:�`���L�A3:�p�[ [1/2/3] > ");
	scanf("%d", &myHand);
	rewind(stdin);

	printf("\n����񂯂���n�߂܂��B\n");
	Sleep(1000);
	printf("�ŏ��̓O�[");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	printf("\n");

	Sleep(500);
	printf("����񂯂�A");
	Sleep(500);
	printf("�|���I�I�I\n");


	//���������܂ŁA����񂯂���J��Ԃ�
	bool isDraw = true;
	while (isDraw) {
		int result;
		char dispIMsg[25] = "����";
		char dispPutMsg[15] = "���o���܂����B";

		//����̎�̑I��
		//����̎�͈ȉ��̐��l�����ꂼ��̎�ɐU��ւ���
		//1:�O�[�A2:�`���L�A3:�p�[
		int opponentHand;
		srand((unsigned)time(NULL));
		opponentHand = rand() % 3 + 1;
		Sleep(250);
		printHand(myHand, opponentHand);

		//����̃Z���t�̍���
		strcat(dispIMsg, handStr[opponentHand - 1]);
		strcat(dispIMsg, dispPutMsg);
		printf("\n%s\n", dispIMsg);

		//���s�̔���
		result = jankenHantei(myHand, opponentHand);
		printf("����񂯂�̌��ʂ�...");
		switch (result)
		{
		case 0:	//��������
			Sleep(1000);
			printf("��(߄D�;)\n");
			Sleep(1000);
			printf("�������ł��B\n");
			break;
		case 1:	//����
			Sleep(1000);
			printf("�i�@�s�D�s�j\n");
			Sleep(1000);
			printf("�����܂����B���Ȃ��̏����ł��B\n");
			kachiboshi = 1;
			isDraw = false;
			break;
		case 2:	//����
			Sleep(1000);
			printf("�S( ߁��)��\n");
			Sleep(1000);
			printf("�c�O�B���̏����ł��B\n");
			isDraw = false;
			break;
		default:
			break;
		}
		printf("\n");

		//�������̏ꍇ�̎����̎�̑I��
		if (isDraw == true) {
			printf("�ΐ�𑱂��܂��B�ēx�A���Ȃ����o�����I��ł��������B\n");
			printf("1:�O�[�A2:�`���L�A3:�p�[ [1/2/3] > ");
			scanf("%d", &myHand);
			rewind(stdin);

			printf("��������");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf("����I�I");
			printf("\n");
		}
	}
	Sleep(500);
	return kachiboshi;
}

/*
* jankenHantei
* 2�҂̎�(���l)���r���A���̑㏞�ɂ�菟�s�𔻒肵�A
* �ȉ��̐��l��ԋp����B
* @param myHand�F�����̎�
* @param opponentHand�F����̎�
* @return 0:��������
* 	   1:�����̏���
* 	   2:����̏���
*/
int jankenHantei(int myHand, int opponentHand)
{
	if (myHand == opponentHand) {
		return 0;
	}
	else if (myHand + 1 == opponentHand) {
		// �����������̏ꍇ
		return 1;
	}
	else if (myHand - 1 == opponentHand) {
		// �����������̏ꍇ
		return 2;
	}
	else {
		// ��L�܂ł̃��W�b�N�Ŕ���ł��Ȃ��ꍇ�A
		// ���̐�Βl�̍���2�ł���̂ŁA�ǂ��炩���O�[���p�[�Ƃ������ƂɂȂ�B
		// ���������āA���҂̑㏞���r���邾���ŏ��s������ł���B		
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