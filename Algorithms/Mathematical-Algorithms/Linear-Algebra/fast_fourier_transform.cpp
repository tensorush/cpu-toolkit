/*
    Fast Fourier Transform
    ----------------------
    Time: O(n log(n))
    Space: O(1)
*/
#include <iostream>
#include <complex>
#include <numbers>
#include <vector>
#include <cmath>

void FastFourierTransform(std::vector<std::complex<double>>& array, const bool& invert = false) {
	size_t n = array.size();
	for (size_t i = 1, j = 0; i < n; ++i) {
		size_t bit;
		for (bit = n >> 1; j >= bit; bit >>= 1) {
			j -= bit;
        }
		j += bit;
		if (i < j) std::swap(array[i], array[j]);
	}
	for (size_t length = 2; length <= n; length <<= 1) {
		double angle = 2 * pi_v<double> / length * ((invert)?(-1):(1));
		std::complex<double> w_length(std::cos(angle), std::sin(angle));
		for (size_t i = 0; i < n; i += length) {
			std::complex<double> w(1, 0);
			for (size_t j = 0; j < length / 2; ++j) {
				std::complex<double> u = array[i + j], v = array[i + j + length / 2] * w;
				array[i + j] = u + v;
				array[i + j + length / 2] = u - v;
				w *= w_length;
			}
		}
	}
	if (invert) {
		for (size_t i = 0; i < n; ++i) {
			array[i] /= n;
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::complex<double>> array(n);
    for (std::complex<double>& number : array) {
        double real, imaginary;
        std::cin >> real >> imaginary;
        number = (real, imaginary);
    }
    FastFourierTransform(array);
    for (const std::complex<double>& number : array) {
        std::cout << number;
    }

    return EXIT_SUCCESS;
}