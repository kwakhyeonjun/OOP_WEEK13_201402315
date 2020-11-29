#include <iostream>

template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}
int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl; // 실습1 : x : 8

	std::cout << "x : " << add_num<int, 2>(x) << std::endl; // 실습2 : x : 5

}