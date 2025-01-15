# Current dir
set(CD ${CMAKE_CURRENT_SOURCE_DIR})

set(MAINCLIENT_SOURCES
	${CD}/Patient/Window/PatientWindow.hpp
	${CD}/Patient/Window/PatientWindow.cpp
	${CD}/Patient/Window/PatientWindow.ui

	${CD}/Doctor/Window/DoctorWindow.hpp
	${CD}/Doctor/Window/DoctorWindow.cpp
	${CD}/Doctor/Window/DoctorWindow.ui

	${CD}/Patient/Appointment/PatientAppointment.hpp
	${CD}/Patient/Appointment/PatientAppointment.cpp
	${CD}/Patient/Appointment/PatientAppointment.ui

	PARENT_SCOPE
)