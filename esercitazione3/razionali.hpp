template<typename I>
#include <concepts>
 class rational {
 I num_;
 I den_;
 private:
 bool NaN,Inf;
 I mcd() const {
	I max,min,resto;
	if (num_>=den_) {
		max=num_;
		min=den_;
	}
	else{
		max=den_;
		min=num_;
	}
	resto=min;
	while (resto!=0) {
		resto=max%min;
		max=min;
		min=resto;
	}
	return max;
 }
		


 public:
 /* Costruttore di default */
 rational()
 : num_(I{0}), den_(I{1})
 {NaN=false;
 Inf=false;
 }

 /* Costruttore user-defined */
 rational(const I& pnum, const I& pden)
 : num_(pnum), den_(pden)
 {NaN=!(num_ || den_);
 Inf=num_ && !den_;
 }
 
 /* Restituiscono i valori di num e den */
 I num() const { return num_; }
 I den() const { return den_; }
 
 rational& operator+=(const rational& other) {
 num_ = other.num_*den_+other.den_*num_;
 den_ *= other.den_;
 NaN=!(num_ || den_);
 Inf=num_ && !den_;
 return *this;
 }
 
 /* Implementazione canonica della somma */
 rational operator+(const rational& other) const {
 rational ret = *this;
 ret += other;
 return ret;
 } 
 
 rational& operator-=(const rational& other) {
 num_ = other.den_*num_-other.num_*den_;
 den_ *= other.den_;
 NaN=!(num_ || den_);
 Inf=num_ && !den_;
 return *this;
 }
 
 rational operator-(const rational& other) const {
 rational ret = *this;
 ret -= other;
 return ret;
 } 
 
 
 rational& operator*=(const rational& other) {
 num_ *= other.num_;
 den_ *= other.den_;
 NaN=!(num_ || den_);
 Inf=num_ && !den_;
 return *this;
 }
 
 rational operator*(const rational& other) const {
 rational ret = *this;
 ret *= other;
 return ret;
 }
 
 rational& operator/=(const rational& other) {
 num_ *= other.den_;
 den_ *= other.num_;
 NaN=!(num_ || den_);
 Inf=num_ && !den_;
 return *this;
 }
 
 rational operator/(const rational& other) const {
 rational ret = *this;
 ret /= other;
 return ret;
 }
 
 
 friend std::ostream&
 operator<<(std::ostream& os, const rational<I>& r)
 {
	 if (r.NaN) {
		os << "NaN";
		return os;
	 }
	if (r.Inf) {
		os<<"Inf";
		return os;
	}
os  << r.num()/r.mcd() << "/" << r.den()/r.mcd();
 return os;
 }
 
 
 
 /*std::ostream&
 operator<<(std::ostream& os)
 {
	 if (NaN) {
		os << "NaN";
		return os;
	 }
	if (Inf) {
		os<<"Inf";
		return os;
	}
os  << (*this).num() << "/" << (*this).den() << "\n";
 return os;
 }*/
 
 };