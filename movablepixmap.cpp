#include "movablepixmap.h"

#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QFileInfo>

MovablePicture::MovablePicture(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{}

MovablePicture::MovablePicture(const QString &imagepath, int initialZ, QGraphicsItem *parent):
    QGraphicsPixmapItem(imagepath, parent),
    m_name(QFileInfo{imagepath}.filePath())
{
    setZValue(initialZ);
}

QString MovablePicture::name()
{
    return m_name;
}

void MovablePicture::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
}

void MovablePicture::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto diff = event->scenePos() - event->lastScenePos();
    moveBy(diff.x(), diff.y());
}

void MovablePicture::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
}
