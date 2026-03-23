#include <stdlib.h>

int* topKFrequent(int* nums, int n, int k) {
    int freq[1000] = {0};

    for (int i = 0; i < n; i++)
        freq[nums[i]]++;

    int* res = malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        int max = 0;
        for (int j = 0; j < 1000; j++)
            if (freq[j] > freq[max]) max = j;

        res[i] = max;
        freq[max] = -1;
    }

    return res;
}
