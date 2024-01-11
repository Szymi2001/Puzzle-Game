#include "MainForm.h"

#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;

namespace szablon 
{
	System::Void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		resetuj_gre();
	}

	System::Void MainForm::click_puzzle(System::Object^ sender, System::EventArgs^ e) {
		Button^ clicked_button = (Button^)sender;

		int index = (int)clicked_button->Tag;

		puzzle->obsluz_klikniecie(index);

		draw_puzzles();

		if (puzzle->czy_zwyciestwo())
		{
			String^ komunikat = marshal_as<String^>(puzzle->komunikat_zwyciescy());

			MessageBox::Show(komunikat);

			for (int i = 0; i < 16; i++)
			{
				buttons[i]->Enabled = false;
			}
		}
	}

	System::Void MainForm::wyjscieToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}

	System::Void MainForm::nowaGraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		resetuj_gre();
	}

	System::Void MainForm::buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		menuStrip1->Enabled = true;
		button1->Enabled = true;

		std::string login = marshal_as<std::string>(textBox1->Text);

		puzzle = new Puzzle(login);

		textBox1->Visible = false;
		buttonLogin->Visible = false;
	}

	void MainForm::draw_puzzles()
	{
		array<String^>^ imagePaths = gcnew array<String^>(16);

		for (int i = 0; i < 16; i++)
		{
			

			Button^ btn = buttons[i];

			

			std::string puzzle_text = puzzle->getPuzzleText(i);

			if (puzzle_text == "0")
			{
				btn->Enabled = false;
				btn->Text = "";
				btn->BackgroundImage = Image::FromFile("images\\image_empty.jpg");
			}
			else
			{
				btn->Enabled = true;
				btn->Text = marshal_as<String^>(puzzle_text);
				System::String^ defaultPath = gcnew System::String("images\\image_part_");
				System::String^ imagePaths = System::String::Concat(defaultPath,
					gcnew System::String(puzzle_text.c_str()), ".jpg");

				Image^ bgImage = Image::FromFile(imagePaths);
				btn->BackgroundImage = bgImage;
				btn->BackgroundImageLayout = ImageLayout::Stretch;
			}
		}

		int ruchy = puzzle->get_liczba_ruchow();
		labelRuchy->Text = "Liczba ruchów: " + ruchy;
	}

	void MainForm::resetuj_gre()
	{
		for (int i = 0; i < 16; i++)
		{
			buttons[i]->Enabled = true;
		}

		puzzle->resetuj();
		draw_puzzles();
	}
}

