#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

class Student {
private:
	string name;
	int age;
	int life;
	int exp;
	int level;
	int money;
	int weapon;

	string weaponName;
	int weaponDamage;
	string weaponSound;
public:
	Student(string _name, int _age, int _life, int _exp, int _level, int _money, int _weapon) :name(_name), age(_age), life(_life), exp(_exp), level(_level), money(_money), weapon(_weapon) {}

	string getName() const { return name; }
	int getAge() const { return age; }
	int getLife() const { return life; }
	int getExp() const { return exp; }
	int getLevel() const { return level; }
	int getMoney() const { return money; }
	int getWeapon() const { return weapon; }
	int getWeaponDamage() const { return weaponDamage; }
	string getWeaponSound() const { return weaponSound; }

	void setLife(int _life) { life = _life; }
	void setExp(int _exp) { exp = _exp; };
	void setLevel(int _level) { level = _level; }
	void setWeapon(int _weapon) {
		weapon = _weapon;
		switch (weapon) {
		case 0:
			weaponName = "손";
			weaponDamage = 0;
			weaponSound = "";
			break;
		case 1:
			weaponName = "동검";
			weaponDamage = 3;
			weaponSound = "푸슉!!!!!!!!!";
			break;
		case 2:
			weaponName = "은검";
			weaponDamage = 10;
			weaponSound = "씽!!!!!!!!!!!!!!!!!!";
			break;
		case 3:
			weaponName = "금검";
			weaponDamage = 20;
			weaponSound = "씽씽!! 푸슈슉!!!";
			break;
		case 4:
			weaponName = "다이아몬드검";
			weaponDamage = 50;
			weaponSound = "팅!! 씽씽!! 푸슈슈슈슈슈슈슈슉!!!";
			break;
		case 5:
			weaponName = "권총";
			weaponDamage = 70;
			weaponSound = "탕!!!! 탕!!!!!!!!!!!!!!!!";
			break;
		case 6:
			weaponName = "라이플총";
			weaponDamage = 100;
			weaponSound = "타타타타타타타타타타타타타타타타타타타타타탕!!!";
			break;
		case 7:
			weaponName = "샷건";
			weaponDamage = 200;
			weaponSound = "팡!!! 팡!!!";
			break;
		default:
			weaponName = "없음";
			weaponDamage = 0;
			weaponSound = "";
			break;
		}
		cout << weaponName << "을 장착하였습니다! 몬스터에게 주는 피해량이 " << weaponDamage << "만큼 증가합니다." << endl << endl;
	}

	void levelUp() { level++; }

	void increaseMoney(int _money) { money += _money; }
	bool useMoney(int _money) {
		if (money >= _money) {
			money -= _money;
			return true;
		}
		else {
			cout << "돈이 모자랍니다..." << endl << endl;
			return false;
		}
	}

	void damaged(int damage) {
		cout << "으악!! 공격을 피하지 못해서 " << name << "의 Life가 " << damage << "만큼 줄어들었다!" << endl;
		life -= damage;
	}
	void heal(int heart) {
		life += heart;
		if (life > 100) {
			life = 100;
		}
	}
	void increaseExp(int _exp) { exp += _exp; }
	void die() {
		cout << "캐릭터가 사망하였습니다...." << endl;
		Sleep(1000);
		cout << "캐릭터의 정보가 초기화됩니다..." << endl;
		life = 100;
		exp = 0;
		level = 1;
		money = 0;
		weapon = 0;
		Sleep(1000);
		system("cls");
	}

	void fullinform() {
		cout << "이름: " << name << ", 나이: " << age << ", 경험치: " << exp << ", 레벨: " << level << ", 골드: " << money << endl << endl;
	}
	void fullinform2() {
		cout << "이름: " << name << ", 나이: " << age << ", 경험치: " << exp << ", 레벨: " << level << ", 골드: " << money << endl;
		if (weapon == 0)
			cout << "무기를 장착하고 있지 않습니다." << endl << endl;
		else
			cout << weaponName << "을 장착하고 있습니다." << endl << endl;
	}
	void inform() { cout << name << "의 피는 " << life << "/100 이다." << endl; }
};

class Monster {
private:
	string name;
	int hp;
	int force;
	int exp;
	int money;
public:
	Monster(string _name, int _hp, int _force, int _exp, int _money) :name(_name), hp(_hp), force(_force), exp(_exp), money(_money) {}

