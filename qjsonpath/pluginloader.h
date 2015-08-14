#ifndef CLIENTPLUGINLOADER_H
#define	CLIENTPLUGINLOADER_H

#include <QQmlExtensionPlugin>

class Loader
   : public QQmlExtensionPlugin
{
   Q_OBJECT
   Q_PLUGIN_METADATA(IID "QJson.QJsonPath" )

public:
   Loader();
   Loader( const Loader& orig );
   virtual ~Loader();

   void registerTypes( const char* uri );
};
#endif
