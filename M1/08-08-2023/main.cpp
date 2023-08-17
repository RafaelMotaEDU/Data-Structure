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
void liberarLUE(LUE<T> &list)
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
