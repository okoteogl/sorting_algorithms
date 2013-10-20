#include <iostream>
using namespace std;

int partition(int* array, int start_index, int end_index);
void quicksort(int* array, int start_index, int end_index);

void displayList(int* nums)
{
  for (int i = 0; i < 10; i++)
    {
      cout << nums[i] << " ";
    }
  cout << endl;
}

int main (int argc, char* argv[])
{
  cout << "Quicksort, worst-case O(n^2) and average complexity O(nlgn)" << endl;
  int mylistofnumbers [] = {7, 3, 9, 9, 4, 0, 5, 78, 9, 1};
  
  //displayList(mylistofnumbers);
  quicksort(mylistofnumbers, 0, 9);
  //displayList(mylistofnumbers);
  return 0;
}

int partition(int* array, int start_index, int end_index)
{
  int pivot = array[end_index];
  int left_cursor = start_index - 1;
  
  for (int right_cursor = start_index; right_cursor < end_index; right_cursor++)
    {
      if (array[right_cursor] < pivot)
	{
	  left_cursor++;
	  //swap
	  int temp = array[right_cursor];
	  array[right_cursor] = array[left_cursor];
	  array[left_cursor] = temp;
	}
    }
  //swap pivot with the first element that is greater than pivot (where left cursor points + 1)
  array[end_index] = array[left_cursor+1];
  array[left_cursor+1] = pivot;
  return left_cursor+1;
}

void quicksort(int* array, int start_index, int end_index)
{
  if (start_index < end_index)
    {
      int pivot = partition(array, start_index, end_index);
      displayList(array);
      quicksort(array, start_index, pivot-1);
      quicksort(array, pivot+1, end_index);
    }
}
