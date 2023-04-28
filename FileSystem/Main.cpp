#include <iostream>
#include <string>
#include <fstream> //библиотека работы с файловой системой компьютера

bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	return false;
}

bool statistic(std::string word);

bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);
	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//std::string path = "file.txt"; //путь к файлу в котором будем взаимодействовать
	//Класс ofstream
	/*std::ofstream out; //объект класса ofstream для записи данных ф-лов
	//или std::ofstream out(path);
	out.open(path,std::ios::app); //открытие файла в режиме app

	if (out.is_open()) { //проверка ф-ла на открытие 
		std::cout << "Файл открыт для записи\n";
		std::string str;
		std::cout << "Введите строку:\n";
		std::getline(std::cin, str);
		out << str<<'\n'; //добавление информации в ф-л
		std::cout << "запись добавлена в файл.\n";
	}
	else
		std::cout << "Ошибка открытия файла";
	//возможные причины ошибок при открытии файла:
	//1.Неправильный синтаксис указания пути к файлу;
	//2.Нет доступа к файлу;
	//3.Файл открыт другим объектом или приложением;
	out.close(); //закрытие ф-ла и очистка объекта*/
	//Класс ifstream
	/*std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт\n";
		std::cout << "Содержимое файла:\n";
		std::string file_text;

		//Посимвольное считывание
		//char sym;
		//while (in.get(sym))
			//std::cout << sym; //только вывод
		//	file_text += sym; //вывод и сохранение в строке
		//std::cout << file_text << std::endl;

		//Пословное считывание
		//while (!in.eof()) {
			//std::string tmp;
			//in >> tmp;
			//file_text += tmp+'\n';
		//}
		//std::cout << file_text << std::endl;

		//Построчное считывание
		std::string line;
		while (std::getline(in, line))
			file_text += line+'\n';
		std::cout << file_text << std::endl;
	}
  
    else
		std::cout << "Ошибка открытия\n";*/
		




	//Возможные причины ошибок при открытии файла
	//1.Не правильный синтаксис  указания пути к файлу;
	//2.Нет доступа к ф-лу;
	//3.Файла не существует.


	//in.close(); //закрытие ф-ла 

	//Удаление ф-ла
	/*if (remove(path.c_str()) == 0) {
		std::cout << "Файл \" " << path << "\" удален.\n";
	}
	else
		std::cout << "Ошибка удаления ф-ла\n";*/

	//Возможные причины ошибок при открытии файла
	//1.Не правильный синтаксис  указания пути к файлу;
	//2.Нет доступа к ф-лу;
	//3.Файла не существует.
	//4.Если ф-л открыт.

	//Задача1. Слова в ф-л и их длина
	std::cout << "Задача 1.\n";
	int action;
	do {
		std::cout << "Выберите действие:\n";
		std::cout << "1.Добавление статистики в файл;\n";
		std::cout << "2.Вывод файла;\n";
		std::cout << "3.Очистка файла;\n";
		std::cout << "4.Завершение работы;\n";
		std::cout << "Введите номер действия:\n";
		std::cin >> action;
		std::string str1;
		switch (action) {
		case 1:
			std::cout << "Введите строку:\n";
			std::cin.ignore();
			std::getline(std::cin, str1);

			if (statistic(str1)) {
				std::cout << "Запись добавлена\n";
				std::cout << "Содержимое файла:\n";
				print_file("stats.txt");
			}
			else
				std::cout << "Ошибка выполнения ф-ции\n";
			break;
		case 2:
			std::cout << "Содержимое файла:\n";
			print_file("stats.txt");
			break;
		case 3:
			clear_file("stats.txt");
			std::cout << "Файл очищен";
			break;
		default:
			std::cout << "Ошибка ввода.\n\n";

		}
	}while (action != 4);

	/*std::string str1;
	std::getline(std::cin, str1);

	if (statistic(str1)) {
		std::cout << "Запись добавлена\n";
		std::cout << "Содержимое файла:\n";
		print_file("stats.txt");
     }
	else
		std::cout << "Ошибка выполнения ф-ции\n";
	} while (action!=4);*/


	return 0;
}

bool statistic(std::string word) {
	std::ofstream out;
	out.open("stats.txt",std::ios::app);

	if (out.is_open()) {
		out << word << ' ' << word.length() << '\n';
		out.close();
		return true;
     }
	return false;

}