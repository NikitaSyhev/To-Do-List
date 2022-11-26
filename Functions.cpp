#include <iostream>
#include "Functions.h"
#include <fstream>
#include <ctime>
#include <string>





void show_menu() {
	std::cout << "Выберите действие:" << "\n\n";
	std::cout << "1. Добавить задачу в свой список." << '\n';
	std::cout << "2. Посмотреть список задач." << '\n';
	std::cout << "3. Найти задачу и работать с ней." << '\n';
	std::cout << "4. Очистить список задач." << '\n';
	std::cout << "5. Выход из программы." << '\n';
}

void add_note(std::string& str) {
	std::string path = "file.txt";
	std::ofstream out;
	out.open(path, std::ios::app);
	if (out.is_open()) {
		out << str << '\n';
	}
	else
		std::cout << "Ошибка добавления задачи.\n";

	out.close();
}

void add_note_status(std::string& str) {
	std::string path = "file.txt";
	std::ofstream out;
	out.open(path, std::ios::app);

	if (out.is_open()) {
		std::string tmp;
		out << "Срок выполнения и статус: " << str + "\n";
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	std::cout << "Задача успешно добавлена.\n";

	out.close();
}

void show_note() {
	std::ifstream in;
	in.open("file.txt");
	std::string str;
	if (!in.is_open()) {
		std::cout << "Задачи еще не добавлены. Добавьте их!.\n";
		return;
	}

	for (int i = 1; !in.eof(); i++) {
		getline(in, str);
		if (str.empty()) continue;
		if (i % 2 != 0)
			std::cout << str << '\n';
	}
	in.close();
}

void delete_all_notes() {
	remove("file.txt");
}

std::string* find_one_note(const std::string& note_no_find, int& n_count) {
	std::ifstream file("file.txt");
	if (!file.is_open()) {
		std::cout << "Задачи еще не добавлены!\n";
		return nullptr;
	}
	std::string one_note;
	std::string* found_notes = nullptr;
	std::string* found_notes_tmp = nullptr;
	int count = 0; // количество найденных заметок
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.find(note_no_find) != -1) {
			count++;
			found_notes_tmp = new std::string[count];
			for (int i = 0; i < count - 1; i++)
				found_notes_tmp[i] = found_notes[i];
			found_notes_tmp[count - 1] = one_note;

			delete[] found_notes;

			found_notes = found_notes_tmp;
			found_notes_tmp = nullptr;
		}
	}
	file.close();
	n_count = count; 

	return found_notes;

}



// возвращает указатель на массив всех задач
std::string* all_notes(int& n_count) {
	std::string* all_notes_tmp = nullptr;
	std::string* all_notes = nullptr;

	std::ifstream file("file.txt");
	if (!file.is_open()) {
		std::cout << "Задачи еще не записаны.\n";
		exit(EXIT_FAILURE);
	}
	std::string one_note;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		count++;
		all_notes_tmp = new std::string[count];

		for (int i = 0; i < count - 1; i++)
			all_notes_tmp[i] = all_notes[i];

		all_notes_tmp[count - 1] = one_note;
		delete[] all_notes;

		all_notes = all_notes_tmp;
		all_notes_tmp = nullptr;
	}

	n_count = count;
	file.close();
	
	return all_notes;

}

void remove_one_note() {



}
