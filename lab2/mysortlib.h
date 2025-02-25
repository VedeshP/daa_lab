// mysortlib.h
#ifndef MYSORTLIB_H
#define MYSORTLIB_H

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void selection_sort(int arr[], int len);
void insertion_sort(int arr[], int len);

#endif