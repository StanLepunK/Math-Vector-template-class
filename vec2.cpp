#ifndef VEC2_H
# define VEC2_H
/**
* vec2 0.0.1
* 2020-2020
*/ 
#include "vec.cpp"
#include "r_t_utils.cpp"




/**
* TEMPLATE DECLARATION
*/
template <class T>
class vec2 : public vec<T> {
private:
	static int instance;
	static bool _warning;
	T _x;
	T _y;
public:
	vec2();
	vec2(T const &arg);
	vec2(T const &x, T const &y);
	vec2(vec2<T> const &src);
	~vec2();

	// set
	vec2 set(T const &x, T const &y);
	vec2 x(T const &x);
	vec2 y(T const &y);
  
  // get
	T x() const;	
	T y() const;
	T min() const;	
	T max() const;
	vec2 copy() const;
	T * array() const;

	// common algorithm for all vec

	// Calcule the dot product of the vector
	T dot(vec2<T> const &v) const;
	T dot(T const &x, T const &y) const;

	// dir > return normal cartesian direction
	vec2 dir();
	vec2 dir(T const &a_x, T const &a_y);
	vec2 dir(vec2<T> const &origin);


	// square length can be usefull and faster when the real length is not necessary
	T mag_sq() const;
	T mag_sq(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// mag and dist is a same methode
	double mag() const;
	double mag(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// call mag to calculate the the dist
	double dist() const;
	double dist(vec2<T> const &v) const;

	// cacule the power of the vector for each component
	vec2 pow(T const &pow);
	vec2 pow(T const &pow_x, T const &pow_y);

	//normalize
	vec2 normalize();
	static vec2 normalize(vec2<T> &target);
	
	//map
	vec2 map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec2 map(vec2<T> const &start_src, vec2<T> const &stop_src, vec2<T> const &start_dst, vec2<T> const &stop_dst);

	// limit
	vec2 limit(T const &max);

	// constrain
	vec2 constrain(T const &min, T const &max);
	vec2 constrain(vec2<T> const &min, vec2<T> const &max);
	
	// operator
  bool compare(vec2<T> const &target, vec2<T> const &area);
  bool compare(vec2<T> const &target, T const &area);
  // random
  vec2 rand();
	vec2 rand(T const &max);
	vec2 rand(T const &min, T const &max);
	vec2 rand(vec2<T> const &min, vec2<T> const &max);
	vec2 rand(T const &x_min, T const &x_max, T const &y_min, T const &y_max);

	vec2 rand(std::default_random_engine &generator);
	vec2 rand(T const &max, std::default_random_engine &generator);
	vec2 rand(T const &min, T const &max, std::default_random_engine &generator);
	vec2 rand(vec2<T> const &min, vec2<T> const &max, std::default_random_engine &generator);
	vec2 rand(T const &x_min, T const &x_max, T const &y_min, T const &y_max, std::default_random_engine &generator);



	// public vec2 wave(int value, float s);
	// public vec2 wave(int value, float sx, float sy);
	// public vec2 cos_wave(int value, float s);
	// public vec2 cos_wave(int value, float sx, float sy);
	// public vec2 sin_wave(int value, float s);
	// public vec2 sin_wave(int value, float sx, float sy);

	//VEC 2
	// public vec2 tan();
	// public vec2 tan(float a_x, float a_y);
	// public vec2 tan(vec2 target);
	// public float angle();
	// public float angle(vec2 target);
	// public float heading();

	bool operator==(vec2<T> const &rhs);
	bool operator==(T const &rhs);

	bool operator!=(vec2<T> const &rhs);
	bool operator!=(T const &rhs);

	vec2 & operator=(vec2<T> const &rhs);

	vec2 operator+(vec2<T> const &rhs) const;
	vec2 operator+(T const &rhs) const;
	// vec2 add(vec2<T> const &rhs) const;
	// vec2 add(T const &rhs) const;
	vec2 & operator+=(vec2<T> const &rhs);
	vec2 & operator+=(T const &rhs);

	vec2 operator-(vec2<T> const &rhs) const;
	vec2 operator-(T const &rhs) const;
	// vec2 sub(vec2<T> const &rhs) const;
	// vec2 sub(T const &rhs) const;
	vec2 & operator-=(vec2<T> const &rhs);
	vec2 & operator-=(T const &rhs);

	vec2 operator*(vec2<T> const &rhs) const;
	vec2 operator*(T const &rhs) const;
	// vec2 mult(vec2<T> const &rhs) const;
	// vec2 mult(T const &rhs) const;
	vec2 & operator*=(vec2<T> const &rhs);
	vec2 & operator*=(T const &rhs);

	vec2 operator/(vec2<T> const &rhs) const;
	vec2 operator/(T const &rhs) const;
	// vec2 div(vec2<T> const &rhs) const;
	// vec2 div(T const &rhs) const;
	vec2 & operator/=(vec2<T> const &rhs);
	vec2 & operator/=(T const &rhs);

	// info
	static void warning(bool is);
	static int get_instance();
}; 


template <class T>
std::ostream & operator<<(std::ostream &out, vec2<T> const &rhs);





/**
* TEMPLATE DEFINITION
*/

// CONSTRUCTOR + DESTRUCTOR
template <class T>
vec2<T>::vec2() : _x(0), _y(0) {
	this->size = 2;
  set_list(this->v_list, &_x, &_y); 
	if(vec2<T>::_warning) {
		std::cout << "Default constructor vec2" << std::endl;
		vec2<T>::instance++;
	}	
	return;
}

template <class T>
vec2<T>::vec2(T const &arg) : _x(arg), _y(arg) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Parametric constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}

template <class T>
vec2<T>::vec2(T const &x, T const &y) : _x(x), _y(y) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Parametric constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}

