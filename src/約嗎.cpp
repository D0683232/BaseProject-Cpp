#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>


typedef struct users{
	char name[25];					
	char id[25];					
	char password[25];			
	char gender[25];			
	char position[50];				
	char phonenum;					
	int age;						
}User;

void singup(){
	User user;
	FILE *inptr = fopen("input.txt", "r"), *outptr = fopen("output.txt", "a"), *account = fopen("account.txt", "a");
	char name, id, paddword, gender, position, phonenum;
	int age;
	int choose = 0;
	
	printf("�m�W : ");
	scanf("%s", user.name);
	fprintf(outptr, "%s\t", user.name);
	
	printf("\n��� : ");
	scanf("%s", user.id);
	fprintf(account, "%s\t", user.id);
	
	printf("\n�K�X : ");
	scanf("%s", user.password);
	fprintf(account, "%s\n", user.password);
	
	while(choose != 1 && choose != 2){
		printf("\n�ʧO : ");
		printf("1. Male\t2. Female\n");
		scanf("%d", &choose);
		if(choose == 1){
			printf("�w��� ");
			 printf("Male\n");
			strcpy(user.gender, "Male");
			fprintf(outptr, "Male\t");
		}
		else if(choose == 2){
			printf("�w��� ");
			printf("Female\n");
			strcpy(user.gender, "Female");
			fprintf(outptr, "Female\t");
		}else{
			printf("�Э��s���");
		}
	}
	
	printf("\n��m : ");
	printf("�O�_�� �s�_�� �򶩥� ��饫 �s�˥�\n");
	printf("�s�˿� �]�X�� �O���� ���ƿ� �n�뿤\n");
	printf("���L�� �Ÿq�� �Ÿq�� �x�n�� ������\n");
	printf("�̪F�� �y���� �Ὤ�� �x�F�� ���\n");
	printf("������ �s����\n\n-------------------\n");
	scanf("%s", user.position);
	fprintf(outptr, "%s\t", user.position);
	
	printf("\n�~�� : ");
	scanf("%d", &user.age);
	fprintf(outptr, "%d\n", user.age);

	fclose(outptr);
	fclose(account);
}

