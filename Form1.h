#pragma once
#include <cmath>
#include "functions.h"
namespace Optimize {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 





	private: System::Windows::Forms::TextBox^  textBoxX2;
	private: System::Windows::Forms::TextBox^  textBoxX1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBoxE;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBoxX02;
	private: System::Windows::Forms::TextBox^  textBoxX01;
	private: System::Windows::Forms::Label^  label9;


	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;






	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxX2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxE = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxX02 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX01 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxX2
			// 
			this->textBoxX2->Location = System::Drawing::Point(448, 295);
			this->textBoxX2->Name = L"textBoxX2";
			this->textBoxX2->Size = System::Drawing::Size(73, 29);
			this->textBoxX2->TabIndex = 7;
			// 
			// textBoxX1
			// 
			this->textBoxX1->Location = System::Drawing::Point(321, 295);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(73, 29);
			this->textBoxX1->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(47, 298);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(157, 21);
			this->label7->TabIndex = 53;
			this->label7->Text = L"Решение системы:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(325, 242);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 28);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBoxE
			// 
			this->textBoxE->Location = System::Drawing::Point(321, 180);
			this->textBoxE->Name = L"textBoxE";
			this->textBoxE->Size = System::Drawing::Size(73, 29);
			this->textBoxE->TabIndex = 4;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(47, 183);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(158, 21);
			this->label8->TabIndex = 50;
			this->label8->Text = L"Введите точность:";
			// 
			// textBoxX02
			// 
			this->textBoxX02->Location = System::Drawing::Point(448, 124);
			this->textBoxX02->Name = L"textBoxX02";
			this->textBoxX02->Size = System::Drawing::Size(73, 29);
			this->textBoxX02->TabIndex = 2;
			// 
			// textBoxX01
			// 
			this->textBoxX01->Location = System::Drawing::Point(321, 124);
			this->textBoxX01->Name = L"textBoxX01";
			this->textBoxX01->Size = System::Drawing::Size(73, 29);
			this->textBoxX01->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(47, 128);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(222, 21);
			this->label9->TabIndex = 47;
			this->label9->Text = L"Введите начальную точку:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(48, 64);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(246, 21);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Решение системы уравнений:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(275, 128);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(263, 21);
			this->label34->TabIndex = 60;
			this->label34->Text = L"x0 =                   y0 =                  ";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(286, 299);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(260, 21);
			this->label35->TabIndex = 63;
			this->label35->Text = L"x =                    y =                    ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(358, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 21);
			this->label3->TabIndex = 65;
			this->label3->Text = L"xy  =  1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(358, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 21);
			this->label2->TabIndex = 64;
			this->label2->Text = L"x  -  y  =  5";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 362);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxX2);
			this->Controls->Add(this->textBoxX1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxE);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxX02);
			this->Controls->Add(this->textBoxX01);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label35);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"Form1";
			this->Text = L"Оптимизационные методы решения систем нелинейных уравнений";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	double E; // E - точность, А - длина шага спуска, sum - вспомогательная переменная
	int n = 2; // количество переменных

	double *x = new double[n];
	double *X = new double[n];

	if (!Double::TryParse(textBoxX01->Text, X[0])) {
		MessageBox::Show("Неверно задана точка x. Повторите ввод.", "Ошибка ввода", MessageBoxButtons::OK);
		return;
	}

	if (!Double::TryParse(textBoxX02->Text, X[1])) {
		MessageBox::Show("Неверно задана точка y. Повторите ввод.", "Ошибка ввода", MessageBoxButtons::OK);
		return;
	}

	/*if (!Double::TryParse(textBoxX02->Text, X[2])) {
		MessageBox::Show("Неверно задана точка z. Повторите ввод.", "Ошибка ввода", MessageBoxButtons::OK);
		return;
	}*/

	if (!Double::TryParse(textBoxE->Text, E)) {
		MessageBox::Show("Неверно задана точность. Повторите ввод", "Ошибка ввода", MessageBoxButtons::OK);
		return;
	}

	// Находим начальное приближение ГМНС
	GradientMethod(X, x, n, E);
	
	// Уточняем точку минимума ДФП
	DFPMethod(X, x, n, E);

	textBoxX1->Text = Convert::ToString(X[0]);
	textBoxX2->Text = Convert::ToString(X[1]);
	//textBoxX3->Text = Convert::ToString(X[2]);

	if (f(X) > 0.1) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Найденная точка - точка ненулевого минимума. Повторите попытку, выбрав другую начальную точку.",
			"Результат проверки", MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button1,
			MessageBoxOptions::DefaultDesktopOnly);
	}

	// Очищение памяти
	delete[]x;
	delete[]X;

		 }
};
}

