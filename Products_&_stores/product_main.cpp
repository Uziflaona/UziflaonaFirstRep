//1. Разработать класс «Товар», содержащий информацию:
//▪ название товара,
//▪ название магазина, в котором продается товар,
//▪ стоимость товара в рублях.
//2. Для разрабатываемого класса необходимо выполнить:
//1) Описание полей класса.
//2) Конструктор без параметров, конструктор с параметрами, конструкторы копирования,
//деструктор.
//3) Перегрузку одного из бинарных операторов как метод класса.
//4) Перегрузку одного из бинарных операторов через дружественную функцию.
//5) Перегрузку одного из операторов отношения как метод класса.
//6) Перегрузку одного из операторов отношения через дружественную функцию.
//7) Перегрузку оператора присваивания.
//8) Перегрузку префиксного инкремента как метод класса.
//9) Перегрузку постфиксного инкремента через дружественную функцию.
//10) Перегрузку операторов << и >> через дружественные функции.
//3. Создать массив из объектов разработанного класса. Ввести в массив данные из текстового
//файла. Имя файла со входными данными должны вводиться из потока cin.
//4. Определить самый дорогой товар. Для сравнения использовать перегруженный оператор
//отношения, поиск элемента выполнить в отдельной процедуре.
//5. Выполнить сортировку массива методом простого выбора по стоимости товара. Для
//сортировки написать и использовать шаблон функции. Результат вывести в файл в виде
//таблицы, сделать заголовки колонок таблицы.
//6. Создать список магазинов. Результат вывести в файл в виде таблицы, сделать заголовки
//колонок таблицы
//7. Предусмотреть обработку и инициализацию исключительных ситуаций, связанных, например,
//с проверкой значения полей перед инициализацией и присваиванием

#include <clocale>
#include <vector>
#include <iostream>
#include <fstream>
#include "product.hpp"
#include "invalidproduct.hpp"
#include <iomanip>


template <typename T> //task 5
void selectionSort (T array[], int n);
Product maxProduct (Product *array, int n); //task 4

int main()
{
	setlocale (LC_ALL, " ");
	std::cout << "Product\n";
	
	Product P1;
	try
	{
		std::string name2("Vilka");
		std::string store2("C&C");
		float price2(2540);

		Product P2(name2, store2, price2);
	}
	catch (InvalidProduct& ex)
	{
		std::cerr << ex.what() << "\n";
		return 1;
	}
	//task 3	
	char fileName[128];
	std::cout<<"Name of input File: ";
	std::cin>>fileName;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Error\n";
		return 1;
	}
	
	std::size_t n;

	ifs >> n;
	Product* array = new Product[n];
	try
	{
		for (size_t i = 0; i < n; i++)
		{
			ifs >> array[i];
		}

	}
	catch (InvalidProduct& ex)
	{
		std::cerr << ex.what() << "\n";
		return 1;
	}
	
	ifs.close();

	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << std::endl;
	}
	//task 4
	std::cout << "Max Price Product:\n" << maxProduct(array, n) << std::endl;
	//task 5
	selectionSort(array, n);
	
	std::cout<<"Sorted array:\n";
	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::ofstream ofs("outArray.txt");
	ofs << std::setw(30) << "Name of Product|"; 
	ofs << std::setw(20) << "Name of Shop|"; 
	ofs << std::setw(25) << "Price|\n";
	for (size_t i = 0; i < n; i++)
		ofs << array[i] << std::endl;
	ofs.close();
	//Task 6
	
	std::string *shopArray = new std::string [n];
	for (size_t i = 0; i < n; i++)
		shopArray[i] = array[i].getShop();
	int shopLenght = n;
	for (int m = 0; m < shopLenght; m++)  // removing duplicate elements
	{
		for (int i = m+1; i < shopLenght; i++) 
		{
			if (shopArray[m] == shopArray[i]) 
			{
				for (int k = i; k < shopLenght - 1; k++) 
				{
					shopArray[k] = shopArray[k + 1];
				}
				shopLenght--;
			}
		}
	}

	std::cout << "store list:\n";
	for (int i = 0; i < shopLenght; i++)
		std::cout << shopArray[i] << std::endl;

	ofs.open("outShops.txt");
	ofs << std::setw(20) << "Name of Shop|"; 
	ofs << std::setw(30) << "Name of Product|"; 
	ofs << std::setw(25) << "Price|\n";

	for (int i = 0; i < shopLenght; i++)
	{
		ofs << shopArray[i] << std::endl;
		for (int j = 0; j < n; j++)
		{
			if (shopArray[i] == array[j].getShop())
			{
				printShop(ofs, array[j]);
				ofs << std::endl;
			}
		}
	}
	ofs.close();
}

Product maxProduct (Product *array, int n) //task 4
{
	Product productMax = array[0];
	for (int i = 0; i < n; i++)
	{
		if (productMax < array[i])
			productMax = array[i];
	}
	return productMax;
}	

template <typename T> //task 5
void selectionSort(T array[], int n) 
{
	int min;
	T temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
			min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}
