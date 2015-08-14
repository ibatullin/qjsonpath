#ifndef JSONLISTMODEL_H
#define JSONLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <QJsonDocument>

class QJsonListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QJsonDocument json READ getJson WRITE setJson NOTIFY jsonChanged)
public:
    enum ListRoles {
        TextRole = Qt::UserRole + 1,
        SizeRole
    };

    QJsonListModel(QObject *parent = 0);
    QJsonDocument getJson() const;
    void setJson(const QJsonDocument json);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    bool insertRows(int row, int count, const QModelIndex &parent);
    QHash<int, QByteArray> roleNames() const;

signals:
    void jsonChanged(QJsonDocument);

private:
    QJsonValue getItemValue(const QModelIndex &idx) const;

    QJsonDocument m_json;
};

#endif // JSONLISTMODEL_H
