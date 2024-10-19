#include "testDerivativeClass.h"

int testDerivativeClass::SetText() {
	//cast child to be like parent
	//int testResult = static_cast<int>(1.00f);
	//pretendMFCClass* test = static_cast<pretendMFCClass*>(this);

	//call parent version of method
	//int MFCResult = test->SetText();
	int MFCResult = pretendMFCClass::SetText();
	return MFCResult+1;
}