#pragma once


void show_menu();  // функция вызова меню

void add_note(std::string& str); //функция добавления заметок

void add_note_status(std::string& str); // функция добавления даты выполнения и статуса выполнения задач

void show_note();//функция показа всех заметок

void delete_all_notes();// функция удаления заметок

std::string* find_one_note(const std::string& note_no_find, int &n_count);   //функция поиска задачи по ключевому слову




std::string* all_notes(int& n_count); // копирование заметок в массив

void remove_one_note(); // удаление 1 заметки