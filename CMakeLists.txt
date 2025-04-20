cmake_minimum_required(VERSION 3.29)
project(OculuZ)

set(CMAKE_CXX_STANDARD 17)

set(USE_SYSTEM_NVTX ON)

list(APPEND CMAKE_PREFIX_PATH
        "C:/libtorch"
        "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6"
)

# Явно указать путь к nvtx3
include_directories("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/include/nvtx3")

# Найти CUDA Toolkit
find_package(CUDAToolkit REQUIRED)

# Отключить поиск устаревшего NVTX
set(CAFFE2_USE_NVTX OFF)  # Добавить эту строку перед find_package(Torch)

find_package(Torch REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${TORCH_LIBRARIES})

file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${TORCH_DLLS}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)