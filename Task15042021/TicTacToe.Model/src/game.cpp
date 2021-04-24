
#include "figure.h"
#include "field.h"
#include "game.h"

TicTacToe::Game::Game()
    : m_firstPlayerFigure(Figure(0)), m_secondPlayerFigure(Figure(0)), m_currentPlayerFigure(Figure(0))
{ }

TicTacToe::Game* TicTacToe::Game::create()
{
    return new Game();
}

void TicTacToe::Game::start(Figure firstPlayerFigure, Figure secondPlayerFigure, Figure firstTurnPlayerFigure)
{
    if (firstPlayerFigure == secondPlayerFigure)
        throw "Exception here!";

	if (!m_isEnd)
		throw "Exception here!";

    m_firstPlayerFigure = firstPlayerFigure;
    m_secondPlayerFigure = secondPlayerFigure;
    m_currentPlayerFigure = firstTurnPlayerFigure;

	m_isEnd = false;
}

void TicTacToe::Game::changeCurrentPlayer()
{
	if (m_currentPlayerFigure == Cross)
		m_currentPlayerFigure = Nought;
	else
		m_currentPlayerFigure = Cross;
}

bool TicTacToe::Game::makeTurn(int i, int j)
{
	if (!m_field.cell(i, j).isEmpty() || isEnd())
		return false;

	m_field.cell(i, j).fill(m_currentPlayerFigure);

	if (checkWinning()) 
	{
		m_winnerFigure = m_currentPlayerFigure;
		m_isEnd = true;
        emit gameIsEnd(m_winnerFigure);
	}

	changeCurrentPlayer();
    emit currentPlayerFigureChanged(m_currentPlayerFigure);

	return true;
}

void TicTacToe::Game::clear()
{
    m_field = Field();
}

bool TicTacToe::Game::checkWinning() const
{
	for (int i = 0; i < m_field.size(); i++)
	{
        Figure figure = m_field.cell(0, i).figure();

		int k = 0;
		for (; k < m_field.size(); k++) // column
            if (m_field.cell(k, i).figure() != figure || m_field.cell(k, i).isEmpty())
				break;
		if (k == m_field.size())
			return true;

        figure = m_field.cell(i, 0).figure();

		k = 0;
		for (; k < m_field.size(); k++) // row
            if (m_field.cell(i, k).figure() != figure || m_field.cell(i, k).isEmpty())
				break;
		if (k == m_field.size())
			return true;
	}

	Figure figure = m_field.cell(0, 0).figure();
	int i = 0;
	for (; i < m_field.size(); i++)
		if (m_field.cell(i, i).figure() != figure || m_field.cell(i, i).isEmpty())
			break;
	if (i == m_field.size())
		return true;

	figure = m_field.cell(0, m_field.size() - 1).figure();
	i = 0;
	for (; i < m_field.size(); i++)
		if (m_field.cell(i, m_field.size() - i - 1).figure() != figure || m_field.cell(i, m_field.size() - i - 1).isEmpty())
			break;
	if (i == m_field.size())
		return true;

	return false;
}
