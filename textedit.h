#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

class TextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit TextEdit(QWidget *parent = nullptr);
    void initSpoilers();
    
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void leaveSpoiler();
    void enterSpoiler(int index);
    QList<QPair<int,int> > mSpoilers;
    QTextCharFormat mSpoilerFormat;
    int mSpoilerIndex;
};

#endif // TEXTEDIT_H
