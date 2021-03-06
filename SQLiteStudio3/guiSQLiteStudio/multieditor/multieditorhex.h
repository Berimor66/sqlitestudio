#ifndef MULTIEDITORHEX_H
#define MULTIEDITORHEX_H

#include "multieditorwidget.h"
#include "multieditorwidgetplugin.h"
#include "plugins/builtinplugin.h"
#include <QVariant>
#include <QSharedPointer>

class QHexEdit;
class QBuffer;

class GUI_API_EXPORT MultiEditorHex : public MultiEditorWidget
{
        Q_OBJECT
    public:
        explicit MultiEditorHex();
        ~MultiEditorHex();

        void setValue(const QVariant& value);
        QVariant getValue();
        void setReadOnly(bool value);
        void focusThisWidget();

        QList<QWidget*> getNoScrollWidgets();

    private:
        QHexEdit* hexEdit = nullptr;

    private slots:
        void modificationChanged();
};

class GUI_API_EXPORT MultiEditorHexPlugin : public BuiltInPlugin, public MultiEditorWidgetPlugin
{
    Q_OBJECT

    SQLITESTUDIO_PLUGIN_AUTHOR("sqlitestudio.pl")
    SQLITESTUDIO_PLUGIN_DESC("Hexadecimal data editor.")
    SQLITESTUDIO_PLUGIN_TITLE("Hexadecimal")
    SQLITESTUDIO_PLUGIN_VERSION(10000)

    public:
        MultiEditorWidget* getInstance();
        bool validFor(const DataType& dataType);
        int getPriority(const DataType& dataType);
        QString getTabLabel();
};

#endif // MULTIEDITORHEX_H
