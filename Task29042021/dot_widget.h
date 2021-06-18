#ifndef DOTWIDGET_H
#define DOTWIDGET_H

#include <QWidget>
#include <QVector2D>

class DotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DotWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) final;

    void resizeEvent(QResizeEvent*) final;

    void mouseMoveEvent(QMouseEvent*) final;

private:
    bool inBounds(const QVector2D&) const;

    static constexpr int m_panicDistance = 50;
    static constexpr int m_pointSpeed = 3;
    QVector2D m_pointPosition;
};

#endif // RUNNINGDOTWIDGET_H
