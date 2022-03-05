#include "Priority_Queue.h"


Priority_Queue& Priority_Queue::operator=(Priority_Queue& q) 
{
    // �������� � ���������� ��������
    Element* current = q.back;

    if (front == NULL)
    {
        Element* new_node = new Element;
        new_node->data = current->data;
        new_node->priority = current->priority;
        new_node->prev = NULL;
        front = new_node;
        back = new_node;

        current = current->prev;
    }

    while (current != NULL)
    {
        Element* new_node = new Element;
        new_node->data = current->data;
        new_node->priority = current->priority;
        new_node->prev = NULL;
        front->prev = new_node;
        front = new_node;

        current = current->prev;
    }
    return *this;
}




void Priority_Queue::count_priority()
{
    int my_priority, counter = 0;
    cout << "������� ���������(1 - ������ ���������, 2 - ������� ���������, 3 - ������� ���������)\n-> ", cin >> my_priority;
    Element* current = back;

    while (current != NULL)
    {
        if (current->priority == my_priority)
            counter++;
        current = current->prev;

    }
    cout << "��������� � ����������� " << my_priority << " -> " << counter << endl;
}





void Priority_Queue::count_all() 
{
    int counter = 0;

    Element* current = back;

    while (current != NULL) 
    {
        current = current->prev;
        counter++;
    }
    cout << "��������� � ������� -> " << counter << endl;
}



bool Priority_Queue::empty() 
{
    if (front == NULL)
    {
        cout << "������� �����!\n";
        return true;
    }
    else 
    {
        cout << "������� �� �����!\n";
        return false;
    }
}



void Priority_Queue::get_front() 
{
    cout << "���������� � ������ �������� �������: ";
    if (front->priority == 1)
    {
        cout << front->data << ", ��������� - ������.";
    }
    if (front->priority == 2)
    {
        cout << front->data << ", ��������� - �������.";
    }
    if (front->priority == 3)
    {
        cout << front->data << ", ��������� - �������.";
    }
}



void Priority_Queue::pop()
{
    
    Element* current = back; 
    if (current->prev != NULL) {
        while (current->prev != front) 
        {
            current = current->prev;
        }
        front = current;
        current->prev = NULL;
    }
    else 
    {
        front = NULL;
        back = NULL;
    }
}



void Priority_Queue::add(int new_data, int new_priority)
{
    // ��������������� �����
    Element* temp = NULL;
    Element* tail = NULL;

    // �������� � ���������� ��������
    Element* new_node = new Element;
    new_node->data = new_data;
    new_node->priority = new_priority;
    new_node->prev = NULL;

    if (front != NULL)// ���� � ������ ���������� ��������
    {

        new_node->prev = back; // ����� ������� ����������� ����� ����������
        back = new_node; // ����������� ���������� ���������
        Element* current = back; // current - �������� �������

        switch (new_node->priority)
        {
        case 1:
            while (current->prev->priority < 1)
            {
                if (current->prev == front) 
                {
                    if (current == back)
                        back = current->prev;

                    /// ����� ��������� ///
                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1
                    ////////////////////

                    front = current;
                }
                else 
                {
                    if (current == back)
                        back = current->prev;

                    /// ����� ����� ///
                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1
                    ////////////////////
                }

                if (current->prev == NULL)
                    break;
            }
        case 2:
            while (current->prev->priority < 2)
            {
                if (current->prev == front)
                {
                    if (current == back)
                        back = current->prev;

                    /// ����� ����� ///
                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1
                    ////////////////////

                    front = current;
                }
                else 
                {
                    if (current == back)
                        back = current->prev;

                    /// ����� ����� ///
                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1
                    ////////////////////
                }

                if (current->prev == NULL)
                    break;
            }
            break;
        case 3:
            while (current->prev->priority < 3)
            {
                if (current->prev == front) 
                {
                    if (current == back)
                        back = current->prev;

                    /// ����� ��������� ///
                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1
                    ////////////////////

                    front = current;
                }
                else
                {
                    if (current == back) 
                    {
                        back = current->prev;
                        tail = back;
                    }

                    temp = current->prev;
                    current->prev = current->prev->prev; // 1 -> 3
                    temp->prev = current; // 2 -> 1

                    tail->prev = temp;
                    tail = temp;
                }

                if (current->prev == NULL)
                    break;
            }
            break;
        }
        // }
    }
    else { // ���� ������ ����, ������� ����� �������� ����������� �������
        front = new_node;
        back = new_node;
    }

}
Priority_Queue::Priority_Queue(Priority_Queue& q)
{
    // �������� � ���������� ��������
    Element* current = q.back;

    if (front == NULL)
    {
        Element* new_node = new Element;
        new_node->data = current->data;
        new_node->priority = current->priority;
        new_node->prev = NULL;
        front = new_node;
        back = new_node;

        current = current->prev;
    }

    while (current != NULL)
    {
        Element* new_node = new Element;
        new_node->data = current->data;
        new_node->priority = current->priority;
        new_node->prev = NULL;
        front->prev = new_node;
        front = new_node;

        current = current->prev;
    }
}


void Priority_Queue::push()
{
    int new_data = 0, new_priority = 0;
    cout << "������� ������ (�����)\n-> ", cin >> new_data;
    cout << "������� ��������� (1 - ������ ���������, 2 - ������� ���������, 3 - ������� ���������)\n-> ", cin >> new_priority;
    if (new_priority < 1 || new_priority > 3)
    {
        throw exception("���������� ����� ���� ������ 1, 2, 3");
    }
    add(new_data, new_priority);
}



void Priority_Queue::print()
{
    Element* current = back;
    cout << "\n��� �������� ������:\n";
    if (current == NULL)
    {
        cout << "������ ����";
    }
    else
    {
        
        cout << "����� -> ";
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->prev;
        }
        cout << "������\n";
    }
}