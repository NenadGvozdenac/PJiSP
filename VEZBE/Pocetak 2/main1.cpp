#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vektor_niz = {3, 4, 2, 6, 7, 4, 1, 8};
    
    std::sort(vektor_niz.begin(), vektor_niz.end(), [](const int A, const int B) {
        return A > B;
    });

    for(int i = 0; i < vektor_niz.size(); i++) {
        std::cout << vektor_niz.at(i) << " ";
    }

    return 0;
}