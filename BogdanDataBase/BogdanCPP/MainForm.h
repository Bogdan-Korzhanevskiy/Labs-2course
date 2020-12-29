#pragma once
#include <iostream>
#include <limits>
#include "InfoForm.h"
#include "DeleteConfirmationForm.h"



namespace BogdanDataBase
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace OleDb;

	// ���������� ������� ������ ���� ������������� ��������
	Void ShowConfirmation();

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: static MainForm^ Instance;
		// ���������� ��������������� ����
	protected: InfoForm^ infoForm;

		// ����� ��� ������ ������ ��������� �����������
	protected: System::Drawing::Color connectedColor = System::Drawing::Color::Green;
	protected: System::Drawing::Color connectingColor = System::Drawing::Color::Yellow;
	protected: System::Drawing::Color disconnectedColor = System::Drawing::Color::Red;

	protected:
		// �������� ������ ����������� � ��
		String^ connectInfo = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
		// ��� ����� ��
		String^ dbFileName = "Bogdan DB.mdb";
		// ��� ������� � ��
		String^ dbTableName = "Employee";

		// ����������� ������ ����������� ����� � ������� �������� � �������
		array<String^>^ columnNames;

		// ������ ����� ������� �������������� �����������
		OleDbConnection^ connection;



		// UI ��������! ---------------------------------------------
	private: System::Windows::Forms::Label^  titleLabel;
	private: System::Windows::Forms::MenuStrip^  mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGrid;



	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::Label^  testLabel;
	private: System::Windows::Forms::Button^  disconnectFromDB;
	private: System::Windows::Forms::Label^  connectionStatusLabel;
	private: System::Windows::Forms::Label^  connectionStatusValue;
	private: System::Windows::Forms::Button^  updateButton;
	private: System::Windows::Forms::Button^  deleteSelectedButton;
	private: System::Windows::Forms::Button^  addNewRecordButton;
	private: System::Windows::Forms::CheckBox^  autoUpdateCheckBox;
	private: System::Windows::Forms::TextBox^  newEmployeeTextBox;

	private: System::Windows::Forms::Label^  newEmployeeLabel;

	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem1;






			 // ����������� ------------------------------------------------
	public:
		MainForm(void)
		{
			InitializeComponent();

			MainForm::Instance = this;
			this->dataGrid->ReadOnly = false;
			this->dataGrid->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MainForm::OnCellChanged);
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (this->connection != nullptr)
			{
				this->connection->Close();
			}
			if (components)
			{
				delete components;
			}
		}

	protected:





	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->mainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->testLabel = (gcnew System::Windows::Forms::Label());
			this->disconnectFromDB = (gcnew System::Windows::Forms::Button());
			this->connectionStatusLabel = (gcnew System::Windows::Forms::Label());
			this->connectionStatusValue = (gcnew System::Windows::Forms::Label());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->deleteSelectedButton = (gcnew System::Windows::Forms::Button());
			this->addNewRecordButton = (gcnew System::Windows::Forms::Button());
			this->autoUpdateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->newEmployeeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->newEmployeeLabel = (gcnew System::Windows::Forms::Label());
			this->mainMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23, System::Drawing::FontStyle::Bold));
			this->titleLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->titleLabel->Location = System::Drawing::Point(355, 36);
			this->titleLabel->Margin = System::Windows::Forms::Padding(10);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(410, 35);
			this->titleLabel->TabIndex = 10;
			this->titleLabel->Text = L"���� ������ �����������";
			// 
			// mainMenu
			// 
			this->mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����������ToolStripMenuItem });
			this->mainMenu->Location = System::Drawing::Point(0, 0);
			this->mainMenu->Name = L"mainMenu";
			this->mainMenu->Size = System::Drawing::Size(1133, 24);
			this->mainMenu->TabIndex = 11;
			this->mainMenu->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�����ToolStripMenuItem,
					this->�����ToolStripMenuItem1
			});
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(84, 20);
			this->����������ToolStripMenuItem->Text = L"���������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->�����ToolStripMenuItem->Text = L"� ���������";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem1
			// 
			this->�����ToolStripMenuItem1->Name = L"�����ToolStripMenuItem1";
			this->�����ToolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->�����ToolStripMenuItem1->Text = L"�����";
			this->�����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::�����ToolStripMenuItem1_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AllowUserToAddRows = false;
			this->dataGrid->AllowUserToDeleteRows = false;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGrid->Location = System::Drawing::Point(220, 84);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->ReadOnly = true;
			this->dataGrid->RowHeadersVisible = false;
			this->dataGrid->Size = System::Drawing::Size(901, 506);
			this->dataGrid->TabIndex = 12;
			// 
			// connectButton
			// 
			this->connectButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->connectButton->Location = System::Drawing::Point(15, 84);
			this->connectButton->Margin = System::Windows::Forms::Padding(10);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(192, 52);
			this->connectButton->TabIndex = 20;
			this->connectButton->Text = L"������������ � ��";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &MainForm::connectButton_Click);
			// 
			// testLabel
			// 
			this->testLabel->AutoSize = true;
			this->testLabel->Enabled = false;
			this->testLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->testLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->testLabel->Location = System::Drawing::Point(6, 594);
			this->testLabel->Name = L"testLabel";
			this->testLabel->Size = System::Drawing::Size(76, 15);
			this->testLabel->TabIndex = 21;
			this->testLabel->Text = L"*Debug text*";
			// 
			// disconnectFromDB
			// 
			this->disconnectFromDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->disconnectFromDB->Location = System::Drawing::Point(15, 156);
			this->disconnectFromDB->Margin = System::Windows::Forms::Padding(10);
			this->disconnectFromDB->Name = L"disconnectFromDB";
			this->disconnectFromDB->Size = System::Drawing::Size(192, 52);
			this->disconnectFromDB->TabIndex = 22;
			this->disconnectFromDB->Text = L"����������� �� ��";
			this->disconnectFromDB->UseVisualStyleBackColor = true;
			this->disconnectFromDB->Click += gcnew System::EventHandler(this, &MainForm::disconnectFromDB_Click);
			// 
			// connectionStatusLabel
			// 
			this->connectionStatusLabel->AutoSize = true;
			this->connectionStatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->connectionStatusLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->connectionStatusLabel->Location = System::Drawing::Point(6, 609);
			this->connectionStatusLabel->Name = L"connectionStatusLabel";
			this->connectionStatusLabel->Size = System::Drawing::Size(186, 18);
			this->connectionStatusLabel->TabIndex = 23;
			this->connectionStatusLabel->Text = L"��������� �����������:";
			// 
			// connectionStatusValue
			// 
			this->connectionStatusValue->AutoSize = true;
			this->connectionStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->connectionStatusValue->ForeColor = System::Drawing::Color::Red;
			this->connectionStatusValue->Location = System::Drawing::Point(189, 609);
			this->connectionStatusValue->Name = L"connectionStatusValue";
			this->connectionStatusValue->Size = System::Drawing::Size(88, 18);
			this->connectionStatusValue->TabIndex = 24;
			this->connectionStatusValue->Text = L"���������";
			// 
			// updateButton
			// 
			this->updateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17));
			this->updateButton->Location = System::Drawing::Point(15, 228);
			this->updateButton->Margin = System::Windows::Forms::Padding(10);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(192, 52);
			this->updateButton->TabIndex = 25;
			this->updateButton->Text = L"��������";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &MainForm::updateButton_Click);
			// 
			// deleteSelectedButton
			// 
			this->deleteSelectedButton->BackColor = System::Drawing::Color::Red;
			this->deleteSelectedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteSelectedButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->deleteSelectedButton->ForeColor = System::Drawing::SystemColors::Control;
			this->deleteSelectedButton->Location = System::Drawing::Point(19, 356);
			this->deleteSelectedButton->Margin = System::Windows::Forms::Padding(10);
			this->deleteSelectedButton->Name = L"deleteSelectedButton";
			this->deleteSelectedButton->Size = System::Drawing::Size(188, 52);
			this->deleteSelectedButton->TabIndex = 26;
			this->deleteSelectedButton->Text = L"������� ���������� �����������";
			this->deleteSelectedButton->UseVisualStyleBackColor = false;
			this->deleteSelectedButton->Click += gcnew System::EventHandler(this, &MainForm::deleteSelectedButton_Click);
			// 
			// addNewRecordButton
			// 
			this->addNewRecordButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->addNewRecordButton->Location = System::Drawing::Point(15, 538);
			this->addNewRecordButton->Margin = System::Windows::Forms::Padding(10);
			this->addNewRecordButton->Name = L"addNewRecordButton";
			this->addNewRecordButton->Size = System::Drawing::Size(192, 52);
			this->addNewRecordButton->TabIndex = 27;
			this->addNewRecordButton->Text = L"�������� ����������";
			this->addNewRecordButton->UseVisualStyleBackColor = true;
			this->addNewRecordButton->Click += gcnew System::EventHandler(this, &MainForm::addNewRecordButton_Click);
			// 
			// autoUpdateCheckBox
			// 
			this->autoUpdateCheckBox->Checked = true;
			this->autoUpdateCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoUpdateCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->autoUpdateCheckBox->ForeColor = System::Drawing::SystemColors::Control;
			this->autoUpdateCheckBox->Location = System::Drawing::Point(15, 293);
			this->autoUpdateCheckBox->Name = L"autoUpdateCheckBox";
			this->autoUpdateCheckBox->Size = System::Drawing::Size(192, 50);
			this->autoUpdateCheckBox->TabIndex = 28;
			this->autoUpdateCheckBox->Text = L"���� ���������� ����� ��������";
			this->autoUpdateCheckBox->UseVisualStyleBackColor = true;
			// 
			// newEmployeeTextBox
			// 
			this->newEmployeeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->newEmployeeTextBox->Location = System::Drawing::Point(15, 499);
			this->newEmployeeTextBox->MaxLength = 128;
			this->newEmployeeTextBox->Name = L"newEmployeeTextBox";
			this->newEmployeeTextBox->Size = System::Drawing::Size(192, 26);
			this->newEmployeeTextBox->TabIndex = 29;
			// 
			// newEmployeeLabel
			// 
			this->newEmployeeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->newEmployeeLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->newEmployeeLabel->Location = System::Drawing::Point(15, 473);
			this->newEmployeeLabel->Margin = System::Windows::Forms::Padding(10);
			this->newEmployeeLabel->Name = L"newEmployeeLabel";
			this->newEmployeeLabel->Size = System::Drawing::Size(192, 22);
			this->newEmployeeLabel->TabIndex = 30;
			this->newEmployeeLabel->Text = L"��� ������ ����������:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->ClientSize = System::Drawing::Size(1133, 632);
			this->Controls->Add(this->newEmployeeLabel);
			this->Controls->Add(this->newEmployeeTextBox);
			this->Controls->Add(this->autoUpdateCheckBox);
			this->Controls->Add(this->addNewRecordButton);
			this->Controls->Add(this->deleteSelectedButton);
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->connectionStatusValue);
			this->Controls->Add(this->connectionStatusLabel);
			this->Controls->Add(this->disconnectFromDB);
			this->Controls->Add(this->testLabel);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->mainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->mainMenu;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->mainMenu->ResumeLayout(false);
			this->mainMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion





		// ����������� UI -----------------
	private: System::Void �����ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->infoForm = gcnew InfoForm();
		this->infoForm->ShowDialog();
	}
	private: System::Void updateButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UpdateDataFromDB();
	}
	private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ConnectToDB();
		if (autoUpdateCheckBox->Checked)
		{
			UpdateDataFromDB();
		}
	}
	private: System::Void disconnectFromDB_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DisconnectFromDB();
	}
	private: System::Void addNewRecordButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// ���� �������� ��� - �� ������ ������ - ���������� ������ ������������ � ��
		if (this->newEmployeeTextBox->Text != "")
		{
			AddNewUserToDB();
		}
	}
	private: System::Void deleteSelectedButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->dataGrid->SelectedCells->Count > 0)
		{
			ShowConfirmation();
		}
	}

		//----------------------------------------






			 // ������� ����������� � ��
	public: System::Boolean ConnectToDB()
	{
		bool result = false;
		try
		{
			this->connection = gcnew OleDbConnection(connectInfo + dbFileName);

			connection->StateChange += gcnew System::Data::StateChangeEventHandler(this, &MainForm::OnConnectionStateChanged);
			connection->Open();
			if (connection->State == System::Data::ConnectionState::Open)
			{
				result = true;
				UpdateTableNamesFromDB();
			}
		}
		catch (Exception^ e)
		{
			connectionStatusValue->ForeColor = disconnectedColor;
			connectionStatusValue->Text = "�� ������� ������������ � ��! " + e->Message;
		}

		return result;
	}

			// ������� ������������ �� ��
	public: System::Boolean DisconnectFromDB()
	{
		bool result = false;
		try
		{
			if (this->connection != nullptr)
			{
				this->connection->Close();
				if (connection->State == System::Data::ConnectionState::Closed ||
					connection->State == System::Data::ConnectionState::Broken)
				{
					result = true;
				}
			}
		}
		catch (Exception^ e)
		{
			connectionStatusValue->ForeColor = disconnectedColor;
			connectionStatusValue->Text = "�� ������� ����������� �� ��! " + e->Message;
		}

		return result;
	}

			// ���������� ������ ������������ � ��
	public: Void AddNewUserToDB()
	{
		if (this->connection != nullptr)
		{
			if (this->connection->State == ConnectionState::Open)
			{
				try
				{
					// ��������� ������ ������ ������������ �� TextBox
					String^ txt = this->newEmployeeTextBox->Text;
					// �������� ������� �� ������� ����� ������. � ����� ������ � ������� � �������� 1 (���) ����� ������ ����� �� TextBox
					String^ query = "INSERT INTO " + dbTableName + "(" + columnNames[1] + ") VALUES ('" + txt + "')";
					OleDbCommand^ command = gcnew OleDbCommand(query, this->connection);
					// ���������� �������. ��������� ���������� ���������� ����� � �� ����� ��������.
					int affectedRows = command->ExecuteNonQuery();
					if (affectedRows > 0)
					{
						// ���� ����� ������ 0 - ���������� �� ���� � ������ ��������� � ��������� ����� ������ �� ������.
						connectionStatusValue->ForeColor = connectedColor;
						connectionStatusValue->Text = "������� ��������������� �����: " + affectedRows;
						// ���� ����� ������� �������������� - ���������� ������� �� ��
						if (this->autoUpdateCheckBox->Checked)
						{
							UpdateDataFromDB();
						}
					}
				}
				catch (Exception^ e)
				{
					connectionStatusValue->ForeColor = disconnectedColor;
					connectionStatusValue->Text = "������ ��� �������� ��: " + e->Message;
				}
			}
		}
	}

			// ��������� ���������� �������� � �� ���
	public: System::Void UpdateTableNamesFromDB()
	{
		if (this->connection != nullptr)
		{
			if (this->connection->State == System::Data::ConnectionState::Open)
			{
				OleDbCommand^ command = gcnew OleDbCommand("SELECT TOP 1 * FROM [" + dbTableName + "]", this->connection);
				OleDbDataReader^ reader = command->ExecuteReader();
				DataTable^ metaData = reader->GetSchemaTable();

				this->columnNames = gcnew array<String^>(metaData->Rows->Count);

				for (int i = 0; i < metaData->Rows->Count; i++)
				{
					this->columnNames[i] = metaData->Rows[i]->ItemArray[0]->ToString();
				}
				
				UpdateDataGridTabels();
			}
		}
	}

			// ������ ����������� �� � ���������� �������
	public: Void UpdateDataFromDB()
	{
		if (this->connection != nullptr)
		{
			if (this->connection->State == ConnectionState::Open)
			{
				try
				{
					// �������� ������� �� ������� ����� ����������� ������� � ���������� �������.
					// ��������� ���������� � ���������� reader
					OleDbCommand^ command = gcnew OleDbCommand(("SELECT * FROM " + dbTableName), this->connection);
					OleDbDataReader^ reader = command->ExecuteReader();

					// ������� �������
					this->dataGrid->Rows->Clear();

					// �������� ��������� ���������� ��� �������� ������� �������
					DataGridViewRow^ row = gcnew DataGridViewRow();
					// ��������� ���������� �������� � �������
					int columnCount = columnNames->Length;
					// ������� �������
					int columnCounter = 0;

					// ��������� ����������� ������ �� �� �� ������ � ���������� �� � �������
					while (reader->Read())
					{
						// ���������� ���� ����� �� ��
						for (int i = 0; i < reader->FieldCount; i++)
						{
							// �������� ������ �������. ������� �� �������� �� ������ �� ��. ��������� ���������� �� ����������� ������
							DataGridViewTextBoxCell^ cell = gcnew DataGridViewTextBoxCell();
							cell->Value = reader[i]->ToString();
							row->Cells->Add(cell);
							cell->ReadOnly = false;

							// ���������� �������� �������. ���� ������� ������� ����� ���������� �������� - ������ �����������.
							columnCounter++;
							if (columnCounter >= columnCount)
							{
								// ���������� ������� ������ � �������. �������� ����� ������ � ��������� � �� ��������� ����������.
								// ��������� �������� ��������.
								this->dataGrid->Rows->Add(row);
								row = gcnew DataGridViewRow();
								columnCounter = 0;
							}
						}
					}
				}
				catch (Exception^ e)
				{
					connectionStatusValue->ForeColor = disconnectedColor;
					connectionStatusValue->Text = "������ ��� �������� ��: " + e->Message;
				}
			}
		}
	}

			// ���������� ���������� �������� � �������
	public: void UpdateDataGridTabels()
	{
		if (this->columnNames != nullptr)
		{
			this->dataGrid->Rows->Clear();
			this->dataGrid->Columns->Clear();

			for (int i = 0; i < this->columnNames->Length; i++)
			{
				DataGridViewColumn^ column = gcnew DataGridViewColumn();
				column->ReadOnly = false;
				column->Name = this->columnNames[i];
				this->dataGrid->Columns->Add(column);
			}
		}
	}

			// �������� ��������� ����� �� ��
	public: Void RemoveSelectedRows()
	{
		List<int>^ allRowsIndeces = gcnew List<int>();
		List<String^>^ indeces = gcnew List<String^>();

		for (int i = 0; i < dataGrid->SelectedCells->Count; i++)
		{
			int rowIndex = dataGrid->SelectedCells[i]->RowIndex;
			if (allRowsIndeces->Contains(rowIndex) == false)
			{
				allRowsIndeces->Add(rowIndex);
				String^ curIndex = dataGrid->Rows[rowIndex]->Cells[0]->Value->ToString();
				indeces->Add(curIndex);
			}
		}

		if (indeces->Count > 0)
		{
			String^ indecesStr = "";
			
			for (int i = 0; i < indeces->Count; i++)
			{
				indecesStr += " " + columnNames[0] + " = " + indeces[i] + "";
				if (i < indeces->Count - 1)
				{
					indecesStr += " OR ";
				}
			}

			String^ query = "DELETE FROM " + dbTableName + " WHERE " + indecesStr + " ;";
			try
			{
				OleDbCommand^ command = gcnew OleDbCommand(query, this->connection);
				int affectedRows = command->ExecuteNonQuery();
				if (affectedRows > 0)
				{
					connectionStatusValue->ForeColor = connectedColor;
					connectionStatusValue->Text = "������� ����� �� ��: " + affectedRows;
					if (this->autoUpdateCheckBox->Checked)
					{
						UpdateDataFromDB();
					}
				}
			}
			catch (Exception^ e)
			{
				connectionStatusValue->ForeColor = disconnectedColor;
				connectionStatusValue->Text = "������ ��� �������� ��: " + e->Message;
			}
		}
	}

			// ������� (����������) ��������� ������ � �������
	public: Void OnCellChanged(Object^ sender, DataGridViewCellEventArgs^ e)
	{
		try
		{
			String^ index;

			OleDbCommand^ getIndexCommand = gcnew OleDbCommand("SELECT TOP " + (e->RowIndex + 1) + " " + columnNames[0] + " FROM " + dbTableName, this->connection);
			OleDbDataReader^ indexReader = getIndexCommand->ExecuteReader();
			while (indexReader->Read())
			{
				if (indexReader->FieldCount > 0)
				{
					index = indexReader[0]->ToString();
				}
				else
				{
					connectionStatusValue->ForeColor = disconnectedColor;
					connectionStatusValue->Text = "�� ������� �������� ������ � ��. ������������� ������ ��� ����������� � ��";
					return;
				}
			}


			String^ query = "UPDATE " + dbTableName + " SET [" + columnNames[e->ColumnIndex] + "] = \"" +
				this->dataGrid->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value +
				"\" WHERE [" + columnNames[0] + "] = " + index + ";";

			OleDbCommand^ command = gcnew OleDbCommand(query, this->connection);
			int affectedRows = command->ExecuteNonQuery();
			if (affectedRows > 0)
			{
				connectionStatusValue->ForeColor = connectedColor;
				connectionStatusValue->Text = "������� ��������������� �����: " + affectedRows;
			}
		}
		catch (Exception^ e)
		{
			connectionStatusValue->ForeColor = disconnectedColor;
			connectionStatusValue->Text = "������ ��� �������� ��: " + e->Message;
		}
	}

			// ������ ������� (����������) ���������� ��� ��������� ��������� ����������� � ��
	public: System::Void OnConnectionStateChanged(System::Object^ sender, System::Data::StateChangeEventArgs^ e)
	{
		switch (e->CurrentState)
		{
		case System::Data::ConnectionState::Open:
			connectionStatusValue->ForeColor = connectedColor;
			connectionStatusValue->Text = "����������.";
			break;
		case System::Data::ConnectionState::Connecting:
			connectionStatusValue->ForeColor = connectingColor;
			connectionStatusValue->Text = "�����������...";
			break;
		case System::Data::ConnectionState::Closed:
			connectionStatusValue->ForeColor = disconnectedColor;
			connectionStatusValue->Text = "���������.";
			break;
		default:
			connectionStatusValue->ForeColor = disconnectedColor;
			connectionStatusValue->Text = "���������.";
			break;
		}
	}
	};
}
