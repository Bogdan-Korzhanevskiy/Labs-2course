#include "DeleteConfirmationForm.h"
#include "MainForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace BogdanDataBase;

namespace BogdanDataBase
{
	Void ConfirmDeleting()
	{
		MainForm::Instance->RemoveSelectedRows();
	}
}