template <class T>
vec2<T>::vec2(vec2<T> const &src) : _x(src.x()), _y(src.y()) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Copy constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}
	
template <class T>
vec2<T>::~vec2() {
	if(vec2<T>::_warning) {
		std::cout << "Destructor vec2" << std::endl;
		vec2<T>::instance--;
	}
	return;
}


// COMMMON ALGORITHM FOR VEC
/**
* dot
*/
template <class T>
T vec2<T>::dot(vec2<T> const &v) const {
	return this->x()*v.x() + this->y()*v.y();
}

template <class T>
T vec2<T>::dot(T const &x, T const &y) const {
	return this->x()*x + this->y()*y;
}

/**
* DIRECTION NORMAL
*/
template <class T>
vec2<T>	vec2<T>::dir() {
	return vec2<T>::dir(vec2<T>());
}

template <class T>
vec2<T>	vec2<T>::dir(T const &a_x, T const &a_y) {
	return vec2<T>::dir(vec2<T>(a_x, a_y));
}

template <class T>
vec2<T>	vec2<T>::dir(vec2<T> const &origin) {
	vec2 temp = *this;
	T dist = vec2<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}





/**
* MAG / DIST
*/
template <class T>
T vec2<T>::mag_sq() const {
	return vec<T>::mag_sq();
}

template <class T>
T vec2<T>::mag_sq(vec2<T> const &v) const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += ((v.v_list.at(i)[0] - this->v_list.at(i)[0]) * (v.v_list.at(i)[0] - this->v_list.at(i)[0]));
	}
	return res;
}

// mag
template <class T>
double vec2<T>::mag() const {
	return vec<T>::mag();
}

template <class T>
double vec2<T>::mag(vec2<T> const &v) const {
	return ::sqrt(vec2<T>::mag_sq(v));
}

// dist
template <class T>
double vec2<T>::dist() const {
	return vec2<T>::mag();
}

template <class T>
double vec2<T>::dist(vec2<T> const &v) const {
	return vec2<T>::mag(v);
}


// pow
template <class T>
vec2<T>	vec2<T>::pow(T const &pow) {
	return vec2<T>::pow(pow, pow);
}

