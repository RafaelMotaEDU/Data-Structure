#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T info;
    Node *eloA, *eloP;
};

template <typename T>
struct LDE
{
    Node<T> *start;
    Node<T> *end;
};

template <typename T>
void inicializeLDE(LDE<T> &list)
{
    list.start = NULL;
    list.end = NULL;
}

template <typename T>
void showLDE(LDE<T> list, char sort = 'C')
{
    Node<T> *aux;

    aux = (sort == 'C') ? list.start : list.end;
    while (aux != NULL)
    {
        cout << aux->info << " ";
        aux = (sort == 'C') ? aux->eloP : aux->eloA;
    }
    if (list.start == NULL)
        cout << "<Vazio>";
}

template <typename T>
bool insertLDE(LDE<T> &list, T value)
{
    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = value;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    if (value <= list.start->info)
    {
        novo->eloP = list.start;
        list.start->eloA = novo;
        list.start = novo;
        return true;
    }

    if (value >= list.end->info)
    {
        list.end->eloP = novo;
        novo->eloA = list.end;
        list.end = novo;
        return true;
    }

    Node<T> *previous = list.start;
    while (previous->info < value && previous->eloP->info <= value)
        previous = previous->eloP;
    Node<T> *next = previous->eloP;

    novo->eloA = previous;
    novo->eloP = next;
    previous->eloP = novo;
    next->eloA = novo;
    return true;
}

template <typename T>
bool insertEndLDE(LDE<T> &list, T value)
{
    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = value;
    novo->eloA = NULL;
    novo->eloP = NULL;

    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    list.end->eloP = novo;
    novo->eloA = list.end;
    list.end = novo;
    return true;
}

template <typename T>
Node<T> *searchLDE(LDE<T> list, T value)
{
    Node<T> *aux = list.start;

    while (aux != NULL)
    {
        if (aux->info == value)
            return aux;
        aux = aux->eloP;
    }
    return NULL;
}

template <typename T>
bool removeLDE(LDE<T> &list, T value)
{
    Node<T> *aux, *previous, *next;

    aux = searchLDE(list, value);

    if (aux == NULL)
        return false;
    previous = aux->eloA;
    next = aux->eloP;

    if (aux == list.start)
    {
        list.start = next;
        if (aux == list.end)
            list.end = NULL;
        else
            next->eloA = NULL;
    }
    else
    {
        previous->eloP = aux->eloP;
        if (aux == list.end)
            list.end = previous;
        else
            next->eloA = previous;
    }
    delete aux;
    return true;
}

template <typename T>
void releaseLDE(LDE<T> &list)
{
    Node<T> *aux = list.start;
    Node<T> *aux2;

    while (aux != NULL)
    {
        aux2 = aux->eloP;
        delete aux;
        aux = aux2;
    }
}

int main()
{
    LDE<char> list1;

    inicializeLDE(list1);

    insertLDE(list1, 'P');
    insertLDE(list1, 'E');
    insertLDE(list1, 'R');
    insertLDE(list1, 'N');
    insertLDE(list1, 'A');
    insertLDE(list1, 'M');
    insertLDE(list1, 'B');
    insertLDE(list1, 'U');
    insertLDE(list1, 'C');
    insertLDE(list1, 'O');

    cout << endl
         << "list 1 (C): ";
    showLDE(list1);
    cout << endl
         << "list 1 (D): ";
    showLDE(list1, 'D');

    removeLDE(list1, 'A');
    removeLDE(list1, 'U');
    removeLDE(list1, 'N');
    removeLDE(list1, 'E');
    removeLDE(list1, 'R');
    removeLDE(list1, 'O');

    cout << endl
         << "list 1: ";
    showLDE(list1);

    removeLDE(list1, 'B');
    removeLDE(list1, 'C');
    removeLDE(list1, 'M');
    removeLDE(list1, 'P');

    cout << endl
         << "list 1: ";
    showLDE(list1);

    releaseLDE(list1);

    cout << endl;
}
