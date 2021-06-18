#include <QtMath>

#include <QPainter>
#include <QMouseEvent>

#include "dot_widget.h"

DotWidget::DotWidget(QWidget* parent) : QWidget(parent), m_pointPosition(0, 0)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setMouseTracking(true);
}

void DotWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(0, 0, width(), height(), QColor(255, 255, 0));


    painter.drawEllipse(m_pointPosition.x(), m_pointPosition.y(), 5, 5);
}

void DotWidget::resizeEvent(QResizeEvent *event)
{
    event->accept();

    m_pointPosition = QVector2D(width(), height()) / 2;
}

void DotWidget::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    QVector2D pointMouseVector = QVector2D(m_pointPosition.x() - event->pos().x(), m_pointPosition.y() - event->pos().y());
    float pointMouseDistance = pointMouseVector.length();

    if (pointMouseDistance <= m_panicDistance)
    {
        QVector2D newPointPosition = m_pointPosition + pointMouseVector.normalized() * m_pointSpeed;
        if (inBounds(newPointPosition))
            m_pointPosition = newPointPosition;
    }

    update();
}

bool DotWidget::inBounds(const QVector2D& vector) const
{
    return !(vector.x() < 0 || vector.x() >= width() || vector.y() < 0 || vector.y() >= height());
}
