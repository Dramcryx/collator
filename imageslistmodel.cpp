#include "imageslistmodel.h"

#include <utility>

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

void ImagesListModel::pull(int index)
{
    if (index < m_images.size() - 1)
    {
        beginMoveRows(this->index(index), index, index, this->index(index + 1), index + 1);

        auto tmp = m_images.at(index);
        m_images.replace(index, m_images.at(index + 1));
        m_images.replace(index + 1, tmp);


        auto lower = m_images.at(index);
        lower->setZValue(lower->zValue() - 1);

        auto upper = m_images.at(index + 1);
        upper->setZValue(upper->zValue() + 1);
        endMoveRows();
        emit movedAbove(this->index(index + 1), QItemSelectionModel::ClearAndSelect);
    }
}

void ImagesListModel::push(int index)
{
    if (index > 0)
    {
        beginMoveRows(QModelIndex(), index, index, QModelIndex(), index - 1);

        // standard swaps don't work
        auto tmp = m_images.at(index);
        m_images.replace(index, m_images.at(index - 1));
        m_images.replace(index - 1, tmp);


        auto lower = m_images.at(index - 1);
        lower->setZValue(lower->zValue() - 1);

        auto upper = m_images.at(index);
        upper->setZValue(upper->zValue() + 1);
        endMoveRows();
    }
}
