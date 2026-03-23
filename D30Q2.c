struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void printPoly(struct Node* head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
}
