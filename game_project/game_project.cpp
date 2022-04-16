// game_project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bangtal.h>
#include <stdio.h>
#include<list>
#include <time.h>
#include <windows.h>
#include <string>

using namespace std;
SceneID scene;
ObjectID cardBack[52], startButton,getButton, stopButton, money[10], plusButton, minusButton,betting[6];
// 0 : 안쓴 패, 1:손 패 2: 쓴 패
int card_status[52] = { 0, };
int card_list[52] = {};
int myMoney = 3000,bettingMoney=100;

list<int> player_hand;
list<int> computer_hand;

//뒷면: 0.5배 앞면 : 0.6배
void calculation_hand();
void arrange_deck();
void playerGet();
void computerGet();
void restartGame();
void startGame();
void showInterface();
void win_game();
const char* getCardPath(int card_num) {
	const char* path;
	//클로버
	if (card_num == 1) {
		path = "Images/cards/clover_A.png";
	}
	else if (card_num == 2) {
		path = "Images/cards/clover_2.png";
	}
	else if (card_num == 3) {
		path = "Images/cards/clover_3.png";
	}
	else if (card_num == 4) {
		path = "Images/cards/clover_4.png";
	}
	else if (card_num == 5) {
		path = "Images/cards/clover_5.png";
	}
	else if (card_num == 6) {
		path = "Images/cards/clover_6.png";
	}
	else if (card_num == 7) {
		path = "Images/cards/clover_7.png";
	}
	else if (card_num == 8) {
		path = "Images/cards/clover_8.png";
	}
	else if (card_num == 9) {
		path = "Images/cards/clover_9.png";
	}
	else if (card_num == 10) {
		path = "Images/cards/clover_10.png";
	}
	else if (card_num == 11) {
		path = "Images/cards/clover_J.png";
	}
	else if (card_num == 12) {
		path = "Images/cards/clover_Q.png";
	}
	else if (card_num == 13) {
		path = "Images/cards/clover_K.png";
	}
	//다이아
	else if (card_num == 14) {
		path = "Images/cards/diamon_A.png";
	}
	else if (card_num == 15) {
		path = "Images/cards/diamon_2.png";
	}
	else if (card_num == 16) {
		path = "Images/cards/diamon_3.png";
	}
	else if (card_num == 17) {
		path = "Images/cards/diamon_4.png";
	}
	else if (card_num == 18) {
		path = "Images/cards/diamon_5.png";
	}
	else if (card_num == 19) {
		path = "Images/cards/diamon_6.png";
	}
	else if (card_num == 20) {
		path = "Images/cards/diamon_7.png";
	}
	else if (card_num == 21) {
		path = "Images/cards/diamon_8.png";
	}
	else if (card_num == 22) {
		path = "Images/cards/diamon_9.png";
	}
	else if (card_num == 23) {
		path = "Images/cards/diamon_10.png";
	}
	else if (card_num == 24) {
		path = "Images/cards/diamon_J.png";
	}
	else if (card_num == 25) {
		path = "Images/cards/diamon_Q.png";
	}
	else if (card_num == 26) {
		path = "Images/cards/diamon_K.png";
	}
	//하트
	else if (card_num == 27) {
		path = "Images/cards/hart_A.png";
	}
	else if (card_num == 28) {
		path = "Images/cards/hart_2.png";
	}
	else if (card_num == 29) {
		path = "Images/cards/hart_3.png";
	}
	else if (card_num == 30) {
		path = "Images/cards/hart_4.png";
	}
	else if (card_num == 31) {
		path = "Images/cards/hart_5.png";
	}
	else if (card_num == 32) {
		path = "Images/cards/hart_6.png";
	}
	else if (card_num == 33) {
		path = "Images/cards/hart_7.png";
	}
	else if (card_num == 34) {
		path = "Images/cards/hart_8.png";
	}
	else if (card_num == 35) {
		path = "Images/cards/hart_9.png";
	}
	else if (card_num == 36) {
		path = "Images/cards/hart_10.png";
	}
	else if (card_num == 37) {
		path = "Images/cards/hart_J.png";
	}
	else if (card_num == 38) {
		path = "Images/cards/hart_Q.png";
	}
	else if (card_num == 39) {
		path = "Images/cards/hart_K.png";
	}
	//스페이드
	else if (card_num == 40) {
		path = "Images/cards/spade_A.png";
	}
	else if (card_num == 41) {
		path = "Images/cards/spade_2.png";
	}
	else if (card_num == 42) {
		path = "Images/cards/spade_3.png";
	}
	else if (card_num == 43) {
		path = "Images/cards/spade_4.png";
	}
	else if (card_num == 44) {
		path = "Images/cards/spade_5.png";
	}
	else if (card_num == 45) {
		path = "Images/cards/spade_6.png";
	}
	else if (card_num == 46) {
		path = "Images/cards/spade_7.png";
	}
	else if (card_num == 47) {
		path = "Images/cards/spade_8.png";
	}
	else if (card_num == 48) {
		path = "Images/cards/spade_9.png";
	}
	else if (card_num == 49) {
		path = "Images/cards/spade_10.png";
	}
	else if (card_num == 50) {
		path = "Images/cards/spade_J.png";
	}
	else if (card_num == 51) {
		path = "Images/cards/spade_Q.png";
	}
	else if (card_num == 52) {
		path = "Images/cards/spade_K.png";
	}
	else {
		path = "Images/card_back.png";
	}



	return path;

}
void lose_game();
bool isWin();
void stopGame();
ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown)
{
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}

	return object;
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		restartGame();
	}
	else if (object == getButton) {
		playerGet();
	}
	else if (object == stopButton) {
		stopGame();
	}
	else if (object == plusButton) {
		if (bettingMoney + 100 > myMoney / 2) {
			showMessage("베팅 금액은 현재 보유금액의 1/2를 넘을 수 없습니다.");
		}
		else {
			bettingMoney += 100;
			showInterface();
		}
	}
	else if (object == minusButton) {
		if (bettingMoney - 100<=0) {
			showMessage("베팅 금액은 0원보다 커야합니다.");
		}
		else {
			bettingMoney -= 100;
			showInterface();
		}
	}
}


