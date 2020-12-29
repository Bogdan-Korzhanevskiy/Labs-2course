#include "MainForm.h"
#include "DeleteConfirmationForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace BogdanDataBase
{
	Void ShowConfirmation()
	{
		DeleteConfirmationForm^ confirmationForm = gcnew DeleteConfirmationForm();
		confirmationForm->ShowDialog(MainForm::Instance);
	}
}

int main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BogdanDataBase::MainForm mainForm;
	Application::Run(%mainForm);

	return 0;
}

