#include <iostream>
#include <fstream>

void swapToRight(int* arr, int *size) {		           // Сдвиг массива в право
	int temp = arr[*size - 1];
	for (int i = *size - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}  

void swapToLeft(int* arr, int* size) {		           // Сдвиг массива в лево
	int temp = arr[0];
	for (int i = 0; i < *size; i++) {
		arr[i] = arr[i + 1];
	}
	arr[*size - 1] = temp;
}


void save(int *arr, int *size) {					// Сохранение массива в файл в продолжение
	std::ofstream fout("out.txt", std::ios::app);
	fout << *size << std::endl;
		for (int i = 0; i < *size; i++) {
			fout << arr[i] << " ";
		}
		fout << std::endl;
		fout.close();								// Закрытие файла для записи
}				

int main(int argc, char** argv) {

	int sizeOne,
		sizeTwo,
		temp;
	std::ifstream fin("in.txt");			// Открытие файл на чтение

	fin >> sizeOne;							// Считывание размера первого массива
	int* arrOne = new int[sizeOne];			// Иницилизация первого массива
	for (int i = 0; i < sizeOne; i++) {		// Заполнение первого массива
		fin >> temp;
		arrOne[i] = temp;
	}

	fin >> sizeTwo;							// Считывание размера второго массива
	int* arrTwo = new int[sizeTwo];			// Иницилизация второго массива
	for (int i = 0; i < sizeTwo; i++) {		// Заполнение второго массива
		fin >> temp;
		arrTwo[i] = temp;
	}
	fin.close();

	std::ofstream fout("out.txt", std::ios::trunc);  // Открытие файла для записи и его очистка
	fout.close();
	
	swapToRight(arrTwo, &sizeTwo);
	save(arrTwo, &sizeTwo);							

	swapToLeft(arrOne, &sizeOne);
	save(arrOne, &sizeOne);							
	
	delete[] arrOne;								// очистка памяти
	delete[] arrTwo;

	return 0;
}