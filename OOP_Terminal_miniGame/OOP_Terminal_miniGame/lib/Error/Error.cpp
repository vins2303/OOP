#include "../../include/Error/Error.h"

void Error::showOpenError(string _class, string _function, string data) {
    cout << "OpenError:\nClass = " << _class << "\nFunction = " << _function << "\nFile = " << data << endl;
    system("pause");
}