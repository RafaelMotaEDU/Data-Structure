#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T info;
    Node *elo;
};

template <typename T>
struct LUE
{
    Node<T> *start;
    Node<T> *end;
};

template <typename T>
void inicializeLUE(LUE<T> &list)
{
    list.start = NULL;
    list.end = NULL;
}

template <typename T>
void showLUE(LUE<T> list)
{
    Node<T> *aux = list.start;

    while (aux != NULL)
    {
        cout << aux->info << " ";
        aux = aux->elo;
    }
    if (list.start == NULL)
        cout << "<Vazio>";
}

template <typename T>
bool insertLUE(LUE<T> &list, T value)
{

    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = value;
    novo->elo = NULL;

    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    if (value <= list.start->info)
    {
        novo->elo = list.start;
        list.start = novo;
        return true;
    }

    if (value >= list.end->info)
    {
        list.end->elo = novo;
        list.end = novo;
        return true;
    }

    Node<T> *aux = list.start;
    while (aux->info < value && aux->elo->info <= value)
        aux = aux->elo;

    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

template <typename T>
bool insertLUE_D(LUE<T> &list, T value)
{

    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = value;
    novo->elo = NULL;

    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    if (value >= list.start->info)
    {
        novo->elo = list.start;
        list.start = novo;
        return true;
    }

    if (value <= list.end->info)
    {
        list.end->elo = novo;
        list.end = novo;
        return true;
    }

    Node<T> *aux = list.start;
    while (aux->info > value && aux->elo->info >= value)
        aux = aux->elo;

    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

template <typename T>
bool insertEndLUE(LUE<T> &list, T value)
{
    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = value;
    novo->elo = NULL;

    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    list.end->elo = novo;
    list.end = novo;
    return true;
}

template <typename T>
Node<T> *searchLUE(LUE<T> list, T value)
{
    Node<T> *aux = list.start;

    while (aux != NULL)
    {
        if (aux->info == value)
            return aux;
        aux = aux->elo;
    }
    return NULL;
}

template <typename T>
bool removeLUE(LUE<T> &list, T value)
{
    Node<T> *aux = list.start, *previous = NULL;

    while (aux != NULL && aux->info != value)
    {
        previous = aux;
        aux = aux->elo;
    }
    if (aux == NULL)
        return false;

    if (aux == list.start)
    {
        list.start = list.start->elo;
        if (aux == list.end)
            list.end = NULL;
    }
    else
    {
        previous->elo = aux->elo;
        if (aux == list.end)
            list.end = previous;
    }
    delete aux;
    return true;
}

template <typename T>
void releaseLUE(LUE<T> &list)
{
    Node<T> *aux = list.start;
    Node<T> *aux2;

    while (aux != NULL)
    {
        aux2 = aux->elo;
        delete aux;
        aux = aux2;
    }
}

int main()
{
    LUE<char> list1;

    inicializeLUE(list1);

    insertLUE(list1, 'P');
    insertLUE(list1, 'E');
    insertLUE(list1, 'R');
    insertLUE(list1, 'N');
    insertLUE(list1, 'A');
    insertLUE(list1, 'M');
    insertLUE(list1, 'B');
    insertLUE(list1, 'U');
    insertLUE(list1, 'C');
    insertLUE(list1, 'O');

    cout << endl
         << "Lista 1: ";
    showLUE(list1);

    removeLUE(list1, 'A');
    removeLUE(list1, 'U');
    removeLUE(list1, 'N');
    removeLUE(list1, 'E');
    removeLUE(list1, 'R');
    removeLUE(list1, 'O');

    cout << endl
         << "list 1: ";
    showLUE(list1);

    removeLUE(list1, 'B');
    removeLUE(list1, 'C');
    removeLUE(list1, 'M');
    removeLUE(list1, 'P');

    cout << endl
         << "list 1: ";
    showLUE(list1);

    releaseLUE(list1);

    cout << endl;
}
