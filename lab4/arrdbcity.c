#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct City {
    char* name;
    int x;
    int y;
} City;

typedef struct Arrdb {
    City** citiesarr;
    int size;
    int capacity;
} Arrdb;

City* create_city(char* name, int x, int y);
Arrdb* init_arr_db(int int_cap);
void insert_city_arr(Arrdb* arrdb, City* city);
void delete_by_name(Arrdb* arrdb, char* name);
void delete_by_coordinates(Arrdb* arrdb, int x, int y);
void print_arr_db(Arrdb* arrdb);

int main(void)
{   
    
    Arrdb* arrdb = init_arr_db(2);
    City* city1 = create_city("Ahmedabad", 6, 9);
    insert_city_arr(arrdb, city1);
    City* city2 = create_city("Mumbai", 9, 6);
    insert_city_arr(arrdb, city2);
    City* city3 = create_city("Delhi", 3, 4);
    insert_city_arr(arrdb, city3);
    City* city4 = create_city("MyCity", 5, 4);
    insert_city_arr(arrdb, city4);
    City* city5 = create_city("Kolkata", 9, 4);
    insert_city_arr(arrdb, city5);
    City* city6 = create_city("Chennai", 7, 9);
    insert_city_arr(arrdb, city6);
    City* city7 = create_city("Indore", 9, 9);
    insert_city_arr(arrdb, city7);

    print_arr_db(arrdb);
    delete_by_name(arrdb, "Delhi");
    print_arr_db(arrdb);
    delete_by_coordinates(arrdb, 9, 4);
    print_arr_db(arrdb);

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

Arrdb* init_arr_db(int init_cap)
{
    Arrdb* arrdb = (Arrdb*)malloc(sizeof(Arrdb));
    arrdb->citiesarr = (City**)malloc(sizeof(City*) * init_cap);
    arrdb->size = 0;
    arrdb->capacity = init_cap;
}

void insert_city_arr(Arrdb* arrdb, City* city)
{
    if (arrdb->size == arrdb->capacity)
    {
        arrdb->citiesarr = (City**)realloc(arrdb->citiesarr, sizeof(City*) * arrdb->capacity * 2);
        arrdb->capacity *= 2;
    }
    arrdb->citiesarr[arrdb->size] = city;
    arrdb->size++;
}

void delete_by_name(Arrdb* arrdb, char* name)
{
    if (arrdb->size == 0)
    {
        printf("Database is already empyt!");
        return;
    }

    for (int i = 0; i < arrdb->size - 1; i++)
    {
        if (strcmp(arrdb->citiesarr[i]->name, name) == 0)
        {
            free(arrdb->citiesarr[i]->name);
            // free(arrdb->citiesarr[i]->x);
            // free(arrdb->citiesarr[i]->y);
            // can't do the above as have not done malloc for the above i.e. not dynamically allocated (not pointers)
            free(arrdb->citiesarr[i]);

            for (int j = i; j < arrdb->size - 1; j++)
            {
                arrdb->citiesarr[j] = arrdb->citiesarr[j + 1];
            }
            arrdb->size--;

            printf("%s deleted successfully!\n", name);
            return;
        }
    }

    printf("City not found!\n");
    return;
}

void delete_by_coordinates(Arrdb* arrdb, int x, int y)
{
    if (arrdb->size == 0)
    {
        printf("Database is already empyt!");
        return;
    }

    for (int i = 0; i < arrdb->size - 1; i++)
    {
        if (arrdb->citiesarr[i]->x == x && arrdb->citiesarr[i]->y == y)
        {
            char* name = arrdb->citiesarr[i]->name;
            free(arrdb->citiesarr[i]->name);
            free(arrdb->citiesarr[i]);

            for (int j = i; j < arrdb->size - 1; j++)
            {
                arrdb->citiesarr[j] = arrdb->citiesarr[j + 1];
            }
            arrdb->size--;

            printf("%s deleted successfully! with coordinates (%d, %d)\n", name, x, y);
            return;
        }
    }
    return;
}

void print_arr_db(Arrdb* arrdb)
{
    for (int i = 0; i < arrdb->size; i++)
    {
        printf("%s %d %d\n", arrdb->citiesarr[i]->name, arrdb->citiesarr[i]->x, arrdb->citiesarr[i]->y);
    }
    printf("Size of array database: %d\n", arrdb->size);
    printf("Capacity of array database: %d\n", arrdb->capacity);
}