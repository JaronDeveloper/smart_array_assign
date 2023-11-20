#include <iostream>

class  smart_array
{
public:
	int* array;
	int index = 0,index_copy=0;
	int size;
	smart_array(int size) {
		this->size = size;
		array = new int[size];
	}
	smart_array(int* arr) {
		arr = new int[size];
		array = arr;
	}
	smart_array(const smart_array& copy) :
		array(copy.array) {}	
	void add_element(int number) {
		array[index] = number;
		index++;
	}
	int get_element(int index) {return array[index];}
	smart_array& operator= (const smart_array& smart_array)
	{
		while (smart_array.size>index_copy)
		{
			array[index] = smart_array.array[index_copy];
			index++;
			index_copy++;
		}
		

		return *this;
	}
	~smart_array() { delete[] array; }
};

int main() {

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		
		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		
		std::cout << arr.get_element(2) << std::endl;	
		arr = new_array;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

