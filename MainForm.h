#pragma once

#include "puzzle.h"

namespace szablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			puzzle = new Puzzle("Puzzle");

			buttons = gcnew array<Button^>(16);

			for (int i = 0; i < 4; i++) 
			{
				for (int j = 0; j < 4; j++) 
				{
					int puzzle_btn = i * 4 + j;

					buttons[puzzle_btn] = gcnew Button();

					buttons[puzzle_btn]->Left = 100 + j * 40;
					buttons[puzzle_btn]->Top = 200 + i * 40;
					buttons[puzzle_btn]->Width = 40;
					buttons[puzzle_btn]->Height = 40;
					buttons[puzzle_btn]->Tag = puzzle_btn;

					buttons[puzzle_btn]->Click += gcnew System::EventHandler(this, &MainForm::click_puzzle);
					buttons[puzzle_btn]->Enabled = false;

					Controls->Add(buttons[puzzle_btn]);
				}
			}

			menuStrip1->Enabled = false;
			button1->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}

			if (puzzle) 
			{
				delete puzzle;
			}
		}


	private: Puzzle *puzzle;
	private: System::Windows::Forms::Button^ button1;
	private: array<Button^>^ buttons;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ plikToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nowaGraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ wyjœcieToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonLogin;
	private: System::Windows::Forms::Label^ labelRuchy;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->plikToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nowaGraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wyjœcieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->labelRuchy = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Nowa gra";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->plikToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(768, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// plikToolStripMenuItem
			// 
			this->plikToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nowaGraToolStripMenuItem,
					this->wyjœcieToolStripMenuItem
			});
			this->plikToolStripMenuItem->Name = L"plikToolStripMenuItem";
			this->plikToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->plikToolStripMenuItem->Text = L"Plik";
			// 
			// nowaGraToolStripMenuItem
			// 
			this->nowaGraToolStripMenuItem->Name = L"nowaGraToolStripMenuItem";
			this->nowaGraToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->nowaGraToolStripMenuItem->Text = L"Nowa gra";
			this->nowaGraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::nowaGraToolStripMenuItem_Click);
			// 
			// wyjœcieToolStripMenuItem
			// 
			this->wyjœcieToolStripMenuItem->Name = L"wyjœcieToolStripMenuItem";
			this->wyjœcieToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->wyjœcieToolStripMenuItem->Text = L"Wyjœcie";
			this->wyjœcieToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::wyjœcieToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(310, 211);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"Wpisz login";
			// 
			// buttonLogin
			// 
			this->buttonLogin->Location = System::Drawing::Point(324, 237);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(75, 23);
			this->buttonLogin->TabIndex = 6;
			this->buttonLogin->Text = L"zaloguj";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &MainForm::buttonLogin_Click);
			// 
			// labelRuchy
			// 
			this->labelRuchy->AutoSize = true;
			this->labelRuchy->Location = System::Drawing::Point(24, 436);
			this->labelRuchy->Name = L"labelRuchy";
			this->labelRuchy->Size = System::Drawing::Size(88, 13);
			this->labelRuchy->TabIndex = 7;
			this->labelRuchy->Text = L"Liczba ruchów: 0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 479);
			this->Controls->Add(this->labelRuchy);
			this->Controls->Add(this->buttonLogin);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void click_puzzle(System::Object^ sender, System::EventArgs^ e);
		System::Void wyjœcieToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void nowaGraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e);

		void draw_puzzles();
		void resetuj_gre();
};
}
