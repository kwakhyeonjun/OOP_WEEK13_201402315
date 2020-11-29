#include <iostream>
#include <string>

// 재귀함수 종료
auto sum() {
	return 0;
}

template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}
