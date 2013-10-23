#include <iostream>
using namespace std;

int partition(int* array, int start_index, int end_index);
void mergesort(int* array, int start_index, int end_index);
void merge(int* array, int start_index, int middle_index, int end_index);

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
  cout << "Merge sort, worst and average case O(nlgn)" << endl;
  int mylistofnumbers [] = {7, 3, 9, 9, 4, 0, 5, 78, 9, 1};
  
  //displayList(mylistofnumbers);
  mergesort(mylistofnumbers, 1, 10);
  //displayList(mylistofnumbers);
  return 0;
}

void mergesort(int* array, int start_index, int end_index)
{
  if (start_index < end_index)
    {
      int middle_index = (start_index+end_index)/2;
      mergesort(array, start_index, middle_index);
      mergesort(array, middle_index+1, end_index);
      merge(array, start_index, middle_index, end_index);
      displayList(array);
    }
}

void merge(int* array, int start_index, int middle_index, int end_index)
{
  int left_noElements = middle_index - start_index + 1;
  int right_noElements = end_index - middle_index;

  cout << "start_index = " << start_index << endl << 
    "middle_index = " << middle_index << endl << 
    "end_index = " << end_index << endl << 
    "left_noElements = " << left_noElements << endl << 
    "right_noElements = " << right_noElements << endl;

  int left[left_noElements];
  int right[right_noElements];

  for (int i = 0; i < left_noElements; i++)
    left[i] = array[start_index + i - 1];
  for (int i = 0; i < right_noElements; i++)
    right[i] = array[middle_index + i];

  left[left_noElements] = -1;
  right[right_noElements] = -1;

  int left_index = 0;
  int right_index = 0;
  for (int i = start_index - 1; i < end_index; i++)
    {
      if (left[left_index] == -1)
	{
	  array[i] = right[right_index];
	  right_index++;
	}
      else if (right[right_index] == -1)
	{
	  array[i] = left[left_index];
	  left_index++;
	}
      else if (left[left_index] < right[right_index])
	{
	  array[i] = left[left_index];
	  left_index++;
	}
      else
	{
	  array[i] = right[right_index];
	  right_index++;
	}
    }
}
