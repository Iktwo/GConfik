#ifndef LISTKEY_H
#define LISTKEY_H

#include <QObject>

class ListKey : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString index READ index WRITE setIndex NOTIFY indexChanged)

public:
    ListKey(QObject *parent=0);
    ListKey(const QString &value, const QString &index, QObject *parent=0);

    QString value() const;
    void setValue(const QString &value);

    QString index() const;
    void setIndex(const QString &index);

signals:
    void valueChanged();
    void indexChanged();

private:
    QString m_value;
    QString m_index;
};

#endif // LISTKEY_H
