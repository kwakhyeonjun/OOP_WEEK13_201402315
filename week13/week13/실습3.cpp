#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

/**
* 오름차순으로 정렬하기 위한 functor
*/
class compLess {
public:
	bool operator()(int cur, int prev) {
		return cur < prev;
	}
};

/**
* 내림차순으로 정렬하기 위한 functor
*/
class compGreater {
public:
	bool operator()(int cur, int prev) {
		return cur > prev;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}	
	std::cout << std::endl;
	// 0 1 2 3 4 5 6 7

	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	// 7 6 5 4 3 2 1 0

	getchar();
}