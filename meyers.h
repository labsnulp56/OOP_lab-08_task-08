
#ifndef NAIVE_H
#define NAIVE_H
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
//NaiveSingleton *inst = NaiveSingleton::instance();
//inst->do_it();

#include <iostream>

class NaiveSingleton {
	static NaiveSingleton *_instance;
	double radius;
	double height;
	NaiveSingleton(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
	};  // private default constructor
	NaiveSingleton(const NaiveSingleton&);  // prevent copying
	~NaiveSingleton();
public:
	friend ostream& operator<<(ostream &s, const NaiveSingleton &l)
	{
		s << "Radius = " << l.radius << " Height = " << l.height << endl;
		return s;
	}
	friend const NaiveSingleton operator+(const NaiveSingleton& l1, const NaiveSingleton& l2)
	{
		return NaiveSingleton(l1.radius + l2.radius, l2.height + l1.height);
	}
	static NaiveSingleton* instance(double radius, double height) {
		if (!_instance) {
			_instance = new NaiveSingleton(radius, height);
		}
		return _instance;
	}
	double GetVolume() const {
		return (1.0 / 3.0)*M_PI*pow(this->radius, 2)*(this->height);
	}
	double GetArea() const {
		return M_PI * this->radius * (this->radius + this->height);
	}

};

NaiveSingleton *NaiveSingleton::_instance = nullptr;

#endif //NAIVE_H


//#ifndef DCL_H
//#define DCL_H
//
////DCLSingleton *inst = DCLSingleton::instance();
////inst->do_it();
//
//#include <mutex>
//#include <iostream>
//
//class DCLSingleton {
//	static DCLSingleton *_instance;
//
//	DCLSingleton() {};  // private default constructor
//	DCLSingleton(const DCLSingleton&);  // prevent copying
//	DCLSingleton& operator=(const DCLSingleton&);
//	static std::mutex mtx;
//
//public:
//	static DCLSingleton* instance() {
//		if (!_instance) {       // first check
//			mtx.lock();         // acquire lock
//			if (!_instance)     // second check
//				_instance = new DCLSingleton();
//			mtx.unlock();
//		}
//		return _instance;
//	}
//
//	void do_it() const {
//		std::cout << "Doing it" << std::endl;
//	}
//};
//
//std::mutex DCLSingleton::mtx;
//DCLSingleton *DCLSingleton::_instance = nullptr;
//
//#endif //DCL_H
