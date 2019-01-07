template <class ForwardIterator, class InputIterator, class T>

class Binary
{
private:
	ForwardIterator forwardforwardFirst;
	ForwardIterator forwardforwardLast;
public:
	const T& value;
	Binary() {}
	~Binary() {}
	bool binary_search(ForwardIterator forwardFirst, ForwardIterator forwardLast, const T& value) {
		  forwardFirst = lower_bound(forwardFirst,forwardLast,value);
		  return (forwardFirst!=forwardLast && !(value<*forwardFirst));
	}
};