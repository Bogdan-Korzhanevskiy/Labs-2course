#pragma once
#include "MainForm.h"
#include "DeleteConfirmationForm.h"



namespace BogdanDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Void ConfirmDeleting();

	/// <summary>
	/// Сводка для DeleteConfirmationForm
	/// </summary>
	public ref class DeleteConfirmationForm : public System::Windows::Forms::Form
	{
	public:
		//MainForm^ mainForm = nullptr;
		DeleteConfirmationForm(void)
		{
			InitializeComponent();
			//this->mainForm = MainForm::Instance;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DeleteConfirmationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  yesButton;
	protected:

	private: System::Windows::Forms::Button^  noButton;
	protected:

	private: System::Windows::Forms::Label^  mainLabel;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->yesButton = (gcnew System::Windows::Forms::Button());
			this->noButton = (gcnew System::Windows::Forms::Button());
			this->mainLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// yesButton
			// 
			this->yesButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->yesButton->Location = System::Drawing::Point(35, 104);
			this->yesButton->Name = L"yesButton";
			this->yesButton->Size = System::Drawing::Size(136, 39);
			this->yesButton->TabIndex = 0;
			this->yesButton->Text = L"Да";
			this->yesButton->UseVisualStyleBackColor = true;
			this->yesButton->Click += gcnew System::EventHandler(this, &DeleteConfirmationForm::yesButton_Click);
			// 
			// noButton
			// 
			this->noButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->noButton->Location = System::Drawing::Point(209, 104);
			this->noButton->Name = L"noButton";
			this->noButton->Size = System::Drawing::Size(136, 39);
			this->noButton->TabIndex = 1;
			this->noButton->Text = L"Нет";
			this->noButton->UseVisualStyleBackColor = true;
			this->noButton->Click += gcnew System::EventHandler(this, &DeleteConfirmationForm::noButton_Click);
			// 
			// mainLabel
			// 
			this->mainLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->mainLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->mainLabel->ForeColor = System::Drawing::Color::White;
			this->mainLabel->Location = System::Drawing::Point(16, 25);
			this->mainLabel->Name = L"mainLabel";
			this->mainLabel->Size = System::Drawing::Size(353, 57);
			this->mainLabel->TabIndex = 2;
			this->mainLabel->Text = L"Вы уверенны что хотите удалить данные записи\?";
			this->mainLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DeleteConfirmationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->ClientSize = System::Drawing::Size(381, 159);
			this->ControlBox = false;
			this->Controls->Add(this->mainLabel);
			this->Controls->Add(this->noButton);
			this->Controls->Add(this->yesButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DeleteConfirmationForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Подтвердите удаление записей";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void noButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void yesButton_Click(System::Object^  sender, System::EventArgs^  e) {

		ConfirmDeleting();
		this->Close();
	}
};
}
