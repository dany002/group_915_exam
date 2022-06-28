cmake_minimum_required(VERSION 3.21)
project(group_915)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.3.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(group_915 main.cpp src/Domain/Teacher.cpp src/Domain/Teacher.h src/Domain/Student.cpp src/Domain/Student.h src/Repository/TeacherRepo.cpp src/Repository/TeacherRepo.h src/Repository/StudentRepo.cpp src/Repository/StudentRepo.h src/Controller/Controller.cpp src/Controller/Controller.h src/Ui/GUIManager.cpp src/Ui/GUIManager.h src/Domain/Observer.h src/Domain/Subject.cpp src/Domain/Subject.h src/Ui/teacherwindow.cpp src/Ui/teacherwindow.h src/Ui/teacherwindow.ui src/Ui/editwindow.cpp src/Ui/editwindow.h src/Ui/editwindow.ui)
target_link_libraries(group_915
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