int main()
{
	srand(time(NULL));

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setMouseCallback(mouseCallback);

	scene = createScene("Santa Race", "Images/background.png");

	startButton = createObject("Images/start.png", scene, 835, 480, true);
	getButton = createObject("Images/hit.png", scene, 720, 480, false);
	stopButton = createObject("Images/stay.png", scene, 1020, 480, false);

	plusButton = createObject("Images/plus.png", scene, 1020, 560, true);
	minusButton = createObject("Images/minus.png", scene, 720, 560, true);
	scaleObject(startButton, 0.5);
	scaleObject(getButton, 0.5);
	scaleObject(stopButton, 0.5);
	scaleObject(plusButton, 0.1);
	scaleObject(minusButton, 0.1);
	startGame();
	startGame(scene);
}

void calculation_hand() {
	list<int>::iterator iter = player_hand.begin();
	int total = 0;

	for (iter = player_hand.begin(); iter != player_hand.end(); iter++) {
		int card = *iter % 13;
		if (card == 0 || card == 11 || card == 12) {
			total += 10;
		}
		else if (card == 1) {
			total += 11;
		}
		else {
			total += card;
		}
	}
	if (total > 21) {
		total = 0;
		for (iter = player_hand.begin(); iter != player_hand.end(); iter++) {
			int card = *iter % 13;
			if (card == 0 || card == 11 || card == 12) {
				total += 10;
			}
			else if (card == 1) {
				total += 1;
			}
			else {
				total += card;
			}
		}

		
		
		//stopGame();
		//stopGame();
	}
	if (total > 21) {
		showMessage("버스트ㅠㅠ");
		lose_game();
	}
	else if (total == 21) {
		stopGame();
	}
	


}

