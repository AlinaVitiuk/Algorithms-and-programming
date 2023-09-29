#pragma warning(disable:4996);
#include <iostream>
#include <ctime>
#include <cstring>
#include <Windows.h>

using namespace std;

const int userInputSize = BUFSIZ;

struct Node {             // Структура для реалізації вузла
    unsigned int value;
    Node* next;
};

struct FIFO {             // Структура для реалізації списку
    Node* head = nullptr; // Перший елемент у черзі
    Node* tail = nullptr; // Останній елемент у черзі
    void addNewNode(unsigned int newValue); // Фукція для додання елементу у кінець черги
    void showElementsInFIFO() const; // Фукція для виводу елементів у черзі
    void ifElementNotRepeatedAddToFIFO(int); // Функція додає елемент до черги, якщо він не повторюється
    void deleteQueue();   // Видалення усіх елементів у списку
};

inline int randomNumber(int);
inline bool onlyNumberChecker(char const*, unsigned int); //Функція для перевірки чи стрічка складається тільки з цифр
void enterNumber(char*&); // Функція для вводу числа, що зберігається у стрічку

int main() {
    SetConsoleOutputCP(1251); //встановлення кодування Windows-1251 для виведення даних
    srand(unsigned(time(nullptr)));
    FIFO* queue = new FIFO;
    char* elementsAmountInStr;
    int elementsAmount;
    enterNumber(elementsAmountInStr);
    elementsAmount = atoi(elementsAmountInStr);
    delete[] elementsAmountInStr;
    int* array = new int[elementsAmount];
    cout << "Масив: \n";
    int newElement;
    for (int i = 0; i < elementsAmount; ++i) {
        newElement = randomNumber(10);
        array[i] = newElement;
        cout << newElement << " ";
        queue->ifElementNotRepeatedAddToFIFO(newElement);
    }
    cout << "\nНова черга без повторюваних елементів: \n";
    queue->showElementsInFIFO();
    queue->deleteQueue();
    delete queue;
    delete[] array;
    return 0;
}

void FIFO::ifElementNotRepeatedAddToFIFO(int newValue) {
    bool isElementRepeated = false;
    auto* newNode = new Node;
    newNode->next = nullptr;
    newNode->value = newValue;
    if (head != nullptr) {
        Node* temp = head;
        while (temp != nullptr) {
            if (newValue == temp->value) isElementRepeated = true;
            temp = temp->next;
        }
        if (!isElementRepeated) {
            tail->next = newNode;
            tail = newNode;
        }
    }
    else {
        head = tail = newNode;
    }
}

void enterNumber(char*& number) {
    cout << "Введіть число: ";
    char str[userInputSize];
    int strLen;
    do {
        cin.getline(str, userInputSize - 1);
        strLen = strlen(str);
    } while (!onlyNumberChecker(str, strLen));
    number = new char[strLen + 1];
    strcpy(number, str);
}

bool onlyNumberChecker(char const* userData, unsigned int lineLength) {
    for (int i = 0; i < lineLength; i++) {
        if (!(('0' <= int(*(userData + i))) && (int(*(userData + i)) <= '9') || (i == 0) && (*(userData + i) == '-'))) {
            cout << "Використовуйте лише цілі числа! >:c\n";
            return false;
        }
    }
    return true;
}

inline int randomNumber(int maxRandomNumber) {
    return rand() % (maxRandomNumber + 1);
}

void FIFO::showElementsInFIFO() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void FIFO::addNewNode(unsigned int newValue) {
    auto* temp = new Node;
    temp->next = nullptr;
    temp->value = newValue;
    if (head != nullptr) {
        tail->next = temp;
        tail = temp;
    }
    else {
        head = tail = temp;
    }
}

void FIFO::deleteQueue() {
    Node* next;
    while (head) {
        next = head->next;
        delete head;
        head = next;
    }
}