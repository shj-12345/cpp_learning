cmake_minimum_required(VERSION 3.10.0)
project(cpp_test)

###################################################
##################### data structure ################
###################################################
add_executable(binary_tree data_structure/binary_tree.cpp)

###################################################
##################### multi thread ################
###################################################
find_package(Threads REQUIRED)
add_executable(lock multi_thread/lock.cpp)
target_link_libraries(lock Threads::Threads)

add_executable(recursive_lock multi_thread/recursive_lock.cpp)
target_link_libraries(recursive_lock Threads::Threads)

###################################################
##################### cpp base ################
###################################################
add_executable(class_test cpp_base_test/class_test.cpp)
add_executable(class_test2 cpp_base_test/class_test2.cpp)
add_executable(map_set_test cpp_base_test/map_set_test.cpp)
add_executable(static_test cpp_base_test/static_test.cpp)
add_executable(static_cast_test cpp_base_test/static_cast_test.cpp)
add_executable(weak_ptr_test cpp_base_test/weak_ptr_test.cpp)

###################################################
##################### design model ################
###################################################
add_executable(simple_factory design_model/simple_factory.cpp)


###################################################
##################### osqp test ################
###################################################
find_package(osqp REQUIRED) # Find OSQP library and headers
add_executable(osqp_test_1 osqp_test/test1.cpp)
target_link_libraries(osqp_test_1 PRIVATE osqp::osqp) # Link the OSQP shared library
#target_link_libraries(yourTarget PRIVATE osqp::osqpstatic) # Link the OSQP static library

###################################################
##################### eigen3 test ################
###################################################
find_package(Eigen3)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})
add_executable(eigen_test1 eigen3_test/eigen_test1.cpp)
# target_link_libraries(eigen_test1 PRIVATE Eigen3)

###################################################
##################### osqp-eigen3 test ################
###################################################
add_subdirectory (osqp-eigen_test)

#find_package用法
# find_package(PCL 1.2 REQUIRED)
# MESSAGE(STATUS "PCL_FOUND=${PCL_FOUND}")
# MESSAGE(STATUS "PCL_INCLUDE_DIRS=${PCL_INCLUDE_DIRS}")
# MESSAGE(STATUS "PCL_LIBRARIES=${PCL_LIBRARIES}")
# MESSAGE(STATUS "PCL_COMPONENTS=${PCL_COMPONENTS}")