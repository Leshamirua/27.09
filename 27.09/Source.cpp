#include <iostream>
using namespace std;
// Тема: 

struct Element {
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	List();
	~List();

	void Add(char data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
	char GetAmount(char& symbol);
	char AddSymbol(char& symbol, int pos);
	char DelSymbol(int pos);

};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

char List::GetAmount(char& symbol) {
	Element* temp = Head;

	cout << "Enter symbol: ";
	cin >> symbol;

	int i = 1, count = 0;
	while (temp != 0) {
		if (temp->data == symbol) {
			break;
		}
		temp = temp->Next;
		i++;
	}
	if (i == 18) {
		cout << "Didn't find symbol " << symbol << endl;
		return 0;
	}
	cout << "index = " << i << endl;
	return i;
}

char List::AddSymbol(char& symbol, int pos) {
	Element* temp = Head;

	cout << "Enter symbol and position: ";
	cin >> symbol >> pos;

	for (int i = 1; i <= pos; i++) {
		temp = temp->Next;
	}
	temp->data = symbol;

	return temp->data;
}

char List::DelSymbol(int pos) {
	Element* temp = Head;
	cout << "Enter position: ";
	cin >> pos;

	for (int i = 1; i <= pos; i++) {
		temp = temp->Next;
	}
	Element* temp2 = temp->Next;
	delete temp;

	while (temp2->data != 0) {
		temp2 = temp2->Next;
	}
	return temp2->data;
}



void main() {
	List lst;

	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";

	int len = strlen(s); // Определяем длину строки
	for (int i = 0; i < len; i++) {
		lst.Add(s[i]);
	}
	lst.Print();

	char answer;
	cout << static_cast<int>(lst.GetAmount(answer));

	lst.AddSymbol(answer, 2);

	lst.DelSymbol(4);

	lst.Print();

}