void showInterface() {
	//플레이어 머니 출력 함수
	for (int j = 0; j < 10; j++) {
		string path = "Images/num/";
		string str_money = to_string(myMoney);

		if (str_money.size() < j) {
			hideObject(money[j]);
		}
		else {
			path += str_money[j];
			path += ".png";
			//290 시작
			setObjectImage(money[j], path.c_str());
			locateObject(money[j],scene,400 + 10 * j, 850);
			//money[j] = createObject(path.c_str(), scene, 390 + 10 * j, 850, true);
			scaleObject(money[j], 0.3);
		}
	}
	//베팅 머니 출력 함수
	if (bettingMoney > myMoney / 2)
		bettingMoney = myMoney / 2;
	for (int j = 0; j < 6; j++) {
		string path = "Images/num/";
		string str_money = to_string(bettingMoney);

		if (str_money.size() < j) {
			hideObject(betting[j]);
		}
		else {
			path += str_money[j];
			path += ".png";
			//290 시작
			setObjectImage(betting[j], path.c_str());
			locateObject(betting[j], scene, 925 + 15 * j, 570);
			//money[j] = createObject(path.c_str(), scene, 390 + 10 * j, 850, true);
			scaleObject(betting[j], 0.5);
			showObject(betting[j]);
		}
	}
}
void arrange_deck() {
	list<int>::iterator player = player_hand.begin();
	list<int>::iterator computer = computer_hand.begin();

	int right = 0, left = 0, mid = 0,com_hand=0;
	for (int i = 0; i < 52; i++) {

		if (card_status[i] == 0) {
			setObjectImage(cardBack[i], "Images/card_back.png");
			locateObject(cardBack[i], scene, 500, 660 + left++);
			scaleObject(cardBack[i], 0.5);
		}
		else if (card_status[i] == 1) {
			setObjectImage(cardBack[i], getCardPath(*player));
			locateObject(cardBack[i], scene, 500 + (mid++) * 100, 180);
			scaleObject(cardBack[i], 0.6);

			player++;
		}
		else if (card_status[i] == 2) {
			if (com_hand == 0) {
				setObjectImage(cardBack[i], getCardPath(*computer));
				scaleObject(cardBack[i], 0.6);
			}
			else {
				setObjectImage(cardBack[i], "Images/card_back.png");
				scaleObject(cardBack[i], 0.48);
			}
			locateObject(cardBack[i], scene, 800+(com_hand++)*100, 660);
		}
		else {

			setObjectImage(cardBack[i], "Images/card_back.png");
			locateObject(cardBack[i], scene, 1200, 660 + right++);
			scaleObject(cardBack[i], 0.5);
		}
	}


}
void playerGet() {
	bool inCard = false;
	for (int i = 51; i >= 0; i--) {
		if (card_status[i] == 0) {
			inCard = true;
			card_status[i] = 1;
			player_hand.push_back(card_list[i]);
			break;

		}
	}
	if (!inCard) {
		for (int i = 0; i < 52; i++) {
			if (card_status[i] == 3) {
				card_status[i] = 0;
			}
			card_list[i] = rand() % 52 + 1;
			for (int j = 0; j < i; j++) {
				if (card_list[i] == card_list[j]) {
					i--;
					break;
				}
			}
		}
		card_status[51] = 1;
		player_hand.push_back(card_list[51]);
	}



	arrange_deck();
	calculation_hand();
}

void computerGet() {
	bool inCard = false;
	for (int i = 51; i >= 0; i--) {
		if (card_status[i] == 0) {
			inCard = true;
			card_status[i] = 2;
			computer_hand.push_back(card_list[i]);
			break;

		}
	}

	if (!inCard) {
		for (int i = 0; i < 52; i++) {
			if (card_status[i] == 3) {
				card_status[i] = 0;
			}
			card_list[i] = rand() % 52 + 1;
			for (int j = 0; j < i; j++) {
				if (card_list[i] == card_list[j]) {
					i--;
					break;
				}
			}
		}
		card_status[51] = 2;
		computer_hand.push_back(card_list[51]);
	}
	arrange_deck();
	calculation_hand();
}

void startGame()
{
	ObjectID asd = createObject("Images/num/player_money.png", scene, 290, 850, true);
	scaleObject(asd, 0.25);
	ObjectID bet = createObject("Images/num/배팅액.png", scene, 820, 570, true);
	scaleObject(bet, 0.45);
	for (int i = 0; i < 10; i++) {
		money[i] = createObject("", scene, 0, 0, true);
	}
	for (int i = 0; i < 6; i++) {
		betting[i] = createObject("", scene, 0, 0, true);
	}


	showInterface();

	for (int i = 0; i < 52; i++) {
		cardBack[i] = createObject("./images/card_back.png");
		locateObject(cardBack[i], scene, 500, 660 + i);
		scaleObject(cardBack[i], 0.5);
		showObject(cardBack[i]);
	}
	for (int i = 0; i < 52; i++) {
		card_list[i] = rand() % 52 + 1;
		for (int j = 0; j < i; j++) {
			if (card_list[i] == card_list[j]) {
				i--;
				break;
			}
		}
	}
}
void restartGame() {
	showInterface();

	for (int i = 0; i < 52; i++) {
		if (card_status[i] == 1 || card_status[i] == 2) {
			card_status[i] = 3;
		}
	}
	player_hand.clear();
	computer_hand.clear();

	showObject(getButton);
	showObject(stopButton);
	hideObject(startButton);

	hideObject(minusButton);
	hideObject(plusButton);
	computerGet();
	computerGet();
	playerGet();
	playerGet();
	
	

	
	
}
void stopGame() {
	if (isWin()) {
		win_game();
	}
	else {
		lose_game();
	}
	
	
}

