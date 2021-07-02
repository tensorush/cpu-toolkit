/*
    Coupon Collector's Problem
    --------------------------
    Time: O(numCoupons)
    Space: O(1)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

unsigned CouponCollectorsProblem(const unsigned& numCoupons) {
    double nthHarmonic = 1;
    for (double i = numCoupons; i > 1; --i) {
        nthHarmonic += 1 / i;
    }
    unsigned numTrials = std::round(numCoupons * nthHarmonic);
    return numTrials;
}

int main() {
    unsigned numCoupons;
    std::cin >> numCoupons;
    std::cout << std::setprecision(3) << std::fixed
        << CouponCollectorsProblem(numCoupons) << std::endl;

    return EXIT_SUCCESS;
}