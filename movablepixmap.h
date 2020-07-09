#ifndef MOVABLEPIXMAP_H
#define MOVABLEPIXMAP_H

#include <QGraphicsPixmapItem>

class MovablePicture: public QGraphicsPixmapItem
{
public:
    MovablePicture(QGraphicsItem *parent = nullptr);
    MovablePicture(const QString & imagepath, int initialZ = 0, QGraphicsItem *parent = nullptr);

    QString name();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString m_name;
};

Q_DECLARE_METATYPE(MovablePicture*);

#endif // MOVABLEPIXMAP_H
