#include <iostream>
#include <vector>

class PrinterQueue { // имитирует очередь печати
private:
	std::vector<std::string> queue; // используем стандартный контейнер std::vector для хранения элементов очереди

public:
	void enqueue(const std::string& item) { //  добавляет новый элемент в конец очереди. 
		queue.push_back(item);
	}

	void dequeue() { // удаляет и выводит первый элемент из очереди. 
		if (!queue.empty()) {
			std::cout << "Печать: " << queue.front() << std::endl;
			queue.erase(queue.begin());
		}
		else {
			std::cout << "Пустая очередь" << std::endl;
		}
	}

	void removeAtIndex(int index) { // удаляют элементы по указанному индексу соответственно.
		if (index >= 0 && index < queue.size()) {
			queue.erase(queue.begin() + index);
		}
		else {
			std::cout << "Не входит в диапазон" << std::endl;
		}
	}

	void insertAtIndex(const std::string& item, int index) { // добавляют элементы по указанному индексу соответственно.
		if (index >= 0 && index <= queue.size()) { 
			queue.insert(queue.begin() + index, item);
		}
		else {
			std::cout << "Не входит в диапазон" << std::endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	PrinterQueue pq;

	pq.enqueue("Document1");
	pq.enqueue("Document2");
	pq.enqueue("Document3");

	pq.dequeue(); // Print Document1
	pq.removeAtIndex(1); // Remove Document2

	pq.insertAtIndex("NewDocument", 1); // Insert NewDocument at position 1

	return 0;
}
// Задание
// Разработайте приложение в объектно - ориентированном
// стиле, имитирующее очередь печати принтера.На печать
// передаются строки, встающие в очередь.С помощью
// специального метода можно выводить первый из очереди
// элемент в консоль.Также добавьте возможность удаление
// элемента из очереди(по индексу) и добавление элемента в
// произвольное место очереди(по индексу).