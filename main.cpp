#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

class Array {
private:
    std::vector<double> data;
    int lowerBound1;
    int upperBound2;

public:
    Array(int lower, int upper) : lowerBound1(lower), upperBound2(upper) {
        data.resize(upper - lower + 1);
    }

    ~Array() {
    }

    double& operator[](int index) {
        return data[index - lowerBound1];
    }

    const double& operator[](int index) const {
        return data[index - lowerBound1];
    }

    void print() const {
        for (const auto& value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    double min() const {
        return *std::min_element(data.begin(), data.end());
    }

    double max() const {
        return *std::max_element(data.begin(), data.end());
    }

    double sum() const {
        return std::accumulate(data.begin(), data.end(), 0.0);
    }

    double average() const {
        return sum() / data.size();
    }

    void addConstant(double constant) {
        std::transform(data.begin(), data.end(), data.begin(), [constant](double value) { return value + constant; });
    }

    void subtractConstant(double constant) {
        std::transform(data.begin(), data.end(), data.begin(), [constant](double value) { return value - constant; });
    }

    void multiplyConstant(double constant) {
        std::transform(data.begin(), data.end(), data.begin(), [constant](double value) { return value * constant; });
    }

    void divideConstant(double constant) {
        std::transform(data.begin(), data.end(), data.begin(), [constant](double value) { return value / constant; });
    }

    void sortAscending() {
        std::sort(data.begin(), data.end());
    }

    void sortDescending() {
        std::sort(data.rbegin(), data.rend());
    }

    friend Array addArrays(const Array& arr1, const Array& arr2);
    friend Array subtractArrays(const Array& arr1, const Array& arr2);
    friend Array multiplyArrays(const Array& arr1, const Array& arr2);
    friend Array divideArrays(const Array& arr1, const Array& arr2);
};

// Определение функций для арифметических операций с двумя массивами
Array addArrays(const Array& arr1, const Array& arr2) {
    int lowerBound1 = std::min(arr1.lowerBound1, arr2.lowerBound1);
    int upperBound2 = std::max(arr1.upperBound2, arr2.upperBound2);

    Array result(lowerBound1, upperBound2);

    for (int i = lowerBound1; i <= upperBound2; ++i) {
        result[i] = arr1[i] + arr2[i];
    }

    return result;
}

Array subtractArrays(const Array& arr1, const Array& arr2) {
    int lowerBound1 = std::min(arr1.lowerBound1, arr2.lowerBound1);
    int upperBound2 = std::max(arr1.upperBound2, arr2.upperBound2);

    Array result(lowerBound1, upperBound2);

    for (int i = lowerBound1; i <= upperBound2; ++i) {
        result[i] = arr1[i] - arr2[i];
    }

    return result;
}

Array multiplyArrays(const Array& arr1, const Array& arr2) {
    int lowerBound1 = std::min(arr1.lowerBound1, arr2.lowerBound1);
    int upperBound2 = std::max(arr1.upperBound2, arr2.upperBound2);

    Array result(lowerBound1, upperBound2);

    for (int i = lowerBound1; i <= upperBound2; ++i) {
        result[i] = arr1[i] * arr2[i];
    }

    return result;
}

Array divideArrays(const Array& arr1, const Array& arr2) {
    int lowerBound1 = std::min(arr1.lowerBound1, arr2.lowerBound1);
    int upperBound2 = std::max(arr1.upperBound2, arr2.upperBound2);

    Array result(lowerBound1, upperBound2);

    for (int i = lowerBound1; i <= upperBound2; ++i) {
        if (arr2[i] != 0.0) {
            result[i] = arr1[i] / arr2[i];
        }
        else {
            std::cout << "delenie na 0" << std::endl;
            return result;
            // Handle division by zero, for example, set result[i] to some default value.
            // Here, we set it to 0.0, but you may choose a different approach based on your requirements.
            result[i] = 0.0;
        }
    }
    std::cout << "delenie= ";
    result.print();

    return result;
}



int main() {
    int lower1, upper1, lower2, upper2;
    std::cin >> lower1 >> upper1;
    lower2 = lower1;
    upper2 = upper1;

    Array array1(lower1, upper1);

    for (int i = lower1; i <= upper1; ++i) {
        std::cin >> array1[i];
    }

    Array array2(lower2, upper2);

    for (int i = lower2; i <= upper2; ++i) {
        std::cin >> array2[i];
    }

    double constant;
    std::cin >> constant;

    // Output for the first array
    std::cout << "Array1= ";
    array1.print();
    std::cout << "min= " << array1.min() << " max= " << array1.max()
        << " summa= " << array1.sum() << " srar= " << array1.average() << std::endl;

    Array tempArray1 = array1;  // Create a copy for further calculations

    tempArray1.addConstant(constant);
    std::cout << "Array1+const= ";
    tempArray1.print();

    tempArray1 = array1;
    tempArray1.subtractConstant(constant);
    std::cout << "Array1-const= ";
    tempArray1.print();

    tempArray1 = array1;
    tempArray1.multiplyConstant(constant);
    std::cout << "Array1*const= ";
    tempArray1.print();

    tempArray1 = array1;
    tempArray1.divideConstant(constant);
    std::cout << "Array1/const= ";
    tempArray1.print();

    tempArray1 = array1;
    std::cout << "sort up Array1= ";
    tempArray1.sortAscending();
    tempArray1.print();

    tempArray1 = array1;
    std::cout << "sort down Array1= ";
    tempArray1.sortDescending();
    tempArray1.print();

    // Output for the second array
    std::cout << "Array2= ";
    array2.print();
    std::cout << "min= " << array2.min() << " max= " << array2.max()
        << " summa= " << array2.sum() << " srar= " << array2.average() << std::endl;

    Array tempArray2 = array2;  // Create a copy for further calculations

    tempArray2.addConstant(constant);
    std::cout << "Array2+const= ";
    tempArray2.print();

    tempArray2 = array2;
    tempArray2.subtractConstant(constant);
    std::cout << "Array2-const= ";
    tempArray2.print();

    tempArray2 = array2;
    tempArray2.multiplyConstant(constant);
    std::cout << "Array2*const= ";
    tempArray2.print();

    tempArray2 = array2;
    tempArray2.divideConstant(constant);
    std::cout << "Array2/const= ";
    tempArray2.print();

    tempArray2 = array2;
    std::cout << "sort up Array2= ";
    tempArray2.sortAscending();
    tempArray2.print();

    tempArray2 = array2;
    std::cout << "sort down Array2= ";
    tempArray2.sortDescending();
    tempArray2.print();

    // Operations with arrays
    tempArray1 = array1;
    tempArray2 = array2;
    Array sumArray = addArrays(tempArray1, tempArray2);
    tempArray1 = array1;
    tempArray2 = array2;
    Array diffArray = subtractArrays(tempArray1, tempArray2);
    tempArray1 = array1;
    tempArray2 = array2;
    Array prodArray = multiplyArrays(tempArray1, tempArray2);


    std::cout << "summa= ";
    sumArray.print();

    std::cout << "raznost= ";
    diffArray.print();

    std::cout << "proizv = ";
    prodArray.print();

    tempArray1 = array1;
    tempArray2 = array2;
    Array divArray = divideArrays(tempArray1, tempArray2);
   // std::cout << "delenie= ";
   // divArray.print();

    while (true) {
        int action, index;
        std::cin >> action;

        if (action == 0) {
            break;
        }

        std::cin >> index;

        switch (action) {
        case 1:
            if (index >= lower1 && index <= upper1) {
                std::cout << "Array1[" << index << "] = " << array1[index] << std::endl;
            }
            else {
                std::cout << "Array1 wrong index " << index << std::endl;
            }
            break;

        case 2:
            if (index >= lower2 && index <= upper2) {
                std::cout << "Array2[" << index << "] = " << array2[index] << std::endl;
            }
            else {
                std::cout << "Array2 wrong index " << index << std::endl;
            }
            break;

        default:
            std::cout << "Invalid action. Try again." << std::endl;
        }
    }
}
