#ifndef QJSONPATH_H
#define QJSONPATH_H

#include "jsonpath.h"
#include <QtQuick/QQuickItem>
#include <QJsonDocument>
#include <QMetaType>

class QJsonPath : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool valid READ getValid NOTIFY validChanged)
    Q_PROPERTY(QString path READ getPath WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString json READ getJson WRITE setJson NOTIFY jsonChanged)
    Q_PROPERTY(QJsonDocument jsonDocument READ getJsonDocument NOTIFY jsonDocumentChanged)
public:
    QJsonPath(QQuickItem *parent = 0);
    bool getValid() const;
    QString getPath() const;
    void setPath(const QString &);
    QString getJson() const;
    void setJson(const QString &);
    QJsonDocument getJsonDocument() const;

signals:
    void validChanged(bool);
    void pathChanged(QString);
    void jsonDocumentChanged(QJsonDocument);
    void jsonChanged(QString);

private:
    void setValid(bool);
    void update();

    QJsonDocument m_jsonDocument;
    QString m_json;
    bool m_valid;
    QString m_path;
};

Q_DECLARE_METATYPE(QJsonPath *)

#endif // QJSONPATH_H
