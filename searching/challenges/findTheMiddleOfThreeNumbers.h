#ifndef FIND_THE_MIDDLE_OF_THREE_NUMBER
#define FIND_THE_MIDDLE_OF_THREE_NUMBER

#endif

// Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).
int findTheMiddleOfThreeNumbers(int A, int B, int C)
{
    //code here//Position this line where user code will be pasted.
    if (A < B)
    {
        if (B < C)
        {
            return B;
        }
        else // B >= C
        {
            if (A < C)
            {
                return C;
            }
            else
            {
                return A;
            }
        }
    }
    else // A >= B
    {
        if (B < C)
        {
            if (A < C)
            {
                return A;
            }
            else
            {
                return C;
            }
        }
        else // B >= C
        {
            return B;
        }
    }
}