#ifndef IMAGESLISTMODEL_H
#define IMAGESLISTMODEL_H

#include <QAbstractListModel>
#include <QItemSelectionModel>

#include "movablepixmap.h"

class ImagesListModel: public QAbstractListModel
{
    Q_OBJECT

public:
    ImagesListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addImage(const QString & img);
    void removeImage(int index);

    void pull(int index);
    void push(int index);

signals:
    void imageAdded(QGraphicsPixmapItem * img);
    void imageRemoved(QGraphicsPixmapItem * img);

    // when moving down in list, it does not save selection unlike moving up
    void movedAbove(const QModelIndex & index, QItemSelectionModel::SelectionFlag flags);

private:
    QList<MovablePicture*> m_images;
};

#endif // IMAGESLISTMODEL_H
