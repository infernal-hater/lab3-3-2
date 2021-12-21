#include <iostream>
#include <cmath>	     // std::sqrt()
#include <vector>    // std::vector<>

#include <new>       // std::bad_alloc
#include <stdexcept> // std::out_of_range, std::domain_error
#include <typeinfo>  // std::bad_cast
using namespace std;

int main() {
	// Программа предлагает ввести номер исключения из задания, которое она сымитирует
	cout << "1 - bad_alloc\n" << "2 - out_of_range\n" << "3 - domain_error\n" << "4 - bad_cast\n\n";
	cout << "Enter the number of excetion you want to imitate: ";
	char choice;
	cin >> choice;

	try
	{
		switch (choice) {
		case '1': {
			// Слишком много памяти
			new int[1000000000000];
			break;
		}
		case '2': {
			// Выбираем элемент вне границ вектора
			vector<int> vector;
			vector.at(-1);
			break;
		}
		case '3': {
			// Корень из -1
			sqrt(-1);
			break;
		}
		case '4': {
			// Создаем два полиморфных несвязанных класса и приводим тип одного класса к другому никак несвязанному классу
		class A { public: virtual ~A() {} };
		class B { public: virtual ~B() {} };
						B object_b;
						A& object_a = dynamic_cast<A&>(object_b);

						break;
		}
		default:
			cout << "wrong number...";
			break;
		}
	}
	// ловим исключения и выводим их через метод what()
	catch (const bad_alloc& exc) {
		cout << "Bad_alloc exception: " << exc.what() << "\n";
	}
	catch (const out_of_range& exc) {
		cout << "Out_of_range exception: " << exc.what() << "\n";
	}
	catch (const domain_error& exc) {
		cout << "Domain_error exception: " << exc.what() << "\n";
	}
	catch (const bad_cast& exc) {
		cout << "Bad_cast exception: " << exc.what() << "\n";
	}
	catch (...) {
		cout << "Unkown exception..." << endl;
	}

	return 0;
}