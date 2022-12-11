#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

// @param data: pcm 格式编码，单通道， 16位量化
// @param data_size: data 长度

void convert_arr_pcm_to_ptr_float(const char* data, 
                                  int data_size, 
                                  float* float_data, 
                                  int* float_data_size)
{
    const int16_t* tmp = reinterpret_cast<const int16_t*>(data);
    *float_data_size = data_size / sizeof(int16_t);
    for (int i = 0; i < *float_data_size; i++){
        float_data[i] = static_cast<float>(tmp[i]);
    }
}

void convert_vec_pcm_to_ptr_float(const std::vector<char> data, 
                              float* float_data,
                              int* float_data_size)
{
    const int16_t* tmp = reinterpret_cast<const int16_t*>(data.data());
    *float_data_size = data.size() / sizeof(int16_t);
    for (int i = 0; i < *float_data_size; i++){
        float_data[i] = static_cast<float>(tmp[i]);
    }
}

void convert_vec_pcm_to_vec_float(const std::vector<char> data,
                                  std::vector<float>* vec_float,
                                  int* float_data_size)
{
    const int16_t* tmp = reinterpret_cast<const int16_t*>(data.data());
    *float_data_size = data.size() / sizeof(int16_t);
    for (int i = 0; i < *float_data_size; i++) {
        vec_float->emplace_back(static_cast<float>(tmp[i]));
    }
}

int main() {
    // TODO(case 1): 数组存储 pcm 数据，指针存储 float 数据
    const char array_data[4] = {0x01, 0x02, 0x03, 0x04};
    float* float_array_data = (float* )malloc(2 * sizeof(float));
    int float_array_size = 0;

    convert_arr_pcm_to_ptr_float(array_data, sizeof(array_data), 
                          float_array_data, &float_array_size);
    std::cout << "size: " << float_array_size << std::endl;
    for (int i = 0; i < float_array_size; i++) {
        std::cout << float_array_data[i] << " ";
    }
    std::cout << std::endl;   
    free(float_array_data);

    // TODO(case 2): vector 存储 pcm 数据，指针存储 float 数据
    std::vector<char> vec_data = {0x01, 0x02, 0x03, 0x04};
    float_array_data = (float*) malloc(2 * sizeof(float));
    convert_vec_pcm_to_ptr_float(vec_data, float_array_data, &float_array_size);
    std::cout << "size: " << float_array_size << std::endl;
    for (int i = 0; i < float_array_size; i++) {
        std::cout << float_array_data[i] << " ";
    }
    std::cout << std::endl;
    free(float_array_data);
    // TODO(case 3): vector 存储 pcm 数据，vector 存储 float 数据
    std::vector<float> vec_float;
    convert_vec_pcm_to_vec_float(vec_data, &vec_float, &float_array_size);
    std::cout << "size: " << vec_float.size() << std::endl;
    for (int i = 0; i < vec_float.size(); i++) {
        std::cout << vec_float[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}