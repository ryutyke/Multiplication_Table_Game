// system(string) ==> 콘솔창에 string을 입력함
// cls  ==> clean screen, 즉 콘솔창을 청소해줌 ===> system(cls)하면 콘솔창 지워짐
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
public:
	Student(string _name, int _age, int _life, int _exp, int _level) :name(_name), age(_age), life(_life), exp(_exp), level(_level) {}

	string getName() const { return name; }
	int getAge() const { return age; }
	int getLife() const { return life; }
	int getExp() const { return exp; }
	int getLevel() const { return level; }

	void setLife(int _life) { life = _life; }
	void setExp(int _exp) { exp = _exp; };
	void setLevel(int _level) { level = _level; }
	void levelUp() { level++; }

	void damaged(int damage) { 
		cout << "으악!! 공격을 피하지 못해서 "<< name << "의 Life가 " << damage << "만큼 줄어들었다!" << endl;
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
		Sleep(1000);
		system("cls");
	}

	void fullinform() { cout << "이름: " << name << ", 나이: " << age << ", 경험치: " << exp << ", 레벨: " << level << endl << endl; }
	void inform() { cout << name << "의 피는 " << life << "/100 이다." << endl; }
};

class Monster {
private:
	string name;
	int hp;
	int force;
	int exp;
public:
	Monster(string _name, int _hp, int _force, int _exp) :name(_name), hp(_hp), force(_force), exp(_exp) {}

	string getName() const { return name; }
	int getHp() const { return hp; }
	int getforce() const { return force; }
	int getExp() const { return exp; }

	void damaged(int damage) {
		cout << name << "에게 " << damage << "만큼 피해를 주었다!" << endl;
		hp -= damage;
	}

	void appear() {
		cout << "몬스터 " << name << "이(가) 출몰했다!!!" << endl;
	}
	void fullform() { cout << "이 괴물의 Hp는 " << hp << "이고, " << "공격력은 " << force << "이다. 물리치자!" << endl << endl; }
	void inform() { cout << name << "의 Hp는 " << hp << "이다." << endl; }
};

void readStudentFile(vector<Student>& students) {
	
	string name; int age; int life; int exp; int level;
	ifstream fin("students.txt");

	fin >> name >> age >> life >> exp >> level;
	while (!fin.eof()) {
		Student a = Student(name, age, life, exp, level);
		students.push_back(a);
		fin >> name >> age >> life >> exp >> level;
	}
	fin.close();
}

void readMonsterFile(vector<Monster>& monsters) {
	string name; int hp; int force; int exp;
	ifstream fin("monsters.txt");

	fin >> name >> hp >> force >> exp;
	while (!fin.eof()) {
		Monster a = Monster(name, hp, force, exp);
		monsters.push_back(a);
		fin >> name >> hp >> force >> exp;
	}
	fin.close();
}

void writeStudentFile(vector<Student>& students) {
	ofstream fout("students.txt");
	int studentsCnt = students.size();
	string name; int age; int life; int exp; int level;
	for (int i = 0; i < studentsCnt; i++) {
		name = students[i].getName();
		age = students[i].getAge();
		life = students[i].getLife();
		exp = students[i].getExp();
		level = students[i].getLevel();
		fout << name << "\t" << age << "\t" << life << "\t" << exp << "\t" << level << "\t";
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
	cout << endl<< endl;
}

void battle(vector<Student>& students, Student& student, Monster monster) {
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
			monster.damaged(num1*num2);
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
			cout << monster.getExp() << "의 경험치를 얻었다! 현재 내 경험치는 " << student.getExp() << "/100 이다." << endl << endl;
			Sleep(800);
			if (student.getExp() >= 100) {
				int cnt=0;
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
		cout << i+1 << ". ";
		students[i].fullinform();
	}
	int choice;
	cin >> choice;
	//예외처리하기
	Student& student = students[choice - 1];
	system("cls");
	cout << student.getName() << " 로그인 하였습니다." << endl << endl;

	while (true) {
		int monsterNum = rand() % monsters.size();
		Monster monster = monsters[monsterNum];
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1. 몬스터 찾기\n2. 내 정보 보기\n3. 저장\n4. 로그아웃(+저장)" << endl;
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
			cout << "<플레이어 정보>" << endl;
			student.fullinform();
			break;
		case 3:
			system("cls");
			writeStudentFile(students);
			cout << "저장되었습니다!" << endl;
			break;
		case 4:
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