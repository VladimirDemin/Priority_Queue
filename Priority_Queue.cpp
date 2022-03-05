#include "Priority_Queue.h"


Priority_Queue& Priority_Queue::operator=(Priority_Queue& q) 
{
    // Создание и заполнение Элемента
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
    cout << "Введите приоритет(1 - низкий приоритет, 2 - средний приоритет, 3 - высокий приоритет)\n-> ", cin >> my_priority;
    Element* current = back;

    while (current != NULL)
    {
        if (current->priority == my_priority)
            counter++;
        current = current->prev;

    }
    cout << "Элементов с приоритетом " << my_priority << " -> " << counter << endl;
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
    cout << "Элементов в очереди -> " << counter << endl;
}



bool Priority_Queue::empty() 
{
    if (front == NULL)
    {
        cout << "Очередь пуста!\n";
        return true;
    }
    else 
    {
        cout << "Очередь не пуста!\n";
        return false;
    }
}



void Priority_Queue::get_front() 
{
    cout << "Информация о первом элементе очереди: ";
    if (front->priority == 1)
    {
        cout << front->data << ", приоритет - низкий.";
    }
    if (front->priority == 2)
    {
        cout << front->data << ", приоритет - средний.";
    }
    if (front->priority == 3)
    {
        cout << front->data << ", приоритет - высокий.";
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
    // Вспомогательные метки
    Element* temp = NULL;
    Element* tail = NULL;

    // Создание и заполнение Элемента
    Element* new_node = new Element;
    new_node->data = new_data;
    new_node->priority = new_priority;
    new_node->prev = NULL;

    if (front != NULL)// ЕСли в списке существуют элементы
    {

        new_node->prev = back; // Новый элемент добавляется после последнего
        back = new_node; // Добавленный становится последним
        Element* current = back; // current - итератор очереди

        switch (new_node->priority)
        {
        case 1:
            while (current->prev->priority < 1)
            {
                if (current->prev == front) 
                {
                    if (current == back)
                        back = current->prev;

                    /// ОБМЕН ЭЛЕМЕНТОВ ///
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

                    /// ОБМЕН УЗЛОВ ///
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

                    /// ОБМЕН УЗЛОВ ///
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

                    /// ОБМЕН УЗЛОВ ///
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

                    /// ОБМЕН Элементов ///
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
    else { // Если список пуст, началом будет являться добавляемый элемент
        front = new_node;
        back = new_node;
    }

}
Priority_Queue::Priority_Queue(Priority_Queue& q)
{
    // Создание и заполнение Элемента
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
    cout << "Введите данные (число)\n-> ", cin >> new_data;
    cout << "Введите приоритет (1 - низкий приоритет, 2 - средний приоритет, 3 - высокий приоритет)\n-> ", cin >> new_priority;
    if (new_priority < 1 || new_priority > 3)
    {
        throw exception("Приоритеты могут быть только 1, 2, 3");
    }
    add(new_data, new_priority);
}



void Priority_Queue::print()
{
    Element* current = back;
    cout << "\nВсе элементы списка:\n";
    if (current == NULL)
    {
        cout << "Список пуст";
    }
    else
    {
        
        cout << "конец -> ";
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->prev;
        }
        cout << "начало\n";
    }
}