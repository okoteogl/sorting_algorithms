#include <iostream>
using namespace std;

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
  cout << "Bubble sort, worst-case and average complexity O(n^2)" << endl;
  int mylistofnumbers [] = {7, 3, 9, 9, 4, 0, 5, 78, 9, 1};
  int temp, noOfSwaps = 1;
  
  displayList(mylistofnumbers);
  while (noOfSwaps > 0)
    {
      noOfSwaps = 0;
      for (int i = 0; i < 9; i++)
	{
	  if (mylistofnumbers[i] > mylistofnumbers[i+1])
	    {
	      temp = mylistofnumbers[i+1];
	      mylistofnumbers[i+1] = mylistofnumbers[i];
	      mylistofnumbers[i] = temp;
	      noOfSwaps++;
	    }
	}
    }
  displayList(mylistofnumbers);
  return 0;
}
