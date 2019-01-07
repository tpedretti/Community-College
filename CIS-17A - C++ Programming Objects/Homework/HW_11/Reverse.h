template <class BidirectionalIterator>

class Reverse
{	
public:
	Reverse() {}
	~Reverse() {}
	void reverse(BidirectionalIterator reverseFirst, BidirectionalIterator reverseLast) {
		while ((reverseFirst!=reverseLast)&&(reverseFirst!=--reverseLast))
			swap (*reverseFirst++,*reverseLast);
	}
};