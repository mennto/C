#include<iostream>
#include<vector>
#include<chrono>
using namespace std;

template <typename T>
class MyVector {
public:
	MyVector() {
		capasity_ = 1;
		ptr_m = new T[capasity_];
		size_ = 0;
	}

	~MyVector() {
		delete ptr_m;
	}

	void push_back(T sub) {
		if (size_ < capasity_) {
			*(ptr_m + size_) = sub;
			size_++;
		}
		else {
			capasity_ += 2;
			ptr_r = new T[capasity_];
			this->copy_r();
			*(ptr_m + size_) = sub;
			size_++;
		}

	}

	void pop_back() {
		if (size_ + 2 <= capasity_)
			capasity_ -= 2;
		size_--;
		ptr_r = new T[capasity_];
		this->copy_r();
	}

	T at(size_t num) {
		return *(ptr_m + num);
	}
	T back() {
		return *(ptr_m + size_ - 1);
	}

	void copy_r() {
		for (int i = 0; i < size_; i++) {
			*(ptr_r + i) = *(ptr_m + i);
		}
		delete ptr_m;
		ptr_m = ptr_r;
	}



	size_t capasity() {
		return capasity_;
	}
	size_t size() {
		return size_;
	}
private:
	T* ptr_m;    //main ptr
	T* ptr_r;    //reserve ptr
	size_t size_;
	size_t capasity_;
};


int main() {
	auto start = std::chrono::high_resolution_clock::now();
	MyVector<int> myVector;

	myVector.push_back(5);
	myVector.push_back(999);
	myVector.push_back(-190);
	myVector.push_back(-190);

	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector.at(i) << endl;
	}
	cout << myVector.size() << ' ' << myVector.capasity() << endl;
	myVector.pop_back();
	myVector.pop_back();

	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector.at(i) << endl;
	}
	cout << myVector.size() << ' ' << myVector.capasity();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	cout << endl<<"time " << duration.count() << endl;

	return 0;
}