template <class T>
vec2<T>	vec2<T>::pow(T const &pow_x, T const &pow_y) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	return *this;
}

// random
template <class T>
vec2<T>	vec2<T>::rand() {
	return rand(0,1, 0,1);
}

template <class T>
vec2<T>	vec2<T>::rand(std::default_random_engine &generator) {
	return rand(0,1, 0,1, generator);
}

//
template <class T>
vec2<T>	vec2<T>::rand(T const &max) {
	return rand(0,max, 0,max);
}

template <class T>
vec2<T>	vec2<T>::rand(T const &max, std::default_random_engine &generator) {
	return rand(0,max, 0,max, generator);
}

//
template <class T>
vec2<T>	vec2<T>::rand(T const &min, T const &max) {
	return rand(min,max, min,max);
}

template <class T>
vec2<T>	vec2<T>::rand(T const &min, T const &max, std::default_random_engine &generator) {
	return rand(min,max, min,max ,generator);
}

//
template <class T>
vec2<T>	vec2<T>::rand(vec2<T> const &min, vec2<T> const &max) {
	return rand(min.x(),max.x(), min.y(),max.y());
}

template <class T>
vec2<T>	vec2<T>::rand(vec2<T> const &min, vec2<T> const &max, std::default_random_engine &generator) {
	return rand(min.x(),max.x(), min.y(),max.y(), generator);
}

//
template <class T>
vec2<T>	vec2<T>::rand(T const &x_min, T const &x_max, 
											T const &y_min, T const &y_max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return rand(x_min,x_max,
							y_min,y_max,
							generator);
}


template <class T>
vec2<T>	vec2<T>::rand(T const &x_min, T const &x_max, 
											T const &y_min, T const &y_max,
											std::default_random_engine &generator) {
	switch(vec<T>::get_type()) {
		case 'c':
			this->_x = random_char(x_min, x_max);
			this->_y = random_char(y_min, y_max);
			break;
		case 'b':
			this->_x = random_bool();
			this->_y = random_bool();
			break;
		case 's':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			break;
		case 'i':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			break;
		case 'l':
			this->_x = random_long(x_min, x_max);
			this->_y = random_long(y_min, y_max);
			break;
		case 'f':
			this->_x = random(x_min, x_max);
			this->_y = random(y_min, y_max);
			break;
		case 'd':
			this->_x = random_double(x_min, x_max);
			this->_y = random_double(y_min, y_max);
			break;
		default:
			if(vec2<T>::_warning) {
				std::cout << "vec2<T>::rand(); wait <T arg> like bool, char, int, float, double" << std::endl;
			}
			abort();
	}
	return *this;
}


// normalize
template <class T>
vec2<T>	vec2<T>::normalize() {
	T m = vec2<T>::mag();
	if (m != 0 && m != 1) {
		*this /= m;
	}
	return *this;
}

template <class T>
vec2<T>	vec2<T>::normalize(vec2<T> &target) {
	return target.normalize();
}

// map
template <class T>
vec2<T>	vec2<T>::map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = ::map(	this->list().at(i),
																	start_src,stop_src, 
																	start_dst,stop_dst);
	}
	return *this;
}

template <class T>
vec2<T>	vec2<T>::map(vec2<T> const &start_src, vec2<T> const &stop_src, vec2<T> const &start_dst, vec2<T> const &stop_dst) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = ::map(	this->list().at(i), 
																	start_src.ref().at(i)[0],stop_src.ref().at(i)[0], 
																	start_dst.ref().at(i)[0],stop_dst.ref().at(i)[0]);
	}
	return *this;
}



template <class T>
vec2<T>	vec2<T>::limit(T const &max) {
	if (vec2<T>::magSq() > max*max) {
		vec2<T>::normalize();
		*this *= max;
	}
	return *this;
}


// constrain
template <class T>
vec2<T>	vec2<T>::constrain(T const &min, T const &max) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->list().at(i) < min ) {
			this->ref().at(i)[0] = min;
		}
		if(this->list().at(i) > max ) {
			this->ref().at(i)[0] = max;
		}
	}
	return *this;
}

