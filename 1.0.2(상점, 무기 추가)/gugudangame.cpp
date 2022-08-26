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
			weaponName = "��";
			weaponDamage = 0;
			weaponSound = "";
			break;
		case 1:
			weaponName = "����";
			weaponDamage = 3;
			weaponSound = "Ǫ��!!!!!!!!!";
			break;
		case 2:
			weaponName = "����";
			weaponDamage = 10;
			weaponSound = "��!!!!!!!!!!!!!!!!!!";
			break;
		case 3:
			weaponName = "�ݰ�";
			weaponDamage = 20;
			weaponSound = "�ž�!! Ǫ����!!!";
			break;
		case 4:
			weaponName = "���̾Ƹ���";
			weaponDamage = 50;
			weaponSound = "��!! �ž�!! Ǫ����������������!!!";
			break;
		case 5:
			weaponName = "����";
			weaponDamage = 70;
			weaponSound = "��!!!! ��!!!!!!!!!!!!!!!!";
			break;
		case 6:
			weaponName = "��������";
			weaponDamage = 100;
			weaponSound = "ŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸŸ��!!!";
			break;
		case 7:
			weaponName = "����";
			weaponDamage = 200;
			weaponSound = "��!!! ��!!!";
			break;
		default:
			weaponName = "����";
			weaponDamage = 0;
			weaponSound = "";
			break;
		}
		cout << weaponName << "�� �����Ͽ����ϴ�! ���Ϳ��� �ִ� ���ط��� " << weaponDamage << "��ŭ �����մϴ�." << endl << endl;
	}

	void levelUp() { level++; }

	void increaseMoney(int _money) { money += _money; }
	bool useMoney(int _money) {
		if (money >= _money) {
			money -= _money;
			return true;
		}
		else {
			cout << "���� ���ڶ��ϴ�..." << endl << endl;
			return false;
		}
	}

	void damaged(int damage) {
		cout << "����!! ������ ������ ���ؼ� " << name << "�� Life�� " << damage << "��ŭ �پ�����!" << endl;
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
		cout << "ĳ���Ͱ� ����Ͽ����ϴ�...." << endl;
		Sleep(1000);
		cout << "ĳ������ ������ �ʱ�ȭ�˴ϴ�..." << endl;
		life = 100;
		exp = 0;
		level = 1;
		money = 0;
		weapon = 0;
		Sleep(1000);
		system("cls");
	}

	void fullinform() {
		cout << "�̸�: " << name << ", ����: " << age << ", ����ġ: " << exp << ", ����: " << level << ", ���: " << money << endl << endl;
	}
	void fullinform2() {
		cout << "�̸�: " << name << ", ����: " << age << ", ����ġ: " << exp << ", ����: " << level << ", ���: " << money << endl;
		if (weapon == 0)
			cout << "���⸦ �����ϰ� ���� �ʽ��ϴ�." << endl << endl;
		else
			cout << weaponName << "�� �����ϰ� �ֽ��ϴ�." << endl << endl;
	}
	void inform() { cout << name << "�� �Ǵ� " << life << "/100 �̴�." << endl; }
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
		cout << name << "���� " << damage << " + " << student.getWeaponDamage() << "��ŭ ���ظ� �־���!" << endl;
		hp -= (damage + student.getWeaponDamage());
	}

	void appear() {
		cout << "���� " << name << "��(��) ����ߴ�!!!" << endl;
	}
	void fullform() { cout << "�� ������ Hp�� " << hp << "�̰�, " << "���ݷ��� " << force << "�̴�. ����ġ��!" << endl << endl; }
	void inform() { cout << name << "�� Hp�� " << hp << "�̴�." << endl; }
};

