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
	
	printf("姓名 : ");
	scanf("%s", user.name);
	fprintf(outptr, "%s\t", user.name);
	
	printf("\n昵稱 : ");
	scanf("%s", user.id);
	fprintf(account, "%s\t", user.id);
	
	printf("\n密碼 : ");
	scanf("%s", user.password);
	fprintf(account, "%s\n", user.password);
	
	while(choose != 1 && choose != 2){
		printf("\n性別 : ");
		printf("1. Male\t2. Female\n");
		scanf("%d", &choose);
		if(choose == 1){
			printf("已選擇 ");
			 printf("Male\n");
			strcpy(user.gender, "Male");
			fprintf(outptr, "Male\t");
		}
		else if(choose == 2){
			printf("已選擇 ");
			printf("Female\n");
			strcpy(user.gender, "Female");
			fprintf(outptr, "Female\t");
		}else{
			printf("請重新選擇");
		}
	}
	
	printf("\n位置 : ");
	printf("臺北市 新北市 基隆市 桃園市 新竹市\n");
	printf("新竹縣 苗慄縣 臺中市 彰化縣 南投縣\n");
	printf("雲林縣 嘉義市 嘉義縣 台南市 高雄市\n");
	printf("屏東縣 宜蘭縣 花蓮縣 台東縣 澎湖縣\n");
	printf("金門縣 連江縣\n\n-------------------\n");
	scanf("%s", user.position);
	fprintf(outptr, "%s\t", user.position);
	
	printf("\n年齡 : ");
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
	
	SetConsoleTextAttribute(hOut, FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//黃色 
	printf("請輸入暱稱id : ");
	scanf("%s", id_check);
	printf("\n");
	printf("請輸入密碼 : ");
	scanf("%s", password_check);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
	
	i = 1;
	while(fscanf(account, "%s%s", user.id, user.password) != EOF){
		
		if(strcmp(id_check, user.id) == 0){
			if(strcmp(password_check, user.password) == 0){
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色
				system("cls"); 
				printf("\n\n\n\n\n\t\t\t\t登入中"); 
				for(j = 0; j < 3; j++){
					printf(".");
					Sleep(1000);
				}
				system("cls");
				printf("\n\n\n\n\n\t\t\t\t登入完成...");
				Sleep(1000);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
				fclose(account);
				return i;
			}
			else{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
				printf("\n\n\n\n\n\t\t\t\t密碼錯誤，請重新登入");
				Sleep(2000);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
				fclose(account);
				return 0;
			}
		} 
		i++;
		num++;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
	printf("\n\n\n\n\n\t\t\t\tid錯誤，請重新登入");
	Sleep(2000); 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色
	fclose(account);
	return 0;
}
	
	

 
int interest(){
	FILE *interest = fopen("interest.txt", "a");
	int choose = 0;
	char yesno[10];
	printf("是否填寫過興趣 ? Yes/No(打小寫即可)\t");
	scanf("%s", yesno);
	if(yesno[0] >= 65 && yesno[0] <= 90){
			yesno[0] = yesno[0] + 32;
	}
	if(strcmp(yesno, "yes") ==  0){
		return 0;
	}
	else{
		printf("你是1.內向 2.外向 ?\t");
		scanf("%d", &choose);
		if(choose == 1) fprintf(interest, "內向\t");
		else fprintf(interest, "外向\t");
		
		printf("你覺得你是 1.文靜 2. 陽光 ?\t");
		scanf("%d", &choose);
		if(choose == 1) fprintf(interest, "文靜\n");
		else fprintf(interest, "陽光\n");
	}
	fclose(interest);
}

void pair(int num){ //配對 
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
	
	printf("是 否 想 和 %s 成 為 好 友 ? Yes/No(打小寫即可)\t", pair_people);
	scanf("%s", yesno);
	system("cls");
	if(yesno[0] >= 65 && yesno[0] <= 90){
			yesno[0] = yesno[0] + 32;
	}
	if(strcmp(yesno, "yes") ==  0){
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
		printf("\n\n\n\n\n\t\t\t\t加好友中");
		for(i = 0; i < 3; i++){
			Sleep(1000);
			printf(".");
		}
		system("cls");
		Sleep(1000);
		printf("\n\n\n\n\n\t\t\t\t添加完成...");
		Sleep(2000);	
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
		printf("是 否 想 要 進 入 私 人 聊 天 室 ? Yes/No(打小寫即可)\t"); //私人聊天室 
		scanf("%s",chatyesno);
		system("cls");
		if(chatyesno[0] >= 65 && chatyesno[0] <= 90){
			chatyesno[0] = chatyesno[0] + 32;
		}
		if(strcmp(chatyesno, "yes") ==  0){
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
			printf("\n\n\n\n\n\t\t\t\t進入聊天室中");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls");
			printf("\t\t\t\t\t\t聊天室\t\t\t\t\t\t\t\n");
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
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
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
			printf("\n\n\n\n\n\t\t\t\t退出聊天室中");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls"); 
			printf("\n\n\n\n\n\t\t\t\t退出完成，登出中");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			Sleep(3000);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
		}     //私人聊天室 
		else if(strcmp(chatyesno,"no") == 0){
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
			printf("\n\n\n\n\n\t\t\t\t登出中");
			for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			Sleep(3000);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
		}

	}
	else{
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
		printf("\n\n\n\n\n\t\t\t\t沒有添加好友，即將登出\n");
		Sleep(3000);	
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t登出中");
		for(i = 0; i < 3; i++){
			Sleep(1000);
			printf(".");
		}
		Sleep(3000);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
	}
	
}

void chatroom(int num){ //公開聊天室 
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
	
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
	printf("\t\t\t\t\t\t進入公開聊天室中");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	Sleep(3000);
	system("cls");
	printf("\t\t\t\t\t\t公開聊天室\t\t\t\t\t\t\t\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色  
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
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
	printf("\n\n\n\n\n\t\t\t\t退出聊天室中");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	system("cls"); 
	printf("\n\n\n\n\n\t\t\t\t退出完成，登出中");
	for(i = 0; i < 3; i++){
		Sleep(1000);
		printf(".");
	}
	Sleep(3000);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
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
    printf("請輸入你想要添加的好友的id ：");
	scanf("%s",add_id);
	system("cls"); 
	people = 1;
    account = fopen("account.txt", "r");
    while(fscanf(account, "%s%s",new_user.id, new_user.password) != EOF){
    	if(strcmp(add_id,new_user.id) == 0){
    		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
    		printf("\n\n\n\n\n\t\t\t\t正在給id為%s的好友發送請求",add_id);
    		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 */
    		for(i = 0; i < 3; i++){
				Sleep(1000);
				printf(".");
			}
			system("cls"); 
			Sleep(3000);
			printf("\n\n\nt\t\t\t%s的消息欄：來自%s的添加好友請求，是否同意 ? Yes/No ?(打小寫即可)\t",add_id,user.id);
			scanf("%s",yesno);
			system("cls");
			if(yesno[0] >= 65 && yesno[0] <= 90){
				yesno[0] = yesno[0] + 32;
			}
			if(strcmp(yesno,"yes") == 0){
				printf("\n\n\nt\t\t\t%s的消息欄：添加好友完成...",user.id);
			}
			else{
				printf("\n\n\nt\t\t\t%s的消息欄：添加好友失敗",user.id);
			} 
    		break;
		}
		else{
			people++;
		}	
	}
	return people;
}
void chooserole1()	//第一組玩家選擇角色 
{
	int player1,player2;
	
	printf("<請第一組玩家一選擇角色形象> \n1.性感小野獸\n2.可愛小甜心\n3.陽光男女\n4.成熟智慧男(女)\n\n請選擇:");
	while(1)
	{
		scanf("%d",&player1);
		if(player1>4||player1<1) printf("選擇無效，請重新選擇 :");
		else break;
	}	//玩家一選擇 
	
	printf("\n<請第一組玩家二選擇角色形象> \n1.性感小野獸\n2.可愛小甜心\n3.陽光男女\n4.成熟智慧男(女)\n\n請選擇:");
	while(1)
	{
		scanf("%d",&player2);
		if(player2==player1) printf("角色已被組員使用，請重新選擇 :");
		else if(player2>4||player2<1) printf("選擇無效，請重新選擇 :");
		else break;
	}	//玩家二選擇
}

void chooserole2()	//第二組家選擇角色 
{
	int player1,player2;
	printf("-----------------------------\n"); 
	printf("<請第二組玩家一選擇角色形象> \n1.性感小野獸\n2.可愛小甜心\n3.陽光男女\n4.成熟智慧男(女)\n\n請選擇:");
	while(1)
	{
		scanf("%d",&player1);
		if(player1>4||player1<1) printf("選擇無效，請重新選擇 :");
		else break;
	}	//玩家一選擇 
	
	printf("\n<請第二組玩家二選擇角色形象> \n1.性感小野獸\n2.可愛小甜心\n3.陽光男女\n4.成熟智慧男(女)\n\n請選擇:");
	while(1)
	{
		scanf("%d",&player2);
		if(player2==player1) printf("角色已被組員使用，請重新選擇 :");
		else if(player2>4||player2<1) printf("選擇無效，請重新選擇 :");
		else break;
	}	//玩家二選擇
}

void gamestart()	//角色選擇完畢進入遊戲介面 
{
	int i=5;
	printf("\n-------------------------\n");
	printf("遊戲5秒後開始 : ");
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

	printf("<猜數字遊戲!!!> 越快猜到分數越高!!!\n\n");
	printf(" ------------------------------------------------------\n");
	printf("|遊戲規則:                                             |\n");
	printf("|       1.原先分數為500分。                            |\n");
	printf("|       2.數字範圍介於1~500之間，猜錯一次分數扣10分。  |\n");
	printf("|       3.若在5次內猜中數字，總分加上500分。           |\n");
	printf(" ------------------------------------------------------\n\n");
	printf("第一組:\n"); 
	while(X!=num)
	{
		printf("%d~%d 請輸入一個數字 :",min,max);
		scanf("%d",&num);
		
		if(num>max||num<min) printf("已超出範圍!\n\n");
		else if(num!=X)
		{
			printf("你猜錯了!扣%d分。\n\n",sub);
			score-=10;
			sub+=10;
		}
		
		if(num<X && num>min) min = num;
		else if (num<max&&num>X) max = num;
		
		i++;
	}
	printf("Bingo!\n\n");
	if(i<=5) score+=500;
	printf("總共得分: %d\n",score);
	return score;
}

void game2(int score)
{
	printf("\n-------------------------\n");
	printf("第二組5秒後開始 _ ");
	for(int i=5;i>0;i--)
	{
		printf("%d\b",i);
		Sleep(1000);
	}
	system("cls");
	
	srand(time(NULL));
	int max = 500 , min = 1,score2=500,num,X,i=0,sub=10;
	X = (rand()%500)+1;

	printf("第二組:\n"); 
	while(X!=num)
	{
		printf("%d~%d 請輸入一個數字 :",min,max);
		scanf("%d",&num);
		
		if(num>max||num<min) printf("已超出範圍!\n\n");
		else if(num!=X)
		{
			printf("你猜錯了!扣%d分。\n\n",sub);
			score2-=10;
			sub+=10;
		}
		
		if(num<X && num>min) min = num;
		else if (num<max&&num>X) max = num;
		i++;
	}
	printf("Bingo!\n\n");
	if(i<=5) score2+=500;
	printf("總共得分: %d\n\n",score2);
	
	printf("\n------------------\n");
	printf("第一組為 : %d 分。\n第二組為 : %d 分。\n",score,score2);
	printf("\n------------------\n");
	
	if(score>score2) printf("第一組獲勝\n");
	else if(score<score2) printf("第二組獲勝\n");
	else printf("兩組平手\n");
}

void search(){
	float num;
	char yesno[20];
	
	printf("輸入距離(m) : ");
	while(1){
		scanf("%f", &num);
		printf("\n");
		
		if(num > 0 && num <= 1000){
			printf("輸入距離正確\n");
			printf("開始搜尋......");
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
			
			printf("是否選擇交友 ? Yes/No ?(打小寫即可)");		
			scanf("%s", yesno);
			if(yesno[0] >= 65 && yesno[0] <= 99){
				yesno[0] = yesno[0] + 32;
			}
			if(strcmp("yes", yesno) == 0){
				printf("獲得使用者資料中...");
				Sleep(5000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("搜尋完成!");
				Sleep(3000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break; 
			}
			else if(strcmp("no", yesno) == 0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				printf("交友失敗 TT");
				Sleep(3000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("不符合搜尋距離!\n\n");
			Sleep(3000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("請重新輸入距離 : ");	
		}
	}
} 
void Verify(){
	int length = 0, i = 0, correct = 0, wrong = 0, j = 0, publicLength = 0;
	char open = '\0', num[20] = {}, clear[] = {}, allNum[1000][15] = {}, allData[1000] = {};
	
	/* 讀檔publicOrNot，存入allData */ 
	FILE *inptr_publicOrNot = fopen("publicOrNot.txt", "r");
	publicLength = 0;
	while((fscanf(inptr_publicOrNot, "%c", &allData[publicLength])) != EOF){
		publicLength++;
	}
	fclose(inptr_publicOrNot);
	
	/* 公開個人資料及位置 */ 
	while(open != 'O' && open != 'X'){
		if(wrong != 0 && wrong != 1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("請輸入正確格式(大寫O或大寫X)。\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		printf("選擇是否公開個人資料及位置(輸入O/X)：");
		scanf("%c", &open);
		if(open == 'O' || open == 'X'){
			allData[publicLength] = open;
		}
		system("cls");
		wrong++;
	}
	
	/* 讀檔number，存入allNum */ 
	FILE *inptr = fopen("number.txt", "r");
	i = 0;
	while((fscanf(inptr, "%s", allNum[i])) != EOF){
		i++;
	}
	fclose(inptr);
	
	/* 驗證 */ 
	while(correct != 1){
		correct = 0;
		printf("請輸入電話號碼(供驗證使用) : ");
		scanf("%s", num);
		length = strlen(num);
		
		/* 大於10字 */ 
		if(length != 10 || num[0] != '0' || num[1] != '9'){
			strcpy(num, clear);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
			printf("格式輸入錯誤，請重新輸入。\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}else{
			/* 不是數字 */ 
			for(i = 0; i < 10; i++){
				if(num[i] < '0' || num[i] > '9'){
					strcpy(num, clear);
					correct = -1;
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
					printf("格式輸入錯誤，請重新輸入。\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			
			if(correct != -1){
				for(i = 0; strlen(allNum[i]) != 0; i++){
					/* 重複號碼 */ 
					if(strcmp(allNum[i], num) == 0){
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
						printf("驗證失敗，請重新輸入。\n");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						correct = -1; 
						strcpy(num, clear);
						break;
					}else if(strlen(allNum[i+1]) == 0){
						strcpy(allNum[i+1], num);
						/* 開檔(number) */ 
						FILE *outptr = fopen("number.txt", "w");
						/* 寫檔 */ 
						for(i = 0; strlen(allNum[i]) != 0; i++){
							fprintf(outptr, "%s", allNum[i]);
							if(strlen(allNum[i+1]) != 0){
								fprintf(outptr, "\n");
							}
						}
						fclose(outptr);
						
						/* 開檔(publicOrNot) */ 
						FILE *publicOrNot = fopen("publicOrNot.txt", "w");
						for(j = 0; j <= publicLength; j++){
							fprintf(publicOrNot, "%c", allData[j]);
						}
						fclose(publicOrNot);
						
						/* 註冊成功 */ 
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
						printf("電話號碼已核准。\n");
						printf("恭喜註冊完成！\n");
						Sleep(3000);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
						correct = 1;
						break;
					}
				}
				
				/* allNum為空時 */ 
				if(i == 0 && correct != -1 && correct != 1){
					strcpy(allNum[i], num);
					/* 開檔(number) */ 
					FILE *outptr = fopen("number.txt", "w");
					/* 寫檔 */
					for(i = 0; strlen(allNum[i]) != 0; i++){
						fprintf(outptr, "%s", allNum[i]);
						if(strlen(allNum[i+1]) != 0){
							fprintf(outptr, "\n");
						}
					}
					fclose(outptr);
					
					/* 開檔(publicOrNot) */ 
					FILE *publicOrNot = fopen("publicOrNot.txt", "w");
					for(j = 0; j <= publicLength; j++){
						fprintf(publicOrNot, "%c", allData[j]);
					}
					fclose(publicOrNot);
					
					/* 註冊成功 */ 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					printf("電話號碼已核准。\n");
					printf("恭喜註冊完成！\n");
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
	
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
	printf("\t\t\t\t\t\t\t約嗎?\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
	User new_user;
	int all = 1;
	FILE *account = fopen("account.txt","r");
	while(fscanf(account, "%s%s",new_user.id, new_user.password) != EOF){
		all++;
	}
	while(1){
		if(flag != 2){
			printf("1.注冊\t2.登入（可配對聊天）\t3.添加好友\t4.公開聊天室\t5.游戲\t6.搜尋附近好友\n\n---------------------------------------\n\n");
			scanf("%d", &choose);
			system("cls");
		}
		
		switch(choose){
			case 1:
				singup();//注冊
				Verify();
				system("cls");
				break;
			case 2:
				user_num = singin();//登入 
				system("cls");
				if(user_num != 0){
					flag = 2;
					interest();//興趣 
					system("cls");
					printf("是否開始配對 ? Yes/No(打小寫即可)\t");
					scanf("%s", yesno);
					if(yesno[0] >= 65 && yesno[0] <= 99){
							yesno[0] = yesno[0] + 32;
					}
					if(strcmp(yesno, "yes") ==  0){
						pair(user_num);//配對 
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
						printf("\n\n\n\n\n\t\t\t\t登出完成\n");
						Sleep(500);
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 */
						return 0;
					}
					else{
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
						printf("\n\n\n\n\n\t\t\t\t即將登出!!!\n");
						Sleep(3000);	
						system("cls");
						printf("\n\n\n\n\n\t\t\t\t登出中");
						for(i = 0; i < 3; i++){
							Sleep(1000);
							printf(".");
						}
						Sleep(3000);
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
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
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
						printf("\n\n\n\t\t\t不存在此用戶！添加好友失敗！"); 
						SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 */
						Sleep(3000);
						system("cls");
					}
					Sleep(3000);
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
					printf("\n\n\n\n\n\t\t\t\t即將登出!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t登出中");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
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
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
					printf("\n\n\n\n\n\t\t\t\t即將登出!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t登出中");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
					system("cls");	
				}
				break; 
			case 6:
				user_num = singin();
				system("cls");
				if(user_num != 0){
					search();
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY);//藍色 
					printf("\n\n\n\n\n\t\t\t\t即將登出!!!\n");
					Sleep(3000);	
					system("cls");
					printf("\n\n\n\n\n\t\t\t\t登出中");
					for(int i = 0; i < 3; i++){
						Sleep(1000);
						printf(".");
					}
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色 
					system("cls");
				}
				break; 
		}		
	}
	//fclose(inptr);
	//fclose(outptr);
	return 0;
}
