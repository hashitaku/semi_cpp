/**
 * @file matrix.hpp
 * @brief constexpr matrix class
 * @author hashitaku
 * @data 2019/7/27
 */

#ifndef SEMI_CPP_MATRIX
#define SEMI_CPP_MATRIX

#include<cstddef>
#include<iostream>
#include<array>
#include<tuple>

namespace semi_cpp::numeric{

/**
 * @struct matrix
 * @brief constexpr matrix class
 */
template<typename Tp, size_t N, size_t M>
struct Matrix{
    Tp mat_[N][M];

    using value_type = Tp;
    using reference = value_type&;
    using const_reference = const value_type&;

    constexpr size_t row() const noexcept { return N; }
    constexpr size_t col() const noexcept { return M; }

    constexpr Matrix<Tp, M, N> transpose() const noexcept {
        Matrix<Tp, M, N> retval{};

        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                retval.mat_[j][i] = this->mat_[i][j];
            }
        }

        return retval;
    }

    constexpr std::tuple<Matrix<Tp, N, M>, Matrix<Tp, N, M>> LU() const noexcept {
        Matrix<Tp, N, M> ret_l{};
        Matrix<Tp, N, M> ret_u{};

        static_assert(N == M, "member function LU() is only N == M");

        for(size_t i = 0; i < N; i++){
            ret_l.mat_[i][i] = Tp{1};
        }

        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                if(i <= j){
                    Tp tmp{0};
                    for(size_t k = 0; k < i; k++){
                        tmp += ret_l.mat_[i][k] * ret_u.mat_[k][j];
                    }
                    ret_u.mat_[i][j] = this->mat_[i][j] - tmp;
                }else{
                    Tp tmp{0};
                    for(size_t k = 0; k < j; k++){
                        tmp += ret_l.mat_[i][k] * ret_u.mat_[k][j];
                    }
                    ret_l.mat_[i][j] = (this->mat_[i][j] - tmp) / ret_u.mat_[j][j];
                }
            }
        }

        return {ret_l, ret_u};
    }

    constexpr reference operator()(size_t row, size_t col){
        if(row < N && col < M){
            return mat_[row][col];
        }else{
            throw std::out_of_range("Matrix::operator() out of range");
        }
    }

    constexpr const_reference operator()(size_t row, size_t col) const {
        if(row < N && col < M){
            return mat_[row][col];
        }else{
            throw std::out_of_range("Matrix::operator() out of range");
        }
    }

    constexpr Matrix<Tp, N, M>& operator*=(const Tp& a) noexcept {
        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                mat_[i][j] *= a;
            }
        }

        return *this;
    }

    constexpr Matrix<Tp, N, M>& operator=(const Matrix<Tp, N, M>& obj) noexcept {
        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                mat_[i][j] = obj.mat_[i][j];
            }
        }

        return *this;
    }

    constexpr Matrix<Tp, N, M>& operator+=(const Matrix<Tp, N, M>& obj) noexcept {
        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                mat_[i][j] += obj.mat_[i][j];
            }
        }

        return *this;
    }

    constexpr Matrix<Tp, N, M>& operator-=(const Matrix<Tp, N, M>& obj) noexcept {
        for(size_t i = 0; i < N; i++){
            for(size_t j = 0; j < M; j++){
                mat_[i][j] -= obj.mat_[i][j];
            }
        }
        
        return *this;
    }
};

template<typename Tp, size_t N, size_t M>
constexpr Matrix<Tp, N, M> operator+(const Matrix<Tp, N, M>& x, const Matrix<Tp, N, M>& y) noexcept {
    Matrix<Tp, N, M> retval = x;
    retval += y;
    return retval;
}

template<typename Tp, size_t N, size_t M>
constexpr Matrix<Tp, N, M> operator-(const Matrix<Tp, N, M>& x, const Matrix<Tp, N, M>& y) noexcept {
    Matrix<Tp, N, M> retval = x;
    retval -= y;
    return retval;
}

template<typename Tp, size_t lN, size_t MN, size_t rM>
constexpr Matrix<Tp, lN, rM> operator*(const Matrix<Tp, lN, MN>& x, const Matrix<Tp, MN, rM>& y){
    Matrix<Tp, lN, rM> retval{};
    for(size_t i = 0; i < lN; i++){
        for(size_t j = 0; j < MN; j++){
            for(size_t k = 0; k < rM; k++){
                retval(i, k) += x(i, j) * y(j, k);
            }
        }
    }

    return retval;
}

template<typename Tp, size_t N, size_t M>
constexpr Matrix<Tp, N, M> operator*(const Matrix<Tp, N, M>& x, const Tp& y){
    Matrix<Tp, N, M> retval = x;
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            retval(i, j) *= y;
        }
    }

    return retval;
}

template<typename Tp, size_t N, size_t M>
constexpr Matrix<Tp, N, M> operator*(const Tp& x, const Matrix<Tp, N, M>& y){
    Matrix<Tp, N, M> retval = y;
    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < M; j++){
            retval(i, j) *= x;
        }
    }

    return retval;
}

template<typename Tp, size_t N, size_t M, typename Char, typename Traits>
std::basic_ostream<Char, Traits>&
operator<<(std::basic_ostream<Char, Traits>& os, const Matrix<Tp, N, M>& x){
    for(const auto& e : x.mat_){
        for(const auto& ee : e){
            os << ee << " ";
        }os << std::endl;
    }
    return os;
}

}

#endif //SEMI_CPP_MATRIX
