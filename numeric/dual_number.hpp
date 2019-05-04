#ifndef SEMI_CPP_DUAL_NUM
#define SEMI_CPP_DUAL_NUM

#include<iostream>
#include<type_traits>

namespace semi_cpp::numeric{

template<typename Tp>
class dual_num{
    private:
        Tp re;
        Tp im;
    public:

        using value_type = Tp;

        constexpr dual_num() : re(0), im(0) {}
        constexpr dual_num(Tp a, Tp b) : re(a), im(b) {}

        constexpr Tp real() const { return re; }
        constexpr Tp imag() const { return im; }

        constexpr dual_num<Tp>& operator+=(const Tp& a){
            re += a;
            return *this;
        }

        constexpr dual_num<Tp>& operator-=(const Tp& a){
            re -= a;
            return *this;
        }

        constexpr dual_num<Tp>& operator=(const Tp& a){
            re = a;
            im = Tp();
            return *this;
        }

        constexpr dual_num<Tp>& operator*=(const Tp& a){
            re *= a;
            im *= a;
            return *this;
        }

        constexpr dual_num<Tp>& operator/=(const Tp& a){
            re /= a;
            im /= a;
            return *this;
        }

        constexpr dual_num<Tp>& operator=(const dual_num<Tp>& z){
            re = z.real();
            im = z.imag();
            return *this;
        }

        constexpr dual_num<Tp>& operator+=(const dual_num<Tp>& z){
            re += z.real();
            im += z.imag();
            return *this;
        }

        constexpr dual_num<Tp>& operator-=(const dual_num<Tp>& z){
            re -= z.real();
            im -= z.imag();
            return *this;
        }

        constexpr dual_num<Tp>& operator*=(const dual_num<Tp>& z){
            const Tp r = re * z.real();
            im = re * z.imag() + im * z.real();
            re = r;
            return *this;
        }

        constexpr dual_num<Tp>& operator/=(const dual_num<Tp>& z){
            const Tp r = re * z.real();
            const Tp n = z.real() * z.real();
            im = (im * z.real() - re * z.imag()) / n;
            re = r / n;
            return *this;
        }

};

template<typename Tp>
constexpr Tp real(const dual_num<Tp>& z){
    return z.real();
}

template<typename Tp>
constexpr Tp imag(const dual_num<Tp>& z){
    return z.imag();
}

template<typename Tp>
constexpr dual_num<Tp> operator+(const dual_num<Tp>& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = x;
    retval += y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator+(const dual_num<Tp>& x, const Tp& y){
    dual_num<Tp> retval = x;
    retval += y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator+(const Tp& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = y;
    retval += x;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator-(const dual_num<Tp>& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = x;
    retval -= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator-(const dual_num<Tp>& x, const Tp& y){
    dual_num<Tp> retval = x;
    retval -= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator-(const Tp& x, const dual_num<Tp>& y){
    dual_num<Tp> retval(x, -y.imag());
    retval -= y.real();
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator*(const dual_num<Tp>& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = x;
    retval *= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator*(const dual_num<Tp>& x, const Tp& y){
    dual_num<Tp> retval = x;
    retval *= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator*(const Tp& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = y;
    retval *= x;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator/(const dual_num<Tp>& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator/(const dual_num<Tp>& x, const Tp& y){
    dual_num<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator/(const Tp& x, const dual_num<Tp>& y){
    dual_num<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr dual_num<Tp> operator+(const dual_num<Tp>& x){
    return x;
}

template<typename Tp>
constexpr dual_num<Tp> operator-(const dual_num<Tp>& x){
    return {-x.real(), -x.imag()};
}

template<typename Tp>
constexpr bool operator==(const dual_num<Tp>& x, const dual_num<Tp>& y){
    return x.real() == y.real() && x.imag() == y.imag();
}

template<typename Tp>
constexpr bool operator==(const dual_num<Tp>& x, const Tp& y){
    return x.real() == y && x.imag() == Tp();
}

template<typename Tp>
constexpr bool operator==(const Tp& x, const dual_num<Tp>& y){
    return x == y.real() && Tp() == y.imag();
}

template<typename Tp>
constexpr bool operator!=(const dual_num<Tp>& x, const dual_num<Tp>& y){
    return x.real() != y.real() || x.imag() != y.imag();
}

template<typename Tp>
constexpr bool operator!=(const dual_num<Tp>& x, const Tp& y){
    return x.real() != y || x.imag() != Tp();
}

template<typename Tp>
constexpr bool operator!=(const Tp& x, const dual_num<Tp>& y){
    return x != y.real() || Tp() != y.imag();
}

template<typename Tp, typename Char, typename Traits>
std::basic_ostream<Char, Traits>&
operator<<(std::basic_ostream<Char, Traits>& os, const dual_num<Tp>& x){
    os << '(' << x.real() << ',' << x.imag() << ')';
    return os;
}
}

#endif //SEMI_CPP_DUAL_NUM
