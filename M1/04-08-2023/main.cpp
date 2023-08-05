#include <iostream>

using namespace std;

#define MAXIMUM 20

struct List
{
    char array[MAXIMUM];
    int lastIndex;
};

void initialize(List &list)
{
    list.lastIndex = -1;
}

bool insert(List &list, char value, char sort = ' ')
{
    int position;

    if (list.lastIndex == (MAXIMUM - 1))
        return false;

    switch (sort)
    {
    case 'C':
        position = 0;

        while (position <= list.lastIndex && value > list.array[position])
            position++;
        list.lastIndex++;

        for (int index = list.lastIndex; index > position; index--)
        {
            list.array[index] = list.array[index - 1];
        }
        list.array[position] = value;
        break;
    case 'D':
        position = 0;

        while (position <= list.lastIndex && value < list.array[position])
            position++;
        list.lastIndex++;

        for (int index = list.lastIndex; index > position; index--)
        {
            list.array[index] = list.array[index - 1];
        }
        list.array[position] = value;
        break;
    default:
        list.lastIndex++;
        list.array[list.lastIndex] = value;
        break;
    }
    return true;
}

int search(List list, char value)
{
}

bool remove(List &list, char value)
{
}

bool remove(List &list, int position)
{
}

void show(List list)
{
    for (int index = 0; index <= list.lastIndex; index++)
    {
        cout << list.array[index] << "\t";
    }
}

int main()
{
    List l1;

    cout << l1.lastIndex << endl;

    initialize(l1);
    cout << l1.lastIndex << endl;
    insert(l1, 'P', 'D');
    insert(l1, 'E', 'D');
    insert(l1, 'R', 'D');
    insert(l1, 'N', 'D');
    insert(l1, 'A', 'D');
    insert(l1, 'M', 'D');

    cout << endl
         << "List: ";
    show(l1);
}
