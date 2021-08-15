class AccessLevels {
private:
	int noAccess;
	int readOnly;
	int readWrite;
	int writeOnly;
public:
	int getReadOnly() const {
		return readOnly;
	}

	void setReadWrite(int value) {
		readWrite = value;
	}
	int getReadWrite() const {
		return readWrite;
	}

	void setWriteOnly(int value) {
		writeOnly = value;
	}
};

int main() { }