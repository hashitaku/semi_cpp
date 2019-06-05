#ifndef SEMI_CPP_MATRIX
#define SEMI_CPP_MATRIX

#include<cstddef>
#include<iostream>
#include<array>

namespace semi_cpp::numeric{

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
