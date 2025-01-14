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

	PARENT_SCOPE
)