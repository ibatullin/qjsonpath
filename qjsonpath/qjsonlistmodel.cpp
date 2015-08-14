#include "qjsonlistmodel.h"
#include <QJsonArray>
#include <QJsonObject>

QJsonListModel::QJsonListModel( QObject *parent )
   : QAbstractListModel( parent )
{
}

QJsonDocument QJsonListModel::getJson() const
{
   return _json;
}

void QJsonListModel::setJson( const QJsonDocument value )
{
   if ( _json != value )
   {
      if ( value.isArray() )
      {
         _json = value;
         QJsonArray arr = _json.array();
         beginInsertRows( QModelIndex(), 0, arr.size() - 1 );
         endInsertRows();
         //updateModel();
         emit jsonChanged( _json );
      }
   }
}

bool QJsonListModel::insertRows( int row, int count, const QModelIndex& parent )
{
   // todo: do I need to change the model index of rows that follow the insertion?
   beginInsertRows( parent, row, row + count - 1 );
   endInsertRows();
   return true;
}

QJsonValue QJsonListModel::getItemValue( const QModelIndex& idx ) const
{
   if ( idx.isValid() )
   {
      QJsonValue v = getItemValue( idx.parent() );
      if ( v.isArray() )
         return v.toArray()[ idx.row() ];
      return QJsonValue();
   }
   // if not valid it's the root
   return QJsonValue( _json.array() );
}

int QJsonListModel::rowCount( const QModelIndex& idx ) const
{
   // if not an array then will return zero
   return getItemValue( idx ).toArray().size();
}

// todo: investigate using toVariant() here
QVariant getValue( const QJsonValue& r, const QModelIndex& idx, const char* key )
{
   switch ( r.type() )
   {
      case QJsonValue::Array:
         if ( idx.isValid() )
            return getValue( r.toArray()[ idx.row() ], QModelIndex(), key );
         break;
      case QJsonValue::Object:
         {
            QJsonObject obj = r.toObject();
            QJsonValue val = obj[ key ];
            if ( ! val.isUndefined() )
               return val.toString();
         }
         break;
      case QJsonValue::Bool:
      case QJsonValue::Double:
      case QJsonValue::String:
         return r.toString();
      default:
         break;
   }
   return QVariant();
}

QVariant QJsonListModel::data( const QModelIndex& idx, int role ) const
{
   QJsonValue v = getItemValue( idx );
   switch ( role )
   {
      case Qt::ToolTipRole:
         return getValue( v, idx, "ToolTip" );
         break;

      case Qt::StatusTipRole:
         return getValue( v, idx, "StatusTip" );
         break;

      case Qt::WhatsThisRole:
         return getValue( v, idx, "WhatsThis" );
         break;

      case Qt::DisplayRole:
      case Qt::EditRole:
      case TextRole:
         return getValue( v, idx, "text" );
         break;
      default:
         break;
   }
   return QVariant();
}

QHash<int, QByteArray> QJsonListModel::roleNames() const
{
   QHash<int, QByteArray> roles;
   roles[TextRole] = "text";
   return roles;
}

