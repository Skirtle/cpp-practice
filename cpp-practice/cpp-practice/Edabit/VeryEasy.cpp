// Includes
#include <iostream>

// Prototypes
int sum(int a, int b);
int addOne(int a);
int minutesToSeconds(int a);
int triangleArea(int base, int height);
int circuitPower(int volt, int curr);
int hoursToSeconds(int hours);
int maxEddge(int a, int b);
int getRemainder(int a, int b);
int squared(int a);
int rectPerimiter(int l, int w);
bool isEqual(int a, int b);
bool leqZero(int a);
int farmLegs(int ch, int co, int p);
bool isSameNum(int a, int b);
bool reverse(bool a);

int sum(int a, int b) { return a + b; }
int addOne(int a) { return a + 1; }
int minutesToSeconds(int a) { return a * 60; }
int triangleArea(int base, int height) { return (base * height) / 2; }
int circuitPower(int volt, int curr) { return volt * curr; }
int hoursToSeconds(int hours) { return hours * 3600; }
int maxEddge(int a, int b) { return (a + b) - 1; }
int getRemainder(int a, int b) { return a % b; }
int squared(int a) { return a * a; }
int rectPerimiter(int l, int w) { return (l + w) * 2; }
bool isEqual(int a, int b) { return a == b; }
bool leqZero(int a) { return a <= 0; }
int farmLegs(int ch, int co, int p) { return (ch * 2 + (co + p) * 4); }
bool isSameNum(int a, int b) { return a == b; }
bool reverse(bool a) { return !a; }