//���� Ŭ����
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
			cout << "Į�Ҹ�" << endl;
			break;
		case 1:
			cout << "�ѼҸ�" << endl;
			break;
		default:
			cout << "�Ҹ�����" << endl;
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
	//Sleep(integer) ==> integer ms ��ŭ �ܼ� ����  ==> ms = 0.001s
	cout << "���� ã�� ��";
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
	if (student.getName() == "��ȯ��" || student.getName() == "�̼�ȣ" || student.getName() == "�̽¹�") {
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
		cout << "\n���Ͱ� �����ߴ�! ������ ������!" << endl;
		cout << num1 << " ���ϱ� " << num2 << "��?" << endl;
		cin >> answer;
		if (answer == (num1 * num2)) {
			cout << "�����̴�! ������ ���ߴ�!\n" << endl;
			Sleep(1000);
			cout << "���� �� ���ʴ�!" << endl;
			Sleep(1000);
			system("cls");
			monster.damaged(num1*num2, student);
		}
		else {
			cout << "Ʋ�ȴ�..." << endl;
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
			cout << "\n�����ƴ�! ü���� 10��ŭ ȸ���ߴ�!" << endl;
			Sleep(400);
			student.increaseExp(monster.getExp());
			student.increaseMoney(monster.getMoney());
			cout << monster.getMoney() << "�� ��带 �����! ���� �� ���� " << student.getMoney() << "�̴�!" << endl;
			cout << monster.getExp() << "�� ����ġ�� �����! ���� �� ����ġ�� " << student.getExp() << "/100 �̴�." << endl << endl;
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

				cout << "������!!" << endl;
				Sleep(400);
				cout << student.getName() << "�� ������ " << cnt << "��ŭ �ö� " << student.getLevel() << "��(��) �Ǿ���!" << endl << endl;
			}
			break;
		}
	}
}

void shop(vector<Student>& students, Student& student) {
	cout << "�������� " << student.getMoney() << "���� �ֽ��ϴ�." << endl << endl;
	cout << "������ �����Ͻðڽ��ϱ�? (���ư���: 0)" << endl;
	cout << "1. ����(�߰������� 3) 100�� " << endl;
	cout << "2. ����(�߰������� 10) 500�� " << endl;
	cout << "3. �ݰ�(�߰������� 20) 1000�� " << endl;
	cout << "4. ���̾Ƹ���(�߰������� 50) 2000�� " << endl;
	cout << "5. ����(�߰������� 70) 3000�� " << endl;
	cout << "6. ��������(�߰������� 100) 4000�� " << endl;
	cout << "7. ����(�߰������� 200) 6000�� " << endl;
	vector<int> price{100, 500, 1000, 2000, 3000, 4000, 6000};
	int choice;
	cin >> choice;
	system("cls");
	if (choice <= 7 && choice >= 1) {
		cout << "����: " << price[choice - 1] << "�� �Դϴ�~" << endl;
		Sleep(800);
		if (student.useMoney(price[choice - 1])) {
			cout << "�����~ �ܾ��� " << student.getMoney() << "�� �Դϴ�." << endl << endl;
			Sleep(800);
			cout << "������...." << endl;
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
	// ĳ���� ����
	// ���� ã����
	// ���� ��� (5�� ���� ������)
	// ��Ʋ
	// ����ġ ȹ��

	//read monsters
	vector<Monster> monsters;
	readMonsterFile(monsters);

	//choice character
	vector<Student> students;
	readStudentFile(students);
	cout << "ĳ���͸� �����Ͻʽÿ�. �ش��ϴ� ���ڸ� �Է��Ͻø� �˴ϴ�." << endl << endl;
	int a = students.size();
	for (int i = 0; i < a; i++) {
		cout << i + 1 << ". ";
		students[i].fullinform();
	}
	int choice;
	cin >> choice;
	//����ó���ϱ�
	Student& student = students[choice - 1];
	int weaponNum = student.getWeapon();
	system("cls");
	cout << student.getName() << " �α��� �Ͽ����ϴ�." << endl << endl;
	student.setWeapon(weaponNum);

	while (true) {
		int monsterNum = rand() % monsters.size();
		Monster monster = monsters[monsterNum];
		cout << "������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. ���� ã��\n2. ���� ����\n3. �� ���� ����\n4. ����\n5. �α׾ƿ�(+����)" << endl;
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
			cout << "<�÷��̾� ����>" << endl;
			student.fullinform2();
			break;
		case 4:
			system("cls");
			writeStudentFile(students);
			cout << "����Ǿ����ϴ�!" << endl;
			break;
		case 5:
			writeStudentFile(students);
			exit(100);
			break;
		default:
			system("cls");
			cout << "�ش� Ȱ���� �����ϴ�." << endl;
			break;
		}
	}
	return 0;
}