	string getName() const { return name; }
	int getHp() const { return hp; }
	int getforce() const { return force; }
	int getExp() const { return exp; }
	int getMoney() const { return money; }

	void damaged(int damage, Student student) {
		int weaponNum = student.getWeapon();
		if (weaponNum >= 1 && weaponNum <= 7) {
			cout << student.getWeaponSound() << endl;
			Sleep(600);
		}
		cout << name << "에게 " << damage << " + " << student.getWeaponDamage() << "만큼 피해를 주었다!" << endl;
		hp -= (damage + student.getWeaponDamage());
	}

	void appear() {
		cout << "몬스터 " << name << "이(가) 출몰했다!!!" << endl;
	}
	void fullform() { cout << "이 괴물의 Hp는 " << hp << "이고, " << "공격력은 " << force << "이다. 물리치자!" << endl << endl; }
	void inform() { cout << name << "의 Hp는 " << hp << "이다." << endl; }
};

//무기 클래스
/*
class Weapon {
private:
	string name;
	int price;
	int damage;
	int type;
public:
	Weapon(string _name, int _price, int _damage, int _type) : name(_name), price(_price), damage(_damage), type(_type) {}

	string getName() const { return name; }
	int getPrice() const { return price; }
	int getDamage() const { return damage; }
	int getType() const { return type; }

	void sound() const {
		switch (type) {
		case 0:
			cout << "칼소리" << endl;
			break;
		case 1:
			cout << "총소리" << endl;
			break;
		default:
			cout << "소리없음" << endl;
			break;
		}
	}
};
*/

void readStudentFile(vector<Student>& students) {

	string name; int age; int life; int exp; int level; int money; int weapon;
	ifstream fin("students.txt");

	fin >> name >> age >> life >> exp >> level >> money >> weapon;
	while (!fin.eof()) {
		Student a = Student(name, age, life, exp, level, money, weapon);
		students.push_back(a);
		fin >> name >> age >> life >> exp >> level >> money >> weapon;
	}
	fin.close();
}

void readMonsterFile(vector<Monster>& monsters) {
	string name; int hp; int force; int exp; int money;
	ifstream fin("monsters.txt");

	fin >> name >> hp >> force >> exp >> money;
	while (!fin.eof()) {
		Monster a = Monster(name, hp, force, exp, money);
		monsters.push_back(a);
		fin >> name >> hp >> force >> exp >> money;
	}
	fin.close();
}

void writeStudentFile(vector<Student>& students) {
	ofstream fout("students.txt");
	int studentsCnt = students.size();
	string name; int age; int life; int exp; int level; int money; int weapon;
	for (int i = 0; i < studentsCnt; i++) {
		name = students[i].getName();
		age = students[i].getAge();
		life = students[i].getLife();
		exp = students[i].getExp();
		level = students[i].getLevel();
		money = students[i].getMoney();
		weapon = students[i].getWeapon();
		fout << name << "\t" << age << "\t" << life << "\t" << exp << "\t" << level << "\t" << money << "\t" << weapon << "\t";
		fout << endl;
	}
	fout.close();
}

void findMonster() {
	//Sleep(integer) ==> integer ms 만큼 콘솔 정지  ==> ms = 0.001s
	cout << "몬스터 찾는 중";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << endl << endl;
}

