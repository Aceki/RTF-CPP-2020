#pragma once

#include <QObject>

#include "field.h"

namespace TicTacToe
{
	enum Figure;

    class Game : public QObject
	{
        Q_OBJECT

	public:
		Game(const Game&) = default;

        static Game* create();

		bool isEnd() const;

		const Field& field() const;

		Figure firstPlayerFigure() const;

		Figure secondPlayerFigure() const;

		Figure currentPlayerFigure() const;

		Figure winnerPlayerFigure() const;

		Game& operator=(const Game&) = delete;

    public slots:
        void start(Figure firstPlayerFigure, Figure secondPlayerFigure, Figure firstTurnPlayerFigure);

        bool makeTurn(int i, int j);

        void clear();
    signals:
        void gameIsEnd(Figure winnerPlayerFigure);

        void currentPlayerFigureChanged(Figure currentPlayerFigure);

	private:
        Game();

		bool checkWinning() const;

		void changeCurrentPlayer();

		Figure m_firstPlayerFigure;
		Figure m_secondPlayerFigure;
		Figure m_currentPlayerFigure;

		Field m_field;

		mutable bool m_isEnd = true;
		mutable Figure m_winnerFigure = Figure(0);
	};

	inline bool Game::isEnd() const { return m_isEnd; }

	inline Figure Game::winnerPlayerFigure() const { return m_winnerFigure; }
	
	inline const Field& Game::field() const { return m_field; }

	inline Figure Game::firstPlayerFigure() const { return m_firstPlayerFigure; }

	inline Figure Game::secondPlayerFigure() const { return m_secondPlayerFigure; }

	inline Figure Game::currentPlayerFigure() const { return m_currentPlayerFigure; }
}
