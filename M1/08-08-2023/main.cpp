#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T info;
    Node *elo;
};

template <typename T>
struct LSE
{
    Node<T> *start;
    Node<T> *end;
};

template <typename T>
void inicializateLSE(LSE<T> &list)
{
    list.start = NULL;
    list.end = NULL;
}

template <typename T>
void showLSE(LSE<T> list)
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
bool insertLSE(LSE<T> &list, T valor)
{
    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->elo = NULL;

    // empty list
    if (list.start == NULL)
    {
        list.start = novo;
        list.end = novo;
        return true;
    }

    // Put the value at the beginning of the list
    if (valor < list.start->info)
    {
        novo->elo = list.start;
        list.start = novo;
        return true;
    }

    // put the value at the end of the list
    if (valor > list.end->info)
    {
        list.end->elo = novo;
        list.end = novo;
        return true;
    }

    // put the value in the middle of the list
    Node<T> *aux = list.start;
    while (aux->info < valor && aux->elo->info < valor)
        aux = aux->elo;

    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

//
// Always insert the given value End of list node
//
template <typename T>
bool inserirFinalLSE(LSE<T> &list, T valor)
{
    Node<T> *novo;

    // Create a new node
    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->elo = NULL;

    // empty list
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
Node<T> *searchLSE(LSE<T> list, T valor)
{
    Node<T> *aux = list.start;

    while (aux != NULL)
    {
        if (aux->info == valor)
            return aux;
        aux = aux->elo;
    }
    return NULL;
}

template <typename T>
bool removeLSE(LSE<T> &list, T valor)
{
    Node<T> *aux = list.start, *anterior = NULL;

    while (aux != NULL && aux->info != valor)
    {
        anterior = aux;
        aux = aux->elo;
    }
    if (aux == NULL)
        return false;

    if (aux == list.start)
    { // Cases 1 e 2
        list.start = list.start->elo;
        if (aux == list.end)
            list.end = NULL;
    }
    else
    { // Cases 3 e 4
        anterior->elo = aux->elo;
        if (aux == list.end)
            list.end = anterior;
    }
    delete aux;
    return true;
}

template <typename T>
void releaseLSE(LSE<T> &list)
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
    LSE<char> list1;

    inicializateLSE(list1);

    insertLSE(list1, 'P');
    insertLSE(list1, 'E');
    insertLSE(list1, 'R');
    insertLSE(list1, 'N');
    insertLSE(list1, 'A');
    insertLSE(list1, 'M');
    insertLSE(list1, 'B');
    insertLSE(list1, 'U');
    insertLSE(list1, 'C');
    insertLSE(list1, 'O');

    cout << endl
         << "list 1: ";
    showLSE(list1);

    cout << endl;
    Node<char> *aux = searchLSE(list1, 'M');
    if (aux == NULL)
        cout << "Informacao nao localizada";
    else
        cout << "Informacao esta na list";

    removeLSE(list1, 'A');
    removeLSE(list1, 'U');
    removeLSE(list1, 'N');
    removeLSE(list1, 'E');
    removeLSE(list1, 'R');
    removeLSE(list1, 'O');

    cout << endl
         << "list 1: ";
    showLSE(list1);

    removeLSE(list1, 'B');
    removeLSE(list1, 'C');
    removeLSE(list1, 'M');
    removeLSE(list1, 'P');

    cout << endl
         << "list 1: ";
    showLSE(list1);

    releaseLSE(list1);

    cout << endl;
}
