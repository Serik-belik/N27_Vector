#include <iostream>


class Vector {
	int* data = nullptr;
	unsigned int size = 0;
	unsigned int lastId = 0;

public:
	// Default Constructor
	Vector() { std::cout << "Varctor at " << this << " created" << std::endl; }

	// Parameterized Constructor
	Vector(unsigned int setSize) {
		size = setSize;
		data = new int[setSize];
		std::cout << "Varctor at " << this << " created" << std::endl;
	}

	// Copy Constructor
	Vector(const Vector &other) {
		size = other.size;
		lastId = other.lastId;
		data = new int[size];
		for (unsigned int i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
		std::cout << "Varctor at " << this << " created" << std::endl;
	}

	// Unary subtraction operator overload
	Vector operator-() {
		Vector newV = Vector(*this);
		for (unsigned int i = 0; i < newV.size; ++i) {
			newV.data[i] *= -1;
		}
		return newV;
	}

	// Binary subtraction operator overload
	Vector operator-(const Vector& other) {
		if (size != other.size)
			return Vector();

		Vector resVector = Vector(size);
		for (unsigned int i = 0; i < size; ++i) {
			resVector.data[i] = data[i] - other.data[i];
		}

		return resVector;
	}

	// Unary addition operator overload
	Vector operator+() {
		return Vector(*this);
	}

	// Binary addition operator overload
	Vector operator+(const Vector& other) {
		if (size != other.size)
			return Vector();

		Vector resVector = Vector(size);
		for (unsigned int i = 0; i < size; ++i) {
			resVector.data[i] = data[i] + other.data[i];
		}

		return resVector;
	}

	// Assignment operator overload
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			size = other.size;
			lastId = other.lastId;
			delete[] data;
			data = new int[size];
			for (unsigned int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	// Multiply operator overload. Dot product
	int operator* (const Vector& other) {
		if (size != other.size) {
			std::cout << "Different vector sizes";
			return 0;
		}

		int resVector = 0;
		for (unsigned int i = 0; i < size; ++i) {
			resVector += data[i] * other.data[i];
		}

		return resVector;
	}

	// Multiply operator overload. Multiply by a value
	Vector operator*(int mult) {
		Vector resVector = Vector(size);
		for (unsigned int i = 0; i < size; ++i) {
			resVector.data[i] = data[i] * mult;
		}

		return resVector;
	}

	// Destructor
	~Vector() {
		std::cout << "Deleting Vector at " << this << "... ";
		if (data) {
			delete[] data;
			data = nullptr;
		}
		std::cout << "Deleted." << std::endl;
	}

	// Adding item to data array
	void push_back(const int newItem) {
		if (lastId < size) {
			data[lastId] = newItem;
			++lastId;
		}
		else std::cout << "Size exceed" << std::endl;
	}

	// Index operator overload
	int operator[](unsigned int index) {
		return data[index];
	}

	// Size getter
	unsigned int getSize() const { return size; }

	// Data getter
	int getData(int index) const { return data[index]; }

};

std::ostream& operator<<(std::ostream& os, const Vector& v) {
	os << "Vector [ ";
	unsigned int size = v.getSize();
	for (unsigned int i = 0; i < size; ++i) {
		std::cout << v.getData(i) << ((i < size - 1)?",":"") << " ";
	}
	std::cout << "]" << std::endl;
	return os;
}

int main() {
	Vector a(2);
	a.push_back(1);
	a.push_back(-2);
	std::cout << "a " << a;
	Vector b(2);
	b.push_back(2);
	b.push_back(3);
	std::cout << "b " << b;
	Vector c = a + b;
	std::cout << "c = a + b = " << c;
	Vector d = a - b;
	std::cout << "d = a - b = " << d;
	Vector m = b * 2;
	std::cout << "m = b * 2 =" << m;

	// Find dot product of vectors v(2, -5) and w(-1, 0)
	// (—кал€рное произведение)
	Vector v(2);
	v.push_back(2);
	v.push_back(-5);
	std::cout << "v " << v;
	Vector w(2);
	w.push_back(-1);
	w.push_back(0);
	std::cout << "w " << w;
	int result = v * w;
	std::cout << "v * w = " << result << std::endl;

}
