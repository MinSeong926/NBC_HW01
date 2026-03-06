// 1번 과제 도전 기능

// [도전 기능]
//  레벨 시스템: level 변수를 만들어서, 6번을 누를 때마다 레벨도 1씩 올리기.
//  함수 활용: 포션을 충전하는 기능을 별도의 함수로 분리.
//  스탯 정보 추가 1: 5번 선택으로 현재 능력치 출력 시, 현재 레벨도 함께 출력.
//  스탯 정보 추가 2: 5번 선택으로 현재 능력치 출력 시, 남은 포션 개수도 출력.
//  확장: 공격력/방어력 외 힘, 민첩, 지능 등 나만의 새로운 스탯을 추가해서 나만의 게임 만들기.


#include <iostream>

using namespace std;

// HP, MP 포션 함수
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

// [도전 기능] HP, MP 포션 사용 함수
void addPotion(int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion += 1;
	*p_MPPotion += 1;
}

int main() {
	// 캐릭터 스탯 (HP, MP, 공격력, 방어력, AP, SP) 선언 및 초기화
	int status[6] = { 0 };

	// [도전 기능] Level 변수 선언 및 초기화
	int level = 0;

	// HP, MP 포션 선언
	int HPotion;
	int MPotion;

	// HP, MP 포션 함수 정의
	setPotion(5, &HPotion, &MPotion);

	// 선택지 번호 변수 선언
	int index;


	// 환영 인사
	cout << "환영합니다!" << endl;

	// HP, MP 입력
	cout << "\n" << "HP와 MP를 입력해주세요 : ";
	cin >> status[0] >> status[1];

	// HP, MP 중 하나라도 50이하일 시, 다시 입력
	while (status[0] <= 50 || status[1] <= 50) {
		cout << "HP나 MP가 너무 작습니다!(50이하)" << endl;
		cout << "다시 입력해주세요!" << endl;

		cout << "\n" << "HP와 MP를 입력해주세요 : ";
		cin >> status[0] >> status[1];
	}

	// 공격력,방어력 입력
	cout << "\n" << "공격력과 방어력을 입력해주세요 : ";
	cin >> status[2] >> status[3];

	// 공격력, 방어력 하나라도 0이하 일 시, 다시 입력
	while (status[2] <= 0 || status[3] <= 0) {
		cout << "공격력과 방어력이 너무 낮습니다!(0 이하)" << endl;
		cout << "다시 입력해주세요!" << endl;

		cout << "\n" << "공격력과 방어력을 입력해주세요 : ";
		cin >> status[2] >> status[3];
	}

	// [도전 기능] AP, SP 입력
	cout << "\n" << "AP와 SP를 입력해주세요 : ";
	cin >> status[4] >> status[5];

	// [도전 기능] AP, SP 하나라도 0이하 일 시, 다시 입력
	while (status[4] <= 0 || status[5] <= 0) {
		cout << "AP와 SP이 너무 낮습니다!(0 이하)" << endl;
		cout << "다시 입력해주세요!" << endl;

		cout << "\n" << "AP와 SP를 입력해주세요 : ";
		cin >> status[4] >> status[5];
	}

	// HP, MP 포션 기본 지급 (5개씩)
	cout << "스탯을 입력한 보상으로 HP, MP 포션을 드립니다!" << endl;
	cout << "HP, MP 포션이 5개씩 지급되었습니다." << endl;
	cout << "============================================" << "\n" << endl;


	// 스탯 관리 시스템
	while (1) {
		cout << "== <스탯 관리 시스템 >==" << endl;
		cout << "1. HP UP" << endl;
		cout << "2. MP UP" << endl;
		cout << "3. 공격력 UP" << endl;
		cout << "4. 방어력 UP" << endl;
		cout << "5. AP UP" << endl;
		cout << "6. SP UP" << endl;
		cout << "7. 스탯 확인" << endl;
		cout << "8. Level UP" << endl;
		cout << "0. 종료" << endl;
		cout << "========================" << endl;

		// 번호 입력
		cout << "\n" << "번호를 입력해주세요 : ";
		cin >> index;
		cout << "\n" << endl;

		// switch으로 입력값에 대한 결과 출력
		switch (index) {
		case 1: // HP UP
			if (HPotion > 0) { // HP 포션이 있을 시
				cout << "HP 포션을 사용해서 HP가 20 증가했습니다!" << endl;
				cout << "HP 포션이 1개 차감됩니다." << endl;

				status[0] += 20; // HP 20 증가
				HPotion -= 1; // HP 포션 1 감소
			}
			else { // HP 포션이 없을 시
				cout << "HP 포션이 없습니다!" << endl;
			}

			cout << "<현재 HP : " << status[0] << ">" << endl;
			cout << "남은 HP 포션 : " << HPotion << "/5" << endl;

			break;
		case 2: // MP UP
			if (MPotion > 0) { // MP 포션이 있을 시
				cout << "MP 포션을 사용해서 HP가 20 증가했습니다!" << endl;
				cout << "MP 포션이 1개 차감됩니다." << endl;

				status[1] += 20; // MP 20 증가
				MPotion -= 1; // MP 포션 1 감소
			}
			else { // MP 포션이 없을 시
				cout << "MP 포션이 없습니다!" << endl;
			}

			cout << "<현재 MP : " << status[1] << ">" << endl;
			cout << "남은 MP 포션 : " << MPotion << "/5" << endl;

			break;
		case 3: // 공격력 UP
			cout << "공격력이 2배로 증가됩니다!" << endl;

			status[2] = status[2] * 2; // 공격력 2배 상승

			cout << "<현재 공격력 : " << status[2] << ">" << endl;

			break;
		case 4: // 방어력 UP
			cout << "방어력이 2배로 증가됩니다!" << endl;

			status[3] = status[3] * 2; // 방어력 2배 상승

			cout << "<현재 방어력 : " << status[3] << ">" << endl;

			break;
		case 5: // [도전 기능] AP UP
			cout << "AP가 5 증가됩니다!" << endl;

			status[4] = status[4] + 5; // AP 5 상승

			cout << "<현재 AP : " << status[4] << ">" << endl;

			break;
		case 6: // [도전 기능] SP UP
			cout << "SP가 5 증가됩니다!" << endl;

			status[5] = status[5] + 5; // SP 5 상승

			cout << "<현재 SP : " << status[5] << ">" << endl;

			break;
		case 7: // 스탯 창 출력
			cout << "== My Stat ==" << endl;
			cout << "Level : " << level << endl;
			cout << "HP : " << status[0] << endl;
			cout << "MP : " << status[1] << endl;
			cout << "공격력 : " << status[2] << endl;
			cout << "방어력 : " << status[3] << endl;
			cout << "AP : " << status[4] << endl;
			cout << "SP : " << status[5] << endl;
			cout << "=============" << endl;
			cout << "HP 포션 갯수 : " << HPotion << "개" << endl;
			cout << "MP 포션 갯수 : " << MPotion << "개" << endl;

			break;
		case 8: // [도전 기능] Level UP
			cout << "Level Up! 포션이 지급됩니다." << endl;

			level += 1; // Level 1 증가

			if (HPotion >= 5 || MPotion >= 5) { // 포션이 가득차면 지급 취소
				cout << "\n" << "앗! 포션이 가득 찼습니다! 지급이 취소됩니다." << "\n" << endl;
			}
			else if (HPotion < 5 && MPotion < 5) { // 포션 지급
				addPotion(&HPotion, &MPotion); // 포션 충전 기능 함수 사용
			}

			cout << "현재 Level : " << level << endl;
			cout << "남은 HP 포션 : " << HPotion << "/5" << endl;
			cout << "남은 MP 포션 : " << MPotion << "/5" << endl;

			break;
		case 0: // 프로그램 종료
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		}
	}


	return 0;
}