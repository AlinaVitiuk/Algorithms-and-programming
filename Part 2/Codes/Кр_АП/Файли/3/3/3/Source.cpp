#pragma warning(disable:4996);
#include <iostream>
#include <ctime>
#include <cstring>
#include <Windows.h>

using namespace std;

const int userInputSize = BUFSIZ;

struct Node {             // ��������� ��� ��������� �����
    unsigned int value;
    Node* next;
};

struct FIFO {             // ��������� ��� ��������� ������
    Node* head = nullptr; // ������ ������� � ����
    Node* tail = nullptr; // ������� ������� � ����
    void addNewNode(unsigned int newValue); // ������ ��� ������� �������� � ����� �����
    void showElementsInFIFO() const; // ������ ��� ������ �������� � ����
    void ifElementNotRepeatedAddToFIFO(int); // ������� ���� ������� �� �����, ���� �� �� ������������
    void deleteQueue();   // ��������� ��� �������� � ������
};

inline int randomNumber(int);
inline bool onlyNumberChecker(char const*, unsigned int); //������� ��� �������� �� ������ ���������� ����� � ����
void enterNumber(char*&); // ������� ��� ����� �����, �� ���������� � ������

int main() {
    SetConsoleOutputCP(1251); //������������ ��������� Windows-1251 ��� ��������� �����
    srand(unsigned(time(nullptr)));
    FIFO* queue = new FIFO;
    char* elementsAmountInStr;
    int elementsAmount;
    enterNumber(elementsAmountInStr);
    elementsAmount = atoi(elementsAmountInStr);
    delete[] elementsAmountInStr;
    int* array = new int[elementsAmount];
    cout << "�����: \n";
    int newElement;
    for (int i = 0; i < elementsAmount; ++i) {
        newElement = randomNumber(10);
        array[i] = newElement;
        cout << newElement << " ";
        queue->ifElementNotRepeatedAddToFIFO(newElement);
    }
    cout << "\n���� ����� ��� ������������ ��������: \n";
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
    cout << "������ �����: ";
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
            cout << "�������������� ���� ��� �����! >:c\n";
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