#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct City {
    char* name;
    int x;
    int y;
} City;

typedef struct Node {
    City* city;
    struct Node* next;
} Node;

typedef struct Lldb {
    Node* head;
    int size;
} Lldb;

City* create_city(char* name, int x, int y);
Node* create_node(City* city);
void insert_city_ll (Lldb* lldb, City* city);
void print_ll_db(Lldb* lldb);
void delete_by_name(Lldb* lldb, char* name);
void delete_by_coordinates(Lldb* lldb, int x, int y);
Node* search_by_name(Lldb* lldb, char* name);
Node* search_by_coordinates(Lldb* lldb, int x, int y);

int main(void)
{

    Lldb* lldb = (Lldb*)malloc(sizeof(Lldb));
    lldb->head = NULL;
    lldb->size = 0;

    City* city1 = create_city("Ahmedabad", 6, 9);
    insert_city_ll(lldb, city1);
    City* city2 = create_city("Mumbai", 9, 6);
    insert_city_ll(lldb, city2);
    City* city3 = create_city("Delhi", 3, 4);
    insert_city_ll(lldb, city3);
    City* city4 = create_city("MyCity", 5, 4);
    insert_city_ll(lldb, city4);
    City* city5 = create_city("Kolkata", 9, 4);
    insert_city_ll(lldb, city5);
    City* city6 = create_city("Chennai", 7, 9);
    insert_city_ll(lldb, city6);
    City* city7 = create_city("Indore", 9, 9);
    insert_city_ll(lldb, city7);

    print_ll_db(lldb);
    delete_by_name(lldb, "MyCity");
    print_ll_db(lldb);
    delete_by_coordinates(lldb, 9, 6);
    print_ll_db(lldb);
    Node* somecity = search_by_name(lldb, "Delhi");
    printf("%s %d %d\n", somecity->city->name, somecity->city->x, somecity->city->y);
    somecity = search_by_coordinates(lldb, 9, 9);
    printf("%s %d %d\n", somecity->city->name, somecity->city->x, somecity->city->y);

    return 0;
}

City* create_city(char* name, int x, int y)
{
    City* city = (City*)malloc(sizeof(City));
    city->name = (char*)malloc(strlen(name) + 1);
    city->name = name;
    city->x = x;
    city->y = y;
    return city;
}

Node* create_node(City* city)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->city = city;
    node->next = NULL;
    return node;
}

void insert_city_ll (Lldb* lldb, City* city)
{
    Node* node = create_node(city);
    node->next = lldb->head;
    lldb->head = node;
    lldb->size++;
}

void print_ll_db(Lldb* lldb)
{
    Node* trav = lldb->head;
    while(trav != NULL)
    {
        printf("%s %d %d\n", trav->city->name, trav->city->x, trav->city->y);
        trav = trav->next;
    }
    printf("Size of linked list (database): %d\n", lldb->size);
}

void delete_by_name(Lldb* lldb, char* name)
{
    Node* trav = lldb->head;
    if (strcmp(trav->city->name, name) == 0)
    {
        // if city is at head
        lldb->head = trav->next;
        free(trav);
        lldb->size--;
        return;
    }

    while (trav || strcmp(trav->next->city->name, name) != 0)
    {
        if (trav->next == NULL)
        {
            printf("City not found\n");
            return;
        }
        if (strcmp(trav->next->city->name, name) == 0)
        {
            Node* temp = trav->next;
            trav->next = trav->next->next;
            free(temp);
            lldb->size--;
            return;
        }

        trav = trav->next;
    }

    lldb->size--;

    return;
}

void delete_by_coordinates(Lldb* lldb, int x, int y)
{
    Node* trav = lldb->head;
    if (trav->city->x == x && trav->city->y == y)
    {
        // if city is at head
        lldb->head = trav->next;
        free(trav);
        lldb->size--;
        return;
    }

    while (trav || (trav->next->city->x != x && trav->next->city->y != y))
    {
        if (trav->next == NULL)
        {
            printf("City not found\n");
            return;
        }
        if (trav->next->city->x == x && trav->next->city->y == y)
        {
            Node* temp = trav->next;
            trav->next = trav->next->next;
            free(temp);
            lldb->size--;
            return;
        }

        trav = trav->next;
    }

    lldb->size--;

    return;
}

Node* search_by_name(Lldb* lldb, char* name)
{
    Node* trav = lldb->head;    
    while (trav || strcmp(trav->city->name, name) != 0)
    {
        if (trav->next == NULL)
        {
            printf("City not found\n");
            return NULL;
        }
        if (strcmp(trav->city->name, name) == 0)
        {
            return trav;
        }

        trav = trav->next;
    }

    return NULL;
}

Node* search_by_coordinates(Lldb* lldb, int x, int y)
{
    Node* trav = lldb->head;    
    while (trav || (trav->city->x != x && trav->city->y != y))
    {
        if (trav->next == NULL)
        {
            printf("City not found\n");
            return NULL;
        }
        if (trav->city->x == x && trav->city->y == y)
        {
            return trav;
        }

        trav = trav->next;
    }

    return NULL;
}

// get_by_coordinates()
// {
    
// }