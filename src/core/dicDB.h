#ifndef DICDB_H
#define DICDB_H

#include <QObject>
#include <QSqlDatabase>
#include "word.h"

class DicDB : public QObject
{
    Q_OBJECT
public:
    explicit DicDB(QObject *parent = 0);
    ~DicDB();
    Q_INVOKABLE bool connect();
    Q_INVOKABLE bool isDbExist();
    Q_INVOKABLE QList<QList<QString>> execSelect(QString sql);
    Q_INVOKABLE Word* getAWord(QString sql);
    Q_INVOKABLE Word* getAWord(QList<QString> propertys);
    Q_INVOKABLE Word* getAWord(int index);
//    Q_INVOKABLE void setWordList(QString tableName, int begin, int number);
    Q_INVOKABLE QString getErrorText() {return errorText;}
    Q_INVOKABLE int getQuantity();
    Q_INVOKABLE void setTableName(QString tableName) {this->tableName = tableName;}

    Q_INVOKABLE QStringList getWordListModel();
    Q_INVOKABLE QStringList getWordListModel(QString spell);
    Q_INVOKABLE Word *getWordBySpell(QString spell);

//    Q_INVOKABLE void clearMemory();

    //单词的各个属性在记录链表中的位置
    enum WordProperty {
        Index = 0,
        Spell = 1,
        Mean = 2,
        CET6_Frequency = 3,
        CET4_Frequency = 4,
        Length = 5
    };

private:
    QString dbFileName;
    QSqlDatabase db;
    QString tableName;
    QString errorText;
    Word *word;
//    QList<Word*> wordList;
};

#endif // DICDB_H
