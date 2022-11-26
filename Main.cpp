//���� ������ ������ � ������� ������������� �������
#include <iostream>
#include"Functions.h"
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstdlib>    


int main() {
	setlocale(LC_ALL, "Russian");
	int user_menu;   // ���������� ��� ������������ ����
	std::string note;// ���������� ����� ��� ���������� ������� � ����
	std::string note_date_status;// ���������� ����� ��� ���������� ������� ������� � ����
	int task_edit;// ���������� ����� ��� ������ � �������� ( �������������, ������� )
	


	SYSTEMTIME st; // ������� ���������� �� ��������, ����� ������������, ��� ��� ��� �������, ����� ������� �����
	GetLocalTime(&st);
	std::cout << "Today's date: \n";
	std::cout << "Month:" << st.wMonth << '\n';
	std::cout << "Date:" << st.wDay << '\n';
	std::cout << "\n\n";


	setlocale(LC_ALL, "Russian");
	std::cout << "Welcome to Your Task Manager!\n����� �� ������ ����� ���� ����������� ���, ��������� ����� ������, �������������� ��������.\n\n";
	show_menu();
	std::cout << "�������� ����� ����: ";
	std::cin >> user_menu; 

	std::cout << "\n";
	if (user_menu == 1) {
		system("cls");
		std::getline(std::cin, note);
		std::cout << " �������� ������: ";
		std::getline(std::cin, note);
		add_note(note);

		std::cout << "�������� ���� ���������� � ������: ��������� - 1, �� ��������� - 0.\n ";
		std::getline(std::cin, note_date_status);
		add_note_status(note_date_status);
		system("pause");
	}
	else
		if (user_menu == 2) {
			system("cls");
			std::cout << "�� ������ ������ �����:\n";
			show_note();
			system("pause");
		}
	else
		if (user_menu == 3) {
			system("cls");
			std::string note_to_find; //��������� ���������� ��� ������ ������� �� ��������� �����
			std::getline(std::cin, note_to_find);
			std::cout << "����� ������ �� ��������� �����: \n";
			std::getline(std::cin, note_to_find);
			int n_found = 0;//���������� ��� ����������� ������� �������
			std::string* found_notes = find_one_note(note_to_find, n_found);


			std::cout << "��������� ������: \n";
			for (int i = 0; i < n_found; i++) 
				std::cout << *(found_notes) << '\n';
			delete[] found_notes;
			
			std::cout << "��� ������� � ���� �������?\n1. �������.\n2. ���������������.\n3. �������� ��� �����������.\n";
		std::cin >> task_edit;
		if (task_edit == 1) {
			system("cls");
			int n_all_notes = 0;//���������� ��� ����������� ������� �������
			
			std::string* all_notes_arr = all_notes(n_all_notes); // ���������� ��� ����������� ����� � ������
		
			for (int i = 0; i < n_all_notes; i++)
				std::cout << all_notes_arr << '\n';


			system("pause");
		}
		if (task_edit == 2) {

		}
		if (task_edit == 3) {

		}
		system("pause");
		}
	else
			if (user_menu == 4) {
				system("cls");
			std::cout << "�� �������� ������ ���� �����.\n";
			delete_all_notes();
			system("pause");
		}
			else
				if (user_menu == 5) {
					system("cls");
					std::cout << "������ ��������� ���������. �������� � ��������� ���!\n";
					system("pause");
				}






















	return 0;
}