void battle(vector<Student>& students, Student& student, Monster monster) {
	string weaponSound = student.getWeaponSound();
	int difficulty = 0;
	int num1, num2;
	int answer;
	monster.fullform();
	if (student.getName() == "김환이" || student.getName() == "이석호" || student.getName() == "이승민") {
		difficulty = 1;
	}
	while (true) {
		if (difficulty == 0) {
			num1 = (rand() % 9) + 1;
			num2 = (rand() % 9) + 1;
		}
		else {
			num1 = (rand() % 15) + 1;
			num2 = (rand() % 15) + 1;
		}
		student.inform();
		monster.inform();
		cout << "\n몬스터가 공격했다! 공격을 피하자!" << endl;
		cout << num1 << " 곱하기 " << num2 << "는?" << endl;
		cin >> answer;
		if (answer == (num1 * num2)) {
			cout << "정답이다! 공격을 피했다!\n" << endl;
			Sleep(1000);
			cout << "이제 내 차례다!" << endl;
			Sleep(1000);
			system("cls");
			monster.damaged(num1*num2, student);
		}
		else {
			cout << "틀렸다..." << endl;
			Sleep(1000);
			system("cls");
			student.damaged(monster.getforce());
		}

		if (student.getLife() <= 0) {
			student.die();
			writeStudentFile(students);
			break;
		}

		if (monster.getHp() <= 0) {
			student.heal(10);
			cout << "\n물리쳤다! 체력을 10만큼 회복했다!" << endl;
			Sleep(400);
			student.increaseExp(monster.getExp());
			student.increaseMoney(monster.getMoney());
			cout << monster.getMoney() << "의 골드를 얻었다! 현재 내 골드는 " << student.getMoney() << "이다!" << endl;
			cout << monster.getExp() << "의 경험치를 얻었다! 현재 내 경험치는 " << student.getExp() << "/100 이다." << endl << endl;
			Sleep(800);
			if (student.getExp() >= 100) {
				int cnt = 0;
				int exp = student.getExp();
				while (exp >= 100) {
					cnt++;
					student.levelUp();
					exp -= 100;
				}
				student.setExp(exp);

				cout << "레벨업!!" << endl;
				Sleep(400);
				cout << student.getName() << "의 레벨이 " << cnt << "만큼 올라서 " << student.getLevel() << "이(가) 되었다!" << endl << endl;
			}
			break;
		}
	}
}

void shop(vector<Student>& students, Student& student) {
	cout << "지갑에는 " << student.getMoney() << "원이 있습니다." << endl << endl;
	cout << "무엇을 구매하시겠습니까? (돌아가기: 0)" << endl;
	cout << "1. 동검(추가데미지 3) 100원 " << endl;
	cout << "2. 은검(추가데미지 10) 500원 " << endl;
	cout << "3. 금검(추가데미지 20) 1000원 " << endl;
	cout << "4. 다이아몬드검(추가데미지 50) 2000원 " << endl;
	cout << "5. 권총(추가데미지 70) 3000원 " << endl;
	cout << "6. 라이플총(추가데미지 100) 4000원 " << endl;
	cout << "7. 샷건(추가데미지 200) 6000원 " << endl;
	vector<int> price{100, 500, 1000, 2000, 3000, 4000, 6000};
	int choice;
	cin >> choice;
	system("cls");
	if (choice <= 7 && choice >= 1) {
		cout << "상점: " << price[choice - 1] << "원 입니다~" << endl;
		Sleep(800);
		if (student.useMoney(price[choice - 1])) {
			cout << "여기요~ 잔액은 " << student.getMoney() << "원 입니다." << endl << endl;
			Sleep(800);
			cout << "장착중...." << endl;
			Sleep(800);
			student.setWeapon(choice);
			writeStudentFile(students);
			Sleep(1000);
		}
	}
	else {
		system("cls");
	}
}

int main() {
	srand((unsigned int)time(NULL));
	// 캐릭터 선택
	// 몬스터 찾는중
	// 몬스터 출몰 (5번 마다 보스몹)
	// 배틀
	// 경험치 획득

	//read monsters
	vector<Monster> monsters;
	readMonsterFile(monsters);

	//choice character
	vector<Student> students;
	readStudentFile(students);
	cout << "캐릭터를 선택하십시오. 해당하는 숫자를 입력하시면 됩니다." << endl << endl;
	int a = students.size();
	for (int i = 0; i < a; i++) {
		cout << i + 1 << ". ";
		students[i].fullinform();
	}
	int choice;
	cin >> choice;
	//예외처리하기
	Student& student = students[choice - 1];
	int weaponNum = student.getWeapon();
	system("cls");
	cout << student.getName() << " 로그인 하였습니다." << endl << endl;
	student.setWeapon(weaponNum);

	while (true) {
		int monsterNum = rand() % monsters.size();
		Monster monster = monsters[monsterNum];
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1. 몬스터 찾기\n2. 상점 가기\n3. 내 정보 보기\n4. 저장\n5. 로그아웃(+저장)" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			findMonster();
			monster.appear();
			battle(students, student, monster);
			break;
		case 2:
			system("cls");
			shop(students, student);
			break;
		case 3:
			system("cls");
			cout << "<플레이어 정보>" << endl;
			student.fullinform2();
			break;
		case 4:
			system("cls");
			writeStudentFile(students);
			cout << "저장되었습니다!" << endl;
			break;
		case 5:
			writeStudentFile(students);
			exit(100);
			break;
		default:
			system("cls");
			cout << "해당 활동이 없습니다." << endl;
			break;
		}
	}
	return 0;
}