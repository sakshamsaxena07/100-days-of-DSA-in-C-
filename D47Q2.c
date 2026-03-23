// Min heap + Max heap
int maxH[1000], minH[1000];
int maxSize = 0, minSize = 0;

void addNum(int num) {
    // insert into max heap
    maxH[maxSize++] = num;

    // balance manually (simplified version)
}

double findMedian() {
    if (maxSize > minSize)
        return maxH[0];
    return (maxH[0] + minH[0]) / 2.0;
}
