# Current dir
set(CD ${CMAKE_CURRENT_SOURCE_DIR})

set(SQL_SOURCES
	${CD}/Manager/SQLManager.hpp
	${CD}/Manager/SQLManager.cpp

	${CD}/Tables/TableRecord.hpp
	${CD}/Tables/TableRecord.cpp

	${CD}/Tables/DefaultRecord.hpp
	${CD}/Tables/DefaultRecord.cpp

	${CD}/Tables/People/PeopleRecord.hpp
	${CD}/Tables/People/PeopleRecord.cpp

	${CD}/Tables/Patients/PatientsRecord.hpp
	${CD}/Tables/Patients/PatientsRecord.cpp

	${CD}/Tables/Passwords/PasswordsRecord.hpp
	${CD}/Tables/Passwords/PasswordsRecord.cpp

	${CD}/Tables/Doctors/DoctorsRecord.hpp
	${CD}/Tables/Doctors/DoctorsRecord.cpp

	${CD}/Tables/Specializations/SpecializationsRecord.hpp
	${CD}/Tables/Specializations/SpecializationsRecord.cpp

	${CD}/Tables/Appointments/AppointmentsRecord.hpp
	${CD}/Tables/Appointments/AppointmentsRecord.cpp

	${CD}/Tables/AppPharmConn/AppPharmConnRecord.hpp
	${CD}/Tables/AppPharmConn/AppPharmConnRecord.cpp

	${CD}/Tables/Pharmacies/PharmaciesRecord.hpp
	${CD}/Tables/Pharmacies/PharmaciesRecord.cpp

	${CD}/Loaders/MultyRecordLoader.hpp
	${CD}/Loaders/MultyRecordLoader.cpp

	${CD}/Loaders/Appointments/AppointmentsMultyLoader.hpp
	${CD}/Loaders/Appointments/AppointmentsMultyLoader.cpp

	${CD}/Loaders/AppPharmConn/AppPharmConnMultyLoader.hpp
	${CD}/Loaders/AppPharmConn/AppPharmConnMultyLoader.cpp

	${CD}/Loaders/Patients/PatientsMultyLoader.hpp
	${CD}/Loaders/Patients/PatientsMultyLoader.cpp

	PARENT_SCOPE
)