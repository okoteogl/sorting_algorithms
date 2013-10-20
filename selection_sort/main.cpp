#include <iostream>
#include <vector>
using namespace std;

void displayList(vector<int> nums)
{
  for (int i = 0; i < nums.size(); i++)
    {
      cout << nums[i] << " ";
    }
  cout << endl;
}

int main (int argc, char* argv[])
{
  cout << "Selection sort, average complexity O(n^2)" << endl;
  int temp [] = {7, 3, 9, 9, 4, 0, 5, 78, 9, 1};
  vector<int> nums (&temp[0], &temp[0]+10);
  int index_of_min;

  displayList(nums);
  int counter = 0;
  while (counter < 10)
    {
      index_of_min = counter;
      for (int i = counter+1; i < nums.size(); i++)
  	{
  	  if (nums[index_of_min] > nums[i])
  	      index_of_min = i;
  	}
      if (index_of_min != counter)
	{
	  //swap
	  int t = nums[index_of_min];
	  nums[index_of_min] = nums[counter];
	  nums[counter] = t;
	}
      counter++;
    }
  displayList(nums);
  return 0;
}
