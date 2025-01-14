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

	${CD}/Tables/Specialzations/SpecializationsRecord.hpp
	${CD}/Tables/Specializations/SpecializationsRecord.cpp

	PARENT_SCOPE
)