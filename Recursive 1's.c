#include <stdio.h>
#include <math.h>

/* Question: Write a program to calculate the sum of the series 1 + 11 + 111 + ... upto
N terms using recursive function. Example: If N is read as 5, the series is: 
1 + 11 + 111 + 1111 + 11111

The logic behind the program is to find the sum of repeating 1's where the number of 1's in every term is correlated with the term number.
Example for 2nd term there are two 1's and for the 3rd term there are three 1's.

Using the concepts from Sequence and Series, the problem can also be formulated as:
(10^0) + (10^0 + 10^1) + (10^0 + 10^1 + 10^2) + ... N
We can see that every term in brackets is the sum of powers of 10 from 0 to the term number - 1.

Concretely let us say that N = 3 then our problem becomes : (10^0) + (10^0 + 10^1) + (10^0 + 10^1 + 10^2) = 123. Our objective is to return the sum 123.
*/
int sumterms_without_recursion(int n);
int sumterms_with_recursion(int n);


/*This part is totally optional but you can do the problem without recursion to better understand the program logic. Besides, recursion is kinda..weird
We basically use nested loops, the inner loop computes the sum for each term while the outer loop computes the sum of all the terms to give our final answer.
*/
int sumterms_without_recursion(int n)
{
  int sum = 0;
  for(int i = 0; i<n; ++i)
  {
    for(int j = 0; j<=i; ++j)
    {
      sum += pow(10,j);
    }

  }
  return sum;
}

/*So, we come to the heart of the problem. Recursion basically means to call a 
function from within itself. As programmers, recursion will play a big role in 
what we do later on so I'll try to give you a step by step approach that worked 
for me.

For a recursive problem there are basically three steps:

The first step is to think of a "base case". This is best visualized by thinking
 of the simplest input to the function. In our case, it will be sum(1) = 1.

The second step is to think how the base case can be used to solve the larger 
problem. It will be helpful to focus on a single like 1 or 2 and try to come 
up with a recursive function that gives us the desired output.

The third step is to generalize this function for other terms so that we
 can solve the problem.
 */

int sumterms_with_recursion(int n)
{
  if(n == 1)
  {
    return 1;
  }
  else
  {
    return (sumterms_with_recursion(n-1) + (1 - pow(10,n))/(1 - 10));
  }
}

/*In the above function we set our base case to be when n = 1. When 
our base case occurs we want to return 10^0 = 1. This is also the 
condition that will prevent the recursive call from running indefintely. 
What if we don't encounter our base case? Now this is the tricky part.
This is where you have to use the recursive function that you thought of. 
Note that the term n will decrease with every recursive call.

In our case if we consider N = 3: 

The base case will be sumterms_with_recursion(1) = 1
If we take N = 2 then sumterms_with_recursion(2) = (10^0) + (10^0 + 10^1)
Taking N = 3, sumterms_with_recursion(3) = (10^0) + (10^0 + 10^1) + (10^0 + 10^1 + 10^2)
that is:
sumterms_with_recursion(3) = sumterms_with_recursion(2) + (1 - pow(10,3))/(1 - 10)

The second term in the function is a formula for geometric series where a = 1, r = 10 and n = 3


Generalising this:
sumterms_with_recursion(n) = sumterms_with_recursion(n-1) + (1 - pow(10,n))/(1 - 10);
*/


int main(void)
{
  int N;
  printf("enter the value of N ");
  scanf("%d", &N);
  printf("Sum of terms without recursion: %d\n",sumterms_without_recursion(N));
  printf("Sum of terms with recursion: %d",sumterms_with_recursion(N));
  return 0;
}