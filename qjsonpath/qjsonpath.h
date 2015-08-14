#ifndef __QJSONPATH__
#define __QJSONPATH__

#include "jsonpath.h"
#include <QtQuick/QQuickItem>
#include <QJsonDocument>

class QJsonPath
   : public QQuickItem
{
   Q_OBJECT
   Q_PROPERTY( bool valid READ getValid NOTIFY validChanged )
   Q_PROPERTY( QString path READ getPath WRITE setPath NOTIFY pathChanged )
   Q_PROPERTY( QString json READ getJson WRITE setJson NOTIFY jsonChanged )
   Q_PROPERTY( QJsonDocument jsonDocument READ getJsonDocument NOTIFY jsonDocumentChanged )
public:
   bool getValid() const;
private:
   void setValid( bool );
   bool _valid;
signals:
   void validChanged( bool );

public:
   QString getPath() const;
   void setPath( const QString& );
private:
   QString _path;
signals:
   void pathChanged( QString );

public:
   QString getJson() const;
   void setJson( const QString& );
private:
   QString _json;
signals:
   void jsonChanged( QString );
public:
   QJsonDocument getJsonDocument() const;
private:
   QJsonDocument _jsonDocument;
signals:
   void jsonDocumentChanged( QJsonDocument );

public:
   QJsonPath( QQuickItem* parent = 0 );
   
private:
   void update();
};

#include <QMetaType>
Q_DECLARE_METATYPE( QJsonPath* )

#endif
