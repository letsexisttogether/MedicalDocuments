cmake_minimum_required(VERSION 3.16)

project(MedicalDocuments VERSION 0.1 LANGUAGES CXX)

# ============================================
#            CMake Configuration
# ============================================

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================
#            Qt Packages
# ============================================

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# ============================================
#            Project Sources
# ============================================

set(PROJECT_SOURCES
	main.cpp
)

# ============================================
#               Subdirectories
# ============================================

add_subdirectory(Authorization)
add_subdirectory(MainClient)

add_subdirectory(SQL)

# ============================================
#            Executable Configuration
# ============================================

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(MedicalDocuments
		MANUAL_FINALIZATION
		${PROJECT_SOURCES}
		appointmentwindow.h appointmentwindow.cpp appointmentwindow.ui
		${AUTHORIZATION_SOURCES}
		${SQL_SOURCES}
		${MAINCLIENT_SOURCES}
	)
else()
	if(ANDROID)
		add_library(MedicalDocuments SHARED
			${PROJECT_SOURCES}
		)
    else()
		add_executable(MedicalDocuments
			${PROJECT_SOURCES}
		)
    endif()
endif()

# ============================================
#            Target Linking
# ============================================

target_link_libraries(MedicalDocuments PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
	PRIVATE Qt${QT_VERSION_MAJOR}::Sql
)

# ============================================
#            macOS/iOS Configuration
# ============================================

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

# ============================================
#            Installation
# ============================================

include(GNUInstallDirs)
install(TARGETS MedicalDocuments
	BUNDLE DESTINATION .
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ============================================
#            Finalization
# ============================================

if(QT_VERSION_MAJOR EQUAL 6)
	qt_finalize_executable(MedicalDocuments)
endif()

# ============================================
#            Include Directories
# ============================================

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})