bool isWin() {


	//======================플레이어 손패 확인======================
	list<int>::iterator player = player_hand.begin();
	int player_total = 0;
	for (player = player_hand.begin(); player != player_hand.end(); player++) {
		int card = *player % 13;
		if (card == 0 || card == 11 || card == 12) {
			player_total += 10;
		}
		else if (card == 1) {
			player_total += 11;
		}
		else {
			player_total += card;
		}
	}

	if (player_total > 21) {
		player_total = 0;
		for (player = player_hand.begin(); player != player_hand.end(); player++) {
			int card = *player % 13;
			if (card == 0 || card == 11 || card == 12) {
				player_total += 10;
			}
			else if (card == 1) {
				player_total += 1;
			}
			else {
				player_total += card;
			}
		}
	
	}
	
	if (player_total == 21) {
		showMessage("블랙잭!");
		return true;
	}
	//======================컴퓨터 손패 확인======================
	list<int>::iterator computer = computer_hand.begin();
	int computer_total = 0;

	for (computer = computer_hand.begin(); computer != computer_hand.end(); computer++) {
		int card = *computer % 13;
		if (card == 0 || card == 11 || card == 12) {
			computer_total += 10;
		}
		else if (card == 1) {
			computer_total += 11;
		}
		else {
			computer_total += card;
		}
	}

	if (computer_total > 21) {
		computer_total = 0;

		for (computer = computer_hand.begin(); computer != computer_hand.end(); computer++) {
			int card = *computer % 13;
			if (card == 0 || card == 11 || card == 12) {
				computer_total += 10;
			}
			else if (card == 1) {
				computer_total += 1;
			}
			else {
				computer_total += card;
			}
		}
	}
	int com_hand = 0;
	computer = computer_hand.begin();



	for (int i = 0; i < 52; i++) {

		if (card_status[i] == 2) {
			setObjectImage(cardBack[i], getCardPath(*computer));
			scaleObject(cardBack[i], 0.6);
			locateObject(cardBack[i], scene, 800 + (com_hand++) * 100, 660);
			computer++;
		}
	}


	while (computer_total <= 16) {
		
		computerGet();
		computer_total = 0;
		for (computer = computer_hand.begin(); computer != computer_hand.end(); computer++) {
			int card = *computer % 13;
			if (card == 0 || card == 11 || card == 12) {
				computer_total += 10;
			}
			else if (card == 1) {
				computer_total += 11;
			}
			else {
				computer_total += card;
			}
		}
		
		int com_hand = 0;
		computer = computer_hand.begin();

		//showImageViewer("Images/start.png");

		for (int i = 0; i < 52; i++) {

			if (card_status[i] == 2) {
				setObjectImage(cardBack[i], getCardPath(*computer));
				scaleObject(cardBack[i], 0.6);
				locateObject(cardBack[i], scene, 600 + (com_hand++)%6 * 100, 660- (int)com_hand/7*140);
				computer++;
			}
		}
		if (computer_total > 21) {
			computer_total = 0;
			for (computer = computer_hand.begin(); computer != computer_hand.end(); computer++) {
				int card = *computer % 13;
				if (card == 0 || card == 11 || card == 12) {
					computer_total += 10;
				}
				else if (card == 1) {
					computer_total += 1;
				}
				else {
					computer_total += card;
				}
			}
		
		}
	}

	//======================최종 정산======================
	
	printf("player:%d computer:%d\n", player_total, computer_total);
	if (computer_total > 21) {
		showMessage("딜러 버스트!");
		return true;
	}
	else if (player_total >= computer_total) {
		showMessage("승리!!");
		return true;
	}
	else{
		showMessage("패배..ㅠㅠ");
		return false;
	}
}

void win_game() {
	player_hand.clear();
	computer_hand.clear();
	for (int i = 51; i >= 0; i--) {
		if (card_status[i] == 1 || card_status[i] == 2) {
			card_status[i] = 3;
		}
	}
	myMoney += bettingMoney;
	hideObject(getButton);
	hideObject(stopButton);
	showObject(startButton);
	showObject(minusButton);
	showObject(plusButton);
	showInterface();
}

void lose_game() {
	player_hand.clear();
	computer_hand.clear();
	for (int i = 51; i >= 0; i--) {
		if (card_status[i] == 1 || card_status[i] == 2) {
			card_status[i] = 3;
		}
	}
	myMoney -= bettingMoney;
	hideObject(getButton);
	hideObject(stopButton);
	showObject(startButton);
	showObject(minusButton);
	showObject(plusButton);
	showInterface();
}

