cmake_minimum_required(VERSION 3.13)
project(cv4p)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
    list( APPEND ThirdParty_LIBS ${OpenCV_LIBS} )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

# uncomment this for OpenMP support
#FIND_PACKAGE(OpenMP REQUIRED)
#if(OPENMP_FOUND)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
#endif()

# uncomment this for c++11 support
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# currently we don't have any forms-uncomment if you have qt-forms
#set(${PROJECT_NAME}_FORMS mainwindow.ui)

# also no moc from headers needed (uncomment if qt used)
#QT4_WRAP_CPP(${PROJECT_NAME}_HDR_MOC ${${PROJECT_NAME}_HDR})
# no forms
#QT4_WRAP_UI(${PROJECT_NAME}_FORMS_HDR ${${PROJECT_NAME}_FORMS})

# use this line if you have used Qt instead the next line
#add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR_MOC} ${${PROJECT_NAME}_FORMS_HDR} )
add_executable(cv4p main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})