#ifndef IMAGESLISTMODEL_H
#define IMAGESLISTMODEL_H

#include <QAbstractListModel>

#include "movablepixmap.h"

class ImagesListModel: public QAbstractListModel
{
    Q_OBJECT

public:
    ImagesListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addImage(const QString & img);

signals:
    void imageAdded(QGraphicsPixmapItem * img);

private:
    QList<MovablePicture*> m_images;
};

#endif // IMAGESLISTMODEL_H
