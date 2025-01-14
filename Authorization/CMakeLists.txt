# Current dir
set(CD ${CMAKE_CURRENT_SOURCE_DIR})

set(AUTHORIZATION_SOURCES
	${CD}/Window/AuthorizationWindow.hpp
	${CD}/Window/AuthorizationWindow.cpp
	${CD}/Window/AuthorizationWindow.ui

	${CD}/CustomField/CustomField.hpp
	${CD}/CustomField/CustomField.cpp
	${CD}/CustomField/CustomField.ui

	${CD}/FieldCheck/FieldChecker.hpp
	${CD}/FieldCheck/FieldChecker.cpp
	${CD}/FieldCheck/FieldCondition.hpp
	${CD}/FieldCheck/FieldCondition.cpp

	${CD}/FieldCheck/DefaultCheckers/DefaultPasswordChecker.hpp
	${CD}/FieldCheck/DefaultCheckers/DefaultPasswordChecker.cpp
	${CD}/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp
	${CD}/FieldCheck/DefaultCheckers/DefaultEmailChecker.cpp

	${CD}/Pages/Login/Login.hpp
	${CD}/Pages/Login/Login.cpp
	${CD}/Pages/Login/Login.ui

	${CD}/Pages/SignUp/SignUp.hpp
	${CD}/Pages/SignUp/SignUp.cpp
	${CD}/Pages/SignUp/SignUp.ui

	${CD}/PasswordEncryption/PasswordEncryptor.hpp
	${CD}/PasswordEncryption/PasswordEncryptor.cpp

	PARENT_SCOPE
)
