#include <stdio.h>
// https://www.youtube.com/watch?v=rw4s4M3hFfs

typedef struct
{
    char gym;
    char park;
    char store;
} Block;

int main()
{
    Block block0 = {'F', 'T', 'F'};
    Block block1 = {'T', 'F', 'F'};
    Block block2 = {'T', 'T', 'F'};
    Block block3 = {'F', 'T', 'F'};
    Block block4 = {'F', 'T', 'T'};

    Block blocks[] = {block0, block1, block2, block3, block4};

    int length = sizeof(blocks) / sizeof(blocks[0]);

    int farthest[length], iteration = 0, gym = 1, store = 1, park = 1;

    for (int i = 0; i < length; i++)
    {
        if (blocks[i].gym == 'T')
        {
            farthest[i] = 0;
            int gym = 0;
        }
        if (blocks[i].store == 'T')
        {
            farthest[i] = 0;
            int store = 0;
        }
        if (blocks[i].park == 'T')
        {
            farthest[i] = 0;
            int park = 0;
        }
        for (int j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (blocks[j].gym == 'T' && gym != 0)
            {
                if (farthest[i] < iteration)
                {
                    farthest[i] = iteration;
                }
            }

            if (blocks[j].park == 'T' && park != 0)
            {
                if (farthest[i] < iteration)
                {
                    farthest[i] = iteration;
                }
            }
            if (blocks[j].store == 'T' && store != 0)
            {
                if (farthest[i] < iteration)
                {
                    farthest[i] = iteration;
                }
            }

            if (gym == 0 && park == 0 && store == 0)
            {
                break;
            }

            iteration++;
        }
        iteration = 0;
    }

    // print the farthest array
    for (int i = 0; i < length; i++)
    {
        printf("%d ", farthest[i]);
    }
}

// Solution

// #include <stdio.h>
// #include <limits.h> // For INT_MAX

// // https://www.youtube.com/watch?v=rw4s4M3hFfs

// typedef struct
// {
//     char gym;
//     char park;
//     char store;
// } Block;

// int main()
// {
//     Block block0 = {'F', 'T', 'F'};
//     Block block1 = {'T', 'F', 'F'};
//     Block block2 = {'T', 'F', 'F'};
//     Block block3 = {'F', 'T', 'T'};
//     Block block4 = {'F', 'T', 'T'};

//     Block blocks[] = {block0, block1, block2, block3, block4};

//     int length = sizeof(blocks) / sizeof(blocks[0]);

//     int farthest[length];

//     for (int i = 0; i < length; i++)
//     {
//         int maxDist = 0;
//         int nearestGym = INT_MAX, nearestPark = INT_MAX, nearestStore = INT_MAX;

//         for (int j = 0; j < length; j++)
//         {
//             if (blocks[j].gym == 'T' && abs(i - j) < nearestGym)
//             {
//                 nearestGym = abs(i - j);
//             }
//             if (blocks[j].park == 'T' && abs(i - j) < nearestPark)
//             {
//                 nearestPark = abs(i - j);
//             }
//             if (blocks[j].store == 'T' && abs(i - j) < nearestStore)
//             {
//                 nearestStore = abs(i - j);
//             }
//         }

//         maxDist = nearestGym > nearestPark ? (nearestGym > nearestStore ? nearestGym : nearestStore) : (nearestPark > nearestStore ? nearestPark : nearestStore);

//         farthest[i] = maxDist;
//     }

//     // Print the farthest array
//     for (int i = 0; i < length; i++)
//     {
//         printf("%d ", farthest[i]);
//     }
//     printf("\n");

//     return 0;
// }