template <class T>
vec2<T>	vec2<T>::constrain(vec2<T> const &min, vec2<T> const &max) {
for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->list().at(i) < min.ref().at(i)[0]) {
			this->ref().at(i)[0] = min.ref().at(i)[0];
		}
		if(this->list().at(i) > max.ref().at(i)[0]) {
			this->ref().at(i)[0] = max.ref().at(i)[0];
		}
	}
	return *this;
}

// OPERATOR
// op =
template <class T>
vec2<T> & vec2<T>::operator=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = rhs.ref().at(i)[0];
	}
	return *this;
}


// op +
template <class T>
vec2<T> vec2<T>::operator+(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator+(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator+=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator+=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs;
	}
	return *this;
}

// op -
template <class T>
vec2<T> vec2<T>::operator-(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator-(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs;
	}
	return temp;
}


template <class T>
vec2<T> & vec2<T>::operator-=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator-=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs;
	}
	return *this;
}



// op *
template <class T>
vec2<T> vec2<T>::operator*(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator*(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator*=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator*=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs;
	}
	return *this;
}



// op /
template <class T>
vec2<T> vec2<T>::operator/(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator/(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator/=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] /= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator/=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] /= rhs;
	}
	return *this;
}

// op ==
template <class T>
bool vec2<T>::operator==(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs.ref().at(i)[0])
			return false;
	}
	return true;
}


template <class T>
bool vec2<T>::operator==(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs)
			return false;
	}
	return true;
}

// op !=
template <class T>
bool vec2<T>::operator!=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs.ref().at(i)[0]) {
			return true;
		}
	}
	return false;
}


template <class T>
bool vec2<T>::operator!=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs) {
			return true;
		}
	}
	return false;
}


// COMPARE
template <class T>
bool vec2<T>::compare(vec2<T> const &target, vec2<T> const &area) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if((	this->ref().at(i)[0] < target.ref().at(i)[0] - area.ref().at(i)[0] 
					|| this->ref().at(i)[0] > target.ref().at(i)[0] + area.ref().at(i)[0])) { 
			return false;
		}
	}
	return true;
}

template <class T>
bool vec2<T>::compare(vec2<T> const &target, T const &area) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if((	this->ref().at(i)[0] < target.ref().at(i)[0] - area 
					|| this->ref().at(i)[0] > target.ref().at(i)[0] + area)) {
			return false;
		}
	}
	return true;
}



// set
template <class T>
vec2<T> vec2<T>::set(T const &x, T const &y) {
	this->_x = x;
	this->_y = y;
	return *this;
}

template <class T>
vec2<T> vec2<T>::x(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec2<T> vec2<T>::y(T const &y) {
	this->_y = y;
	return *this;
}



// get
template <class T>
T vec2<T>::x() const {
	return this->_x;
}

template <class T>
T vec2<T>::y() const {
	return this->_y;
}

template <class T>
T vec2<T>::min() const {
	return this->_x;
}

template <class T>
T vec2<T>::max() const {
	return this->_y;
}

template <class T>
vec2<T> vec2<T>::copy() const {
	return *this;
}

template <class T>
T * vec2<T>::array() const {
	static T arg[2];
	for(size_t i = 0 ; i < this->get_size() ; i++) {
		arg[i] = *this->v_list.at(i);
	}
	return arg;
}


// info
template <class T>
void vec2<T>::warning(bool is) {
	vec2<T>::_warning = is;
}


template <class T>
std::ostream & operator<<(std::ostream & out, vec2<T> const & rhs) {
	out << "[ " << rhs.x() << ", " << rhs.y() << " ]";
	return out;
}

template <class T>
int vec2<T>::get_instance() {
	return vec2<T>::instance;
}


// static instantiation
template <class T>
bool vec2<T>::_warning = false;

template <class T>
int vec2<T>::instance = 0;

#endif