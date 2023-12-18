#pragma once

#include <string>

class Puzzle
{
private:
	const static int LICZBA_POL = 16;

	std::string _nazwa_gracza;
	int _liczba_ruchow;
	int _puzzle[LICZBA_POL];

public:
	Puzzle(std::string nazwa_gracza);

	void obsluz_klikniecie(int id);
	bool czy_zwyciestwo();
	void resetuj();

	int get_liczba_ruchow();
	std::string getPuzzleText(int id);

	std::string komunikat_zwyciescy();
};

