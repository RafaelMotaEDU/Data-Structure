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
    for (int index = 0; index <= list.lastIndex; index++)
    {
        if (value == list.array[index])
        {
            return index;
        }
    }
    return -1;
}

bool remove(List &list, char value)
{
    int position = search(list, value);

    if (position == -1)
        return false;

    list.lastIndex--;

    for (int index = position; index <= list.lastIndex; index++)
    {
        list.array[index] = list.array[index + 1];
    }

    return true;
}

bool remove(List &list, int position)
{
    if (position < 0 || position > list.lastIndex)
        return false;

    list.lastIndex--;

    for (int index = position; index <= list.lastIndex; index++)
    {
        list.array[index] = list.array[index + 1];
    }
    return true;
}

bool removeAll(List &list, char value)
{
    int amountFound = 0;
    int indexValue = search(list, value);

    while (indexValue != -1)
    {
        amountFound++;
        remove(list, indexValue);
        indexValue = search(list, value);
    }

    return amountFound == 0 ? true : false;
}

List cloneList(List list)
{
    List newList = list;
    return newList;
}

void show(List list)
{
    for (int index = 0; index <= list.lastIndex; index++)
    {
        cout << list.array[index] << " ";
    }
}

int main()
{
    List l1;

    initialize(l1);

    insert(l1, 'P', ' ');
    insert(l1, 'E', ' ');
    insert(l1, 'R', ' ');
    insert(l1, 'N', ' ');
    insert(l1, 'A', ' ');
    insert(l1, 'M', ' ');
    insert(l1, 'M', ' ');
    insert(l1, 'M', ' ');
    insert(l1, 'A', ' ');
    insert(l1, 'E', ' ');
    insert(l1, 'A', ' ');

    List clonedList = cloneList(l1);

    cout << endl
         << "List: ";

    show(l1);
    cout << endl
         << "List cloned: ";
    show(clonedList);
}
