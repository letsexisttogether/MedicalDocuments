cmake_minimum_required(VERSION 3.16)

project(MedicalDocuments VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

set(AUTHORIZATION_SOURCES
	Authorization/Window/authorizationwindow.h
	Authorization/Window/authorizationwindow.cpp
	Authorization/Window/authorizationwindow.ui
	Authorization/FieldCheck/FieldChecker.hpp Authorization/FieldCheck/FieldChecker.cpp
	Authorization/FieldCheck/FieldCondition.hpp Authorization/FieldCheck/FieldCondition.cpp
)

set(SQL_SOURCES
	SQL/Manager/SQLManager.hpp SQL/Manager/SQLManager.cpp
	SQL/TableRecords/TableRecord.hpp SQL/TableRecords/TableRecord.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MedicalDocuments
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        appointmentwindow.h appointmentwindow.cpp appointmentwindow.ui  
        registerwindow.h registerwindow.cpp registerwindow.ui
        doctorclientwindow.h doctorclientwindow.cpp doctorclientwindow.ui
        redactwindow.h redactwindow.cpp redactwindow.ui
		${AUTHORIZATION_SOURCES}
		${SQL_SOURCES}
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MedicalDocuments APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MedicalDocuments SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MedicalDocuments
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MedicalDocuments PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
	PRIVATE Qt${QT_VERSION_MAJOR}::Sql
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MedicalDocuments)
endif()
set_target_properties(MedicalDocuments PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MedicalDocuments
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MedicalDocuments)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})