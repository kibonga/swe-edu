#include "happy-number.h"

int sumOfSquareDigits(int num) {
    int d, sum = 0;
    while(num) {
       d = num % 10;
       sum += (d * d);
       num /= 10;
    }
    return sum;
}

bool isHappyNumber(int num) {
    if(num == 1) {
        return true;
    }
    int slow, fast;
    slow = num, fast = sumOfSquareDigits(num);

    while(fast != slow) {
        if(fast == 1) {
            return true;
        }
        slow = sumOfSquareDigits(slow);
        fast = sumOfSquareDigits(sumOfSquareDigits(fast));
    }
    return false;
}

void runHappyNumberExample() {
    int num = 4;
    cout << "Is happy number = " << isHappyNumber(num);
}
