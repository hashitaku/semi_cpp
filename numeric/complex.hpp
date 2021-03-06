/**
 * @file complex.hpp
 * @brief constexpr complex class
 * @author hashitaku
 * @data 2019/7/27
 */

#ifndef SEMI_CPP_COMPLEX
#define SEMI_CPP_COMPLEX

#include"../math/abs.hpp"
#include"../math/pow.hpp"

/**
 * @def SEMI_CPP_COMPLEX_CONCEPT
 * テンプレートパラメータTypeがcomplex<>と一致しているか判定マクロ
 */
#define SEMI_CPP_COMPLEX_CONCEPT(Type) \
(std::is_same_v<Type, semi_cpp::numeric::complex<float>> || \
std::is_same_v<Type, semi_cpp::numeric::complex<double>> || \
std::is_same_v<Type, semi_cpp::numeric::complex<long double>>)

#include<ostream>

namespace semi_cpp::numeric{

/**
 * @class complex
 * @brief constexpr complex class
 */
template<typename Tp>
class complex{
    private:
        Tp re;
        Tp im;
    public:
        using value_type = Tp;

        constexpr complex() : re(0), im(0) {}
        constexpr complex(Tp a, Tp b) : re(a), im(b) {}

        constexpr Tp real() const { return re; }
        constexpr Tp imag() const { return im; }

        void real(Tp a){ re = a; }
        void imag(Tp a){ im = a; }

        constexpr complex<Tp>& operator+=(const Tp& a){
            re += a;
            return *this;
        }

        constexpr complex<Tp>& operator-=(const Tp& a){
            re -= a;
            return *this;
        }

        constexpr complex<Tp>& operator=(const Tp& a){
            re = a;
            im = Tp();
            return *this;
        }

        constexpr complex<Tp>& operator*=(const Tp& a){
            re *= a;
            im *= a;
            return *this;
        }

        constexpr complex<Tp>& operator/=(const Tp& a){
            re /= a;
            im /= a;
            return *this;
        }

        constexpr complex<Tp>& operator=(const complex<Tp>& z){
            re = z.real();
            im = z.imag();
            return *this;
        }

        constexpr complex<Tp>& operator+=(const complex<Tp>& z){
            re += z.real();
            im += z.imag();
            return *this;
        }

        constexpr complex<Tp>& operator-=(const complex<Tp>& z){
            re -= z.real();
            im -= z.imag();
            return *this;
        }

        constexpr complex<Tp>& operator*=(const complex<Tp>& z){
            const Tp r = re * z.real() - im * z.imag();
            im = re * z.imag() + im * z.real();
            re = r;
            return *this;
        }

        constexpr complex<Tp>& operator/=(const complex<Tp>& z){
            const Tp r = re * z.real() + im * z.imag();
            const Tp n = z.real() * z.real() + z.imag() * z.imag();
            im = (im * z.real() - re * z.imag()) / n;
            re = r / n;
            return *this;
        }

};

template<typename Tp>
constexpr Tp real(const complex<Tp>& z){
    return z.real();
}

template<typename Tp>
constexpr Tp imag(const complex<Tp>& z){
    return z.imag();
}

template<typename Tp>
constexpr Tp abs(const complex<Tp>& z){
    if(z.real() == 0.0) return semi_cpp::math::abs(z.imag());
    if(z.imag() == 0.0) return semi_cpp::math::abs(z.real());

    if(semi_cpp::math::abs(z.imag()) > semi_cpp::math::abs(z.real())){
        auto t = z.real() / z.imag();
        return semi_cpp::math::abs(z.imag()) * semi_cpp::math::pow(1.0 + t * t, 0.5);
    }else{
        auto t = z.imag() / z.real();
        return semi_cpp::math::abs(z.real()) * semi_cpp::math::pow(1.0 + t * t, 0.5);           
    }
}

template<typename Tp>
constexpr complex<Tp> conj(const complex<Tp>& z){
    return {z.real(), -z.imag()};
}

template<typename Tp>
constexpr Tp norm(const complex<Tp>& z){
    return z * conj(z);
}

template<typename Tp>
constexpr complex<Tp> operator+(const complex<Tp>& x, const complex<Tp>& y){
    complex<Tp> retval = x;
    retval += y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator+(const complex<Tp>& x, const Tp& y){
    complex<Tp> retval = x;
    retval += y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator+(const Tp& x, const complex<Tp>& y){
    complex<Tp> retval = y;
    retval += x;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator-(const complex<Tp>& x, const complex<Tp>& y){
    complex<Tp> retval = x;
    retval -= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator-(const complex<Tp>& x, const Tp& y){
    complex<Tp> retval = x;
    retval -= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator-(const Tp& x, const complex<Tp>& y){
    complex<Tp> retval(x, -y.imag());
    retval -= y.real();
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator*(const complex<Tp>& x, const complex<Tp>& y){
    complex<Tp> retval = x;
    retval *= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator*(const complex<Tp>& x, const Tp& y){
    complex<Tp> retval = x;
    retval *= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator*(const Tp& x, const complex<Tp>& y){
    complex<Tp> retval = y;
    retval *= x;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator/(const complex<Tp>& x, const complex<Tp>& y){
    complex<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator/(const complex<Tp>& x, const Tp& y){
    complex<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator/(const Tp& x, const complex<Tp>& y){
    complex<Tp> retval = x;
    retval /= y;
    return retval;
}

template<typename Tp>
constexpr complex<Tp> operator+(const complex<Tp>& x){
    return x;
}

template<typename Tp>
constexpr complex<Tp> operator-(const complex<Tp>& x){
    return {-x.real(), -x.imag()};
}

template<typename Tp>
constexpr bool operator==(const complex<Tp>& x, const complex<Tp>& y){
    return x.real() == y.real() && x.imag() == y.imag();
}

template<typename Tp>
constexpr bool operator==(const complex<Tp>& x, const Tp& y){
    return x.real() == y && x.imag() == Tp();
}

template<typename Tp>
constexpr bool operator==(const Tp& x, const complex<Tp>& y){
    return x == y.real() && Tp() == y.imag();
}

template<typename Tp>
constexpr bool operator!=(const complex<Tp>& x, const complex<Tp>& y){
    return x.real() != y.real() || x.imag() != y.imag();
}

template<typename Tp>
constexpr bool operator!=(const complex<Tp>& x, const Tp& y){
    return x.real() != y || x.imag() != Tp();
}

template<typename Tp>
constexpr bool operator!=(const Tp& x, const complex<Tp>& y){
    return x != y.real() || Tp() != y.imag();
}

template<typename Tp, typename Char, typename Traits>
std::basic_ostream<Char, Traits>&
operator<<(std::basic_ostream<Char, Traits>& os, const complex<Tp>& x){
    os << '(' << x.real() << ',' << x.imag() << ')';
    return os;
}
}

#endif //SEMI_CPP_COMPLEX
