#include <iostream>
using namespace std;

//структура стека
struct stack
{
    string data;
    stack* prev;
};

//размер стека
int sizeStack(stack* head) {
	int count = 0;
	while (head) {
		count++;
		head = head->prev;
	}
	return count;
}

//адрес последнего элемента стека
stack* getLast(stack* head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->prev) {
		head = head->prev;
	}
	return head;
}

//Добавление нового элемента в ПУСТОЙ стек
void pushEmpty(stack** head, string data) {
	void* ex_raw = malloc(sizeof(stack)); //!!что это? выделение памяти на структуру стека?
	stack* tmp = new(ex_raw) stack; //!!указатель на..? выделенную память?
	tmp->data = data;
	tmp->prev = (*head);
	(*head) = tmp;
}

//Добавление нового элемента на верхушку стека
void pushBack(stack* head, string value) {
	stack* last = getLast(head);
	void* ex_raw = malloc(sizeof(stack));
	stack* tmp = new(ex_raw) stack;
	tmp->data = value;
	tmp->prev = NULL;
	last->prev = tmp;
}

//инициализация стека
void push (stack*& stk, const string& token) {
	if (!stk)
		pushEmpty(&stk, token);
	else
		pushBack(stk, token);
}

//удаление стека
void deleteStack(stack** head) {
	stack* prev = NULL;
	while ((*head)->prev) {
		prev = (*head);
		(*head) = (*head)->prev;
		free(prev);
	}
	free(*head);
}

//Вывод стека на экран/в файл
void printStack(const stack* head, ofstream& fout, bool console) {
	while (head) {
		if (!console)
			fout << head->data << " ";
		else {
			cout << head->data << " ";
			fout << head->data << " ";
		}
		head = head->prev;
	}
	if (!console)
		fout << endl;
	else {
		cout << endl;
		fout << endl;
	}
	return;
}

//Считывание элемента с вершины стека (с его удалением)
string pop(stack** head) {
	stack* prev = NULL;
	string val;
	if (head == NULL) {
		exit(-1); // считано все выражение - окончание работы
	}
	prev = (*head);
	val = prev->data;
	(*head) = (*head)->prev;
	free(prev);
	return val;
}

int main()
{

    return 0;
}