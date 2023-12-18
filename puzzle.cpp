#include "puzzle.h"

#include <algorithm>
#include <ctime>

Puzzle::Puzzle(std::string nazwa_gracza)
{
	_nazwa_gracza = nazwa_gracza;
}

void Puzzle::obsluz_klikniecie(int id)
{
	if (id < 0 || id >= LICZBA_POL)
	{
		return;
	}

	if (_puzzle[id] == 0)
	{
		return;
	}

	_liczba_ruchow++;

	bool czy_sprawdzac_dol = id + 4 < LICZBA_POL;
	bool czy_sprawdzac_gore = id - 4 >= 0;
	bool czy_sprawdzac_lewo = id % 4 != 0;
	bool czy_sprawdzac_prawo = (id + 1) % 4 != 0;

	if (czy_sprawdzac_dol)
	{
		if (_puzzle[id + 4] == 0)
		{
			std::swap(_puzzle[id], _puzzle[id + 4]);
			return;
		}
	}
	if (czy_sprawdzac_gore)
	{
		if (_puzzle[id - 4] == 0)
		{
			std::swap(_puzzle[id], _puzzle[id - 4]);
			return;
		}
	}
	if (czy_sprawdzac_lewo)
	{
		if (_puzzle[id - 1] == 0)
		{
			std::swap(_puzzle[id], _puzzle[id - 1]);
			return;
		}
	}
	if (czy_sprawdzac_prawo)
	{
		if (_puzzle[id + 1] == 0)
		{
			std::swap(_puzzle[id], _puzzle[id + 1]);
			return;
		}
	}
}

bool Puzzle::czy_zwyciestwo()
{
	for (int i = 0; i < LICZBA_POL; i++)
	{
		if (_puzzle[i] != i)
		{
			return false;
		}
	}

	return true;
}

void Puzzle::resetuj()
{
	_liczba_ruchow = 0;

	std::srand(unsigned(std::time(0)));

	for (int i = 0; i < LICZBA_POL; i++)
	{
		_puzzle[i] = i;

	}

	std::random_shuffle(_puzzle, _puzzle + LICZBA_POL);
}

int Puzzle::get_liczba_ruchow()
{
	return _liczba_ruchow;
}

std::string Puzzle::getPuzzleText(int id)
{
	int puzzle_value = _puzzle[id];

	return std::to_string(puzzle_value);
}

std::string Puzzle::komunikat_zwyciescy()
{
	return "Wygra³eœ. Gratulacje u¿ytkowniku: " + _nazwa_gracza;
}