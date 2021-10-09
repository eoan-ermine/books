#include <format>

int main() {
	std::string s = std::format("I'd rather be {1} than {0}.", "happy", "horny");

	std::memory_buffer buf;
	std::format_to(buf, "{}", 42);
	std::format_to(buf, "{:x}", 42);
}
