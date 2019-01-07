template <class InputIterator, class T>

class Find
{
private:
	InputIterator inputFirst;
	InputIterator intputLast;
public:
	const T& value;
	Find() {}
	~Find() {}
	InputIterator find (InputIterator inputFirst, InputIterator intputLast, const T& value) {
		for( ;inputFirst!=intputLast; inputFirst++)
			if(*inputFirst == value)
				break;
		return inputFirst;
	}
};