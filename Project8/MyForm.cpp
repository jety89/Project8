#include "MyForm.h"
#include <string>
#include <iostream>
#include <array>
//#include "getparam.cpp"

//int param[6];


const char* ininames[] = { "COM", "Speed", "Aver", "T_min", "T_max", "T_1", "Time_1" };
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
//[STAThread]




int main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Arduino_Read::Form1 form;
	Application::Run(% form);



	return 0;


}