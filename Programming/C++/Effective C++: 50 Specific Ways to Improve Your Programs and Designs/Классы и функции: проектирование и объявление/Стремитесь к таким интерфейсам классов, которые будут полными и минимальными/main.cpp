#include <vector>
#include <tuple>

template<class T>
class Array {
public:
	enum BoundsCheckingStatus {
		NO_CHECK_BOUNDS = 0, CHECK_BOUNDS = 1
	};

	Array(int lowBound, int highBound,
	  BoundsCheckingStatus status=NO_CHECK_BOUNDS):
		m_lBound{lowBound}, m_hBound{highBound},
		data{highBound - lowBound + 1}, checkingBounds{status}
	{ }

	Array(const Array& rhs) {
		std::tie(this->m_lBound, this->m_hBound, this->checkingBounds, this->data) =
		  std::tie(rhs->m_lBound, rhs->m_hBound, rhs->checkingBounds, rhs->data);
	}
	~Array();
	/*
		Array& operator=(const Array& rhs)
		^ Объявим эту фигню, и нам придется городить
		всякую хрень, которая никак не минимальный интерфейс
	*/

	const T& operator[](size_t idx) const {
		return this->data[idx];
	}

	T& operator[](size_t idx) {
		if(checkingBounds && idx >= this->m_lBound && idx < this->m_hBound) {
			return this->data[idx];
		}
		throw std::out_of_range{"Out of bounds!"};
	}

	int lBound() {
		return this->m_lBound;
	}
	int hBound() {
		return this->m_hBound;
	}

	/*
		int size() - это не минимальные интерфейс, потому что мы можем посчитать размер так:
		int size = arr.hBound() - arr.lBound() + 1;
	*/
private:
	int m_lBound, m_hBound;
	std::vector<T> data;
	BoundsCheckingStatus checkingBounds;
};

int main() {

}