#include "MainForm.h"

using namespace szablon;

[STAThreadAttribute]
int main(array < System::String^ > ^ args)
{
	// Enabling Windows XP visual effects before any changes are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
		//Create the main window and run it 
	Application::Run(gcnew MainForm());
	return 0;
}