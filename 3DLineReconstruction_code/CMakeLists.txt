cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(3DLineReconstruction_PROJ)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ELSD)

# try to find the NLopt headers
find_package(NLopt REQUIRED)

# try to find the eigen3 headers
find_package(Eigen3 REQUIRED)

find_package(CUDA REQUIRED)

find_path(TCLAP_INCLUDE_DIR tclap/CmdLine.h)

# find ELSRPPLib
find_path(ELSRPP_LIB_DIR PairMatch.h)
find_library(ELSRPP_LIB_DEBUG NAMES ELSRPP_Lib-debug)
find_library(ELSRPP_LIB_RELEASE NAMES ELSRPP_Lib)

# openMP
FIND_PACKAGE(OpenMP)
IF(OPENMP_FOUND)
    message("OPENMP_FOUND")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
ENDIF(OPENMP_FOUND)

# try to find OPENCV
find_package(OpenCV REQUIRED)

# try to find the boost headers
find_package(Boost REQUIRED COMPONENTS filesystem serialization)

if(NOT OpenCV_FOUND)
	message(FATAL_ERROR "Opencv not found.")
endif()

#3DLineReconstruction
file( GLOB 3DLineReconstruction_header_list ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file( GLOB 3DLineReconstruction_source_list ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp) 
file( GLOB 3DLineReconstruction_cuda_list ${CMAKE_CURRENT_SOURCE_DIR}/*.cu) 
cuda_add_executable(3DLineReconstruction
		${3DLineReconstruction_header_list}
		${3DLineReconstruction_cuda_list}
		${3DLineReconstruction_source_list})
option(APP_USE_OPENMP "3DLineReconstruction: use OpenMP" ON)
target_include_directories(3DLineReconstruction PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(3DLineReconstruction PUBLIC ${ELSRPP_LIB_DIR})
target_include_directories(3DLineReconstruction PUBLIC ${OpenCV_INCLUDE_DIRS}
		   ${TCLAP_INCLUDE_DIR}
		   ${EIGEN3_INCLUDE_DIRS}
		   ${NLOPT_INCLUDE_DIRS})
target_link_libraries(3DLineReconstruction ${OpenCV_LIBRARIES})
target_link_libraries(3DLineReconstruction ${CUDA_cusolver_LIBRARY})
target_link_libraries(3DLineReconstruction debug ${Boost_FILESYSTEM_LIBRARY_DEBUG})
target_link_libraries(3DLineReconstruction optimized ${Boost_FILESYSTEM_LIBRARY_RELEASE})
target_link_libraries(3DLineReconstruction debug ${Boost_SERIALIZATION_LIBRARY_DEBUG})
target_link_libraries(3DLineReconstruction optimized ${Boost_SERIALIZATION_LIBRARY_RELEASE})
target_link_libraries(3DLineReconstruction NLopt::nlopt)

target_link_libraries(3DLineReconstruction debug ${ELSRPP_LIB_DEBUG})
target_link_libraries(3DLineReconstruction optimized ${ELSRPP_LIB_RELEASE})

set_property(TARGET 3DLineReconstruction PROPERTY CXX_STANDARD 17)

