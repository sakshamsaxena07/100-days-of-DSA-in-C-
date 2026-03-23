int leastInterval(char* tasks, int n) {
    int freq[26] = {0};

    for (int i = 0; tasks[i]; i++)
        freq[tasks[i] - 'A']++;

    int max = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > max) max = freq[i];

    int count = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] == max) count++;

    int res = (max - 1) * (n + 1) + count;

    int total = 0;
    for (int i = 0; i < 26; i++) total += freq[i];

    return res > total ? res : total;
}
