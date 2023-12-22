#pragma once
#include <chrono>
#include <thread>

namespace BinSearchlab9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ text_main;
	private: System::Windows::Forms::Label^ history_main;
	private: System::Windows::Forms::Button^ btn_run;
	private: System::Windows::Forms::RadioButton^ great_btn;
	private: System::Windows::Forms::RadioButton^ less_btn;
	private: System::Windows::Forms::RadioButton^ equ_btn;



	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->text_main = (gcnew System::Windows::Forms::Label());
			this->history_main = (gcnew System::Windows::Forms::Label());
			this->btn_run = (gcnew System::Windows::Forms::Button());
			this->great_btn = (gcnew System::Windows::Forms::RadioButton());
			this->less_btn = (gcnew System::Windows::Forms::RadioButton());
			this->equ_btn = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// text_main
			// 
			this->text_main->AutoSize = true;
			this->text_main->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_main->Location = System::Drawing::Point(280, 21);
			this->text_main->Name = L"text_main";
			this->text_main->Size = System::Drawing::Size(398, 25);
			this->text_main->TabIndex = 1;
			this->text_main->Text = L"Загадай число от 1 до 100 и я его угадаю!";
			// 
			// history_main
			// 
			this->history_main->AutoSize = true;
			this->history_main->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->history_main->Location = System::Drawing::Point(12, 54);
			this->history_main->Name = L"history_main";
			this->history_main->Size = System::Drawing::Size(177, 25);
			this->history_main->TabIndex = 2;
			this->history_main->Text = L"История диалога:";
			// 
			// btn_run
			// 
			this->btn_run->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_run->Location = System::Drawing::Point(741, 54);
			this->btn_run->Name = L"btn_run";
			this->btn_run->Size = System::Drawing::Size(247, 57);
			this->btn_run->TabIndex = 3;
			this->btn_run->Text = L"Начать угадывание";
			this->btn_run->UseVisualStyleBackColor = true;
			this->btn_run->Click += gcnew System::EventHandler(this, &MyForm::btn_run_Click);
			// 
			// great_btn
			// 
			this->great_btn->AutoSize = true;
			this->great_btn->Location = System::Drawing::Point(456, 75);
			this->great_btn->Name = L"great_btn";
			this->great_btn->Size = System::Drawing::Size(77, 20);
			this->great_btn->TabIndex = 4;
			this->great_btn->TabStop = true;
			this->great_btn->Text = L"Больше";
			this->great_btn->UseVisualStyleBackColor = true;
			this->great_btn->Click += gcnew System::EventHandler(this, &MyForm::great_btn_Click);
			// 
			// less_btn
			// 
			this->less_btn->AutoSize = true;
			this->less_btn->Location = System::Drawing::Point(456, 114);
			this->less_btn->Name = L"less_btn";
			this->less_btn->Size = System::Drawing::Size(79, 20);
			this->less_btn->TabIndex = 5;
			this->less_btn->TabStop = true;
			this->less_btn->Text = L"Меньше";
			this->less_btn->UseVisualStyleBackColor = true;
			this->less_btn->Click += gcnew System::EventHandler(this, &MyForm::less_btn_Click);
			// 
			// equ_btn
			// 
			this->equ_btn->AutoSize = true;
			this->equ_btn->Location = System::Drawing::Point(456, 152);
			this->equ_btn->Name = L"equ_btn";
			this->equ_btn->Size = System::Drawing::Size(69, 20);
			this->equ_btn->TabIndex = 6;
			this->equ_btn->TabStop = true;
			this->equ_btn->Text = L"Равно";
			this->equ_btn->UseVisualStyleBackColor = true;
			this->equ_btn->Click += gcnew System::EventHandler(this, &MyForm::equ_btn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 500);
			this->Controls->Add(this->equ_btn);
			this->Controls->Add(this->less_btn);
			this->Controls->Add(this->great_btn);
			this->Controls->Add(this->btn_run);
			this->Controls->Add(this->history_main);
			this->Controls->Add(this->text_main);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	long long l = 0, r = 101, m;
	private: System::Void btn_run_Click(System::Object^ sender, System::EventArgs^ e) {
		l = 0; r = 101;
		m = (r + l) / 2;
		this->history_main->Text += "\n";
		this->history_main->Text += m.ToString();
	}

	private: System::Void great_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->history_main->Text += "        Больше\n";
		r = m;
		m = (r + l) / 2;
		this->history_main->Text += m.ToString();
	}

	private: System::Void less_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->history_main->Text += "        Меньше\n";
		l = m;
		m = (r + l) / 2;
		this->history_main->Text += m.ToString();
	}

	private: System::Void equ_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->history_main->Text += "        Угадал\n";
		l = 1; r = 100;

	}
	

};
}
