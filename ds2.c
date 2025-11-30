#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32  // Universal set size (0 to 31)

// Function to set a bit (add element to set)
unsigned int addElement(unsigned int set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Invalid element: %d (must be 0-%d)\n", element, MAX_BITS - 1);
        return set;
    }
    return set | (1U << element);
}

// Function to remove a bit (remove element from set)
unsigned int removeElement(unsigned int set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Invalid element: %d (must be 0-%d)\n", element, MAX_BITS - 1);
        return set;
    }
    return set & ~(1U << element);
}

// Function to check if an element exists in the set
int containsElement(unsigned int set, int element) {
    if (element < 0 || element >= MAX_BITS) return 0;
    return (set & (1U << element)) != 0;
}

// Function to display the set
void displaySet(unsigned int set) {
    printf("{ ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set & (1U << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

// Set operations
unsigned int setUnion(unsigned int setA, unsigned int setB) {
    return setA | setB;
}

unsigned int setIntersection(unsigned int setA, unsigned int setB) {
    return setA & setB;
}

unsigned int setDifference(unsigned int setA, unsigned int setB) {
    return setA & ~setB;
}

int main() {
    unsigned int setA = 0, setB = 0;

    // Example: Add elements to sets
    setA = addElement(setA, 1);
    setA = addElement(setA, 3);
    setA = addElement(setA, 5);

    setB = addElement(setB, 3);
    setB = addElement(setB, 4);
    setB = addElement(setB, 5);

    printf("Set A: ");
    displaySet(setA);

    printf("Set B: ");
    displaySet(setB);

    // Perform operations
    printf("Union: ");
    displaySet(setUnion(setA, setB));

    printf("Intersection: ");
    displaySet(setIntersection(setA, setB));

    printf("Difference (A - B): ");
    displaySet(setDifference(setA, setB));

    // Check membership
    int check = 4;
    printf("Element %d is %sin Set A\n", check, containsElement(setA, check) ? "" : "not ");

    return 0;
}
