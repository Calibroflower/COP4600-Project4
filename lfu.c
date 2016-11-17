#include<stdio.h>
 
int lfu(int refString[])
{
	int frames = 3;
  int numpages = 17;
  int hit = 0;
  int pagefault = 3;
	
  int frame[17], array[17], time[17];
	int i, j, page, flag, k, minimum_time, temp;
  
  //initialize the page table to -1
	for(i = 0; i < numpages; i++)
	{
		frame[i] = -1;
	}
	for(i = 0; i < 17; i++)
	{
		array[i] = 0;
	}
	
  	//lfu algorithm
  	for(i = 0; i < numpages; i++)
  	{
    		array[refString[i]]++;
    		time[refString[i]] = i;     //updates time spent in table for the current reference string element
    		flag = 1;
    		k = frame[0];
    		for(j = 0; j < frames; j++)
    		{ 
      			if(frame[j] == -1 || frame[j] == refString[i])  //compares reference string element to value of current page position
      			{
        			if(frame[j] != -1)    //checks if page is already in the table
        			{
            				hit++;   //increment hit count
        			}
        			flag = 0;
        			frame[j] = refString[i];    //places string element into page table
        			break;
      			}
      			if(array[k] > array[frame[j]])
      			{
        			k = frame[j];
      			}
    		}
    		if(flag)    //there is a page fault if true
    		{
      			pagefault++;
            minimum_time = 17;
      			for(j = 0; j < frames; j++) //determines which page has been least frequently used
      			{
        			if(array[frame[j]] == array[k] && time[frame[j]] < minimum_time)
        			{
          				temp = j;
          				minimum_time = time[frame[j]];   //updates minimum time spent in table
        			}
      			}
      			array[frame[temp]] = 0;
      			frame[temp] = refString[i];
    		}
    		for(j = 0; j < frames; j++)     //prints the page table row by row
		    {
      			printf("|%d\t", frame[j]);
    		}
    		printf("\n");
  	}
  	printf("LFU Hits:\t%d\n", hit);               //prints the number of successful hits
    printf("LFU Page Faults: %d\n", pagefault);      //prints the number of page faults
  	return 0;
}
int main(){
  int pages[17] =  {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 6};


  lfu(pages);
}
