// 1번 과제 필수 기능

#include <iostream>

using namespace std;

// HP, MP 포션 함수
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

int main() {
	// 캐릭터 스탯 (HP, MP, 공격력, 방어력) 선언 및 초기화
	int status[4] = { 0, 0, 0, 0 };

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
		cout << "5. 스탯 확인" << endl;
		cout << "6. Level UP" << endl;
		cout << "0. 종료" << endl;
		cout << "========================" << endl;

		// 번호 입력
		cout << "\n" << "번호를 입력해주세요 : ";
		cin >> index;
		cout << "\n" << endl;

		// switch으로 입력값에 대한 결과 출력
		switch (index) {
		case 1:
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
		case 2:
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
		case 3:
			cout << "공격력이 2배로 증가됩니다!" << endl;

			status[2] = status[2] * 2; // 공격력 2배 상승

			cout << "<현재 공격력 : " << status[2] << ">" << endl;

			break;
		case 4:
			cout << "방어력이 2배로 증가됩니다!" << endl;

			status[3] = status[3] * 2; // 방어력 2배 상승

			cout << "<현재 방어력 : " << status[3] << ">" << endl;

			break;
		case 5:
			cout << "== My Stat ==" << endl;
			cout << "HP : " << status[0] << endl;
			cout << "MP : " << status[1] << endl;
			cout << "공격력 : " << status[2] << endl;
			cout << "방어력 : " << status[3] << endl;
			cout << "=============" << endl;

			break;
		case 6:
			cout << "Level Up! 포션이 지급됩니다." << endl;

			if (HPotion >= 5 || MPotion >= 5) {
				cout << "\n" << "앗! 포션이 가득 찼습니다! 지급이 취소됩니다." << "\n" << endl;
			}
			else if (HPotion < 5 && MPotion < 5) {
				HPotion += 1; // HP 포션 1개 지급
				MPotion += 1; // MP 포션 1개 지급
			}

			cout << "남은 HP 포션 : " << HPotion << "/5" << endl;
			cout << "남은 MP 포션 : " << MPotion << "/5" << endl;

			break;
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		}
	}


	return 0;
}