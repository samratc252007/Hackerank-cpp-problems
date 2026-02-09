#include <iostream>
#include <cstdio>
#include <cstdlib> // Required for abs()

void update(int *a, int *b) {
    // Store original values before we start modifying them
    int tempA = *a;
    int tempB = *b;
    
    // Update a to be the sum
    *a = tempA + tempB;
    
    // Update b to be the absolute difference
    // abs(x) returns the positive version of a number
    *b = std::abs(tempA - tempB);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    // Reading input
    if (scanf("%d %d", &a, &b) == 2) {
        // We pass the memory addresses using the pointers
        update(pa, pb);
        
        // Print the modified values
        printf("%d\n%d", a, b);
    }
    
    return 0;
}
