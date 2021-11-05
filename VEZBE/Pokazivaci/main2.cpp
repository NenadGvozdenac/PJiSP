#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    std::vector<int> niz = {1, 2, 3, 4, 2, 6 , 7, 10, 9};

    cout << *max_element(niz.begin(), niz.end());

    return 0;
}