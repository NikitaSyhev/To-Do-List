//Этот проект создан с помощью классического шаблона
#include <iostream>
#include"Functions.h"
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <cstdlib>    


int main() {
	setlocale(LC_ALL, "Russian");
	int user_menu;   // переменная для переключения менб
	std::string note;// переменная нужна для добавления заметок в файл
	std::string note_date_status;// переменная нужна для добавления статуса заметок в файл
	int task_edit;// переменная нужна для работы с заметкой ( редактировать, удалить )
	


	SYSTEMTIME st; // вставил библиотеку со временем, чтобы отображалось, так как это дневник, время текущее нужно
	GetLocalTime(&st);
	std::cout << "Today's date: \n";
	std::cout << "Month:" << st.wMonth << '\n';
	std::cout << "Date:" << st.wDay << '\n';
	std::cout << "\n\n";


	setlocale(LC_ALL, "Russian");
	std::cout << "Welcome to Your Task Manager!\nЗдесь ты можешь вести учет выполненных дел, добавлять новые задачи, контролировать дедлайны.\n\n";
	show_menu();
	std::cout << "Выберете пункт меню: ";
	std::cin >> user_menu; 

	std::cout << "\n";
	if (user_menu == 1) {
		system("cls");
		std::getline(std::cin, note);
		std::cout << " Добавьте задачу: ";
		std::getline(std::cin, note);
		add_note(note);

		std::cout << "Добавьте дату выполнения и статус: выполнено - 1, не выполнено - 0.\n ";
		std::getline(std::cin, note_date_status);
		add_note_status(note_date_status);
		system("pause");
	}
	else
		if (user_menu == 2) {
			system("cls");
			std::cout << "Вы видите список задач:\n";
			show_note();
			system("pause");
		}
	else
		if (user_menu == 3) {
			system("cls");
			std::string note_to_find; //строковая переменная для поиска заметки по ключевому слову
			std::getline(std::cin, note_to_find);
			std::cout << "Поиск задачи по ключевому слову: \n";
			std::getline(std::cin, note_to_find);
			int n_found = 0;//переменная для определения размера массива
			std::string* found_notes = find_one_note(note_to_find, n_found);


			std::cout << "Выбранные задачи: \n";
			for (int i = 0; i < n_found; i++) 
				std::cout << *(found_notes) << '\n';
			delete[] found_notes;
			
			std::cout << "Что сделать с этой задачей?\n1. Удалить.\n2. Отредактировать.\n3. Отметить как выполненную.\n";
		std::cin >> task_edit;
		if (task_edit == 1) {
			system("cls");
			int n_all_notes = 0;//переменная для определения размера массива
			
			std::string* all_notes_arr = all_notes(n_all_notes); // переменная для копирования файла в массив
		
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
			std::cout << "Вы очистили список всех задач.\n";
			delete_all_notes();
			system("pause");
		}
			else
				if (user_menu == 5) {
					system("cls");
					std::cout << "Работа программы завершена. Увидимся в следующий раз!\n";
					system("pause");
				}






















	return 0;
}