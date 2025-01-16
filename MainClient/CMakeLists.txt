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

	${CD}/General/OpenAppointmentFilter/OpenAppointmentFilter.hpp
	${CD}/General/OpenAppointmentFilter/OpenAppointmentFilter.cpp

	${CD}/General/AppointmentInfo/AppointmentInfo.hpp
	${CD}/General/AppointmentInfo/AppointmentInfo.cpp
	${CD}/General/PharmacyInfo/PharmacyInfo.hpp
	${CD}/General/PharmacyInfo/PharmacyInfo.cpp

	${CD}/General/AppointmentFullWidget/AppointmentFullWidget.hpp
	${CD}/General/AppointmentFullWidget/AppointmentFullWidget.cpp
	${CD}/General/AppointmentFullWidget/AppointmentFullWidget.ui


	${CD}/General/PharmacyViewWidget/PharmacyViewWidget.hpp
	${CD}/General/PharmacyViewWidget/PharmacyViewWidget.cpp
	${CD}/General/PharmacyViewWidget/PharmacyViewWidget.ui

	PARENT_SCOPE
)