#ifndef MOVABLEPIXMAP_H
#define MOVABLEPIXMAP_H

#include <QGraphicsPixmapItem>

class MovablePicture: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MovablePicture(QGraphicsItem *parent = nullptr);
    MovablePicture(const QString & imagepath, int initialZ = 0, QGraphicsItem *parent = nullptr);

    QString name();

signals:
    void mouseClicked(MovablePicture *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString m_name;
};

Q_DECLARE_METATYPE(MovablePicture*);

#endif // MOVABLEPIXMAP_H
