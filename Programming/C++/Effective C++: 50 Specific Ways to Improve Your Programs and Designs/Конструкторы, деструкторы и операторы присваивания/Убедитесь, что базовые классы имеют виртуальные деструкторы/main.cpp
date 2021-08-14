#include <iostream>
#include <cstdint>

class EnemyTarget {
public:
	EnemyTarget() { ++numTargets; }
	EnemyTarget(const EnemyTarget&) { ++numTargets; }
	virtual ~EnemyTarget() { --numTargets; }

	static std::size_t numberOfTargets() {
		return numTargets;
	}	

	virtual bool destroy() {
		return true;
	}
private:
	static std::size_t numTargets;
};
std::size_t EnemyTarget::numTargets;

class EnemyTank: public EnemyTarget {
public:
	EnemyTank() { ++numTanks; }
	EnemyTank(const EnemyTank& rhs)
		: EnemyTarget(rhs) { ++numTanks; }
	~EnemyTank() { --numTanks; }

	static size_t numberOfTanks() {
		return numTanks;
	}

	virtual bool destroy() {
		return true;
	}
private:
	static std::size_t numTanks;
};
std::size_t EnemyTank::numTanks;

int main() {
	EnemyTarget* targetPtr = new EnemyTank;

	std::cout << EnemyTarget::numberOfTargets() << '\n';
	std::cout << EnemyTank::numberOfTanks() << '\n';

	delete targetPtr; // UB without virtual destructor

	std::cout << EnemyTarget::numberOfTargets() << '\n';
	std::cout << EnemyTank::numberOfTanks() << '\n';
}
