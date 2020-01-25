#ifndef SEMI_CPP_MNIST_HPP
#define SEMI_CPP_MNIST_HPP

#include<cstdint>
#include<cstring>

#include<vector>
#include<algorithm>
#include<utility>
#include<fstream>
#include<iostream>

namespace semi_cpp::mnist{

using Data = std::pair<std::vector<uint8_t>, uint8_t>;
using Set = std::vector<Data>;

Set load_mnist(const char* image, const char* label){
    std::ifstream image_file(image, std::ios::binary | std::ios::in);
    std::ifstream label_file(label, std::ios::binary | std::ios::in);

    if(image_file.is_open() && label_file.is_open()){

        char buf[4];

        image_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t image_header;
        std::memcpy(&image_header, buf, 4);

        label_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t label_header;
        std::memcpy(&label_header, buf, 4);

        if(image_header != 2051 && label_header != 2049){
            std::cerr << "load_mnist: file header error" << std::endl;
            std::exit(1);
        }

        image_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t image_data_size;
        std::memcpy(&image_data_size, buf, 4);

        label_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t label_data_size;
        std::memcpy(&label_data_size, buf, 4);

        if(image_data_size != label_data_size){
            std::cerr << "load_mnist: file data size two file different" << std::endl;
            std::exit(1);
        }

        image_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t image_data_height;
        std::memcpy(&image_data_height, buf, 4);

        image_file.read(buf, 4);
        std::reverse(std::begin(buf), std::end(buf));
        uint32_t image_data_width;
        std::memcpy(&image_data_width, buf, 4);

        Set retval(image_data_size);

        for(auto&& elem : retval){
            std::vector<uint8_t> image_data;
            uint8_t label_data;

            for(size_t i = 0; i < image_data_height; i++){
                for(size_t j = 0; j < image_data_width; j++){
                    char tmp;
                    image_file.read(&tmp, 1);
                    image_data.emplace_back(tmp);
                }
            }

            char tmp;
            label_file.read(&tmp, 1);
            std::memcpy(&label_data, &tmp, 1);

            elem = Data{image_data, label_data};
        }

        return retval;

    }else{
        std::cerr << "load_mnist: file open error" << std::endl;
        std::exit(1);
    }
}

}

#endif // SEMI_CPP_MNIST_HPP