int singin(){
	FILE *account = fopen("account.txt", "r");
	int flag, i = 1, j = 1, num = 1;
	User user;
	char id_check[1000], password_check[1000];
	
	HANDLE hOut;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	SetConsoleTextAttribute(hOut, FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//���� 
	printf("�п�J�ʺ�id : ");
	scanf("%s", id_check);
	printf("\n");
	printf("�п�J�K�X : ");
	scanf("%s", password_check);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
	
	i = 1;
	while(fscanf(account, "%s%s", user.id, user.password) != EOF){
		
		if(strcmp(id_check, user.id) == 0){
			if(strcmp(password_check, user.password) == 0){
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ�
				system("cls"); 
				printf("\n\n\n\n\n\t\t\t\t�n�J��"); 
				for(j = 0; j < 3; j++){
					printf(".");
					Sleep(1000);
				}
				system("cls");
				printf("\n\n\n\n\n\t\t\t\t�n�J����...");
				Sleep(1000);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
				fclose(account);
				return i;
			}
			else{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
				printf("\n\n\n\n\n\t\t\t\t�K�X���~�A�Э��s�n�J");
				Sleep(2000);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
				fclose(account);
				return 0;
			}
		} 
		i++;
		num++;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
	printf("\n\n\n\n\n\t\t\t\tid���~�A�Э��s�n�J");
	Sleep(2000); 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ�
	fclose(account);
	return 0;
}
	
	

 
int interest(){
	FILE *interest = fopen("interest.txt", "a");
	int choose = 0;
	char yesno[10];
	printf("�O�_��g�L���� ? Yes/No(���p�g�Y�i)\t");
	scanf("%s", yesno);
	if(yesno[0] >= 65 && yesno[0] <= 90){
			yesno[0] = yesno[0] + 32;
	}
	if(strcmp(yesno, "yes") ==  0){
		return 0;
	}
	else{
		printf("�A�O1.���V 2.�~�V ?\t");
		scanf("%d", &choose);
		if(choose == 1) fprintf(interest, "���V\t");
		else fprintf(interest, "�~�V\t");
		
		printf("�Aı�o�A�O 1.���R 2. ���� ?\t");
		scanf("%d", &choose);
		if(choose == 1) fprintf(interest, "���R\n");
		else fprintf(interest, "����\n");
	}
	fclose(interest);
}

void pair(int num){ //�t�� 
	HANDLE hOut;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE *account = fopen("account.txt", "r");
	int i = 1, people = 1, rand_;
	User user;
	char pair_people[25], useless[25], yesno[5], chatyesno[5], word[1000], word_[1000];
	
	while(fscanf(account, "%s%s", user.id, user.password) != EOF){
		people++;
	}
	
	fclose(account);
	account = fopen("account.txt", "r");
	
	while(i <= num){
		fscanf(account, "%s%s", user.id, user.password);
		i++;
	}
	
	fclose(account);
	account = fopen("account.txt", "r");
	
	srand(time(NULL));
	while(1){
		rand_ = (rand() % 1000) + 1;
		if(rand_ > people){
			
		}
		else if(rand_ != num) break;
	}
	
	i = 1;
	while(i <= rand_){
		fscanf(account, "%s%s", pair_people, useless);
		i++;
	}
	
	fclose(account);
	system("cls");
	
	printf("�O �_ �Q �M %s �� �� �n �� ? Yes/No(���p�g�Y�i)\t", pair_people);
	scanf("%s", yesno);
	system("cls");
	if(yesno[0] >= 65 && yesno[0] <= 90){
			yesno[0] = yesno[0] + 32;
	}
	if(strcmp(yesno, "yes") ==  0){
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
		printf("\n\n\n\n\n\t\t\t\t�[�n�ͤ�");
		for(i = 0; i < 3; i++){
			Sleep(1000);
			printf(".");
		}
		system("cls");
		Sleep(1000);
		printf("\n\n\n\n\n\t\t\t\t�K�[����...");
		Sleep(2000);	
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
		printf("�O �_ �Q �n �i �J �p �H �� �� �� ? Yes/No(���p�g�Y�i)\t"); //�p�H��ѫ� 
		scanf("%s",chatyesno);
		system("cls");
		if(chatyesno[0] >= 65 && chatyesno[0] <= 90){
			chatyesno[0] = chatyesno[0] + 32;
		}
		if(strcmp(chatyesno, "yes") ==  0){
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
			printf("\n\n\n\n\n\t\t\t\t�i�J��ѫǤ�");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls");
			printf("\t\t\t\t\t\t��ѫ�\t\t\t\t\t\t\t\n");
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
			printf("%s : ",user.id);
			word[1000] = NULL;
			scanf("%s",word);
			while(strcmp(word,"byebye") != 0 && strcmp(word_,"byebye") != 0){
				word_[1000] = NULL;
				printf("%s : ",pair_people);
				scanf("%s",word_);
				if(strcmp(word_,"byebye") == 0){
					break; 
				}
				else{
					word_[1000] = NULL;
				}
				word[1000] = NULL;
				printf("%s : ",user.id);
				scanf("%s",word);
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
			printf("\n\n\n\n\n\t\t\t\t�h�X��ѫǤ�");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls"); 
			printf("\n\n\n\n\n\t\t\t\t�h�X�����A�n�X��");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			Sleep(3000);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
		}     //�p�H��ѫ� 
		else if(strcmp(chatyesno,"no") == 0){
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
			printf("\n\n\n\n\n\t\t\t\t�n�X��");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			Sleep(3000);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
		}

	}
	else{
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
		printf("\n\n\n\n\n\t\t\t\t�S���K�[�n�͡A�Y�N�n�X\n");
		Sleep(3000);	
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t�n�X��");
		for(i = 0; i < 3; i++){
			Sleep(1000);
			printf(".");
		}
		Sleep(3000);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
	}
	
}

void chatroom(int num){ //���}��ѫ� 
	HANDLE hOut;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    
	FILE *account = fopen("account.txt", "r");
	int i = 1, people = 1, rand_;
	User user;
	char pair_people[25], useless[25], word[1000], word_[1000];
	
	while(fscanf(account, "%s%s", user.id, user.password) != EOF){
		people++;
	}
	
	fclose(account);
	account = fopen("account.txt", "r");
	
	while(i <= num){
		fscanf(account, "%s%s", user.id, user.password);
		i++;
	}
	
	fclose(account);
	
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
	printf("\t\t\t\t\t\t�i�J���}��ѫǤ�");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	Sleep(3000);
	system("cls");
	printf("\t\t\t\t\t\t���}��ѫ�\t\t\t\t\t\t\t\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ�  
	printf("%s : ",user.id);
	scanf("%s",word);
	while(strcmp(word,"byebye") != 0){
		account = fopen("account.txt", "r");
		srand(time(NULL));
		while(1){
			rand_ = (rand() % 1000) + 1;
			if(rand_ > people){
			
			}
			else if(rand_ != num) break;
		}
	
		i = 1;
		while(i <= rand_){
			fscanf(account, "%s%s", pair_people, useless);
			i++;
		}
	
		fclose(account);
		
		printf("%s : ",pair_people);
		scanf("%s",word_);
		word_[1000] = NULL;
		
		printf("%s : ",user.id);
		scanf("%s",word);
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
	printf("\n\n\n\n\n\t\t\t\t�h�X��ѫǤ�");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	system("cls"); 
	printf("\n\n\n\n\n\t\t\t\t�h�X�����A�n�X��");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	Sleep(3000);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
} 
int addfriend(int num){
	HANDLE hOut;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    
    FILE *account = fopen("account.txt", "r");
	int i = 1, people = 1;
	User user;
	User new_user;
	char pair_people[25], useless[25],add_id[25],yesno[5];
	
	while(fscanf(account, "%s%s", user.id, user.password) != EOF){
		people++;
	}
	
	fclose(account);
	account = fopen("account.txt", "r");
	
	while(i <= num){
		fscanf(account, "%s%s", user.id, user.password);
		i++;
	}
	
	fclose(account);
    printf("�п�J�A�Q�n�K�[���n�ͪ�id �G");
	scanf("%s",add_id);
	system("cls"); 
	people = 1;
    account = fopen("account.txt", "r");
    while(fscanf(account, "%s%s",new_user.id, new_user.password) != EOF){
    	if(strcmp(add_id,new_user.id) == 0){
    		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
    		printf("\n\n\n\n\n\t\t\t\t���b��id��%s���n�͵o�e�ШD",add_id);
    		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� */
    		for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls"); 
			Sleep(3000);
			printf("\n\n\nt\t\t\t%s��������G�Ӧ�%s���K�[�n�ͽШD�A�O�_�P�N ? Yes/No ?(���p�g�Y�i)\t",add_id,user.id);
			scanf("%s",yesno);
			system("cls");
			if(yesno[0] >= 65 && yesno[0] <= 90){
				yesno[0] = yesno[0] + 32;
			}
			if(strcmp(yesno,"yes") == 0){
				printf("\n\n\nt\t\t\t%s��������G�K�[�n�ͧ���...",user.id);
			}
			else{
				printf("\n\n\nt\t\t\t%s��������G�K�[�n�ͥ���",user.id);
			} 
    		break;
		}
		else{
			people++;
		}	
	}
	return people;
}
void chooserole1()	//�Ĥ@�ժ��a��ܨ��� 
{
	int player1,player2;
	
	printf("<�вĤ@�ժ��a�@��ܨ���ζH> \n1.�ʷP�p���~\n2.�i�R�p����\n3.�����k�k\n4.�������z�k(�k)\n\n�п��:");
	while(1)
	{
		scanf("%d",&player1);
		if(player1>4||player1<1) printf("��ܵL�ġA�Э��s��� :");
		else break;
	}	//���a�@��� 
	
	printf("\n<�вĤ@�ժ��a�G��ܨ���ζH> \n1.�ʷP�p���~\n2.�i�R�p����\n3.�����k�k\n4.�������z�k(�k)\n\n�п��:");
	while(1)
	{
		scanf("%d",&player2);
		if(player2==player1) printf("����w�Q�խ��ϥΡA�Э��s��� :");
		else if(player2>4||player2<1) printf("��ܵL�ġA�Э��s��� :");
		else break;
	}	//���a�G���
}

void chooserole2()	//�ĤG�ծa��ܨ��� 
{
	int player1,player2;
	printf("-----------------------------\n"); 
	printf("<�вĤG�ժ��a�@��ܨ���ζH> \n1.�ʷP�p���~\n2.�i�R�p����\n3.�����k�k\n4.�������z�k(�k)\n\n�п��:");
	while(1)
	{
		scanf("%d",&player1);
		if(player1>4||player1<1) printf("��ܵL�ġA�Э��s��� :");
		else break;
	}	//���a�@��� 
	
	printf("\n<�вĤG�ժ��a�G��ܨ���ζH> \n1.�ʷP�p���~\n2.�i�R�p����\n3.�����k�k\n4.�������z�k(�k)\n\n�п��:");
	while(1)
	{
		scanf("%d",&player2);
		if(player2==player1) printf("����w�Q�խ��ϥΡA�Э��s��� :");
		else if(player2>4||player2<1) printf("��ܵL�ġA�Э��s��� :");
		else break;
	}	//���a�G���
}

void gamestart()	//�����ܧ����i�J�C������ 
{
	int i=5;
	printf("\n-------------------------\n");
	printf("�C��5���}�l : ");
	for(i=5;i>0;i--)
	{
		printf("%d\b",i);
		Sleep(1000);
	}
	system("cls");	
}

int game1()
{
	srand(time(NULL));
	int max = 500 , min = 1,score=500,num,X,i=0,sub=10;
	X = (rand()%500)+1;

	printf("<�q�Ʀr�C��!!!> �V�ֲq����ƶV��!!!\n\n");
	printf(" ------------------------------------------------------\n");
	printf("|�C���W�h:                                             |\n");
	printf("|       1.������Ƭ�500���C                            |\n");
	printf("|       2.�Ʀr�d�򤶩�1~500�����A�q���@�����Ʀ�10���C  |\n");
	printf("|       3.�Y�b5�����q���Ʀr�A�`���[�W500���C           |\n");
	printf(" ------------------------------------------------------\n\n");
	printf("�Ĥ@��:\n"); 
	while(X!=num)
	{
		printf("%d~%d �п�J�@�ӼƦr :",min,max);
		scanf("%d",&num);
		
		if(num>max||num<min) printf("�w�W�X�d��!\n\n");
		else if(num!=X)
		{
			printf("�A�q���F!��%d���C\n\n",sub);
			score-=10;
			sub+=10;
		}
		
		if(num<X && num>min) min = num;
		else if (num<max&&num>X) max = num;
		
		i++;
	}
	printf("Bingo!\n\n");
	if(i<=5) score+=500;
	printf("�`�@�o��: %d\n",score);
	return score;
}

void game2(int score)
{
	printf("\n-------------------------\n");
	printf("�ĤG��5���}�l _ ");
	for(int i=5;i>0;i--)
	{
		printf("%d\b",i);
		Sleep(1000);
	}
	system("cls");
	
	srand(time(NULL));
	int max = 500 , min = 1,score2=500,num,X,i=0,sub=10;
	X = (rand()%500)+1;

	printf("�ĤG��:\n"); 
	while(X!=num)
	{
		printf("%d~%d �п�J�@�ӼƦr :",min,max);
		scanf("%d",&num);
		
		if(num>max||num<min) printf("�w�W�X�d��!\n\n");
		else if(num!=X)
		{
			printf("�A�q���F!��%d���C\n\n",sub);
			score2-=10;
			sub+=10;
		}
		
		if(num<X && num>min) min = num;
		else if (num<max&&num>X) max = num;
		i++;
	}
	printf("Bingo!\n\n");
	if(i<=5) score2+=500;
	printf("�`�@�o��: %d\n\n",score2);
	
	printf("\n------------------\n");
	printf("�Ĥ@�լ� : %d ���C\n�ĤG�լ� : %d ���C\n",score,score2);
	printf("\n------------------\n");
	
	if(score>score2) printf("�Ĥ@�����\n");
	else if(score<score2) printf("�ĤG�����\n");
	else printf("��ե���\n");
}

void search(){
	float num;
	char yesno[20];
	
	printf("��J�Z��(m) : ");
	while(1){
		scanf("%f", &num);
		printf("\n");
		
		if(num > 0 && num <= 1000){
			printf("��J�Z�����T\n");
			printf("�}�l�j�M......");
			Sleep(3000);
			if(num > 0 && num <= 500){
				printf("\n");
				printf("     *             \n");
				Sleep(1000);
				printf("         *         \n");
				Sleep(1000);
				printf("       *           \n");
				Sleep(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
				printf("       me          \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf("    *         *    \n");
				Sleep(1000);
				printf("     *             \n");
				Sleep(1000);
				printf("           *       \n");
			}
			else if(num > 500 && num <= 1000){
				printf("\n");
				printf("       *            \n");
				Sleep(1000);
				printf("              *     \n");
				Sleep(1000);
				printf(" *                  \n");
				Sleep(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
				printf("       me           \n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf("     *              \n");
				Sleep(1000);
				printf("                 *  \n");
				Sleep(1000);
				printf("       *            \n");
			}
			
			printf("�O�_��ܥ�� ? Yes/No ?(���p�g�Y�i)");		
			scanf("%s", yesno);
			if(yesno[0] >= 65 && yesno[0] <= 99){
				yesno[0] = yesno[0] + 32;
			}
			if(strcmp("yes", yesno) == 0){
				printf("��o�ϥΪ̸�Ƥ�...");
				Sleep(5000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("�j�M����!");
				Sleep(3000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break; 
			}
			else if(strcmp("no", yesno) == 0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("��ͥ��� TT");
				Sleep(3000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("���ŦX�j�M�Z��!\n\n");
			Sleep(3000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("�Э��s��J�Z�� : ");	
		}
	}
} 
void Verify(){
	int length = 0, i = 0, correct = 0, wrong = 0, j = 0, publicLength = 0;
	char open = '\0', num[20] = {}, clear[] = {}, allNum[1000][15] = {}, allData[1000] = {};
	
	/* Ū��publicOrNot�A�s�JallData */ 
	FILE *inptr_publicOrNot = fopen("publicOrNot.txt", "r");
	publicLength = 0;
	while((fscanf(inptr_publicOrNot, "%c", &allData[publicLength])) != EOF){
		publicLength++;
	}
	fclose(inptr_publicOrNot);
	
	/* ���}�ӤH��ƤΦ�m */ 
	while(open != 'O' && open != 'X'){
		if(wrong != 0 && wrong != 1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("�п�J���T�榡(�j�gO�Τj�gX)�C\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		printf("��ܬO�_���}�ӤH��ƤΦ�m(��JO/X)�G");
		scanf("%c", &open);
		if(open == 'O' || open == 'X'){
			allData[publicLength] = open;
		}
		system("cls");
		wrong++;
	}
	
	/* Ū��number�A�s�JallNum */ 
	FILE *inptr = fopen("number.txt", "r");
	i = 0;
	while((fscanf(inptr, "%s", allNum[i])) != EOF){
		i++;
	}
	fclose(inptr);
	
	/* ���� */ 
	while(correct != 1){
		correct = 0;
		printf("�п�J�q�ܸ��X(�����Ҩϥ�) : ");
		scanf("%s", num);
		length = strlen(num);
		
		/* �j��10�r */ 
		if(length != 10 || num[0] != '0' || num[1] != '9'){
			strcpy(num, clear);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("�榡��J���~�A�Э��s��J�C\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}else{
			/* ���O�Ʀr */ 
			for(i = 0; i < 10; i++){
				if(num[i] < '0' || num[i] > '9'){
					strcpy(num, clear);
					correct = -1;
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
					printf("�榡��J���~�A�Э��s��J�C\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			
			if(correct != -1){
				for(i = 0; strlen(allNum[i]) != 0; i++){
					/* ���Ƹ��X */ 
					if(strcmp(allNum[i], num) == 0){
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
						printf("���ҥ��ѡA�Э��s��J�C\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						correct = -1; 
						strcpy(num, clear);
						break;
					}else if(strlen(allNum[i+1]) == 0){
						strcpy(allNum[i+1], num);
						/* �}��(number) */ 
						FILE *outptr = fopen("number.txt", "w");
						/* �g�� */ 
						for(i = 0; strlen(allNum[i]) != 0; i++){
							fprintf(outptr, "%s", allNum[i]);
							if(strlen(allNum[i+1]) != 0){
								fprintf(outptr, "\n");
							}
						}
						fclose(outptr);
						
						/* �}��(publicOrNot) */ 
						FILE *publicOrNot = fopen("publicOrNot.txt", "w");
						for(j = 0; j <= publicLength; j++){
							fprintf(publicOrNot, "%c", allData[j]);
						}
						fclose(publicOrNot);
						
						/* ���U���\ */ 
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
						printf("�q�ܸ��X�w�֭�C\n");
						printf("���ߵ��U�����I\n");
						Sleep(3000);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						correct = 1;
						break;
					}
				}
				
				/* allNum���Ů� */ 
				if(i == 0 && correct != -1 && correct != 1){
					strcpy(allNum[i], num);
					/* �}��(number) */ 
					FILE *outptr = fopen("number.txt", "w");
					/* �g�� */
					for(i = 0; strlen(allNum[i]) != 0; i++){
						fprintf(outptr, "%s", allNum[i]);
						if(strlen(allNum[i+1]) != 0){
							fprintf(outptr, "\n");
						}
					}
					fclose(outptr);
					
					/* �}��(publicOrNot) */ 
					FILE *publicOrNot = fopen("publicOrNot.txt", "w");
					for(j = 0; j <= publicLength; j++){
						fprintf(publicOrNot, "%c", allData[j]);
					}
					fclose(publicOrNot);
					
					/* ���U���\ */ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					printf("�q�ܸ��X�w�֭�C\n");
					printf("���ߵ��U�����I\n");
					Sleep(3000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					correct = 1;
				}
			}
		}
	}
} 

int main(){
	User user;
	int choose = 0, i = 0, user_num, flag = 0, people;
	char yesno[10], datayesno[10];
 
	HANDLE hOut;  
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
	printf("\t\t\t\t\t\t\t����?\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
	User new_user;
	int all = 1;
	FILE *account = fopen("account.txt","r");
	while(fscanf(account, "%s%s",new_user.id, new_user.password) != EOF){
		all++;
	}
	while(1){
		if(flag != 2){
			printf("1.�`�U\t2.�n�J�]�i�t���ѡ^\t3.�K�[�n��\t4.���}��ѫ�\t5.����\t6.�j�M����n��\n\n---------------------------------------\n\n");
			scanf("%d", &choose);
			system("cls");
		}
		
		switch(choose){
			case 1:
				singup();//�`�U
				Verify();
				system("cls");
				break;
			case 2:
				user_num = singin();//�n�J 
				system("cls");
				if(user_num != 0){
					flag = 2;
					interest();//���� 
					system("cls");
					printf("�O�_�}�l�t�� ? Yes/No(���p�g�Y�i)\t");
					scanf("%s", yesno);
					if(yesno[0] >= 65 && yesno[0] <= 99){
							yesno[0] = yesno[0] + 32;
					}
					if(strcmp(yesno, "yes") ==  0){
						pair(user_num);//�t�� 
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
						printf("\n\n\n\n\n\t\t\t\t�n�X����\n");
						Sleep(500);
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� */
						return 0;
					}
					else{
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
						printf("\n\n\n\n\n\t\t\t\t�Y�N�n�X!!!\n");
						Sleep(3000);	
						system("cls");
						printf("\n\n\n\n\n\t\t\t\t�n�X��");
						for(i = 0; i < 3; i++){
							Sleep(1000);
							printf(".");
						}
						Sleep(3000);
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
						return 0;
					}
				}
				break;
			case 3:
				user_num = singin();
				system("cls");
				if(user_num != 0){
					people = addfriend(user_num);
					if(people == all){
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
						printf("\n\n\n\t\t\t���s�b���Τ�I�K�[�n�ͥ��ѡI"); 
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� */
						Sleep(3000);
						system("cls");
					}
					Sleep(3000);
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
					printf("\n\n\n\n\n\t\t\t\t�Y�N�n�X!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t�n�X��");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
					system("cls");
				}
				break;
			case 4:
				user_num = singin();
				system("cls");
				if(user_num != 0){
					chatroom(user_num);
					system("cls"); 
				}
				break;
			case 5:
				int score;
				user_num = singin();
				system("cls");
				if(user_num != 0){
					chooserole1();
					chooserole2();
					gamestart();
					score=game1();
					game2(score);
					Sleep(5000);
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
					printf("\n\n\n\n\n\t\t\t\t�Y�N�n�X!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t�n�X��");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
					system("cls");	
				}
				break; 
			case 6:
				user_num = singin();
				system("cls");
				if(user_num != 0){
					search();
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//�Ŧ� 
					printf("\n\n\n\n\n\t\t\t\t�Y�N�n�X!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t�n�X��");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�զ� 
					system("cls");
				}
				break; 
		}		
	}
	//fclose(inptr);
	//fclose(outptr);
	return 0;
}
