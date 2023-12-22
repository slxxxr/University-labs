#pragma once

namespace lab9vtoroe {

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
	private: System::Windows::Forms::Label^ front_text;
	private: System::Windows::Forms::Label^ text_text;
	private: System::Windows::Forms::Label^ front_now;
	private: System::Windows::Forms::Label^ text_now;
	protected:

	protected:



	private: System::Windows::Forms::RadioButton^ btn_blue;
	private: System::Windows::Forms::RadioButton^ btn_red;
	private: System::Windows::Forms::RadioButton^ btn_green;
	private: System::Windows::Forms::ListBox^ front_clr;







	private: System::Windows::Forms::RadioButton^ btn_black;
	private: System::Windows::Forms::Label^ selected_front;
	private: System::Windows::Forms::Label^ selected_text;
	private: System::Windows::Forms::RadioButton^ btn_white;

	protected:

	protected:

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
			this->front_text = (gcnew System::Windows::Forms::Label());
			this->text_text = (gcnew System::Windows::Forms::Label());
			this->front_now = (gcnew System::Windows::Forms::Label());
			this->text_now = (gcnew System::Windows::Forms::Label());
			this->btn_blue = (gcnew System::Windows::Forms::RadioButton());
			this->btn_red = (gcnew System::Windows::Forms::RadioButton());
			this->btn_green = (gcnew System::Windows::Forms::RadioButton());
			this->front_clr = (gcnew System::Windows::Forms::ListBox());
			this->btn_black = (gcnew System::Windows::Forms::RadioButton());
			this->selected_front = (gcnew System::Windows::Forms::Label());
			this->selected_text = (gcnew System::Windows::Forms::Label());
			this->btn_white = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// front_text
			// 
			this->front_text->AutoSize = true;
			this->front_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->front_text->ForeColor = System::Drawing::Color::Black;
			this->front_text->Location = System::Drawing::Point(39, 44);
			this->front_text->Name = L"front_text";
			this->front_text->Size = System::Drawing::Size(202, 16);
			this->front_text->TabIndex = 0;
			this->front_text->Text = L"Выберите текущий цвет фона";
			// 
			// text_text
			// 
			this->text_text->AutoSize = true;
			this->text_text->Location = System::Drawing::Point(297, 44);
			this->text_text->Name = L"text_text";
			this->text_text->Size = System::Drawing::Size(153, 16);
			this->text_text->TabIndex = 1;
			this->text_text->Text = L"Выберите цвет текста";
			// 
			// front_now
			// 
			this->front_now->AutoSize = true;
			this->front_now->Location = System::Drawing::Point(529, 44);
			this->front_now->Name = L"front_now";
			this->front_now->Size = System::Drawing::Size(139, 16);
			this->front_now->TabIndex = 2;
			this->front_now->Text = L"Текущий цвет фона:";
			// 
			// text_now
			// 
			this->text_now->AutoSize = true;
			this->text_now->Location = System::Drawing::Point(776, 44);
			this->text_now->Name = L"text_now";
			this->text_now->Size = System::Drawing::Size(151, 16);
			this->text_now->TabIndex = 3;
			this->text_now->Text = L"Текущий цвет текста: ";
			// 
			// btn_blue
			// 
			this->btn_blue->AutoSize = true;
			this->btn_blue->Location = System::Drawing::Point(300, 186);
			this->btn_blue->Name = L"btn_blue";
			this->btn_blue->Size = System::Drawing::Size(55, 20);
			this->btn_blue->TabIndex = 7;
			this->btn_blue->Text = L"Blue";
			this->btn_blue->UseVisualStyleBackColor = true;
			this->btn_blue->CheckedChanged += gcnew System::EventHandler(this, &MyForm::btn_blue_CheckedChanged);
			// 
			// btn_red
			// 
			this->btn_red->AutoSize = true;
			this->btn_red->Location = System::Drawing::Point(300, 112);
			this->btn_red->Name = L"btn_red";
			this->btn_red->Size = System::Drawing::Size(54, 20);
			this->btn_red->TabIndex = 8;
			this->btn_red->Text = L"Red";
			this->btn_red->UseVisualStyleBackColor = true;
			this->btn_red->CheckedChanged += gcnew System::EventHandler(this, &MyForm::btn_red_CheckedChanged);
			// 
			// btn_green
			// 
			this->btn_green->AutoSize = true;
			this->btn_green->Location = System::Drawing::Point(300, 150);
			this->btn_green->Name = L"btn_green";
			this->btn_green->Size = System::Drawing::Size(65, 20);
			this->btn_green->TabIndex = 9;
			this->btn_green->Text = L"Green";
			this->btn_green->UseVisualStyleBackColor = true;
			this->btn_green->CheckedChanged += gcnew System::EventHandler(this, &MyForm::btn_green_CheckedChanged);
			// 
			// front_clr
			// 
			this->front_clr->AllowDrop = true;
			this->front_clr->FormattingEnabled = true;
			this->front_clr->ItemHeight = 16;
			this->front_clr->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"White", L"Blue", L"Red", L"Green" });
			this->front_clr->Location = System::Drawing::Point(42, 73);
			this->front_clr->Name = L"front_clr";
			this->front_clr->Size = System::Drawing::Size(120, 68);
			this->front_clr->TabIndex = 10;
			this->front_clr->UseWaitCursor = true;
			this->front_clr->SetSelected(0, true);
			this->front_clr->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::front_clr_SelectedIndexChanged);
			// 
			// btn_black
			// 
			this->btn_black->AutoSize = true;
			this->btn_black->Checked = true;
			this->btn_black->Location = System::Drawing::Point(300, 73);
			this->btn_black->Name = L"btn_black";
			this->btn_black->Size = System::Drawing::Size(62, 20);
			this->btn_black->TabIndex = 11;
			this->btn_black->TabStop = true;
			this->btn_black->Text = L"Black";
			this->btn_black->UseVisualStyleBackColor = true;
			this->btn_black->CheckedChanged += gcnew System::EventHandler(this, &MyForm::btn_black_CheckedChanged);
			// 
			// selected_front
			// 
			this->selected_front->AutoSize = true;
			this->selected_front->Location = System::Drawing::Point(529, 73);
			this->selected_front->Name = L"selected_front";
			this->selected_front->Size = System::Drawing::Size(41, 16);
			this->selected_front->TabIndex = 12;
			this->selected_front->Text = L"White";
			// 
			// selected_text
			// 
			this->selected_text->AutoSize = true;
			this->selected_text->Location = System::Drawing::Point(776, 73);
			this->selected_text->Name = L"selected_text";
			this->selected_text->Size = System::Drawing::Size(41, 16);
			this->selected_text->TabIndex = 13;
			this->selected_text->Text = L"Black";
			// 
			// btn_white
			// 
			this->btn_white->AutoSize = true;
			this->btn_white->Location = System::Drawing::Point(300, 224);
			this->btn_white->Name = L"btn_white";
			this->btn_white->Size = System::Drawing::Size(62, 20);
			this->btn_white->TabIndex = 14;
			this->btn_white->TabStop = true;
			this->btn_white->Text = L"White";
			this->btn_white->UseVisualStyleBackColor = true;
			this->btn_white->CheckedChanged += gcnew System::EventHandler(this, &MyForm::btn_white_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1000, 500);
			this->Controls->Add(this->btn_white);
			this->Controls->Add(this->selected_text);
			this->Controls->Add(this->selected_front);
			this->Controls->Add(this->btn_black);
			this->Controls->Add(this->front_clr);
			this->Controls->Add(this->btn_green);
			this->Controls->Add(this->btn_red);
			this->Controls->Add(this->btn_blue);
			this->Controls->Add(this->text_now);
			this->Controls->Add(this->front_now);
			this->Controls->Add(this->text_text);
			this->Controls->Add(this->front_text);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void front_clr_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (front_clr->SelectedItem == "White") {
		this->BackColor = System::Drawing::Color::White;
		this->selected_front->Text = "White";
	}
	if (front_clr->SelectedItem == "Blue") {
		this->BackColor = System::Drawing::Color::Blue;
		this->selected_front->Text = "Blue";
	}
	if (front_clr->SelectedItem == "Red") {
		this->BackColor = System::Drawing::Color::Red;
		this->selected_front->Text = "Red";
	}
	if (front_clr->SelectedItem == "Green") {
		this->BackColor = System::Drawing::Color::Green;
		this->selected_front->Text = "Green";
	}
}
private: System::Void btn_black_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->front_text->ForeColor = System::Drawing::Color::Black;
	this->text_text->ForeColor = System::Drawing::Color::Black;
	this->front_now->ForeColor = System::Drawing::Color::Black;
	this->selected_front->ForeColor = System::Drawing::Color::Black;
	this->text_now->ForeColor = System::Drawing::Color::Black;
	this->selected_text->ForeColor = System::Drawing::Color::Black;
	this->selected_text->Text = "Black";
}
private: System::Void btn_red_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->front_text->ForeColor = System::Drawing::Color::Red;
	this->text_text->ForeColor = System::Drawing::Color::Red;
	this->front_now->ForeColor = System::Drawing::Color::Red;
	this->selected_front->ForeColor = System::Drawing::Color::Red;
	this->text_now->ForeColor = System::Drawing::Color::Red;
	this->selected_text->ForeColor = System::Drawing::Color::Red;
	this->selected_text->Text = "Red";

}
private: System::Void btn_green_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->front_text->ForeColor = System::Drawing::Color::Green;
	this->text_text->ForeColor = System::Drawing::Color::Green;
	this->front_now->ForeColor = System::Drawing::Color::Green;
	this->selected_front->ForeColor = System::Drawing::Color::Green;
	this->text_now->ForeColor = System::Drawing::Color::Green;
	this->selected_text->ForeColor = System::Drawing::Color::Green;
	this->selected_text->Text = "Green";

}
private: System::Void btn_blue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->front_text->ForeColor = System::Drawing::Color::Blue;
	this->text_text->ForeColor = System::Drawing::Color::Blue;
	this->front_now->ForeColor = System::Drawing::Color::Blue;
	this->selected_front->ForeColor = System::Drawing::Color::Blue;
	this->text_now->ForeColor = System::Drawing::Color::Blue;
	this->selected_text->ForeColor = System::Drawing::Color::Blue;
	this->selected_text->Text = "Blue";
}
private: System::Void btn_white_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->front_text->ForeColor = System::Drawing::Color::White;
	this->text_text->ForeColor = System::Drawing::Color::White;
	this->front_now->ForeColor = System::Drawing::Color::White;
	this->selected_front->ForeColor = System::Drawing::Color::White;
	this->text_now->ForeColor = System::Drawing::Color::White;
	this->selected_text->ForeColor = System::Drawing::Color::White;
	this->selected_text->Text = "White";
}
};
}
