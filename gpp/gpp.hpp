/**
 * @file gpp.hpp
 * @brief gnuplot cpp wrapper
 * @details gnuplot cpp wrapper file
 * @author hashitaku
 * @data 2019/5/4
 */

#ifndef SEMI_GNUPLOT_CPP_LIB
#define SEMI_GNUPLOT_CPP_LIB

#include<cstdio>
#include<cstdlib>

#include<iostream>
#include<type_traits>
#include<string>
#include<vector>
#include<tuple>

/**
 * @namespace semi_cpp::gpp
 * @brief gnuplot cpp wrapper namespace
 * @details gnuplot cpp wrapper namespace
 */
namespace semi_cpp::gpp{

/**
 * @brief gnuplot wrapper class
 * @details gnuplot wrapper class
 */
class Gnuplot final {
    private:
        std::FILE *pipe;
        bool plot_flag;
    public:
        /**
         * @brief default constructor
         * @details this is noexcept
         */
        Gnuplot() noexcept : plot_flag(false){
          pipe = popen("gnuplot -persist", "w");
            if(pipe == nullptr){
                std::exit(EXIT_FAILURE);
            }
        }

        /**
         * @brief x and y range set constructor
         * @details this is noexcept
         */
        Gnuplot(double xbegin, double xend, double ybegin, double yend) noexcept {
          pipe = popen("gnuplot -persist", "w");
            if(pipe == nullptr){
                std::exit(EXIT_FAILURE);
            }

            this->plot_flag = false;

            *this << "set xrange [" << xbegin << ":" << xend << "]\n";
            *this << "set yrange [" << ybegin << ":" << yend << "]\n";          
        }

        /**
         * @brief copy constructor
         * @details this is delete
         */
        Gnuplot(const Gnuplot &) = delete;

        /**
         * @brief move constructor
         * @details this is delete
         */
        Gnuplot(Gnuplot &&) noexcept = delete;

        /**
         * @brief call std::fflush
         * @details this is noexcept
         */
        void flush() noexcept {
            if(std::fflush(pipe) == EOF){
                std::cerr << "flush error" << std::endl;
            }
        }

        /**
         * @brief set xrange
         * @details this is noexcept
         */
        void set_xrange(double begin, double end) noexcept {
            *this << "set xrange [" << begin << ":" << end << "]\n";
        }
    
        /**
         * @brief set yrange
         * @details this is noexcept
         */
        void set_yrange(double begin, double end) noexcept {
            *this << "set yrange [" << begin << ":" << end << "]\n";
        }

        /**
         * @brief plot string function
         * @details plot a function represented by a string. this is noexcept
         */
        void plot(const char *str) noexcept {
            if(plot_flag == false){
                std::fprintf(pipe, "plot %s\n", str);
                std::fflush(pipe);
                plot_flag = true;
            }else{
                std::fprintf(pipe, "replot %s\n", str);
                std::fflush(pipe);
            }
        }

        /**
         * @brief plot string function
         * @details plot a function represented by a string. this is noexcept
         */
        void plot(const std::string& str) noexcept {
            if(plot_flag == false){
                std::fprintf(pipe, "plot %s\n", str.c_str());
                std::fflush(pipe);
                plot_flag = true;
            }else{
                std::fprintf(pipe, "replot %s\n", str.c_str());
                std::fflush(pipe);
            }
        }

        /**
         * @brief plot function object
         * @details function object return type is only double. this is noexcept
         */
        template<typename FuncType>
        void plot(FuncType func, double begin, double end, double delta = 0.01){
            if constexpr(std::is_same_v<std::invoke_result_t<FuncType, double>, double>) noexcept {
                if(plot_flag == false){
                    std::fprintf(pipe, "plot '-' with line\n");
                    for(double i = begin; i < end; i+=delta){
                        std::fprintf(pipe, "%f %f\n", i, func(i));
                    }std::fprintf(pipe, "e\n");
                    std::fflush(pipe);
                    plot_flag = true;
                }else{
                    std::fprintf(pipe, "replot '-' with line\n");
                    for(double i = begin; i < end; i+=delta){
                        std::fprintf(pipe, "%f %f\n", i, func(i));
                    }std::fprintf(pipe, "e\n");
                    std::fflush(pipe);
                }
            }else{
                static_assert([](){ return false; }(), "gpp::plot() FuncType return Type is only double");
            }
        }

        /**
         * @brief operator<<() is the same as std::fprintf
         * @details operator<<() is the same as std::fprintf. this is noexcept
         */
        Gnuplot& operator<<(const char *str) noexcept {
            std::fprintf(pipe, "%s", str);
            this->flush();
            
            return *this;
        }

        /**
         * @brief operator<<() is the same as std::fprintf
         * @details operator<<() is the same as std::fprintf. this is noexcept
         */
        Gnuplot& operator<<(int num) noexcept {
            std::fprintf(pipe, "%d", num);
            this->flush();

            return *this;
        }

        /**
         * @brief operator<<() is the same as std::fprintf
         * @details operator<<() is the same as std::fprintf. this is noexcept
         */
        Gnuplot& operator<<(float num) noexcept {
            std::fprintf(pipe, "%f", num);
            this->flush();

            return *this;
        }

        /**
         * @brief operator<<() is the same as std::fprintf
         * @details operator<<() is the same as std::fprintf. this is noexcept
         */
        Gnuplot& operator<<(double num) noexcept {
            std::fprintf(pipe, "%f", num);
            this->flush();

            return *this;
        }

        /**
         * @brief operator<<() is the same as std::fprintf
         * @details operator<<() is the same as std::fprintf. this is noexcept
         */
        Gnuplot& operator<<(std::size_t num) noexcept {
            std::fprintf(pipe, "%zu", num);
            this->flush();

            return *this;
        }

        /**
         * @brief copy assignment operator is delete 
         */
        Gnuplot &operator=(const Gnuplot &) = delete;

        /**
         * @brief move assignment opetator is delete
         */
        Gnuplot &operator=(Gnuplot &&) noexcept = delete;


        /**
         * @brief destructor
         */
        ~Gnuplot(){
            auto error = pclose(pipe);
            
            if(error == -1){
                std::cerr << "pclose error" << std::endl;
            }
        }
};

}

#endif //GNUPLOT_CPP_LIB
