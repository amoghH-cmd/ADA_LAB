#include <stdio.h>

int a[20], dir[20], n;

void print()
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobile()
{
    int mobile = 0, pos = -1;

    for(int i = 0; i < n; i++)
    {
        if(dir[i] == -1 && i != 0 && a[i] > a[i-1] && a[i] > mobile)
        {
            mobile = a[i];
            pos = i;
        }

        if(dir[i] == 1 && i != n-1 && a[i] > a[i+1] && a[i] > mobile)
        {
            mobile = a[i];
            pos = i;
        }
    }

    return pos;
}

void generatePermutations()
{
    int mobilePos, mobile;

    print();

    while(1)
    {
        mobilePos = getMobile();

        if(mobilePos == -1)
            break;

        mobile = a[mobilePos];

        if(dir[mobilePos] == -1)
        {
            int temp = a[mobilePos];
            a[mobilePos] = a[mobilePos-1];
            a[mobilePos-1] = temp;

            temp = dir[mobilePos];
            dir[mobilePos] = dir[mobilePos-1];
            dir[mobilePos-1] = temp;

            mobilePos--;
        }
        else
        {
            int temp = a[mobilePos];
            a[mobilePos] = a[mobilePos+1];
            a[mobilePos+1] = temp;

            temp = dir[mobilePos];
            dir[mobilePos] = dir[mobilePos+1];
            dir[mobilePos+1] = temp;

            mobilePos++;
        }

        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
                dir[i] = -dir[i];
        }

        print();
    }
}

int main()
{
    printf("Enter value of n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = -1;
    }

    generatePermutations();

    return 0;
}