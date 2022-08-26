// system(string) ==> �ܼ�â�� string�� �Է���
// cls  ==> clean screen, �� �ܼ�â�� û������ ===> system(cls)�ϸ� �ܼ�â ������
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
		cout << "����!! ������ ������ ���ؼ� "<< name << "�� Life�� " << damage << "��ŭ �پ�����!" << endl;
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
		Sleep(1000);
		system("cls");
	}

	void fullinform() { cout << "�̸�: " << name << ", ����: " << age << ", ����ġ: " << exp << ", ����: " << level << endl << endl; }
	void inform() { cout << name << "�� �Ǵ� " << life << "/100 �̴�." << endl; }
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
		cout << name << "���� " << damage << "��ŭ ���ظ� �־���!" << endl;
		hp -= damage;
	}

	void appear() {
		cout << "���� " << name << "��(��) ����ߴ�!!!" << endl;
	}
	void fullform() { cout << "�� ������ Hp�� " << hp << "�̰�, " << "���ݷ��� " << force << "�̴�. ����ġ��!" << endl << endl; }
	void inform() { cout << name << "�� Hp�� " << hp << "�̴�." << endl; }
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
	//Sleep(integer) ==> integer ms ��ŭ �ܼ� ����  ==> ms = 0.001s
	cout << "���� ã�� ��";
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
			monster.damaged(num1*num2);
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
			cout << monster.getExp() << "�� ����ġ�� �����! ���� �� ����ġ�� " << student.getExp() << "/100 �̴�." << endl << endl;
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
				
				cout << "������!!" << endl;
				Sleep(400);
				cout << student.getName() << "�� ������ " << cnt << "��ŭ �ö� " << student.getLevel() << "��(��) �Ǿ���!" << endl << endl;
			}
			break;
		}
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
		cout << i+1 << ". ";
		students[i].fullinform();
	}
	int choice;
	cin >> choice;
	//����ó���ϱ�
	Student& student = students[choice - 1];
	system("cls");
	cout << student.getName() << " �α��� �Ͽ����ϴ�." << endl << endl;

	while (true) {
		int monsterNum = rand() % monsters.size();
		Monster monster = monsters[monsterNum];
		cout << "������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. ���� ã��\n2. �� ���� ����\n3. ����\n4. �α׾ƿ�(+����)" << endl;
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
			cout << "<�÷��̾� ����>" << endl;
			student.fullinform();
			break;
		case 3:
			system("cls");
			writeStudentFile(students);
			cout << "����Ǿ����ϴ�!" << endl;
			break;
		case 4:
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