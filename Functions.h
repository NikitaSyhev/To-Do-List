#pragma once


void show_menu();  // ������� ������ ����

void add_note(std::string& str); //������� ���������� �������

void add_note_status(std::string& str); // ������� ���������� ���� ���������� � ������� ���������� �����

void show_note();//������� ������ ���� �������

void delete_all_notes();// ������� �������� �������

std::string* find_one_note(const std::string& note_no_find, int &n_count);   //������� ������ ������ �� ��������� �����




std::string* all_notes(int& n_count); // ����������� ������� � ������

void remove_one_note(); // �������� 1 �������