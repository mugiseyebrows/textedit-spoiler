#include "textedit.h"

#include <QMouseEvent>
#include <QTextCursor>

#include <QDebug>
#include <QTextDocument>
#include <QTextBlock>

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent), mSpoilerIndex(-1)
{

}

void TextEdit::initSpoilers()
{
    QTextDocument* doc = document();
    mSpoilers.clear();
    for (QTextBlock block = doc->begin(); block != doc->end(); block = block.next()) {
        for(QTextBlock::iterator it = block.begin(); it != block.end(); it++) {
            QTextFragment fragment = it.fragment();
            QTextCharFormat format = fragment.charFormat();
            if (format.background().style() == Qt::NoBrush) {
                continue;
            }
            int head = fragment.position();
            int tail = fragment.position() + fragment.length();
            mSpoilers.append(QPair<int,int>(head, tail));
            mSpoilerFormat = format;
        }
    }
}

void TextEdit::enterSpoiler(int index)
{
    QTextCursor cursor(document());
    cursor.setPosition(mSpoilers[index].first);
    cursor.setPosition(mSpoilers[index].second, QTextCursor::KeepAnchor);
    QTextCharFormat format;
    format.setForeground(QBrush(Qt::black));
    cursor.setCharFormat(format);
    mSpoilerIndex = index;
}

void TextEdit::leaveSpoiler()
{
    int index = mSpoilerIndex;
    QTextCursor cursor(document());
    cursor.setPosition(mSpoilers[index].first);
    cursor.setPosition(mSpoilers[index].second, QTextCursor::KeepAnchor);
    cursor.setCharFormat(mSpoilerFormat);
    mSpoilerIndex = -1;
}

void TextEdit::mouseMoveEvent(QMouseEvent *event)
{
    QTextCursor cursor = cursorForPosition(event->pos());
    int pos = cursor.position();
    int spoilerIndex = -1;
    for(int i=0;i<mSpoilers.size();i++) {
        const QPair<int,int>& spoiler = mSpoilers[i];
        if (spoiler.first < pos && pos < spoiler.second) {
            spoilerIndex = i;
        }
    }
    if (spoilerIndex > -1 && mSpoilerIndex < 0) {
        enterSpoiler(spoilerIndex);
    } else if (spoilerIndex < 0 && mSpoilerIndex > -1) {
        leaveSpoiler();
    }
}
