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
void inicializateLDE(LDE<T> &list)
{
    list.start = NULL;
    list.end = NULL;
}

template <typename T>
void showLDE(LDE<T> list, char sort = 'C')
{
    Node<T> *aux = sort == 'C' ? list.start : list.end;

    while (aux != NULL)
    {
        cout << aux->info << " ";
        aux = sort == 'C' ? aux->eloP : aux->eloA;
    }
    if (list.start == NULL)
        cout << "<Vazio>";
}

template <typename T>
bool insertLDE(LDE<T> &list, T valor)
{
    Node<T> *novo;

    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->eloP = NULL;
    novo->eloA = NULL;

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
        novo->eloP = list.start;
        list.start->eloA = novo;
        list.start = novo;
        return true;
    }

    // put the value at the end of the list
    if (valor > list.end->info)
    {
        list.end->eloP = novo;
        novo->eloA = list.end;
        list.end = novo;
        return true;
    }

    // put the value in the middle of the list
    Node<T> *aux = list.start;
    while (aux->info < valor && aux->eloP->info < valor)
        aux = aux->eloP;

    novo->eloA = aux;
    novo->eloP = aux->eloP;
    aux->eloP->eloA = novo;
    aux->eloP = novo;
    return true;
}

//
// Always insert the given value End of list node
//
template <typename T>
bool inserirFinalLDE(LDE<T> &list, T valor)
{
    Node<T> *novo;

    // Create a new node
    novo = new Node<T>;
    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->eloP = NULL;

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
Node<T> *searchLDE(LDE<T> list, T valor)
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
bool removeLDE(LDE<T> &list, T valor)
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
void releaseLDE(LDE<T> &list)
{
    Node<T> *aux = list.start;
    Node<T> *aux2;

    while (aux != NULL)
    {
        aux2 = aux->eloA;
        aux2 = aux->eloP;
        delete aux;
        aux = aux2;
    }
}

int main()
{
    LDE<char> list1;

    inicializateLDE(list1);

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
         << "list 1 C: ";
    showLDE(list1);

    cout << endl
         << "list 1 D: ";
    showLDE(list1, 'D');

    cout << endl;
    // Node<char> *aux = searchLDE(list1, 'M');
    // if (aux == NULL)
    //     cout << "Informacao nao localizada";
    // else
    //     cout << "Informacao esta na list";

    // removeLDE(list1, 'A');
    // removeLDE(list1, 'U');
    // removeLDE(list1, 'N');
    // removeLDE(list1, 'E');
    // removeLDE(list1, 'R');
    // removeLDE(list1, 'O');

    // cout << endl
    //      << "list 1: ";
    // showLDE(list1);

    // removeLDE(list1, 'B');
    // removeLDE(list1, 'C');
    // removeLDE(list1, 'M');
    // removeLDE(list1, 'P');

    // cout << endl
    //      << "list 1: ";
    // showLDE(list1);

    releaseLDE(list1);

    cout << endl;
}
