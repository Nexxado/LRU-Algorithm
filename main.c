#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX 100000

int lru[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int age_arr[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int age_len = 10;
int counter = 0;

int findSmallest();
void addTo_LRU(int);
int remove_LRU();
void print_LRU();

int findSmallest() {
  int i, min_index = 0, min_age = MAX;
  for(i=0; i < age_len; i++) {
    if(min_age > age_arr[i]) {
      min_age = age_arr[i];
      min_index = i;
    }
  }
    
  return min_index;
}

//Add an argurment to the data structure or update the data structure
void addTo_LRU(int x)
{
  int frame = findSmallest();
  counter++;
  lru[frame] = x;
  age_arr[frame] = counter;
  
  print_LRU();

}


//Remove the first argument (least recent used)
int remove_LRU()
{
  int frame = findSmallest();
  int removed = lru[frame];
  lru[frame] = 0;
  counter++;
  age_arr[frame] = counter;

  return removed;
}



//Print the arguments in the correct order (least recent used first)
void print_LRU()
{
  int temp_lru[age_len], temp_age[age_len];
  int i, j, min_age, min_index;
    
  //copy arrays
  for(i=0; i < age_len; i++) {
    temp_lru[i] = lru[i];
    temp_age[i] = age_arr[i];
  }
  
  //sort by min age
  for(i=0; i < age_len; i++) {
    min_age = MAX;
    for(j=0; j < age_len; j++) {
      if(min_age > temp_age[j]) {
	min_age = temp_age[j];
	min_index = j;
      }
    }
    temp_lru[i] = lru[min_index];
    temp_age[min_index] = MAX;
  }
  
  //print sorted array
  for(i=0; i < age_len; i++) {
    printf("%d, " ,temp_lru[i]);
  }
  printf("\n");

}

int main()
{

int arr[]={3, 5, 7, 8, 15, 32, 16, 9, 3, 4, 6, 13};
int arrlength = sizeof(arr)/sizeof(int); //array length
int i;
for(i=0; i<arrlength; i++)
{
  addTo_LRU(arr[i]);
}
print_LRU();
addTo_LRU(7);
int x= remove_LRU();
printf("the number which removed is: %d \n", x);
print_LRU();

return 0;
}
