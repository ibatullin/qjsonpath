#include "pluginloader.h"
#include "qjsonpath.h"
#include "qjsonlistmodel.h"

#include <QQmlEngine>
#include <QtQml>

Loader::Loader()
{
}

Loader::Loader( const Loader& orig )
   : QQmlExtensionPlugin( 0 )
{
   setParent( orig.parent() );
}

Loader::~Loader()
{
}

void Loader::registerTypes( const char* )
{
   qmlRegisterType< QJsonPath >( "QJson", 0, 1, "JsonPath" );
   qmlRegisterType< QJsonListModel >( "QJson", 0, 1, "JsonListModel" );
}
