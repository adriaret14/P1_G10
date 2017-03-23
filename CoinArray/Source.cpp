#include <iostream>

void Swap(int a, int b) {
	int tmp = a;
a = b;
b = tmp;
}
int main() {
	int *a = new int[5]{ 7, 4, 9, 8, 2 };
		int b[3];
		for (int &it : b) it = *a;
		Swap(a[2], b[2]);
		std::cout << a[2] << std::endl;
		delete[] a;
		
		return 0;	
}