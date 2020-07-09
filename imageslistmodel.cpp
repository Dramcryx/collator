#include "imageslistmodel.h"

ImagesListModel::ImagesListModel(QObject * parent): QAbstractListModel(parent)
{

}

int ImagesListModel::rowCount(const QModelIndex & /*parent*/) const
{
    return m_images.size();
}

QVariant ImagesListModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case Qt::DisplayRole:
        return m_images.at(index.row())->name();
    case Qt::UserRole:
        return QVariant::fromValue(m_images.at(index.row()));
    }
    return QVariant();
}

void ImagesListModel::addImage(const QString &img)
{
    int current_size = m_images.size();
    beginInsertRows(QModelIndex(), current_size, current_size + 1);
    m_images.append(new MovablePicture{img, current_size});
    endInsertRows();
    emit imageAdded(m_images.last());
}

void ImagesListModel::removeImage(int index)
{
    beginRemoveRows(QModelIndex(), index, index + 1);
    auto save = m_images.at(index);
    m_images.removeAt(index);
    endRemoveRows();
    emit imageRemoved(save);
    delete save;
}
