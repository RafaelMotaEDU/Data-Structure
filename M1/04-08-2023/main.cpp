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

List concatList(List list1, List list2, char sort = ' ')
{

    List newList;
    initialize(newList);

    for (int index = 0; index <= list1.lastIndex; index++)
    {
        insert(newList, list1.array[index], sort);
    }

    for (int index = 0; index <= list2.lastIndex; index++)
    {
        insert(newList, list2.array[index], sort);
    }

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
    List l2;

    initialize(l1);
    initialize(l2);

    insert(l1, 'D');
    insert(l1, 'F');
    insert(l1, 'A');

    insert(l2, 'C');
    insert(l2, 'B');
    insert(l2, 'G');

    cout << endl
         << "List: ";

    show(l1);

    // List clone = cloneList(l1);
    // insert(clone, 'D');
    // insert(clone, 'E');
    // insert(clone, 'F');

    cout << endl
         << "List: ";
    show(l2);

    cout << endl
         << "List concat: ";

    List concat = concatList(l1, l2, 'C');
    show(concat);

    cout << endl;
    cout << concat.lastIndex;
}
